
int curl_getdate(byte *param_1)

{
  ushort uVar1;
  byte bVar2;
  ushort **ppuVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined1 *puVar13;
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
  
  uVar8 = 0xffffffff;
  uVar9 = (uint)*param_1;
  local_58 = -1;
  local_54 = -1;
  local_50 = 0xffffffff;
  if (uVar9 == 0) {
    bVar16 = true;
    local_74 = -1;
    local_70 = -1;
    uVar5 = uVar8;
  }
  else {
    local_70 = -1;
    local_74 = -1;
    iVar14 = -1;
    ppuVar3 = __ctype_b_loc();
    iVar7 = 6;
    local_6c = 0;
    uVar15 = 0xffffffff;
    __nptr = param_1;
    do {
      uVar5 = uVar15;
      if (uVar9 == 0) {
        uVar9 = (uint)**ppuVar3;
LAB_0004d70a:
        uVar10 = uVar9 & 0x400;
        if (uVar10 != 0) goto LAB_0004d7d4;
LAB_0004d714:
        if ((int)(uVar9 << 0x14) < 0) {
          if (local_50 == 0xffffffff) {
            puVar18 = &local_50;
            iVar6 = __isoc99_sscanf(__nptr,"%02d:%02d:%02d",&local_58,&local_54,puVar18);
            if (iVar6 == 3) {
              __nptr = __nptr + 8;
            }
            else {
              if ((local_50 != 0xffffffff) ||
                 (iVar6 = __isoc99_sscanf(__nptr,"%02d:%02d",&local_58,&local_54,puVar18),
                 iVar6 != 2)) goto LAB_0004d720;
              __nptr = __nptr + 5;
              local_50 = uVar10;
            }
          }
          else {
LAB_0004d720:
            piVar4 = __errno_location();
            iVar11 = *piVar4;
            *piVar4 = 0;
            strtol((char *)__nptr,(char **)&local_4c,10);
            iVar6 = *piVar4;
            *piVar4 = iVar11;
            if (iVar6 != 0) {
              return -1;
            }
            uVar5 = curlx_sltosi();
            if ((local_70 != -1) || ((int)local_4c - (int)__nptr != 4)) {
              if (((int)local_4c - (int)__nptr != 8) || (local_74 != -1 || uVar15 != 0xffffffff))
              goto LAB_0004d768;
              if (uVar8 == 0xffffffff) {
                uVar9 = (int)uVar5 % 10000;
                uVar8 = (int)uVar5 % 100;
                local_74 = (int)uVar9 / 100 + ((int)uVar9 >> 0x1f) + ((int)~uVar9 >> 0x1f);
                uVar5 = (int)uVar5 / 10000;
                __nptr = local_4c;
                goto LAB_0004d780;
              }
              if (local_6c != 0) {
                uVar15 = 0xffffffff;
                uVar9 = 1;
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
              iVar6 = uVar5 + ((int)uVar5 / 100) * -0x28;
              local_70 = iVar6 * 0x3c;
              if (bVar2 == 0x2b) {
                local_70 = iVar6 * -0x3c;
                bVar16 = true;
                uVar9 = 0;
              }
              else {
                bVar16 = true;
                uVar9 = 0;
              }
LAB_0004d8a6:
              if ((uVar9 & local_6c) != 0) {
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
                local_6c = uVar8 + 1;
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
              uVar9 = 1;
              if (local_6c == 1) goto LAB_0004d8a6;
              if (uVar8 == 0xffffffff) {
                if (uVar5 - 1 < 0x1f) {
                  bVar16 = true;
                  local_6c = 1;
                  uVar8 = uVar5;
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
          uVar9 = (uint)(*ppuVar3)[uVar9];
          if ((int)(uVar9 << 0x1c) < 0) goto LAB_0004d70a;
          __nptr = __nptr + 1;
          uVar9 = (uint)*__nptr;
        } while (uVar9 != 0);
        uVar1 = **ppuVar3;
        uVar9 = (uint)uVar1;
        uVar10 = uVar9 & 0x400;
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
        iVar6 = __isoc99_sscanf(__nptr,"%31[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz]",
                                &local_48);
        if (iVar6 == 0) {
          if (iVar14 == -1) {
            local_64 = 0;
            puVar12 = &Curl_wkday;
LAB_0004d830:
            puVar12 = puVar12 + -1;
            iVar14 = 0;
            do {
              puVar12 = puVar12 + 1;
              iVar11 = Curl_raw_equal(&local_48,*puVar12);
              iVar6 = local_74;
              if (iVar11 != 0) goto LAB_0004d974;
              iVar14 = iVar14 + 1;
            } while (iVar14 != 7);
            iVar14 = -1;
          }
          else {
            local_64 = 0;
          }
        }
        else {
          local_64 = strlen((char *)&local_48);
          if (iVar14 == -1) {
            puVar12 = &Curl_wkday;
            if (3 < local_64) {
              puVar12 = (undefined4 *)weekday;
            }
            goto LAB_0004d830;
          }
        }
        if (local_74 == -1) {
          puVar12 = (undefined4 *)(tz + 0x32c);
          iVar6 = 0;
          do {
            puVar12 = puVar12 + 1;
            iVar11 = Curl_raw_equal(&local_48,*puVar12);
            if (iVar11 != 0) goto LAB_0004d974;
            iVar6 = iVar6 + 1;
          } while (iVar6 != 0xc);
        }
        if (local_70 != -1) {
          return -1;
        }
        puVar13 = tz;
        while (iVar6 = Curl_raw_equal(&local_48,puVar13), iVar6 == 0) {
          puVar13 = puVar13 + 0xc;
          if (puVar13 == Curl_month) {
            return -1;
          }
        }
        local_70 = *(int *)(puVar13 + 8) * 0x3c;
        iVar6 = local_74;
LAB_0004d974:
        local_74 = iVar6;
        __nptr = __nptr + local_64;
      }
LAB_0004d780:
      uVar9 = (uint)*__nptr;
    } while ((uVar9 != 0) && (iVar7 = iVar7 + -1, uVar15 = uVar5, iVar7 != 0));
    if (local_50 != 0xffffffff) {
      if (uVar8 == 0xffffffff || local_74 == -1) {
        bVar16 = true;
      }
      else {
        bVar16 = false;
      }
      goto LAB_0004d7a4;
    }
    if (local_74 == -1 || uVar8 == 0xffffffff) {
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
    bVar17 = SBORROW4(uVar8,0x1f);
    iVar14 = uVar8 - 0x1f;
    bVar16 = uVar8 == 0x1f;
    if ((int)uVar8 < 0x20) {
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
      uVar9 = uVar5;
      if (local_74 < 2) {
        uVar9 = uVar5 - 1;
      }
      uVar15 = uVar9 & ~((int)uVar9 >> 0x20);
      if ((int)uVar9 < 0) {
        uVar15 = uVar9 + 3;
      }
      iVar14 = local_50 +
               (local_54 +
               (local_58 +
               (uVar5 * 0x16d + (int)uVar9 / 400 + (((int)uVar15 >> 2) - (int)uVar9 / 100) +
                *(int *)(month_days_cumulative_8160 + iVar14 * 4) + uVar8) * 0x18 + -0x1077fc0) *
               0x3c) * 0x3c;
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

