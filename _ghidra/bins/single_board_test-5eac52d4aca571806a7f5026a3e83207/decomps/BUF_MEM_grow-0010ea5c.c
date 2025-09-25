
int BUF_MEM_grow(BUF_MEM *str,size_t len)

{
  char *__dest;
  uint uVar1;
  int line;
  size_t num;
  
  uVar1 = str->length;
  if (len <= uVar1) {
LAB_0010ea80:
    str->length = len;
    return len;
  }
  if (len <= str->max) {
    if (str->data != (char *)0x0) {
      memset(str->data + uVar1,0,len - uVar1);
    }
    goto LAB_0010ea80;
  }
  if (0x5ffffffc < len) {
    line = 0x5a;
    goto LAB_0010eb0e;
  }
  num = (len + 3) / 3 << 2;
  if ((int)(str[1].length << 0x1f) < 0) {
    __dest = (char *)CRYPTO_secure_malloc(num,"crypto/buffer/buffer.c",0x3e);
    if (str->data == (char *)0x0) goto LAB_0010eaec;
    if (__dest != (char *)0x0) {
      memcpy(__dest,str->data,str->length);
      CRYPTO_secure_clear_free(str->data,str->length,"crypto/buffer/buffer.c",0x42);
      goto LAB_0010eaee;
    }
  }
  else {
    __dest = (char *)CRYPTO_realloc(str->data,num,"crypto/buffer/buffer.c",0x61);
LAB_0010eaec:
    if (__dest != (char *)0x0) {
LAB_0010eaee:
      str->data = __dest;
      str->max = num;
      memset(__dest + str->length,0,len - str->length);
      str->length = len;
      return len;
    }
  }
  line = 99;
LAB_0010eb0e:
  ERR_put_error(7,100,0x41,"crypto/buffer/buffer.c",line);
  return 0;
}

