
EVP_PKEY * EVP_PKEY_new_mac_key(int type,ENGINE *e,uchar *key,int keylen)

{
  int *ctx;
  EVP_PKEY *pkey;
  int iVar1;
  code *pcVar2;
  int iVar3;
  EVP_PKEY *pEVar4;
  
  iVar3 = keylen;
  ctx = (int *)EVP_PKEY_CTX_new_id(type,e);
  if (ctx == (int *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  iVar1 = *ctx;
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == 0)) {
    ERR_put_error(6,0x93,0x96,DAT_000b4808,0x76);
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x1c);
    ctx[4] = 4;
    if (pcVar2 != (code *)0x0) {
      iVar1 = (*pcVar2)();
      if (iVar1 < 1) {
        iVar3 = 0;
      }
      if (iVar1 < 1) {
        ctx[4] = iVar3;
        goto LAB_000b47cc;
      }
    }
    iVar3 = EVP_PKEY_CTX_ctrl((EVP_PKEY_CTX *)ctx,-1,4,6,keylen,key);
    if (0 < iVar3) {
      if ((*ctx == 0) || (*(int *)(*ctx + 0x20) == 0)) {
        ERR_put_error(6,0x92,0x96,DAT_000b4808,0x88);
        pEVar4 = (EVP_PKEY *)0x0;
      }
      else if (ctx[4] == 4) {
        pkey = EVP_PKEY_new();
        iVar3 = (**(code **)(*ctx + 0x20))(ctx,pkey);
        pEVar4 = pkey;
        if (iVar3 < 1) {
          pEVar4 = (EVP_PKEY *)0x0;
          EVP_PKEY_free(pkey);
        }
      }
      else {
        ERR_put_error(6,0x92,0x97,DAT_000b4808,0x8c);
        pEVar4 = (EVP_PKEY *)0x0;
      }
      goto LAB_000b47ce;
    }
  }
LAB_000b47cc:
  pEVar4 = (EVP_PKEY *)0x0;
LAB_000b47ce:
  EVP_PKEY_CTX_free((EVP_PKEY_CTX *)ctx);
  return pEVar4;
}

