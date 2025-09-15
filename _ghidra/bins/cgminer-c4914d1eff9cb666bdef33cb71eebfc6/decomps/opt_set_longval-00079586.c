
char * opt_set_longval(char *arg,long *l)

{
  int *piVar1;
  long lVar2;
  char *pcVar3;
  long *l_local;
  char *arg_local;
  char *endp;
  
  piVar1 = __errno_location();
  *piVar1 = 0;
  lVar2 = strtol(arg,&endp,0);
  *l = lVar2;
  if ((*endp == '\0') && (*arg != '\0')) {
    piVar1 = __errno_location();
    if (*piVar1 == 0) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = arg_bad("\'%s\' is out of range",arg);
    }
  }
  else {
    pcVar3 = arg_bad("\'%s\' is not a number",arg);
  }
  return pcVar3;
}

