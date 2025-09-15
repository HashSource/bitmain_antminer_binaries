
char strbuffer_pop(strbuffer_t *strbuff)

{
  char cVar1;
  strbuffer_t *strbuff_local;
  char c;
  
  if (strbuff->length == 0) {
    cVar1 = '\0';
  }
  else {
    strbuff->length = strbuff->length - 1;
    cVar1 = strbuff->value[strbuff->length];
    strbuff->value[strbuff->length] = '\0';
  }
  return cVar1;
}

