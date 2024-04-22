
/* WARNING: Unknown calling convention */

char * opt_invalid_argument(char *arg)

{
  size_t sVar1;
  char *__s;
  char *str;
  
  sVar1 = strlen(arg);
  __s = (char *)malloc(sVar1 + 0x16);
  sprintf(__s,"Invalid argument \'%s\'",arg);
  return __s;
}

