
undefined4 siphash_signctx_init(EVP_PKEY_CTX *param_1,EVP_MD_CTX *param_2)

{
  void *pvVar1;
  EVP_PKEY *pEVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  
  pvVar1 = EVP_PKEY_CTX_get_data(param_1);
  pEVar2 = EVP_PKEY_CTX_get0_pkey(param_1);
  iVar3 = EVP_PKEY_get0_siphash(pEVar2,&local_14);
  if (iVar3 == 0) {
    return 0;
  }
  if (local_14 == 0x10) {
    EVP_MD_CTX_set_flags(param_2,0x100);
    EVP_MD_CTX_set_update_fn(param_2,0x1688c5);
    uVar4 = SipHash_Init((int)pvVar1 + 0x10,iVar3,0);
    return uVar4;
  }
  return 0;
}

