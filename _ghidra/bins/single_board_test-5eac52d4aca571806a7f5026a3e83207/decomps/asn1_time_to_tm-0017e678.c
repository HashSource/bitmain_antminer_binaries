
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 asn1_time_to_tm(int *param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  bool bVar15;
  bool bVar16;
  int local_98;
  int local_90;
  int local_8c;
  int local_74;
  int local_68;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int iStack_30;
  int iStack_2c;
  
  if (param_2[1] == 0x17) {
    local_68 = 7;
    local_98 = 5;
    local_90 = 6;
    bVar16 = (param_2[3] & 0x100U) != 0;
    bVar15 = !bVar16;
    if (bVar16) {
      iVar9 = 0xd;
    }
    else {
      iVar9 = 0xb;
    }
  }
  else {
    if (param_2[1] != 0x18) {
      return 0;
    }
    local_68 = 8;
    local_98 = 6;
    local_90 = 7;
    bVar15 = (param_2[3] & 0x100U) == 0;
    if (bVar15) {
      iVar9 = 0xd;
    }
    else {
      iVar9 = 0xf;
    }
    bVar16 = !bVar15;
  }
  iVar12 = *param_2;
  pbVar6 = (byte *)param_2[2];
  memset(&local_54,0,0x2c);
  if (iVar9 <= iVar12) {
    iVar9 = 0;
    iVar11 = 0;
    pbVar10 = pbVar6;
    do {
      bVar1 = *pbVar10;
      bVar5 = bVar15;
      if (local_98 != iVar11) {
        bVar5 = false;
      }
      if ((bVar5) && ((bVar1 - 0x2b & 0xfd) == 0 || bVar1 == 0x5a)) {
        iVar2 = param_2[1];
        goto LAB_0017e7a6;
      }
      iVar2 = ascii_isdigit();
      if (iVar2 == 0) {
        return 0;
      }
      bVar1 = *pbVar10;
      if (iVar12 == iVar9 + 1) {
        return 0;
      }
      iVar2 = ascii_isdigit(pbVar10[1]);
      if (iVar2 == 0) {
        return 0;
      }
      iVar9 = iVar9 + 2;
      iVar3 = (uint)pbVar10[1] + (bVar1 - 0x30) * 10;
      iVar14 = iVar3 + -0x30;
      if (iVar12 == iVar9) {
        return 0;
      }
      iVar2 = param_2[1];
      iVar7 = iVar11;
      if (iVar2 == 0x17) {
        iVar7 = iVar11 + 1;
      }
      if (iVar14 < (int)(&min_11283)[iVar7]) {
        return 0;
      }
      if (*(int *)(max_11284 + iVar7 * 4) < iVar14) {
        return 0;
      }
      switch(iVar7) {
      case 0:
        local_40 = iVar14 * 100 + -0x76c;
        break;
      case 1:
        if (iVar2 == 0x17) {
          iVar7 = iVar3 + -0x61;
          if (iVar14 < 0x32) {
            iVar3 = iVar3 + 0x34;
          }
          local_40 = iVar3;
          if (iVar14 != 0x31 && iVar7 < 0 == SBORROW4(iVar14,0x31)) {
            local_40 = iVar14;
          }
        }
        else {
          local_40 = local_40 + iVar14;
        }
        break;
      case 2:
        local_44 = iVar3 + -0x31;
        break;
      case 3:
        if (local_44 == 1) {
          uVar4 = local_40 + 0x76c;
          if ((int)uVar4 % 400 == 0) {
            iVar7 = 0x1d;
          }
          else if ((int)uVar4 % 100 == 0) {
            iVar7 = 0x1c;
          }
          else if ((uVar4 & 3) == 0) {
            iVar7 = 0x1d;
          }
          else {
            iVar7 = 0x1c;
          }
          if (iVar7 < iVar14) {
            return 0;
          }
          local_38 = iVar3 + -0x12;
LAB_0017e9ae:
          uVar4 = local_40 + 0x76b;
          iVar3 = local_44 + 0xe;
          local_74 = (int)uVar4 >> 0x1f;
          uVar13 = (int)uVar4 % 100;
        }
        else {
          if (*(int *)(mdays_11285 + local_44 * 4) < iVar14) {
            return 0;
          }
          local_38 = *(int *)(ydays_11274 + local_44 * 4) + iVar14 + -1;
          uVar4 = local_40 + 0x76c;
          if (local_44 < 2) goto LAB_0017e9ae;
          local_74 = (int)uVar4 >> 0x1f;
          iVar3 = (int)uVar4 / 100 + local_74;
          if ((int)uVar4 % 400 == 0) {
            uVar8 = 1;
            uVar13 = uVar4 + (iVar3 - local_74) * -100;
          }
          else {
            uVar13 = uVar4 + (iVar3 - local_74) * -100;
            if (uVar13 == 0) {
              uVar8 = 0;
            }
            else {
              uVar8 = (uint)((uVar4 & 3) == 0);
            }
          }
          local_38 = local_38 + uVar8;
          iVar3 = local_44 + 2;
        }
        uVar8 = uVar13 + 3 & (int)uVar13 >> 0x20;
        if ((iVar3 * 0xd >> 0x1e & 1U) == 0) {
          uVar8 = uVar13;
        }
        local_3c = (int)(((int)uVar4 / 100) * 5 + ((int)uVar4 >> 0x1f) * 6 + local_74 * -6 +
                         (int)uVar4 / 400 + (iVar3 * 0xd) / 5 + iVar14 + uVar13 + ((int)uVar8 >> 2)
                        + 6) % 7;
        local_48 = iVar14;
        break;
      case 4:
        local_4c = iVar14;
        break;
      case 5:
        local_50 = iVar14;
        break;
      case 6:
        local_54 = iVar14;
      }
      iVar11 = iVar11 + 1;
      pbVar10 = pbVar10 + 2;
    } while (local_90 != iVar11);
    bVar1 = pbVar6[iVar9];
LAB_0017e7a6:
    if ((iVar2 == 0x18) && (bVar1 == 0x2e)) {
      if (((!bVar16) && (iVar11 = iVar9 + 1, iVar12 != iVar11)) && (iVar11 < iVar12)) {
        pbVar10 = pbVar6 + iVar11;
        iVar9 = iVar11;
        do {
          iVar2 = ascii_isdigit(*pbVar10);
          if (iVar2 == 0) {
            if (iVar11 == iVar9) {
              return 0;
            }
            bVar1 = *pbVar10;
            if (bVar1 == 0x5a) goto LAB_0017eabe;
            goto LAB_0017e7bc;
          }
          iVar9 = iVar9 + 1;
          pbVar10 = pbVar10 + 1;
        } while (iVar12 != iVar9);
      }
    }
    else {
      if (bVar1 == 0x5a) {
LAB_0017eabe:
        iVar2 = iVar9 + 1;
      }
      else {
        if (bVar16) {
          return 0;
        }
LAB_0017e7bc:
        if ((bVar1 - 0x2b & 0xfd) != 0) {
          return 0;
        }
        if (bVar1 == 0x2d) {
          iVar11 = 1;
        }
        else {
          iVar11 = -1;
        }
        if (iVar12 != iVar9 + 5) {
          return 0;
        }
        iVar2 = iVar9 + 1;
        if (param_1 != (int *)0x0) {
          pbVar6 = pbVar6 + iVar9;
          iVar2 = iVar9 + 3;
          local_8c = 0;
          iVar3 = local_90;
          iVar9 = local_90;
          do {
            iVar9 = iVar9 + 1;
            iVar14 = ascii_isdigit(pbVar6[1]);
            if (iVar14 == 0) {
              return 0;
            }
            bVar1 = pbVar6[1];
            iVar14 = ascii_isdigit(pbVar6[2]);
            if (iVar14 == 0) {
              return 0;
            }
            iVar14 = iVar3;
            if (param_2[1] == 0x17) {
              iVar14 = iVar9;
            }
            iVar7 = (uint)pbVar6[2] + (bVar1 - 0x30) * 10 + -0x30;
            if (iVar7 < (int)(&min_11283)[iVar14]) {
              return 0;
            }
            if (*(int *)(max_11284 + iVar14 * 4) < iVar7) {
              return 0;
            }
            if (local_90 == iVar3) {
              local_8c = iVar7 * 0xe10;
            }
            else {
              if (iVar3 == local_68) {
                local_8c = iVar7 * 0x3c + local_8c;
              }
              if (local_68 < iVar9) {
                if ((local_8c != 0) &&
                   (iVar9 = OPENSSL_gmtime_adj(&local_54,0,iVar11 * local_8c), iVar9 == 0)) {
                  return 0;
                }
                goto LAB_0017eac0;
              }
            }
            pbVar6 = pbVar6 + 2;
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 2;
          } while( true );
        }
        pbVar6 = pbVar6 + iVar9;
        do {
          iVar9 = ascii_isdigit(pbVar6[1]);
          if (iVar9 == 0) {
            return 0;
          }
          bVar1 = pbVar6[1];
          iVar9 = ascii_isdigit(pbVar6[2]);
          if (iVar9 == 0) {
            return 0;
          }
          pbVar10 = pbVar6 + 2;
          iVar2 = iVar2 + 2;
          pbVar6 = pbVar6 + 2;
          iVar9 = local_90;
          if (param_2[1] == 0x17) {
            iVar9 = local_90 + 1;
          }
          local_90 = local_90 + 1;
          iVar11 = (uint)*pbVar10 + (bVar1 - 0x30) * 10 + -0x30;
          if (iVar11 < (int)(&min_11283)[iVar9]) {
            return 0;
          }
          if (*(int *)(max_11284 + iVar9 * 4) < iVar11) {
            return 0;
          }
        } while (local_90 <= local_68);
      }
LAB_0017eac0:
      if (iVar2 == iVar12) {
        if (param_1 == (int *)0x0) {
          return 1;
        }
        *param_1 = local_54;
        param_1[1] = local_50;
        param_1[2] = local_4c;
        param_1[3] = local_48;
        param_1[4] = local_44;
        param_1[5] = local_40;
        param_1[6] = local_3c;
        param_1[7] = local_38;
        param_1[8] = local_34;
        param_1[9] = iStack_30;
        param_1[10] = iStack_2c;
        return 1;
      }
    }
  }
  return 0;
}

