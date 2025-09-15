
undefined4
pkey_gost94_derive(EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  EVP_PKEY *pEVar1;
  undefined4 uVar2;
  
  pEVar1 = EVP_PKEY_CTX_get0_peerkey(param_1);
  EVP_PKEY_CTX_get0_pkey(param_1);
  *param_3 = 0x20;
  if (param_2 != 0) {
    uVar2 = gost_get0_priv_key();
    uVar2 = make_cp_exchange_key(uVar2,pEVar1,param_2,param_4);
    return uVar2;
  }
  return 1;
}

