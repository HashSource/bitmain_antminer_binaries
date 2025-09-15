
char * arg_bad(char *fmt,char *arg)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  char *arg_local;
  char *fmt_local;
  char *str;
  
  sVar1 = strlen(fmt);
  sVar2 = strlen(arg);
  __s = (char *)malloc(sVar1 + sVar2);
  sprintf(__s,fmt,arg);
  return __s;
}

