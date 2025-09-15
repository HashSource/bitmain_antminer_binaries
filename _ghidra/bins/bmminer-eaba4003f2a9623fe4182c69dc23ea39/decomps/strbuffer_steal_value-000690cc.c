
char * strbuffer_steal_value(strbuffer_t *strbuff)

{
  char *pcVar1;
  strbuffer_t *strbuff_local;
  char *result;
  
  pcVar1 = strbuff->value;
  strbuff->value = (char *)0x0;
  return pcVar1;
}

