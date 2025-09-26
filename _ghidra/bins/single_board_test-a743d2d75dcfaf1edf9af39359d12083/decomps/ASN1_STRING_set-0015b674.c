
int ASN1_STRING_set(ASN1_STRING *str,void *data,int len)

{
  uchar *puVar1;
  uchar *addr;
  
  if (len < 0) {
    if (data == (void *)0x0) {
      return 0;
    }
    len = strlen((char *)data);
  }
  if (str->length < len) {
    addr = str->data;
    if (addr == (uchar *)0x0) goto LAB_0015b6f4;
    puVar1 = (uchar *)CRYPTO_realloc(addr,len + 1,"asn1_lib.c",0x17a);
    str->data = puVar1;
    if (puVar1 != (uchar *)0x0) goto LAB_0015b68e;
LAB_0015b6cc:
    ERR_put_error(0xd,0xba,0x41,"asn1_lib.c",0x17d);
    str->data = addr;
  }
  else {
    if (str->data == (uchar *)0x0) {
LAB_0015b6f4:
      addr = (uchar *)0x0;
      puVar1 = (uchar *)CRYPTO_malloc(len + 1,"asn1_lib.c",0x178);
      str->data = puVar1;
      if (puVar1 == (uchar *)0x0) {
        puVar1 = (uchar *)0x0;
        goto LAB_0015b6cc;
      }
    }
LAB_0015b68e:
    str->length = len;
    puVar1 = (uchar *)0x1;
    if (data != (void *)0x0) {
      memcpy(str->data,data,len);
      puVar1 = (uchar *)0x1;
      str->data[len] = '\0';
    }
  }
  return (int)puVar1;
}

