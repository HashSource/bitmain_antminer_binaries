
undefined4 * X509_OBJECT_new(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(8,"crypto/x509/x509_lu.c",0x1a4);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0xb,0x96,0x41,"crypto/x509/x509_lu.c",0x1a7);
  }
  else {
    *puVar1 = 0;
  }
  return puVar1;
}

