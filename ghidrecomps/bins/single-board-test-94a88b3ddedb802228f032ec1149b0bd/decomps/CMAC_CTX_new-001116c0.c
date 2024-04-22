
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CMAC_CTX * CMAC_CTX_new(void)

{
  EVP_CIPHER_CTX *a;
  
  a = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x110,DAT_001116e4,0x62);
  if (a != (EVP_CIPHER_CTX *)0x0) {
    EVP_CIPHER_CTX_init(a);
    *(undefined4 *)(a[1].final + 0x14) = 0xffffffff;
  }
  return (CMAC_CTX *)a;
}

