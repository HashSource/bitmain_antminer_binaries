
ASN1_STRING * ASN1_pack_string(void *obj,undefined1 *i2d,ASN1_OCTET_STRING **oct)

{
  int num;
  ASN1_STRING *a;
  uchar *local_1c [2];
  
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    a = ASN1_STRING_new();
    if (a == (ASN1_STRING *)0x0) {
LAB_0010a740:
      ERR_put_error(0xd,0x7c,0x41,DAT_0010a754,0x86);
      return (ASN1_STRING *)0x0;
    }
  }
  else {
    a = *oct;
    if (a == (ASN1_OCTET_STRING *)0x0) {
      a = ASN1_STRING_new();
      if (a == (ASN1_STRING *)0x0) goto LAB_0010a740;
      *oct = a;
    }
  }
  num = (*(code *)i2d)(obj,0);
  a->length = num;
  if (num == 0) {
    ERR_put_error(0xd,0x7c,0x70,DAT_0010a754,0x8f);
  }
  else {
    local_1c[0] = (uchar *)CRYPTO_malloc(num,DAT_0010a754,0x92);
    if (local_1c[0] != (uchar *)0x0) {
      a->data = local_1c[0];
      (*(code *)i2d)(obj,local_1c);
      return a;
    }
    ERR_put_error(0xd,0x7c,0x41,DAT_0010a754,0x93);
  }
  if (oct == (ASN1_OCTET_STRING **)0x0) {
    ASN1_STRING_free(a);
  }
  else if (*oct == (ASN1_OCTET_STRING *)0x0) {
    ASN1_STRING_free(a);
    *oct = (ASN1_OCTET_STRING *)0x0;
  }
  return (ASN1_STRING *)0x0;
}

