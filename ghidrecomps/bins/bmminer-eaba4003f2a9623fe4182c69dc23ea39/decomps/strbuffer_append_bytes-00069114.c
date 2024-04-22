
int strbuffer_append_bytes(strbuffer_t *strbuff,char *data,size_t size)

{
  char *__dest;
  uint uVar1;
  uint size_00;
  size_t size_local;
  char *data_local;
  strbuffer_t *strbuff_local;
  char *new_value;
  size_t new_size;
  
  if (strbuff->size - strbuff->length <= size) {
    if ((((int)strbuff->size < 0) || (size == 0xffffffff)) || (-size - 2 < strbuff->length)) {
      return -1;
    }
    uVar1 = strbuff->length + size + 1;
    size_00 = strbuff->size << 1;
    if (size_00 <= uVar1) {
      size_00 = uVar1;
    }
    __dest = (char *)jsonp_malloc(size_00);
    if (__dest == (char *)0x0) {
      return -1;
    }
    memcpy(__dest,strbuff->value,strbuff->length);
    jsonp_free(strbuff->value);
    strbuff->value = __dest;
    strbuff->size = size_00;
  }
  memcpy(strbuff->value + strbuff->length,data,size);
  strbuff->length = strbuff->length + size;
  strbuff->value[strbuff->length] = '\0';
  return 0;
}

