
float conv_voltage_ext_ch(float param_1,int param_2)

{
  if (param_2 == 1) {
    param_1 = param_1 * DAT_0004b80c * DAT_0004b814;
  }
  else if (param_2 != 0) {
    if (param_2 == 2) {
      return (param_1 / DAT_0004b80c) * DAT_0004b810;
    }
    puts("Convertion type incorrect... Doing no conversion");
    return param_1;
  }
  return param_1;
}

