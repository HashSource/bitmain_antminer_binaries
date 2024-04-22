
undefined4
Curl_resolv_timeout(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                   int param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_134;
  undefined4 local_130;
  undefined4 uStack_12c;
  sigaction sStack_128;
  sigaction local_9c;
  
  iVar4 = *param_1;
  bVar1 = false;
  *param_4 = 0;
  local_134 = 0;
  if (param_5 < 0) {
    return 0xfffffffe;
  }
  if ((*(char *)(iVar4 + 0x324) != '\0') || (param_5 == 0)) {
    uVar5 = Curl_resolv(param_1,param_2,param_3,param_4);
    return uVar5;
  }
  if (param_5 < 1000) {
    return 0xfffffffe;
  }
  iVar2 = __sigsetjmp(curl_jmpenv,1);
  if (iVar2 == 0) {
    sigaction(0xe,(sigaction *)0x0,&local_9c);
    memcpy(&sStack_128,&local_9c,0x8c);
    bVar1 = true;
    local_9c.sa_flags = local_9c.sa_flags & 0xefffffff;
    local_9c.__sigaction_handler.sa_handler = alarmfunc + 1;
    sigaction(0xe,&local_9c,(sigaction *)0x0);
    uVar3 = curlx_sltoui(param_5 / 1000);
    local_134 = alarm(uVar3);
    uVar5 = Curl_resolv(param_1,param_2,param_3,param_4);
    if (local_134 == 0) goto LAB_0003d94e;
  }
  else {
    uVar5 = 0xffffffff;
    Curl_failf(iVar4,"name lookup timed out");
LAB_0003d94e:
    alarm(local_134);
    if (!bVar1) goto joined_r0x0003d968;
  }
  sigaction(0xe,&sStack_128,(sigaction *)0x0);
joined_r0x0003d968:
  if (local_134 != 0) {
    curlx_tvnow(&local_130);
    uVar3 = curlx_tvdiff(local_130,uStack_12c,param_1[0x53],param_1[0x54]);
    uVar3 = local_134 - uVar3 / 1000;
    if ((uVar3 == 0) || (((int)uVar3 < 0 && (-1 < (int)local_134)))) {
      uVar5 = 0xfffffffe;
      alarm(1);
      Curl_failf(iVar4,"Previous alarm fired off!");
    }
    else {
      alarm(uVar3);
    }
  }
  return uVar5;
}

