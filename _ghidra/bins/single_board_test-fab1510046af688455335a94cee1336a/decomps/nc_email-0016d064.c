
undefined4 nc_email(int *param_1,int *param_2)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char *__s;
  char *__s_00;
  
  __s = (char *)param_2[2];
  __s_00 = (char *)param_1[2];
  pcVar1 = strchr(__s,0x40);
  pcVar2 = strchr(__s_00,0x40);
  if (pcVar2 == (char *)0x0) {
    return 0x35;
  }
  if (pcVar1 == (char *)0x0) {
    if (*__s == '.') {
      if (*param_1 <= *param_2) {
        return 0x2f;
      }
      iVar3 = strcasecmp(__s,__s_00 + (*param_1 - *param_2));
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = 0x2f;
      }
      return uVar4;
    }
  }
  else {
    if (pcVar1 != __s) {
      if ((int)pcVar1 - (int)__s != (int)pcVar2 - (int)__s_00) {
        return 0x2f;
      }
      iVar3 = strncmp(__s,__s_00,(int)pcVar1 - (int)__s);
      if (iVar3 != 0) {
        return 0x2f;
      }
    }
    __s = pcVar1 + 1;
  }
  iVar3 = strcasecmp(__s,pcVar2 + 1);
  if (iVar3 != 0) {
    return 0x2f;
  }
  return 0;
}

