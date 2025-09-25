
int HMAC_CTX_new(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  
  iVar1 = CRYPTO_zalloc(0x10,"crypto/hmac/hmac.c",0x89,in_r3,in_r3);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = HMAC_CTX_reset();
  if (iVar2 != 0) {
    return iVar1;
  }
  HMAC_CTX_free(iVar1);
  return 0;
}

