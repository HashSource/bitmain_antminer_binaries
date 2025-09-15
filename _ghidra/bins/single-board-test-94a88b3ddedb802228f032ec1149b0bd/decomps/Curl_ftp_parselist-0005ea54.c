
uint Curl_ftp_parselist(byte *param_1,int param_2,int param_3,int *param_4)

{
  char cVar1;
  ushort uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  ushort **ppuVar5;
  int *piVar6;
  long lVar7;
  int iVar8;
  uint extraout_r2;
  int iVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  byte *pbVar17;
  bool bVar18;
  bool bVar19;
  longlong lVar20;
  char *local_2c [2];
  
  uVar14 = param_2 * param_3;
  piVar12 = (int *)**(undefined4 **)(*param_4 + 0x86e8);
  if (piVar12[3] == 0) {
    if (*piVar12 == 0) {
      if (uVar14 != 0) {
        if (*param_1 - 0x30 < 10) {
          iVar11 = 2;
        }
        else {
          iVar11 = 1;
        }
        *piVar12 = iVar11;
        goto LAB_0005ea78;
      }
    }
    else if (uVar14 != 0) {
LAB_0005ea78:
      iVar11 = piVar12[4];
      uVar13 = 0;
      uVar15 = (uint)*param_1;
      if (iVar11 == 0) goto LAB_0005ec18;
LAB_0005ea8a:
      iVar8 = *(int *)(iVar11 + 0x3c);
      do {
        iVar9 = *(int *)(iVar11 + 0x44);
        *(char *)(iVar8 + iVar9) = (char)uVar15;
        uVar10 = iVar9 + 1;
        *(uint *)(iVar11 + 0x44) = uVar10;
        if (*(int *)(iVar11 + 0x40) - 1U <= uVar10) {
          iVar8 = (*Curl_crealloc)(*(undefined4 *)(iVar11 + 0x3c),*(int *)(iVar11 + 0x40) + 0xa0);
          if (iVar8 == 0) {
            Curl_fileinfo_dtor(0,piVar12[4]);
            piVar12[3] = 0x1b;
            piVar12[4] = 0;
            PL_ERROR(param_4);
            return uVar14;
          }
          *(int *)(iVar11 + 0x3c) = iVar8;
          *(int *)(iVar11 + 0x40) = *(int *)(iVar11 + 0x40) + 0xa0;
        }
        if (*piVar12 != 1) {
          if (*piVar12 != 2) {
            return uVar14 + 1;
          }
          switch(piVar12[1]) {
          case 0:
            uVar10 = piVar12[5] + 1;
            piVar12[5] = uVar10;
            if (uVar10 < 9) {
              pcVar16 = strchr("0123456789-",uVar15);
              goto joined_r0x0005eda0;
            }
            if ((uVar10 != 9) || (uVar15 != 0x20)) goto switchD_0005ef78_caseD_2e;
            piVar12[1] = 1;
            piVar12[2] = 0;
            break;
          case 1:
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (piVar12[2] != 0) {
              if (piVar12[2] == 1) {
                if (uVar15 != 0x20) {
                  pcVar16 = strchr("APM0123456789:",uVar15);
                  goto joined_r0x0005eda0;
                }
                iVar11 = *(int *)(iVar11 + 0x3c);
                piVar12[10] = piVar12[6];
                *(undefined1 *)(iVar11 + iVar8 + 1 + piVar12[6] + -1) = 0;
                piVar12[2] = 0;
                piVar12[5] = 0;
                piVar12[1] = 2;
              }
              break;
            }
            ppuVar5 = __ctype_b_loc();
            if ((int)((uint)(*ppuVar5)[uVar15] << 0x12) < 0) break;
            goto LAB_0005ed34;
          case 2:
            if (piVar12[2] == 0) goto switchD_0005ee9e_caseD_0;
            if (piVar12[2] == 1) {
              iVar8 = piVar12[5];
              piVar12[5] = iVar8 + 1;
              if (uVar15 == 0x20) {
                *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -1) = 0;
                pcVar16 = (char *)(*(int *)(iVar11 + 0x3c) + piVar12[6]);
                iVar8 = strcmp("<DIR>",pcVar16);
                if (iVar8 == 0) {
                  iVar8 = piVar12[4];
                  *(undefined4 *)(iVar11 + 4) = 1;
                  *(undefined4 *)(iVar11 + 0x18) = 0;
                  *(undefined4 *)(iVar11 + 0x1c) = 0;
                }
                else {
                  lVar20 = strtoll(pcVar16,local_2c,10);
                  *(longlong *)(iVar11 + 0x18) = lVar20;
                  if ((*local_2c[0] != '\0') ||
                     ((((int)((ulonglong)lVar20 >> 0x20) + -0x80000000) - (uint)((int)lVar20 == 0)
                       == -1 && 0xfffffffd < (int)lVar20 - 1U &&
                      (piVar6 = __errno_location(), *piVar6 == 0x22))))
                  goto switchD_0005ef78_caseD_2e;
                  iVar8 = piVar12[4];
                  *(undefined4 *)(iVar8 + 4) = 0;
                }
                *(uint *)(iVar8 + 0x38) = *(uint *)(iVar8 + 0x38) | 0x40;
                piVar12[5] = 0;
                piVar12[2] = 0;
                piVar12[1] = 3;
              }
            }
            break;
          case 3:
            iVar8 = piVar12[2];
            if (iVar8 == 1) {
              piVar12[5] = piVar12[5] + 1;
              if (uVar15 == 0xd) {
                piVar12[2] = 2;
                *(undefined1 *)(*(int *)(iVar11 + 0x3c) + *(int *)(iVar11 + 0x44) + -1) = 0;
              }
              else if (uVar15 == 10) {
                *(undefined1 *)(*(int *)(iVar11 + 0x44) + *(int *)(iVar11 + 0x3c) + -1) = 0;
                piVar12[7] = piVar12[6];
                iVar11 = ftp_pl_insert_finfo(param_4,iVar11);
                goto joined_r0x0005f2e0;
              }
            }
            else {
              if (iVar8 == 0) goto switchD_0005ee9e_caseD_0;
              if (iVar8 == 2) {
                if (uVar15 != 10) goto switchD_0005ef78_caseD_2e;
                piVar12[7] = piVar12[6];
                iVar11 = ftp_pl_insert_finfo(param_4,iVar11);
joined_r0x0005f2e0:
                if (iVar11 != 0) goto LAB_0005ef28;
                piVar12[1] = 0;
                piVar12[2] = 0;
              }
            }
          }
          goto switchD_0005ead2_default;
        }
        switch(piVar12[1]) {
        case 0:
          if (piVar12[2] == 0) {
            bVar18 = uVar15 == 0x74;
            if (bVar18) {
              iVar8 = piVar12[5];
            }
            else {
              iVar8 = 0;
            }
            if (bVar18) {
              piVar12[2] = 1;
            }
            if (bVar18) {
              iVar8 = iVar8 + 1;
            }
            else {
              piVar12[1] = 1;
              uVar13 = uVar13 - 1;
            }
            if (!bVar18) {
              *(int *)(iVar11 + 0x44) = iVar8;
            }
            if (bVar18) {
              piVar12[5] = iVar8;
            }
          }
          else if (piVar12[2] == 1) {
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (uVar15 == 0xd) {
              iVar9 = *(int *)(iVar11 + 0x44);
              piVar12[5] = iVar8;
              *(int *)(iVar11 + 0x44) = iVar9 + -1;
            }
            else if (uVar15 == 10) {
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8) = 0;
              pcVar16 = *(char **)(iVar11 + 0x3c);
              iVar8 = strncmp("total ",pcVar16,6);
              if (iVar8 != 0) goto switchD_0005ef78_caseD_2e;
              ppuVar5 = __ctype_b_loc();
              pbVar3 = (byte *)(pcVar16 + 6);
              do {
                pbVar17 = pbVar3;
                uVar15 = (uint)*pbVar17;
                uVar2 = (*ppuVar5)[uVar15];
                pbVar3 = pbVar17 + 1;
              } while ((uVar2 & 0x2000) != 0);
              while ((int)((uint)uVar2 << 0x14) < 0) {
                pbVar17 = pbVar17 + 1;
                uVar15 = (uint)*pbVar17;
                uVar2 = (*ppuVar5)[uVar15];
              }
              if (uVar15 != 0) goto switchD_0005ef78_caseD_2e;
              piVar12[1] = 1;
              *(undefined4 *)(iVar11 + 0x44) = 0;
            }
          }
          break;
        case 1:
          switch(uVar15) {
          case 0x2d:
            *(undefined4 *)(iVar11 + 4) = 0;
            break;
          default:
            goto switchD_0005ef78_caseD_2e;
          case 0x44:
            *(undefined4 *)(iVar11 + 4) = 7;
            break;
          case 0x62:
            *(undefined4 *)(iVar11 + 4) = 3;
            break;
          case 99:
            *(undefined4 *)(iVar11 + 4) = 4;
            break;
          case 100:
            *(undefined4 *)(iVar11 + 4) = 1;
            break;
          case 0x6c:
            *(undefined4 *)(iVar11 + 4) = 2;
            break;
          case 0x70:
            *(undefined4 *)(iVar11 + 4) = 5;
            break;
          case 0x73:
            *(undefined4 *)(iVar11 + 4) = 6;
          }
          piVar12[1] = 2;
          piVar12[5] = 0;
          piVar12[6] = 1;
          break;
        case 2:
          uVar10 = piVar12[5] + 1;
          piVar12[5] = uVar10;
          if (uVar10 < 10) {
            pcVar16 = strchr("rwx-tTsS",uVar15);
joined_r0x0005eda0:
            if (pcVar16 == (char *)0x0) goto switchD_0005ef78_caseD_2e;
          }
          else if (uVar10 == 10) {
            if (uVar15 != 0x20) goto switchD_0005ef78_caseD_2e;
            *(undefined1 *)(*(int *)(iVar11 + 0x3c) + 10) = 0;
            iVar8 = piVar12[6];
            cVar1 = *(char *)(*(int *)(iVar11 + 0x3c) + iVar8);
            iVar11 = *(int *)(iVar11 + 0x3c) + iVar8;
            if (cVar1 == 'r') {
              uVar15 = 0x100;
            }
            else if (cVar1 == '-') {
              uVar15 = 0;
            }
            else {
              uVar15 = 0x1000000;
            }
            if (*(char *)(iVar11 + 1) == 'w') {
              uVar15 = uVar15 | 0x80;
            }
            else if (*(char *)(iVar11 + 1) != '-') {
              uVar15 = uVar15 | 0x1000000;
            }
            cVar1 = *(char *)(iVar11 + 2);
            if (cVar1 == 'x') {
              uVar15 = uVar15 | 0x40;
            }
            else if (cVar1 == 's') {
              uVar15 = uVar15 | 0x840;
            }
            else if (cVar1 == 'S') {
              uVar15 = uVar15 | 0x800;
            }
            else if (cVar1 != '-') {
              uVar15 = uVar15 | 0x1000000;
            }
            if (*(char *)(iVar11 + 3) == 'r') {
              uVar15 = uVar15 | 0x20;
            }
            else if (*(char *)(iVar11 + 3) != '-') {
              uVar15 = uVar15 | 0x1000000;
            }
            if (*(char *)(iVar11 + 4) == 'w') {
              uVar15 = uVar15 | 0x10;
            }
            else if (*(char *)(iVar11 + 4) != '-') {
              uVar15 = uVar15 | 0x1000000;
            }
            cVar1 = *(char *)(iVar11 + 5);
            if (cVar1 == 'x') {
              uVar15 = uVar15 | 8;
            }
            else if (cVar1 == 's') {
              uVar15 = uVar15 | 0x408;
            }
            else if (cVar1 == 'S') {
              uVar15 = uVar15 | 0x400;
            }
            else if (cVar1 != '-') {
              uVar15 = uVar15 | 0x1000000;
            }
            if (*(char *)(iVar11 + 6) == 'r') {
              uVar15 = uVar15 | 4;
            }
            else if (*(char *)(iVar11 + 6) != '-') {
              uVar15 = uVar15 | 0x1000000;
            }
            if (*(char *)(iVar11 + 7) == 'w') {
              uVar15 = uVar15 | 2;
            }
            else if (*(char *)(iVar11 + 7) != '-') {
              uVar15 = uVar15 | 0x1000000;
            }
            cVar1 = *(char *)(iVar11 + 8);
            if (cVar1 == 'x') {
LAB_0005f434:
              uVar15 = uVar15 | 1;
            }
            else {
              if (cVar1 == 't') {
                uVar15 = uVar15 | 0x200;
                goto LAB_0005f434;
              }
              if (cVar1 == 'T') {
                uVar15 = uVar15 | 0x200;
              }
              else if (cVar1 != '-') {
                uVar15 = uVar15 | 0x1000000;
              }
            }
            if ((uVar15 & 0x1000000) != 0) goto switchD_0005ef78_caseD_2e;
            iVar11 = piVar12[4];
            *(uint *)(iVar11 + 0xc) = uVar15;
            *(uint *)(iVar11 + 0x38) = *(uint *)(iVar11 + 0x38) | 8;
            piVar12[0xb] = iVar8;
            piVar12[5] = 0;
            piVar12[2] = 0;
            piVar12[1] = 3;
          }
          break;
        case 3:
          if (piVar12[2] != 0) {
            if (piVar12[2] == 1) {
              iVar8 = piVar12[5];
              piVar12[5] = iVar8 + 1;
              if (uVar15 == 0x20) {
                *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -1) = 0;
                lVar7 = strtol((char *)(*(int *)(iVar11 + 0x3c) + piVar12[6]),local_2c,10);
                if (*local_2c[0] == '\0') {
                  bVar19 = lVar7 + 0x7fffffffU < 0xfffffffd;
                  iVar11 = lVar7 + -0x7ffffffe;
                  bVar18 = iVar11 == 0;
                  uVar15 = extraout_r2;
                  if (bVar19 || bVar18) {
                    iVar11 = piVar12[4];
                    uVar15 = *(uint *)(iVar11 + 0x38);
                  }
                  if (bVar19 || bVar18) {
                    *(long *)(iVar11 + 0x20) = lVar7;
                    uVar15 = uVar15 | 0x80;
                  }
                  if (bVar19 || bVar18) {
                    *(uint *)(iVar11 + 0x38) = uVar15;
                  }
                }
                piVar12[5] = 0;
                piVar12[6] = 0;
                piVar12[2] = 0;
                piVar12[1] = 4;
              }
              else if (9 < uVar15 - 0x30) goto switchD_0005ef78_caseD_2e;
            }
            break;
          }
LAB_0005f296:
          if (uVar15 == 0x20) break;
          if (9 < uVar15 - 0x30) goto switchD_0005ef78_caseD_2e;
LAB_0005ed5c:
          iVar11 = *(int *)(iVar11 + 0x44);
          uVar13 = uVar13 + 1;
          piVar12[5] = 1;
          piVar12[2] = 1;
          piVar12[6] = iVar11 + -1;
          if (uVar14 < uVar13 || uVar14 - uVar13 == 0) {
            return uVar14;
          }
          goto LAB_0005ec0c;
        case 4:
          if (piVar12[2] == 0) {
switchD_0005ee9e_caseD_0:
            if (uVar15 != 0x20) goto LAB_0005ed5c;
          }
          else if (piVar12[2] == 1) {
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (uVar15 == 0x20) {
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -1) = 0;
              iVar11 = piVar12[6];
              piVar12[2] = 0;
              piVar12[5] = 0;
              piVar12[6] = 0;
              piVar12[8] = iVar11;
              piVar12[1] = 5;
            }
          }
          break;
        case 5:
          if (piVar12[2] == 0) goto switchD_0005ee9e_caseD_0;
          if (piVar12[2] == 1) {
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (uVar15 == 0x20) {
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -1) = 0;
              iVar11 = piVar12[6];
              piVar12[2] = 0;
              piVar12[5] = 0;
              piVar12[6] = 0;
              piVar12[9] = iVar11;
              piVar12[1] = 6;
            }
          }
          break;
        case 6:
          if (piVar12[2] == 0) goto LAB_0005f296;
          if (piVar12[2] == 1) {
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (uVar15 == 0x20) {
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -1) = 0;
              lVar20 = strtoll((char *)(*(int *)(iVar11 + 0x3c) + piVar12[6]),local_2c,10);
              if ((*local_2c[0] == '\0') &&
                 (((int)((ulonglong)lVar20 >> 0x20) + -0x80000000) - (uint)((int)lVar20 == 0) != -1
                  || (int)lVar20 - 1U < 0xfffffffe)) {
                iVar11 = piVar12[4];
                *(longlong *)(iVar11 + 0x18) = lVar20;
                *(uint *)(iVar11 + 0x38) = *(uint *)(iVar11 + 0x38) | 0x40;
              }
              piVar12[5] = 0;
              piVar12[6] = 0;
              piVar12[2] = 0;
              piVar12[1] = 7;
            }
            else {
              ppuVar5 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar5)[uVar15] << 0x14)) goto switchD_0005ef78_caseD_2e;
            }
          }
          break;
        case 7:
          switch(piVar12[2]) {
          case 0:
            if (uVar15 != 0x20) {
              ppuVar5 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar5)[uVar15] << 0x1c)) goto switchD_0005ef78_caseD_2e;
              goto LAB_0005ed5c;
            }
            break;
          case 1:
            piVar12[5] = piVar12[5] + 1;
            if (uVar15 == 0x20) {
LAB_0005f100:
              piVar12[2] = 2;
            }
            else {
LAB_0005f0a8:
              ppuVar5 = __ctype_b_loc();
              if ((-1 < (int)((uint)(*ppuVar5)[uVar15] << 0x1c)) && (uVar15 != 0x2e))
              goto switchD_0005ef78_caseD_2e;
            }
            break;
          case 2:
            piVar12[5] = piVar12[5] + 1;
            if (uVar15 != 0x20) {
              ppuVar5 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar5)[uVar15] << 0x1c)) goto switchD_0005ef78_caseD_2e;
