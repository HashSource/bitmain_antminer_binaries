
int Curl_GetFTPResponse(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  bool bVar7;
  int local_34;
  int local_30;
  int local_2c [2];
  
  uVar2 = *param_2;
  uVar4 = param_2[0x55];
  local_30 = 0;
  if (param_3 == (int *)0x0) {
    param_3 = &local_30;
  }
  else {
    *param_3 = 0;
  }
  iVar3 = 0;
  *param_1 = 0;
LAB_0005cd6c:
  while( true ) {
    if (*param_3 != 0) {
      iVar1 = 0;
      goto LAB_0005ce28;
    }
    iVar1 = Curl_pp_state_timeout(param_2 + 0xf0);
    if (iVar1 < 1) {
      Curl_failf(uVar2,DAT_0005ce50);
      return 0x1c;
    }
    if ((param_2[0xf0] != 0) && (iVar3 < 2)) break;
    iVar1 = Curl_socket_check(uVar4,0xffffffff,0xffffffff);
    if (iVar1 == -1) {
      piVar5 = __errno_location();
      Curl_failf(uVar2,DAT_0005ce48,*piVar5);
      return 0x38;
    }
    if (iVar1 != 0) break;
    iVar1 = Curl_pgrsUpdate(param_2);
    if (iVar1 != 0) {
      return 0x2a;
    }
  }
  piVar5 = (int *)param_2[0xfb];
  iVar6 = *piVar5;
  iVar1 = Curl_pp_readresp(uVar4,param_2 + 0xf0,local_2c,&local_34);
  *(int *)(iVar6 + 0x86f4) = local_2c[0];
  bVar7 = local_2c[0] == 0x1a5;
  *param_3 = local_2c[0];
  if (bVar7) {
    Curl_infof(iVar6,DAT_0005ce4c);
    iVar1 = 0x1c;
    piVar5[0x10a] = 0;
  }
  else if (iVar1 == 0) {
    if (local_34 == 0) {
      iVar3 = iVar3 + 1;
      if (param_2[0xf0] == 0) {
        iVar3 = 0;
      }
      *param_1 = *param_1;
    }
    else {
      *param_1 = *param_1 + local_34;
      iVar3 = 0;
    }
    goto LAB_0005cd6c;
  }
LAB_0005ce28:
  *(undefined *)(param_2 + 0xf4) = 0;
  return iVar1;
}

