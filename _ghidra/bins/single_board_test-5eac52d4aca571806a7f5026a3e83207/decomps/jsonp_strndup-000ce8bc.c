
/* WARNING: Unknown calling convention */

char * jsonp_strndup(char *str,size_t len)

{
  char *__dest;
  char *new_str;
  
  if ((len + 1 != 0) && (__dest = (char *)(*do_malloc)(len + 1), __dest != (char *)0x0)) {
    memcpy(__dest,str,len);
    __dest[len] = '\0';
    return __dest;
  }
  return (char *)0x0;
}

