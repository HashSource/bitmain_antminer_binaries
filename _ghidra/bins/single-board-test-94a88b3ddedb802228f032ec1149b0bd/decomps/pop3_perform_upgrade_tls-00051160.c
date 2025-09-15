
void pop3_perform_upgrade_tls(int param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = Curl_ssl_connect_nonblocking(param_1,0,param_1 + 0x3fc);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x3f8);
    bVar2 = iVar1 != 4;
    if (bVar2) {
      iVar1 = 4;
    }
    if (bVar2) {
      *(int *)(param_1 + 0x3f8) = iVar1;
    }
    if (*(char *)(param_1 + 0x3fc) != '\0') {
      *(undefined4 *)(param_1 + 0x410) = 0;
      *(undefined1 *)(param_1 + 0x1ec) = 1;
      *(undefined1 **)(param_1 + 0x218) = Curl_handler_pop3s;
      *(undefined4 *)(param_1 + 0x418) = 0;
      *(undefined1 *)(param_1 + 0x42c) = 0;
      iVar1 = Curl_pp_sendf(param_1 + 0x3c0,"%s",&DAT_0013978c);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x3f8) = 2;
        return;
      }
    }
  }
  return;
}

