
int ftp_state_ul_setup(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined4 uVar11;
  
  iVar8 = *param_1;
  iVar9 = *(int *)(iVar8 + 0x14c);
  uVar4 = *(uint *)(iVar8 + 0x8698);
  uVar5 = *(uint *)(iVar8 + 0x869c);
  if ((uVar4 | uVar5) != 0) {
    if (param_2 == 0) {
      if ((int)uVar5 < 0) {
        iVar8 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005b8c4,param_1[0x102]);
        if (iVar8 != 0) {
          return iVar8;
        }
        param_1[0x10a] = 0x19;
        return 0;
      }
    }
    else if ((int)(uVar5 - (uVar4 == 0)) < 0 != (SBORROW4(uVar5,(uint)(uVar4 == 0)) != false))
    goto LAB_0005b7b0;
    pcVar3 = (code *)param_1[0x9b];
    *(undefined *)(iVar8 + 0x2fc) = 1;
    if (pcVar3 != (code *)0x0) {
      uVar11 = 0;
      iVar1 = (*pcVar3)(param_1[0x9c]);
      if (iVar1 != 0) {
        if (iVar1 != 2) {
          Curl_failf(iVar8,DAT_0005b8b8);
          return 0x1f;
        }
        uVar5 = 0;
        uVar4 = *(uint *)(iVar8 + 0x8698);
        iVar1 = *(int *)(iVar8 + 0x869c);
        iVar7 = 0;
        do {
          iVar1 = (iVar1 - iVar7) - (uint)(uVar4 < uVar5);
          uVar2 = 0x4000;
          bVar10 = 0x4000 < uVar4 - uVar5;
          if ((int)(-(uint)bVar10 - iVar1) < 0 == (SBORROW4(-iVar1,(uint)bVar10) != false)) {
            uVar2 = curlx_sotouz();
          }
          uVar4 = (**(code **)(iVar8 + 0x86c0))
                            (iVar8 + 0x59c,1,uVar2,*(undefined4 *)(iVar8 + 0x86c4),uVar11);
          uVar6 = 1 - uVar4;
          if (1 < uVar4) {
            uVar6 = 0;
          }
          bVar10 = CARRY4(uVar5,uVar4);
          uVar5 = uVar5 + uVar4;
          iVar7 = iVar7 + (uint)bVar10;
          if (uVar2 < uVar4) {
            uVar6 = uVar6 | 1;
          }
          if (uVar6 != 0) {
            Curl_failf(iVar8,DAT_0005b8cc);
            return 0x1f;
          }
          uVar4 = *(uint *)(iVar8 + 0x8698);
          iVar1 = *(int *)(iVar8 + 0x869c);
        } while ((int)((iVar7 - iVar1) - (uint)(uVar5 < uVar4)) < 0 !=
                 (SBORROW4(iVar7,iVar1) != SBORROW4(iVar7 - iVar1,(uint)(uVar5 < uVar4))));
      }
    }
    uVar4 = *(uint *)(iVar8 + 0x86b0);
    iVar1 = *(int *)(iVar8 + 0x86b4);
    if ((int)(-(uint)(uVar4 != 0) - iVar1) < 0 != (SBORROW4(-iVar1,(uint)(uVar4 != 0)) != false)) {
      iVar7 = uVar4 - *(uint *)(iVar8 + 0x8698);
      iVar1 = (iVar1 - *(int *)(iVar8 + 0x869c)) - (uint)(uVar4 < *(uint *)(iVar8 + 0x8698));
      *(int *)(iVar8 + 0x86b0) = iVar7;
      *(int *)(iVar8 + 0x86b4) = iVar1;
      if ((int)(-(uint)(iVar7 != 0) - iVar1) < 0 == (SBORROW4(-iVar1,(uint)(iVar7 != 0)) != false))
      {
        Curl_infof(iVar8,DAT_0005b8c8);
        Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
        *(undefined4 *)(iVar9 + 0xc) = 2;
        param_1[0x10a] = 0;
        return 0;
      }
    }
  }
LAB_0005b7b0:
  uVar11 = DAT_0005b8bc;
  if (*(char *)(iVar8 + 0x2fc) != '\0') {
    uVar11 = DAT_0005b8c0;
  }
  iVar8 = Curl_pp_sendf(param_1 + 0xf0,uVar11,param_1[0x102]);
  if (iVar8 == 0) {
    param_1[0x10a] = 0x21;
  }
  return iVar8;
}

