
undefined4 Curl_hash_str(byte *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 extraout_r1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (param_1 < param_1 + param_2) {
    uVar1 = 0x1505;
    pbVar3 = param_1;
    do {
      pbVar2 = pbVar3 + 1;
      uVar1 = (uint)*pbVar3 ^ uVar1 * 0x21;
      pbVar3 = pbVar2;
    } while (pbVar2 != param_1 + param_2);
  }
  else {
    uVar1 = 0x1505;
  }
  __aeabi_uidivmod(uVar1,param_3);
  return extraout_r1;
}

