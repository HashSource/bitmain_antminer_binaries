
undefined4 tftp_set_timeouts(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar6 = 1 - *param_1;
  if (1 < *param_1) {
    iVar6 = 0;
  }
  time((time_t *)(param_1 + 9));
  iVar1 = Curl_timeleft(*(undefined4 *)param_1[4],0,iVar6);
  if (iVar1 < 0) {
    Curl_failf(*(undefined4 *)param_1[4],DAT_0004df20);
    uVar2 = 0x1c;
  }
  else {
    if (iVar6 == 0) {
      if (iVar1 == 0) {
        uVar3 = 0x2d0;
        iVar6 = 0xe10;
      }
      else {
        iVar6 = (iVar1 + 500) / 1000;
        uVar3 = iVar6 / 5;
      }
      uVar8 = param_1[9];
      param_1[8] = uVar3;
      uVar4 = uVar8 + iVar6;
      param_1[10] = uVar4;
    }
    else {
      uVar8 = param_1[9];
      iVar6 = (iVar1 + 500) / 1000;
      uVar4 = iVar6 >> 0x1f;
      param_1[10] = uVar8 + iVar6;
      uVar7 = iVar6 / 5;
      if ((int)uVar7 < 1) {
        uVar4 = 1;
      }
      uVar3 = uVar4;
      if (0 < (int)uVar7) {
        param_1[8] = uVar7;
        uVar3 = uVar7;
      }
      if ((int)uVar7 < 1) {
        param_1[8] = uVar4;
      }
      uVar7 = __aeabi_idiv(iVar6,uVar3);
      if ((int)uVar7 < 1) {
        uVar4 = 1;
      }
      if (0 < (int)uVar7) {
        param_1[7] = uVar7;
      }
      if ((int)uVar7 < 1) {
        param_1[7] = uVar4;
      }
    }
    uVar7 = uVar3;
    if ((int)uVar3 < 3) {
      uVar7 = 3;
    }
    uVar5 = uVar7;
    if ((int)uVar3 < 3) {
      param_1[8] = uVar7;
    }
    else {
      if (0x32 < (int)uVar7) {
        uVar5 = 0x32;
        uVar4 = uVar5;
      }
      if (0x32 < (int)uVar7) {
        param_1[8] = uVar4;
      }
    }
    uVar7 = __aeabi_idiv(iVar6,uVar5);
    if ((int)uVar7 < 1) {
      uVar4 = 1;
    }
    uVar3 = uVar4;
    if (0 < (int)uVar7) {
      param_1[7] = uVar7;
      uVar3 = uVar7;
    }
    if ((int)uVar7 < 1) {
      param_1[7] = uVar4;
    }
    Curl_infof(*(undefined4 *)param_1[4],DAT_0004df1c,*param_1,param_1[10] - uVar8,uVar3,uVar5);
    time((time_t *)(param_1 + 0xb));
    uVar2 = 0;
  }
  return uVar2;
}

