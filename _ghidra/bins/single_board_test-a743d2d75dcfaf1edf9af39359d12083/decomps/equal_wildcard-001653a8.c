
/* WARNING: Type propagation algorithm not settling */

undefined4 equal_wildcard(byte *param_1,byte *param_2,byte *param_3,byte *param_4,uint param_5)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  
  pbVar5 = param_1;
  pbVar9 = param_2;
  if ((param_4 < (byte *)0x2) || (*param_3 != 0x2e)) {
    if (param_2 != (byte *)0x0) {
      iVar8 = 0;
      pbVar10 = (byte *)0x0;
      uVar6 = 1;
      bVar12 = false;
      pbVar7 = (byte *)0x0;
      pbVar11 = param_1;
      do {
        pbVar4 = pbVar7;
        uVar3 = (uint)*pbVar11;
        if (uVar3 == 0x2a) {
          if (pbVar4 == param_2 + -1) {
            bVar13 = true;
          }
          else {
            bVar13 = pbVar11[1] == 0x2e;
          }
          if ((((pbVar10 != (byte *)0x0) || (bVar12 || iVar8 != 0)) ||
              (((param_5 & 4) != 0 && (!bVar13 || (uVar6 & 1) != 1)))) ||
             (!bVar13 && (uVar6 & 1) == 0)) goto LAB_001654d6;
          uVar6 = uVar6 & 0xfffffffe;
          iVar8 = 0;
          pbVar10 = pbVar11;
        }
        else if (((uVar3 & 0xffffffdf) - 0x41 < 0x1a) || (uVar3 - 0x30 < 10)) {
          if (((int)(uVar6 << 0x1f) < 0) &&
             ((3 < (uint)((int)param_2 - (int)pbVar4) &&
              (iVar1 = strncasecmp((char *)pbVar11,"xn--",4), iVar1 == 0)))) {
            bVar12 = true;
          }
          uVar6 = 0;
        }
        else if (uVar3 == 0x2e) {
          if (uVar6 != 0) goto LAB_001654d6;
          iVar8 = iVar8 + 1;
          uVar6 = 1;
          bVar12 = false;
        }
        else {
          if ((uVar3 != 0x2d) || ((int)(uVar6 << 0x1d) < 0)) goto LAB_001654d6;
          uVar6 = uVar6 | 4;
        }
        pbVar7 = pbVar4 + 1;
        pbVar11 = pbVar11 + 1;
      } while (pbVar4 + 1 != param_2);
      if (((uVar6 == 0) && (1 < iVar8)) && (pbVar10 != (byte *)0x0)) {
        pbVar9 = param_1 + (int)(pbVar4 + (1 - (int)pbVar10));
        iVar8 = (int)pbVar10 - (int)param_1;
        pbVar5 = pbVar9 + -1;
        if (param_4 < pbVar5 + iVar8) {
          return 0;
        }
        if (iVar8 != 0) {
          uVar6 = (uint)*param_1;
          bVar2 = *param_3;
          if (uVar6 == 0) {
            return 0;
          }
          pbVar11 = param_1 + iVar8 + -1;
          pbVar7 = param_3;
          while( true ) {
            uVar3 = (uint)bVar2;
            if (uVar6 != uVar3) {
              if (uVar6 - 0x41 < 0x1a) {
                uVar6 = uVar6 + 0x20 & 0xff;
              }
              if (uVar3 - 0x41 < 0x1a) {
                uVar3 = uVar3 + 0x20 & 0xff;
              }
              if (uVar6 != uVar3) {
                return 0;
              }
            }
            if (param_1 == pbVar11) break;
            param_1 = param_1 + 1;
            uVar6 = (uint)*param_1;
            pbVar7 = pbVar7 + 1;
            bVar2 = *pbVar7;
            if (uVar6 == 0) {
              return 0;
            }
          }
        }
        pbVar7 = param_3 + ((int)param_4 - (int)pbVar5);
        if (pbVar5 != (byte *)0x0) {
          uVar6 = (uint)param_3[(int)param_4 - (int)pbVar5];
          bVar2 = pbVar10[1];
          if (uVar6 == 0) {
            return 0;
          }
          pbVar5 = pbVar7;
          pbVar11 = pbVar10 + 2;
          while( true ) {
            uVar3 = (uint)bVar2;
            if (uVar6 != uVar3) {
              if (uVar6 - 0x41 < 0x1a) {
                uVar6 = uVar6 + 0x20 & 0xff;
              }
              if (uVar3 - 0x41 < 0x1a) {
                uVar3 = uVar3 + 0x20 & 0xff;
              }
              if (uVar6 != uVar3) {
                return 0;
              }
            }
            if (pbVar11 == pbVar10 + (int)pbVar9) break;
            pbVar5 = pbVar5 + 1;
            uVar6 = (uint)*pbVar5;
            bVar2 = *pbVar11;
            pbVar11 = pbVar11 + 1;
            if (uVar6 == 0) {
              return 0;
            }
          }
        }
        pbVar5 = param_3 + iVar8;
        if ((iVar8 == 0) && (pbVar10[1] == 0x2e)) {
          if (pbVar5 == pbVar7) {
            return 0;
          }
          uVar6 = (param_5 << 0x1c) >> 0x1f;
        }
        else {
          if (((byte *)0x3 < param_4) && (iVar1 = strncasecmp((char *)param_3,"xn--",4), iVar1 == 0)
             ) {
            return 0;
          }
          uVar6 = 0;
        }
        if ((pbVar7 == pbVar5 + 1) && (param_3[iVar8] == 0x2a)) {
          return 1;
        }
        if (pbVar5 == pbVar7) {
          return 1;
        }
        if (uVar6 != 0) {
          while( true ) {
            pbVar9 = pbVar5 + 1;
            uVar3 = (uint)*pbVar5;
            uVar6 = uVar3 - 0x30;
            bVar13 = 8 < uVar6;
            bVar12 = uVar6 == 9;
            if (9 < uVar6) {
              bVar13 = 0x18 < uVar3 - 0x41;
              bVar12 = uVar3 - 0x41 == 0x19;
            }
            if (((bVar13 && !bVar12) && (0x19 < uVar3 - 0x61)) &&
               ((uVar3 != 0x2d && (uVar3 != 0x2e)))) break;
            pbVar5 = pbVar9;
            if (pbVar7 == pbVar9) {
              return 1;
            }
          }
          return 0;
        }
        while( true ) {
          pbVar9 = pbVar5 + 1;
          uVar3 = (uint)*pbVar5;
          uVar6 = uVar3 - 0x41;
          bVar13 = 0x18 < uVar6;
          bVar12 = uVar6 == 0x19;
          if (0x19 < uVar6) {
            bVar13 = 8 < uVar3 - 0x30;
            bVar12 = uVar3 - 0x30 == 9;
          }
          if (((bVar13 && !bVar12) && (0x19 < uVar3 - 0x61)) && (uVar3 != 0x2d)) break;
          pbVar5 = pbVar9;
          if (pbVar7 == pbVar9) {
            return 1;
          }
        }
        return 0;
      }
      goto LAB_001654d6;
    }
    if ((int)(param_5 << 0x10) < 0) goto LAB_0016551a;
  }
  else {
LAB_001654d6:
    if ((int)(param_5 << 0x10) < 0) {
      if ((param_4 < param_2) && (bVar2 = *param_1, bVar2 != 0)) {
        pbVar10 = param_1;
        if ((int)(param_5 << 0x1b) < 0) {
          do {
            pbVar7 = pbVar10 + 1;
            pbVar5 = pbVar10;
            if ((bVar2 == 0x2e) || (pbVar9 = pbVar9 + -1, pbVar5 = pbVar7, pbVar9 <= param_4))
            break;
            bVar2 = pbVar10[1];
            pbVar10 = pbVar7;
          } while (bVar2 != 0);
        }
        else {
          do {
            pbVar5 = pbVar5 + 1;
            pbVar9 = pbVar9 + -1;
            if (pbVar9 <= param_4) break;
          } while (*pbVar5 != 0);
        }
      }
LAB_0016551a:
      if (param_4 == pbVar9) goto LAB_00165522;
    }
  }
  bVar12 = param_4 != param_2;
  pbVar5 = param_1;
  param_4 = param_2;
  if (bVar12) {
    return 0;
  }
LAB_00165522:
  if (param_4 == (byte *)0x0) {
    return 1;
  }
  uVar6 = (uint)*pbVar5;
  bVar2 = *param_3;
  if (uVar6 != 0) {
    pbVar9 = pbVar5 + (int)(param_4 + -1);
    do {
      uVar3 = (uint)bVar2;
      if (uVar6 != uVar3) {
        if (uVar6 - 0x41 < 0x1a) {
          uVar6 = uVar6 + 0x20 & 0xff;
        }
        if (uVar3 - 0x41 < 0x1a) {
          uVar3 = uVar3 + 0x20 & 0xff;
        }
        if (uVar6 != uVar3) {
          return 0;
        }
      }
      if (pbVar5 == pbVar9) {
        return 1;
      }
      pbVar5 = pbVar5 + 1;
      uVar6 = (uint)*pbVar5;
      param_3 = param_3 + 1;
      bVar2 = *param_3;
    } while (uVar6 != 0);
    return 0;
  }
  return 0;
}

