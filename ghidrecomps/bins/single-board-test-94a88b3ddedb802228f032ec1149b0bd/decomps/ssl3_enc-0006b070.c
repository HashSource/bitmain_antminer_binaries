
undefined4 ssl3_enc(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  EVP_MD *pEVar4;
  int extraout_r1;
  int extraout_r1_00;
  int iVar5;
  EVP_CIPHER_CTX *pEVar6;
  EVP_CIPHER_CTX *ctx;
  uint uVar7;
  uint inl;
  size_t __n;
  
  if (param_2 == 0) {
    ctx = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
    iVar5 = *(int *)(param_1 + 0x58) + 0x10c;
    if (ctx == (EVP_CIPHER_CTX *)0x0) {
      pEVar6 = (EVP_CIPHER_CTX *)0x0;
      goto LAB_0006b08e;
    }
  }
  else {
    pEVar6 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    iVar5 = *(int *)(param_1 + 0x58) + 0x130;
    ctx = pEVar6;
    if (pEVar6 == (EVP_CIPHER_CTX *)0x0) goto LAB_0006b08e;
  }
  pEVar6 = (EVP_CIPHER_CTX *)EVP_CIPHER_CTX_cipher(ctx);
LAB_0006b08e:
  if ((*(int *)(param_1 + 0xc0) == 0) ||
     (ctx == (EVP_CIPHER_CTX *)0x0 || pEVar6 == (EVP_CIPHER_CTX *)0x0)) {
    memmove(*(void **)(iVar5 + 0xc),*(void **)(iVar5 + 0x10),*(size_t *)(iVar5 + 4));
    uVar1 = 1;
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar5 + 0xc);
  }
  else {
    inl = *(uint *)(iVar5 + 4);
    iVar2 = EVP_CIPHER_block_size(ctx->cipher);
    uVar7 = iVar2 - 1;
    if (uVar7 != 0) {
      uVar7 = 1;
    }
    if (param_2 == 0 || iVar2 == 1) {
      if ((param_2 == 0) && ((inl == 0 || (__aeabi_uidivmod(inl,iVar2), extraout_r1 != 0)))) {
        return 0;
      }
    }
    else {
      __aeabi_idivmod(inl,iVar2);
      __n = iVar2 - extraout_r1_00;
      inl = inl + __n;
      memset((void *)(*(int *)(iVar5 + 0x10) + *(int *)(iVar5 + 4)),0,__n);
      *(size_t *)(iVar5 + 4) = *(int *)(iVar5 + 4) + __n;
      *(char *)(*(int *)(iVar5 + 0x10) + inl + -1) = (char)__n + -1;
    }
    iVar3 = EVP_Cipher(ctx,*(uchar **)(iVar5 + 0xc),*(uchar **)(iVar5 + 0x10),inl);
    if (iVar3 < 1) {
      uVar1 = 0xffffffff;
    }
    else {
      pEVar4 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
      if (pEVar4 != (EVP_MD *)0x0) {
        pEVar4 = EVP_MD_CTX_md(*(EVP_MD_CTX **)(param_1 + 0x84));
        pEVar4 = (EVP_MD *)EVP_MD_size(pEVar4);
      }
      if (param_2 == 0) {
        uVar7 = uVar7 & 1;
      }
      else {
        uVar7 = 0;
      }
      uVar1 = 1;
      if (uVar7 != 0) {
        uVar1 = ssl3_cbc_remove_padding(param_1,iVar5,iVar2,pEVar4);
        return uVar1;
      }
    }
  }
  return uVar1;
}

