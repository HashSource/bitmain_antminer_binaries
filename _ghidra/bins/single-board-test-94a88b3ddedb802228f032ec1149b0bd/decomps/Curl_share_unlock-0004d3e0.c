
undefined4 Curl_share_unlock(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0x48);
  if (puVar1 != (uint *)0x0) {
    if (((*puVar1 & 1 << (param_2 & 0xff)) != 0) && ((code *)puVar1[3] != (code *)0x0)) {
      (*(code *)puVar1[3])(param_1,param_2,puVar1[4],puVar1,param_4);
    }
    return 0;
  }
  return 3;
}

