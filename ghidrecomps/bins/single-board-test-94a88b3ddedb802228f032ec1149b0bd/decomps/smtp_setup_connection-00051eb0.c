
undefined4 smtp_setup_connection(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  bool bVar6;
  
  *(undefined1 *)(param_1 + 0x7b) = 0;
  iVar5 = *param_1;
  if (((char)param_1[0x7c] != '\0') && (*(char *)(iVar5 + 0x2fa) == '\0')) {
    puVar3 = (undefined1 *)param_1[0x86];
    bVar6 = puVar3 == Curl_handler_smtp;
    if (!bVar6) {
      puVar3 = Curl_handler_smtps_proxy;
    }
    puVar4 = puVar3;
    if (bVar6) {
      param_1[0x86] = (int)&Curl_handler_smtp_proxy;
      puVar4 = &Curl_handler_smtp_proxy;
    }
    if (!bVar6) {
      param_1[0x86] = (int)puVar3;
    }
    uVar2 = (**(code **)(puVar4 + 4))();
    return uVar2;
  }
  iVar1 = (*Curl_ccalloc)(0x14,1);
  *(int *)(iVar5 + 0x14c) = iVar1;
  if (iVar1 != 0) {
    *(int *)(iVar5 + 0x868c) = *(int *)(iVar5 + 0x868c) + 1;
    return 0;
  }
  return 0x1b;
}

