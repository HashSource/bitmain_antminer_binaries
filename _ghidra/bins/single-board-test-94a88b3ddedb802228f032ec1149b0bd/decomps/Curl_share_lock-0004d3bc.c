
undefined4 Curl_share_lock(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(param_1 + 0x48);
  if (puVar1 != (uint *)0x0) {
    if (((*puVar1 & 1 << (param_2 & 0xff)) != 0) && ((code *)puVar1[2] != (code *)0x0)) {
      (*(code *)puVar1[2])();
    }
    return 0;
  }
  return 3;
}

