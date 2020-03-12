#!/usr/bin/perl

#
# Copyright 2014, Cypress Semiconductor
# All Rights Reserved.
#
# This is UNPUBLISHED PROPRIETARY SOURCE CODE of Cypress Semiconductor;
# the contents of this file may not be disclosed to third parties, copied
# or duplicated in any form, in whole or in part, without the prior
# written permission of Cypress Semiconductor.
#
#print "$0 @ARGV \n";
my $params = {};
while(defined(my $arg = shift @ARGV)) {
  my $type;
  if($arg =~ /^\-(\w+)$/) {
    $type = $1;
    $params->{$type} = "";
    my $next_arg = shift @ARGV;
    next if !defined $next_arg;
    if($next_arg =~ /^\-(\w+)$/) {
      unshift @ARGV, $next_arg;
    }
    else {
      $params->{$type} = $next_arg;
    }
  }
  else {
    die "bad args \"$arg @ARGV\"\n";
  }
}

my $tools_path = $params->{tools_path};
my $build_loc =  $params->{build_path} // ".";
my $id_file = $params->{id};
my $btp_file = $params->{btp};
my $mini_driver = $params->{mini};
my $config_file = $params->{hex};
my $com_port = $params->{uart};
$com_port = undef if $com_port eq "AUTO";
my $baud_rate = "AUTO";
my $detected_baud;
my $addl_flags;
my $baud_file_cmd;


if(defined $params->{baudfile} && -f $params->{baudfile}) {
    $baud_file_cmd = "-BAUDRATEFILE \"" . $params->{baudfile} . "\"";
}
if(defined $params->{flags} && -f $params->{flags}) {
  open(my $FLAGS, "<", $params->{flags}) or die "Could not open file: $!";
  $addl_flags = <$FLAGS>;
  $addl_flags =~ s/\r|\n//g;
  if($addl_flags =~ /-PORT (\S+)/) {
    $com_port = $1;
    $addl_flags =~ s/-PORT (\S+)//;
  }
  close $FLAGS;
}

my $os_exec_ext = "";
$os_exec_ext = ".exe" if $^O eq 'MSWin32';

#update paths for chipload and DetectAndId
my $chip_load = $tools_path . "/ChipLoad/ChipLoad" . $os_exec_ext;
my $detect_and_id = $tools_path . "/DetectAndId/DetAndId" . $os_exec_ext;


#Find the COM port
my $chip_id       = 0;
my $expected_str  = 0;
my $device_found  = 0;
my $id_file_line  = 0;
my $line          = 0;

# Open ID file and get the chip ID.
open INFILE, "<:raw", $id_file or die "cant open " . $id_file;

($id_file_line) = <INFILE>;

chomp($id_file_line);      # Remove trailing newline
$id_file_line =~ s/^\s+//; # Remove leading spaces
$id_file_line =~ s/\s+$//; # Remove trailing spaces

if($com_port)
{
    $device_found = 1;
    $detected_baud = "AUTO";

    #do not pass -NOHCIRESET if DetectAndId is not used
    $addl_flags =~ s/-NOHCIRESET//g;
}
else
{
    print "\nDetecting serial port ...";

    # Get chip ID (first word)
    ($chip_id) = $id_file_line =~ /\A([^:\s]+)/;

    my $det_id_log_path = $build_loc . "/det_and_id.log";
    # Call DetectAndId to identify the board
    #print "$detect_and_id -TRAN UART -BAUDRATE $baud_rate -IDFILE $id_file $baud_file_cmd\n";
    # enable for debug output from detect_and_id:
    #$output = `"$detect_and_id" -TRAN UART -BAUDRATE $baud_rate -IDFILE "$id_file" $baud_file_cmd -DEBUG 2 2> $det_id_log_path`;
    $output = `"$detect_and_id" -TRAN UART -BAUDRATE $baud_rate -IDFILE "$id_file" $baud_file_cmd 2> $det_id_log_path`;

    # Expected string
    ($expected_str) = qr/(.*\S)\s+HCI\s+$chip_id/;
    # $1 will be table1, table2, table3. delim is a newline
    my @tables = split(/\n/, $output);
    foreach $line (@tables)
    {
        chomp($line);      # Remove trailing newline
        $line =~ s/^\s+//; # Remove leading spaces
        $line =~ s/\s+$//; # Remove trailing spaces

        # Check if DetectAndId output contains the expected string
        if ( $line =~ $expected_str )
        {
            # Get COM port (first word)
            ($com_port) = $line =~ /\A([^:\s]+)/;
            ($detected_baud) = $line =~ /(\w+)$/;
            $device_found = 1;
            last;
        } else {
        }
    }

    close INFILE;
}

if ( $device_found == 0 )
{
    die "\nSerial port not detected...\n";
}
else
{
    print "\nFound serial port : $com_port\n\nDownloading FW ...\n";
    my $download_log_path = $build_loc . "/download.log";

    #Download FW
    #print "$chip_load -BLUETOOLMODE -PORT $com_port -LAUNCHADDRESS 0x00000000 -BAUDRATE $detected_baud -NOVERIFY -CHECKCRC -MINIDRIVER $mini_driver -BTP $btp_file -CONFIG $config_file ${addl_flags}\n";
    qx{"$chip_load" -BLUETOOLMODE -PORT $com_port -LAUNCHADDRESS 0x00000000 -BAUDRATE $detected_baud -NOVERIFY -CHECKCRC -MINIDRIVER "${mini_driver}" -BTP "${btp_file}" -CONFIG ${config_file} -LOGTO "$download_log_path" ${addl_flags}};
	exit ($? >> 8);
}
