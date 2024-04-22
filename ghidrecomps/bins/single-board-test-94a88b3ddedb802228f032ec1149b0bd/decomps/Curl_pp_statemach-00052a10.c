
int Curl_pp_statemach(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 local_28;
  undefined4 uStack_24;
  
  puVar4 = (undefined4 *)param_1[0xb];
  uVar5 = puVar4[0x55];
  iVar1 = Curl_pp_state_timeout();
  uVar6 = *puVar4;
  if (iVar1 < 1) {
    Curl_failf(uVar6,DAT_00052ad0);
    return 0x1c;
  }
  if (999 < iVar1) {
    iVar1 = 1000;
  }
  if (param_2 == 0) {
    iVar1 = 0;
  }
  if (param_1[6] == 0) {
    if (((*param_1 != 0) && ((uint)param_1[2] < (uint)param_1[1])) ||
       (iVar2 = Curl_ssl_data_pending(puVar4,0), iVar2 != 0)) {
      iVar1 = 1;
      goto joined_r0x00052a74;
    }
    if (param_1[6] != 0) goto LAB_00052a62;
    uVar3 = uVar5;
    uVar5 = 0xffffffff;
  }
  else {
LAB_00052a62:
    uVar3 = 0xffffffff;
  }
  iVar1 = Curl_socket_check(uVar3,0xffffffff,uVar5,iVar1);
joined_r0x00052a74:
  if (param_2 != 0) {
    iVar2 = Curl_pgrsUpdate(puVar4);
    if (iVar2 != 0) {
      return 0x2a;
    }
    curlx_tvnow(&local_28);
    iVar2 = Curl_speedcheck(uVar6,local_28,uStack_24);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if (iVar1 == -1) {
    Curl_failf(uVar6,DAT_00052ad4);
    iVar1 = 0x1b;
  }
  else if (iVar1 != 0) {
    iVar1 = (*(code *)param_1[0xc])(puVar4);
  }
  return iVar1;
}

