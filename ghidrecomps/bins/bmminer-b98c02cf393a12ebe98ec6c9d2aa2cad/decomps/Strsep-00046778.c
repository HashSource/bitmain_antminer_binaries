
char * Strsep(char **param_1,char *param_2)

{
  char *pcVar1;
  char *__s;
  
  __s = *param_1;
  if ((__s != (char *)0x0) && (pcVar1 = strpbrk(__s,param_2), pcVar1 != (char *)0x0)) {
    *pcVar1 = '\0';
    *param_1 = pcVar1 + 1;
    return __s;
  }
  *param_1 = (char *)0x0;
  return __s;
}

