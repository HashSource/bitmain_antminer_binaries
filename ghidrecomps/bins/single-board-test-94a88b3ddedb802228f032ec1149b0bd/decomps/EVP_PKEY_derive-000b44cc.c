
int EVP_PKEY_derive(EVP_PKEY_CTX *ctx,uchar *key,size_t *keylen)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (pcVar3 = *(code **)(iVar2 + 0x60), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x99,0x96,DAT_000b4560,0x151);
    iVar2 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x400) {
    if (*(int *)(iVar2 + 4) << 0x1e < 0) {
      uVar1 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
      if (key == (uchar *)0x0) {
        *keylen = uVar1;
        return 1;
      }
      if (*keylen < uVar1) {
        ERR_put_error(6,0x99,0x9b,DAT_000b4560,0x158);
        return 0;
      }
      pcVar3 = *(code **)(*(int *)ctx + 0x60);
    }
    iVar2 = (*pcVar3)(ctx,key,keylen);
  }
  else {
    ERR_put_error(6,0x99,0x97,DAT_000b4560,0x155);
    iVar2 = -1;
  }
  return iVar2;
}

