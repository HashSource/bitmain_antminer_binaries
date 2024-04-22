
undefined4 curl_easy_setopt(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (param_1 == 0) {
    uVar1 = 0x2b;
  }
  else {
    uStack_8 = param_3;
    uStack_4 = param_4;
    uVar1 = Curl_setopt(param_1,param_2,&uStack_8);
  }
  return uVar1;
}

