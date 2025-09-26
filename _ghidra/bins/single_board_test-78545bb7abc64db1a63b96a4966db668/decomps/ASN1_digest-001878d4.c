
int ASN1_digest(undefined1 *i2d,EVP_MD *type,char *data,uchar *md,uint *len)

{
  size_t count;
  void *data_00;
  int iVar1;
  void *local_24;
  
  count = (*(code *)i2d)(data,0);
  if ((int)count < 1) {
    ERR_put_error(0xd,0xb8,0x44,"crypto/asn1/a_digest.c",0x1f);
    return 0;
  }
  data_00 = CRYPTO_malloc(count,"crypto/asn1/a_digest.c",0x22);
  if (data_00 == (void *)0x0) {
    ERR_put_error(0xd,0xb8,0x41,"crypto/asn1/a_digest.c",0x23);
    iVar1 = 0;
  }
  else {
    local_24 = data_00;
    (*(code *)i2d)(data,&local_24);
    iVar1 = EVP_Digest(data_00,count,md,len,type,(ENGINE *)0x0);
    if (iVar1 == 0) {
      CRYPTO_free(data_00);
      return 0;
    }
    iVar1 = 1;
    CRYPTO_free(data_00);
  }
  return iVar1;
}

