
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CMAC_CTX * CMAC_CTX_new(void)

{
  CMAC_CTX *ptr;
  EVP_CIPHER_CTX *pEVar1;
  
  ptr = (CMAC_CTX *)CRYPTO_malloc(0x88,"crypto/cmac/cmac.c",0x32);
  if (ptr == (CMAC_CTX *)0x0) {
    ERR_put_error(0xf,0x78,0x41,"crypto/cmac/cmac.c",0x33);
  }
  else {
    pEVar1 = EVP_CIPHER_CTX_new();
    *(EVP_CIPHER_CTX **)ptr = pEVar1;
    if (pEVar1 == (EVP_CIPHER_CTX *)0x0) {
      CRYPTO_free(ptr);
      ptr = (CMAC_CTX *)0x0;
    }
    else {
      *(undefined4 *)(ptr + 0x84) = 0xffffffff;
    }
  }
  return ptr;
}

