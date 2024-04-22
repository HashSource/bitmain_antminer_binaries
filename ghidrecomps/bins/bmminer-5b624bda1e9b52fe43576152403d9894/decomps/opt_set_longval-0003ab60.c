
/* WARNING: Unknown calling convention */

char * opt_set_longval(char *arg,long *l)

{
  char **ppcVar1;
  long lVar2;
  char *pcVar3;
  char *endp;
  
  ppcVar1 = (char **)__errno_location();
  *ppcVar1 = (char *)0x0;
  lVar2 = strtol(arg,&endp,0);
  *l = lVar2;
  if ((*endp == '\0') && (*arg != '\0')) {
    pcVar3 = *ppcVar1;
    if (pcVar3 != (char *)0x0) {
      pcVar3 = arg_bad(DAT_0003aba0,arg);
    }
  }
  else {
    pcVar3 = arg_bad(DAT_0003aba4,arg);
  }
  return pcVar3;
}

