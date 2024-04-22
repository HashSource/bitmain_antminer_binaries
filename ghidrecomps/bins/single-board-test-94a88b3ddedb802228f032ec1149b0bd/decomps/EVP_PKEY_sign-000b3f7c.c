
int EVP_PKEY_sign(EVP_PKEY_CTX *ctx,uchar *sig,size_t *siglen,uchar *tbs,size_t tbslen)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (pcVar3 = *(code **)(iVar1 + 0x28), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x8c,0x96,DAT_000b4014,0x6a);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 8) {
    if (*(int *)(iVar1 + 4) << 0x1e < 0) {
      uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
      if (sig == (uchar *)0x0) {
        *siglen = uVar2;
        return 1;
      }
      if (*siglen < uVar2) {
        ERR_put_error(6,0x8c,0x9b,DAT_000b4014,0x71);
        return 0;
      }
      pcVar3 = *(code **)(*(int *)ctx + 0x28);
    }
    iVar1 = (*pcVar3)(ctx,sig,siglen,tbs,tbslen);
  }
  else {
    ERR_put_error(6,0x8c,0x97,DAT_000b4014,0x6e);
    iVar1 = -1;
  }
  return iVar1;
}

