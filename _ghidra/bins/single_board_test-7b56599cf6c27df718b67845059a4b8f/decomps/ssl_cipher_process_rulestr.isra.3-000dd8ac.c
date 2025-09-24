
undefined4
ssl_cipher_process_rulestr_isra_3
          (byte *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4,uint *param_5)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  size_t __n;
  char *__s2;
  int iVar12;
  int *piVar13;
  undefined4 uVar14;
  byte *__s1;
  int *piVar15;
  int *piVar16;
  bool bVar17;
  bool bVar18;
  uint local_50;
  int *local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  
  uVar14 = 1;
  uVar3 = (uint)*param_1;
LAB_000dd8d8:
  if (uVar3 == 0) {
    return uVar14;
  }
  while (uVar3 != 0x2d) {
    if (uVar3 == 0x2b) {
      param_1 = param_1 + 1;
      iVar10 = 4;
      goto LAB_000dd928;
    }
    if (uVar3 == 0x21) {
      param_1 = param_1 + 1;
      iVar10 = 2;
      goto LAB_000dd928;
    }
    if (uVar3 == 0x40) {
      param_1 = param_1 + 1;
      iVar10 = 5;
      goto LAB_000dd928;
    }
    if ((uVar3 != 0x20 && uVar3 != 0x3a) && (uVar3 != 0x2c && uVar3 != 0x3b)) {
      iVar10 = 1;
      goto LAB_000dd928;
    }
    uVar3 = (uint)param_1[1];
    param_1 = param_1 + 1;
    if (uVar3 == 0) {
      return uVar14;
    }
  }
  param_1 = param_1 + 1;
  iVar10 = 3;
LAB_000dd928:
  local_38 = 0;
  local_50 = 0;
  local_40 = 0;
  local_44 = 0;
  local_48 = 0;
  local_3c = 0;
  __s1 = param_1;
