
/* WARNING: Type propagation algorithm not settling */

int dprintf_formatf(undefined4 param_1,code *param_2,byte *param_3,int *param_4)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  int iVar9;
  undefined8 *puVar10;
  size_t sVar11;
  byte *__nptr;
  int extraout_r2;
  undefined1 uVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined4 uVar20;
  uint uVar21;
  char *pcVar22;
  int *piVar23;
  undefined4 uVar24;
  uint uVar25;
  int iVar26;
  uint uVar27;
  bool bVar28;
  bool bVar29;
  longlong lVar30;
  int *local_f80;
  size_t local_f7c;
  int local_f78;
  undefined4 *local_f74;
  size_t local_f70;
  uint *local_f6c;
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
  char local_e29 [513];
  uint local_c28 [3];
  size_t local_c1c [7];
  int local_c00 [759];
  
  uVar17 = 0;
  uVar25 = 0;
  local_f4c = param_3;
  local_f80 = (int *)((int)local_e29 + 1);
  while( true ) {
    pbVar3 = local_f4c;
    local_f4c = pbVar3 + 1;
    if (*pbVar3 == 0) break;
    if (*pbVar3 == 0x25) {
      if (pbVar3[1] == 0x25) {
        local_f4c = pbVar3 + 2;
      }
      else {
        uVar15 = 0;
        uVar25 = uVar25 + 1;
        uVar21 = 0;
        uVar4 = dprintf_DollarString(local_f4c,&local_f4c);
        if (uVar4 == 0) {
          uVar4 = uVar25;
        }
        if ((int)uVar17 < (int)uVar4) {
          uVar17 = uVar4;
        }
        uVar27 = 0;
        while( true ) {
          pbVar3 = local_f4c;
          bVar1 = *local_f4c;
          if ((0x5a < (byte)(bVar1 - 0x20)) || (CSWTCH_30[(byte)(bVar1 - 0x20)] == '\0')) break;
          __nptr = local_f4c + 1;
          switch(bVar1) {
          case 0x20:
            uVar15 = uVar15 | 1;
            local_f4c = __nptr;
            break;
          default:
            local_f4c = __nptr;
            break;
          case 0x23:
            uVar15 = uVar15 | 8;
            local_f4c = __nptr;
            break;
          case 0x2a:
            uVar25 = uVar25 + 1;
            uVar15 = uVar15 | 0x4000;
            local_f4c = __nptr;
            uVar27 = dprintf_DollarString(__nptr,&local_f4c);
            if (uVar27 == 0) {
              uVar27 = uVar25;
            }
            if ((int)uVar17 < (int)uVar27) {
              uVar17 = uVar27;
            }
            break;
          case 0x2b:
            uVar15 = uVar15 | 2;
            local_f4c = __nptr;
            break;
          case 0x2d:
            uVar15 = uVar15 & 0xfffffeff | 4;
            local_f4c = __nptr;
            break;
          case 0x2e:
            if (local_f4c[1] == 0x2a) {
              local_f4c = local_f4c + 2;
              uVar25 = uVar25 + 1;
              uVar15 = uVar15 | 0x18000;
              uVar21 = dprintf_DollarString(local_f4c,&local_f4c);
              if (uVar21 == 0) {
                uVar21 = uVar25;
              }
              if ((int)uVar17 < (int)uVar21) {
                uVar17 = uVar21;
              }
            }
            else {
              uVar15 = uVar15 | 0x8000;
              local_f4c = __nptr;
              uVar21 = strtol((char *)__nptr,(char **)&local_f4c,10);
            }
            break;
          case 0x30:
            if (-1 < (int)(uVar15 << 0x1d)) {
              uVar15 = uVar15 | 0x100;
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
            local_f4c = __nptr;
            uVar27 = strtol((char *)pbVar3,(char **)&local_f4c,10);
            uVar15 = uVar15 | 0x2000;
            break;
          case 0x4c:
            uVar15 = uVar15 | 0x80;
            local_f4c = __nptr;
            break;
          case 0x68:
            uVar15 = uVar15 | 0x10;
            local_f4c = __nptr;
            break;
          case 0x6c:
            if (-1 < (int)(uVar15 << 0x1a)) goto switchD_000486b2_caseD_7a;
          case 0x4f:
          case 0x71:
            uVar15 = uVar15 | 0x40;
            local_f4c = __nptr;
            break;
          case 0x7a:
switchD_000486b2_caseD_7a:
            uVar15 = uVar15 | 0x20;
            local_f4c = __nptr;
          }
        }
        uVar4 = uVar4 - 1;
        switch(bVar1) {
        case 0x45:
          uVar15 = uVar15 | 0x41000;
          goto LAB_00048ea0;
        default:
          local_f6c = local_c28 + uVar4 * 6;
          local_c28[uVar4 * 6] = 0;
          goto LAB_00048dd2;
        case 0x47:
          uVar15 = uVar15 | 0x81000;
          goto LAB_00048ea0;
        case 0x53:
          uVar15 = uVar15 | 8;
        case 0x73:
          uVar14 = 1;
LAB_00048dc6:
          local_c28[uVar4 * 6] = uVar14;
          local_f6c = local_c28 + uVar4 * 6;
          goto LAB_00048dd2;
        case 0x58:
          uVar15 = uVar15 | 0x1a00;
          uVar14 = 3;
          break;
        case 99:
          uVar15 = uVar15 | 0x20000;
          uVar14 = 3;
          break;
        case 100:
        case 0x69:
          local_c28[uVar4 * 6] = 3;
          local_f6c = local_c28 + uVar4 * 6;
          goto LAB_00048dd2;
        case 0x65:
          uVar15 = uVar15 | 0x40000;
          goto LAB_00048ea0;
        case 0x66:
          goto LAB_00048ea0;
        case 0x67:
          uVar15 = uVar15 | 0x80000;
LAB_00048ea0:
          uVar14 = 7;
          break;
        case 0x6e:
          uVar14 = 4;
          goto LAB_00048dc6;
        case 0x6f:
          uVar15 = uVar15 | 0x400;
          uVar14 = 3;
          break;
        case 0x70:
          uVar14 = 2;
          goto LAB_00048dc6;
        case 0x75:
          uVar15 = uVar15 | 0x200;
          uVar14 = 3;
          break;
        case 0x78:
          uVar15 = uVar15 | 0xa00;
          uVar14 = 3;
        }
        local_c28[uVar4 * 6] = uVar14;
        local_f6c = local_c28 + uVar4 * 6;
LAB_00048dd2:
        local_f6c[1] = uVar15;
        local_f6c[2] = uVar27;
        local_f6c[3] = uVar21;
        if ((int)(uVar15 << 0x11) < 0) {
          uVar4 = uVar27 - 1;
          local_f6c[2] = uVar4;
          local_c28[uVar4 * 6] = 9;
          local_c28[uVar4 * 6 + 1] = 0;
          local_c1c[uVar4 * 6 + -1] = 0;
          local_c1c[uVar4 * 6] = 0;
        }
        if ((int)(uVar15 << 0xf) < 0) {
          sVar11 = uVar21 - 1;
          local_c1c[uVar4 * 6] = sVar11;
          local_c28[sVar11 * 6 + 1] = 0;
          local_c28[sVar11 * 6] = 9;
          local_c1c[sVar11 * 6 + -1] = 0;
          local_c1c[sVar11 * 6] = 0;
        }
        *local_f80 = (int)(local_f4c + 1);
        local_f4c = local_f4c;
        local_f80 = local_f80 + 1;
      }
    }
  }
  piVar13 = local_c00;
  if (0 < (int)uVar17) {
    uVar25 = 0;
    do {
      uVar25 = uVar25 + 1;
      if (((int)uVar25 < (int)uVar17) && (piVar13[-4] == 9)) {
        iVar9 = *param_4;
        param_4 = param_4 + 1;
        *piVar13 = iVar9;
        piVar13[1] = iVar9 >> 0x1f;
      }
      switch(piVar13[-10]) {
      case 0:
      case 1:
      case 2:
      case 4:
        iVar9 = *param_4;
        param_4 = param_4 + 1;
        piVar13[-6] = iVar9;
        break;
      case 3:
        if (((piVar13[-9] & 0x240U) == 0x240) || (uVar21 = piVar13[-9], (uVar21 & 0x40) != 0)) {
          piVar23 = (int *)((int)param_4 + 7U & 0xfffffff8);
          iVar9 = piVar23[1];
          param_4 = piVar23 + 2;
          piVar13[-6] = *piVar23;
          piVar13[-5] = iVar9;
        }
        else if ((piVar13[-9] & 0x220U) == 0x220) {
          iVar9 = *param_4;
          param_4 = param_4 + 1;
          piVar13[-5] = 0;
          piVar13[-6] = iVar9;
        }
        else if ((uVar21 & 0x20) == 0) {
          iVar9 = *param_4;
          param_4 = param_4 + 1;
          if ((uVar21 & 0x200) == 0) {
            piVar13[-6] = iVar9;
            piVar13[-5] = iVar9 >> 0x1f;
          }
          else {
            piVar13[-5] = 0;
            piVar13[-6] = iVar9;
          }
        }
        else {
          iVar9 = *param_4;
          param_4 = param_4 + 1;
          piVar13[-6] = iVar9;
          piVar13[-5] = iVar9 >> 0x1f;
        }
        break;
      case 7:
        puVar10 = (undefined8 *)((int)param_4 + 7U & 0xfffffff8);
        param_4 = (int *)(puVar10 + 1);
        *(undefined8 *)(piVar13 + -6) = *puVar10;
        break;
      case 9:
        piVar13[-10] = 3;
      }
      piVar13 = piVar13 + 6;
    } while (uVar17 != uVar25);
  }
  bVar1 = *param_3;
  local_f80 = (int *)0x1371cc;
  iVar9 = 0;
  local_f74 = (undefined4 *)((int)local_e29 + 1);
  iVar26 = 0;
  do {
    while( true ) {
      while( true ) {
        if (bVar1 == 0) {
          return iVar9;
        }
        if (bVar1 == 0x25) break;
        local_f4c = param_3;
        iVar5 = (*param_2)(bVar1,param_1);
        if (iVar5 == -1) {
          return iVar9;
        }
        param_3 = local_f4c + 1;
        bVar1 = local_f4c[1];
        iVar9 = iVar9 + 1;
      }
      local_f4c = param_3 + 1;
      if (param_3[1] != 0x25) break;
      local_f4c = param_3 + 2;
      iVar5 = (*param_2)(0x25,param_1);
      if (iVar5 == -1) {
        return iVar9;
      }
      iVar9 = iVar9 + 1;
      bVar1 = *local_f4c;
      param_3 = local_f4c;
    }
    iVar6 = dprintf_DollarString(local_f4c,&local_f4c);
    iVar5 = iVar6 + -1;
    if (iVar6 == 0) {
      iVar5 = iVar26;
    }
    local_f78 = iVar26 + 1;
    sVar11 = local_c1c[iVar5 * 6 + -1];
    uVar17 = local_c28[iVar5 * 6 + 1];
    local_f70 = sVar11;
    if ((uVar17 & 0x4000) != 0) {
      local_f70 = local_c1c[sVar11 * 6 + 1];
    }
    if ((uVar17 & 0x10000) == 0) {
      if ((int)(uVar17 << 0x10) < 0) {
        local_f7c = local_c1c[iVar5 * 6];
      }
      else {
        local_f7c = 0xffffffff;
      }
    }
    else {
      local_f78 = iVar26 + 2;
      local_f7c = local_c1c[local_c1c[iVar5 * 6] * 6 + 1];
    }
    local_f64 = uVar17 & 8;
    iVar26 = iVar9;
    switch(local_c28[iVar5 * 6]) {
    case 1:
      pcVar16 = (char *)local_c1c[iVar5 * 6 + 1];
      if (pcVar16 == (char *)0x0) {
        if ((int)local_f7c < 5 && local_f7c != 0xffffffff) {
          pcVar16 = "";
          local_f7c = 0;
        }
        else {
          uVar17 = uVar17 & 0xfffffff7;
          local_f7c = 5;
          local_c28[iVar5 * 6 + 1] = uVar17;
          pcVar16 = "(nil)";
          local_f64 = 0;
        }
      }
      else if (local_f7c == 0xffffffff) {
        local_f7c = strlen(pcVar16);
      }
      iVar6 = local_f70 - local_f7c;
      if (local_f64 != 0) {
        iVar26 = (*param_2)(0x22,param_1);
        if (iVar26 == -1) {
          return iVar9;
        }
        uVar17 = local_c28[iVar5 * 6 + 1];
        iVar26 = iVar9 + 1;
      }
      iVar9 = iVar6;
      if ((-1 < (int)(uVar17 << 0x1d)) && (iVar9 = iVar6 + -1, iVar8 = iVar9, 0 < iVar6)) {
        do {
          iVar6 = (*param_2)(0x20,param_1);
          iVar9 = iVar8 + -1;
          if (iVar6 == -1) {
            return iVar26;
          }
          bVar28 = iVar8 != 0;
          iVar26 = iVar26 + 1;
          iVar8 = iVar9;
        } while (bVar28);
      }
      if ((local_f7c != 0) && (cVar2 = *pcVar16, cVar2 != '\0')) {
        iVar6 = 0;
        do {
          iVar8 = (*param_2)(cVar2,param_1);
          if (iVar8 == -1) {
            return iVar26;
          }
          bVar28 = local_f7c - 1 == iVar6;
          iVar26 = iVar26 + 1;
          iVar6 = iVar6 + 1;
          if (bVar28) break;
          pcVar16 = pcVar16 + 1;
          cVar2 = *pcVar16;
        } while (cVar2 != '\0');
      }
      uVar17 = local_c28[iVar5 * 6 + 1];
      if (((int)(uVar17 << 0x1d) < 0) && (0 < iVar9)) {
        iVar9 = iVar9 + iVar26;
        do {
          iVar6 = (*param_2)(0x20,param_1);
          if (iVar6 == -1) {
            return iVar26;
          }
          iVar26 = iVar26 + 1;
        } while (iVar26 != iVar9);
        uVar17 = local_c28[iVar5 * 6 + 1];
      }
      if ((int)(uVar17 << 0x1c) < 0) {
        iVar9 = (*param_2)(0x22,param_1);
        if (iVar9 == -1) {
          return iVar26;
        }
        iVar26 = iVar26 + 1;
      }
      break;
    case 2:
      uVar25 = local_c1c[iVar5 * 6 + 1];
      if (uVar25 == 0) {
        iVar6 = local_f70 - 5;
        if (((int)(uVar17 << 0x1d) < 0) &&
           (iVar6 = local_f70 - 6, iVar26 = iVar6, 0 < (int)(local_f70 - 5))) {
          do {
            iVar8 = (*param_2)(0x20,param_1);
            iVar6 = iVar26 + -1;
            if (iVar8 == -1) {
              return iVar9;
            }
            bVar28 = iVar26 != 0;
            iVar9 = iVar9 + 1;
            iVar26 = iVar6;
          } while (bVar28);
        }
        cVar2 = '(';
        iVar26 = iVar9;
        do {
          iVar8 = (*param_2)(cVar2,param_1);
          if (iVar8 == -1) {
            return iVar26;
          }
          iVar26 = iVar26 + 1;
          cVar2 = *(char *)((int)&strnil_8335 + (iVar26 - iVar9));
        } while (cVar2 != '\0');
        if ((-1 < (int)(local_c28[iVar5 * 6 + 1] << 0x1d)) && (0 < iVar6)) {
          iVar6 = iVar6 + iVar26;
          do {
            iVar9 = (*param_2)(0x20,param_1);
            if (iVar9 == -1) {
              return iVar26;
            }
            iVar26 = iVar26 + 1;
          } while (iVar26 != iVar6);
        }
      }
      else {
        local_f64 = 0;
        sVar11 = 0;
        bVar28 = false;
        local_f80 = (int *)0x1371f4;
        if ((uVar17 & 0x1000) == 0) {
          local_f80 = (int *)0x1371cc;
        }
        uVar24 = 0x10;
        local_f68 = 1;
LAB_00048bfe:
        lVar30 = CONCAT44(sVar11,uVar25);
        if (local_f7c == 0xffffffff) {
          local_f7c = 1;
        }
        pcVar16 = local_e29;
        if (uVar25 == 0 && sVar11 == 0) {
          iVar26 = 0;
          pcVar22 = local_e29;
        }
        else {
          do {
            uVar20 = (undefined4)((ulonglong)lVar30 >> 0x20);
            __aeabi_uldivmod((int)lVar30,uVar20,uVar24,0);
            pcVar22 = pcVar16 + -1;
            *pcVar16 = *(char *)((int)local_f80 + extraout_r2);
            lVar30 = __aeabi_uldivmod((int)lVar30,uVar20,uVar24,0);
            pcVar16 = pcVar22;
          } while (lVar30 != 0);
          iVar26 = (int)pcVar22 - (int)local_e29;
        }
        iVar6 = local_f70 + iVar26;
        iVar26 = local_f7c + iVar26;
        if (local_f64 == 0) {
          if (0 < iVar26) goto LAB_00048c8e;
        }
        else if (iVar26 < 1) {
          iVar6 = iVar6 + -1;
          *pcVar22 = '0';
          pcVar22 = pcVar22 + -1;
        }
        else {
LAB_00048c8e:
          iVar6 = iVar6 - iVar26;
          iVar26 = iVar26 - (int)pcVar22;
          pcVar16 = pcVar22;
          do {
            pcVar22 = pcVar16 + -1;
            *pcVar16 = '0';
            pcVar16 = pcVar22;
          } while (0 < (int)(pcVar22 + iVar26));
        }
        if (local_f68 != 0) {
          iVar6 = iVar6 + -2;
        }
        if ((bVar28) || ((local_c28[iVar5 * 6 + 1] & 3) != 0)) {
          iVar6 = iVar6 + -1;
        }
        iVar8 = iVar6;
        if (((local_c28[iVar5 * 6 + 1] & 0x104) == 0) &&
           (iVar8 = iVar6 + -1, iVar26 = iVar8, 0 < iVar6)) {
          do {
            iVar6 = (*param_2)(0x20,param_1);
            iVar8 = iVar26 + -1;
            if (iVar6 == -1) {
              return iVar9;
            }
            bVar29 = iVar26 != 0;
            iVar9 = iVar9 + 1;
            iVar26 = iVar8;
          } while (bVar29);
        }
        if (bVar28) {
          iVar26 = (*param_2)(0x2d,param_1);
          if (iVar26 == -1) {
            return iVar9;
          }
LAB_00049006:
          iVar26 = iVar9 + 1;
        }
        else {
          if ((int)(local_c28[iVar5 * 6 + 1] << 0x1e) < 0) {
            iVar26 = (*param_2)(0x2b,param_1);
joined_r0x00049116:
            if (iVar26 == -1) {
              return iVar9;
            }
            goto LAB_00049006;
          }
          iVar26 = iVar9;
          if ((int)(local_c28[iVar5 * 6 + 1] << 0x1f) < 0) {
            iVar26 = (*param_2)(0x20,param_1);
            goto joined_r0x00049116;
          }
        }
        if (local_f68 != 0) {
          iVar9 = (*param_2)(0x30,param_1);
          if (iVar9 == -1) {
            return iVar26;
          }
          if ((int)(local_c28[iVar5 * 6 + 1] << 0x13) < 0) {
            iVar9 = (*param_2)(0x58,param_1);
          }
          else {
            iVar9 = (*param_2)(0x78,param_1);
          }
          if (iVar9 == -1) {
            return iVar26 + 1;
          }
          iVar26 = iVar26 + 2;
        }
        iVar9 = iVar8;
        if (((local_c28[iVar5 * 6 + 1] & 0x104) == 0x100) && (iVar9 = iVar8 + -1, 0 < iVar8)) {
          do {
            iVar6 = (*param_2)(0x30,param_1);
            iVar9 = iVar9 + -1;
            if (iVar6 == -1) {
              return iVar26;
            }
            iVar26 = iVar26 + 1;
          } while (iVar9 != -1);
        }
        if (pcVar22 + 1 <= local_e29) {
          do {
            pcVar22 = pcVar22 + 1;
            iVar6 = (*param_2)(*pcVar22,param_1);
            if (iVar6 == -1) {
              return iVar26;
            }
            iVar26 = iVar26 + 1;
          } while (pcVar22 != local_e29);
        }
        if (((int)(local_c28[iVar5 * 6 + 1] << 0x1d) < 0) && (0 < iVar9)) {
          iVar9 = iVar9 + iVar26;
          do {
            iVar5 = (*param_2)(0x20,param_1);
            if (iVar5 == -1) {
              return iVar26;
            }
            iVar26 = iVar26 + 1;
          } while (iVar26 != iVar9);
        }
      }
      break;
    case 3:
      uVar25 = local_c1c[iVar5 * 6 + 1];
      sVar11 = local_c1c[iVar5 * 6 + 2];
      if ((uVar17 & 0x20000) == 0) {
        if (local_f64 != 0) {
          local_f64 = 1;
        }
        if ((uVar17 & 0x400) == 0) {
          if ((uVar17 & 0x800) == 0) {
            if ((uVar17 & 0x200) == 0) {
              local_f68 = 0;
              local_f64 = local_f68;
              if ((int)sVar11 < 0) {
                bVar28 = uVar25 != 0;
                uVar25 = -uVar25;
                sVar11 = -sVar11 - (uint)bVar28;
                uVar24 = 10;
                bVar28 = true;
              }
              else {
                uVar24 = 10;
                bVar28 = false;
              }
            }
            else {
              uVar24 = 10;
              bVar28 = false;
              local_f68 = 0;
              local_f64 = 0;
            }
          }
          else {
            local_f68 = local_f64;
            if ((uVar17 & 0x1000) == 0) {
              uVar24 = 0x10;
              local_f80 = (int *)0x1371cc;
              bVar28 = false;
              local_f64 = 0;
            }
            else {
              uVar24 = 0x10;
              local_f80 = (int *)0x1371f4;
              bVar28 = false;
              local_f64 = 0;
            }
          }
        }
        else {
          uVar24 = 8;
          local_f68 = 0;
          bVar28 = false;
        }
        goto LAB_00048bfe;
      }
      if ((-1 < (int)(uVar17 << 0x1d)) && (local_f70 = local_f70 - 1, 0 < (int)local_f70)) {
        do {
          iVar26 = (*param_2)(0x20,param_1);
          if (iVar26 == -1) {
            return iVar9;
          }
          local_f70 = local_f70 - 1;
          iVar9 = iVar9 + 1;
        } while (local_f70 != 0);
        local_f70 = 0;
      }
      iVar26 = (*param_2)(uVar25 & 0xff,param_1);
      if (iVar26 == -1) {
        return iVar9;
      }
      iVar26 = iVar9 + 1;
      if (((int)(local_c28[iVar5 * 6 + 1] << 0x1d) < 0) && (1 < (int)local_f70)) {
        do {
          iVar5 = (*param_2)(0x20,param_1);
          if (iVar5 == -1) {
            return iVar26;
          }
          iVar26 = iVar26 + 1;
        } while (iVar26 != iVar9 + local_f70);
      }
      break;
    case 4:
      piVar13 = (int *)local_c1c[iVar5 * 6 + 1];
      if ((int)(uVar17 << 0x19) < 0) {
        *piVar13 = iVar9;
        piVar13[1] = iVar9 >> 0x1f;
      }
      else if (((int)(uVar17 << 0x1a) < 0) || (-1 < (int)(uVar17 << 0x1b))) {
        *piVar13 = iVar9;
      }
      else {
        *(short *)piVar13 = (short)iVar9;
      }
      break;
    case 7:
      local_f44 = 0;
      local_f40 = 0;
      local_f3c = 0;
      local_f38 = 0;
      local_f34 = 0;
      local_f30 = 0;
      local_f2c = 0;
      local_f48 = 0x25;
      sVar7 = strlen((char *)&local_f48);
      iVar6 = 0x20 - sVar7;
      if ((uVar17 & 0x2000) == 0) {
        if ((uVar17 & 0x4000) == 0) {
          sVar11 = 0xffffffff;
        }
        else {
          sVar11 = local_c1c[sVar11 * 6 + 1];
        }
      }
      if ((int)(uVar17 << 0x10) < 0) {
        sVar7 = local_c1c[iVar5 * 6];
      }
      else {
        sVar7 = 0xffffffff;
        if ((uVar17 & 0x10000) != 0) {
          sVar7 = local_c1c[local_c1c[iVar5 * 6] * 6 + 1];
        }
      }
      if ((int)(uVar17 << 0x1d) < 0) {
        puVar19 = (undefined1 *)((int)&local_f48 + 2);
        local_f48._0_2_ = CONCAT11(0x2d,(char)local_f48);
      }
      else {
        puVar19 = (undefined1 *)((int)&local_f48 + 1);
      }
      puVar18 = puVar19;
      if ((int)(uVar17 << 0x1e) < 0) {
        puVar18 = puVar19 + 1;
        *puVar19 = 0x2b;
      }
      puVar19 = puVar18;
      if ((int)(uVar17 << 0x1f) < 0) {
        puVar19 = puVar18 + 1;
        *puVar18 = 0x20;
        local_f64 = local_c28[iVar5 * 6 + 1] & 8;
      }
      puVar18 = puVar19;
      if (local_f64 != 0) {
        puVar18 = puVar19 + 1;
        *puVar19 = 0x23;
      }
      *puVar18 = 0;
      if (-1 < (int)sVar11) {
        iVar8 = curl_msnprintf(puVar18,iVar6,"%ld");
        puVar18 = puVar18 + iVar8;
        iVar6 = iVar6 - iVar8;
      }
      if (-1 < (int)sVar7) {
        iVar6 = curl_msnprintf(puVar18,iVar6,&DAT_00137288,sVar7);
        puVar18 = puVar18 + iVar6;
      }
      uVar17 = local_c28[iVar5 * 6 + 1];
      puVar19 = puVar18;
      if ((int)(uVar17 << 0x1a) < 0) {
        puVar19 = puVar18 + 1;
        *puVar18 = 0x6c;
        uVar17 = local_c28[iVar5 * 6 + 1];
      }
      if ((int)(uVar17 << 0xd) < 0) {
        bVar28 = (uVar17 & 0x1000) == 0;
        if (bVar28) {
          uVar17 = 0x65;
        }
        uVar12 = (undefined1)uVar17;
        if (!bVar28) {
          uVar12 = 0x45;
        }
        *puVar19 = uVar12;
      }
      else if ((int)(uVar17 << 0xc) < 0) {
        bVar28 = (uVar17 & 0x1000) == 0;
        if (bVar28) {
          uVar17 = 0x67;
        }
        uVar12 = (undefined1)uVar17;
        if (!bVar28) {
          uVar12 = 0x47;
        }
        *puVar19 = uVar12;
      }
      else {
        *puVar19 = 0x66;
      }
      puVar19[1] = 0;
      sprintf(local_f28,(char *)&local_f48,local_c1c[iVar5 * 6 + 1],local_c1c[iVar5 * 6 + 2]);
      if (local_f28[0] != '\0') {
        cVar2 = local_f28[0];
        do {
          iVar5 = (*param_2)(cVar2,param_1);
          if (iVar5 == -1) {
            return iVar26;
          }
          iVar26 = iVar26 + 1;
          cVar2 = local_f28[iVar26 - iVar9];
        } while (cVar2 != '\0');
      }
    }
    param_3 = (byte *)*local_f74;
    bVar1 = *param_3;
    iVar9 = iVar26;
    local_f74 = local_f74 + 1;
    iVar26 = local_f78;
  } while( true );
}

