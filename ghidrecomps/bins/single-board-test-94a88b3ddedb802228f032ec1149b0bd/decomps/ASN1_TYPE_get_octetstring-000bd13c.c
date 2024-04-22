
int ASN1_TYPE_get_octetstring(ASN1_TYPE *a,uchar *data,int max_len)

{
  ASN1_STRING *pAVar1;
  size_t sVar2;
  
  if ((a->type == 4) && (pAVar1 = (a->value).asn1_string, pAVar1 != (ASN1_STRING *)0x0)) {
    sVar2 = pAVar1->length;
    if ((int)sVar2 <= max_len) {
      max_len = sVar2;
    }
    memcpy(data,pAVar1->data,max_len);
  }
  else {
    ERR_put_error(0xd,0x87,0x6d,DAT_000bd178,0x55);
    sVar2 = 0xffffffff;
  }
  return sVar2;
}

