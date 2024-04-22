
/* WARNING: Unknown calling convention */

char * set_temp_cutoff(char *arg)

{
  uint uVar1;
  
  if ((arg != (char *)0x0) && (*arg != '\0')) {
    uVar1 = strtol(arg,(char **)0x0,10);
    if (200 < uVar1) {
      return DAT_0001ec58;
    }
    *(char **)(DAT_0001ec5c + 0x420) = arg;
    return (char *)0x0;
  }
  return DAT_0001ec54;
}

