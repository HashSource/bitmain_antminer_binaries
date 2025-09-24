
char * pem_check_suffix(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  char *__s1;
  
  sVar1 = strlen(param_1);
  sVar2 = strlen(param_2);
  if ((int)(sVar2 + 1) < (int)sVar1) {
    __s1 = param_1 + (sVar1 - sVar2);
    iVar3 = strcmp(__s1,param_2);
    if ((iVar3 == 0) && (__s1[-1] == ' ')) {
      return __s1 + (-1 - (int)param_1);
    }
  }
  return (char *)0x0;
}

