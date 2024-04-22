
char * set_float_100_to_250(undefined4 param_1,float *param_2)

{
  char *pcVar1;
  float fVar2;
  
  pcVar1 = (char *)opt_set_floatval();
  if (pcVar1 == (char *)0x0) {
    fVar2 = *param_2;
    if (-1 < (int)((uint)(fVar2 < DAT_0001bfec) << 0x1f)) {
      pcVar1 = "Value out of range";
      if (fVar2 == DAT_0001bff0 || fVar2 < DAT_0001bff0 != (NAN(fVar2) || NAN(DAT_0001bff0))) {
        pcVar1 = (char *)0x0;
      }
      return pcVar1;
    }
    pcVar1 = "Value out of range";
  }
  return pcVar1;
}

