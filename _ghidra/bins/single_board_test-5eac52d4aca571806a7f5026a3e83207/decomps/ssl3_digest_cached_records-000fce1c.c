
undefined4 ssl3_digest_cached_records(int param_1,int param_2)

{
  undefined4 uVar1;
  size_t cnt;
  EVP_MD *type;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *local_1c;
  
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0xd8) == 0) {
    cnt = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4),3,0,&local_1c);
    if ((int)cnt < 1) {
      uVar4 = 0x182;
      uVar1 = 0x14c;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x7c);
      uVar1 = EVP_MD_CTX_new();
      iVar2 = *(int *)(param_1 + 0x7c);
      *(undefined4 *)(iVar3 + 0xd8) = uVar1;
      if (*(int *)(iVar2 + 0xd8) == 0) {
        uVar4 = 0x189;
        uVar1 = 0x41;
      }
      else {
        type = (EVP_MD *)ssl_handshake_md(param_1);
        if (((type != (EVP_MD *)0x0) &&
            (iVar2 = EVP_DigestInit_ex(*(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8),type,
                                       (ENGINE *)0x0), iVar2 != 0)) &&
           (iVar2 = EVP_DigestUpdate(*(EVP_MD_CTX **)(*(int *)(param_1 + 0x7c) + 0xd8),local_1c,cnt)
           , iVar2 != 0)) goto LAB_000fce2e;
        uVar4 = 0x191;
        uVar1 = 0x44;
      }
    }
    ossl_statem_fatal(param_1,0x50,0x125,uVar1,"ssl/s3_enc.c",uVar4);
    uVar1 = 0;
  }
  else {
LAB_000fce2e:
    uVar1 = 1;
    if (param_2 == 0) {
      BIO_free(*(BIO **)(*(int *)(param_1 + 0x7c) + 0xd4));
      uVar1 = 1;
      *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xd4) = 0;
    }
  }
  return uVar1;
}

