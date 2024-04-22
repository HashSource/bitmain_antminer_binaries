
uchar getPICvoltageFromValue(int vol_value)

{
  double dVar1;
  int vol_value_local;
  uchar temp_voltage;
  
  dVar1 = DAT_000321b0 - ((double)(longlong)vol_value * DAT_000321a0) / DAT_000321a8;
  return (0.0 < dVar1) * (char)(longlong)dVar1;
}

