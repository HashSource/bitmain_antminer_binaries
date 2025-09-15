
undefined4 Curl_fnmatch(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0 || param_3 == 0) {
    return 2;
  }
  uVar1 = loop(param_2,param_3);
  return uVar1;
}

