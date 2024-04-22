
double curlx_tvdiff_secs(int param_1,int param_2,int param_3,int param_4)

{
  double dVar1;
  
  if (param_1 == param_3) {
    dVar1 = (double)(longlong)(param_2 - param_4) / DAT_0003d210;
  }
  else {
    dVar1 = (double)(longlong)(param_1 - param_3) +
            (double)(longlong)(param_2 - param_4) / DAT_0003d210;
  }
  return dVar1;
}

