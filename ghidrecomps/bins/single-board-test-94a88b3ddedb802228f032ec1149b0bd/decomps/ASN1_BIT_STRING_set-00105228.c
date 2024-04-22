
int ASN1_BIT_STRING_set(ASN1_STRING *str,void *data,int len)

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
    if (addr == (uchar *)0x0) goto LAB_000bceb4;
    puVar1 = (uchar *)CRYPTO_realloc(addr,len + 1,DAT_000bced0,0x17a);
    str->data = puVar1;
    if (puVar1 != (uchar *)0x0) goto LAB_000bce4e;
LAB_000bce8c:
    ERR_put_error(0xd,0xba,0x41,DAT_000bced0,0x17d);
    str->data = addr;
  }
  else {
    if (str->data == (uchar *)0x0) {
LAB_000bceb4:
      addr = (uchar *)0x0;
      puVar1 = (uchar *)CRYPTO_malloc(len + 1,DAT_000bced0,0x178);
      str->data = puVar1;
      if (puVar1 == (uchar *)0x0) {
        puVar1 = (uchar *)0x0;
        goto LAB_000bce8c;
      }
    }
LAB_000bce4e:
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

