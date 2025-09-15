
float conv_temperature(float param_1,int param_2)

{
  if (param_2 == 1) {
    param_1 = param_1 * 503.975 * 0.00024414062 - 273.15;
  }
  else if (param_2 != 0) {
    if (param_2 == 2) {
      return ((param_1 + 273.15) * 4096.0) / 503.975;
    }
    puts("Conversion type incorrect... Doing no conversion");
    return param_1;
  }
  return param_1;
}

