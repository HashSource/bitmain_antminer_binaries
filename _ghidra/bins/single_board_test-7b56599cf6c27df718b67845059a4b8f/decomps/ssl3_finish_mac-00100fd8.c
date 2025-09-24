
undefined4 ssl3_finish_mac(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  undefined4 uVar2;
  EVP_MD_CTX *ctx;
  uint uVar3;
  
  ctx = *(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8);
  if (ctx == (EVP_MD_CTX *)0x0) {
    if ((int)param_3 < 0) {
      ossl_statem_fatal(param_1,0x50,0x24b,0xed,"ssl/s3_enc.c",0x164);
      return 0;
    }
    iVar1 = BIO_write(*(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4),param_2,param_3);
    uVar3 = param_3 - iVar1;
    if (uVar3 != 0) {
      uVar3 = 1;
    }
    if (iVar1 < 1) {
      uVar3 = uVar3 | 1;
    }
    if (uVar3 != 0) {
      uVar2 = 0x16a;
      goto LAB_00100ffe;
    }
  }
  else {
    iVar1 = EVP_DigestUpdate(ctx,param_2,param_3);
    if (iVar1 == 0) {
      uVar2 = 0x171;
LAB_00100ffe:
      ossl_statem_fatal(param_1,0x50,0x24b,0x44,"ssl/s3_enc.c",uVar2);
      return 0;
    }
  }
  return 1;
}

