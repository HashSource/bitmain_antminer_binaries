
/* WARNING: Unknown calling convention */

void strbuffer_close(strbuffer_t *strbuff)

{
  if (strbuff->value != (char *)0x0) {
    _jsonp_free(&strbuff->value);
  }
  strbuff->size = 0;
  strbuff->length = 0;
  strbuff->value = (char *)0x0;
  return;
}

