
undefined4 * CTLOG_new(EVP_PKEY *param_1,char *param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  size_t n;
  uchar *local_1c [2];
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x28,"crypto/ct/ct_log.c",0xef);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x32,0x75,0x41,"crypto/ct/ct_log.c",0xf2);
    return (undefined4 *)0x0;
  }
  pcVar2 = CRYPTO_strdup(param_2,"crypto/ct/ct_log.c",0xf6);
  *puVar1 = pcVar2;
  if (pcVar2 == (char *)0x0) {
    ERR_put_error(0x32,0x75,0x41,"crypto/ct/ct_log.c",0xf8);
  }
  else {
    local_1c[0] = (uchar *)0x0;
    n = i2d_PUBKEY(param_1,local_1c);
    if (0 < (int)n) {
      SHA256(local_1c[0],n,(uchar *)(puVar1 + 1));
      CRYPTO_free(local_1c[0]);
      puVar1[9] = param_1;
      return puVar1;
    }
    ERR_put_error(0x32,0x7d,0x71,"crypto/ct/ct_log.c",0x51);
    CRYPTO_free(local_1c[0]);
  }
  CTLOG_free(puVar1);
  return (undefined4 *)0x0;
}