LAB_000dd93a:
  bVar1 = *__s1;
  param_1 = __s1;
  do {
    uVar5 = (uint)bVar1;
    uVar3 = uVar5 - 0x30;
    uVar7 = (uVar5 & 0xffffffdf) - 0x41;
    bVar18 = 8 < uVar3;
    bVar17 = uVar3 == 9;
    if (9 < uVar3) {
      bVar18 = 0x18 < uVar7;
      bVar17 = uVar7 == 0x19;
    }
    __n = (int)param_1 - (int)__s1;
    if (bVar18 && !bVar17) {
      bVar17 = 0x3c < uVar5;
      if (uVar5 != 0x3d) {
        bVar17 = uVar5 != 0x2d;
      }
      if (bVar17 && (uVar5 != 0x3d && uVar5 != 0x2e)) break;
    }
    param_1 = param_1 + 1;
    bVar1 = *param_1;
  } while( true );
  if (__n == 0) {
    ERR_put_error(0x14,0xe6,0x118,"ssl/ssl_ciph.c",0x404);
    return 0;
  }
  if (iVar10 == 5) {
    if (__n == 8) {
      iVar10 = strncmp((char *)__s1,"STRENGTH",8);
      if (iVar10 != 0) goto LAB_000ddc72;
      iVar10 = ssl_cipher_strength_sort(param_2,param_3);
      if (iVar10 != 0) goto LAB_000ddc26;
    }
    else {
      if ((__n == 10) && (iVar10 = strncmp((char *)__s1,"SECLEVEL=",9), iVar10 == 0)) {
        if (__s1[9] - 0x30 < 6) {
          *param_5 = __s1[9] - 0x30;
          goto LAB_000ddc26;
        }
        iVar10 = 0x4a1;
      }
      else {
LAB_000ddc72:
        iVar10 = 0x4a7;
      }
      ERR_put_error(0x14,0xe6,0x118,"ssl/ssl_ciph.c",iVar10);
    }
    uVar14 = 0;
LAB_000ddc26:
    uVar3 = (uint)*param_1;
    if (uVar3 == 0) {
      return uVar14;
    }
    bVar17 = uVar3 != 0x2c && uVar3 != 0x20;
    if (uVar3 - 0x3a < 2) {
      bVar17 = false;
    }
    while (bVar17) {
      param_1 = param_1 + 1;
      uVar3 = (uint)*param_1;
      bVar17 = 1 < uVar3 - 0x3a && (uVar3 != 0x20 && uVar3 != 0x2c);
      if (uVar3 == 0) {
        return uVar14;
      }
    }
    goto LAB_000dd8d8;
  }
  if (uVar5 == 0x2b) {
    param_1 = param_1 + 1;
    local_4c = (int *)0x1;
  }
  piVar11 = (int *)*param_4;
  piVar15 = param_4;
  if (uVar5 != 0x2b) {
    local_4c = (int *)0x0;
  }
  while( true ) {
    if (piVar11 == (int *)0x0) goto LAB_000dd9b0;
    __s2 = (char *)piVar11[1];
    iVar4 = strncmp((char *)__s1,__s2,__n);
    if ((iVar4 == 0) && (__s2[__n] == '\0')) break;
    piVar11 = (int *)piVar15[1];
    piVar15 = piVar15 + 1;
  }
  uVar5 = piVar11[4];
  uVar3 = local_3c;
  if (((((uVar5 != 0) &&
        ((uVar3 = uVar5, local_3c != 0 && (uVar3 = uVar5 & local_3c, (uVar5 & local_3c) == 0)))) ||
       ((local_3c = uVar3, uVar5 = piVar11[5], uVar3 = local_48, uVar5 != 0 &&
        ((uVar3 = uVar5, local_48 != 0 && (uVar3 = uVar5 & local_48, (uVar5 & local_48) == 0))))))
      || ((local_48 = uVar3, uVar5 = piVar11[6], uVar3 = local_44, uVar5 != 0 &&
          ((uVar3 = uVar5, local_44 != 0 && (uVar3 = uVar5 & local_44, (uVar5 & local_44) == 0))))))
     || ((local_44 = uVar3, uVar5 = piVar11[7], uVar3 = local_40, uVar5 != 0 &&
         ((uVar3 = uVar5, local_40 != 0 && (uVar3 = uVar5 & local_40, (uVar5 & local_40) == 0))))))
  goto LAB_000dd9b0;
  local_40 = uVar3;
  uVar5 = piVar11[0xc];
  uVar3 = uVar5 & 0x1f;
  if (uVar3 == 0) {
LAB_000dda5e:
    if ((uVar5 & 0x20) != 0) {
      if (-1 < (int)(local_50 << 0x1a)) goto LAB_000ddbd6;
      local_50 = local_50 & (uVar5 | 0xffffffdf);
      if (-1 < (int)(local_50 << 0x1a)) goto LAB_000dd9b0;
    }
  }
  else {
    if ((local_50 & 0x1f) != 0) {
      local_50 = local_50 & (uVar5 | 0xffffffe0);
      if ((local_50 & 0x1f) == 0) goto LAB_000dd9b0;
      goto LAB_000dda5e;
    }
    local_50 = uVar3;
    if ((uVar5 & 0x20) != 0) {
LAB_000ddbd6:
      local_50 = uVar5 & 0x20 | local_50;
    }
  }
  if (*piVar11 == 0) {
    iVar4 = piVar11[8];
    if (iVar4 == 0) {
      iVar12 = 0;
    }
    else {
      if (iVar4 != local_38 && local_38 != 0) {
LAB_000dd9b0:
        uVar3 = (uint)*param_1;
        if (uVar3 == 0) {
          return uVar14;
        }
        bVar17 = uVar3 != 0x20 && uVar3 != 0x2c;
        if (uVar3 - 0x3a < 2) {
          bVar17 = false;
        }
        while (bVar17) {
          param_1 = param_1 + 1;
          uVar3 = (uint)*param_1;
          bVar17 = 1 < uVar3 - 0x3a && (uVar3 != 0x2c && uVar3 != 0x20);
          if (uVar3 == 0) {
            return uVar14;
          }
        }
        goto LAB_000dd8d8;
      }
      iVar12 = 0;
      local_38 = iVar4;
    }
  }
  else {
    iVar12 = piVar11[3];
  }
  __s1 = param_1;
  if (local_4c == (int *)0x0) goto code_r0x000dda8c;
  goto LAB_000dd93a;
