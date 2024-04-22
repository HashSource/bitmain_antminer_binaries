
/* WARNING: Type propagation algorithm not settling */

uint Curl_ftp_parselist(byte *param_1,int param_2,int param_3,int *param_4)

{
  char cVar1;
  ushort uVar2;
  code **ppcVar3;
  byte *pbVar4;
  undefined4 uVar5;
  ushort **ppuVar6;
  char *pcVar7;
  int *piVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  char *pcVar18;
  byte *pbVar19;
  bool bVar20;
  bool bVar21;
  longlong lVar22;
  char *local_2c [2];
  
  uVar16 = param_2 * param_3;
  piVar14 = **(int ***)(*param_4 + 0x86e8);
  if (piVar14[3] == 0) {
    if (*piVar14 == 0) {
      if (uVar16 != 0) {
        if (*param_1 - 0x30 < 10) {
          iVar13 = 2;
        }
        else {
          iVar13 = 1;
        }
        *piVar14 = iVar13;
        goto LAB_0005ea78;
      }
    }
    else if (uVar16 != 0) {
LAB_0005ea78:
      ppcVar3 = DAT_0005ef68;
      iVar13 = piVar14[4];
      uVar15 = 0;
      uVar17 = (uint)*param_1;
      if (iVar13 == 0) goto LAB_0005ec18;
LAB_0005ea8a:
      iVar10 = *(int *)(iVar13 + 0x3c);
      do {
        iVar11 = *(int *)(iVar13 + 0x44);
        *(char *)(iVar10 + iVar11) = (char)uVar17;
        uVar12 = iVar11 + 1;
        *(uint *)(iVar13 + 0x44) = uVar12;
        if (*(int *)(iVar13 + 0x40) - 1U <= uVar12) {
          iVar10 = (**ppcVar3)(*(undefined4 *)(iVar13 + 0x3c),*(int *)(iVar13 + 0x40) + 0xa0);
          if (iVar10 == 0) {
            Curl_fileinfo_dtor(0,piVar14[4]);
            piVar14[3] = 0x1b;
            piVar14[4] = 0;
            PL_ERROR(param_4);
            return uVar16;
          }
          *(int *)(iVar13 + 0x3c) = iVar10;
          *(int *)(iVar13 + 0x40) = *(int *)(iVar13 + 0x40) + 0xa0;
        }
        if (*piVar14 != 1) {
          if (*piVar14 != 2) {
            return uVar16 + 1;
          }
          switch(piVar14[1]) {
          case 0:
            uVar12 = piVar14[5] + 1;
            piVar14[5] = uVar12;
            if (uVar12 < 9) {
              pcVar7 = strchr(DAT_0005ef5c,uVar17);
              goto joined_r0x0005eda0;
            }
            if ((uVar12 != 9) || (uVar17 != 0x20)) goto switchD_0005ef78_caseD_2e;
            piVar14[1] = 1;
            piVar14[2] = 0;
            break;
          case 1:
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            if (piVar14[2] != 0) {
              if (piVar14[2] == 1) {
                if (uVar17 != 0x20) {
                  pcVar7 = strchr(DAT_0005ef60,uVar17);
                  goto joined_r0x0005eda0;
                }
                iVar13 = *(int *)(iVar13 + 0x3c);
                piVar14[10] = piVar14[6];
                *(undefined *)(iVar13 + iVar10 + 1 + piVar14[6] + -1) = 0;
                piVar14[2] = 0;
                piVar14[5] = 0;
                piVar14[1] = 2;
              }
              break;
            }
            ppuVar6 = __ctype_b_loc();
            if ((int)((uint)(*ppuVar6)[uVar17] << 0x12) < 0) break;
            goto LAB_0005ed34;
          case 2:
            if (piVar14[2] == 0) goto switchD_0005ee9e_caseD_0;
            if (piVar14[2] == 1) {
              iVar10 = piVar14[5];
              piVar14[5] = iVar10 + 1;
              pcVar7 = DAT_0005ef58;
              if (uVar17 == 0x20) {
                *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -1) = 0;
                pcVar18 = (char *)(*(int *)(iVar13 + 0x3c) + piVar14[6]);
                iVar10 = strcmp(pcVar7,pcVar18);
                if (iVar10 == 0) {
                  iVar10 = piVar14[4];
                  *(undefined4 *)(iVar13 + 4) = 1;
                  *(undefined4 *)(iVar13 + 0x18) = 0;
                  *(undefined4 *)(iVar13 + 0x1c) = 0;
                }
                else {
                  lVar22 = strtoll(pcVar18,local_2c,10);
                  *(longlong *)(iVar13 + 0x18) = lVar22;
                  if ((*local_2c[0] != '\0') ||
                     ((((int)((ulonglong)lVar22 >> 0x20) + -0x80000000) - (uint)((int)lVar22 == 0)
                       == -1 && 0xfffffffd < (int)lVar22 - 1U &&
                      (piVar8 = __errno_location(), *piVar8 == 0x22))))
                  goto switchD_0005ef78_caseD_2e;
                  iVar10 = piVar14[4];
                  *(undefined4 *)(iVar10 + 4) = 0;
                }
                *(uint *)(iVar10 + 0x38) = *(uint *)(iVar10 + 0x38) | 0x40;
                piVar14[5] = 0;
                piVar14[2] = 0;
                piVar14[1] = 3;
              }
            }
            break;
          case 3:
            iVar10 = piVar14[2];
            if (iVar10 == 1) {
              piVar14[5] = piVar14[5] + 1;
              if (uVar17 == 0xd) {
                piVar14[2] = 2;
                *(undefined *)(*(int *)(iVar13 + 0x3c) + *(int *)(iVar13 + 0x44) + -1) = 0;
              }
              else if (uVar17 == 10) {
                *(undefined *)(*(int *)(iVar13 + 0x44) + *(int *)(iVar13 + 0x3c) + -1) = 0;
                piVar14[7] = piVar14[6];
                iVar13 = ftp_pl_insert_finfo(param_4,iVar13);
                goto joined_r0x0005f2e0;
              }
            }
            else {
              if (iVar10 == 0) goto switchD_0005ee9e_caseD_0;
              if (iVar10 == 2) {
                if (uVar17 != 10) goto switchD_0005ef78_caseD_2e;
                piVar14[7] = piVar14[6];
                iVar13 = ftp_pl_insert_finfo(param_4,iVar13);
joined_r0x0005f2e0:
                if (iVar13 != 0) goto LAB_0005ef28;
                piVar14[1] = 0;
                piVar14[2] = 0;
              }
            }
          }
          goto switchD_0005ead2_caseD_4;
        }
        switch(piVar14[1]) {
        case 0:
          if (piVar14[2] == 0) {
            bVar20 = uVar17 == 0x74;
            if (bVar20) {
              iVar10 = piVar14[5];
            }
            else {
              iVar10 = 0;
            }
            if (bVar20) {
              piVar14[2] = 1;
            }
            if (bVar20) {
              iVar10 = iVar10 + 1;
            }
            else {
              piVar14[1] = 1;
              uVar15 = uVar15 - 1;
            }
            if (!bVar20) {
              *(int *)(iVar13 + 0x44) = iVar10;
            }
            if (bVar20) {
              piVar14[5] = iVar10;
            }
          }
          else if (piVar14[2] == 1) {
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            pcVar7 = DAT_0005f540;
            if (uVar17 == 0xd) {
              iVar11 = *(int *)(iVar13 + 0x44);
              piVar14[5] = iVar10;
              *(int *)(iVar13 + 0x44) = iVar11 + -1;
            }
            else if (uVar17 == 10) {
              *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10) = 0;
              pcVar18 = *(char **)(iVar13 + 0x3c);
              iVar10 = strncmp(pcVar7,pcVar18,6);
              if (iVar10 != 0) goto switchD_0005ef78_caseD_2e;
              ppuVar6 = __ctype_b_loc();
              pbVar4 = (byte *)(pcVar18 + 6);
              do {
                pbVar19 = pbVar4;
                uVar17 = (uint)*pbVar19;
                uVar2 = (*ppuVar6)[uVar17];
                pbVar4 = pbVar19 + 1;
              } while ((uVar2 & 0x2000) != 0);
              while ((int)((uint)uVar2 << 0x14) < 0) {
                pbVar19 = pbVar19 + 1;
                uVar17 = (uint)*pbVar19;
                uVar2 = (*ppuVar6)[uVar17];
              }
              if (uVar17 != 0) goto switchD_0005ef78_caseD_2e;
              piVar14[1] = 1;
              *(undefined4 *)(iVar13 + 0x44) = 0;
            }
          }
          break;
        case 1:
          switch(uVar17) {
          case 0x2d:
            *(undefined4 *)(iVar13 + 4) = 0;
            break;
          default:
            goto switchD_0005ef78_caseD_2e;
          case 0x44:
            *(undefined4 *)(iVar13 + 4) = 7;
            break;
          case 0x62:
            *(undefined4 *)(iVar13 + 4) = 3;
            break;
          case 99:
            *(undefined4 *)(iVar13 + 4) = 4;
            break;
          case 100:
            *(undefined4 *)(iVar13 + 4) = 1;
            break;
          case 0x6c:
            *(undefined4 *)(iVar13 + 4) = 2;
            break;
          case 0x70:
            *(undefined4 *)(iVar13 + 4) = 5;
            break;
          case 0x73:
            *(undefined4 *)(iVar13 + 4) = 6;
          }
          piVar14[1] = 2;
          piVar14[5] = 0;
          piVar14[6] = 1;
          break;
        case 2:
          uVar12 = piVar14[5] + 1;
          piVar14[5] = uVar12;
          if (uVar12 < 10) {
            pcVar7 = strchr(DAT_0005ef64,uVar17);
joined_r0x0005eda0:
            if (pcVar7 == (char *)0x0) goto switchD_0005ef78_caseD_2e;
          }
          else if (uVar12 == 10) {
            if (uVar17 != 0x20) goto switchD_0005ef78_caseD_2e;
            *(undefined *)(*(int *)(iVar13 + 0x3c) + 10) = 0;
            iVar10 = piVar14[6];
            cVar1 = *(char *)(*(int *)(iVar13 + 0x3c) + iVar10);
            iVar13 = *(int *)(iVar13 + 0x3c) + iVar10;
            if (cVar1 == 'r') {
              uVar17 = 0x100;
            }
            else if (cVar1 == '-') {
              uVar17 = 0;
            }
            else {
              uVar17 = 0x1000000;
            }
            if (*(char *)(iVar13 + 1) == 'w') {
              uVar17 = uVar17 | 0x80;
            }
            else if (*(char *)(iVar13 + 1) != '-') {
              uVar17 = uVar17 | 0x1000000;
            }
            cVar1 = *(char *)(iVar13 + 2);
            if (cVar1 == 'x') {
              uVar17 = uVar17 | 0x40;
            }
            else if (cVar1 == 's') {
              uVar17 = uVar17 | 0x840;
            }
            else if (cVar1 == 'S') {
              uVar17 = uVar17 | 0x800;
            }
            else if (cVar1 != '-') {
              uVar17 = uVar17 | 0x1000000;
            }
            if (*(char *)(iVar13 + 3) == 'r') {
              uVar17 = uVar17 | 0x20;
            }
            else if (*(char *)(iVar13 + 3) != '-') {
              uVar17 = uVar17 | 0x1000000;
            }
            if (*(char *)(iVar13 + 4) == 'w') {
              uVar17 = uVar17 | 0x10;
            }
            else if (*(char *)(iVar13 + 4) != '-') {
              uVar17 = uVar17 | 0x1000000;
            }
            cVar1 = *(char *)(iVar13 + 5);
            if (cVar1 == 'x') {
              uVar17 = uVar17 | 8;
            }
            else if (cVar1 == 's') {
              uVar17 = uVar17 | 0x408;
            }
            else if (cVar1 == 'S') {
              uVar17 = uVar17 | 0x400;
            }
            else if (cVar1 != '-') {
              uVar17 = uVar17 | 0x1000000;
            }
            if (*(char *)(iVar13 + 6) == 'r') {
              uVar17 = uVar17 | 4;
            }
            else if (*(char *)(iVar13 + 6) != '-') {
              uVar17 = uVar17 | 0x1000000;
            }
            if (*(char *)(iVar13 + 7) == 'w') {
              uVar17 = uVar17 | 2;
            }
            else if (*(char *)(iVar13 + 7) != '-') {
              uVar17 = uVar17 | 0x1000000;
            }
            cVar1 = *(char *)(iVar13 + 8);
            if (cVar1 == 'x') {
LAB_0005f434:
              uVar17 = uVar17 | 1;
            }
            else {
              if (cVar1 == 't') {
                uVar17 = uVar17 | 0x200;
                goto LAB_0005f434;
              }
              if (cVar1 == 'T') {
                uVar17 = uVar17 | 0x200;
              }
              else if (cVar1 != '-') {
                uVar17 = uVar17 | 0x1000000;
              }
            }
            if ((uVar17 & 0x1000000) != 0) goto switchD_0005ef78_caseD_2e;
            iVar13 = piVar14[4];
            *(uint *)(iVar13 + 0xc) = uVar17;
            *(uint *)(iVar13 + 0x38) = *(uint *)(iVar13 + 0x38) | 8;
            piVar14[0xb] = iVar10;
            piVar14[5] = 0;
            piVar14[2] = 0;
            piVar14[1] = 3;
          }
          break;
        case 3:
          if (piVar14[2] != 0) {
            if (piVar14[2] == 1) {
              iVar10 = piVar14[5];
              piVar14[5] = iVar10 + 1;
              if (uVar17 == 0x20) {
                uVar17 = 10;
                *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -1) = 0;
                lVar9 = strtol((char *)(*(int *)(iVar13 + 0x3c) + piVar14[6]),local_2c,10);
                if (*local_2c[0] == '\0') {
                  bVar21 = lVar9 + 0x7fffffffU < 0xfffffffd;
                  iVar13 = lVar9 + -0x7ffffffe;
                  bVar20 = iVar13 == 0;
                  if (bVar21 || bVar20) {
                    iVar13 = piVar14[4];
                    uVar17 = *(uint *)(iVar13 + 0x38);
                  }
                  if (bVar21 || bVar20) {
                    *(long *)(iVar13 + 0x20) = lVar9;
                    uVar17 = uVar17 | 0x80;
                  }
                  if (bVar21 || bVar20) {
                    *(uint *)(iVar13 + 0x38) = uVar17;
                  }
                }
                piVar14[5] = 0;
                piVar14[6] = 0;
                piVar14[2] = 0;
                piVar14[1] = 4;
              }
              else if (9 < uVar17 - 0x30) goto switchD_0005ef78_caseD_2e;
            }
            break;
          }
LAB_0005f296:
          if (uVar17 == 0x20) break;
          if (9 < uVar17 - 0x30) goto switchD_0005ef78_caseD_2e;
LAB_0005ed5c:
          iVar13 = *(int *)(iVar13 + 0x44);
          uVar15 = uVar15 + 1;
          piVar14[5] = 1;
          piVar14[2] = 1;
          piVar14[6] = iVar13 + -1;
          if (uVar16 < uVar15 || uVar16 - uVar15 == 0) {
            return uVar16;
          }
          goto LAB_0005ec0c;
        case 4:
          if (piVar14[2] == 0) {
switchD_0005ee9e_caseD_0:
            if (uVar17 != 0x20) goto LAB_0005ed5c;
          }
          else if (piVar14[2] == 1) {
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            if (uVar17 == 0x20) {
              *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -1) = 0;
              iVar13 = piVar14[6];
              piVar14[2] = 0;
              piVar14[5] = 0;
              piVar14[6] = 0;
              piVar14[8] = iVar13;
              piVar14[1] = 5;
            }
          }
          break;
        case 5:
          if (piVar14[2] == 0) goto switchD_0005ee9e_caseD_0;
          if (piVar14[2] == 1) {
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            if (uVar17 == 0x20) {
              *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -1) = 0;
              iVar13 = piVar14[6];
              piVar14[2] = 0;
              piVar14[5] = 0;
              piVar14[6] = 0;
              piVar14[9] = iVar13;
              piVar14[1] = 6;
            }
          }
          break;
        case 6:
          if (piVar14[2] == 0) goto LAB_0005f296;
          if (piVar14[2] == 1) {
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            if (uVar17 == 0x20) {
              *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -1) = 0;
              lVar22 = strtoll((char *)(*(int *)(iVar13 + 0x3c) + piVar14[6]),local_2c,10);
              if ((*local_2c[0] == '\0') &&
                 (((int)((ulonglong)lVar22 >> 0x20) + -0x80000000) - (uint)((int)lVar22 == 0) != -1
                  || (int)lVar22 - 1U < 0xfffffffe)) {
                iVar13 = piVar14[4];
                *(longlong *)(iVar13 + 0x18) = lVar22;
                *(uint *)(iVar13 + 0x38) = *(uint *)(iVar13 + 0x38) | 0x40;
              }
              piVar14[5] = 0;
              piVar14[6] = 0;
              piVar14[2] = 0;
              piVar14[1] = 7;
            }
            else {
              ppuVar6 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar6)[uVar17] << 0x14)) goto switchD_0005ef78_caseD_2e;
            }
          }
          break;
        case 7:
          switch(piVar14[2]) {
          case 0:
            if (uVar17 != 0x20) {
              ppuVar6 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar6)[uVar17] << 0x1c)) goto switchD_0005ef78_caseD_2e;
              goto LAB_0005ed5c;
            }
            break;
          case 1:
            piVar14[5] = piVar14[5] + 1;
            if (uVar17 == 0x20) {
LAB_0005f100:
              piVar14[2] = 2;
            }
            else {
LAB_0005f0a8:
              ppuVar6 = __ctype_b_loc();
              if ((-1 < (int)((uint)(*ppuVar6)[uVar17] << 0x1c)) && (uVar17 != 0x2e))
              goto switchD_0005ef78_caseD_2e;
            }
            break;
          case 2:
            piVar14[5] = piVar14[5] + 1;
            if (uVar17 != 0x20) {
              ppuVar6 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar6)[uVar17] << 0x1c)) goto switchD_0005ef78_caseD_2e;
