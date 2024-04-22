
undefined4
keyWrapCryptoPro(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined4 uVar1;
  undefined auStack_38 [36];
  
  keyDiversifyCryptoPro();
  gost_key(param_1,auStack_38);
  uVar1 = param_3[1];
  *param_5 = *param_3;
  param_5[1] = uVar1;
  gost_enc(param_1,param_4,param_5 + 2,4);
  gost_mac_iv(param_1,0x20,param_3,param_4,0x20,param_5 + 10);
  return 1;
}

