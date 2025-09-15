
void opt_set_floatval(char *param_1,float *param_2)

{
  int *piVar1;
  float fVar2;
  char *local_14;
  
  piVar1 = __errno_location();
  *piVar1 = 0;
  fVar2 = strtof(param_1,&local_14);
  *param_2 = fVar2;
  if ((*local_14 == '\0') && (*param_1 != '\0')) {
    if (*piVar1 != 0) {
      arg_bad("\'%s\' is out of range",param_1);
      return;
    }
  }
  else {
    arg_bad("\'%s\' is not a number",param_1);
  }
  return;
}

