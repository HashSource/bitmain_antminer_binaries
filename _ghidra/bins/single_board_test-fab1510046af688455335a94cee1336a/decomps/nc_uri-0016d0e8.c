
undefined4 nc_uri(int param_1,size_t *param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  size_t __n;
  size_t __n_00;
  char *__s2;
  
  __s2 = (char *)param_2[2];
  pcVar1 = strchr(*(char **)(param_1 + 8),0x3a);
  if (((pcVar1 != (char *)0x0) && (pcVar1[1] == '/')) && (pcVar1[2] == '/')) {
    pcVar1 = pcVar1 + 3;
    pcVar2 = strchr(pcVar1,0x3a);
    if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(pcVar1,0x2f), pcVar2 == (char *)0x0)) {
      __n_00 = strlen(pcVar1);
    }
    else {
      __n_00 = (int)pcVar2 - (int)pcVar1;
    }
    if (__n_00 != 0) {
      __n = *param_2;
      if (*__s2 == '.') {
        if ((int)__n < (int)__n_00) {
          iVar4 = strncasecmp(pcVar1 + (__n_00 - __n),__s2,__n);
          if (iVar4 == 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = 0x2f;
          }
          return uVar3;
        }
      }
      else if ((__n == __n_00) && (iVar4 = strncasecmp(pcVar1,__s2,__n_00), iVar4 == 0)) {
        return 0;
      }
      return 0x2f;
    }
  }
  return 0x35;
}

