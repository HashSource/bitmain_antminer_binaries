
char * set_float_125_to_500(char *arg,float *i)

{
  char *pcVar1;
  float fVar2;
  float *i_local;
  char *arg_local;
  char *err;
  
  pcVar1 = opt_set_floatval(arg,i);
  if (pcVar1 == (char *)0x0) {
    if ((*i < DAT_00049d1c) ||
       (fVar2 = *i,
       fVar2 != DAT_00049d20 && fVar2 < DAT_00049d20 == (NAN(fVar2) || NAN(DAT_00049d20)))) {
      pcVar1 = "Value out of range";
    }
    else {
      pcVar1 = (char *)0x0;
    }
  }
  return pcVar1;
}