code_r0x000dda8c:
  if (iVar10 != 3) {
    piVar11 = (int *)*param_2;
    piVar16 = (int *)*param_3;
    piVar15 = piVar11;
    local_4c = piVar16;
  }
  else {
    piVar16 = (int *)*param_2;
    piVar11 = (int *)*param_3;
    piVar15 = piVar16;
    local_4c = piVar11;
  }
  piVar8 = (int *)0x0;
  while (piVar13 = piVar11, piVar8 != piVar16 && piVar13 != (int *)0x0) {
    piVar9 = (int *)piVar13[3];
    piVar6 = (int *)piVar13[4];
    iVar4 = *piVar13;
    piVar11 = piVar9;
    if (iVar10 == 3) {
      piVar11 = piVar6;
    }
    piVar8 = piVar13;
    if (((((((iVar12 == 0) || (iVar12 == *(int *)(iVar4 + 0xc))) &&
           ((local_3c == 0 || ((local_3c & *(uint *)(iVar4 + 0x10)) != 0)))) &&
          ((local_48 == 0 || ((local_48 & *(uint *)(iVar4 + 0x14)) != 0)))) &&
         ((local_44 == 0 || ((local_44 & *(uint *)(iVar4 + 0x18)) != 0)))) &&
        ((((local_40 == 0 || ((local_40 & *(uint *)(iVar4 + 0x1c)) != 0)) &&
          ((local_38 == 0 || (local_38 == *(int *)(iVar4 + 0x20))))) &&
         (((local_50 & 0x1f) == 0 || ((*(uint *)(iVar4 + 0x30) & 0x1f & local_50) != 0)))))) &&
       (((local_50 & 0x20) == 0 || ((*(uint *)(iVar4 + 0x30) & 0x20 & local_50) != 0)))) {
      if (iVar10 == 1) {
        if (piVar13[1] == 0) {
          if (piVar13 != local_4c) {
            if (piVar13 == piVar15) {
              piVar15 = piVar9;
            }
            if (piVar6 != (int *)0x0) {
              piVar6[3] = (int)piVar9;
              piVar9 = (int *)piVar13[3];
            }
            if (piVar9 != (int *)0x0) {
              piVar9[4] = (int)piVar6;
            }
            local_4c[3] = (int)piVar13;
            piVar13[4] = (int)local_4c;
            piVar13[3] = 0;
            local_4c = piVar13;
          }
          piVar13[1] = 1;
        }
      }
      else if (iVar10 == 4) {
        if (piVar13 != local_4c && piVar13[1] != 0) {
          if (piVar13 == piVar15) {
            piVar15 = piVar9;
          }
          if (piVar6 != (int *)0x0) {
            piVar6[3] = (int)piVar9;
            piVar9 = (int *)piVar13[3];
          }
          if (piVar9 != (int *)0x0) {
            piVar9[4] = (int)piVar6;
          }
          local_4c[3] = (int)piVar13;
          piVar13[4] = (int)local_4c;
          piVar13[3] = 0;
          local_4c = piVar13;
        }
      }
      else if (iVar10 == 3) {
        if (piVar13[1] != 0) {
          if (piVar13 != piVar15) {
            if (piVar13 == local_4c) {
              local_4c = piVar6;
            }
            if (piVar9 != (int *)0x0) {
              piVar9[4] = (int)piVar6;
              piVar6 = (int *)piVar13[4];
            }
            if (piVar6 != (int *)0x0) {
              piVar6[3] = (int)piVar9;
            }
            piVar15[4] = (int)piVar13;
            piVar13[3] = (int)piVar15;
            piVar13[4] = 0;
            piVar15 = piVar13;
          }
          piVar13[1] = 0;
        }
      }
      else {
        piVar2 = piVar9;
        if (piVar13 != piVar15) {
          piVar6[3] = (int)piVar9;
          piVar9 = piVar15;
          piVar2 = (int *)piVar13[3];
        }
        if (piVar13 == local_4c) {
          local_4c = piVar6;
        }
        piVar13[1] = 0;
        if (piVar2 != (int *)0x0) {
          piVar2[4] = (int)piVar6;
          piVar6 = (int *)piVar13[4];
        }
        if (piVar6 != (int *)0x0) {
          piVar6[3] = (int)piVar2;
        }
        piVar13[3] = 0;
        piVar13[4] = 0;
        piVar15 = piVar9;
      }
    }
  }
  *param_2 = piVar15;
  *param_3 = local_4c;
  uVar3 = (uint)*param_1;
  if (uVar3 == 0) {
    return uVar14;
  }
  goto LAB_000dd8d8;
}

