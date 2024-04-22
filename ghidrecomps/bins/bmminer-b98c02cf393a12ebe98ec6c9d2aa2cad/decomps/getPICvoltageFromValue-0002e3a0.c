
uint getPICvoltageFromValue(int param_1)

{
  double dVar1;
  
  dVar1 = DAT_0002e3f8 / (((double)(longlong)param_1 * 4.75) / DAT_0002e3e8 - DAT_0002e3f0) -
          DAT_0002e400;
  return (uint)(0.0 < dVar1) * (int)(longlong)dVar1 & 0xff;
}

