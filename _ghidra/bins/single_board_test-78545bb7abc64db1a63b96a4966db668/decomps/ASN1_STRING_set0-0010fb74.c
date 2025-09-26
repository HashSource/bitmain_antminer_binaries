
void ASN1_STRING_set0(ASN1_STRING *str,void *data,int len)

{
  CRYPTO_free(str->data);
  str->data = (uchar *)data;
  str->length = len;
  return;
}

