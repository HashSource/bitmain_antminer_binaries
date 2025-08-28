
float conv_voltage(float param_1,int param_2)

{
  if (param_2 == 1) {
    param_1 = param_1 * 3.0 * 1000.0 * 0.00024414062;
  }
  else if (param_2 != 0) {
    if (param_2 == 2) {
      return (param_1 / 3000.0) * 4096.0;
    }
    puts("Convertion type incorrect... Doing no conversion");
    return param_1;
  }
  return param_1;
}

