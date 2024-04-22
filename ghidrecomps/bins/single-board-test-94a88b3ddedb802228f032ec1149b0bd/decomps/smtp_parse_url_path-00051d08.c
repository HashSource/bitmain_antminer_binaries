
void smtp_parse_url_path(int *param_1)

{
  int iVar1;
  char *pcVar2;
  char acStack_414 [1032];
  
  iVar1 = *param_1;
  pcVar2 = *(char **)(iVar1 + 0x868c);
  if (**(char **)(iVar1 + 0x868c) == '\0') {
    iVar1 = Curl_gethostname(acStack_414,0x401);
    if (iVar1 == 0) {
      pcVar2 = acStack_414;
      iVar1 = *param_1;
    }
    else {
      iVar1 = *param_1;
      pcVar2 = DAT_00051d50;
    }
  }
  Curl_urldecode(iVar1,pcVar2,0,param_1 + 0x100,0,1);
  return;
}

