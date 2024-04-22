
void pop3_perform_upgrade_tls(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = Curl_ssl_connect_nonblocking(param_1,0,param_1 + 0x3fc);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x3f8);
    bVar3 = iVar2 != 4;
    if (bVar3) {
      iVar2 = 4;
    }
    if (bVar3) {
      *(int *)(param_1 + 0x3f8) = iVar2;
    }
    uVar1 = DAT_000511b8;
    if (*(char *)(param_1 + 0x3fc) != '\0') {
      *(undefined4 *)(param_1 + 0x410) = 0;
      *(undefined *)(param_1 + 0x1ec) = 1;
      *(undefined4 *)(param_1 + 0x218) = uVar1;
      *(undefined4 *)(param_1 + 0x418) = 0;
      *(undefined *)(param_1 + 0x42c) = 0;
      iVar2 = Curl_pp_sendf(param_1 + 0x3c0,DAT_000511bc,DAT_000511c0);
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x3f8) = 2;
        return;
      }
    }
  }
  return;
}

