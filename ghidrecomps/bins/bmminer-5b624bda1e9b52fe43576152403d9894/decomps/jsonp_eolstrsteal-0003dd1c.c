
/* WARNING: Unknown calling convention */

char * jsonp_eolstrsteal(strbuffer_t *strbuff)

{
  char *pcVar1;
  
  pcVar1 = (char *)realloc(strbuff->value,strbuff->length + 2);
  pcVar1[strbuff->length] = '\n';
  pcVar1[strbuff->length + 1] = '\0';
  return pcVar1;
}

