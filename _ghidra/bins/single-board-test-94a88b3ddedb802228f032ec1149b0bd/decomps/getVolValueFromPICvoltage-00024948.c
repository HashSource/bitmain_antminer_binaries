
int getVolValueFromPICvoltage(byte param_1)

{
  return ((int)(longlong)(((364.0704 / ((double)param_1 + 30.72) + 32.79) * 100.0) / 4.75) / 10) *
         10;
}