LAB_0005f14c:
              piVar14[2] = 3;
            }
            break;
          case 3:
            piVar14[5] = piVar14[5] + 1;
            if (uVar17 != 0x20) goto LAB_0005f0a8;
LAB_0005f240:
            piVar14[2] = 4;
            break;
          case 4:
            piVar14[5] = piVar14[5] + 1;
            if (uVar17 != 0x20) {
              ppuVar6 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar6)[uVar17] << 0x1c)) goto switchD_0005ef78_caseD_2e;
              piVar14[2] = 5;
            }
            break;
          case 5:
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            if (uVar17 == 0x20) {
              *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -1) = 0;
              iVar13 = *(int *)(iVar13 + 4);
              piVar14[2] = 0;
              piVar14[10] = piVar14[6];
              if (iVar13 == 2) {
                iVar13 = 9;
              }
              else {
                iVar13 = 8;
              }
              piVar14[1] = iVar13;
            }
            else {
              ppuVar6 = __ctype_b_loc();
              if ((-1 < (int)((uint)(*ppuVar6)[uVar17] << 0x1c)) &&
                 (uVar17 != 0x3a && uVar17 != 0x2e)) goto switchD_0005ef78_caseD_2e;
            }
          }
          break;
        case 8:
          iVar10 = piVar14[2];
          if (iVar10 == 1) {
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            if (uVar17 == 0xd) goto LAB_0005f100;
            if (uVar17 == 10) {
              *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -1) = 0;
              piVar14[1] = 1;
              piVar14[7] = piVar14[6];
              iVar13 = ftp_pl_insert_finfo(param_4,iVar13);
              goto joined_r0x0005f396;
            }
          }
          else {
            if (iVar10 == 0) goto switchD_0005ee9e_caseD_0;
            if (iVar10 == 2) {
              if (uVar17 != 10) goto switchD_0005ef78_caseD_2e;
              *(undefined *)(*(int *)(iVar13 + 0x3c) + piVar14[6] + piVar14[5] + -1) = 0;
              piVar14[1] = 1;
              piVar14[7] = piVar14[6];
              iVar13 = ftp_pl_insert_finfo(param_4,iVar13);
joined_r0x0005f396:
              if (iVar13 != 0) goto LAB_0005ef28;
            }
          }
          break;
        case 9:
          switch(piVar14[2]) {
          case 0:
            goto switchD_0005ee9e_caseD_0;
          case 1:
            piVar14[5] = piVar14[5] + 1;
            if (uVar17 == 0x20) goto LAB_0005f100;
            if (uVar17 == 0xd || uVar17 == 10) goto switchD_0005ef78_caseD_2e;
            break;
          case 2:
            piVar14[5] = piVar14[5] + 1;
            if (uVar17 == 0x2d) goto LAB_0005f14c;
            goto LAB_0005f222;
          case 3:
            piVar14[5] = piVar14[5] + 1;
            if (uVar17 == 0x3e) goto LAB_0005f240;
LAB_0005f222:
            if (uVar17 == 0xd || uVar17 == 10) {
switchD_0005ef78_caseD_2e:
              PL_ERROR(param_4,0x57);
              return uVar16;
            }
LAB_0005ed34:
            piVar14[2] = 1;
            break;
          case 4:
            iVar10 = piVar14[5];
            piVar14[5] = iVar10 + 1;
            if (uVar17 != 0x20) goto LAB_0005f222;
            piVar14[2] = 5;
            *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + 1 + piVar14[6] + -4) = 0;
            iVar13 = piVar14[6];
            piVar14[5] = 0;
            piVar14[6] = 0;
            piVar14[7] = iVar13;
            break;
          case 5:
            if (uVar17 == 10 || uVar17 == 0xd) goto switchD_0005ef78_caseD_2e;
            piVar14[2] = 6;
            iVar13 = *(int *)(iVar13 + 0x44);
            piVar14[5] = 1;
            piVar14[6] = iVar13 + -1;
            break;
          case 6:
            iVar10 = piVar14[5] + 1;
            piVar14[5] = iVar10;
            if (uVar17 == 0xd) {
              iVar10 = 7;
            }
            if (uVar17 == 0xd) {
              piVar14[2] = iVar10;
            }
            else if (uVar17 == 10) {
              *(undefined *)(*(int *)(iVar13 + 0x3c) + iVar10 + piVar14[6] + -1) = 0;
              goto LAB_0005f1de;
            }
            break;
          case 7:
            if (uVar17 != 10) goto switchD_0005ef78_caseD_2e;
            *(undefined *)(*(int *)(iVar13 + 0x3c) + piVar14[6] + piVar14[5] + -1) = 0;
