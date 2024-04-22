
int BUF_MEM_grow(BUF_MEM *str,size_t len)

{
  char *pcVar1;
  uint uVar2;
  size_t num;
  
  uVar2 = str->length;
  if (uVar2 < len) {
    if (str->max < len) {
      if (0x5ffffffc < len) {
        ERR_put_error(7,100,0x41,DAT_000a8898,0x71);
        return 0;
      }
      num = (len + 3) / 3 << 2;
      if (str->data == (char *)0x0) {
        pcVar1 = (char *)CRYPTO_malloc(num,DAT_000a8898,0x76);
      }
      else {
        pcVar1 = (char *)CRYPTO_realloc(str->data,num,DAT_000a8898,0x78);
      }
      if (pcVar1 != (char *)0x0) {
        str->data = pcVar1;
        str->max = num;
        memset(pcVar1 + str->length,0,len - str->length);
        str->length = len;
        return len;
      }
      ERR_put_error(7,100,0x41,DAT_000a8898,0x7a);
      return 0;
    }
    memset(str->data + uVar2,0,len - uVar2);
  }
  str->length = len;
  return len;
}

