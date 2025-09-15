
char * opt_version_and_exit(char *version)

{
  char *version_local;
  
  puts(version);
  fflush(stdout);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

