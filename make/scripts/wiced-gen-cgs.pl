#!/usr/bin/perl

#use warnings;
#use strict;
use READELF;

my $dynamic_entry_lut = {
	# see glibc elf.h for definitions of .dynamic entries
	# only subset of items is included so far
	0x00 => { 'type' => 'DT_NULL', 'next' => 'ignore' },
	0x01 => { 'type' => 'DT_NEEDED', 'next' => 'val' },
	0x02 => { 'type' => 'DT_PLTRELSZ', 'next' => 'val' },
	0x03 => { 'type' => 'DT_PLTGOT', 'next' => 'ptr' },
	0x04 => { 'type' => 'DT_HASH', 'next' => 'ptr' },
	0x05 => { 'type' => 'DT_STRTAB', 'next' => 'ptr' },
	0x06 => { 'type' => 'DT_SYMTAB', 'next' => 'ptr' },
	0x07 => { 'type' => 'DT_RELA', 'next' => 'ptr' },
	0x08 => { 'type' => 'DT_RELASZ', 'next' => 'val' },
	0x09 => { 'type' => 'DT_RELAENT', 'next' => 'val' },
	0x0a => { 'type' => 'DT_STRSZ', 'next' => 'val' },
	0x0b => { 'type' => 'DT_SYMENT', 'next' => 'val' },
	0x0c => { 'type' => 'DT_INIT', 'next' => 'ptr' },
	0x0d => { 'type' => 'DT_FINI', 'next' => 'ptr' },
	0x0e => { 'type' => 'DT_SONAME', 'next' => 'ignore' },
	0x0f => { 'type' => 'DT_RPATH', 'next' => 'val' },
	0x10 => { 'type' => 'DT_SYMBOLIC', 'next' => 'ignore' },
	0x11 => { 'type' => 'DT_REL', 'next' => 'ptr' },
	0x12 => { 'type' => 'DT_RELSZ', 'next' => 'val' },
	0x13 => { 'type' => 'DT_RELENT', 'next' => 'val' },
	0x14 => { 'type' => 'DT_PLTREL', 'next' => 'val' },
	0x15 => { 'type' => 'DT_DEBUG', 'next' => 'ptr' },
	0x16 => { 'type' => 'DT_TEXTREL', 'next' => 'ignore' },
	0x17 => { 'type' => 'DT_JMPREL', 'next' => 'ptr' },
	0x6ffffff9 => { 'type' => 'DT_RELACOUNT', 'next' => 'val' },
	0x6ffffffa => { 'type' => 'DT_RELCOUNT', 'next' => 'val' },
	0x6ffffffb => { 'type' => 'DT_FLAGS_1', 'next' => 'val', 'map' => { 0x08000000 => 'DF_1_PIE' }, },
};

main();

sub main
{
	my ($app_elf, $hdf_in);
	my $hdf = {};
	my $entry2code = {};
	my $cgs_list = [];
	my $app_entry_function;
	my $outfile;
	my $direct_load;
	my $OUT;

	foreach my $arg (@ARGV) {
		#print "# ----- $arg\n";
		if($arg =~ /^out=(.*)/) {
			$outfile = $1;
		}
		elsif($arg =~ /\.elf$/) {
			$app_elf = $arg;
		}
		elsif($arg =~ /\.cgs$/) {
			push @{$cgs_list}, $arg;
		}
		elsif($arg =~ /\.hdf$/) {
			$hdf_in = $arg;
		}
		elsif($arg =~ /\.ld$/) {
			$app_ld = $arg;
		}
		elsif($arg =~ /(\w+)\.entry$/) {
			$app_entry_function = $1;
		}
		elsif($arg =~ /^DIRECT_LOAD/) {
			$direct_load = 1;
		}
	}

	my $sections = [];
	my $stringtable = {};
	my $sym_str_tbl = {};
	my $symbol_entries = [];
	parse_elf($app_elf, $sections, $stringtable, $sym_str_tbl, $symbol_entries, 0);

	parse_hdf($hdf_in, $hdf, $entry2code);
#	output_cgs_cfg($cfg_prep, $entry2code, $hdf_out, $symbol_entries);
	if(defined $outfile) {
        open($OUT, ">", $outfile) || die "Could not open $outfile, $!\n";
		select $OUT;
	}

	# combine the cgs files
    my @cgs_records;
    foreach my $cgs (@{$cgs_list}) {
        my $cgs_record = {};
        # transport cgs
        if($cgs =~ /wiced_(uart|spi)\.cgs$/) {
            $cgs_record->{'type'} = 'transport';
            $cgs_record->{'order'} = 1;
        }
        # patch cgs
        elsif($cgs =~ /patch\.cgs$/) {
            $cgs_record->{'type'} = 'patch';
            $cgs_record->{'order'} = 2;
        }
        # platform cgs
        elsif(($cgs =~ /platforms\/[^\.]+.cgs$/) || ($cgs =~ /TARGET_.*\/.*.cgs$/)) {
            $cgs_record->{'type'} = 'platform';
            $cgs_record->{'order'} = 3;
        }
        else {
            die "could not categorize \"$cgs\" for processing\n";
        }
        $cgs_record->{'file'} = $cgs;
        $cgs_record->{'lines'} = [];
        open(my $CGS, "<", $cgs) or die "could not open \"$cgs\"\n";
        push @{$cgs_record->{lines}}, <$CGS>;
        close $CGS;
        post_process_cgs($cgs_record);
        push @cgs_records, $cgs_record;
    }
    @cgs_records = sort { $a->{order} <=> $b->{order} } @cgs_records;
    dump_cgs(\@cgs_records);

	my $sym = find_symbol($symbol_entries, $app_entry_function);
	my $addr = $sym->{st_value} if defined $sym;
#	output_hex_elf($app_elf, $sections, $addr);
	output_cgs_elf($app_elf, $sections, $symbol_entries, $stringtable, $hdf, $entry2code, $app_entry_function, $direct_load);

    post_app_cgs(\@cgs_records);

	if(defined $outfile) {
		select STDOUT;
	}
	report_resource_usage($sections, $app_ld);
}

