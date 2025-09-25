
size_t pkey_rsa_verifyrecover(int param_1,uchar *param_2,size_t *param_3,uchar *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  uchar *to;
  size_t __n;
  int iVar5;
  size_t local_24 [2];
  
  iVar5 = *(int *)(param_1 + 0x14);
  if (*(EVP_MD **)(iVar5 + 0x18) == (EVP_MD *)0x0) {
    __n = RSA_public_decrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x18),
                             *(int *)(iVar5 + 0x14));
  }
  else {
    if (*(int *)(iVar5 + 0x14) == 5) {
      to = *(uchar **)(iVar5 + 0x28);
      if (to == (uchar *)0x0) {
        iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        to = (uchar *)CRYPTO_malloc(iVar2,"crypto/rsa/rsa_pmeth.c",0x6a);
        *(uchar **)(iVar5 + 0x28) = to;
        if (to == (uchar *)0x0) {
          ERR_put_error(4,0xa7,0x41,"crypto/rsa/rsa_pmeth.c",0x6b);
          return 0xffffffff;
        }
      }
      iVar2 = RSA_public_decrypt(param_5,param_4,to,*(RSA **)(*(int *)(param_1 + 8) + 0x18),5);
      if (iVar2 < 1) {
        return 0;
      }
      __n = iVar2 - 1;
      bVar1 = *(byte *)(*(int *)(iVar5 + 0x28) + __n);
      iVar2 = EVP_MD_type(*(EVP_MD **)(iVar5 + 0x18));
      uVar3 = RSA_X931_hash_id(iVar2);
      if (bVar1 != uVar3) {
        ERR_put_error(4,0x8d,100,"crypto/rsa/rsa_pmeth.c",0xd2);
        return 0;
      }
      sVar4 = EVP_MD_size(*(EVP_MD **)(iVar5 + 0x18));
      if (__n != sVar4) {
        ERR_put_error(4,0x8d,0x8f,"crypto/rsa/rsa_pmeth.c",0xd7);
        return 0;
      }
      if (param_2 != (uchar *)0x0) {
        memcpy(param_2,*(void **)(iVar5 + 0x28),__n);
      }
      goto LAB_0014ebb8;
    }
    if (*(int *)(iVar5 + 0x14) != 1) {
      return 0xffffffff;
    }
    iVar5 = EVP_MD_type(*(EVP_MD **)(iVar5 + 0x18));
    iVar5 = int_rsa_verify(iVar5,0,0,param_2,local_24,param_4,param_5,
                           *(undefined4 *)(*(int *)(param_1 + 8) + 0x18));
    __n = local_24[0];
    if (iVar5 < 1) {
      return 0;
    }
  }
  if ((int)__n < 0) {
    return __n;
  }
LAB_0014ebb8:
  *param_3 = __n;
  return 1;
}

