
undefined4 ossl_store_detach_pem_bio(void *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ossl_store_file_detach_pem_bio_int(*(undefined4 *)((int)param_1 + 4));
  CRYPTO_free(param_1);
  return uVar1;
}

