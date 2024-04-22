
undefined4 Curl_str2addr(char *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack_24 [4];
  undefined auStack_20 [20];
  
  iVar1 = inet_pton(2,param_1,auStack_24);
  if (iVar1 < 1) {
    iVar1 = inet_pton(10,param_1,auStack_20);
    if (iVar1 < 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = Curl_ip2addr(10,auStack_20,param_1,param_2);
    }
  }
  else {
    uVar2 = Curl_ip2addr(2,auStack_24,param_1,param_2);
  }
  return uVar2;
}

