
int curl_strequal(char *param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = strcasecmp(param_1,param_2);
  iVar2 = 1 - uVar1;
  if (1 < uVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

