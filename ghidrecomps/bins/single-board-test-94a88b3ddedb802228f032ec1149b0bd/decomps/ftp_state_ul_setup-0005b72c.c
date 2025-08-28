
int ftp_state_ul_setup(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  undefined4 uVar12;
  
  iVar9 = *param_1;
  iVar10 = *(int *)(iVar9 + 0x14c);
  iVar5 = *(int *)(iVar9 + 0x869c);
  if (*(int *)(iVar9 + 0x8698) != 0 || iVar5 != 0) {
    if (param_2 == 0) {
      if (iVar5 < 0) {
        iVar5 = Curl_pp_sendf(param_1 + 0xf0,"SIZE %s",param_1[0x102]);
        if (iVar5 != 0) {
          return iVar5;
        }
        param_1[0x10a] = 0x19;
        return 0;
      }
    }
    else if (iVar5 < (int)(uint)(*(int *)(iVar9 + 0x8698) == 0)) goto LAB_0005b7b0;
    pcVar3 = (code *)param_1[0x9b];
    *(undefined1 *)(iVar9 + 0x2fc) = 1;
    if (pcVar3 != (code *)0x0) {
      uVar12 = 0;
      iVar5 = (*pcVar3)(param_1[0x9c]);
      if (iVar5 != 0) {
        if (iVar5 != 2) {
          Curl_failf(iVar9,"Could not seek stream");
          return 0x1f;
        }
        uVar7 = 0;
        uVar1 = *(uint *)(iVar9 + 0x8698);
        iVar5 = *(int *)(iVar9 + 0x869c);
        iVar8 = 0;
        do {
          uVar2 = 0x4000;
          if ((int)(uint)(0x4000 < uVar1 - uVar7) <= (int)-((iVar5 - iVar8) - (uint)(uVar1 < uVar7))
             ) {
            uVar2 = curlx_sotouz();
          }
          uVar1 = (**(code **)(iVar9 + 0x86c0))
                            (iVar9 + 0x59c,1,uVar2,*(undefined4 *)(iVar9 + 0x86c4),uVar12);
          uVar6 = 1 - uVar1;
          if (1 < uVar1) {
            uVar6 = 0;
          }
          bVar11 = CARRY4(uVar7,uVar1);
          uVar7 = uVar7 + uVar1;
          iVar8 = iVar8 + (uint)bVar11;
          if (uVar2 < uVar1) {
            uVar6 = uVar6 | 1;
          }
          if (uVar6 != 0) {
            Curl_failf(iVar9,"Failed to read data");
            return 0x1f;
          }
          uVar1 = *(uint *)(iVar9 + 0x8698);
          iVar5 = *(int *)(iVar9 + 0x869c);
        } while ((int)((iVar8 - iVar5) - (uint)(uVar7 < uVar1)) < 0 !=
                 (SBORROW4(iVar8,iVar5) != SBORROW4(iVar8 - iVar5,(uint)(uVar7 < uVar1))));
      }
    }
    uVar1 = *(uint *)(iVar9 + 0x86b0);
    if (-*(int *)(iVar9 + 0x86b4) < (int)(uint)(uVar1 != 0)) {
      iVar5 = uVar1 - *(uint *)(iVar9 + 0x8698);
      iVar8 = (*(int *)(iVar9 + 0x86b4) - *(int *)(iVar9 + 0x869c)) -
              (uint)(uVar1 < *(uint *)(iVar9 + 0x8698));
      *(int *)(iVar9 + 0x86b0) = iVar5;
      *(int *)(iVar9 + 0x86b4) = iVar8;
      if ((int)(uint)(iVar5 != 0) <= -iVar8) {
        Curl_infof(iVar9,"File already completely uploaded\n");
        Curl_setup_transfer(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,0xffffffff,0);
        *(undefined4 *)(iVar10 + 0xc) = 2;
        param_1[0x10a] = 0;
        return 0;
      }
    }
  }
LAB_0005b7b0:
  pcVar4 = "STOR %s";
  if (*(char *)(iVar9 + 0x2fc) != '\0') {
    pcVar4 = "APPE %s";
  }
  iVar5 = Curl_pp_sendf(param_1 + 0xf0,pcVar4,param_1[0x102]);
  if (iVar5 == 0) {
    param_1[0x10a] = 0x21;
  }
  return iVar5;
}

