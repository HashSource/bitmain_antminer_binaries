
/* WARNING: Unknown calling convention */

char * opt_set_ulongval(char *arg,ulong *ul)

{
  char *pcVar1;
  long l;
  
  pcVar1 = opt_set_longval(arg,&l);
  if ((pcVar1 == (char *)0x0) && (*ul = l, l < 0)) {
    pcVar1 = arg_bad("\'%s\' is negative",arg);
  }
  return pcVar1;
}

