
int ASN1_digest(undefined1 *i2d,EVP_MD *type,char *data,uchar *md,uint *len)

{
  size_t count;
  void *data_00;
  int iVar1;
  void *local_24 [2];
  
  count = (*(code *)i2d)(data,0);
  data_00 = CRYPTO_malloc(count,DAT_00106ef4,0x52);
  if (data_00 == (void *)0x0) {
    ERR_put_error(0xd,0xb8,0x41,DAT_00106ef4,0x53);
    iVar1 = 0;
  }
  else {
    local_24[0] = data_00;
    (*(code *)i2d)(data,local_24);
    iVar1 = EVP_Digest(data_00,count,md,len,type,(ENGINE *)0x0);
    if (iVar1 != 0) {
      CRYPTO_free(data_00);
      iVar1 = 1;
    }
  }
  return iVar1;
}

