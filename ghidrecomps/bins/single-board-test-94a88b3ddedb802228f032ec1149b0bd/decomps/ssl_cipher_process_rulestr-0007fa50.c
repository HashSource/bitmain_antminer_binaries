
/* WARNING: Type propagation algorithm not settling */

undefined4 ssl_cipher_process_rulestr(byte *param_1,int **param_2,int **param_3,int **param_4)

{
  int **ppiVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  size_t __n;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  byte bVar13;
  char *__s2;
  int iVar14;
  byte *__s1;
  int *piVar15;
  bool bVar16;
  bool bVar17;
  uint local_54;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  
  bVar13 = *param_1;
  local_3c = 1;
joined_r0x0007fa66:
  do {
    if (bVar13 == 0) {
      return local_3c;
    }
    if (bVar13 == 0x2d) {
      param_1 = param_1 + 1;
      iVar14 = 3;
      goto LAB_0007fac2;
    }
    if (bVar13 == 0x2b) {
      param_1 = param_1 + 1;
      iVar14 = 4;
      goto LAB_0007fac2;
    }
    if (bVar13 == 0x21) {
      param_1 = param_1 + 1;
      iVar14 = 2;
      goto LAB_0007fac2;
    }
    if (bVar13 == 0x40) {
      param_1 = param_1 + 1;
      iVar14 = 5;
      goto LAB_0007fac2;
    }
LAB_0007faa0:
    if (bVar13 != 0x3a && bVar13 != 0x20) {
      iVar14 = 1;
LAB_0007fac2:
      if (bVar13 == 0x3b || bVar13 == 0x2c) goto LAB_0007faaa;
      uVar12 = 0;
      local_40 = 0;
      local_48 = 0;
      local_4c = 0;
      local_54 = 0;
      local_44 = 0;
      __s1 = param_1;
LAB_0007fada:
      bVar13 = *__s1;
      param_1 = __s1;
      while( true ) {
        uVar5 = (uint)bVar13;
        uVar3 = uVar5 - 0x41;
        bVar17 = 0x18 < uVar3;
        bVar16 = uVar3 == 0x19;
        if (0x19 < uVar3) {
          bVar17 = 8 < uVar5 - 0x30;
          bVar16 = uVar5 - 0x30 == 9;
        }
        __n = (int)param_1 - (int)__s1;
        if (((bVar17 && !bVar16) && (0x19 < uVar5 - 0x61)) && (1 < uVar5 - 0x2d)) break;
        param_1 = param_1 + 1;
        bVar13 = *param_1;
      }
      if (__n == 0) {
        ERR_put_error(0x14,0xe6,0x118,DAT_0007fec4,0x4c7);
        param_1 = param_1 + 1;
        if (iVar14 == 5) {
LAB_0007fe22:
          ERR_put_error(0x14,0xe6,0x118,DAT_0007fec4,0x55f);
LAB_0007fe36:
          local_3c = 0;
LAB_0007fe3a:
          bVar13 = *param_1;
          if (bVar13 == 0) {
            return local_3c;
          }
          if (bVar13 == 0x20 || bVar13 == 0x3a) goto joined_r0x0007fa66;
          break;
        }
        local_3c = 0;
LAB_0007fb4e:
        bVar13 = *param_1;
        if (bVar13 == 0) {
          return local_3c;
        }
        if (bVar13 == 0x3a || bVar13 == 0x20) goto joined_r0x0007fa66;
        while ((bVar13 != 0x3b && (bVar13 != 0x2c))) {
          param_1 = param_1 + 1;
          bVar13 = *param_1;
          if (bVar13 == 0) {
            return local_3c;
          }
          if (bVar13 == 0x20 || bVar13 == 0x3a) goto joined_r0x0007fa66;
        }
        goto LAB_0007faa0;
      }
      if (iVar14 == 5) {
        if ((__n != 8) || (iVar14 = strncmp((char *)__s1,DAT_0007fec8,8), iVar14 != 0))
        goto LAB_0007fe22;
        iVar14 = ssl_cipher_strength_sort(param_2,param_3);
        if (iVar14 == 0) goto LAB_0007fe36;
        goto LAB_0007fe3a;
      }
      if (uVar5 == 0x2b) {
        param_1 = param_1 + 1;
      }
      piVar10 = *param_4;
      ppiVar1 = param_4;
      while( true ) {
        if (piVar10 == (int *)0x0) goto LAB_0007fb4e;
        __s2 = (char *)piVar10[1];
        iVar2 = strncmp((char *)__s1,__s2,__n);
        if ((iVar2 == 0) && (__s2[__n] == '\0')) break;
        ppiVar1 = ppiVar1 + 1;
        piVar10 = *ppiVar1;
      }
      uVar6 = piVar10[3];
      uVar3 = local_44;
      if (((((uVar6 != 0) &&
            ((uVar3 = uVar6, local_44 != 0 && (uVar3 = local_44 & uVar6, (local_44 & uVar6) == 0))))
           || ((local_44 = uVar3, uVar6 = piVar10[4], uVar3 = local_54, uVar6 != 0 &&
               ((uVar3 = uVar6, local_54 != 0 && (uVar3 = local_54 & uVar6, (local_54 & uVar6) == 0)
                ))))) ||
          ((local_54 = uVar3, uVar6 = piVar10[5], uVar3 = local_4c, uVar6 != 0 &&
           ((uVar3 = uVar6, local_4c != 0 && (uVar3 = local_4c & uVar6, (local_4c & uVar6) == 0)))))
          ) || ((local_4c = uVar3, uVar6 = piVar10[6], uVar3 = local_48, uVar6 != 0 &&
                ((uVar3 = uVar6, local_48 != 0 &&
                 (uVar3 = local_48 & uVar6, (local_48 & uVar6) == 0)))))) goto LAB_0007fb4e;
      local_48 = uVar3;
      uVar3 = piVar10[8];
      if ((uVar3 & 3) != 0) {
        if ((uVar12 & 3) == 0) {
          uVar12 = uVar12 | uVar3 & 3;
        }
        else {
          uVar12 = uVar12 & (uVar3 | 0xfffffffc);
          if ((uVar12 & 3) == 0) goto LAB_0007fb4e;
        }
      }
      if ((uVar3 & 0x1fc) != 0) {
        if ((uVar12 & 0x1fc) == 0) {
          uVar12 = uVar12 | uVar3 & 0x1fc;
        }
        else {
          uVar12 = uVar12 & (uVar3 | 0xfffffe03);
          if ((uVar12 & 0x1fc) == 0) goto LAB_0007fb4e;
        }
      }
      uVar3 = local_40;
      if ((((*piVar10 == 0) && (uVar6 = piVar10[7], uVar6 != 0)) && (uVar3 = uVar6, local_40 != 0))
         && (uVar3 = local_40 & uVar6, (local_40 & uVar6) == 0)) goto LAB_0007fb4e;
      local_40 = uVar3;
      __s1 = param_1;
      if (uVar5 == 0x2b) goto LAB_0007fada;
      bVar16 = iVar14 == 3;
      if (bVar16) {
        piVar10 = *param_2;
        piVar7 = *param_3;
        piVar9 = piVar7;
        piVar15 = piVar10;
      }
      else {
        piVar7 = *param_2;
        piVar9 = *param_3;
        piVar10 = piVar7;
        piVar15 = *param_3;
      }
      piVar8 = piVar9;
      if ((piVar15 != (int *)0x0) && (piVar7 != (int *)0x0)) {
        uVar3 = uVar12 & 0x1fc;
        piVar8 = piVar7;
        if (!bVar16) goto LAB_0007fd36;
LAB_0007fc7e:
        piVar7 = (int *)piVar8[4];
        iVar2 = *piVar8;
        if (uVar12 == 3) goto LAB_0007fd3e;
LAB_0007fc86:
        if ((local_40 == 0xfffffffe) && (*(int *)(iVar2 + 0x1c) == 1)) {
          uVar5 = 1;
        }
        else {
          piVar4 = piVar9;
          if ((local_44 != 0) && ((local_44 & *(uint *)(iVar2 + 0xc)) == 0)) goto LAB_0007fd26;
          if ((local_54 != 0) && ((local_54 & *(uint *)(iVar2 + 0x10)) == 0)) goto LAB_0007fd26;
          if ((local_4c != 0) && ((local_4c & *(uint *)(iVar2 + 0x14)) == 0)) goto LAB_0007fd26;
          if ((local_48 != 0) && ((local_48 & *(uint *)(iVar2 + 0x18)) == 0)) goto LAB_0007fd26;
          if ((local_40 != 0) && ((local_40 & *(uint *)(iVar2 + 0x1c)) == 0)) goto LAB_0007fd26;
          if (((uVar12 & 3) != 0) && ((uVar12 & *(uint *)(iVar2 + 0x20) & 3) == 0))
          goto LAB_0007fd26;
          uVar5 = uVar3;
          if ((uVar3 != 0) && ((uVar12 & *(uint *)(iVar2 + 0x20) & 0x1fc) == 0)) goto LAB_0007fd26;
        }
        if (iVar14 == 1) goto LAB_0007fd4a;
LAB_0007fcea:
        piVar4 = piVar9;
        if (iVar14 == 4) {
          if ((piVar8[1] != 0) && (piVar4 = piVar8, piVar8 != piVar9)) {
            iVar2 = piVar8[4];
            if (piVar8 == piVar10) {
              piVar11 = (int *)piVar8[3];
              piVar10 = piVar11;
            }
            else {
              piVar11 = (int *)piVar8[3];
            }
            if (iVar2 != 0) {
              *(int **)(iVar2 + 0xc) = piVar11;
              piVar11 = (int *)piVar8[3];
            }
            if (piVar11 != (int *)0x0) {
              piVar11[4] = iVar2;
            }
            piVar9[3] = (int)piVar8;
            piVar8[4] = (int)piVar9;
            piVar8[3] = 0;
          }
        }
        else if (iVar14 == 3) {
          if (piVar8[1] != 0) {
            if (piVar8 != piVar10) {
              iVar2 = piVar8[3];
              if (piVar8 == piVar9) {
                piVar4 = (int *)piVar8[4];
                piVar9 = piVar4;
              }
              else {
                piVar4 = (int *)piVar8[4];
              }
              if (iVar2 != 0) {
                *(int **)(iVar2 + 0x10) = piVar4;
                piVar4 = (int *)piVar8[4];
              }
              if (piVar4 != (int *)0x0) {
                piVar4[3] = iVar2;
              }
              piVar10[4] = (int)piVar8;
              piVar8[3] = (int)piVar10;
              piVar8[4] = 0;
            }
            piVar8[1] = 0;
            piVar4 = piVar9;
            piVar10 = piVar8;
          }
        }
        else {
          bVar17 = piVar8 != piVar10;
          piVar8[1] = 0;
          if (bVar17) {
            uVar5 = piVar8[3];
            piVar4 = (int *)piVar8[4];
          }
          else {
            piVar10 = (int *)piVar8[3];
            piVar4 = (int *)piVar8[4];
          }
          piVar11 = piVar10;
          if (bVar17) {
            piVar4[3] = uVar5;
            piVar11 = (int *)piVar8[3];
          }
          if (piVar8 == piVar9) {
            piVar9 = piVar4;
          }
          if (piVar11 != (int *)0x0) {
            piVar11[4] = (int)piVar4;
            piVar4 = (int *)piVar8[4];
          }
          if (piVar4 != (int *)0x0) {
            piVar4[3] = (int)piVar11;
          }
          piVar8[3] = 0;
          piVar8[4] = 0;
          piVar4 = piVar9;
        }
LAB_0007fd26:
        while (bVar17 = piVar15 != piVar8, piVar9 = piVar4, piVar8 = piVar4, bVar17) {
          while( true ) {
            piVar8 = piVar9;
            if (piVar7 == (int *)0x0) goto LAB_0007fd84;
            piVar8 = piVar7;
            if (bVar16) goto LAB_0007fc7e;
LAB_0007fd36:
            piVar7 = (int *)piVar8[3];
            iVar2 = *piVar8;
            if (uVar12 != 3) goto LAB_0007fc86;
LAB_0007fd3e:
            uVar5 = *(int *)(iVar2 + 0x20) << 0x1e;
            if (-1 < (int)uVar5) goto LAB_0007fc86;
            if (iVar14 != 1) goto LAB_0007fcea;
LAB_0007fd4a:
            piVar4 = piVar9;
            if (piVar8[1] != 0) break;
            if (piVar8 != piVar9) {
              iVar2 = piVar8[4];
              if (piVar8 == piVar10) {
                piVar4 = (int *)piVar8[3];
                piVar10 = piVar4;
              }
              else {
                piVar4 = (int *)piVar8[3];
              }
              if (iVar2 != 0) {
                *(int **)(iVar2 + 0xc) = piVar4;
                piVar4 = (int *)piVar8[3];
              }
              if (piVar4 != (int *)0x0) {
                piVar4[4] = iVar2;
              }
              piVar9[3] = (int)piVar8;
              piVar8[4] = (int)piVar9;
              piVar8[3] = 0;
            }
            piVar8[1] = 1;
            piVar9 = piVar8;
            if (piVar15 == piVar8) goto LAB_0007fd84;
          }
        }
      }
LAB_0007fd84:
      *param_2 = piVar10;
      *param_3 = piVar8;
      bVar13 = *param_1;
      goto joined_r0x0007fa66;
    }
LAB_0007faaa:
    bVar13 = param_1[1];
    param_1 = param_1 + 1;
  } while( true );
joined_r0x0007fe50:
  if ((bVar13 == 0x3b) || (bVar13 == 0x2c)) goto LAB_0007faa0;
  param_1 = param_1 + 1;
  bVar13 = *param_1;
  if (bVar13 == 0) {
    return local_3c;
  }
  if (bVar13 == 0x20 || bVar13 == 0x3a) goto joined_r0x0007fa66;
  goto joined_r0x0007fe50;
}

