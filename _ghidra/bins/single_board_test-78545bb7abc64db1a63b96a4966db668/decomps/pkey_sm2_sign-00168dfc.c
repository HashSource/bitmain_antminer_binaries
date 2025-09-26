
int pkey_sm2_sign(int param_1,int param_2,uint *param_3,undefined4 param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  EC_KEY *eckey;
  uint local_1c [2];
  
  eckey = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x18);
  uVar1 = ECDSA_size(eckey);
  if ((int)uVar1 < 1) {
    iVar2 = 0;
  }
  else if (param_2 == 0) {
    *param_3 = uVar1;
    iVar2 = 1;
  }
  else {
    if (*param_3 < uVar1) {
      ERR_put_error(0x35,0x70,0x6b,"crypto/sm2/sm2_pmeth.c",0x6a);
      return 0;
    }
    iVar2 = sm2_sign(param_4,param_5,param_2,local_1c,eckey);
    if (0 < iVar2) {
      iVar2 = 1;
      *param_3 = local_1c[0];
    }
  }
  return iVar2;
}

