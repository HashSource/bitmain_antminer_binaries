
int EVP_PKEY_verify_recover(EVP_PKEY_CTX *ctx,uchar *rout,size_t *routlen,uchar *sig,size_t siglen)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (pcVar3 = *(code **)(iVar1 + 0x38), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x90,0x96,DAT_000b4188,0xad);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x20) {
    if (*(int *)(iVar1 + 4) << 0x1e < 0) {
      uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
      if (rout == (uchar *)0x0) {
        *routlen = uVar2;
        return 1;
      }
      if (*routlen < uVar2) {
        ERR_put_error(6,0x90,0x9b,DAT_000b4188,0xb4);
        return 0;
      }
      pcVar3 = *(code **)(*(int *)ctx + 0x38);
    }
    iVar1 = (*pcVar3)(ctx,rout,routlen,sig,siglen);
  }
  else {
    ERR_put_error(6,0x90,0x97,DAT_000b4188,0xb1);
    iVar1 = -1;
  }
  return iVar1;
}

