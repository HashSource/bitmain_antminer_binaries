
int curl_getdate(byte *param_1)

{
  ushort uVar1;
  byte bVar2;
  ushort **ppuVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  byte *__nptr;
  int iVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  uint *puVar18;
  int local_74;
  int local_70;
  uint local_6c;
  size_t local_64;
  int local_58;
  int local_54;
  uint local_50;
  byte *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar9 = 0xffffffff;
  uVar10 = (uint)*param_1;
  local_58 = -1;
  local_54 = -1;
  local_50 = 0xffffffff;
  if (uVar10 == 0) {
    bVar16 = true;
    local_74 = -1;
    local_70 = -1;
    uVar5 = uVar9;
  }
  else {
    local_70 = -1;
    local_74 = -1;
    iVar14 = -1;
    ppuVar3 = __ctype_b_loc();
    iVar8 = 6;
    local_6c = 0;
    uVar15 = 0xffffffff;
    __nptr = param_1;
    do {
      uVar5 = uVar15;
      if (uVar10 == 0) {
        uVar10 = (uint)**ppuVar3;
LAB_0004d70a:
        uVar11 = uVar10 & 0x400;
        if (uVar11 != 0) goto LAB_0004d7d4;
LAB_0004d714:
        if ((int)(uVar10 << 0x14) < 0) {
          if (local_50 == 0xffffffff) {
            puVar18 = &local_50;
            iVar7 = __isoc99_sscanf(__nptr,DAT_0004dac0,&local_58,&local_54,puVar18);
            if (iVar7 == 3) {
              __nptr = __nptr + 8;
            }
            else {
              if ((local_50 != 0xffffffff) ||
                 (iVar7 = __isoc99_sscanf(__nptr,DAT_0004dac4,&local_58,&local_54,puVar18),
                 iVar7 != 2)) goto LAB_0004d720;
              __nptr = __nptr + 5;
              local_50 = uVar11;
            }
          }
          else {
LAB_0004d720:
            piVar4 = __errno_location();
            iVar13 = *piVar4;
            *piVar4 = 0;
            strtol((char *)__nptr,(char **)&local_4c,10);
            iVar7 = *piVar4;
            *piVar4 = iVar13;
            if (iVar7 != 0) {
              return -1;
            }
            uVar5 = curlx_sltosi();
            if ((local_70 != -1) || ((int)local_4c - (int)__nptr != 4)) {
              if (((int)local_4c - (int)__nptr != 8) || (local_74 != -1 || uVar15 != 0xffffffff))
              goto LAB_0004d768;
              if (uVar9 == 0xffffffff) {
                uVar10 = (int)uVar5 % 10000;
                uVar9 = (int)uVar5 % 100;
                local_74 = (int)uVar10 / 100 + ((int)uVar10 >> 0x1f) + ((int)~uVar10 >> 0x1f);
                uVar5 = (int)uVar5 / 10000;
                __nptr = local_4c;
                goto LAB_0004d780;
              }
              if (local_6c != 0) {
                uVar15 = 0xffffffff;
                uVar10 = 1;
                local_74 = -1;
                bVar16 = false;
                goto LAB_0004d8a6;
              }
              uVar15 = 0xffffffff;
              local_74 = -1;
              bVar16 = false;
              goto LAB_0004d77a;
            }
            if ((((int)uVar5 < 0x579) && (param_1 < __nptr)) &&
               (bVar2 = __nptr[-1], bVar2 == 0x2d || bVar2 == 0x2b)) {
              iVar7 = uVar5 + ((int)uVar5 / 100) * -0x28;
              local_70 = iVar7 * 0x3c;
              if (bVar2 == 0x2b) {
                local_70 = iVar7 * -0x3c;
                bVar16 = true;
                uVar10 = 0;
              }
              else {
                bVar16 = true;
                uVar10 = 0;
              }
LAB_0004d8a6:
              if ((uVar10 & local_6c) != 0) {
LAB_0004d8ae:
                if (uVar15 != 0xffffffff) {
                  return -1;
                }
                if ((int)uVar5 < 0x76c) {
                  if ((int)uVar5 < 0x47) {
                    uVar5 = uVar5 + 2000;
                  }
                  else {
                    uVar5 = uVar5 + 0x76c;
                  }
                }
                local_6c = uVar9 + 1;
                __nptr = local_4c;
                if (local_6c != 0) {
                  local_6c = 1;
                }
                goto LAB_0004d780;
              }
            }
            else {
LAB_0004d768:
              bVar16 = false;
              uVar10 = 1;
              if (local_6c == 1) goto LAB_0004d8a6;
              if (uVar9 == 0xffffffff) {
                if (uVar5 - 1 < 0x1f) {
                  bVar16 = true;
                  local_6c = 1;
                  uVar9 = uVar5;
                  goto LAB_0004d77a;
                }
                goto LAB_0004d8ae;
              }
              bVar16 = false;
              local_6c = 0;
            }
LAB_0004d77a:
            uVar5 = uVar15;
            __nptr = local_4c;
            if (!bVar16) {
              return -1;
            }
          }
        }
      }
      else {
        do {
          uVar10 = (uint)(*ppuVar3)[uVar10];
          if ((int)(uVar10 << 0x1c) < 0) goto LAB_0004d70a;
          __nptr = __nptr + 1;
          uVar10 = (uint)*__nptr;
        } while (uVar10 != 0);
        uVar1 = **ppuVar3;
        uVar10 = (uint)uVar1;
        uVar11 = uVar10 & 0x400;
        if ((uVar1 & 0x400) == 0) goto LAB_0004d714;
LAB_0004d7d4:
        local_48 = 0;
        local_44 = 0;
        local_40 = 0;
        local_3c = 0;
        local_38 = 0;
        local_34 = 0;
        local_30 = 0;
        local_2c = 0;
        iVar7 = __isoc99_sscanf(__nptr,DAT_0004dab8,&local_48);
        if (iVar7 == 0) {
          if (iVar14 == -1) {
            local_64 = 0;
            iVar14 = DAT_0004db64;
LAB_0004d830:
            puVar12 = (undefined4 *)(iVar14 + -4);
            iVar14 = 0;
            do {
              puVar12 = puVar12 + 1;
              iVar13 = Curl_raw_equal(&local_48,*puVar12);
              iVar7 = local_74;
              if (iVar13 != 0) goto LAB_0004d974;
              iVar14 = iVar14 + 1;
            } while (iVar14 != 7);
            iVar14 = -1;
            puVar12 = DAT_0004dac8;
          }
          else {
            local_64 = 0;
            puVar12 = DAT_0004dac8;
          }
        }
        else {
          local_64 = strlen((char *)&local_48);
          puVar12 = DAT_0004dac8;
          if (iVar14 == -1) {
            iVar14 = DAT_0004dabc;
            if (3 < local_64) {
              iVar14 = DAT_0004dabc + 0x1c;
            }
            goto LAB_0004d830;
          }
        }
        DAT_0004dac8 = puVar12;
        if (local_74 == -1) {
          iVar7 = 0;
          do {
            puVar12 = puVar12 + 1;
            iVar13 = Curl_raw_equal(&local_48,*puVar12);
            if (iVar13 != 0) goto LAB_0004d974;
            iVar7 = iVar7 + 1;
          } while (iVar7 != 0xc);
        }
        if (local_70 != -1) {
          return -1;
        }
        iVar13 = DAT_0004dacc + 0x330;
        iVar7 = DAT_0004dacc;
        while (iVar6 = Curl_raw_equal(&local_48,iVar7), iVar6 == 0) {
          iVar7 = iVar7 + 0xc;
          if (iVar7 == iVar13) {
            return -1;
          }
        }
        local_70 = *(int *)(iVar7 + 8) * 0x3c;
        iVar7 = local_74;
LAB_0004d974:
        local_74 = iVar7;
        __nptr = __nptr + local_64;
      }
LAB_0004d780:
      uVar10 = (uint)*__nptr;
    } while ((uVar10 != 0) && (iVar8 = iVar8 + -1, uVar15 = uVar5, iVar8 != 0));
    if (local_50 != 0xffffffff) {
      if (uVar9 == 0xffffffff || local_74 == -1) {
        bVar16 = true;
      }
      else {
        bVar16 = false;
      }
      goto LAB_0004d7a4;
    }
    if (local_74 == -1 || uVar9 == 0xffffffff) {
      bVar16 = true;
    }
    else {
      bVar16 = false;
    }
  }
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
LAB_0004d7a4:
  if ((!bVar16) && (uVar5 != 0xffffffff)) {
    if (0x7f5 < (int)uVar5) {
      return 0x7fffffff;
    }
    if ((int)uVar5 < 0x7b2) {
      return 0;
    }
    bVar17 = SBORROW4(uVar9,0x1f);
    iVar14 = uVar9 - 0x1f;
    bVar16 = uVar9 == 0x1f;
    if ((int)uVar9 < 0x20) {
      bVar17 = SBORROW4(local_74,0xb);
      iVar14 = local_74 + -0xb;
      bVar16 = local_74 == 0xb;
    }
    if ((((bVar16 || iVar14 < 0 != bVar17) && (local_58 < 0x18)) && (local_54 < 0x3c)) &&
       ((int)local_50 < 0x3d)) {
      iVar14 = local_74;
      if (local_74 < 0) {
        uVar5 = uVar5 + (0xb - local_74) / 0xc;
        iVar14 = 0xb - (0xb - local_74) % 0xc;
      }
      uVar10 = uVar5;
      if (local_74 < 2) {
        uVar10 = uVar5 - 1;
      }
      uVar15 = uVar10 & ~((int)uVar10 >> 0x20);
      if ((int)uVar10 < 0) {
        uVar15 = uVar10 + 3;
      }
      iVar14 = local_50 +
               (local_54 +
               (local_58 +
               (uVar5 * 0x16d + (int)uVar10 / 400 + (((int)uVar15 >> 2) - (int)uVar10 / 100) +
                *(int *)(DAT_0004dabc + iVar14 * 4 + 0x398) + uVar9) * 0x18 + -0x1077fc0) * 0x3c) *
               0x3c;
      if (iVar14 != -1) {
        if (local_70 == -1) {
          local_70 = 0;
        }
        else if ((0 < local_70) && (0x7fffffff - local_70 < iVar14)) {
          return 0x7fffffff;
        }
        return iVar14 + local_70;
      }
      return -1;
    }
  }
  return -1;
}

