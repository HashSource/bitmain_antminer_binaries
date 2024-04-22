
/* WARNING: Unknown calling convention */

_Bool DownOneChipFreqOneStep(void)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int new_T9_PLUS_chainIndex_1;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int new_T9_PLUS_chainIndex;
  int iVar12;
  int iVar13;
  uint uVar14;
  char logstr [256];
  
  piVar1 = DAT_0002f084;
  iVar10 = 0;
  iVar7 = 0;
  iVar5 = -1;
LAB_0002eeec:
  do {
    iVar12 = iVar7;
    iVar7 = *piVar1;
    if (*(int *)(iVar7 + (iVar12 + 2) * 4) == 1) {
      if (*(char *)(iVar7 + iVar12 + 0x2faa) != '\x12') {
        return false;
      }
      if ((iVar10 == 0) || (iVar7 = GetBoardRate(iVar12), iVar10 < iVar7)) {
        iVar10 = GetBoardRate(iVar12);
        iVar7 = iVar12 + 1;
        iVar5 = iVar12;
        if (iVar12 + 1 == 0x10) break;
        goto LAB_0002eeec;
      }
    }
    iVar7 = iVar12 + 1;
  } while (iVar12 + 1 != 0x10);
  if (iVar5 == -1) {
    sprintf(logstr,DAT_0002f09c,0xffffffff);
    writeInitLogFile(logstr);
  }
  else {
    uVar2 = (uint)*(byte *)(*piVar1 + iVar5 + 0x2faa);
    if (uVar2 != 0) {
      uVar14 = iVar5 - 1;
      bVar4 = 0;
      iVar12 = DAT_0002f088 + uVar14 * 4;
      uVar6 = 0xffffffff;
      uVar8 = 0;
      iVar13 = (iVar5 / 3) * 0x180;
      iVar7 = (iVar5 % 3) * 0x1f;
      iVar10 = iVar13 + iVar7 + DAT_0002f090;
      do {
        while (0xd < *DAT_0002f08c) {
          if (uVar14 < 0xd) {
            iVar11 = *(int *)(iVar12 + 0x9b8);
            iVar9 = *(int *)(iVar12 + 0x9ec) * 0x1f;
          }
          else {
            iVar11 = 0;
            iVar9 = 0xb;
          }
          if (uVar14 < 0xd) {
            iVar9 = iVar9 + 0xb;
          }
          iVar9 = DAT_0002f090 + -0xd4 + iVar11 * 0x80 + uVar8 + iVar9;
          if (bVar4 == 0) {
            bVar3 = *(byte *)(iVar9 + 0xd4);
            goto LAB_0002efae;
          }
          bVar3 = *(byte *)(iVar9 + 0xd4);
          if (bVar4 < bVar3) goto LAB_0002efae;
LAB_0002efb0:
          uVar8 = uVar8 + 1;
          if (uVar2 == uVar8) goto LAB_0002efe0;
        }
        if (bVar4 == 0) {
          bVar3 = *(byte *)(iVar10 + uVar8 + 0xb);
LAB_0002efae:
          uVar6 = uVar8;
          bVar4 = bVar3;
          goto LAB_0002efb0;
        }
        bVar3 = *(byte *)(iVar10 + uVar8 + 0xb);
        if (bVar4 < bVar3) goto LAB_0002efae;
        uVar8 = uVar8 + 1;
      } while (uVar2 != uVar8);
LAB_0002efe0:
      if (uVar6 != 0xffffffff) {
        if (bVar4 < 5) {
          sprintf(logstr,DAT_0002f098,iVar5);
          writeInitLogFile(logstr);
          return false;
        }
        if (*DAT_0002f08c < 0xe) {
          iVar7 = uVar6 + iVar7 + 0xb + iVar13 + DAT_0002f094;
          *(char *)(iVar7 + 0xd4) = *(char *)(iVar7 + 0xd4) + -1;
          return true;
        }
        uVar2 = iVar5 - 1;
        if (uVar2 < 0xd) {
          iVar7 = DAT_0002f088 + uVar2 * 4;
          iVar5 = *(int *)(iVar7 + 0x9b8);
          iVar7 = *(int *)(iVar7 + 0x9ec) * 0x1f;
        }
        else {
          iVar5 = 0;
          iVar7 = 0xb;
        }
        if (uVar2 < 0xd) {
          iVar7 = iVar7 + 0xb;
        }
        iVar7 = DAT_0002f094 + iVar5 * 0x80 + uVar6 + iVar7;
        *(char *)(iVar7 + 0xd4) = *(char *)(iVar7 + 0xd4) + -1;
        return true;
      }
    }
    sprintf(logstr,DAT_0002f0a0,0xffffffff);
    writeInitLogFile(logstr);
  }
  return false;
}