sub dump_cgs
{
    my ($cgs_records) = @_;
    foreach my $cgs_record (@{$cgs_records}) {
        print "\n\n############### dump $cgs_record->{file}\n";
        foreach my $line (@{$cgs_record->{lines}}) {
            print $line;
		}
	}
}

sub post_process_cgs
{
    my ($cgs_record) = @_;
    return if $cgs_record->{type} ne 'patch';

    # for now just need to split TCA records from patch.cgs to end of combined cgs
    return if $cgs_record->{file} !~ /(20721B2|20719B2)/;

    my @lines;
    push @lines, @{$cgs_record->{lines}};
    $cgs_record->{lines} = [];
    my $in_tca_entry = 0;
    foreach my $line (@lines) {
        if ($in_tca_entry) {
            push @{$cgs_record->{tca_lines}}, $line;
            if (index($line, '}') != -1) {
                $in_tca_entry = 0;
        }
    }
        else {
            if (index($line, 'ENTRY "Temperature Correction Algorithm Config"') != -1
            || index($line, 'ENTRY "BR TCA Table"') != -1
            || index($line, 'ENTRY "EDR TCA Table"') != -1
            || index($line, 'ENTRY "LE TCA Table"') != -1
            || index($line, 'ENTRY "LE2 TCA Table"') != -1) {
                $cgs_record->{'tca_lines'} = [] if !defined $cgs_record->{tca_lines};
                $in_tca_entry = 1;
                push @{$cgs_record->{tca_lines}}, $line;
            }
            else {
                push @{$cgs_record->{lines}}, $line;
            }
        }
    }
}

sub post_app_cgs
{
    my ($cgs_records) = @_;
    foreach my $cgs_record (@{$cgs_records}) {
        next if $cgs_record->{type} ne 'patch';
        next if !defined $cgs_record->{tca_lines};
        print "\n\n############### dump TCA entries from $cgs_record->{file}\n";
        foreach my $line (@{$cgs_record->{tca_lines}}) {
		print $line;
	}
        last;
    }
}

sub report_resource_usage
{
	my ($sections, $ld_file) = @_;
	my $load_regions = {};
    my $mem_type_names = { ram => "SRAM", aon => "Battery backed RAM", static_section => "Static Data", xip_section => "Flash", xip_section_ds2 => "Flash", pram => "Patch RAM"};

	my $total;
	my ($ram_patch_begin, $ram_patch_end, $ram_end);
	my ($flash_begin, $flash_len, $flash_ds, $flash_ds2);
	print "\n";

	open(my $LD, "<", $ld_file) || die "Could not read $ld_file, $!\n";
	while(defined(my $line = <$LD>)) {
		if($line =~ /ram_patch_begin=0x([0-9A-F]+)/) {
			$ram_patch_begin = hex($1);
			printf "Patch ram starts at          0x%06X (RAM address)\n", $ram_patch_begin;
		}
		if($line =~ /ram_patch_end=0x([0-9A-F]+)/) {
			$ram_patch_end = hex($1);
			printf "Patch ram ends at            0x%06X (RAM address)\n", $ram_patch_end;
		}
		if($line =~ /ram_end=0x([0-9A-F]+)/) {
			$ram_end = hex($1);
			#printf "RAM ends at                  0x%06X (RAM address)\n", $ram_end;
		}
		if($line =~ /FLASH0_BEGIN_ADDR=0x([0-9A-F]+)/) {
			$flash_begin = hex($1);
		}
		if($line =~ /FLASH0_LENGTH=0x([0-9A-F]+)/) {
			$flash_len = hex($1);
		}
		if($line =~ /FLASH0_DS=0x([0-9A-F]+)/) {
			$flash_ds = hex($1);
		}
		if($line =~ /FLASH0_DS2=0x([0-9A-F]+)/) {
			$flash_ds2 = hex($1);
		}
		if($line =~ /^MEMORY/) {
			my $line2 = <$LD>;
			next unless $line2 =~ /\{/;
			while(defined($line2 = <$LD>)) {
				last if $line2 =~ /\}/;
				$line2 =~ s/\s//g;
				if($line2 =~ /(\w+)\((\w+)\)\:ORIGIN=(0x[0-9A-Fa-f]+),LENGTH=(0x[0-9A-Fa-f]+)/) {
					my $region = {};
					$region->{'name'} = $1;
					$region->{'type'} = $mem_type_names->{$1};
					$region->{'access'} = $2;
					$region->{'start'} = hex($3);
					$region->{'len'} = hex($4);
					next if $region->{start} >= 0xF0000000;
					$region->{'end'} = $region->{start} + $region->{len};
					$region->{'start_used'} = 0xffffffff;
					$region->{'end_used'} = 0;
					$load_regions->{$1} = $region;
				}
			}
		}
	}
	close $LD;

	if(defined $flash_ds) {
		my $flash_ds_len = $flash_len - $flash_ds;
		$flash_ds_len = ($flash_ds2 - $flash_ds) if defined $flash_ds2;
		printf "DS length %d (0x%06X) at 0x%06X\n", $flash_ds_len/2, $flash_ds_len/2, $flash_ds;
	}

	foreach my $section (@{$sections}) {
		foreach my $region (values(%{$load_regions})) {
			next if $section->{sh_addr} < $region->{start};
			next if ($section->{sh_addr} + $section->{sh_size}) > $region->{end};
			if($section->{sh_addr} < $region->{start_used}) {
				$region->{start_used} = $section->{sh_addr};
			}
			if(($section->{sh_addr} + $section->{sh_size}) > $region->{end_used}) {
				$region->{end_used} = $section->{sh_addr} + $section->{sh_size};
			}
			$section->{'mem_type'} = $region->{type};
			last;
		}
		next unless defined $section->{mem_type};
		printf "% 16s %8s start 0x%06X, end 0x%06X, size %d\n", $section->{name}, $section->{mem_type}, $section->{sh_addr},
					$section->{sh_addr} + $section->{sh_size}, $section->{sh_size};
	}
	print  "\nApplication memory usage:\n";
	foreach my $region (values(%{$load_regions})) {
		next if $region->{end_used} == 0;
		my $use = $region->{end_used} - $region->{start_used};
		$total += $use;
		printf "  %s (%s): used 0x%06X - 0x%06X size (%d)\n", $region->{name}, $region->{type}, $region->{start_used}, $region->{end_used}, $use;
	}
	printf "Total footprint %d (0x%X)\n\n", $total, $total;
}

