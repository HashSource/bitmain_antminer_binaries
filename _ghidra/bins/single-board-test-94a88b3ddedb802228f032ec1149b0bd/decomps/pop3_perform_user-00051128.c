
void pop3_perform_user(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (*(char *)(param_1 + 0x1f1) != '\0') {
    puVar2 = *(undefined1 **)(param_1 + 0x120);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = &DAT_0013a6fc;
    }
    iVar1 = Curl_pp_sendf(param_1 + 0x3c0,"USER %s",puVar2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x3f8) = 7;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x3f8) = 0;
  return;
}

