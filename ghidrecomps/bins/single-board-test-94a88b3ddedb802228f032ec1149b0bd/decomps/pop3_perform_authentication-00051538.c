
int pop3_perform_authentication(undefined4 *param_1)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  iVar1 = Curl_sasl_can_authenticate(param_1 + 0x102,param_1);
  if (iVar1 != 0) {
    iVar1 = local_14;
    if ((int)((param_1[0x109] & param_1[0x108]) << 0x1d) < 0) {
      iVar1 = Curl_sasl_start(param_1 + 0x102,param_1,0,&local_14);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = local_14;
      if (local_14 == 1) {
        iVar1 = 5;
      }
      if (local_14 == 1) {
        param_1[0xfe] = iVar1;
        return 0;
      }
    }
    if (iVar1 != 0) {
      return 0;
    }
    if (-1 < (int)((param_1[0x108] & param_1[0x109]) << 0x1e)) {
      if ((int)((param_1[0x108] & param_1[0x109]) << 0x1f) < 0) {
        iVar1 = pop3_perform_user(param_1);
        return iVar1;
      }
      Curl_infof(*param_1,DAT_000515c8);
      return 0x43;
    }
    iVar1 = 0;
    if (*(char *)((int)param_1 + 0x1f1) != '\0') {
      iVar1 = pop3_perform_apop_part_11(param_1);
      return iVar1;
    }
  }
  param_1[0xfe] = iVar1;
  return iVar1;
}

