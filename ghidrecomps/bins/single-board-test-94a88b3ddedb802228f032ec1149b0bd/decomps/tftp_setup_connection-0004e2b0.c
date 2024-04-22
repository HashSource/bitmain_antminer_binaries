
undefined4 tftp_setup_connection(int *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  param_1[0x23] = 2;
  pcVar1 = strstr(*(char **)(iVar3 + 0x868c),DAT_0004e308);
  if ((pcVar1 == (char *)0x0) &&
     (pcVar1 = strstr((char *)param_1[0x24],DAT_0004e308), pcVar1 == (char *)0x0)) {
    return 0;
  }
  *pcVar1 = '\0';
  iVar2 = Curl_raw_toupper(pcVar1[6]);
  if ((iVar2 != 0x41) && (iVar2 != 0x4e)) {
    *(undefined *)(iVar3 + 0x2fb) = 0;
    return 0;
  }
  *(undefined *)(iVar3 + 0x2fb) = 1;
  return 0;
}

