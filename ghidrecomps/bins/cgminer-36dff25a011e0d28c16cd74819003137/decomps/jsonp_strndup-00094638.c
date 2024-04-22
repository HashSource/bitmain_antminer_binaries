
char * jsonp_strndup(char *str,size_t len)

{
  char *__dest;
  size_t len_local;
  char *str_local;
  char *new_str;
  
  __dest = (char *)jsonp_malloc(len + 1);
  if (__dest == (char *)0x0) {
    __dest = (char *)0x0;
  }
  else {
    memcpy(__dest,str,len);
    __dest[len] = '\0';
  }
  return __dest;
}

