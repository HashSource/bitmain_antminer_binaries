
float conv_voltage(float param_1,int param_2)

{
  if (param_2 == 1) {
    param_1 = (float)((double)param_1 * 3.0 * DAT_0004b7b0 * DAT_0004b7b8);
  }
  else if (param_2 != 0) {
    if (param_2 == 2) {
      return (float)(((double)param_1 / DAT_0004b7a0) * DAT_0004b7a8);
    }
    puts("Convertion type incorrect... Doing no conversion");
    return param_1;
  }
  return param_1;
}

