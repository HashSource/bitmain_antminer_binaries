
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CMAC_CTX * CMAC_CTX_new(void)

{
  EVP_CIPHER_CTX *a;
  
  a = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x110,"cmac.c",0x62);
  if (a != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_init(a);
    a[1].final[0x14] = 0xff;
    a[1].final[0x15] = 0xff;
    a[1].final[0x16] = 0xff;
    a[1].final[0x17] = 0xff;
  }
  return (CMAC_CTX *)a;
}

