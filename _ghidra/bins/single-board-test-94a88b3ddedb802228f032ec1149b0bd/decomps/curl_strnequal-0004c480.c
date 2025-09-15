
int curl_strnequal(char *param_1,char *param_2,size_t param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = strncasecmp(param_1,param_2,param_3);
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

