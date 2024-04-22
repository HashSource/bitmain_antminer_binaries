
int smtp_perform_authentication(undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  int local_14 [2];
  
  if (*(char *)((int)param_1 + 0x41e) != '\0') {
    iVar1 = Curl_sasl_can_authenticate(param_1 + 0x101,param_1);
    if (iVar1 != 0) {
      iVar1 = Curl_sasl_start(param_1 + 0x101,param_1,0,local_14);
      if (iVar1 != 0) {
        return iVar1;
      }
      bVar2 = local_14[0] == 1;
      if (bVar2) {
        local_14[0] = 6;
      }
      if (!bVar2) {
        Curl_infof(*param_1,DAT_00051da4);
        return 0x43;
      }
      param_1[0xfe] = local_14[0];
      return 0;
    }
  }
  param_1[0xfe] = 0;
  return 0;
}

