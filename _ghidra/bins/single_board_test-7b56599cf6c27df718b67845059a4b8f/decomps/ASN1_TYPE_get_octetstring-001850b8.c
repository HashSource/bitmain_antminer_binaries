
int ASN1_TYPE_get_octetstring(ASN1_TYPE *a,uchar *data,int max_len)

{
  void *__src;
  size_t sVar1;
  
  if ((a->type == 4) && ((a->value).ptr != (char *)0x0)) {
    __src = (void *)ASN1_STRING_get0_data();
    sVar1 = ASN1_STRING_length((a->value).asn1_string);
    if ((int)sVar1 <= max_len) {
      max_len = sVar1;
    }
    memcpy(data,__src,max_len);
  }
  else {
    ERR_put_error(0xd,0x87,0x6d,"crypto/asn1/evp_asn1.c",0x24);
    sVar1 = 0xffffffff;
  }
  return sVar1;
}

