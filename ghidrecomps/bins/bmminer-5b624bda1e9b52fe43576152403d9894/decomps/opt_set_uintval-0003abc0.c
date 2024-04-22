
/* WARNING: Unknown calling convention */

char * opt_set_uintval(char *arg,uint *ui)

{
  char *pcVar1;
  char *err;
  int i;
  
  pcVar1 = opt_set_intval(arg,&i);
  if (pcVar1 == (char *)0x0) {
    if (i < 0) {
      pcVar1 = arg_bad(DAT_0003abe8,arg);
    }
    else {
      *ui = i;
    }
  }
  return pcVar1;
}

