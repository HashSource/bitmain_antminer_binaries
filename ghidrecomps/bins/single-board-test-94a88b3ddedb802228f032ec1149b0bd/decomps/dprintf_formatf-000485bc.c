
/* WARNING: Type propagation algorithm not settling */

int dprintf_formatf(undefined4 param_1,code *param_2,byte *param_3,undefined8 *param_4)

{
  byte bVar1;
  byte *__nptr;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  uint uVar10;
  byte *pbVar11;
  undefined uVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  undefined *puVar16;
  undefined *puVar17;
  undefined4 uVar18;
  int *piVar19;
  int *piVar20;
  int iVar21;
  int *piVar22;
  bool bVar23;
  bool bVar24;
  longlong lVar25;
  byte **local_f80;
  int *local_f7c;
  int local_f78;
  byte **local_f74;
  int *local_f70;
  int **local_f6c;
  uint local_f68;
  uint local_f64;
  byte *local_f4c;
  undefined4 local_f48;
  undefined4 local_f44;
  undefined4 local_f40;
  undefined4 local_f3c;
  undefined4 local_f38;
  undefined4 local_f34;
  undefined4 local_f30;
  undefined4 local_f2c;
  char local_f28 [255];
  undefined local_e29;
  byte *apbStack_e28 [128];
  int *local_c28 [5];
  uint auStack_c14 [5];
  int local_c00 [759];
  
  iVar8 = DAT_00048a28;
  piVar15 = (int *)0x0;
  piVar20 = (int *)0x0;
  local_f4c = param_3;
  local_f80 = (byte **)(&local_e29 + 1);
  while( true ) {
    pbVar11 = local_f4c;
    local_f4c = pbVar11 + 1;
    if (*pbVar11 == 0) break;
    if (*pbVar11 == 0x25) {
      if (pbVar11[1] == 0x25) {
        local_f4c = pbVar11 + 2;
      }
      else {
        piVar14 = (int *)0x0;
        piVar20 = (int *)((int)piVar20 + 1);
        piVar19 = (int *)0x0;
        piVar3 = (int *)dprintf_DollarString(local_f4c,&local_f4c);
        if (piVar3 == (int *)0x0) {
          piVar3 = piVar20;
        }
        if ((int)piVar15 < (int)piVar3) {
          piVar15 = piVar3;
        }
        piVar22 = (int *)0x0;
        pbVar11 = local_f4c;
        while( true ) {
          local_f4c = pbVar11;
          __nptr = local_f4c;
          bVar1 = *local_f4c;
          if ((0x5a < (byte)(bVar1 - 0x20)) ||
             (*(char *)((uint)(byte)(bVar1 - 0x20) + iVar8 + 0x58) == '\0')) break;
          pbVar11 = local_f4c + 1;
          switch(bVar1) {
          case 0x20:
            piVar14 = (int *)((uint)piVar14 | 1);
            break;
          case 0x23:
            piVar14 = (int *)((uint)piVar14 | 8);
            break;
          case 0x2a:
            piVar20 = (int *)((int)piVar20 + 1);
            piVar14 = (int *)((uint)piVar14 | 0x4000);
            local_f4c = pbVar11;
            piVar22 = (int *)dprintf_DollarString(pbVar11,&local_f4c);
            if (piVar22 == (int *)0x0) {
              piVar22 = piVar20;
            }
            pbVar11 = local_f4c;
            if ((int)piVar15 < (int)piVar22) {
              piVar15 = piVar22;
            }
            break;
          case 0x2b:
            piVar14 = (int *)((uint)piVar14 | 2);
            break;
          case 0x2d:
            piVar14 = (int *)((uint)piVar14 & 0xfffffeff | 4);
            break;
          case 0x2e:
            if (local_f4c[1] == 0x2a) {
              local_f4c = local_f4c + 2;
              piVar20 = (int *)((int)piVar20 + 1);
              piVar14 = (int *)((uint)piVar14 | 0x18000);
              piVar19 = (int *)dprintf_DollarString(local_f4c,&local_f4c);
              if (piVar19 == (int *)0x0) {
                piVar19 = piVar20;
              }
              pbVar11 = local_f4c;
              if ((int)piVar15 < (int)piVar19) {
                piVar15 = piVar19;
              }
            }
            else {
              piVar14 = (int *)((uint)piVar14 | 0x8000);
              local_f4c = pbVar11;
              piVar19 = (int *)strtol((char *)pbVar11,(char **)&local_f4c,10);
              pbVar11 = local_f4c;
            }
            break;
          case 0x30:
            if (-1 < (int)piVar14 << 0x1d) {
              piVar14 = (int *)((uint)piVar14 | 0x100);
            }
          case 0x31:
          case 0x32:
          case 0x33:
          case 0x34:
          case 0x35:
          case 0x36:
          case 0x37:
          case 0x38:
          case 0x39:
            local_f4c = pbVar11;
            piVar22 = (int *)strtol((char *)__nptr,(char **)&local_f4c,10);
            piVar14 = (int *)((uint)piVar14 | 0x2000);
            pbVar11 = local_f4c;
            break;
          case 0x4c:
            piVar14 = (int *)((uint)piVar14 | 0x80);
            break;
          case 0x68:
            piVar14 = (int *)((uint)piVar14 | 0x10);
            break;
          case 0x6c:
            if (-1 < (int)piVar14 << 0x1a) goto switchD_000486b2_caseD_7a;
          case 0x4f:
          case 0x71:
            piVar14 = (int *)((uint)piVar14 | 0x40);
            break;
          case 0x7a:
switchD_000486b2_caseD_7a:
            piVar14 = (int *)((uint)piVar14 | 0x20);
          }
        }
        piVar3 = (int *)((int)piVar3 + -1);
        switch(bVar1) {
        case 0x45:
          piVar14 = (int *)((uint)piVar14 | 0x41000);
          goto LAB_00048ea0;
        default:
          local_f6c = local_c28 + (int)piVar3 * 6;
          local_c28[(int)piVar3 * 6] = (int *)0x0;
          goto LAB_00048dd2;
        case 0x47:
          piVar14 = (int *)((uint)piVar14 | 0x81000);
          goto LAB_00048ea0;
        case 0x53:
          piVar14 = (int *)((uint)piVar14 | 8);
        case 0x73:
          piVar13 = (int *)0x1;
LAB_00048dc6:
          local_c28[(int)piVar3 * 6] = piVar13;
          local_f6c = local_c28 + (int)piVar3 * 6;
          goto LAB_00048dd2;
        case 0x58:
          piVar14 = (int *)((uint)piVar14 | 0x1a00);
          piVar13 = (int *)0x3;
          break;
        case 99:
          piVar14 = (int *)((uint)piVar14 | 0x20000);
          piVar13 = (int *)0x3;
          break;
        case 100:
        case 0x69:
          local_c28[(int)piVar3 * 6] = (int *)0x3;
          local_f6c = local_c28 + (int)piVar3 * 6;
          goto LAB_00048dd2;
        case 0x65:
          piVar14 = (int *)((uint)piVar14 | 0x40000);
          goto LAB_00048ea0;
        case 0x66:
          goto LAB_00048ea0;
        case 0x67:
          piVar14 = (int *)((uint)piVar14 | 0x80000);
LAB_00048ea0:
          piVar13 = (int *)0x7;
          break;
        case 0x6e:
          piVar13 = (int *)0x4;
          goto LAB_00048dc6;
        case 0x6f:
          piVar14 = (int *)((uint)piVar14 | 0x400);
          piVar13 = (int *)0x3;
          break;
        case 0x70:
          piVar13 = (int *)0x2;
          goto LAB_00048dc6;
        case 0x75:
          piVar14 = (int *)((uint)piVar14 | 0x200);
          piVar13 = (int *)0x3;
          break;
        case 0x78:
          piVar14 = (int *)((uint)piVar14 | 0xa00);
          piVar13 = (int *)0x3;
        }
        local_c28[(int)piVar3 * 6] = piVar13;
        local_f6c = local_c28 + (int)piVar3 * 6;
LAB_00048dd2:
        local_f6c[1] = piVar14;
        local_f6c[2] = piVar22;
        local_f6c[3] = piVar19;
        if ((int)piVar14 << 0x11 < 0) {
          piVar3 = (int *)((int)piVar22 + -1);
          local_f6c[2] = piVar3;
          local_c28[(int)piVar3 * 6] = (int *)0x9;
          local_c28[(int)piVar3 * 6 + 1] = (int *)0x0;
          local_c28[(int)piVar3 * 6 + 2] = (int *)0x0;
          local_c28[(int)piVar3 * 6 + 3] = (int *)0x0;
        }
        if ((int)piVar14 << 0xf < 0) {
          piVar19 = (int *)((int)piVar19 + -1);
          local_c28[(int)piVar3 * 6 + 3] = piVar19;
          local_c28[(int)piVar19 * 6 + 1] = (int *)0x0;
          local_c28[(int)piVar19 * 6] = (int *)0x9;
          local_c28[(int)piVar19 * 6 + 2] = (int *)0x0;
          local_c28[(int)piVar19 * 6 + 3] = (int *)0x0;
        }
        *local_f80 = local_f4c + 1;
        local_f4c = local_f4c;
        local_f80 = local_f80 + 1;
      }
    }
  }
  piVar20 = local_c00;
  if (0 < (int)piVar15) {
    piVar19 = (int *)0x0;
    do {
      piVar19 = (int *)((int)piVar19 + 1);
      if (((int)piVar19 < (int)piVar15) && (piVar20[-4] == 9)) {
        iVar8 = *(int *)param_4;
        param_4 = (undefined8 *)((int)param_4 + 4);
        *piVar20 = iVar8;
        piVar20[1] = iVar8 >> 0x1f;
      }
      switch(piVar20[-10]) {
      case 0:
      case 1:
      case 2:
      case 4:
        iVar8 = *(int *)param_4;
        param_4 = (undefined8 *)((int)param_4 + 4);
        piVar20[-6] = iVar8;
        break;
      case 3:
        if (((piVar20[-9] & 0x240U) == 0x240) || (uVar10 = piVar20[-9], (uVar10 & 0x40) != 0)) {
          piVar3 = (int *)((int)param_4 + 7U & 0xfffffff8);
          iVar8 = piVar3[1];
          param_4 = (undefined8 *)(piVar3 + 2);
          piVar20[-6] = *piVar3;
          piVar20[-5] = iVar8;
        }
        else if ((piVar20[-9] & 0x220U) == 0x220) {
          iVar8 = *(int *)param_4;
          param_4 = (undefined8 *)((int)param_4 + 4);
          piVar20[-5] = 0;
          piVar20[-6] = iVar8;
        }
        else if ((uVar10 & 0x20) == 0) {
          iVar8 = *(int *)param_4;
          param_4 = (undefined8 *)((int)param_4 + 4);
          if ((uVar10 & 0x200) == 0) {
            piVar20[-6] = iVar8;
            piVar20[-5] = iVar8 >> 0x1f;
          }
          else {
            piVar20[-5] = 0;
            piVar20[-6] = iVar8;
          }
        }
        else {
          iVar8 = *(int *)param_4;
          param_4 = (undefined8 *)((int)param_4 + 4);
          piVar20[-6] = iVar8;
          piVar20[-5] = iVar8 >> 0x1f;
        }
        break;
      case 7:
        puVar9 = (undefined8 *)((int)param_4 + 7U & 0xfffffff8);
        param_4 = puVar9 + 1;
        *(undefined8 *)(piVar20 + -6) = *puVar9;
        break;
      case 9:
        piVar20[-10] = 3;
      }
      piVar20 = piVar20 + 6;
    } while (piVar15 != piVar19);
  }
  bVar1 = *param_3;
  local_f80 = (byte **)DAT_00048a28;
  iVar8 = 0;
  local_f74 = (byte **)(&local_e29 + 1);
  iVar21 = 0;
  do {
    while( true ) {
      while( true ) {
        if (bVar1 == 0) {
          return iVar8;
        }
        if (bVar1 == 0x25) break;
        local_f4c = param_3;
        iVar4 = (*param_2)(bVar1,param_1);
        if (iVar4 == -1) {
          return iVar8;
        }
        param_3 = local_f4c + 1;
        bVar1 = local_f4c[1];
        iVar8 = iVar8 + 1;
      }
      local_f4c = param_3 + 1;
      if (param_3[1] != 0x25) break;
      local_f4c = param_3 + 2;
      iVar4 = (*param_2)(0x25,param_1);
      if (iVar4 == -1) {
        return iVar8;
      }
      iVar8 = iVar8 + 1;
      bVar1 = *local_f4c;
      param_3 = local_f4c;
    }
    iVar5 = dprintf_DollarString(local_f4c,&local_f4c);
    iVar4 = iVar5 + -1;
    if (iVar5 == 0) {
      iVar4 = iVar21;
    }
    local_f78 = iVar21 + 1;
    piVar15 = local_c28[iVar4 * 6 + 2];
    piVar20 = local_c28[iVar4 * 6 + 1];
    local_f70 = piVar15;
    if (((uint)piVar20 & 0x4000) != 0) {
      local_f70 = local_c28[(int)piVar15 * 6 + 4];
    }
    if (((uint)piVar20 & 0x10000) == 0) {
      if ((int)piVar20 << 0x10 < 0) {
        local_f7c = local_c28[iVar4 * 6 + 3];
      }
      else {
        local_f7c = (int *)0xffffffff;
      }
    }
    else {
      local_f78 = iVar21 + 2;
      local_f7c = local_c28[(int)local_c28[iVar4 * 6 + 3] * 6 + 4];
    }
    local_f64 = (uint)piVar20 & 8;
    iVar21 = iVar8;
    switch(local_c28[iVar4 * 6]) {
    case (int *)0x1:
      piVar15 = local_c28[iVar4 * 6 + 4];
      if (piVar15 == (int *)0x0) {
        if ((int)local_f7c < 5 && local_f7c != (int *)0xffffffff) {
          local_f7c = (int *)0x0;
          piVar15 = DAT_00049198;
        }
        else {
          piVar20 = (int *)((uint)piVar20 & 0xfffffff7);
          local_f7c = (int *)0x5;
          local_c28[iVar4 * 6 + 1] = piVar20;
          local_f64 = 0;
          piVar15 = DAT_00049190;
        }
      }
      else if (local_f7c == (int *)0xffffffff) {
        local_f7c = (int *)strlen((char *)piVar15);
      }
      iVar5 = (int)local_f70 - (int)local_f7c;
      if (local_f64 != 0) {
        iVar21 = (*param_2)(0x22,param_1);
        if (iVar21 == -1) {
          return iVar8;
        }
        piVar20 = local_c28[iVar4 * 6 + 1];
        iVar21 = iVar8 + 1;
      }
      iVar8 = iVar5;
      if ((-1 < (int)piVar20 << 0x1d) && (iVar8 = iVar5 + -1, iVar7 = iVar8, 0 < iVar5)) {
        do {
          iVar5 = (*param_2)(0x20,param_1);
          iVar8 = iVar7 + -1;
          if (iVar5 == -1) {
            return iVar21;
          }
          bVar23 = iVar7 != 0;
          iVar21 = iVar21 + 1;
          iVar7 = iVar8;
        } while (bVar23);
      }
      if ((local_f7c != (int *)0x0) && (cVar2 = *(char *)piVar15, cVar2 != '\0')) {
        iVar5 = 0;
        do {
          iVar7 = (*param_2)(cVar2,param_1);
          if (iVar7 == -1) {
            return iVar21;
          }
          bVar23 = (int)local_f7c - 1U == iVar5;
          iVar21 = iVar21 + 1;
          iVar5 = iVar5 + 1;
          if (bVar23) break;
          piVar15 = (int *)((int)piVar15 + 1);
          cVar2 = *(char *)piVar15;
        } while (cVar2 != '\0');
      }
      piVar15 = local_c28[iVar4 * 6 + 1];
      if (((int)piVar15 << 0x1d < 0) && (0 < iVar8)) {
        iVar8 = iVar8 + iVar21;
        do {
          iVar5 = (*param_2)(0x20,param_1);
          if (iVar5 == -1) {
            return iVar21;
          }
          iVar21 = iVar21 + 1;
        } while (iVar21 != iVar8);
        piVar15 = local_c28[iVar4 * 6 + 1];
      }
      if ((int)piVar15 << 0x1c < 0) {
        iVar8 = (*param_2)(0x22,param_1);
        if (iVar8 == -1) {
          return iVar21;
        }
        iVar21 = iVar21 + 1;
      }
      break;
    case (int *)0x2:
      piVar15 = local_c28[iVar4 * 6 + 4];
      if (piVar15 == (int *)0x0) {
        iVar5 = (int)local_f70 + -5;
        if (((int)piVar20 << 0x1d < 0) &&
           (iVar5 = (int)local_f70 + -6, iVar7 = iVar5, 0 < (int)local_f70 + -5)) {
          do {
            iVar21 = (*param_2)(0x20,param_1);
            iVar5 = iVar7 + -1;
            if (iVar21 == -1) {
              return iVar8;
            }
            bVar23 = iVar7 != 0;
            iVar8 = iVar8 + 1;
            iVar7 = iVar5;
            iVar21 = iVar8;
          } while (bVar23);
        }
        cVar2 = '(';
        iVar8 = DAT_0004918c - iVar21;
        do {
          iVar7 = (*param_2)(cVar2,param_1);
          if (iVar7 == -1) {
            return iVar21;
          }
          iVar21 = iVar21 + 1;
          cVar2 = *(char *)(iVar8 + iVar21);
        } while (cVar2 != '\0');
        if ((-1 < (int)local_c28[iVar4 * 6 + 1] << 0x1d) && (0 < iVar5)) {
          iVar5 = iVar5 + iVar21;
          do {
            iVar8 = (*param_2)(0x20,param_1);
            if (iVar8 == -1) {
              return iVar21;
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 != iVar5);
        }
      }
      else {
        local_f64 = 0;
        uVar10 = 0;
        bVar23 = false;
        local_f80 = (byte **)(DAT_00048d90 + 0x28);
        if (((uint)piVar20 & 0x1000) == 0) {
          local_f80 = (byte **)DAT_00048d90;
        }
        iVar21 = 0x10;
        local_f68 = 1;
LAB_00048bfe:
        lVar25 = CONCAT44(uVar10,piVar15);
        if (local_f7c == (int *)0xffffffff) {
          local_f7c = (int *)0x1;
        }
        puVar17 = &local_e29;
        if (((uint)piVar15 | uVar10) == 0) {
          iVar21 = 0;
          puVar16 = &local_e29;
        }
        else {
          do {
            uVar18 = (undefined4)((ulonglong)lVar25 >> 0x20);
            iVar5 = iVar21;
            __aeabi_uldivmod((int)lVar25,uVar18,iVar21,0);
            puVar16 = puVar17 + -1;
            *puVar17 = *(undefined *)((int)local_f80 + iVar5);
            lVar25 = __aeabi_uldivmod((int)lVar25,uVar18,iVar21,0);
            puVar17 = puVar16;
          } while (lVar25 != 0);
          iVar21 = (int)puVar16 - (int)&local_e29;
        }
        iVar5 = (int)local_f70 + iVar21;
        iVar21 = (int)local_f7c + iVar21;
        if (local_f64 == 0) {
          if (0 < iVar21) goto LAB_00048c8e;
        }
        else if (iVar21 < 1) {
          iVar5 = iVar5 + -1;
          *puVar16 = 0x30;
          puVar16 = puVar16 + -1;
        }
        else {
LAB_00048c8e:
          iVar5 = iVar5 - iVar21;
          iVar21 = iVar21 - (int)puVar16;
          puVar17 = puVar16;
          do {
            puVar16 = puVar17 + -1;
            *puVar17 = 0x30;
            puVar17 = puVar16;
          } while (0 < (int)(puVar16 + iVar21));
        }
        if (local_f68 != 0) {
          iVar5 = iVar5 + -2;
        }
        if ((bVar23) || (((uint)local_c28[iVar4 * 6 + 1] & 3) != 0)) {
          iVar5 = iVar5 + -1;
        }
        iVar7 = iVar5;
        if ((((uint)local_c28[iVar4 * 6 + 1] & 0x104) == 0) &&
           (iVar7 = iVar5 + -1, iVar21 = iVar7, 0 < iVar5)) {
          do {
            iVar5 = (*param_2)(0x20,param_1);
            iVar7 = iVar21 + -1;
            if (iVar5 == -1) {
              return iVar8;
            }
            bVar24 = iVar21 != 0;
            iVar8 = iVar8 + 1;
            iVar21 = iVar7;
          } while (bVar24);
        }
        if (bVar23) {
          iVar21 = (*param_2)(0x2d,param_1);
          if (iVar21 == -1) {
            return iVar8;
          }
LAB_00049006:
          iVar21 = iVar8 + 1;
        }
        else {
          if ((int)local_c28[iVar4 * 6 + 1] << 0x1e < 0) {
            iVar21 = (*param_2)(0x2b,param_1);
joined_r0x00049116:
            if (iVar21 == -1) {
              return iVar8;
            }
            goto LAB_00049006;
          }
          iVar21 = iVar8;
          if ((int)local_c28[iVar4 * 6 + 1] << 0x1f < 0) {
            iVar21 = (*param_2)(0x20,param_1);
            goto joined_r0x00049116;
          }
        }
        if (local_f68 != 0) {
          iVar8 = (*param_2)(0x30,param_1);
          if (iVar8 == -1) {
            return iVar21;
          }
          if ((int)local_c28[iVar4 * 6 + 1] << 0x13 < 0) {
            iVar8 = (*param_2)(0x58,param_1);
          }
          else {
            iVar8 = (*param_2)(0x78,param_1);
          }
          if (iVar8 == -1) {
            return iVar21 + 1;
          }
          iVar21 = iVar21 + 2;
        }
        iVar8 = iVar7;
        if ((((uint)local_c28[iVar4 * 6 + 1] & 0x104) == 0x100) &&
           (iVar8 = iVar7 + -1, iVar5 = iVar8, 0 < iVar7)) {
          do {
            iVar7 = (*param_2)(0x30,param_1);
            iVar8 = iVar5 + -1;
            if (iVar7 == -1) {
              return iVar21;
            }
            bVar23 = iVar5 != 0;
            iVar21 = iVar21 + 1;
            iVar5 = iVar8;
          } while (bVar23);
        }
        if (puVar16 + 1 <= &local_e29) {
          do {
            puVar16 = puVar16 + 1;
            iVar5 = (*param_2)(*puVar16,param_1);
            if (iVar5 == -1) {
              return iVar21;
            }
            iVar21 = iVar21 + 1;
          } while (puVar16 != &local_e29);
        }
        if (((int)local_c28[iVar4 * 6 + 1] << 0x1d < 0) && (0 < iVar8)) {
          iVar8 = iVar8 + iVar21;
          do {
            iVar4 = (*param_2)(0x20,param_1);
            if (iVar4 == -1) {
              return iVar21;
            }
            iVar21 = iVar21 + 1;
          } while (iVar21 != iVar8);
        }
      }
      break;
    case (int *)0x3:
      piVar15 = local_c28[iVar4 * 6 + 4];
      uVar10 = auStack_c14[iVar4 * 6];
      if (((uint)piVar20 & 0x20000) == 0) {
        if (local_f64 != 0) {
          local_f64 = 1;
        }
        if (((uint)piVar20 & 0x400) == 0) {
          if (((uint)piVar20 & 0x800) == 0) {
            if (((uint)piVar20 & 0x200) == 0) {
              local_f68 = 0;
              local_f64 = local_f68;
              if ((int)uVar10 < 0) {
                bVar23 = piVar15 != (int *)0x0;
                piVar15 = (int *)-(int)piVar15;
                uVar10 = -uVar10 - (uint)bVar23;
                iVar21 = 10;
                bVar23 = true;
              }
              else {
                iVar21 = 10;
                bVar23 = false;
              }
            }
            else {
              iVar21 = 10;
              bVar23 = false;
              local_f68 = 0;
              local_f64 = 0;
            }
          }
          else {
            local_f68 = local_f64;
            if (((uint)piVar20 & 0x1000) == 0) {
              iVar21 = 0x10;
              local_f80 = (byte **)DAT_0004919c;
              bVar23 = false;
              local_f64 = 0;
            }
            else {
              local_f80 = (byte **)DAT_00049194;
              iVar21 = 0x10;
              bVar23 = false;
              local_f64 = 0;
            }
          }
        }
        else {
          iVar21 = 8;
          local_f68 = 0;
          bVar23 = false;
        }
        goto LAB_00048bfe;
      }
      if ((-1 < (int)piVar20 << 0x1d) &&
         (local_f70 = (int *)((int)local_f70 + -1), 0 < (int)local_f70)) {
        do {
          iVar21 = (*param_2)(0x20,param_1);
          if (iVar21 == -1) {
            return iVar8;
          }
          local_f70 = (int *)((int)local_f70 + -1);
          iVar8 = iVar8 + 1;
        } while (local_f70 != (int *)0x0);
        local_f70 = (int *)0x0;
      }
      iVar21 = (*param_2)((uint)piVar15 & 0xff,param_1);
      if (iVar21 == -1) {
        return iVar8;
      }
      iVar21 = iVar8 + 1;
      if (((int)local_c28[iVar4 * 6 + 1] << 0x1d < 0) && (1 < (int)local_f70)) {
        do {
          iVar4 = (*param_2)(0x20,param_1);
          if (iVar4 == -1) {
            return iVar21;
          }
          iVar21 = iVar21 + 1;
        } while (iVar21 != iVar8 + (int)local_f70);
      }
      break;
    case (int *)0x4:
      piVar15 = local_c28[iVar4 * 6 + 4];
      if ((int)piVar20 << 0x19 < 0) {
        *piVar15 = iVar8;
        piVar15[1] = iVar8 >> 0x1f;
      }
      else if (((int)piVar20 << 0x1a < 0) || (-1 < (int)piVar20 << 0x1b)) {
        *piVar15 = iVar8;
      }
      else {
        *(short *)piVar15 = (short)iVar8;
      }
      break;
    case (int *)0x7:
      local_f44 = 0;
      local_f40 = 0;
      local_f3c = 0;
      local_f38 = 0;
      local_f34 = 0;
      local_f30 = 0;
      local_f2c = 0;
      local_f48 = 0x25;
      sVar6 = strlen((char *)&local_f48);
      iVar5 = 0x20 - sVar6;
      if (((uint)piVar20 & 0x2000) == 0) {
        if (((uint)piVar20 & 0x4000) == 0) {
          piVar15 = (int *)0xffffffff;
        }
        else {
          piVar15 = local_c28[(int)piVar15 * 6 + 4];
        }
      }
      if ((int)piVar20 << 0x10 < 0) {
        piVar19 = local_c28[iVar4 * 6 + 3];
      }
      else {
        piVar19 = (int *)0xffffffff;
        if (((uint)piVar20 & 0x10000) != 0) {
          piVar19 = local_c28[(int)local_c28[iVar4 * 6 + 3] * 6 + 4];
        }
      }
      if ((int)piVar20 << 0x1d < 0) {
        puVar17 = (undefined *)((int)&local_f48 + 2);
      }
      else {
        puVar17 = (undefined *)((int)&local_f48 + 1);
      }
      puVar16 = puVar17;
      if ((int)piVar20 << 0x1e < 0) {
        puVar16 = puVar17 + 1;
        *puVar17 = 0x2b;
      }
      puVar17 = puVar16;
      if ((int)piVar20 << 0x1f < 0) {
        puVar17 = puVar16 + 1;
        *puVar16 = 0x20;
        local_f64 = (uint)local_c28[iVar4 * 6 + 1] & 8;
      }
      puVar16 = puVar17;
      if (local_f64 != 0) {
        puVar16 = puVar17 + 1;
        *puVar17 = 0x23;
      }
      *puVar16 = 0;
      if (-1 < (int)piVar15) {
        iVar7 = curl_msnprintf(puVar16,iVar5,DAT_00048d88);
        puVar16 = puVar16 + iVar7;
        iVar5 = iVar5 - iVar7;
      }
      if (-1 < (int)piVar19) {
        iVar5 = curl_msnprintf(puVar16,iVar5,DAT_00048d8c,piVar19);
        puVar16 = puVar16 + iVar5;
      }
      piVar15 = local_c28[iVar4 * 6 + 1];
      puVar17 = puVar16;
      if ((int)piVar15 << 0x1a < 0) {
        puVar17 = puVar16 + 1;
        *puVar16 = 0x6c;
        piVar15 = local_c28[iVar4 * 6 + 1];
      }
      if ((int)piVar15 << 0xd < 0) {
        bVar23 = ((uint)piVar15 & 0x1000) == 0;
        if (bVar23) {
          piVar15 = (int *)0x65;
        }
        uVar12 = SUB41(piVar15,0);
        if (!bVar23) {
          uVar12 = 0x45;
        }
        *puVar17 = uVar12;
      }
      else if ((int)piVar15 << 0xc < 0) {
        bVar23 = ((uint)piVar15 & 0x1000) == 0;
        if (bVar23) {
          piVar15 = (int *)0x67;
        }
        uVar12 = SUB41(piVar15,0);
        if (!bVar23) {
          uVar12 = 0x47;
        }
        *puVar17 = uVar12;
      }
      else {
        *puVar17 = 0x66;
      }
      puVar17[1] = 0;
      sprintf(local_f28,(char *)&local_f48,local_c28[iVar4 * 6 + 4],auStack_c14[iVar4 * 6]);
      if (local_f28[0] != '\0') {
        cVar2 = local_f28[0];
        do {
          iVar4 = (*param_2)(cVar2,param_1);
          if (iVar4 == -1) {
            return iVar21;
          }
          iVar21 = iVar21 + 1;
          cVar2 = local_f28[iVar21 - iVar8];
        } while (cVar2 != '\0');
      }
    }
    param_3 = *local_f74;
    bVar1 = *param_3;
    iVar8 = iVar21;
    local_f74 = local_f74 + 1;
    iVar21 = local_f78;
  } while( true );
}

