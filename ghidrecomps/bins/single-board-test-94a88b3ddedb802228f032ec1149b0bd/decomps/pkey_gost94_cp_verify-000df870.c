
EVP_PKEY *
pkey_gost94_cp_verify
          (EVP_PKEY_CTX *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  EVP_PKEY *pkey;
  DSA_SIG *a;
  void *pvVar1;
  undefined4 uVar2;
  
  uVar2 = param_4;
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  a = (DSA_SIG *)unpack_cp_signature(param_2,param_3);
  if (a != (DSA_SIG *)0x0) {
    if (pkey != (EVP_PKEY *)0x0) {
      pvVar1 = EVP_PKEY_get0(pkey);
      pkey = (EVP_PKEY *)gost_do_verify(param_4,param_5,a,pvVar1,uVar2);
    }
    DSA_SIG_free(a);
    return pkey;
  }
  return (EVP_PKEY *)0x0;
}