LAB_0005f1de:
            piVar14[0xc] = piVar14[6];
            iVar13 = ftp_pl_insert_finfo(param_4,iVar13);
            if (iVar13 != 0) {
LAB_0005ef28:
              PL_ERROR(param_4,iVar13);
              return uVar16;
            }
            piVar14[1] = 1;
          }
        }
switchD_0005ead2_caseD_4:
        uVar15 = uVar15 + 1;
        if (uVar16 < uVar15 || uVar16 - uVar15 == 0) {
          return uVar16;
        }
LAB_0005ec0c:
        iVar13 = piVar14[4];
        uVar17 = (uint)param_1[uVar15];
        if (iVar13 != 0) goto LAB_0005ea8a;
LAB_0005ec18:
        iVar10 = Curl_fileinfo_alloc();
        piVar14[4] = iVar10;
        if (iVar10 == 0) {
          piVar14[3] = 0x1b;
          return uVar16;
        }
        uVar5 = (*Curl_cmalloc)(0xa0);
        iVar13 = piVar14[4];
        *(undefined4 *)(iVar10 + 0x3c) = uVar5;
        iVar10 = *(int *)(iVar13 + 0x3c);
        if (iVar10 == 0) {
          PL_ERROR(param_4,0x1b);
          return uVar16;
        }
        *(undefined4 *)(iVar13 + 0x40) = 0xa0;
        piVar14[6] = 0;
        piVar14[5] = 0;
      } while( true );
    }
  }
  return uVar16;
}

