
undefined2 SSL_CONF_cmd_value_type(uint *param_1,char *param_2)

{
  size_t sVar1;
  int iVar2;
  char *pcVar3;
  uint __n;
  uint uVar4;
  
  if (param_2 == (char *)0x0) {
    return 0;
  }
  pcVar3 = (char *)param_1[1];
  if (pcVar3 == (char *)0x0) {
    if ((int)(*param_1 << 0x1f) < 0) {
      if (*param_2 != '-') {
        return 0;
      }
      pcVar3 = param_2 + 1;
      param_2 = param_2 + 1;
      if (*pcVar3 == '\0') {
        return 0;
      }
    }
  }
  else {
    sVar1 = strlen(param_2);
    __n = param_1[2];
    if (((sVar1 <= __n) ||
        ((uVar4 = *param_1, (uVar4 & 1) != 0 && (iVar2 = strncmp(param_2,pcVar3,__n), iVar2 != 0))))
       || (((uVar4 & 2) != 0 && (iVar2 = strncasecmp(param_2,pcVar3,__n), iVar2 != 0)))) {
      return 0;
    }
    param_2 = param_2 + __n;
  }
  iVar2 = ssl_conf_cmd_lookup(param_1,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  return *(undefined2 *)(iVar2 + 0xe);
}

