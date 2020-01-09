   if ( $ARGV[0] =~ m/^[AF]_(\d{4,})[A-Z]\d/ )
   {
      print length($1);
   }
   else
   {
      print 0;
   }
