
void smtp_perform_upgrade_tls(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = Curl_ssl_connect_nonblocking(param_1,0,param_1 + 0x3fc);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x3f8);
    bVar3 = iVar2 != 5;
    if (bVar3) {
      iVar2 = 5;
    }
    if (bVar3) {
      *(int *)(param_1 + 0x3f8) = iVar2;
    }
    uVar1 = DAT_00052390;
    if (*(char *)(param_1 + 0x3fc) != '\0') {
      *(undefined4 *)(param_1 + 0x40c) = 0;
      *(undefined *)(param_1 + 0x1ec) = 1;
      *(undefined4 *)(param_1 + 0x218) = uVar1;
      *(undefined4 *)(param_1 + 0x414) = 0;
      *(undefined *)(param_1 + 0x41c) = 0;
      *(undefined *)(param_1 + 0x41e) = 0;
      iVar2 = Curl_pp_sendf(param_1 + 0x3c0,DAT_00052394,*(undefined4 *)(param_1 + 0x400));
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + 0x3f8) = 2;
        return;
      }
    }
  }
  return;
}

