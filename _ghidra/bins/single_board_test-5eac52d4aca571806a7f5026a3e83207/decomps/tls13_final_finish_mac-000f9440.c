
EVP_PKEY * tls13_final_finish_mac(int param_1,int param_2,undefined4 param_3,uchar *param_4)

{
  EVP_MD *type;
  EVP_MD_CTX *ctx;
  EVP_PKEY *pkey;
  int iVar1;
  undefined4 uVar2;
  EVP_PKEY *pEVar3;
  EVP_PKEY *local_ac;
  undefined1 auStack_a8 [64];
  undefined1 auStack_68 [68];
  
  type = (EVP_MD *)ssl_handshake_md();
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  pkey = (EVP_PKEY *)ssl_handshake_hash(param_1,auStack_a8,0x40,&local_ac);
  pEVar3 = pkey;
  if (pkey != (EVP_PKEY *)0x0) {
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x20) == param_2) {
      pkey = (EVP_PKEY *)EVP_PKEY_new_raw_private_key(0x357,0,param_1 + 0x20c,local_ac);
    }
    else if ((*(int *)(*(int *)(param_1 + 0x7c) + 0x180) == 0) ||
            (*(int *)(*(int *)(param_1 + 0x7c) + 0x204) == 0)) {
      pkey = (EVP_PKEY *)EVP_PKEY_new_raw_private_key(0x357,0,param_1 + 0x1cc,local_ac);
    }
    else {
      uVar2 = ssl_handshake_md(param_1);
      pkey = (EVP_PKEY *)tls13_derive_finishedkey(param_1,uVar2,param_1 + 0x2cc,auStack_68,local_ac)
      ;
      pEVar3 = pkey;
      if (pkey == (EVP_PKEY *)0x0) goto LAB_000f94f4;
      pkey = (EVP_PKEY *)EVP_PKEY_new_raw_private_key(0x357,0,auStack_68,local_ac);
      OPENSSL_cleanse(auStack_68,0x40);
    }
    if ((((ctx == (EVP_MD_CTX *)0x0 || pkey == (EVP_PKEY *)0x0) ||
         (iVar1 = EVP_DigestSignInit(ctx,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,pkey), iVar1 < 1))
        || (iVar1 = EVP_DigestUpdate(ctx,auStack_a8,(size_t)local_ac), iVar1 < 1)) ||
       (iVar1 = EVP_DigestSignFinal(ctx,param_4,(size_t *)&local_ac), pEVar3 = local_ac, iVar1 < 1))
    {
      ossl_statem_fatal(param_1,0x50,0x25d,0x44,"ssl/tls13_enc.c",0x148);
      pEVar3 = (EVP_PKEY *)0x0;
    }
  }
LAB_000f94f4:
  EVP_PKEY_free(pkey);
  EVP_MD_CTX_free(ctx);
  return pEVar3;
}

