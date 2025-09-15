
/* WARNING: Unknown calling convention */

char strbuffer_pop(strbuffer_t *strbuff)

{
  char cVar1;
  size_t sVar2;
  
  if (strbuff->length != 0) {
    sVar2 = strbuff->length - 1;
    strbuff->length = sVar2;
    cVar1 = strbuff->value[sVar2];
    strbuff->value[sVar2] = '\0';
    return cVar1;
  }
  return '\0';
}

