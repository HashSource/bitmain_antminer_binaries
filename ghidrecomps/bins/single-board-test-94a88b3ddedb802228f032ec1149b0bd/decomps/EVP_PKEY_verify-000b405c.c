
int EVP_PKEY_verify(EVP_PKEY_CTX *ctx,uchar *sig,size_t siglen,uchar *tbs,size_t tbslen)

{
  int iVar1;
  code *pcVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (pcVar2 = *(code **)(*(int *)ctx + 0x30), pcVar2 == (code *)0x0)) {
    ERR_put_error(6,0x8e,0x96,DAT_000b40a8,0x8c);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x10) {
    iVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(6,0x8e,0x97,DAT_000b40a8,0x90);
    iVar1 = -1;
  }
  return iVar1;
}

