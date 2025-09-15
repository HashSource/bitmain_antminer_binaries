
/* WARNING: Type propagation algorithm not settling */

undefined4 ssl_cipher_process_rulestr(byte *param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  size_t __n;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  byte bVar12;
  char *__s2;
  int iVar13;
  byte *__s1;
  int *piVar14;
  bool bVar15;
  bool bVar16;
  uint local_54;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  
  bVar12 = *param_1;
  local_3c = 1;
joined_r0x0007fa66:
  do {
    if (bVar12 == 0) {
      return local_3c;
    }
    if (bVar12 == 0x2d) {
      param_1 = param_1 + 1;
      iVar13 = 3;
      goto LAB_0007fac2;
    }
    if (bVar12 == 0x2b) {
      param_1 = param_1 + 1;
      iVar13 = 4;
      goto LAB_0007fac2;
    }
    if (bVar12 == 0x21) {
      param_1 = param_1 + 1;
      iVar13 = 2;
      goto LAB_0007fac2;
    }
    if (bVar12 == 0x40) {
      param_1 = param_1 + 1;
      iVar13 = 5;
      goto LAB_0007fac2;
    }
LAB_0007faa0:
    if (bVar12 != 0x3a && bVar12 != 0x20) {
      iVar13 = 1;
LAB_0007fac2:
      if (bVar12 == 0x3b || bVar12 == 0x2c) goto LAB_0007faaa;
      uVar11 = 0;
      local_40 = 0;
      local_48 = 0;
      local_4c = 0;
      local_54 = 0;
      local_44 = 0;
      __s1 = param_1;
LAB_0007fada:
      bVar12 = *__s1;
      param_1 = __s1;
      while( true ) {
        uVar4 = (uint)bVar12;
        uVar2 = uVar4 - 0x41;
        bVar16 = 0x18 < uVar2;
        bVar15 = uVar2 == 0x19;
        if (0x19 < uVar2) {
          bVar16 = 8 < uVar4 - 0x30;
          bVar15 = uVar4 - 0x30 == 9;
        }
        __n = (int)param_1 - (int)__s1;
        if (((bVar16 && !bVar15) && (0x19 < uVar4 - 0x61)) && (1 < uVar4 - 0x2d)) break;
        param_1 = param_1 + 1;
        bVar12 = *param_1;
      }
      if (__n == 0) {
        ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x4c7);
        param_1 = param_1 + 1;
        if (iVar13 == 5) {
LAB_0007fe22:
          ERR_put_error(0x14,0xe6,0x118,"ssl_ciph.c",0x55f);
LAB_0007fe36:
          local_3c = 0;
LAB_0007fe3a:
          bVar12 = *param_1;
          if (bVar12 == 0) {
            return local_3c;
          }
          if (bVar12 == 0x20 || bVar12 == 0x3a) goto joined_r0x0007fa66;
          break;
        }
        local_3c = 0;
LAB_0007fb4e:
        bVar12 = *param_1;
        if (bVar12 == 0) {
          return local_3c;
        }
        if (bVar12 == 0x3a || bVar12 == 0x20) goto joined_r0x0007fa66;
        while ((bVar12 != 0x3b && (bVar12 != 0x2c))) {
          param_1 = param_1 + 1;
          bVar12 = *param_1;
          if (bVar12 == 0) {
            return local_3c;
          }
          if (bVar12 == 0x20 || bVar12 == 0x3a) goto joined_r0x0007fa66;
        }
        goto LAB_0007faa0;
      }
      if (iVar13 == 5) {
        if ((__n != 8) || (iVar13 = strncmp((char *)__s1,"STRENGTH",8), iVar13 != 0))
        goto LAB_0007fe22;
        iVar13 = ssl_cipher_strength_sort(param_2,param_3);
        if (iVar13 == 0) goto LAB_0007fe36;
        goto LAB_0007fe3a;
      }
      if (uVar4 == 0x2b) {
        param_1 = param_1 + 1;
      }
      piVar8 = (int *)*param_4;
      piVar9 = param_4;
      while( true ) {
        if (piVar8 == (int *)0x0) goto LAB_0007fb4e;
        __s2 = (char *)piVar8[1];
        iVar1 = strncmp((char *)__s1,__s2,__n);
        if ((iVar1 == 0) && (__s2[__n] == '\0')) break;
        piVar9 = piVar9 + 1;
        piVar8 = (int *)*piVar9;
      }
      uVar5 = piVar8[3];
      uVar2 = local_44;
      if (((((uVar5 != 0) &&
            ((uVar2 = uVar5, local_44 != 0 && (uVar2 = local_44 & uVar5, (local_44 & uVar5) == 0))))
           || ((local_44 = uVar2, uVar5 = piVar8[4], uVar2 = local_54, uVar5 != 0 &&
               ((uVar2 = uVar5, local_54 != 0 && (uVar2 = local_54 & uVar5, (local_54 & uVar5) == 0)
                ))))) ||
          ((local_54 = uVar2, uVar5 = piVar8[5], uVar2 = local_4c, uVar5 != 0 &&
           ((uVar2 = uVar5, local_4c != 0 && (uVar2 = local_4c & uVar5, (local_4c & uVar5) == 0)))))
          ) || ((local_4c = uVar2, uVar5 = piVar8[6], uVar2 = local_48, uVar5 != 0 &&
                ((uVar2 = uVar5, local_48 != 0 &&
                 (uVar2 = local_48 & uVar5, (local_48 & uVar5) == 0)))))) goto LAB_0007fb4e;
      local_48 = uVar2;
      uVar2 = piVar8[8];
      if ((uVar2 & 3) != 0) {
        if ((uVar11 & 3) == 0) {
          uVar11 = uVar11 | uVar2 & 3;
        }
        else {
          uVar11 = uVar11 & (uVar2 | 0xfffffffc);
          if ((uVar11 & 3) == 0) goto LAB_0007fb4e;
        }
      }
      if ((uVar2 & 0x1fc) != 0) {
        if ((uVar11 & 0x1fc) == 0) {
          uVar11 = uVar11 | uVar2 & 0x1fc;
        }
        else {
          uVar11 = uVar11 & (uVar2 | 0xfffffe03);
          if ((uVar11 & 0x1fc) == 0) goto LAB_0007fb4e;
        }
      }
      uVar2 = local_40;
      if ((((*piVar8 == 0) && (uVar5 = piVar8[7], uVar5 != 0)) && (uVar2 = uVar5, local_40 != 0)) &&
         (uVar2 = local_40 & uVar5, (local_40 & uVar5) == 0)) goto LAB_0007fb4e;
      local_40 = uVar2;
      __s1 = param_1;
      if (uVar4 == 0x2b) goto LAB_0007fada;
      bVar15 = iVar13 == 3;
      if (bVar15) {
        piVar9 = (int *)*param_2;
        piVar6 = (int *)*param_3;
        piVar8 = piVar6;
        piVar14 = piVar9;
      }
      else {
        piVar6 = (int *)*param_2;
        piVar8 = (int *)*param_3;
        piVar9 = piVar6;
        piVar14 = (int *)*param_3;
      }
      piVar7 = piVar8;
      if ((piVar14 != (int *)0x0) && (piVar6 != (int *)0x0)) {
        uVar2 = uVar11 & 0x1fc;
        piVar7 = piVar6;
        if (!bVar15) goto LAB_0007fd36;
LAB_0007fc7e:
        piVar6 = (int *)piVar7[4];
        iVar1 = *piVar7;
        if (uVar11 == 3) goto LAB_0007fd3e;
LAB_0007fc86:
        if ((local_40 == 0xfffffffe) && (*(int *)(iVar1 + 0x1c) == 1)) {
          uVar4 = 1;
        }
        else {
          piVar3 = piVar8;
          if ((local_44 != 0) && ((local_44 & *(uint *)(iVar1 + 0xc)) == 0)) goto LAB_0007fd26;
          if ((local_54 != 0) && ((local_54 & *(uint *)(iVar1 + 0x10)) == 0)) goto LAB_0007fd26;
          if ((local_4c != 0) && ((local_4c & *(uint *)(iVar1 + 0x14)) == 0)) goto LAB_0007fd26;
          if ((local_48 != 0) && ((local_48 & *(uint *)(iVar1 + 0x18)) == 0)) goto LAB_0007fd26;
          if ((local_40 != 0) && ((local_40 & *(uint *)(iVar1 + 0x1c)) == 0)) goto LAB_0007fd26;
          if (((uVar11 & 3) != 0) && ((uVar11 & *(uint *)(iVar1 + 0x20) & 3) == 0))
          goto LAB_0007fd26;
          uVar4 = uVar2;
          if ((uVar2 != 0) && ((uVar11 & *(uint *)(iVar1 + 0x20) & 0x1fc) == 0)) goto LAB_0007fd26;
        }
        if (iVar13 == 1) goto LAB_0007fd4a;
LAB_0007fcea:
        piVar3 = piVar8;
        if (iVar13 == 4) {
          if ((piVar7[1] != 0) && (piVar3 = piVar7, piVar7 != piVar8)) {
            iVar1 = piVar7[4];
            if (piVar7 == piVar9) {
              piVar10 = (int *)piVar7[3];
              piVar9 = piVar10;
            }
            else {
              piVar10 = (int *)piVar7[3];
            }
            if (iVar1 != 0) {
              *(int **)(iVar1 + 0xc) = piVar10;
              piVar10 = (int *)piVar7[3];
            }
            if (piVar10 != (int *)0x0) {
              piVar10[4] = iVar1;
            }
            piVar8[3] = (int)piVar7;
            piVar7[4] = (int)piVar8;
            piVar7[3] = 0;
          }
        }
        else if (iVar13 == 3) {
          if (piVar7[1] != 0) {
            if (piVar7 != piVar9) {
              iVar1 = piVar7[3];
              if (piVar7 == piVar8) {
                piVar3 = (int *)piVar7[4];
                piVar8 = piVar3;
              }
              else {
                piVar3 = (int *)piVar7[4];
              }
              if (iVar1 != 0) {
                *(int **)(iVar1 + 0x10) = piVar3;
                piVar3 = (int *)piVar7[4];
              }
              if (piVar3 != (int *)0x0) {
                piVar3[3] = iVar1;
              }
              piVar9[4] = (int)piVar7;
              piVar7[3] = (int)piVar9;
              piVar7[4] = 0;
            }
            piVar7[1] = 0;
            piVar3 = piVar8;
            piVar9 = piVar7;
          }
        }
        else {
          bVar16 = piVar7 != piVar9;
          piVar7[1] = 0;
          if (bVar16) {
            uVar4 = piVar7[3];
            piVar3 = (int *)piVar7[4];
          }
          else {
            piVar9 = (int *)piVar7[3];
            piVar3 = (int *)piVar7[4];
          }
          piVar10 = piVar9;
          if (bVar16) {
            piVar3[3] = uVar4;
            piVar10 = (int *)piVar7[3];
          }
          if (piVar7 == piVar8) {
            piVar8 = piVar3;
          }
          if (piVar10 != (int *)0x0) {
            piVar10[4] = (int)piVar3;
            piVar3 = (int *)piVar7[4];
          }
          if (piVar3 != (int *)0x0) {
            piVar3[3] = (int)piVar10;
          }
          piVar7[3] = 0;
          piVar7[4] = 0;
          piVar3 = piVar8;
        }
LAB_0007fd26:
        while (bVar16 = piVar14 != piVar7, piVar8 = piVar3, piVar7 = piVar3, bVar16) {
          while( true ) {
            piVar7 = piVar8;
            if (piVar6 == (int *)0x0) goto LAB_0007fd84;
            piVar7 = piVar6;
            if (bVar15) goto LAB_0007fc7e;
LAB_0007fd36:
            piVar6 = (int *)piVar7[3];
            iVar1 = *piVar7;
            if (uVar11 != 3) goto LAB_0007fc86;
LAB_0007fd3e:
            uVar4 = *(int *)(iVar1 + 0x20) << 0x1e;
            if (-1 < (int)uVar4) goto LAB_0007fc86;
            if (iVar13 != 1) goto LAB_0007fcea;
LAB_0007fd4a:
            piVar3 = piVar8;
            if (piVar7[1] != 0) break;
            if (piVar7 != piVar8) {
              iVar1 = piVar7[4];
              if (piVar7 == piVar9) {
                piVar3 = (int *)piVar7[3];
                piVar9 = piVar3;
              }
              else {
                piVar3 = (int *)piVar7[3];
              }
              if (iVar1 != 0) {
                *(int **)(iVar1 + 0xc) = piVar3;
                piVar3 = (int *)piVar7[3];
              }
              if (piVar3 != (int *)0x0) {
                piVar3[4] = iVar1;
              }
              piVar8[3] = (int)piVar7;
              piVar7[4] = (int)piVar8;
              piVar7[3] = 0;
            }
            piVar7[1] = 1;
            piVar8 = piVar7;
            if (piVar14 == piVar7) goto LAB_0007fd84;
          }
        }
      }
LAB_0007fd84:
      *param_2 = (int)piVar9;
      *param_3 = piVar7;
      bVar12 = *param_1;
      goto joined_r0x0007fa66;
    }
LAB_0007faaa:
    bVar12 = param_1[1];
    param_1 = param_1 + 1;
  } while( true );
joined_r0x0007fe50:
  if ((bVar12 == 0x3b) || (bVar12 == 0x2c)) goto LAB_0007faa0;
  param_1 = param_1 + 1;
  bVar12 = *param_1;
  if (bVar12 == 0) {
    return local_3c;
  }
  if (bVar12 == 0x20 || bVar12 == 0x3a) goto joined_r0x0007fa66;
  goto joined_r0x0007fe50;
}

