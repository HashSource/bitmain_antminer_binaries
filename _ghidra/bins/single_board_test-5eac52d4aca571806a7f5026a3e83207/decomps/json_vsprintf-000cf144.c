
/* WARNING: Unknown calling convention */

json_t * json_vsprintf(char *fmt,va_list ap)

{
  size_t length;
  json_t *__s;
  int iVar1;
  va_list aq;
  
  length = vsnprintf((char *)0x0,0,fmt,ap.__ap);
  if (length == 0) {
    __s = json_string("");
  }
  else {
    __s = (json_t *)jsonp_malloc(length + 1);
    if (__s != (json_t *)0x0) {
      vsnprintf((char *)__s,length + 1,fmt,ap.__ap);
      iVar1 = utf8_check_string((char *)__s,length);
      if (iVar1 == 0) {
        jsonp_free(__s);
        __s = (json_t *)0x0;
      }
      else {
        __s = jsonp_stringn_nocheck_own((char *)__s,length);
      }
    }
  }
  return __s;
}

