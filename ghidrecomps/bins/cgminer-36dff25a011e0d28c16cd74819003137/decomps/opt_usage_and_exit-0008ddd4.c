
char * opt_usage_and_exit(char *extra)

{
  char *pcVar1;
  char *extra_local;
  
  pcVar1 = opt_usage(opt_argv0,extra);
  printf("%s",pcVar1);
  fflush(stdout);
                    /* WARNING: Subroutine does not return */
  exit(0);
}

