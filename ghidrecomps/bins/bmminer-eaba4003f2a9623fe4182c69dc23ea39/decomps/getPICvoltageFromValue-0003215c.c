
uchar getPICvoltageFromValue(int vol_value)

{
  double dVar1;
  int vol_value_local;
  uchar temp_voltage;
  
  dVar1 = 1608.420446 - ((double)(longlong)vol_value * 170.423497) / 100.0;
  return (0.0 < dVar1) * (char)(longlong)dVar1;
}

