
int getVolValueFromPICvoltage(int param_1)

{
  return ((int)(longlong)(((364.0704 / ((double)(longlong)param_1 + 30.72) + 32.79) * 100.0) / 4.75)
         / 10) * 10;
}

