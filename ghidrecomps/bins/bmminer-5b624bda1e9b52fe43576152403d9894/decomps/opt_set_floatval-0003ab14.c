
/* WARNING: Unknown calling convention */

char * opt_set_floatval(char *arg,float *f)

{
  char **ppcVar1;
  char *pcVar2;
  float fVar3;
  char *endp;
  
  ppcVar1 = (char **)__errno_location();
  *ppcVar1 = (char *)0x0;
  fVar3 = strtof(arg,&endp);
  *f = fVar3;
  if ((*endp == '\0') && (*arg != '\0')) {
    pcVar2 = *ppcVar1;
    if (pcVar2 != (char *)0x0) {
      pcVar2 = arg_bad(DAT_0003ab58,arg);
    }
  }
  else {
    pcVar2 = arg_bad(DAT_0003ab5c,arg);
  }
  return pcVar2;
}

