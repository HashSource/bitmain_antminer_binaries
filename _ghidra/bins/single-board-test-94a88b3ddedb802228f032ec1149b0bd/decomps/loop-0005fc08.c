
undefined4 loop(byte *param_1,byte *param_2)

{
  bool bVar1;
  char *__s;
  byte bVar2;
  byte bVar3;
  short sVar4;
  undefined4 *puVar5;
  int iVar6;
  ushort **ppuVar7;
  byte *pbVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  undefined4 uVar12;
  byte *pbVar13;
  uint uVar14;
  bool bVar15;
  int local_14c;
  undefined4 local_144;
  undefined4 local_140;
  undefined2 local_13c;
  char acStack_139 [46];
  undefined1 local_10b;
  undefined1 local_dd;
  undefined1 local_db;
  char local_38;
  bool local_37;
  bool local_36;
  bool local_35;
  bool local_34;
  bool local_33;
  char local_32;
  char local_31;
  bool local_30;
  char local_2f;
  char local_2e;
  
  __s = acStack_139 + 1;
  memset(__s,0,0x10f);
LAB_0005fc20:
  while( true ) {
    while( true ) {
      while( true ) {
        while (bVar2 = *param_1, bVar2 == 0x2a) {
          for (; param_1[1] == 0x2a; param_1 = param_1 + 1) {
          }
          if ((*param_2 == 0) && (param_1[1] == 0)) {
            return 0;
          }
          iVar6 = loop(param_1 + 1,param_2);
          if (iVar6 == 0) {
            return 0;
          }
          if (*param_2 == 0) {
            return 1;
          }
          param_2 = param_2 + 1;
        }
        if (bVar2 != 0x3f) break;
        ppuVar7 = __ctype_b_loc();
        if (-1 < (int)((uint)(*ppuVar7)[*param_2] << 0x11)) {
          if (*param_2 == 0) {
            return 1;
          }
          return 2;
        }
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      }
      if (bVar2 == 0) {
        if (*param_2 != 0) {
          return 1;
        }
        return 0;
      }
      if (bVar2 != 0x5c) break;
      ppuVar7 = __ctype_b_loc();
      pbVar13 = param_1 + 1;
      if (-1 < (int)((uint)(*ppuVar7)[*pbVar13] << 0x11)) {
        return 2;
      }
      bVar2 = *param_2;
      param_1 = param_1 + 2;
      param_2 = param_2 + 1;
      if ((uint)*pbVar13 != (uint)bVar2) {
        return 1;
      }
    }
    if (bVar2 == 0x5b) break;
    bVar3 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    if (bVar2 != bVar3) {
      return 1;
    }
  }
  uVar12 = 0;
  bVar15 = false;
  local_14c = 0;
  uVar9 = (uint)param_1[1];
  pbVar13 = param_1 + 1;
  uVar14 = 0;
switchD_0005fcd4_default:
  uVar11 = uVar9;
  uVar9 = uVar11;
  param_1 = pbVar13;
  switch(uVar12) {
  case 0:
    ppuVar7 = __ctype_b_loc();
    puVar10 = *ppuVar7;
    if ((puVar10[uVar11] & 8) != 0) {
      bVar2 = pbVar13[1];
      uVar12 = 1;
      __s[uVar11] = '\x01';
      bVar15 = true;
      uVar9 = (uint)bVar2;
      pbVar13 = pbVar13 + 1;
      uVar14 = uVar11;
      goto switchD_0005fcd4_default;
    }
    if (uVar11 == 0x5d) {
      if (bVar15) goto LAB_0005fee0;
      local_db = 1;
      uVar12 = 3;
      bVar15 = true;
      uVar9 = (uint)pbVar13[1];
      pbVar13 = pbVar13 + 1;
      goto switchD_0005fcd4_default;
    }
    if (uVar11 == 0x5b) {
      if (pbVar13[1] == 0x3a) {
        uVar9 = (uint)pbVar13[2];
        iVar6 = 0;
        local_144 = 0;
        local_13c = 0;
        pbVar13 = pbVar13 + 3;
        local_140 = local_144;
        do {
          pbVar8 = pbVar13;
          bVar15 = (undefined4 *)(puVar10[uVar9] & 0x600) != (undefined4 *)0x600;
          puVar5 = (undefined4 *)(puVar10[uVar9] & 0x600);
          if (!bVar15) {
            puVar5 = &local_144;
          }
          if (bVar15) {
            if (uVar9 != 0x3a) {
              return 2;
            }
          }
          else {
            *(char *)((int)puVar5 + iVar6) = (char)uVar9;
          }
          iVar6 = iVar6 + 1;
          uVar9 = (uint)*pbVar8;
          if (iVar6 == 10) {
            return 2;
          }
          pbVar13 = pbVar8 + 1;
        } while (!bVar15);
        if (uVar9 != 0x5d) {
          return 2;
        }
        iVar6 = strcmp((char *)&local_144,"digit");
        if (iVar6 == 0) {
          local_36 = bVar15;
        }
        else {
          iVar6 = strcmp((char *)&local_144,"alnum");
          if (iVar6 == 0) {
            local_37 = bVar15;
          }
          else {
            iVar6 = strcmp((char *)&local_144,"alpha");
            if (iVar6 == 0) {
              local_34 = bVar15;
            }
            else {
              iVar6 = strcmp((char *)&local_144,"xdigit");
              if (iVar6 == 0) {
                local_35 = bVar15;
              }
              else {
                iVar6 = strcmp((char *)&local_144,"print");
                if (iVar6 == 0) {
                  local_33 = bVar15;
                }
                else {
                  iVar6 = strcmp((char *)&local_144,"graph");
                  if (iVar6 == 0) {
                    local_30 = bVar15;
                  }
                  else {
                    iVar6 = strcmp((char *)&local_144,"space");
                    if (iVar6 == 0) {
                      local_2f = '\x01';
                    }
                    else {
                      iVar6 = strcmp((char *)&local_144,"blank");
                      if (iVar6 == 0) {
                        local_32 = '\x01';
                      }
                      else {
                        iVar6 = strcmp((char *)&local_144,"upper");
                        if (iVar6 == 0) {
                          local_2e = '\x01';
                        }
                        else {
                          iVar6 = strcmp((char *)&local_144,"lower");
                          if (iVar6 != 0) {
                            return 2;
                          }
                          local_31 = '\x01';
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        bVar15 = true;
        uVar9 = (uint)pbVar8[1];
      }
      else {
        local_dd = 1;
        bVar15 = true;
        uVar9 = (uint)pbVar13[1];
        pbVar13 = pbVar13 + 1;
      }
      goto switchD_0005fcd4_default;
    }
    if (uVar11 == 0x3f || uVar11 == 0x2a) {
LAB_0005fd90:
      __s[uVar11] = '\x01';
      bVar15 = true;
      uVar9 = (uint)pbVar13[1];
      pbVar13 = pbVar13 + 1;
      goto switchD_0005fcd4_default;
    }
    if (uVar11 != 0x5e && uVar11 != 0x21) {
      if (uVar11 != 0x5c) {
        if (uVar11 == 0) {
          return 2;
        }
        goto LAB_0005fd90;
      }
      uVar14 = (uint)pbVar13[1];
      if (-1 < (int)((uint)puVar10[uVar14] << 0x11)) {
        return 2;
      }
      bVar2 = pbVar13[2];
      bVar15 = true;
      uVar12 = 1;
      __s[uVar14] = '\x01';
      uVar9 = (uint)bVar2;
      pbVar13 = pbVar13 + 2;
      goto switchD_0005fcd4_default;
    }
    if (bVar15) {
      __s[uVar11] = '\x01';
    }
    else if (local_38 == '\0') {
      local_38 = '\x01';
    }
    else {
      __s[uVar11] = '\x01';
      bVar15 = true;
    }
    break;
  case 1:
    goto switchD_0005fcd4_caseD_1;
  case 2:
    if (uVar11 == 0x5c) {
      ppuVar7 = __ctype_b_loc();
      uVar11 = (uint)pbVar13[1];
      param_1 = pbVar13 + 1;
      if (-1 < (int)((uint)(*ppuVar7)[uVar11] << 0x11)) {
        return 2;
      }
      if (uVar11 == 0x5d) goto LAB_0005fee0;
      if (uVar11 == 0x5c) {
        ppuVar7 = __ctype_b_loc();
        uVar11 = (uint)pbVar13[2];
        if (-1 < (int)((uint)(*ppuVar7)[uVar11] << 0x11)) {
          return 2;
        }
        uVar12 = 0;
        __s[uVar11] = '\x01';
        param_1 = pbVar13 + 3;
      }
    }
    else if (uVar11 == 0x5d) goto LAB_0005fee0;
    if (uVar11 < uVar14) {
      uVar9 = (uint)*param_1;
      pbVar13 = param_1;
    }
    else {
      ppuVar7 = __ctype_b_loc();
      puVar10 = *ppuVar7;
      uVar9 = (uint)puVar10[uVar11];
      sVar4 = (short)uVar14;
      if (((-1 < (int)(uVar9 << 0x16)) || (-1 < (int)((uint)puVar10[sVar4] << 0x16))) &&
         ((-1 < (int)(uVar9 << 0x14) || (-1 < (int)((uint)puVar10[sVar4] << 0x14))))) {
        if (-1 < (int)(uVar9 << 0x17)) {
          return 2;
        }
        if (-1 < (int)((uint)puVar10[sVar4] << 0x17)) {
          return 2;
        }
      }
      uVar9 = uVar14 + 1;
      uVar14 = uVar14 + 2 & 0xff;
      __s[local_14c] = '\0';
      if (uVar11 < (uVar9 & 0xff)) {
        pbVar13 = param_1 + 1;
        uVar12 = 0;
        uVar9 = (uint)param_1[1];
      }
      else {
        do {
          uVar9 = uVar14 + 1 & 0xff;
          acStack_139[uVar14] = '\x01';
          bVar1 = uVar14 <= uVar11;
          uVar14 = uVar9;
        } while (bVar1);
        pbVar13 = param_1 + 1;
        uVar12 = 0;
        uVar9 = (uint)param_1[1];
      }
    }
    goto switchD_0005fcd4_default;
  case 3:
    if (uVar11 == 0x5b) goto LAB_0005fd9e;
    if (uVar11 != 0x5d) {
      if (uVar11 == 0) {
        return 2;
      }
      ppuVar7 = __ctype_b_loc();
      if (-1 < (int)((uint)(*ppuVar7)[uVar11] << 0x11)) {
        return 2;
      }
      goto LAB_0005fce4;
    }
    goto LAB_0005fee0;
  case 4:
    if (uVar11 == 0x5d) goto LAB_0005fee0;
LAB_0005fce4:
    uVar12 = 0;
    __s[uVar11] = '\x01';
    break;
  default:
    goto switchD_0005fcd4_default;
  }
  uVar9 = (uint)pbVar13[1];
  pbVar13 = pbVar13 + 1;
  goto switchD_0005fcd4_default;
LAB_0005fd9e:
  uVar12 = 4;
  local_dd = 1;
  uVar9 = (uint)pbVar13[1];
  pbVar13 = pbVar13 + 1;
  goto switchD_0005fcd4_default;
switchD_0005fcd4_caseD_1:
  if (uVar11 == 0x2d) {
    pbVar8 = pbVar13 + 1;
    local_10b = 1;
    uVar12 = 2;
    local_14c = 0x2d;
    pbVar13 = pbVar13 + 1;
    uVar9 = (uint)*pbVar8;
    goto switchD_0005fcd4_default;
  }
  if (uVar11 == 0x5b) {
    uVar12 = 0;
    goto switchD_0005fcd4_default;
  }
  ppuVar7 = __ctype_b_loc();
  if ((int)((uint)(*ppuVar7)[uVar11] << 0x1c) < 0) {
    __s[uVar11] = '\x01';
    pbVar8 = pbVar13 + 1;
    pbVar13 = pbVar13 + 1;
    uVar9 = (uint)*pbVar8;
    goto switchD_0005fcd4_default;
  }
  if (uVar11 == 0x5c) {
    pbVar8 = pbVar13 + 1;
    if (-1 < (int)((uint)(*ppuVar7)[*pbVar8] << 0x11)) {
      return 2;
    }
    bVar2 = pbVar13[2];
    pbVar13 = pbVar13 + 2;
    __s[*pbVar8] = '\x01';
    uVar9 = (uint)bVar2;
    goto switchD_0005fcd4_default;
  }
  if (uVar11 != 0x5d) {
    return 2;
  }
LAB_0005fee0:
  uVar14 = (uint)*param_2;
  if (__s[uVar14] == '\0') {
    if (local_37 == false) {
      if (local_34 == false) {
        if (local_36 == false) {
          if (local_35 == false) {
            if (local_33 == false) {
              if (local_2f == '\0') {
                if (local_2e == '\0') {
                  if (local_31 == '\0') {
                    if (local_32 == '\0') {
                      uVar9 = (uint)local_30;
                      if (uVar9 != 0) {
                        ppuVar7 = __ctype_b_loc();
                        uVar9 = (uint)((*ppuVar7)[uVar14] & 0x8000);
                      }
                    }
                    else {
                      uVar9 = (uint)(uVar14 == 0x20 || uVar14 == 9);
                    }
                  }
                  else {
                    ppuVar7 = __ctype_b_loc();
                    uVar9 = (uint)((*ppuVar7)[uVar14] & 0x200);
                  }
                }
                else {
                  ppuVar7 = __ctype_b_loc();
                  uVar9 = (uint)((*ppuVar7)[uVar14] & 0x100);
                }
              }
              else {
                ppuVar7 = __ctype_b_loc();
                uVar9 = (uint)((*ppuVar7)[uVar14] & 0x2000);
              }
            }
            else {
              ppuVar7 = __ctype_b_loc();
              uVar9 = (uint)((*ppuVar7)[uVar14] & 0x4000);
            }
          }
          else {
            ppuVar7 = __ctype_b_loc();
            uVar9 = (uint)((*ppuVar7)[uVar14] & 0x1000);
          }
        }
        else {
          ppuVar7 = __ctype_b_loc();
          uVar9 = (uint)((*ppuVar7)[uVar14] & 0x800);
        }
      }
      else {
        ppuVar7 = __ctype_b_loc();
        uVar9 = (uint)((*ppuVar7)[uVar14] & 0x400);
      }
    }
    else {
      ppuVar7 = __ctype_b_loc();
      uVar9 = (uint)((*ppuVar7)[uVar14] & 8);
    }
  }
  else {
    uVar9 = 1;
  }
  if ((local_38 != '\0') && (bVar15 = 1 < uVar9, uVar9 = 1 - uVar9, bVar15)) {
    uVar9 = 0;
  }
  if (uVar9 == 0) {
    return 1;
  }
  param_1 = param_1 + 1;
  param_2 = param_2 + 1;
  memset(__s,0,0x10f);
  goto LAB_0005fc20;
}

