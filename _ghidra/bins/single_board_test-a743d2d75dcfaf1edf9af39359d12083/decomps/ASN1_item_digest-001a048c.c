
int ASN1_item_digest(ASN1_ITEM *it,EVP_MD *type,void *data,uchar *md,uint *len)

{
  size_t count;
  int iVar1;
  uchar *local_1c [2];
  
  local_1c[0] = (uchar *)0x0;
  count = ASN1_item_i2d((ASN1_VALUE *)data,local_1c,it);
  if ((local_1c[0] != (uchar *)0x0) &&
     (iVar1 = EVP_Digest(local_1c[0],count,md,len,type,(ENGINE *)0x0), iVar1 != 0)) {
    CRYPTO_free(local_1c[0]);
    return 1;
  }
  return 0;
}

