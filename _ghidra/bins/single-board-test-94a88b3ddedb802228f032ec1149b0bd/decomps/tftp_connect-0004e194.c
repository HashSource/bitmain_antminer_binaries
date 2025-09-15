
undefined4 tftp_connect(int *param_1,undefined1 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = (undefined4 *)(*Curl_ccalloc)(1,0x150);
  param_1[0xf0] = (int)puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x1b;
  }
  iVar5 = *(int *)(*param_1 + 0x210);
  if (iVar5 == 0) {
    iVar5 = 0x200;
  }
  else if (0xffb0 < iVar5 - 8U) {
    return 0x47;
  }
  if (puVar1[0x52] == 0) {
    iVar4 = (*Curl_ccalloc)(1,iVar5 + 4);
    puVar1[0x52] = iVar4;
    if (iVar4 == 0) {
      return 0x1b;
    }
  }
  if (puVar1[0x53] == 0) {
    iVar4 = (*Curl_ccalloc)(1,iVar5 + 4);
    puVar1[0x53] = iVar4;
    if (iVar4 == 0) {
      return 0x1b;
    }
  }
  uVar3 = *(undefined4 *)(param_1[0x13] + 4);
  *(undefined1 *)((int)param_1 + 0x1ed) = 1;
  puVar1[4] = param_1;
  *(short *)(puVar1 + 0xd) = (short)uVar3;
  iVar4 = param_1[0x55];
  puVar1[2] = 0xffffff9c;
  puVar1[0x51] = iVar5;
  puVar1[5] = iVar4;
  *puVar1 = 0;
  puVar1[0x50] = 0x200;
  tftp_set_timeouts(puVar1);
  if (*(char *)((int)param_1 + 0x203) == '\0') {
    iVar5 = bind(puVar1[5],(sockaddr *)(puVar1 + 0xd),*(socklen_t *)(param_1[0x13] + 0x10));
    if (iVar5 != 0) {
      piVar2 = __errno_location();
      iVar5 = *param_1;
      uVar3 = Curl_strerror(param_1,*piVar2);
      Curl_failf(iVar5,"bind() failed; %s",uVar3);
      return 7;
    }
    *(undefined1 *)((int)param_1 + 0x203) = 1;
  }
  Curl_pgrsStartNow(*param_1);
  *param_2 = 1;
  return 0;
}

