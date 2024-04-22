
uint getPICvoltageFromValue(int param_1)

{
  double dVar1;
  
  dVar1 = DAT_00024938 / (((double)(longlong)param_1 * 4.75) / DAT_00024928 - DAT_00024930) -
          DAT_00024940;
  return (uint)(0.0 < dVar1) * (int)(longlong)dVar1 & 0xff;
}

