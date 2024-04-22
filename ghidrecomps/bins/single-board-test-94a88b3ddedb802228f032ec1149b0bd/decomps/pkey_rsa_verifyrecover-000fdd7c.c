
size_t pkey_rsa_verifyrecover(int param_1,uchar *param_2,size_t *param_3,uchar *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  int nid;
  uint uVar3;
  uchar *to;
  size_t sVar4;
  int iVar5;
  size_t asStack_24 [2];
  
  iVar5 = *(int *)(param_1 + 0x14);
  if (*(EVP_MD **)(iVar5 + 0x14) == (EVP_MD *)0x0) {
    sVar4 = RSA_public_decrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x14),
                               *(int *)(iVar5 + 0x10));
LAB_000fddc2:
    if ((int)sVar4 < 0) {
      return sVar4;
    }
LAB_000fddc6:
    *param_3 = sVar4;
    sVar4 = 1;
  }
  else {
    if (*(int *)(iVar5 + 0x10) == 5) {
      to = *(uchar **)(iVar5 + 0x20);
      if (to == (uchar *)0x0) {
        iVar2 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
        to = (uchar *)CRYPTO_malloc(iVar2,DAT_000fde80,0x9c);
        *(uchar **)(iVar5 + 0x20) = to;
        if (to == (uchar *)0x0) {
          return 0xffffffff;
        }
      }
      iVar2 = RSA_public_decrypt(param_5,param_4,to,*(RSA **)(*(int *)(param_1 + 8) + 0x14),5);
      if (0 < iVar2) {
        bVar1 = *(byte *)(*(int *)(iVar5 + 0x20) + (iVar2 - 1U));
        nid = EVP_MD_type(*(EVP_MD **)(iVar5 + 0x14));
        uVar3 = RSA_X931_hash_id(nid);
        if (bVar1 != uVar3) {
          ERR_put_error(4,0x8d,100,DAT_000fde80,0x13c);
          return 0;
        }
        sVar4 = EVP_MD_size(*(EVP_MD **)(iVar5 + 0x14));
        if (sVar4 != iVar2 - 1U) {
          ERR_put_error(4,0x8d,0x8f,DAT_000fde80,0x141);
          return 0;
        }
        if (param_2 != (uchar *)0x0) {
          memcpy(param_2,*(void **)(iVar5 + 0x20),sVar4);
        }
        goto LAB_000fddc6;
      }
    }
    else {
      if (*(int *)(iVar5 + 0x10) != 1) {
        return 0xffffffff;
      }
      iVar5 = EVP_MD_type(*(EVP_MD **)(iVar5 + 0x14));
      iVar5 = int_rsa_verify(iVar5,0,0,param_2,asStack_24,param_4,param_5,
                             *(undefined4 *)(*(int *)(param_1 + 8) + 0x14));
      sVar4 = asStack_24[0];
      if (0 < iVar5) goto LAB_000fddc2;
    }
    sVar4 = 0;
  }
  return sVar4;
}

