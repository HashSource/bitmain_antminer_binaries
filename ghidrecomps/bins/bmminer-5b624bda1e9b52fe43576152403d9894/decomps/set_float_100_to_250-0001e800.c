
/* WARNING: Unknown calling convention */

char * set_float_100_to_250(char *arg,float *i)

{
  char *pcVar1;
  char *err;
  float fVar2;
  
  pcVar1 = opt_set_floatval(arg,i);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  fVar2 = *i;
  if ((-1 < (int)((uint)(fVar2 < DAT_0001e830) << 0x1f)) &&
     (fVar2 == DAT_0001e834 || fVar2 < DAT_0001e834 != (NAN(fVar2) || NAN(DAT_0001e834)))) {
    return (char *)0x0;
  }
  return DAT_0001e838;
}

