
/* WARNING: Unknown calling convention */

char * jsonp_strsteal(strbuffer_t *strbuff)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)(undefined *)0x0)(strbuff->value,strbuff->length + 1);
  return pcVar1;
}

