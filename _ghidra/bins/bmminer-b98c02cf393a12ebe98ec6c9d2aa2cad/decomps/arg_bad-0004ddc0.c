
char * arg_bad(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  char *__s;
  
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_2);
  __s = (char *)malloc(sVar2 + sVar1);
  sprintf(__s,param_1,param_2);
  return __s;
}

