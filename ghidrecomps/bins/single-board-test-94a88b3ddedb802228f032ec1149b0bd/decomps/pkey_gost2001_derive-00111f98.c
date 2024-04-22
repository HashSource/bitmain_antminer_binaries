
undefined4
pkey_gost2001_derive(EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  EVP_PKEY *pkey;
  EVP_PKEY *pkey_00;
  void *pvVar1;
  EC_KEY *key;
  EC_POINT *pEVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  pvVar1 = EVP_PKEY_CTX_get_data(param_1);
  if (*(int *)((int)pvVar1 + 8) == 0) {
    ERR_GOST_error(0x79,0x80,DAT_00112000,0x55,param_4);
    uVar5 = 0;
  }
  else {
    if (param_2 == 0) {
      *param_3 = 0x20;
      return 0x20;
    }
    key = (EC_KEY *)EVP_PKEY_get0(pkey_00);
    pEVar2 = EC_KEY_get0_public_key(key);
    pvVar3 = EVP_PKEY_get0(pkey);
    uVar5 = 1;
    uVar4 = VKO_compute_key_isra_0(param_2,pEVar2,pvVar3,*(undefined4 *)((int)pvVar1 + 8));
    *param_3 = uVar4;
  }
  return uVar5;
}

