
uint pkey_rsa_verify(int param_1,uchar *param_2,uint param_3,uchar *param_4,uint param_5)

{
  EVP_MD *md;
  uint uVar1;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  RSA *rsa;
  uint local_24 [2];
  
  iVar4 = *(int *)(param_1 + 0x14);
  md = *(EVP_MD **)(iVar4 + 0x18);
  rsa = (RSA *)(*(EVP_PKEY **)(param_1 + 8))->save_parameters;
  if (md == (EVP_MD *)0x0) {
    puVar3 = *(uchar **)(iVar4 + 0x28);
    if (puVar3 == (uchar *)0x0) {
      iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
      puVar3 = (uchar *)CRYPTO_malloc(iVar2,"crypto/rsa/rsa_pmeth.c",0x6a);
      *(uchar **)(iVar4 + 0x28) = puVar3;
      if (puVar3 == (uchar *)0x0) {
LAB_0015cbb2:
        ERR_put_error(4,0xa7,0x41,"crypto/rsa/rsa_pmeth.c",0x6b);
        return 0xffffffff;
      }
    }
    local_24[0] = RSA_public_decrypt(param_3,param_2,puVar3,rsa,*(int *)(iVar4 + 0x14));
    if (local_24[0] == 0) {
      return 0;
    }
  }
  else {
    if (*(int *)(iVar4 + 0x14) == 1) {
      iVar4 = EVP_MD_type(md);
      uVar1 = RSA_verify(iVar4,param_4,param_5,param_2,param_3,rsa);
      return uVar1;
    }
    uVar1 = EVP_MD_size(md);
    if (param_5 != uVar1) {
      ERR_put_error(4,0x95,0x8f,"crypto/rsa/rsa_pmeth.c",0xfe);
      return 0xffffffff;
    }
    if (*(int *)(iVar4 + 0x14) != 5) {
      if (*(int *)(iVar4 + 0x14) != 6) {
        return 0xffffffff;
      }
      puVar3 = *(uchar **)(iVar4 + 0x28);
      if (puVar3 == (uchar *)0x0) {
        iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        puVar3 = (uchar *)CRYPTO_malloc(iVar2,"crypto/rsa/rsa_pmeth.c",0x6a);
        *(uchar **)(iVar4 + 0x28) = puVar3;
        if (puVar3 == (uchar *)0x0) goto LAB_0015cbb2;
      }
      iVar2 = RSA_public_decrypt(param_3,param_2,puVar3,rsa,3);
      if (iVar2 < 1) {
        return 0;
      }
      iVar4 = RSA_verify_PKCS1_PSS_mgf1
                        (rsa,param_4,*(EVP_MD **)(iVar4 + 0x18),*(EVP_MD **)(iVar4 + 0x1c),
                         *(uchar **)(iVar4 + 0x28),*(int *)(iVar4 + 0x20));
      if (0 < iVar4) {
        return 1;
      }
      return 0;
    }
    iVar2 = pkey_rsa_verifyrecover(param_1,0,local_24,param_2,param_3);
    if (iVar2 < 1) {
      return 0;
    }
  }
  if (param_5 != local_24[0]) {
    return 0;
  }
  iVar4 = memcmp(param_4,*(void **)(iVar4 + 0x28),param_5);
  return (uint)(iVar4 == 0);
}

