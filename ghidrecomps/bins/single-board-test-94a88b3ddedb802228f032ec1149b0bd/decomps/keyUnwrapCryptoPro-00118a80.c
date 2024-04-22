
int keyUnwrapCryptoPro(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined auStack_3c [4];
  undefined auStack_38 [36];
  
  keyDiversifyCryptoPro();
  gost_key(param_1,auStack_38);
  gost_dec(param_1,param_3 + 8,param_4,4);
  gost_mac_iv(param_1,0x20,param_3,param_4,0x20,auStack_3c);
  uVar1 = memcmp(auStack_3c,(void *)(param_3 + 0x28),4);
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

