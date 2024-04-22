
undefined4 tftp_connect(int *param_1,undefined *param_2)

{
  code **ppcVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  ppcVar1 = DAT_0004e288;
  puVar2 = (undefined4 *)(**DAT_0004e288)(1,0x150);
  param_1[0xf0] = (int)puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    return 0x1b;
  }
  iVar6 = *(int *)(*param_1 + 0x210);
  if (iVar6 == 0) {
    iVar6 = 0x200;
  }
  else if (0xffb0 < iVar6 - 8U) {
    return 0x47;
  }
  if (puVar2[0x52] == 0) {
    iVar5 = (**ppcVar1)(1,iVar6 + 4);
    puVar2[0x52] = iVar5;
    if (iVar5 == 0) {
      return 0x1b;
    }
  }
  if (puVar2[0x53] == 0) {
    iVar5 = (**ppcVar1)(1,iVar6 + 4);
    puVar2[0x53] = iVar5;
    if (iVar5 == 0) {
      return 0x1b;
    }
  }
  uVar4 = *(undefined4 *)(param_1[0x13] + 4);
  *(undefined *)((int)param_1 + 0x1ed) = 1;
  puVar2[4] = param_1;
  *(short *)(puVar2 + 0xd) = (short)uVar4;
  iVar5 = param_1[0x55];
  puVar2[2] = 0xffffff9c;
  puVar2[0x51] = iVar6;
  puVar2[5] = iVar5;
  *puVar2 = 0;
  puVar2[0x50] = 0x200;
  tftp_set_timeouts(puVar2);
  if (*(char *)((int)param_1 + 0x203) == '\0') {
    iVar6 = bind(puVar2[5],(sockaddr *)(puVar2 + 0xd),*(socklen_t *)(param_1[0x13] + 0x10));
    if (iVar6 != 0) {
      piVar3 = __errno_location();
      iVar6 = *param_1;
      uVar4 = Curl_strerror(param_1,*piVar3);
      Curl_failf(iVar6,DAT_0004e28c,uVar4);
      return 7;
    }
    *(undefined *)((int)param_1 + 0x203) = 1;
  }
  Curl_pgrsStartNow(*param_1);
  *param_2 = 1;
  return 0;
}

