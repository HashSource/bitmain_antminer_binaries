
char * jsonp_strdup(char *str)

{
  size_t len;
  char *pcVar1;
  char *str_local;
  
  len = strlen(str);
  pcVar1 = jsonp_strndup(str,len);
  return pcVar1;
}

