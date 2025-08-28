
char * set_float_125_to_500(char *arg,float *i)

{
  char *pcVar1;
  float *i_local;
  char *arg_local;
  char *err;
  
  pcVar1 = opt_set_floatval(arg,i);
  if (pcVar1 == (char *)0x0) {
    if (((int)((uint)(*i < 125.0) << 0x1f) < 0) || (500.0 < *i)) {
      pcVar1 = "Value out of range";
    }
    else {
      pcVar1 = (char *)0x0;
    }
  }
  return pcVar1;
}

