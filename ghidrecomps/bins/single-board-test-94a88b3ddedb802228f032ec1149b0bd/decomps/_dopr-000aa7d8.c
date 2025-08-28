
void _dopr(int *param_1,int *param_2,uint *param_3,int *param_4,uint *param_5,byte *param_6,
          double *param_7)

{
  int iVar1;
  ushort **ppuVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  double *pdVar15;
  char *pcVar16;
  int iVar17;
  byte *pbVar18;
  bool bVar19;
  int iVar20;
  double dVar21;
  double dVar22;
  int local_78;
  uint local_74;
  uint local_70;
  double *local_6c;
  uint local_60;
  int local_5c;
  undefined4 local_54;
  char local_50 [19];
  char acStack_3d [25];
  
  local_6c = param_7;
  iVar17 = 0;
  uVar12 = (uint)*param_6;
  local_60 = 0xffffffff;
  local_74 = 0;
  local_70 = 0;
  local_54 = 0;
  pbVar18 = param_6 + 1;
  iVar20 = 0;
joined_r0x000aa816:
  if (uVar12 == 0) goto LAB_000aa99a;
  if ((param_2 == (int *)0x0) && (uVar6 = *param_3, uVar6 <= local_54)) goto LAB_000aa99e;
  switch(iVar17) {
  case 0:
    if (uVar12 == 0x25) {
      iVar17 = 1;
    }
    else {
      doapr_outch(param_1,param_2,&local_54,param_3,uVar12);
    }
    break;
  case 1:
    switch(uVar12) {
    case 0x20:
      local_74 = local_74 | 4;
      uVar12 = (uint)*pbVar18;
      pbVar18 = pbVar18 + 1;
      goto joined_r0x000aa816;
    default:
      iVar17 = 2;
      goto joined_r0x000aa816;
    case 0x23:
      local_74 = local_74 | 8;
      uVar12 = (uint)*pbVar18;
      pbVar18 = pbVar18 + 1;
      goto joined_r0x000aa816;
    case 0x2b:
      local_74 = local_74 | 2;
      uVar12 = (uint)*pbVar18;
      pbVar18 = pbVar18 + 1;
      goto joined_r0x000aa816;
    case 0x2d:
      local_74 = local_74 | 1;
      break;
    case 0x30:
      local_74 = local_74 | 0x10;
      uVar12 = (uint)*pbVar18;
      pbVar18 = pbVar18 + 1;
      goto joined_r0x000aa816;
    }
    break;
  case 2:
    ppuVar2 = __ctype_b_loc();
    if ((int)((uint)(*ppuVar2)[uVar12] << 0x14) < 0) {
      iVar9 = uVar12 - 0x30;
      uVar12 = (uint)*pbVar18;
      local_70 = iVar9 + local_70 * 10;
      pbVar18 = pbVar18 + 1;
    }
    else if (uVar12 == 0x2a) {
      iVar17 = 3;
      local_70 = *(uint *)local_6c;
      local_6c = (double *)((int)local_6c + 4);
      uVar12 = (uint)*pbVar18;
      pbVar18 = pbVar18 + 1;
    }
    else {
      iVar17 = 3;
    }
    goto joined_r0x000aa816;
  case 3:
    if (uVar12 != 0x2e) goto LAB_000aa9ee;
    uVar12 = (uint)*pbVar18;
    iVar17 = 4;
    pbVar18 = pbVar18 + 1;
    goto joined_r0x000aa816;
  case 4:
    ppuVar2 = __ctype_b_loc();
    if ((int)((uint)(*ppuVar2)[uVar12] << 0x14) < 0) {
      iVar9 = uVar12 - 0x30;
      uVar12 = (uint)*pbVar18;
      local_60 = iVar9 + (local_60 & ~((int)local_60 >> 0x1f)) * 10;
      pbVar18 = pbVar18 + 1;
    }
    else if (uVar12 == 0x2a) {
      iVar17 = 5;
      local_60 = *(uint *)local_6c;
      uVar12 = (uint)*pbVar18;
      pbVar18 = pbVar18 + 1;
      local_6c = (double *)((int)local_6c + 4);
    }
    else {
LAB_000aa9ee:
      iVar17 = 5;
    }
    goto joined_r0x000aa816;
  case 5:
    switch(uVar12) {
    case 0x4c:
      uVar12 = (uint)*pbVar18;
      iVar20 = 3;
      iVar17 = 6;
      pbVar18 = pbVar18 + 1;
      break;
    default:
      iVar17 = 6;
      break;
    case 0x68:
      uVar12 = (uint)*pbVar18;
      iVar20 = 1;
      iVar17 = 6;
      pbVar18 = pbVar18 + 1;
      break;
    case 0x6c:
      uVar12 = (uint)*pbVar18;
      iVar17 = 6;
      if (uVar12 == 0x6c) {
        uVar12 = (uint)pbVar18[1];
        pbVar18 = pbVar18 + 1;
        iVar20 = 4;
      }
      else {
        iVar20 = 2;
      }
      pbVar18 = pbVar18 + 1;
      break;
    case 0x71:
      uVar12 = (uint)*pbVar18;
      iVar20 = 4;
      iVar17 = 6;
      pbVar18 = pbVar18 + 1;
    }
    goto joined_r0x000aa816;
  case 6:
    switch(uVar12) {
    case 0x25:
      doapr_outch(param_1,param_2,&local_54,param_3,0x25);
      break;
    case 0x45:
    case 0x47:
    case 0x65:
    case 0x67:
      local_6c = (double *)(((int)local_6c + 7U & 0xfffffff8) + 8);
      break;
    case 0x58:
      local_74 = local_74 | 0x20;
    case 0x6f:
    case 0x75:
    case 0x78:
      if (iVar20 == 2) {
LAB_000aaa5e:
        uVar10 = 0;
        uVar6 = *(uint *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
      }
      else if (iVar20 == 4) {
        puVar11 = (uint *)((int)local_6c + 7U & 0xfffffff8);
        local_6c = (double *)(puVar11 + 2);
        uVar6 = *puVar11;
        uVar10 = puVar11[1];
      }
      else {
        if (iVar20 != 1) goto LAB_000aaa5e;
        uVar6 = (uint)*(ushort *)local_6c;
        uVar10 = 0;
        local_6c = (double *)((int)local_6c + 4);
      }
      if (uVar12 == 0x6f) {
        uVar13 = 8;
      }
      else if (uVar12 == 0x75) {
        uVar13 = 10;
      }
      else {
        uVar13 = 0x10;
      }
      fmtint(param_1,param_2,&local_54,param_3,uVar6,uVar10,uVar13,local_70,local_60,local_74 | 0x40
            );
      break;
    case 99:
      doapr_outch(param_1,param_2,&local_54,param_3,*(uint *)local_6c);
      local_6c = (double *)((int)local_6c + 4);
      break;
    case 100:
    case 0x69:
      if (iVar20 == 2) {
LAB_000aafd4:
        uVar6 = *(uint *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        uVar12 = (int)uVar6 >> 0x1f;
      }
      else if (iVar20 == 4) {
        puVar11 = (uint *)((int)local_6c + 7U & 0xfffffff8);
        local_6c = (double *)(puVar11 + 2);
        uVar6 = *puVar11;
        uVar12 = puVar11[1];
      }
      else {
        if (iVar20 != 1) goto LAB_000aafd4;
        uVar6 = (uint)(short)*(ushort *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        uVar12 = (int)uVar6 >> 0x1f;
      }
      fmtint(param_1,param_2,&local_54,param_3,uVar6,uVar12,10,local_70,local_60,local_74);
      break;
    case 0x66:
      local_6c = (double *)((int)local_6c + 7U & 0xfffffff8);
      if (iVar20 == 3) {
        dVar21 = *local_6c;
      }
      else {
        dVar21 = *local_6c;
      }
      local_6c = local_6c + 1;
      if ((int)local_60 < 0) {
        local_60 = 6;
      }
      else if (8 < (int)local_60) {
        local_60 = 9;
      }
      iVar17 = (uint)(dVar21 < 0.0) << 0x1f;
      if (iVar17 < 0) {
        dVar21 = -dVar21;
        local_78 = 1;
        local_5c = 0x2d;
      }
      else if (iVar17 < 0) {
        local_5c = 0x2d;
        local_78 = 1;
      }
      else if ((int)(local_74 << 0x1e) < 0) {
        local_5c = 0x2b;
        local_78 = 1;
      }
      else if ((local_74 & 4) == 0) {
        local_78 = 0;
        local_5c = 0;
      }
      else {
        local_5c = 0x20;
        local_78 = 1;
      }
      iVar17 = (int)(longlong)dVar21;
      if (local_60 == 0) {
        iVar20 = 1;
        dVar22 = 1.0;
      }
      else {
        dVar22 = 1.0;
        uVar12 = local_60;
        do {
          uVar12 = uVar12 - 1;
          dVar22 = dVar22 * 10.0;
        } while (uVar12 != 0);
        iVar20 = (int)(longlong)dVar22;
        if (0.5 <= dVar22 - (double)(longlong)iVar20) {
          iVar20 = iVar20 + 1;
        }
        dVar22 = 1.0;
        uVar12 = local_60;
        do {
          uVar12 = uVar12 - 1;
          dVar22 = dVar22 * 10.0;
        } while (uVar12 != 0);
      }
      dVar22 = dVar22 * (dVar21 - (double)(longlong)iVar17);
      iVar9 = (int)(longlong)dVar22;
      if (0.5 <= dVar22 - (double)(longlong)iVar9) {
        iVar9 = iVar9 + 1;
      }
      if (iVar20 <= iVar9) {
        iVar9 = iVar9 - iVar20;
        iVar17 = iVar17 + 1;
      }
      iVar20 = 0;
      do {
        iVar14 = iVar20;
        iVar20 = iVar14 + 1;
        iVar1 = iVar17 / 10;
        iVar4 = iVar1;
        if (0x13 < iVar20) {
          iVar4 = 0;
        }
        if (iVar20 == 0x13 || iVar14 + -0x12 < 0 != SBORROW4(iVar20,0x13)) {
          iVar4 = 1;
        }
        if (iVar1 == 0) {
          iVar4 = 0;
        }
        local_50[iVar14] = "0123456789"[iVar17 % 10];
        iVar17 = iVar1;
      } while (iVar4 != 0);
      if (iVar20 == 0x14) {
        iVar20 = iVar14;
      }
      local_50[iVar20] = '\0';
      iVar17 = 0;
      do {
        acStack_3d[iVar17 + 1] = "0123456789"[iVar9 % 10];
        iVar17 = iVar17 + 1;
        iVar9 = iVar9 / 10;
      } while (iVar17 < (int)local_60);
      uVar12 = local_60;
      if ((int)local_60 < 1) {
        uVar12 = 1;
      }
      acStack_3d[uVar12 + 1] = '\0';
      uVar6 = (((local_70 - iVar20) - local_60) + -1) - local_78;
      uVar10 = local_60 - uVar12 & ~((int)(local_60 - uVar12) >> 0x1f);
      uVar6 = uVar6 & ~((int)uVar6 >> 0x1f);
      if ((int)(local_74 << 0x1f) < 0) {
        uVar6 = -uVar6;
        if (-1 < (int)(local_74 << 0x1b)) goto LAB_000ab064;
LAB_000aadd2:
        if ((int)uVar6 < 1) goto LAB_000ab064;
        if (local_78 != 0) {
          doapr_outch(param_1,param_2,&local_54,param_3,local_5c);
          goto joined_r0x000ab13e;
        }
        do {
          doapr_outch_constprop_0(param_1,param_2,&local_54,param_3);
joined_r0x000ab13e:
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
        uVar6 = 0;
      }
      else {
        if ((int)(local_74 << 0x1b) < 0) goto LAB_000aadd2;
        if (0 < (int)uVar6) {
          do {
            doapr_outch_constprop_1(param_1,param_2,&local_54,param_3);
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
LAB_000ab064:
        if (local_5c != 0) {
          doapr_outch(param_1,param_2,&local_54,param_3,local_5c);
        }
      }
      if (iVar20 != 0) {
        do {
          iVar17 = iVar20 + -1;
          doapr_outch(param_1,param_2,&local_54,param_3,local_50[iVar20 + -1]);
          iVar20 = iVar17;
        } while (iVar17 != 0);
      }
      if ((local_60 != 0) || ((int)(local_74 << 0x1c) < 0)) {
        doapr_outch(param_1,param_2,&local_54,param_3,0x2e);
        do {
          uVar7 = uVar12 - 1;
          doapr_outch(param_1,param_2,&local_54,param_3,acStack_3d[uVar12]);
          uVar12 = uVar7;
        } while (uVar7 != 0);
      }
      if (uVar10 != 0) {
        do {
          doapr_outch_constprop_0(param_1,param_2,&local_54,param_3);
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      if (uVar6 != 0) {
        do {
          doapr_outch_constprop_1(param_1,param_2,&local_54,param_3);
          uVar6 = uVar6 + 1;
        } while (uVar6 != 0);
      }
      break;
    case 0x6e:
      if (iVar20 == 1) {
        **(undefined2 **)local_6c = (short)local_54;
        local_6c = (double *)((int)local_6c + 4);
      }
      else if (iVar20 == 2) {
        **(uint **)local_6c = local_54;
        local_6c = (double *)((int)local_6c + 4);
      }
      else if (iVar20 == 4) {
        puVar11 = *(uint **)local_6c;
        puVar11[1] = 0;
        *puVar11 = local_54;
        local_6c = (double *)((int)local_6c + 4);
      }
      else {
        **(uint **)local_6c = local_54;
        local_6c = (double *)((int)local_6c + 4);
      }
      break;
    case 0x70:
      fmtint(param_1,param_2,&local_54,param_3,*(uint *)local_6c,(int)*(uint *)local_6c >> 0x1f,0x10
             ,local_70,local_60,local_74 | 8);
      local_6c = (double *)((int)local_6c + 4);
      break;
    case 0x73:
      pdVar15 = (double *)((int)local_6c + 4);
      if ((int)local_60 < 0) {
        if (param_2 == (int *)0x0) {
          local_60 = *param_3;
          uVar12 = (uint)(0 < (int)local_60);
        }
        else {
          uVar12 = 1;
          local_60 = 0x7fffffff;
        }
      }
      else if ((int)local_60 < 1) {
        uVar12 = 0;
      }
      else {
        uVar12 = 1;
      }
      pcVar16 = *(char **)local_6c;
      if (*(char **)local_6c == (char *)0x0) {
        pcVar16 = "<NULL>";
      }
      cVar8 = *pcVar16;
      if (cVar8 == '\0') {
        iVar17 = 0;
      }
      else {
        iVar17 = 0;
        pcVar5 = pcVar16;
        do {
          pcVar5 = pcVar5 + 1;
          iVar17 = iVar17 + 1;
        } while (*pcVar5 != '\0');
      }
      uVar6 = local_70 - iVar17 & ~((int)(local_70 - iVar17) >> 0x1f);
      if ((int)(local_74 << 0x1f) < 0) {
        uVar6 = -uVar6;
      }
      if ((int)uVar6 < 1) {
        uVar12 = 0;
      }
      if (uVar12 != 0) {
        uVar12 = 0;
        do {
          uVar6 = uVar6 - 1;
          uVar12 = uVar12 + 1;
          doapr_outch_constprop_1(param_1,param_2,&local_54,param_3);
          bVar19 = local_60 == uVar12;
          uVar10 = local_60 - uVar12;
          if ((int)local_60 > (int)uVar12) {
            bVar19 = uVar6 == 0;
            uVar10 = uVar6;
          }
        } while (!bVar19 &&
                 (int)uVar10 < 0 == ((int)local_60 <= (int)uVar12 && SBORROW4(local_60,uVar12)));
        cVar8 = *pcVar16;
      }
      local_6c = pdVar15;
      if ((cVar8 == '\0') || ((int)local_60 <= (int)uVar12)) {
LAB_000aaf5c:
        uVar10 = uVar6 >> 0x1f;
        if ((int)local_60 <= (int)uVar12) {
          uVar10 = 0;
        }
        if (uVar10 != 0) {
          uVar10 = uVar6;
          do {
            uVar10 = uVar10 + 1;
            doapr_outch_constprop_1(param_1,param_2,&local_54,param_3);
            uVar7 = uVar10 >> 0x1f;
            if ((int)local_60 <= (int)((uVar10 - uVar6) + uVar12)) {
              uVar7 = 0;
            }
          } while (uVar7 != 0);
        }
      }
      else {
        do {
          uVar12 = uVar12 + 1;
          doapr_outch(param_1,param_2,&local_54,param_3,cVar8);
          pcVar16 = pcVar16 + 1;
          cVar8 = *pcVar16;
          if (cVar8 == '\0') goto LAB_000aaf5c;
        } while (uVar12 != local_60);
      }
      break;
    case 0x77:
      pbVar18 = pbVar18 + 1;
    }
    iVar17 = 0;
    uVar12 = (uint)*pbVar18;
    local_74 = 0;
    local_70 = 0;
    local_60 = 0xffffffff;
    pbVar18 = pbVar18 + 1;
    iVar20 = iVar17;
    goto joined_r0x000aa816;
  default:
    goto switchD_000aa828_default;
  }
  uVar12 = (uint)*pbVar18;
  pbVar18 = pbVar18 + 1;
  goto joined_r0x000aa816;
switchD_000aa828_default:
  if (iVar17 == 7) goto LAB_000aa99a;
  goto joined_r0x000aa816;
LAB_000aa99a:
  uVar6 = *param_3;
LAB_000aa99e:
  uVar12 = (uint)(uVar6 - 1 < local_54);
  *param_5 = uVar12;
  if (uVar12 == 0) {
    uVar12 = *param_3;
  }
  else {
    uVar12 = *param_3;
    local_54 = uVar12 - 1;
  }
  if ((param_2 != (int *)0x0) && (uVar12 == local_54)) {
    pvVar3 = (void *)*param_2;
    uVar12 = local_54 + 0x400;
    *param_3 = uVar12;
    if (pvVar3 == (void *)0x0) {
      pvVar3 = CRYPTO_malloc(uVar12,"b_print.c",0x2c9);
      *param_2 = (int)pvVar3;
      if (pvVar3 == (void *)0x0) goto LAB_000aa9d8;
      if (local_54 != 0) {
        memcpy(pvVar3,(void *)*param_1,local_54);
      }
      uVar12 = *param_3;
      *param_1 = 0;
    }
    else {
      pvVar3 = CRYPTO_realloc(pvVar3,uVar12,"b_print.c",0x2d4);
      *param_2 = (int)pvVar3;
      if (pvVar3 == (void *)0x0) goto LAB_000aa9d8;
      uVar12 = *param_3;
    }
  }
  if (local_54 < uVar12) {
    if (*param_1 == 0) {
      *(undefined1 *)(*param_2 + local_54) = 0;
      local_54 = local_54 + 1;
    }
    else {
      *(undefined1 *)(*param_1 + local_54) = 0;
      local_54 = local_54 + 1;
    }
  }
LAB_000aa9d8:
  *param_4 = local_54 - 1;
  return;
}

