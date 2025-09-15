
/* WARNING: Unknown calling convention */

int strbuffer_init(strbuffer_t *strbuff)

{
  char *pcVar1;
  
  strbuff->size = 0x1000;
  strbuff->length = 0;
  pcVar1 = (char *)jsonp_malloc(0x1000);
  strbuff->value = pcVar1;
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
    return 0;
  }
  return -1;
}

