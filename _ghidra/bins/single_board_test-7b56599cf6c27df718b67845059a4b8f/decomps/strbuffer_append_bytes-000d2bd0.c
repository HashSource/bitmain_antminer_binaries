
/* WARNING: Unknown calling convention */

int strbuffer_append_bytes(strbuffer_t *strbuff,char *data,size_t size)

{
  size_t sVar1;
  size_t sVar2;
  char *__dest;
  uint size_00;
  
  sVar2 = strbuff->length;
  sVar1 = strbuff->size;
  if (size < sVar1 - sVar2) {
    __dest = strbuff->value;
LAB_000d2c2c:
    memcpy(__dest + sVar2,data,size);
    sVar1 = size + strbuff->length;
    strbuff->length = sVar1;
    strbuff->value[sVar1] = '\0';
    return 0;
  }
  if (((-1 < (int)sVar1) && (size != 0xffffffff)) && (sVar2 <= -size - 2)) {
    size_00 = sVar2 + 1 + size;
    if (size_00 < sVar1 << 1) {
      size_00 = sVar1 << 1;
    }
    __dest = (char *)jsonp_malloc(size_00);
    if (__dest != (char *)0x0) {
      memcpy(__dest,strbuff->value,strbuff->length);
      jsonp_free(strbuff->value);
      sVar2 = strbuff->length;
      strbuff->value = __dest;
      strbuff->size = size_00;
      goto LAB_000d2c2c;
    }
  }
  return -1;
}

