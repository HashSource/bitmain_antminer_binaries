
/* WARNING: Unknown calling convention */

char * opt_set_floatval(char *arg,float *f)

{
  int *piVar1;
  char *pcVar2;
  float fVar3;
  char *endp;
  
  piVar1 = __errno_location();
  *piVar1 = 0;
  fVar3 = strtof(arg,&endp);
  *f = fVar3;
  if ((*endp == '\0') && (*arg != '\0')) {
    pcVar2 = (char *)*piVar1;
    if (pcVar2 != (char *)0x0) {
      pcVar2 = arg_bad("\'%s\' is out of range",arg);
    }
  }
  else {
    pcVar2 = arg_bad("\'%s\' is not a number",arg);
  }
  return pcVar2;
}

