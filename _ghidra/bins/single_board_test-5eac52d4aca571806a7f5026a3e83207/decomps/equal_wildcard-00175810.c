
uint equal_wildcard(byte *param_1,byte *param_2,byte *param_3,byte *param_4,uint param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  
  if ((param_4 < (byte *)0x2) || (*param_3 != 0x2e)) {
    if (param_2 != (byte *)0x0) {
      iVar10 = 0;
      pbVar11 = (byte *)0x0;
      pbVar7 = (byte *)0x0;
      uVar8 = 1;
      bVar12 = false;
      pbVar3 = param_1;
      do {
        pbVar9 = pbVar3 + 1;
        uVar6 = (uint)*pbVar3;
        pbVar4 = pbVar3;
        if (uVar6 == 0x2a) {
          if (param_2 + -1 == pbVar7) {
            uVar6 = 1;
          }
          else {
            uVar6 = (uint)(*pbVar9 == 0x2e);
          }
          if ((((pbVar11 != (byte *)0x0) || (bVar12 || iVar10 != 0)) ||
              (((param_5 & 4) != 0 && (uVar6 <= (uVar8 & 1 ^ 1))))) ||
             ((uVar8 & 1) == 0 && uVar6 == 0)) goto LAB_0017599a;
          uVar8 = uVar8 & 0xfffffffe;
          iVar10 = 0;
          pbVar11 = pbVar3;
        }
        else if (((uVar6 & 0xffffffdf) - 0x41 < 0x1a) || (uVar6 - 0x30 < 10)) {
          if (((int)(uVar8 << 0x1f) < 0) &&
             ((3 < (uint)((int)param_2 - (int)pbVar7) &&
              (pbVar3 = (byte *)strncasecmp((char *)pbVar3,"xn--",4), pbVar3 == (byte *)0x0)))) {
            bVar12 = true;
          }
          uVar8 = 0;
          pbVar4 = pbVar3;
        }
        else if (uVar6 == 0x2e) {
          if (uVar8 != 0) goto LAB_0017599a;
          iVar10 = iVar10 + 1;
          uVar8 = 1;
          bVar12 = false;
        }
        else {
          if ((uVar6 != 0x2d) || ((int)(uVar8 << 0x1f) < 0)) goto LAB_0017599a;
          uVar8 = uVar8 | 4;
        }
        pbVar7 = pbVar7 + 1;
        pbVar3 = pbVar9;
      } while (param_2 != pbVar7);
      bVar12 = pbVar11 == (byte *)0x0;
      pbVar7 = pbVar11;
      if (!bVar12) {
        pbVar7 = (byte *)(iVar10 + -1);
      }
      bVar13 = !bVar12 && SBORROW4(iVar10,1);
      if ((bVar12 || iVar10 == 1) || (int)pbVar7 < 0 != bVar13) {
        pbVar4 = (byte *)0x1;
      }
      if ((!bVar12 && iVar10 != 1) && (int)pbVar7 < 0 == bVar13) {
        pbVar4 = (byte *)0x0;
      }
      if (uVar8 != 0) {
        pbVar4 = (byte *)((uint)pbVar4 | 1);
      }
      if (pbVar4 == (byte *)0x0) {
        param_2 = param_1 + (int)param_2;
        iVar10 = (int)pbVar11 - (int)param_1;
        pbVar7 = param_2 + (-1 - (int)pbVar11);
        if (param_4 < pbVar7 + iVar10) {
          return 0;
        }
        if (iVar10 != 0) {
          bVar2 = *param_1;
          bVar1 = *param_3;
          pbVar3 = param_3;
          do {
            uVar8 = (uint)bVar2;
            if (uVar8 == 0) {
              return 0;
            }
            param_1 = param_1 + 1;
            uVar6 = (uint)bVar1;
            if (uVar6 != uVar8) {
              if (uVar8 - 0x41 < 0x1a) {
                uVar8 = uVar8 + 0x20 & 0xff;
                if (uVar6 - 0x41 < 0x1a) goto LAB_00175a4a;
              }
              else {
                if (0x19 < uVar6 - 0x41) {
                  return 0;
                }
LAB_00175a4a:
                uVar6 = uVar6 + 0x20 & 0xff;
              }
              if (uVar6 != uVar8) {
                return 0;
              }
            }
            if (param_1 == pbVar11) {
              pbVar3 = param_3 + iVar10;
              pbVar4 = param_3 + ((int)param_4 - (int)pbVar7);
              if (pbVar7 != (byte *)0x0) goto LAB_00175a6c;
              goto LAB_00175b18;
            }
            bVar2 = *param_1;
            pbVar3 = pbVar3 + 1;
            bVar1 = *pbVar3;
          } while( true );
        }
        pbVar4 = param_3 + ((int)param_4 - (int)pbVar7);
        pbVar3 = param_3;
        if (pbVar7 == (byte *)0x0) {
          uVar8 = (uint)pbVar11[1];
LAB_00175ac8:
          if (uVar8 == 0x2e) {
            if (pbVar3 == pbVar4) {
              return 0;
            }
            uVar8 = (param_5 << 0x1c) >> 0x1f;
            if ((pbVar4 == pbVar3 + 1) && (*pbVar3 == 0x2a)) {
              return 1;
            }
          }
          else {
LAB_00175b18:
            if (((byte *)0x3 < param_4) &&
               (iVar10 = strncasecmp((char *)param_3,"xn--",4), iVar10 == 0)) {
              return 0;
            }
            if ((pbVar4 == pbVar3 + 1) && (*pbVar3 == 0x2a)) {
              return 1;
            }
            if (pbVar3 == pbVar4) {
              return 1;
            }
            uVar8 = 0;
          }
          do {
            pbVar7 = pbVar3 + 1;
            uVar5 = (uint)*pbVar3;
            uVar6 = (uVar5 & 0xffffffdf) - 0x41;
            bVar13 = 0x18 < uVar6;
            bVar12 = uVar6 == 0x19;
            if (0x19 < uVar6) {
              bVar13 = 8 < uVar5 - 0x30;
              bVar12 = uVar5 - 0x30 == 9;
            }
            if ((bVar13 && !bVar12) && (uVar5 != 0x2d)) {
              uVar6 = uVar8 ^ 1;
              if (uVar5 != 0x2e) {
                uVar6 = 1;
              }
              if (uVar6 != 0) {
                return 0;
              }
            }
            pbVar3 = pbVar7;
            if (pbVar4 == pbVar7) {
              return 1;
            }
          } while( true );
        }
LAB_00175a6c:
        uVar5 = (uint)*pbVar4;
        uVar8 = (uint)pbVar11[1];
        uVar6 = uVar8;
        pbVar7 = pbVar4;
        pbVar11 = pbVar11 + 2;
        if (uVar5 == 0) {
          return 0;
        }
        do {
          if (uVar6 != uVar5) {
            if (uVar5 - 0x41 < 0x1a) {
              uVar5 = uVar5 + 0x20 & 0xff;
              if ((uVar6 - 0x41 & 0xff) < 0x1a) goto LAB_00175ac0;
            }
            else {
              if (0x19 < (uVar6 - 0x41 & 0xff)) {
                return 0;
              }
LAB_00175ac0:
              uVar6 = uVar6 + 0x20 & 0xff;
            }
            if (uVar6 != uVar5) {
              return 0;
            }
          }
          if (pbVar11 == param_2) {
            if (iVar10 == 0) goto LAB_00175ac8;
            goto LAB_00175b18;
          }
          pbVar7 = pbVar7 + 1;
          uVar5 = (uint)*pbVar7;
          uVar6 = (uint)*pbVar11;
          pbVar11 = pbVar11 + 1;
          if (uVar5 == 0) {
            return 0;
          }
        } while( true );
      }
      goto LAB_0017599a;
    }
  }
  else {
LAB_0017599a:
    if ((((int)(param_5 << 0x10) < 0) && (param_4 < param_2)) && (*param_1 != 0)) {
      uVar6 = (param_5 << 0x1b) >> 0x1f;
      uVar8 = uVar6;
      if (*param_1 != 0x2e) {
        uVar8 = 0;
      }
      if (uVar8 == 0) {
        while( true ) {
          param_1 = param_1 + 1;
          param_2 = param_2 + -1;
          if (param_4 == param_2) break;
          uVar8 = uVar6;
          if (*param_1 != 0x2e) {
            uVar8 = 0;
          }
          if (*param_1 == 0) {
            return 0;
          }
          if (uVar8 != 0) {
            return 0;
          }
        }
        goto LAB_001759ea;
      }
    }
  }
  if (param_4 != param_2) {
    return 0;
  }
LAB_001759ea:
  if (param_2 == (byte *)0x0) {
    return 1;
  }
  uVar8 = (uint)*param_1;
  bVar1 = *param_3;
  if (uVar8 != 0) {
    param_2 = param_1 + (int)param_2;
    do {
      param_1 = param_1 + 1;
      uVar6 = (uint)bVar1;
      if (uVar8 != uVar6) {
        if (uVar8 - 0x41 < 0x1a) {
          uVar8 = uVar8 + 0x20 & 0xff;
          if (uVar6 - 0x41 < 0x1a) goto LAB_00175a42;
        }
        else {
          if (0x19 < uVar6 - 0x41) {
            return 0;
          }
LAB_00175a42:
          uVar6 = uVar6 + 0x20 & 0xff;
        }
        if (uVar6 != uVar8) {
          return 0;
        }
      }
      if (param_1 == param_2) {
        return 1;
      }
      uVar8 = (uint)*param_1;
      param_3 = param_3 + 1;
      bVar1 = *param_3;
    } while (uVar8 != 0);
  }
  return uVar8;
}

