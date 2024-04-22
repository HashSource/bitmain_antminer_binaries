
int BUF_MEM_grow_clean(BUF_MEM *str,size_t len)

{
  char *pcVar1;
  uint uVar2;
  size_t num;
  
  uVar2 = str->length;
  if (uVar2 < len) {
    if (str->max < len) {
      if (len < 0x5ffffffd) {
        num = (len + 3) / 3 << 2;
        if (str->data == (char *)0x0) {
          pcVar1 = (char *)CRYPTO_malloc(num,DAT_000a8958,0x9b);
        }
        else {
          pcVar1 = (char *)CRYPTO_realloc_clean(str->data,str->max,num,DAT_000a8958,0x9d);
        }
        if (pcVar1 == (char *)0x0) {
          ERR_put_error(7,0x69,0x41,DAT_000a8958,0x9f);
          len = 0;
        }
        else {
          str->data = pcVar1;
          str->max = num;
          memset(pcVar1 + str->length,0,len - str->length);
          str->length = len;
        }
      }
      else {
        ERR_put_error(7,0x69,0x41,DAT_000a8958,0x96);
        len = 0;
      }
    }
    else {
      memset(str->data + uVar2,0,len - uVar2);
      str->length = len;
    }
  }
  else {
    memset(str->data + len,0,uVar2 - len);
    str->length = len;
  }
  return len;
}

