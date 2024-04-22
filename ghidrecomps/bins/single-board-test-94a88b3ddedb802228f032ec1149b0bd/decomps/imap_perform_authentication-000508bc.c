
int imap_perform_authentication(undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  int local_14 [2];
  
  iVar1 = Curl_sasl_can_authenticate(param_1 + 0x100,param_1);
  if (iVar1 != 0) {
    iVar1 = Curl_sasl_start(param_1 + 0x100,param_1,*(undefined *)((int)param_1 + 0x427),local_14);
    if (iVar1 != 0) {
      return iVar1;
    }
    bVar2 = local_14[0] == 1;
    if (bVar2) {
      local_14[0] = 5;
    }
    if (bVar2) {
      param_1[0xfe] = local_14[0];
      return 0;
    }
    if ((*(char *)((int)param_1 + 0x426) != '\0') || (-1 < (int)(param_1[0x106] << 0x1f))) {
      Curl_infof(*param_1,DAT_00050924);
      return 0x43;
    }
    iVar1 = 0;
    if (*(char *)((int)param_1 + 0x1f1) != '\0') {
      iVar1 = imap_perform_login_part_7(param_1);
      return iVar1;
    }
  }
  param_1[0xfe] = iVar1;
  return iVar1;
}

