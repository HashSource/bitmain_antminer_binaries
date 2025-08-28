
uint getPICvoltageFromValue(int param_1)

{
  double dVar1;
  
  dVar1 = 364.0704 / (((double)(longlong)param_1 * 4.75) / 100.0 - 32.79) - 30.72;
  return (uint)(0.0 < dVar1) * (int)(longlong)dVar1 & 0xff;
}

