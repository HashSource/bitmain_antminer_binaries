
char * set_float_100_to_250(undefined4 param_1,float *param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)opt_set_floatval();
  if (pcVar1 == (char *)0x0) {
    if (-1 < (int)((uint)(*param_2 < 100.0) << 0x1f)) {
      pcVar1 = "Value out of range";
      if (*param_2 <= 250.0) {
        pcVar1 = (char *)0x0;
      }
      return pcVar1;
    }
    pcVar1 = "Value out of range";
  }
  return pcVar1;
}

