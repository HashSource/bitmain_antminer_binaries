
/* WARNING: Unknown calling convention */

char * arg_bad(char *fmt,char *arg)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  char *str;
  
  sVar1 = strlen(fmt);
  sVar2 = strlen(arg);
  __s = (char *)malloc(sVar2 + sVar1);
  sprintf(__s,fmt,arg);
  return __s;
}

