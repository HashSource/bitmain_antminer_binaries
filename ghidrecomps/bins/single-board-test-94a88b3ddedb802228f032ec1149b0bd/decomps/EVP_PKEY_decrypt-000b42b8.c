
int EVP_PKEY_decrypt(EVP_PKEY_CTX *ctx,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (pcVar3 = *(code **)(iVar1 + 0x58), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x68,0x96,DAT_000b4350,0xf1);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x200) {
    if (*(int *)(iVar1 + 4) << 0x1e < 0) {
      uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
      if (out == (uchar *)0x0) {
        *outlen = uVar2;
        return 1;
      }
      if (*outlen < uVar2) {
        ERR_put_error(6,0x68,0x9b,DAT_000b4350,0xf8);
        return 0;
      }
      pcVar3 = *(code **)(*(int *)ctx + 0x58);
    }
    iVar1 = (*pcVar3)(ctx,out,outlen,in,inlen);
  }
  else {
    ERR_put_error(6,0x68,0x97,DAT_000b4350,0xf5);
    iVar1 = -1;
  }
  return iVar1;
}

