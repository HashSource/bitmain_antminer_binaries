
char * set_float_100_to_250(char *arg,float *i)

{
  char *pcVar1;
  float fVar2;
  float *i_local;
  char *arg_local;
  char *err;
  
  pcVar1 = opt_set_floatval(arg,i);
  if (pcVar1 == (char *)0x0) {
    if (((int)((uint)(*i < DAT_00049d58) << 0x1f) < 0) ||
       (fVar2 = *i,
       fVar2 != DAT_00049d5c && fVar2 < DAT_00049d5c == (NAN(fVar2) || NAN(DAT_00049d5c)))) {
      pcVar1 = "Value out of range";
    }
    else {
      pcVar1 = (char *)0x0;
    }
  }
  return pcVar1;
}

