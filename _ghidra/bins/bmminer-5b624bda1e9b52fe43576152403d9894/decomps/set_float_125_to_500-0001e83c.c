
/* WARNING: Unknown calling convention */

char * set_float_125_to_500(char *arg,float *i)

{
  char *pcVar1;
  
  pcVar1 = opt_set_floatval(arg,i);
  if (pcVar1 != (char *)0x0) {
    return pcVar1;
  }
  if ((-1 < (int)((uint)(*i < 125.0) << 0x1f)) && (*i <= 500.0)) {
    return (char *)0x0;
  }
  return "Value out of range";
}