sub output_cgs_cfg
{
	my ($file, $entry2code, $hdf_out, $symbol_entries) = @_;
	my ($entry_name, $entry_code);
	$hdf_out = basename($hdf_out);

	# read file
	my @lines;
	open(my $CGS, "<", $file) or die "could not open \"$file\"\n";;
	while(defined (my $line = <$CGS>)) {
		$line =~ s/^\s*DEFINITION.*/DEFINITION <$hdf_out>\n/;
		push @lines, $line;
	}
	close $CGS;

	# extract settings (array) for each ENTRY
	my @entry_lines;
	my @settings;
	foreach my $line (@lines) {
		if($line =~ /ENTRY\s+\"([^\"]+)\"/) {
			$entry_name = $1;
			$entry_code = $entry2code->{$entry_name};
			die "could not find config command code for ENTRY in \"$line\"\n" if !defined $entry_code;
		}
		elsif($line =~ /^\s*\{/) {
		}
		elsif($line =~ /^\s*\}/) {
			push @entry_lines, $line;
			agi_entry_settings($entry_code, $entry_name, \@entry_lines, \@settings);
			@entry_lines = ();
			next;
		}
		push @entry_lines, $line;
	}

	# coalesce some like entries (e.g., group BB Init)
	my $merge_to;
	my @merged_settings;
	foreach my $setting (@settings) {
		push @merged_settings, $setting;
		next if $setting->{code} != 0x0102;
		if(!defined $merge_to) {
			$merge_to = $setting;
		}
		else {
			# trim trailing non-data lines
			my $last_line;
			while(defined( my $item = pop @{$merge_to->{data}})) {
				if(defined $item->{val}) {
					push @{$merge_to->{data}}, $item;
					last;
				}
				# collect ending line
				$last_line = $item if defined $item->{end};
			}
			# merge all but leading syntax lines
			while(defined( my $item = shift @{$setting->{data}})) {
				next if defined $item->{start};
				# stop appending if we got to end
				last if defined $item->{end};
				push @{$merge_to->{data}}, $item;
			}
			# re-append last line
			if(defined $last_line) {
				push @{$merge_to->{data}}, $last_line;
			}

			# hack to re-index and update NumEntries
			my $count = 0;
			my $index;
			my $first_data_item;
			foreach my $item (@{$merge_to->{data}}) {
				next if !defined $item->{val};
				if(!defined $first_data_item) {
					$first_data_item = $item;
					next;
				}
				$index = int($count/3);
				$item->{orig} =~ s/\[\d+\]\"/\[$index\]\"/;
				$count++;
			}
			if(defined $first_data_item) {
				$first_data_item->{val} = ++$index;
				$aon_extra_alloc = $index; # note NumEntries
				$first_data_item->{orig} =~ s/\s*=\s*\d+/ = $index/;
			}
			# drop separate merged settings after merge complete
			pop @merged_settings;
		}
	}

    # output to cgs
	foreach my $setting (@merged_settings) {
		# any more fix ups
		fix_up_settings($setting, $symbol_entries);
		# note the Init BB Regs size (less mask and NumEntries) - this will be allocated in AON for slimboot
		if($setting->{code} == 0x0102) {
			$aon_extra_alloc++; # firmware adds a bit
			$aon_extra_alloc *= 8; # firmware copies addr, value, not mask
		}
		foreach my $item (@{$setting->{data}}) {
			print $item->{orig};
		}
	}
}

sub fix_up_settings
{
	my ($setting, $symbol_entries) = @_;
	if($setting->{name} eq 'Data') {
		foreach my $item (@{$setting->{data}}) {
			if($item->{orig} =~ /\$AUTOGEN\(ADDR\{(\w+)\}\)/) {
				my $sym = find_symbol($symbol_entries, $1);
				die "could not find address for symbol in \"$item->{orig}\"\n" if !defined $sym;
				$item->{'type'} = 'hex';
				$item->{'val'} = $sym->{st_value};
				my $txt = sprintf "0x%08x", $sym->{st_value};
				$item->{orig} =~ s/\$AUTOGEN/$txt # <<< \$AUTOGEN/;
			}
		}
	}
}

