
/* WARNING: Unknown calling convention */

_Bool DownOneChipFreqOneStep(void)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  char logstr [256];
  
  iVar9 = 0;
  iVar1 = 0;
  iVar5 = -1;
  do {
    while (iVar8 = iVar1, dev->chain_exist[iVar8] != 1) {
LAB_0002eee6:
      iVar1 = iVar8 + 1;
      if (iVar8 + 1 == 0x10) goto LAB_0002ef24;
    }
    if (dev->chain_asic_num[iVar8] != '\x12') {
      return false;
    }
    if ((iVar9 != 0) && (iVar1 = GetBoardRate(iVar8), iVar1 <= iVar9)) goto LAB_0002eee6;
    iVar9 = GetBoardRate(iVar8);
    iVar1 = iVar8 + 1;
    iVar5 = iVar8;
  } while (iVar8 + 1 != 0x10);
LAB_0002ef24:
  if (iVar5 == -1) {
    sprintf(logstr,"Fatal Error: DownOneChipFreqOneStep has Wrong chain index=%d\n",0xffffffff);
    writeInitLogFile(logstr);
  }
  else {
    uVar2 = (uint)dev->chain_asic_num[iVar5];
    if (uVar2 != 0) {
      iVar9 = iVar5 / 3;
      uVar11 = iVar5 - 1;
      bVar4 = 0;
      uVar6 = 0xffffffff;
      uVar7 = 0;
      iVar1 = (iVar5 % 3) * 0x1f;
LAB_0002efb6:
      do {
        if (fpga_version < 0xe) {
          if (bVar4 == 0) {
            bVar3 = chain_pic_buf[iVar9 * 3][uVar7 + iVar1 + 0xb];
          }
          else {
            bVar3 = chain_pic_buf[iVar9 * 3][uVar7 + iVar1 + 0xb];
            if (bVar3 <= bVar4) {
              uVar7 = uVar7 + 1;
              if (uVar2 == uVar7) break;
              goto LAB_0002efb6;
            }
          }
LAB_0002efae:
          uVar6 = uVar7;
          bVar4 = bVar3;
        }
        else {
          if (uVar11 < 0xd) {
            iVar10 = *(int *)(CSWTCH_824 + uVar11 * 4);
            iVar8 = *(int *)(CSWTCH_825 + uVar11 * 4) * 0x1f;
          }
          else {
            iVar10 = 0;
            iVar8 = 0xb;
          }
          if (uVar11 < 0xd) {
            iVar8 = iVar8 + 0xb;
          }
          iVar8 = iVar8 + uVar7 + iVar10 * 0x80;
          if (bVar4 == 0) {
            bVar3 = *(byte *)((int)&h + iVar8 + 0xd4);
            goto LAB_0002efae;
          }
          bVar3 = *(byte *)((int)&h + iVar8 + 0xd4);
          if (bVar4 < bVar3) goto LAB_0002efae;
        }
        uVar7 = uVar7 + 1;
      } while (uVar2 != uVar7);
      if (uVar6 != 0xffffffff) {
        if (bVar4 < 5) {
          sprintf(logstr,
                  "Fatal Error: DownOneChipFreqOneStep Chain[%d] has no chip can down freq!!!\n",
                  iVar5);
          writeInitLogFile(logstr);
          return false;
        }
        if (fpga_version < 0xe) {
          iVar1 = uVar6 + iVar1 + iVar9 * 0x180 + 0x6e6b4b;
          *(char *)(iVar1 + 0xd4) = *(char *)(iVar1 + 0xd4) + -1;
          return true;
        }
        uVar2 = iVar5 - 1;
        if (uVar2 < 0xd) {
          iVar5 = *(int *)(CSWTCH_824 + uVar2 * 4);
          iVar1 = *(int *)(CSWTCH_825 + uVar2 * 4) * 0x1f;
        }
        else {
          iVar5 = 0;
          iVar1 = 0xb;
        }
        if (uVar2 < 0xd) {
          iVar1 = iVar1 + 0xb;
        }
        iVar1 = uVar6 + iVar1 + iVar5 * 0x80;
        *(char *)((int)&h + iVar1 + 0xd4) = *(char *)((int)&h + iVar1 + 0xd4) + -1;
        return true;
      }
    }
    sprintf(logstr,"Fatal Error: DownOneChipFreqOneStep Chain[%d] has Wrong chip index=%d\n",
            0xffffffff);
    writeInitLogFile(logstr);
  }
  return false;
}

