
/* WARNING: Unknown calling convention */

uchar getPICvoltageFromValue(int vol_value)

{
  double dVar1;
  
  dVar1 = 364.0704 / (((double)(longlong)vol_value * 4.75) / 100.0 - 32.79) - 30.72;
  return (0.0 < dVar1) * (char)(longlong)dVar1;
}

