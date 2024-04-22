
/* WARNING: Unknown calling convention */

char * jsonp_strdup(char *str)

{
  size_t sVar1;
  size_t len;
  char *__dest;
  char *new_str;
  
  sVar1 = strlen(str);
  if (((sVar1 != 0xffffffff) && (sVar1 = sVar1 + 1, sVar1 != 0)) &&
     (__dest = (char *)(**DAT_0003dd10)(sVar1), __dest != (char *)0x0)) {
    memcpy(__dest,str,sVar1);
    return __dest;
  }
  return (char *)0x0;
}

