
/* WARNING: Unknown calling convention */

char * set_temp_cutoff(char *arg)

{
  uint uVar1;
  
  if ((arg != (char *)0x0) && (*arg != '\0')) {
    uVar1 = strtol(arg,(char **)0x0,10);
    if (200 < uVar1) {
      return "Invalid value passed to set temp cutoff";
    }
    temp_cutoff_str = arg;
    return (char *)0x0;
  }
  return "Invalid parameters for set temp cutoff";
}

