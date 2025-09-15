
/* WARNING: Unknown calling convention */

char * opt_version_and_exit(char *version)

{
  puts(version);
  fflush(stdout);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

