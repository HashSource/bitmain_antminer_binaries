
int BUF_MEM_grow_clean(BUF_MEM *str,size_t len)

{
  char *__dest;
  int line;
  uint uVar1;
  size_t sVar2;
  
  uVar1 = str->length;
  if (len <= uVar1) {
    if (str->data != (char *)0x0) {
      memset(str->data + len,0,uVar1 - len);
    }
    str->length = len;
    return len;
  }
  if (len <= str->max) {
    memset(str->data + uVar1,0,len - uVar1);
    str->length = len;
    return len;
  }
  if (0x5ffffffc < len) {
    line = 0x80;
    goto LAB_00112e54;
  }
  sVar2 = (len + 3) / 3 << 2;
  if ((int)(str[1].length << 0x1f) < 0) {
    __dest = (char *)CRYPTO_secure_malloc(sVar2,"crypto/buffer/buffer.c",0x3e);
    if (str->data == (char *)0x0) goto LAB_00112e1c;
    if (__dest != (char *)0x0) {
      memcpy(__dest,str->data,str->length);
      CRYPTO_secure_clear_free(str->data,str->length,"crypto/buffer/buffer.c",0x42);
      goto LAB_00112e1e;
    }
  }
  else {
    __dest = (char *)CRYPTO_clear_realloc(str->data,str->max,sVar2,"crypto/buffer/buffer.c",0x87);
LAB_00112e1c:
    if (__dest != (char *)0x0) {
LAB_00112e1e:
      str->data = __dest;
      str->max = sVar2;
      memset(__dest + str->length,0,len - str->length);
      str->length = len;
      return len;
    }
  }
  line = 0x89;
LAB_00112e54:
  ERR_put_error(7,0x69,0x41,"crypto/buffer/buffer.c",line);
  return 0;
}