LAB_0005f14c:
              piVar12[2] = 3;
            }
            break;
          case 3:
            piVar12[5] = piVar12[5] + 1;
            if (uVar15 != 0x20) goto LAB_0005f0a8;
LAB_0005f240:
            piVar12[2] = 4;
            break;
          case 4:
            piVar12[5] = piVar12[5] + 1;
            if (uVar15 != 0x20) {
              ppuVar5 = __ctype_b_loc();
              if (-1 < (int)((uint)(*ppuVar5)[uVar15] << 0x1c)) goto switchD_0005ef78_caseD_2e;
              piVar12[2] = 5;
            }
            break;
          case 5:
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (uVar15 == 0x20) {
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -1) = 0;
              iVar11 = *(int *)(iVar11 + 4);
              piVar12[2] = 0;
              piVar12[10] = piVar12[6];
              if (iVar11 == 2) {
                iVar11 = 9;
              }
              else {
                iVar11 = 8;
              }
              piVar12[1] = iVar11;
            }
            else {
              ppuVar5 = __ctype_b_loc();
              if ((-1 < (int)((uint)(*ppuVar5)[uVar15] << 0x1c)) &&
                 (uVar15 != 0x3a && uVar15 != 0x2e)) goto switchD_0005ef78_caseD_2e;
            }
          }
          break;
        case 8:
          iVar8 = piVar12[2];
          if (iVar8 == 1) {
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (uVar15 == 0xd) goto LAB_0005f100;
            if (uVar15 == 10) {
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -1) = 0;
              piVar12[1] = 1;
              piVar12[7] = piVar12[6];
              iVar11 = ftp_pl_insert_finfo(param_4,iVar11);
              goto joined_r0x0005f396;
            }
          }
          else {
            if (iVar8 == 0) goto switchD_0005ee9e_caseD_0;
            if (iVar8 == 2) {
              if (uVar15 != 10) goto switchD_0005ef78_caseD_2e;
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + piVar12[6] + piVar12[5] + -1) = 0;
              piVar12[1] = 1;
              piVar12[7] = piVar12[6];
              iVar11 = ftp_pl_insert_finfo(param_4,iVar11);
joined_r0x0005f396:
              if (iVar11 != 0) goto LAB_0005ef28;
            }
          }
          break;
        case 9:
          switch(piVar12[2]) {
          case 0:
            goto switchD_0005ee9e_caseD_0;
          case 1:
            piVar12[5] = piVar12[5] + 1;
            if (uVar15 == 0x20) goto LAB_0005f100;
            if (uVar15 == 0xd || uVar15 == 10) goto switchD_0005ef78_caseD_2e;
            break;
          case 2:
            piVar12[5] = piVar12[5] + 1;
            if (uVar15 == 0x2d) goto LAB_0005f14c;
            goto LAB_0005f222;
          case 3:
            piVar12[5] = piVar12[5] + 1;
            if (uVar15 == 0x3e) goto LAB_0005f240;
LAB_0005f222:
            if (uVar15 == 0xd || uVar15 == 10) {
switchD_0005ef78_caseD_2e:
              PL_ERROR(param_4,0x57);
              return uVar14;
            }
LAB_0005ed34:
            piVar12[2] = 1;
            break;
          case 4:
            iVar8 = piVar12[5];
            piVar12[5] = iVar8 + 1;
            if (uVar15 != 0x20) goto LAB_0005f222;
            piVar12[2] = 5;
            *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + 1 + piVar12[6] + -4) = 0;
            iVar11 = piVar12[6];
            piVar12[5] = 0;
            piVar12[6] = 0;
            piVar12[7] = iVar11;
            break;
          case 5:
            if (uVar15 == 10 || uVar15 == 0xd) goto switchD_0005ef78_caseD_2e;
            piVar12[2] = 6;
            iVar11 = *(int *)(iVar11 + 0x44);
            piVar12[5] = 1;
            piVar12[6] = iVar11 + -1;
            break;
          case 6:
            iVar8 = piVar12[5] + 1;
            piVar12[5] = iVar8;
            if (uVar15 == 0xd) {
              iVar8 = 7;
            }
            if (uVar15 == 0xd) {
              piVar12[2] = iVar8;
            }
            else if (uVar15 == 10) {
              *(undefined1 *)(*(int *)(iVar11 + 0x3c) + iVar8 + piVar12[6] + -1) = 0;
              goto LAB_0005f1de;
            }
            break;
          case 7:
            if (uVar15 != 10) goto switchD_0005ef78_caseD_2e;
            *(undefined1 *)(*(int *)(iVar11 + 0x3c) + piVar12[6] + piVar12[5] + -1) = 0;
