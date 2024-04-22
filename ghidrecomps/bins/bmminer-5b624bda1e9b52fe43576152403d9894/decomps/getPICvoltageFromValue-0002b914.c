
/* WARNING: Unknown calling convention */

uchar getPICvoltageFromValue(int vol_value)

{
  double dVar1;
  
  dVar1 = DAT_0002b960 / (((double)(longlong)vol_value * 4.75) / DAT_0002b950 - DAT_0002b958) -
          DAT_0002b968;
  return (0.0 < dVar1) * (char)(longlong)dVar1;
}

