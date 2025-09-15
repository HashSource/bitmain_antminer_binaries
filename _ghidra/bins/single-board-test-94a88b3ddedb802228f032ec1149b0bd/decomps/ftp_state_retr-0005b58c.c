
int ftp_state_retr(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *param_1;
  iVar6 = *(int *)(iVar5 + 0x14c);
  uVar1 = *(uint *)(iVar5 + 0x2e0);
  iVar3 = *(int *)(iVar5 + 0x2e4);
  if ((uVar1 != 0 || iVar3 != 0) &&
     ((int)((iVar3 - param_4) - (uint)(uVar1 < param_3)) < 0 !=
      (SBORROW4(iVar3,param_4) != SBORROW4(iVar3 - param_4,(uint)(uVar1 < param_3))))) {
    Curl_failf(iVar5,"Maximum file size exceeded");
    return 0x3f;
  }
  *(uint *)(iVar6 + 0x10) = param_3;
  *(int *)(iVar6 + 0x14) = param_4;
  uVar1 = *(uint *)(iVar5 + 0x8698);
  iVar3 = *(int *)(iVar5 + 0x869c);
  if (uVar1 == 0 && iVar3 == 0) {
    iVar3 = Curl_pp_sendf(param_1 + 0xf0,"RETR %s",param_1[0x102]);
    if (iVar3 != 0) {
      return iVar3;
    }
    param_1[0x10a] = 0x20;
    return 0;
  }
  if (param_4 == -1 && param_3 == 0xffffffff) {
    Curl_infof(iVar5,"ftp server doesn\'t support SIZE\n");
    uVar2 = *(uint *)(iVar6 + 0x10);
    iVar4 = *(int *)(iVar6 + 0x14);
  }
  else if (iVar3 < 0) {
    uVar2 = -uVar1;
    iVar4 = -iVar3 - (uint)(uVar1 != 0);
    if ((int)((param_4 - iVar4) - (uint)(param_3 < uVar2)) < 0 !=
        (SBORROW4(param_4,iVar4) != SBORROW4(param_4 - iVar4,(uint)(param_3 < uVar2))))
    goto LAB_0005b626;
    *(uint *)(iVar6 + 0x10) = uVar2;
    *(int *)(iVar6 + 0x14) = iVar4;
    *(uint *)(iVar5 + 0x8698) = param_3 + uVar1;
    *(uint *)(iVar5 + 0x869c) = param_4 + iVar3 + (uint)CARRY4(param_3,uVar1);
  }
  else {
    if ((int)((param_4 - iVar3) - (uint)(param_3 < uVar1)) < 0 !=
        (SBORROW4(param_4,iVar3) != SBORROW4(param_4 - iVar3,(uint)(param_3 < uVar1)))) {
LAB_0005b626:
      Curl_failf(iVar5,"Offset (%lld) was beyond file size (%lld)",uVar1,iVar3,param_3,param_4);
      return 0x24;
    }
    uVar2 = param_3 - uVar1;
    iVar4 = (param_4 - iVar3) - (uint)(param_3 < uVar1);
    *(uint *)(iVar6 + 0x10) = uVar2;
    *(int *)(iVar6 + 0x14) = iVar4;
  }
  if (uVar2 == 0 && iVar4 == 0) {
    iVar3 = 0;
    Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
    Curl_infof(iVar5,"File already completely downloaded\n");
    *(undefined4 *)(iVar6 + 0xc) = 2;
    param_1[0x10a] = 0;
  }
  else {
    Curl_infof(iVar5,"Instructs server to resume from offset %lld\n",*(undefined4 *)(iVar5 + 0x8698)
               ,*(undefined4 *)(iVar5 + 0x869c));
    iVar3 = Curl_pp_sendf(param_1 + 0xf0,"REST %lld",*(undefined4 *)(iVar5 + 0x8698),
                          *(undefined4 *)(iVar5 + 0x869c));
    if (iVar3 == 0) {
      param_1[0x10a] = 0x1b;
    }
  }
  return iVar3;
}

