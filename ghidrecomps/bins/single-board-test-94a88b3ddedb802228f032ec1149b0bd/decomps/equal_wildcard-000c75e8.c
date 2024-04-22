
/* WARNING: Type propagation algorithm not settling */

undefined4 equal_wildcard(byte *param_1,byte *param_2,byte *param_3,byte *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  bool bVar14;
  
  pbVar6 = param_1;
  pbVar10 = param_2;
  if ((param_4 < (byte *)0x2) || (*param_3 != 0x2e)) {
    if (param_2 != (byte *)0x0) {
      uVar9 = 0;
      pbVar11 = (byte *)0x0;
      uVar7 = 1;
      pbVar8 = (byte *)0x0;
      pbVar12 = param_1;
      do {
        pbVar5 = pbVar8;
        uVar4 = (uint)*pbVar12;
        if (uVar4 == 0x2a) {
          if (pbVar5 == param_2 + -1) {
            uVar4 = 1;
          }
          else {
            uVar4 = (uint)(pbVar12[1] == 0x2e);
          }
          if ((((pbVar11 != (byte *)0x0) || ((uVar7 & 8 | uVar9) != 0)) ||
              (((param_5 & 4) != 0 && ((uVar4 ^ 1 | uVar7 & 1 ^ 1) != 0)))) ||
             ((uVar4 | uVar7 & 1) == 0)) goto LAB_000c7716;
          uVar7 = uVar7 & 0xfffffffe;
          uVar9 = 0;
          pbVar11 = pbVar12;
        }
        else if (((uVar4 & 0xffffffdf) - 0x41 < 0x1a) || (uVar4 - 0x30 < 10)) {
          if (((int)(uVar7 << 0x1f) < 0) &&
             ((3 < (uint)((int)param_2 - (int)pbVar5) &&
              (iVar1 = strncasecmp((char *)pbVar12,DAT_000c7930,4), iVar1 == 0)))) {
            uVar7 = uVar7 | 8;
          }
          uVar7 = uVar7 & 0xfffffffa;
        }
        else if (uVar4 == 0x2e) {
          if ((uVar7 & 5) != 0) goto LAB_000c7716;
          uVar9 = uVar9 + 1;
          uVar7 = 1;
        }
        else {
          if ((uVar4 != 0x2d) || ((int)(uVar7 << 0x1d) < 0)) goto LAB_000c7716;
          uVar7 = uVar7 | 4;
        }
        pbVar8 = pbVar5 + 1;
        pbVar12 = pbVar12 + 1;
      } while (pbVar5 + 1 != param_2);
      if ((((uVar7 & 5) == 0) && (1 < (int)uVar9)) && (pbVar11 != (byte *)0x0)) {
        pbVar10 = param_1 + (int)(pbVar5 + (1 - (int)pbVar11));
        iVar1 = (int)pbVar11 - (int)param_1;
        pbVar6 = pbVar10 + -1;
        if (param_4 < pbVar6 + iVar1) {
          return 0;
        }
        if (iVar1 != 0) {
          uVar9 = (uint)*param_1;
          bVar3 = *param_3;
          if (uVar9 == 0) {
            return 0;
          }
          pbVar12 = param_1 + iVar1 + -1;
          pbVar8 = param_3;
          while( true ) {
            uVar7 = (uint)bVar3;
            if (uVar9 != uVar7) {
              if (uVar9 - 0x41 < 0x1a) {
                uVar9 = uVar9 + 0x20 & 0xff;
              }
              if (uVar7 - 0x41 < 0x1a) {
                uVar7 = uVar7 + 0x20 & 0xff;
              }
              if (uVar9 != uVar7) {
                return 0;
              }
            }
            if (param_1 == pbVar12) break;
            param_1 = param_1 + 1;
            uVar9 = (uint)*param_1;
            pbVar8 = pbVar8 + 1;
            bVar3 = *pbVar8;
            if (uVar9 == 0) {
              return 0;
            }
          }
        }
        pbVar8 = param_3 + ((int)param_4 - (int)pbVar6);
        if (pbVar6 != (byte *)0x0) {
          uVar9 = (uint)param_3[(int)param_4 - (int)pbVar6];
          bVar3 = pbVar11[1];
          if (uVar9 == 0) {
            return 0;
          }
          pbVar6 = pbVar8;
          pbVar12 = pbVar11 + 2;
          while( true ) {
            uVar7 = (uint)bVar3;
            if (uVar9 != uVar7) {
              if (uVar9 - 0x41 < 0x1a) {
                uVar9 = uVar9 + 0x20 & 0xff;
              }
              if (uVar7 - 0x41 < 0x1a) {
                uVar7 = uVar7 + 0x20 & 0xff;
              }
              if (uVar9 != uVar7) {
                return 0;
              }
            }
            if (pbVar12 == pbVar11 + (int)pbVar10) break;
            pbVar6 = pbVar6 + 1;
            uVar9 = (uint)*pbVar6;
            bVar3 = *pbVar12;
            pbVar12 = pbVar12 + 1;
            if (uVar9 == 0) {
              return 0;
            }
          }
        }
        pbVar6 = param_3 + iVar1;
        if ((iVar1 == 0) && (pbVar11[1] == 0x2e)) {
          if (pbVar6 == pbVar8) {
            return 0;
          }
          uVar9 = (param_5 << 0x1c) >> 0x1f;
        }
        else {
          if (((byte *)0x3 < param_4) &&
             (iVar2 = strncasecmp((char *)param_3,DAT_000c7930,4), iVar2 == 0)) {
            return 0;
          }
          uVar9 = 0;
        }
        if ((pbVar8 == pbVar6 + 1) && (param_3[iVar1] == 0x2a)) {
          return 1;
        }
        if (pbVar6 == pbVar8) {
          return 1;
        }
        if (uVar9 != 0) {
          while( true ) {
            pbVar10 = pbVar6 + 1;
            uVar7 = (uint)*pbVar6;
            uVar9 = uVar7 - 0x30;
            bVar14 = 8 < uVar9;
            bVar13 = uVar9 == 9;
            if (9 < uVar9) {
              bVar14 = 0x18 < uVar7 - 0x41;
              bVar13 = uVar7 - 0x41 == 0x19;
            }
            if (((bVar14 && !bVar13) && (0x19 < uVar7 - 0x61)) &&
               ((uVar7 != 0x2d && (uVar7 != 0x2e)))) break;
            pbVar6 = pbVar10;
            if (pbVar8 == pbVar10) {
              return 1;
            }
          }
          return 0;
        }
        while( true ) {
          pbVar10 = pbVar6 + 1;
          uVar7 = (uint)*pbVar6;
          uVar9 = uVar7 - 0x41;
          bVar14 = 0x18 < uVar9;
          bVar13 = uVar9 == 0x19;
          if (0x19 < uVar9) {
            bVar14 = 8 < uVar7 - 0x30;
            bVar13 = uVar7 - 0x30 == 9;
          }
          if (((bVar14 && !bVar13) && (0x19 < uVar7 - 0x61)) && (uVar7 != 0x2d)) break;
          pbVar6 = pbVar10;
          if (pbVar8 == pbVar10) {
            return 1;
          }
        }
        return 0;
      }
      goto LAB_000c7716;
    }
    if ((int)(param_5 << 0x10) < 0) goto LAB_000c775a;
  }
  else {
LAB_000c7716:
    if ((int)(param_5 << 0x10) < 0) {
      if ((param_4 < param_2) && (bVar3 = *param_1, bVar3 != 0)) {
        pbVar11 = param_1;
        if ((int)(param_5 << 0x1b) < 0) {
          do {
            pbVar8 = pbVar11 + 1;
            pbVar6 = pbVar11;
            if ((bVar3 == 0x2e) || (pbVar10 = pbVar10 + -1, pbVar6 = pbVar8, pbVar10 <= param_4))
            break;
            bVar3 = pbVar11[1];
            pbVar11 = pbVar8;
          } while (bVar3 != 0);
        }
        else {
          do {
            pbVar6 = pbVar6 + 1;
            pbVar10 = pbVar10 + -1;
            if (pbVar10 <= param_4) break;
          } while (*pbVar6 != 0);
        }
      }
LAB_000c775a:
      if (param_4 == pbVar10) goto LAB_000c7762;
    }
  }
  bVar13 = param_4 != param_2;
  pbVar6 = param_1;
  param_4 = param_2;
  if (bVar13) {
    return 0;
  }
LAB_000c7762:
  if (param_4 == (byte *)0x0) {
    return 1;
  }
  uVar9 = (uint)*pbVar6;
  bVar3 = *param_3;
  if (uVar9 != 0) {
    pbVar10 = pbVar6 + (int)(param_4 + -1);
    do {
      uVar7 = (uint)bVar3;
      if (uVar9 != uVar7) {
        if (uVar9 - 0x41 < 0x1a) {
          uVar9 = uVar9 + 0x20 & 0xff;
        }
        if (uVar7 - 0x41 < 0x1a) {
          uVar7 = uVar7 + 0x20 & 0xff;
        }
        if (uVar9 != uVar7) {
          return 0;
        }
      }
      if (pbVar6 == pbVar10) {
        return 1;
      }
      pbVar6 = pbVar6 + 1;
      uVar9 = (uint)*pbVar6;
      param_3 = param_3 + 1;
      bVar3 = *param_3;
    } while (uVar9 != 0);
    return 0;
  }
  return 0;
}

