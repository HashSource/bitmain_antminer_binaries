
char * set_temp_cutoff(char *param_1)

{
  uint uVar1;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    uVar1 = strtol(param_1,(char **)0x0,10);
    if (200 < uVar1) {
      return "Invalid value passed to set temp cutoff";
    }
    temp_cutoff_str = param_1;
    return (char *)0x0;
  }
  return "Invalid parameters for set temp cutoff";
}

