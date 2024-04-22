
int ftp_state_retr(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = *param_1;
  iVar7 = *(int *)(iVar6 + 0x14c);
  uVar1 = *(uint *)(iVar6 + 0x2e0);
  uVar4 = *(uint *)(iVar6 + 0x2e4);
  if (((uVar1 | uVar4) != 0) &&
     ((int)((uVar4 - param_4) - (uint)(uVar1 < param_3)) < 0 !=
      (SBORROW4(uVar4,param_4) != SBORROW4(uVar4 - param_4,(uint)(uVar1 < param_3))))) {
    Curl_failf(iVar6,DAT_0005b6c0);
    return 0x3f;
  }
  *(uint *)(iVar7 + 0x10) = param_3;
  *(int *)(iVar7 + 0x14) = param_4;
  uVar1 = *(uint *)(iVar6 + 0x8698);
  uVar4 = *(uint *)(iVar6 + 0x869c);
  if ((uVar1 | uVar4) == 0) {
    iVar6 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005b6c8,param_1[0x102]);
    if (iVar6 != 0) {
      return iVar6;
    }
    param_1[0x10a] = 0x20;
    return 0;
  }
  if (param_4 == -1 && param_3 == 0xffffffff) {
    Curl_infof(iVar6,DAT_0005b6cc);
    uVar2 = *(uint *)(iVar7 + 0x10);
    uVar5 = *(uint *)(iVar7 + 0x14);
  }
  else if ((int)uVar4 < 0) {
    uVar2 = -uVar1;
    uVar5 = -uVar4 - (uint)(uVar1 != 0);
    if ((int)((param_4 - uVar5) - (uint)(param_3 < uVar2)) < 0 !=
        (SBORROW4(param_4,uVar5) != SBORROW4(param_4 - uVar5,(uint)(param_3 < uVar2))))
    goto LAB_0005b626;
    *(uint *)(iVar7 + 0x10) = uVar2;
    *(uint *)(iVar7 + 0x14) = uVar5;
    *(uint *)(iVar6 + 0x8698) = param_3 + uVar1;
    *(uint *)(iVar6 + 0x869c) = param_4 + uVar4 + CARRY4(param_3,uVar1);
  }
  else {
    if ((int)((param_4 - uVar4) - (uint)(param_3 < uVar1)) < 0 !=
        (SBORROW4(param_4,uVar4) != SBORROW4(param_4 - uVar4,(uint)(param_3 < uVar1)))) {
LAB_0005b626:
      Curl_failf(iVar6,DAT_0005b6c4,uVar1,uVar4,param_3,param_4);
      return 0x24;
    }
    uVar2 = param_3 - uVar1;
    uVar5 = (param_4 - uVar4) - (uint)(param_3 < uVar1);
    *(uint *)(iVar7 + 0x10) = uVar2;
    *(uint *)(iVar7 + 0x14) = uVar5;
  }
  if ((uVar2 | uVar5) == 0) {
    iVar3 = 0;
    Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
    Curl_infof(iVar6,DAT_0005b6d0);
    *(undefined4 *)(iVar7 + 0xc) = 2;
    param_1[0x10a] = 0;
  }
  else {
    Curl_infof(iVar6,DAT_0005b6b8,*(undefined4 *)(iVar6 + 0x8698),*(undefined4 *)(iVar6 + 0x869c));
    iVar3 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005b6bc,*(undefined4 *)(iVar6 + 0x8698),
                          *(undefined4 *)(iVar6 + 0x869c));
    if (iVar3 == 0) {
      param_1[0x10a] = 0x1b;
    }
  }
  return iVar3;
}

