
void strbuffer_close(strbuffer_t *strbuff)

{
  strbuffer_t *strbuff_local;
  
  if (strbuff->value != (char *)0x0) {
    jsonp_free(strbuff->value);
  }
  strbuff->size = 0;
  strbuff->length = 0;
  strbuff->value = (char *)0x0;
  return;
}

