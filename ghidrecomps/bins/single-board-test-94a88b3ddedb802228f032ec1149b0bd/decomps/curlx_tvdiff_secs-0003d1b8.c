
undefined4 curlx_tvdiff_secs(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == param_3) {
    uVar1 = SUB84((double)(longlong)(param_2 - param_4) / 1000000.0,0);
  }
  else {
    uVar1 = SUB84((double)(longlong)(param_1 - param_3) +
                  (double)(longlong)(param_2 - param_4) / 1000000.0,0);
  }
  return uVar1;
}

