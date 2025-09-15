
int ConvirtTotalRate(int totalRate)

{
  _Bool _Var1;
  int totalRate_local;
  int t11a_eco_rate;
  
  _Var1 = is_economic_mode();
  if ((_Var1) && (_Var1 = is_T11(), !_Var1)) {
    totalRate = 0x445c;
  }
  return totalRate;
}

