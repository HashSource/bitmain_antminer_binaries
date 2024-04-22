
/* WARNING: Unknown calling convention */

char * opt_usage(char *argv0,char *extra)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  char cVar4;
  size_t sVar5;
  size_t sVar6;
  size_t sVar7;
  char *pcVar8;
  char *ret;
  int iVar9;
  char *pcVar10;
  char *p_1;
  int iVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  undefined4 *puVar15;
  char **ppcVar16;
  char **ppcVar17;
  char *pcVar18;
  char *pcVar19;
  uint uVar20;
  uint len;
  uint *puVar21;
  uint num;
  uint uVar22;
  char *local_88;
  uint i;
  char buf [84];
  
  puVar21 = DAT_0003b534;
  if (extra == (char *)0x0) {
    uVar22 = *DAT_0003b534;
    if (uVar22 == 0) {
      sVar6 = strlen(argv0);
      local_88 = DAT_0003b530;
      sVar6 = *DAT_0003b500 + 0x14 + sVar6;
      goto LAB_0003b2f2;
    }
    ppcVar17 = (char **)*DAT_0003b504;
    uVar20 = 0;
    ppcVar16 = ppcVar17;
    do {
      uVar20 = uVar20 + 1;
      if ((ppcVar16[2] == DAT_0003b52c) && (local_88 = ppcVar16[5], local_88 != (char *)0x0)) {
        sVar6 = strlen(local_88);
        goto LAB_0003b4dc;
      }
      ppcVar16 = ppcVar16 + 7;
    } while (uVar20 != uVar22);
    sVar6 = 0;
    local_88 = DAT_0003b530;
LAB_0003b4dc:
    sVar5 = strlen(argv0);
    sVar6 = *DAT_0003b500 + 0x14 + sVar5 + sVar6;
  }
  else {
    sVar5 = strlen(argv0);
    sVar6 = strlen(extra);
    uVar22 = *DAT_0003b534;
    sVar6 = *DAT_0003b500 + 0x14 + sVar5 + sVar6;
    puVar21 = DAT_0003b534;
    local_88 = extra;
    if (uVar22 == 0) goto LAB_0003b2f2;
    ppcVar17 = (char **)*DAT_0003b504;
  }
  pcVar8 = DAT_0003b538;
  uVar20 = 0;
  do {
    while (ppcVar17[1] != (char *)0x8) {
      pcVar19 = ppcVar17[6];
      if (pcVar19 != pcVar8) {
        sVar5 = strlen(*ppcVar17);
        sVar7 = strlen(pcVar19);
        iVar9 = sVar7 + sVar6 + 6 + sVar5;
        iVar13 = iVar9 + 0x15;
        if (ppcVar17[4] != (char *)0x0) {
          iVar13 = iVar9 + 0x76;
        }
        sVar6 = iVar13 + 1;
      }
      uVar20 = uVar20 + 1;
      ppcVar17 = ppcVar17 + 7;
      if (uVar22 <= uVar20) goto LAB_0003b2f2;
    }
    uVar20 = uVar20 + 1;
    sVar5 = strlen(ppcVar17[6]);
    sVar6 = sVar6 + 3 + sVar5;
    ppcVar17 = ppcVar17 + 7;
  } while (uVar20 < uVar22);
LAB_0003b2f2:
  pcVar8 = (char *)malloc(sVar6);
  if (pcVar8 != (char *)0x0) {
    iVar9 = sprintf(pcVar8,DAT_0003b508,argv0);
    pcVar18 = pcVar8 + iVar9;
    *(undefined4 *)(pcVar8 + iVar9) = *DAT_0003b50c;
    pcVar10 = first_sopt(&i);
    pcVar19 = DAT_0003b538;
    piVar1 = DAT_0003b504;
    pcVar14 = pcVar18;
    if (pcVar10 != (char *)0x0) {
      iVar9 = 0;
      do {
        if (*(char **)(*piVar1 + i * 0x1c + 0x18) != pcVar19) {
          pcVar18[iVar9 + 3] = *pcVar10;
          iVar9 = iVar9 + 1;
        }
        pcVar10 = next_sopt(pcVar10,&i);
      } while (pcVar10 != (char *)0x0);
      if (iVar9 != 0) {
        pcVar14 = pcVar18 + iVar9 + 4;
        *(undefined2 *)(pcVar18 + iVar9 + 3) = *DAT_0003b528;
      }
    }
    puVar2 = DAT_0003b53c;
    iVar9 = sprintf(pcVar14,DAT_0003b510,local_88);
    pcVar10 = pcVar14 + iVar9 + 1;
    *(undefined2 *)(pcVar14 + iVar9) = *puVar2;
    pcVar19 = DAT_0003b538;
    piVar1 = DAT_0003b504;
    if (*puVar21 != 0) {
      iVar9 = 0;
      uVar22 = 0;
      do {
        while (puVar15 = (undefined4 *)(*piVar1 + iVar9), (char *)puVar15[6] == pcVar19) {
LAB_0003b40e:
          uVar22 = uVar22 + 1;
          iVar9 = iVar9 + 0x1c;
          if (*puVar21 <= uVar22) goto LAB_0003b440;
        }
        if (puVar15[1] != 8) {
          iVar11 = sprintf(pcVar10,DAT_0003b514,*puVar15);
          iVar13 = iVar11;
          if (*(int *)((int)&opt_table->type + iVar9) == 2) {
            pcVar18 = *(char **)((int)&opt_table->names + iVar9);
            pcVar14 = strchr(pcVar18,0x20);
            if ((pcVar14 == (char *)0x0) &&
               (pcVar14 = strchr(pcVar18,0x3d), cVar4 = DAT_00053a52, uVar3 = DAT_00053a50,
               pcVar14 == (char *)0x0)) {
              *(undefined4 *)(pcVar10 + iVar11) = DAT_00053a4c;
              iVar13 = iVar11 + 6;
              *(undefined2 *)(pcVar10 + iVar11 + 4) = uVar3;
              pcVar10[iVar11 + 6] = cVar4;
            }
          }
          iVar11 = sprintf(pcVar10 + iVar13,DAT_0003b518);
          iVar12 = sprintf(pcVar10 + iVar13 + iVar11,DAT_0003b514,
                           *(undefined4 *)(*piVar1 + iVar9 + 0x18));
          iVar12 = iVar13 + iVar11 + iVar12;
          iVar13 = *piVar1 + iVar9;
          if (*(int *)(iVar13 + 0x10) != 0) {
            buf[80] = '.';
            buf[81] = '.';
            buf[82] = '.';
            buf[83] = '\0';
            (**(code **)(iVar13 + 0x10))(buf,*(undefined4 *)(iVar13 + 0x14));
            iVar13 = sprintf(pcVar10 + iVar12,DAT_0003b520,buf);
            iVar12 = iVar12 + iVar13;
          }
          *(undefined2 *)(pcVar10 + iVar12) = *puVar2;
          pcVar10 = pcVar10 + iVar12 + 1;
          goto LAB_0003b40e;
        }
        iVar13 = sprintf(pcVar10,DAT_0003b524);
        uVar22 = uVar22 + 1;
        pcVar10 = pcVar10 + iVar13;
        iVar9 = iVar9 + 0x1c;
      } while (uVar22 < *puVar21);
    }
LAB_0003b440:
    *pcVar10 = '\0';
  }
  return pcVar8;
}

