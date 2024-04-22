
void pop3_perform_user(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x1f1) != '\0') {
    iVar1 = *(int *)(param_1 + 0x120);
    if (*(int *)(param_1 + 0x120) == 0) {
      iVar1 = DAT_00051158;
    }
    iVar1 = Curl_pp_sendf(param_1 + 0x3c0,DAT_0005115c,iVar1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x3f8) = 7;
    }
    return;
  }
  *(undefined4 *)(param_1 + 0x3f8) = 0;
  return;
}

