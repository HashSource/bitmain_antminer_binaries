
/* WARNING: Unknown calling convention */

int strbuffer_append_bytes(strbuffer_t *strbuff,char *data,size_t size)

{
  size_t sVar1;
  __useconds_t __useconds;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  uint __size;
  
  sVar2 = strbuff->size;
  sVar1 = strbuff->length;
  if (sVar2 - sVar1 < size + 2) {
    if ((((int)sVar2 < 0) || (size == 0xffffffff)) || (-size - 2 < sVar1)) {
      return -1;
    }
    __size = sVar1 + 1 + size;
    if (__size < sVar2 << 1) {
      __size = sVar2 << 1;
    }
    iVar4 = 1;
    while( true ) {
      pcVar3 = (char *)realloc(strbuff->value,__size);
      __useconds = iVar4 * 1000;
      if (pcVar3 != (char *)0x0) break;
      iVar4 = iVar4 << 1;
      usleep(__useconds);
    }
    sVar1 = strbuff->length;
    strbuff->value = pcVar3;
    strbuff->size = __size;
  }
  else {
    pcVar3 = strbuff->value;
  }
  memcpy(pcVar3 + sVar1,data,size);
  sVar1 = strbuff->length + size;
  strbuff->length = sVar1;
  strbuff->value[sVar1] = '\0';
  return 0;
}

