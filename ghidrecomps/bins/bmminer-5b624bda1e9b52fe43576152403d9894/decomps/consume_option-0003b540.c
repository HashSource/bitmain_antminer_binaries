
/* WARNING: Unknown calling convention */

void consume_option(int *argc,char **argv,uint optnum)

{
  memmove(argv + optnum,argv + optnum + 1,(*argc - optnum) * 4);
  *argc = *argc + -1;
  return;
}

