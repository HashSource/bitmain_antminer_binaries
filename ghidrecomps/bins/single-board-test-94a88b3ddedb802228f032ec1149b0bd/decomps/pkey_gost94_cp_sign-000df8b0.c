
undefined4
pkey_gost94_cp_sign(EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4,
                   undefined4 param_5)

{
  EVP_PKEY *pkey;
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_3 != (undefined4 *)0x0) {
    if (param_2 == 0) {
      *param_3 = 0x40;
      return 1;
    }
    pvVar1 = EVP_PKEY_get0(pkey);
    iVar2 = gost_do_sign(param_4,param_5,pvVar1);
    if (iVar2 != 0) {
      uVar3 = pack_sign_cp(iVar2,0x20,param_2,param_3);
      return uVar3;
    }
  }
  return 0;
}

