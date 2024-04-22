
int pkey_rsa_encrypt(int param_1,uchar *param_2,int *param_3,uchar *param_4,int param_5)

{
  int flen;
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar3 + 0x10) == 4) {
    flen = RSA_size(*(RSA **)(*(int *)(param_1 + 8) + 0x14));
    pvVar1 = *(void **)(iVar3 + 0x20);
    if (pvVar1 == (void *)0x0) {
      iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
      pvVar1 = CRYPTO_malloc(iVar2,DAT_000fdd78,0x9c);
      *(void **)(iVar3 + 0x20) = pvVar1;
      if (pvVar1 != (void *)0x0) goto LAB_000fdd2c;
    }
    else {
LAB_000fdd2c:
      iVar2 = RSA_padding_add_PKCS1_OAEP_mgf1
                        (pvVar1,flen,param_4,param_5,*(undefined4 *)(iVar3 + 0x24),
                         *(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x14),
                         *(undefined4 *)(iVar3 + 0x18));
      if (iVar2 != 0) {
        iVar3 = RSA_public_encrypt(flen,*(uchar **)(iVar3 + 0x20),param_2,
                                   *(RSA **)(*(int *)(param_1 + 8) + 0x14),3);
        goto LAB_000fdd12;
      }
    }
    iVar3 = -1;
  }
  else {
    iVar3 = RSA_public_encrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x14),
                               *(int *)(iVar3 + 0x10));
LAB_000fdd12:
    if (-1 < iVar3) {
      *param_3 = iVar3;
      iVar3 = 1;
    }
  }
  return iVar3;
}

