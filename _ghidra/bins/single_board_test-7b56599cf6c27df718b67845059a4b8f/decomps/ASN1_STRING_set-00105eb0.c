
int ASN1_STRING_set(ASN1_STRING *str,void *data,int len)

{
  uchar *__dest;
  uchar *addr;
  
  if (len < 0) {
    if (data == (void *)0x0) {
      return 0;
    }
    len = strlen((char *)data);
    if (0x7ffffffe < (uint)len) {
LAB_00105f2c:
      ERR_put_error(0xd,0,0xdf,"crypto/asn1/asn1_lib.c",0x122);
      return 0;
    }
  }
  else if (0x7ffffffe < (uint)len) goto LAB_00105f2c;
  addr = str->data;
  if (((uint)str->length <= (uint)len) || (__dest = addr, addr == (uchar *)0x0)) {
    __dest = (uchar *)CRYPTO_realloc(addr,len + 1,"crypto/asn1/asn1_lib.c",299);
    str->data = __dest;
    if (__dest == (uchar *)0x0) {
      ERR_put_error(0xd,0xba,0x41,"crypto/asn1/asn1_lib.c",0x12e);
      str->data = addr;
      return 0;
    }
  }
  str->length = len;
  if (data != (void *)0x0) {
    memcpy(__dest,data,len);
    str->data[len] = '\0';
  }
  return 1;
}

