
char * opt_invalid_argument(char *param_1)

{
  size_t sVar1;
  char *__s;
  
  sVar1 = strlen(param_1);
  __s = (char *)malloc(sVar1 + 0x16);
  sprintf(__s,"Invalid argument \'%s\'",param_1);
  return __s;
}