# accumulate data from agi file ENTRY
sub agi_entry_settings
{
	my ($code, $name, $lines, $settings) = @_;

	my $entry = {};
	$entry->{'code'} = $code;
	$entry->{'name'} = $name;
	$entry->{'data'} = [];

	foreach my $line (@{$lines}) {
		my $item = {};
		$item->{'orig'} = $line;
		if($line =~ /(\#.*)$/) {
			$item->{'comment'} = $1;
			$line = $`;
		}
		if($line =~ /(\/\/.*)$/) {
			$item->{'comment'} = $1;
			$line = $`;
		}
		$line =~ s/^\s+//;
		$line =~ s/\s+$//;
		if(length($line) > 0) {
			$item->{'parsed'} = $line;
		}
		if($line =~ /\"([^\"]+)\"\s*=\s*\"([^\"]+)\"/) {
			$item->{'name'} = $1;
			$item->{'type'} = 'quoted';
			$item->{'val'} = $2;
		}
		elsif($line =~ /\"([^\"]+)\"\s*=\s*(0x[0-9A-Fa-f]+)/) {
			$item->{'name'} = $1;
			$item->{'type'} = 'hex';
			$item->{'val'} = hex($2);
		}
		elsif($line =~ /\"([^\"]+)\"\s*=\s*(\-?\d+)/) {
			$item->{'name'} = $1;
			$item->{'type'} = 'decimal';
			$item->{'val'} = int($2);
		}
		elsif( ($line =~ /^ENTRY/) || ($line =~ /^\{/)) {
			$item->{'start'}++;
		}
		elsif( $line =~ /^\}/) {
			$item->{'end'}++;
		}
		push @{$entry->{data}}, $item;
	}
	# special case
	if(($name eq 'Config Data Version') && (0 == scalar(@{$entry->{data}}))) {
		my $item = {};
		$item->{'name'} = 'version';
		$item->{'type'} = 'decimal';
		$item->{'val'} = 0;
		$item->{'index'} = 1;
		push @{$entry->{data}}, $item;
	}

	push @{$settings}, $entry;
}


sub output_hdf_cfg_command
{
	my ($cfg, $entry_name, $hdf_cfg, $data, $use_commented_bytes, $direct_load) = @_;
	my $offset = 0;
	my $param_lut = {};
	$use_commented_bytes = 0 if !defined $use_commented_bytes;
	$direct_load = 0 if !defined $direct_load;

	if($direct_load) {
		print "DIRECT_LOAD";
	}
	else {
		print "ENTRY \"$hdf_cfg->{name}\"";
	}
	print " = \"$entry_name\"" if defined $entry_name;
	print "\n\{\n";

	foreach my $param (@{$hdf_cfg->{params}}) {
		last if $offset >= length($data);
		last if $hdf_cfg->{name} eq 'Config Data Version';

		if($use_commented_bytes && $param->{name} eq 'Data') {
			print_commented_bytes($param->{name}, substr($data, $offset));
			next;
		}
		# read data
		my ($data_str, $rdata, $step) = param_data_string($param, substr($data, $offset));
		$param_lut->{$param->{name}} = $rdata;
		$offset += $step;

		# check for 'present_if' rule to determine whether data is output
		next if !param_present_if($param, $param_lut);
		print "\t\"$param->{name}\" = $data_str\n";
	}
	print "\}\n\n";
}

sub	get_string_data
{
	my ($sections, $symbol_entries) = @_;
	foreach my $section (@{$sections}) {
		next if $section->{sh_type} != 9; # SHT_REL == 9
		my $target_section = $sections->[$section->{sh_info}];
		die "could not resolve relocation section\n" if !defined $target_section;
		my @entries = unpack "L*", $section->{data};
		for(my $i = 0; $i < scalar(@entries); $i += 2) {
			my $offset = $entries[$i];
			my $type = $entries[$i+1] & 0xff;
			my $sym_offset = $entries[$i+1] >> 8;
			my $sym = $symbol_entries->[$sym_offset];
			my $reloc = $sym->{st_value} - $offset; # there is no r_addend, so not adding 0
			if($type == 2) {  # R_386_PC32
				# get relocation symbol data
				my $data = $sections->[$sym->{st_shndx}]->{data};
				# replace section data at offset with relocation data
				substr($target_section->{data}, $reloc, $sym->{st_size}, $data);
				# adjust symbol size at this location
				foreach my $s (@{$symbol_entries}) {
					next if $target_section->{index} != $s->{st_shndx};
					if($s->{name} =~ /__override__/) {
						$s->{st_size} = length($data);
						last;
					}
				}
			}
		}
		last;
	}
}


sub param_data_string
{
	my ($param, $data) = @_;

	# check format rule to determine size of parameter data
	my $type = $param->{rules}->{fmt}->{type};

	die "undefined format type for param $param->{name}\n" if !defined $type;
	my ($data_str, $rdata, $step);
	my ($pack_fmt, $str_fmt);
	my $len = length($data);
	if($type eq 'uint8') {
		($step, $pack_fmt, $str_fmt) = (1, "C", "0x%02X");
	}
	elsif($type eq 'uint16') {
		($step, $pack_fmt, $str_fmt) = (2, "S", "0x%X");
	}
	elsif($type eq 'uint32') {
		($step, $pack_fmt, $str_fmt) = (4, "L", "0x%X");
	}
	elsif($type eq 'int8') {
		($step, $pack_fmt, $str_fmt) = (1, "L", "%d");
	}
	elsif($type eq 'int16') {
		($step, $pack_fmt, $str_fmt) = (2, "L", "%d");
	}
	elsif($type eq 'int32') {
		($step, $pack_fmt, $str_fmt) = (4, "L", "%d");
	}
	elsif($type eq 'utf8') {
		($step, $pack_fmt, $str_fmt) = (length($data), "Z*", "\"%s\"");
	}

	if($len >= $step) {
		die "could not read data for param $param->{name}\n" if !defined $step;
		($rdata) = unpack $pack_fmt, $data;
		$data_str = sprintf $str_fmt, $rdata;
	}

	return ($data_str, $rdata, $step);
}

sub param_present_if
{
	my ($param, $lut) = @_;
	my $ret = 1;
	return 1 if !defined $param->{rules}->{condition};
	return 1 if $param->{rules}->{condition}->{type} ne 'present_if';
	my $rule = $param->{rules}->{condition}->{rule};

	# replace each "name" with value from p_lut, then evaluate
	my @matches = $rule =~ /\"([^\"]+)\"/g;
	foreach my $match (@matches) {
	#	return 0 if !defined $lut->{$match};
		die "could not find look up for $match in rule $rule\n" if !defined $lut->{$match};
		# get quoted item
		my $repl = '$lut->{' . "\'" . $match . "\'" . '}';
		$match =~ s/\[/\\\[/g;
		$match =~ s/\]/\\\]/g;
		die "got bad match out of $rule\n" if !defined $match;
		$rule =~ s/\"$match\"/$repl/;
	}
	$ret = eval $rule;
	$ret = 0 if !defined $ret;
	$ret = 0 if $ret eq "";
	return $ret;
}

sub output_hex_elf
{
	my ($file, $sections, $entry) = @_;
	my @output_sections;
	$entry = 0 if !defined $entry;

	$file =~ s/\.elf$/\.hex/;
	open(my $HEX, '>', $file) or die "Cannot open $file for write: $!\n";
	binmode $HEX;

	foreach my $section (@{$sections}) {
		next if $section->{sh_addr} >= 0x1000000;
		next if $section->{sh_size} == 0;
		next if (0 == ($section->{sh_flags} & 7)); # only code or data type
		next if $section->{sh_type} != 1; # only PROGBITS, (fromelf mistakenly appends SRAM data from very different address range)
		push @output_sections, $section;
	}

	@output_sections = sort { $a->{sh_addr} <=> $b->{sh_addr} } @output_sections;

	foreach my $section (@output_sections) {
		#printf "%d: %s: start %x len %x, end %x, data %d\n", $section->{index}, $section->{name}, $section->{sh_addr},
		#		$section->{sh_size}, $section->{sh_addr} + $section->{sh_size}, length($section->{data});
		# emit extended linear address record to start section
		my $addr_hi = $section->{sh_addr} >> 16;
		my $rec_addr = $section->{sh_addr} & 0xffff;
		print $HEX hex_record(0, 4, sprintf("%04x",$addr_hi)), "\n";
		for(my $i = 0; $i < $section->{sh_size}; $i += 16) {
			my $chunk = 16;
			$chunk = $section->{sh_size} - $i if ($section->{sh_size} - $i) < 16;
			last if $chunk == 0;
			my @bytes = unpack("C*",substr($section->{data}, $i, $chunk));
			my $rec_data = "";
			foreach my $byte (@bytes) {
				$rec_data .= sprintf "%02x", $byte;
			}
			print $HEX hex_record($rec_addr & 0xffff, 0, $rec_data), "\n";
			$rec_addr += 16;
			if($rec_addr > 0xfffff) {
				# emit extended linear address record
				$addr_hi++;
				print $HEX hex_record(0, 4, sprintf("%04x",$addr_hi)), "\n";
				$rec_addr &= 0xffff;
			}
		}
	}
	# closing record
	print $HEX hex_record(0, 5, sprintf("%02x%02x%02x%02x",
		$entry & 0xff, ($entry >> 8) & 0xff, ($entry >> 16) & 0xff, ($entry >> 24) & 0xff)), "\n";
	print $HEX hex_record(0, 1, ""), "\n";
	close $HEX;
}

sub hex_record
{
	my ($addr, $type, $data) = @_;

	my $record = sprintf "%02x%04x%02x", length($data)/2, $addr, $type;
	$record .= $data;
	my $checksum = 0;
	$checksum += $_ for unpack('C*', pack("H*", $record));
	my $hex_sum = sprintf "%04x", $checksum;
	$hex_sum = substr($hex_sum, -2); # just save the last byte of sum
	$checksum = (hex($hex_sum) ^ 0xFF) + 1; # 2's complement of hex_sum
	$checksum &= 0xff;
	$checksum = sprintf "%02x", $checksum; # convert checksum to string
	$record = ":" . $record . $checksum;
	return uc($record);
}

sub preview_sections
{
	my ($sections, $sorted_sections, $section_info) = @_;

	# sort overlay sections to end
	# move data sections prior to datagot and relo
	my @overlay_sections;
	my @nonoverlay_sections;
	my @pie_sections;
	my @non_pie_sections;
	foreach my $section (@{$sections}) {
		next if !defined $section->{name};
		if($section->{name} =~ /^\._(\d)_/) {
			# mark the section as overlay
			$section->{'overlay_id'} = $1;
			push @overlay_sections, $section;
		}
		else {
			push @nonoverlay_sections, $section;
		}
		if($section->{sh_type} == 9 || $section->{sh_addr} >= 0xFF000000 || $section->{name} eq '.datagot') {
			push @pie_sections, $section;
		}
		else {
			push @non_pie_sections, $section;
		}
		if($section->{sh_type} == 9) {
			# fix up relocation data section offsets, assume only R_ARM_RELATIVE allowed
			my $d_off = 0;
			my $data;
			while($d_off < length($section->{data})) {
				my ($d_offset, $d_type, $d_sym, $d_info) = unpack "LCCS", substr($section->{data}, $d_off, 8);
				die "encountered relocation record not of type R_ARM_RELATIVE (type $d_type != 23)\n" if $d_type != 0x17; # 0x17 is R_ARM_RELATIVE
				$d_off += 8;
				$data .= pack "L", $d_offset;
			#	warn sprintf "  %08x %02x %02x %04x\n", $d_offset, $d_type, $d_sym, $d_info;
			#	my $sym = find_symbol_with_address($symbol_entries, $d_offset, "^[A-Za-z]");
			#	warn "   $sym->{name}\n" if defined $sym->{name};
			}
			$section_info->{'relo_data'} = pack "S", $d_off/8;
			$section_info->{'relo_data'} .= $data;
		}
		# .app_xip_area will be merged as hex section going into ocf, not to be in cgs config records
		if( $section->{name} eq '.app_xip_area') {
			# note text start
			$section_info->{'xip_text_start'} = $section->{sh_addr};
			$section_info->{'xip_text_end'} = $section->{sh_addr} + $section->{sh_size};
		}
        if( $section->{name} eq '.app_xip_area_ds2') {
            $section_info->{'ds2_xip_text_start'} = $section->{sh_addr};
            $section_info->{'ds2_xip_text_end'} = $section->{sh_addr} + $section->{sh_size};
        }
        if( $section->{name} eq '.app_ram_area_ds2') {
            $section_info->{'ds2_ram_start'} = $section->{sh_addr};
            $section_info->{'ds2_ram_end'} = $section->{sh_addr} + $section->{sh_size};
        }

		if($section->{sh_addr} >= 0xFF000000) {
			next if $section->{name} ne '.dyn_info';
			# this code is just exploratory, not used in builds
			my $d_off = 0;
			while($d_off < length($section->{data})) {
				my $r = {};
				($r->{'d_tag'}, $r->{'ptr_or_val'}) = unpack "LL", substr($section->{data}, $d_off, 8);
				last if $r->{d_tag} == 0; # exit at DT_NULL
				my $d_lut = $dynamic_entry_lut->{$r->{d_tag}};
				die "unhandled dynamic tag type $d_lut\n" if !defined $d_lut;
				$r->{'d_type'} = $d_lut->{next};
				$r->{'d_tag_type'} = $d_lut->{type};
				#warn sprintf "dynamic section %08x %s type %s %08x\n", $r->{d_tag}, $r->{d_tag_type}, $r->{d_type}, $r->{ptr_or_val};
				# DF_1_PIE = 0x08000000
				$d_off += 8;
				if($r->{d_tag_type} eq 'DT_RELCOUNT') {
					$dyn_info->{'DT_RELCOUNT'} = $r->{ptr_or_val};
				}
				if(0) { #$r->{d_tag_type} eq 'DT_HASH') {
					#skip to after
					warn "  looking into dyn info...\n";
					my $relo_offset = $r->{ptr_or_val} - $section->{sh_addr};
					my $addr;
					do {
						$addr = unpack "L", substr($section->{data}, $relo_offset, 4);
						$relo_offset += 4;
					} while($addr <= 3 && $relo_offset < length($section->{data}));
					do {
						my $sym = find_symbol_at_address($symbol_entries, $addr, "");
						warn sprintf "relo at %08x, symbol %s\n", $addr, $sym->{name};
						$kind = unpack "L", substr($section->{data}, $relo_offset, 4);
						$relo_offset += 4;
						die "bad relocation record\n" unless $kind == 0x17;
						$addr = unpack "L", substr($section->{data}, $relo_offset, 4);
						$relo_offset += 4;
					} while($relo_offset < length($section->{data}));
				}
				# push @{$dynamic}, $r;
			}
		}
		}
	if(scalar( @overlay_sections)) {
		push @{$sorted_sections}, @nonoverlay_sections;
		push @{$sorted_sections}, @overlay_sections;
	}
	else {
		push @{$sorted_sections}, @non_pie_sections;
		push @{$sorted_sections}, @pie_sections;
	}


}

sub output_cgs_elf
{
	my ($file, $sections, $symbol_entries, $stringtable, $hdf, $entry2code, $entry_function, $direct_load) = @_;
	my $xip_pie;
	my $ds = 0x501400;

	# now process elf sections for cgs
	my $seperator = "##############################################################################\n";

	print $seperator;
	print "# Patch code from \"$file\"\n";
	print $seperator;

	my $sorted_sections = [];
	my $section_info = {};
	preview_sections($sections, $sorted_sections, $section_info);

	foreach my $section (@{$sorted_sections}) {
		next if ($section->{sh_type} != 1 && $section->{sh_type} != 6 && $section->{sh_type} != 9); # PROGBITS
		next if !($section->{sh_flags} & 3); # attributes off (!write, !alloc, !exec)
		next if $section->{sh_size} == 0;
		next if !defined $section->{name};
		next if $section->{sh_addr} > 0x600000 &&  $section->{sh_type} != 9;
		next if $section->{name} eq '.app_xip_area';
        next if $section->{name} eq '.app_xip_area_ds2';
        next if $section->{name} eq '.app_ram_area_ds2';
		$section->{'name'} = $stringtable->{$section->{sh_name}} if !defined $section->{name};

		#warn sprintf "read section % 20s with %04x bytes addr %08x offset %08x flags %x type %x\n",
		#			$section->{name}, $section->{sh_size},
		#			$section->{sh_addr}, $section->{sh_offset}, $section->{sh_flags}, $section->{sh_type};

		# handle sections in 0xff00 chunks
		my $offset = 0;
		while($offset < length($section->{data})) {
			my $name = "Data";
			my $data = pack "L", $section->{sh_addr} + $offset;
			if( defined $section->{overlay_id}) {
				$name = "Overlay data";
				#my ($d1, $d2, $d3, $d4) = unpack "CCCC", $section->{data};
				#warn sprintf "overlay index %x, addr %x, data %x %x %x %x\n", $section->{overlay_id}, $section->{sh_addr}, $d1, $d2, $d3, $d4;
				$data = pack "L", $section->{overlay_id};
				$data .= pack "L", $section->{sh_addr} + $offset;
			}
			elsif($section->{name} eq '.aon') {
				$name = "AON Data";
			}
			elsif($section->{name} eq '.datagot') {
				# command to update GOT in OCF, walks table adjusting addrs for values referencing pic xip code range
				# reads payload into FOUNDATION_CONFIG_DYN_LINK_GOT_t gotTable
				# copy GOT from OCF table to ram, using gotAddr = this_command_got_offset + active DS
				# update each got value (-= gotTable.textAddress, += active DS + gotTable.textAddressOffset) and copy back to flash
				my $got_end = find_symbol($symbol_entries, "actual_xip_got_end");
				die "could not find actual_xip_got_end\n" unless defined $got_end;
				my $got_size = $section->{sh_size};
				my $got_num_addr = 0;
				my @got = unpack "L*", $section->{data};
				foreach my $got_entry (@got) {
					$got_num_addr++ if $got_entry >= $section_info->{xip_text_start} && $got_entry < $section_info->{xip_text_end};
				}
				$name = "Dynamic Linker GOT";
				$data = pack "L", $section_info->{xip_text_start}; 				# Text Address
				$data .= pack "L", $section_info->{xip_text_start} - $ds; 		# Text Address Offset
				$data .= pack "L", $section->{sh_addr};			# GOT Address
				$data .= pack "L", $section->{sh_addr} - $ds; 	# GOT Address Offset
                $data .= pack "L", $got_size - 0x04;                             # GOT Length - subtract 4 for the signature (We dont want it processed)
				$data .= pack "S", $got_num_addr;					# Total Number of Addresses
				$xip_pie = 1;
			}
			elsif($section->{sh_type} == 9) {
				# this command provides addresses that need to be fixed up based on the active DS
				# addresses need to be sorted smallest to largest
				$name = "Dynamic Linker RELO";
				$data = pack "L", $ds;
				$section->{data} = $section_info->{relo_data};
			}
			my $chunk = length($section->{data}) - $offset;
			$chunk = 0xff00 if $chunk > 0xff00;
			$data .= substr($section->{data}, $offset, $chunk);
			$offset += $chunk;
			output_hdf_cfg_command($section->{name}, "$section->{name} from $file", $hdf->{$entry2code->{$name}}, $data, 1, $direct_load);
		}
	}

	print "\n";
	print $seperator;
	print "# Also call entry function $entry_function\n";
	print $seperator;
	foreach my $sym (@{$symbol_entries}) {
        my $name = $sym->{name};
        next if !defined $name;
        next if(($sym->{st_info} & 0xf) != 2 ); # only function type symbols
        next if $name ne $entry_function;
	    my $data = pack "L", $sym->{st_value};
		my $entry_name = 'Function Call';
		# for pie need 'PIC DS Function Call'- firmware adds active DS base to addr
		if($xip_pie &&  $sym->{st_value} > $ds) {
			$entry_name = 'PIC DS Function Call' ;
			$data = pack "L", $sym->{st_value} - $ds;
		}
		output_hdf_cfg_command($sym, undef, $hdf->{$entry2code->{$entry_name}}, $data);
		last;
	}
}

sub parse_hdf
{
	my ($file, $comment_cfg, $entry2code) = @_;
	my $hdf_txt;
	my $in_hdf_struct;
	my $command_name;
	my $command_num;
	my $braces = 0;

	open(my $HDF, "<", $file) or die "could not open \"$file\"\n";;
	while(defined (my $line = <$HDF>)) {
		# strip comment and blank
		$line =~ s/\#.*$//;
		$line =~ s/^\s+//;
		$line =~ s/\s+$//;
		next if length($line) == 0;

		if($line =~ /COMMAND\s+\"([^\"]+)\"\s+0x([0-9A-Fa-f]+)/) {
			$command_name = $1;
			$command_num = hex($2);
			next;
		}
		if($line =~ /^\{/) {
			$braces++;
			if($line =~ /\}/) {
				$braces--;
			}
			else {
				next;
			}
		}
		if($line =~ /^\}/) {
			$braces-- ;
			if($braces == 1) {
				$comment_cfg->{$command_num} = {};
				$comment_cfg->{$command_num}->{'name'} = $command_name;
				$entry2code->{$command_name} = $command_num;
				$comment_cfg->{$command_num}->{'txt'} = $hdf_txt;
				$comment_cfg->{$command_num}->{'params'} = [];
				#warn "process $command_name $command_num\n";
				process_comment_cfg($comment_cfg->{$command_num}->{'params'}, $hdf_txt);
		        $hdf_txt = "";
		        next;
			}
		}
		next if $braces < 1;
		# end of command def
		$hdf_txt .= $line . "\n";
	}
	close $HDF;
}

