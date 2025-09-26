
undefined4 conf_ssl_name_find(char *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = ssl_names_count;
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (ssl_names_count != 0) {
    iVar4 = 0;
    puVar3 = ssl_names;
    do {
      iVar2 = strcmp((char *)*puVar3,param_1);
      if (iVar2 == 0) {
        *param_2 = iVar4;
        return 1;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 3;
    } while (iVar4 != iVar1);
  }
  return 0;
}

