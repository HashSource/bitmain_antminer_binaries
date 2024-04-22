
int strbuffer_init(strbuffer_t *strbuff)

{
  char *pcVar1;
  int iVar2;
  strbuffer_t *strbuff_local;
  
  strbuff->size = 0x10;
  strbuff->length = 0;
  pcVar1 = (char *)jsonp_malloc(strbuff->size);
  strbuff->value = pcVar1;
  if (strbuff->value == (char *)0x0) {
    iVar2 = -1;
  }
  else {
    *strbuff->value = '\0';
    iVar2 = 0;
  }
  return iVar2;
}

