
void imap_multi_statemach(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x218) + 0x40) << 0x1f;
  if (((iVar2 < 0) && (*(char *)(param_1 + 0x3fc) == '\0')) &&
     ((iVar2 = Curl_ssl_connect_nonblocking(param_1,0,param_1 + 0x3fc,iVar2,param_4), iVar2 != 0 ||
      (*(char *)(param_1 + 0x3fc) == '\0')))) {
    return;
  }
  Curl_pp_statemach(param_1 + 0x3c0,0);
  cVar1 = '\x01' - (char)*(uint *)(param_1 + 0x3f8);
  if (1 < *(uint *)(param_1 + 0x3f8)) {
    cVar1 = '\0';
  }
  *param_2 = cVar1;
  return;
}

