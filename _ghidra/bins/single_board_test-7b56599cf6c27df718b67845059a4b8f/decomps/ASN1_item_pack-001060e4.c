
ASN1_STRING * ASN1_item_pack(void *obj,ASN1_ITEM *it,ASN1_OCTET_STRING **oct)

{
  int iVar1;
  ASN1_STRING *a;
  
  if (((oct == (ASN1_OCTET_STRING **)0x0) || (a = *oct, a == (ASN1_OCTET_STRING *)0x0)) &&
     (a = ASN1_STRING_new(), a == (ASN1_STRING *)0x0)) {
    ERR_put_error(0xd,0xc6,0x41,"crypto/asn1/asn_pack.c",0x16);
  }
  else {
    CRYPTO_free(a->data);
    a->data = (uchar *)0x0;
    iVar1 = ASN1_item_i2d((ASN1_VALUE *)obj,&a->data,it);
    a->length = iVar1;
    if (iVar1 == 0) {
      ERR_put_error(0xd,0xc6,0x70,"crypto/asn1/asn_pack.c",0x21);
    }
    else {
      if (a->data != (uchar *)0x0) {
        if (oct == (ASN1_OCTET_STRING **)0x0) {
          return a;
        }
        if (*oct != (ASN1_OCTET_STRING *)0x0) {
          return a;
        }
        *oct = a;
        return a;
      }
      ERR_put_error(0xd,0xc6,0x41,"crypto/asn1/asn_pack.c",0x25);
    }
    if ((oct == (ASN1_OCTET_STRING **)0x0) || (*oct == (ASN1_OCTET_STRING *)0x0)) {
      ASN1_STRING_free(a);
    }
  }
  return (ASN1_STRING *)0x0;
}

