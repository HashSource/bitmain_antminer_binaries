
char * opt_verusage_and_exit(char *extra)

{
  char *pcVar1;
  char *extra_local;
  
  printf("%s\nBuilt with bitmain_c5 mining support.\n",packagename);
  pcVar1 = opt_usage(opt_argv0,extra);
  printf("%s",pcVar1);
  fflush(stdout);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

