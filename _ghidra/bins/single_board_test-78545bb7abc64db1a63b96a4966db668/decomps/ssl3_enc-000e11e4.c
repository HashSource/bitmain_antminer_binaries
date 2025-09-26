
undefined4 ssl3_enc(int param_1,int param_2,int param_3,int param_4)

{
  EVP_CIPHER *pEVar1;
  int iVar2;
  int iVar3;
  EVP_MD *pEVar4;
  undefined4 uVar5;
  int extraout_r1;
  int extraout_r1_00;
  EVP_CIPHER_CTX *ctx;
  uint uVar6;
  uint inl;
  size_t __n;
  
  if (param_3 != 1) {
    return 0;
  }
  if (param_4 == 0) {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
  }
  else {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x3ec);
  }
  if (((ctx == (EVP_CIPHER_CTX *)0x0) ||
      (pEVar1 = EVP_CIPHER_CTX_cipher(ctx), *(int *)(param_1 + 0x474) == 0)) ||
     (pEVar1 == (EVP_CIPHER *)0x0)) {
    memmove(*(void **)(param_2 + 0x14),*(void **)(param_2 + 0x18),*(size_t *)(param_2 + 8));
    uVar5 = 1;
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_2 + 0x14);
  }
  else {
    inl = *(uint *)(param_2 + 8);
    iVar2 = EVP_CIPHER_CTX_block_size(ctx);
    uVar6 = iVar2 - 1;
    if (uVar6 != 0) {
      uVar6 = 1;
    }
    if (param_4 == 0 || iVar2 == 1) {
      if ((param_4 == 0) && ((inl == 0 || (__aeabi_uidivmod(inl,iVar2), extraout_r1 != 0)))) {
        return 0;
      }
    }
    else {
      __aeabi_uidivmod(inl,iVar2);
      __n = iVar2 - extraout_r1_00;
      inl = inl + __n;
      memset((void *)(*(int *)(param_2 + 8) + *(int *)(param_2 + 0x18)),0,__n);
      *(size_t *)(param_2 + 8) = *(int *)(param_2 + 8) + __n;
      *(char *)(*(int *)(param_2 + 0x18) + inl + -1) = (char)__n + -1;
    }
    iVar3 = EVP_Cipher(ctx,*(uchar **)(param_2 + 0x14),*(uchar **)(param_2 + 0x18),inl);
    if (iVar3 < 1) {
      uVar5 = 0xffffffff;
    }
    else {
      pEVar4 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x3e0));
      if (pEVar4 != (EVP_MD *)0x0) {
        pEVar4 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x3e0));
        pEVar4 = (EVP_MD *)EVP_MD_size(pEVar4);
        if ((int)pEVar4 < 0) {
          ossl_statem_fatal(param_1,0x50,0x260,0x44,"ssl/record/ssl3_record.c",0x392);
          return 0xffffffff;
        }
      }
      if (param_4 == 0) {
        uVar6 = uVar6 & 1;
      }
      else {
        uVar6 = 0;
      }
      uVar5 = 1;
      if (uVar6 != 0) {
        uVar5 = ssl3_cbc_remove_padding(param_2,iVar2,pEVar4);
        return uVar5;
      }
    }
  }
  return uVar5;
}

