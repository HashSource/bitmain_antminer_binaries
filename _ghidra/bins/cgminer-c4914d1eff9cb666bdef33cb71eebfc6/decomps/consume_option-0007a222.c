
void consume_option(int *argc,char **argv,uint optnum)

{
  uint optnum_local;
  char **argv_local;
  int *argc_local;
  
  memmove(argv + optnum,argv + optnum + 1,(*argc - optnum) * 4);
  *argc = *argc + -1;
  return;
}

