
undefined2 * BIO_ADDR_new(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)CRYPTO_zalloc(0x70,"crypto/bio/b_addr.c",0x2c);
  if (puVar1 == (undefined2 *)0x0) {
    ERR_put_error(0x20,0x90,0x41,"crypto/bio/b_addr.c",0x2f);
  }
  else {
    *puVar1 = 0;
  }
  return puVar1;
}