sub process_comment_cfg
{
	my($params, $txt) = @_;
	my @param_lines = ();

	my @lines = split "\n", $txt;
	foreach my $line (@lines) {
		#print "$line\n";
		$line =~ s/\\\"//g;
		next if(length($line) == 0);
		next if $line =~ /^\s*doc/;
		next if($line =~ /^note/);
		next if($line =~ /^\"/);

		if($line =~ /^\s*PARAM/) {
			if(scalar(@param_lines) > 0) {
				process_comment_cfg_param($params, \@param_lines);
				@param_lines = ();
			}
		}
		push @param_lines, $line;
	}
	if(scalar(@param_lines) > 0) {
		process_comment_cfg_param($params, \@param_lines);
	}
}

sub process_comment_cfg_param
{
	my($params, $lines) = @_;
	my $param = {};
	$param->{'rules'} = {};

	my $lut = {
		'uint8'		=> 'fmt',
		'int8'		=> 'fmt',
		'uint16'	=> 'fmt',
		'int16'		=> 'fmt',
		'uint32'	=> 'fmt',
		'int32'		=> 'fmt',
		'utf8'		=> 'fmt',
		'bool8'		=> 'fmt',
		'bool'		=> 'fmt',
		'enum'		=> 'e_limit',
		'max'		=> 'e_limit',
		'min'		=> 'e_limit',
		'default' 	=> 'default',
		'present_if' => 'condition',
		'enabled_if' => 'condition',
		'encode_value' => 'coder',
		'decode_value' => 'coder',
		'valid_length' => 'e_limit',
		'not_in_binary_message' => 'condition',
		'binary_message_only' => 'condition',
	#	'ByteArrayValidLength' => 0,
	#	'ReleaseParameter'	=> 0,
	};

	my $first = shift @{$lines};
	if($first =~ /PARAM\s+\"([^\"]+)\"/) {
		$param->{'name'} = $1;
	}
	else {
		foreach my $line (@{$lines}) {
			print $line;
		}
		die "expected first line of param to have PARAM \"$first\"\n";
	}

	while(defined( my $line = shift @{$lines})) {
		my $p = {};
		if($line =~ /^(\w+)\s*\[\s*(\d+)\s*\]/) {
			$p->{'type'} = $1;
			$p->{'elements'} = $2;
		}
		elsif($line =~ /^(\w+)\s*\[\s*(0x[0-9A-Fa-f]+)\s*\]\s+(\w+)/) {
			$p->{'type'} = $1;
			$p->{'elements'} = $2;
			$p->{'rule'} = $3;
		}
		elsif($line =~ /^(\w+)\s*\[\s*(0x[0-9A-Fa-f]+)\s*\]/) {
			$p->{'type'} = $1;
			$p->{'elements'} = hex($2);
		}
		elsif($line =~ /^(\w+)\s*\{\s*(\d+)\s*\:\s*(\d+)\s*\}/) {
			$p->{'type'} = $1;
			$p->{'bit_hi'} = $2;
			$p->{'bit_lo'} = $3;
		}
		elsif($line =~ /^(\w+)\s*\{\s*(\d+)\s*\}/) {
			$p->{'type'} = $1;
			$p->{'bit_hi'} = $2;
			$p->{'bit_lo'} = $2;
		}
		elsif($line =~ /^(\w+)\s+in\s+(\w+)\{\s*(\d+)\s*\}/) {
			$p->{'type'} = $1;
			$p->{'field'} = $2;
			$p->{'bit_hi'} = $3;
			$p->{'bit_lo'} = $3;
		}
		elsif($line =~ /^(\w+)\s*(\(\s*.*)$/) {
			$p->{'type'} = $1;
			$p->{'rule'} = $2;
			while(!($p->{rule} =~ /\;$/)) {
				$p->{'rule'} .= shift @{$lines};
			}
		}
		elsif($line =~ /^(\w+)\s*=\s*(0x[0-9A-Fa-f]+)/) {
			$p->{'type'} = $1;
			$p->{'val'} = hex($2);
		}
		elsif($line =~ /^(\w+)\s*=\s*(\-?\d+)/) {
			$p->{'type'} = $1;
			$p->{'val'} = $2;
		}
		elsif($line =~ /^(\w+)\s*\=\s*(\(\s*.*)$/) {
			$p->{'type'} = $1;
			$p->{'rule'} = $2;
		}
		elsif($line =~ /^(\w+)\s*\=\s*(\w+\s*\(\s*.*)$/) {
			$p->{'type'} = $1;
			$p->{'rule'} = $2;
		}
		elsif($line =~ /^(enum|bitmap)/) {
			$p->{'type'} = $1;
			$p->{'enums'} = [];
			while(defined($line = shift @{$lines})) {
				if($line =~ /\{\s*(0x[0-9A-Fa-f]+)\s*,\s*\"([^\"]+)\"\s*\}/) {
					my $e = {};
					$e->{'val'} = $1;
					$e->{'name'} = $2;
					push @{$p->{enums}}, $e;
				}
				last if($line =~ /\}\;/);
			}
			next;
		}
		elsif($line =~ /^(\w+)\;?$/) {
			$p->{'type'} = $1;
		}

		warn "no type \"$line\"\n" if !defined $p->{type};
		next if !defined $p->{type};
		# make sure we processed it, even if we don't check the rules
		if(!defined $lut->{$p->{type}}) {
			if($line =~ /(\w+)\s*\((.*)\)/) {
				print "$1 - $2\n";
			}
			die "  ** ($p->{type}) $line\n"; # if ! $line =~ /(\w+)\s*\((.*)\)/;
		}
		$param->{'rules'}->{$lut->{$p->{type}}} = $p;
	}
	push @{$params}, $param;
}

sub get_section_data_from_symbol
{
	my ($sections, $sym) = @_;
	my $data;
	foreach my $section (@{$sections}) {
		next if $section->{index} != $sym->{st_shndx};
		$data = substr($section->{data}, $sym->{st_value} - $section->{sh_addr}, $sym->{st_size});
		last;
	}
	return $data;
}


#######################################################################################
##################################### subs ############################################

sub print_commented_bytes
{
	my ($name, $data) = @_;

	print "\t\"$name\" = \n";
	print "\tCOMMENTED_BYTES\n";
	print "\t{\n";
	print "\t\t<hex>";

	my @bytes = unpack "C*", $data;
	my $count = 0;
	foreach my $byte (@bytes) {
		if(0 == ($count & 0xF)) {
			print "\n\t\t";
		}
		printf "%02x ", $byte;
		$count++;
	}

	print "\n\t} END_COMMENTED_BYTES\n";
}
