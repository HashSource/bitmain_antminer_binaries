
/* WARNING: Unknown calling convention */

void strbuffer_clear(strbuffer_t *strbuff)

{
  strbuff->length = 0;
  *strbuff->value = '\0';
  return;
}

