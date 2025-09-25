
undefined4 asn1_bio_new(undefined4 param_1)

{
  undefined4 *ptr;
  void *pvVar1;
  
  ptr = (undefined4 *)CRYPTO_zalloc(0x40,"crypto/asn1/bio_asn1.c",0x67);
  if (ptr == (undefined4 *)0x0) {
    return 0;
  }
  pvVar1 = CRYPTO_malloc(0x14,"crypto/asn1/bio_asn1.c",0x77);
  ptr[1] = pvVar1;
  if (pvVar1 != (void *)0x0) {
    ptr[6] = 0;
    ptr[2] = 0x14;
    *ptr = 0;
    ptr[7] = 4;
    BIO_set_data(param_1,ptr);
    BIO_set_init(param_1,1);
    return 1;
  }
  ERR_put_error(0xd,0x71,0x41,"crypto/asn1/bio_asn1.c",0x78);
  CRYPTO_free(ptr);
  return 0;
}