LAB_0005f1de:
            piVar12[0xc] = piVar12[6];
            iVar11 = ftp_pl_insert_finfo(param_4,iVar11);
            if (iVar11 != 0) {
LAB_0005ef28:
              PL_ERROR(param_4,iVar11);
              return uVar14;
            }
            piVar12[1] = 1;
          }
        }
switchD_0005ead2_default:
        uVar13 = uVar13 + 1;
        if (uVar14 < uVar13 || uVar14 - uVar13 == 0) {
          return uVar14;
        }
LAB_0005ec0c:
        iVar11 = piVar12[4];
        uVar15 = (uint)param_1[uVar13];
        if (iVar11 != 0) goto LAB_0005ea8a;
LAB_0005ec18:
        iVar8 = Curl_fileinfo_alloc();
        piVar12[4] = iVar8;
        if (iVar8 == 0) {
          piVar12[3] = 0x1b;
          return uVar14;
        }
        uVar4 = (*Curl_cmalloc)(0xa0);
        iVar11 = piVar12[4];
        *(undefined4 *)(iVar8 + 0x3c) = uVar4;
        iVar8 = *(int *)(iVar11 + 0x3c);
        if (iVar8 == 0) {
          PL_ERROR(param_4,0x1b);
          return uVar14;
        }
        *(undefined4 *)(iVar11 + 0x40) = 0xa0;
        piVar12[6] = 0;
        piVar12[5] = 0;
      } while( true );
    }
  }
  return uVar14;
}

