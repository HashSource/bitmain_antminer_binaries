
undefined4 * BIO_meth_new(undefined4 param_1,char *param_2)

{
  undefined4 *ptr;
  char *pcVar1;
  
  ptr = (undefined4 *)CRYPTO_zalloc(0x30,"crypto/bio/bio_meth.c",0x26);
  if (ptr != (undefined4 *)0x0) {
    pcVar1 = CRYPTO_strdup(param_2,"crypto/bio/bio_meth.c",0x29);
    ptr[1] = pcVar1;
    if (pcVar1 != (char *)0x0) {
      *ptr = param_1;
      return ptr;
    }
  }
  CRYPTO_free(ptr);
  ERR_put_error(0x20,0x92,0x41,"crypto/bio/bio_meth.c",0x2b);
  return (undefined4 *)0x0;
}

