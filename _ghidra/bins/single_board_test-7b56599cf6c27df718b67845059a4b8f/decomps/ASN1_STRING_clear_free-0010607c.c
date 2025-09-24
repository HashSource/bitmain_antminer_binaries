
void ASN1_STRING_clear_free(ASN1_STRING *param_1)

{
  if (param_1 == (ASN1_STRING *)0x0) {
    return;
  }
  if ((param_1->data != (uchar *)0x0) && (-1 < param_1->flags << 0x1b)) {
    OPENSSL_cleanse(param_1->data,param_1->length);
    ASN1_STRING_free(param_1);
    return;
  }
  ASN1_STRING_free(param_1);
  return;
}

