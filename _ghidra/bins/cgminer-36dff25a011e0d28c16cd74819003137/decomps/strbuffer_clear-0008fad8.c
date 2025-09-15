
void strbuffer_clear(strbuffer_t *strbuff)

{
  strbuffer_t *strbuff_local;
  
  strbuff->length = 0;
  *strbuff->value = '\0';
  return;
}

