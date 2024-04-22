
float conv_temperature(float param_1,int param_2)

{
  if (param_2 == 1) {
    param_1 = (float)((double)param_1 * DAT_0004b890 * DAT_0004b898 - DAT_0004b880);
  }
  else if (param_2 != 0) {
    if (param_2 == 2) {
      return (float)((((double)param_1 + DAT_0004b880) * DAT_0004b888) / DAT_0004b890);
    }
    puts("Conversion type incorrect... Doing no conversion");
    return param_1;
  }
  return param_1;
}

