
undefined4 * ossl_store_file_attach_pem_bio_int(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x30,"crypto/store/loader_file.c",0x3eb);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2c,0x80,0x41,"crypto/store/loader_file.c",0x3ef);
  }
  else {
    puVar1[3] = param_1;
    *puVar1 = 1;
  }
  return puVar1;
}

