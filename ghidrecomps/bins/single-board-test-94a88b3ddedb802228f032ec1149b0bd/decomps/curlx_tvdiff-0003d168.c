
int curlx_tvdiff(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_1 - param_3 < 0x20c49b) {
    iVar1 = (param_1 - param_3) * 1000 + (param_2 - param_4) / 1000;
  }
  else {
    iVar1 = 0x7fffffff;
  }
  return iVar1;
}

