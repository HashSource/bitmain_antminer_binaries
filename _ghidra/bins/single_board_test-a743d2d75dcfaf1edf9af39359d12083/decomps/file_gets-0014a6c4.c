
size_t file_gets(int param_1,char *param_2,int param_3)

{
  size_t sVar1;
  char *pcVar2;
  
  *param_2 = '\0';
  pcVar2 = fgets(param_2,param_3,*(FILE **)(param_1 + 0x20));
  if ((pcVar2 != (char *)0x0) && (*param_2 != '\0')) {
    sVar1 = strlen(param_2);
    return sVar1;
  }
  return 0;
}

