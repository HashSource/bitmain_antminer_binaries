
int ftp_state_prepare_transfer(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(*(int *)(iVar2 + 0x14c) + 0xc) != 0) {
    param_1[0x10a] = 0xd;
    iVar2 = ftp_state_quote(param_1,1);
    return iVar2;
  }
  if (*(char *)(iVar2 + 0x2fe) != '\0') {
    iVar2 = ftp_state_use_port();
    return iVar2;
  }
  if (*(char *)(iVar2 + 0x316) == '\0') {
    iVar2 = ftp_state_use_pasv();
    return iVar2;
  }
  if (param_1[0x102] == 0) {
    iVar1 = *(int *)(iVar2 + 0x350);
    if ((*(int *)(iVar2 + 0x350) == 0) && (iVar1 = DAT_0005cb94, *(char *)(iVar2 + 0x2fd) != '\0'))
    {
      iVar1 = DAT_0005cb98;
    }
    iVar2 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cb90,iVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  else if (*(char *)(iVar2 + 0x309) == '\0') {
    iVar2 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cb8c);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  else {
    iVar2 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cb88);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  param_1[0x10a] = 0x1d;
  return 0;
}

