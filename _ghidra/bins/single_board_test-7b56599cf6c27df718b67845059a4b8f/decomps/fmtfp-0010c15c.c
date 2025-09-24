
undefined4
fmtfp(int *param_1,int *param_2,uint *param_3,uint *param_4,int param_5,int param_6,uint param_7,
     uint param_8)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  double in_d0;
  double dVar17;
  uint uVar19;
  uint uVar20;
  double dVar18;
  uint local_94;
  uint local_88;
  uint local_84;
  char acStack_64 [20];
  char acStack_50 [20];
  char acStack_3c [24];
  
  if (param_6 < 0) {
    param_6 = 6;
  }
  dVar17 = in_d0;
  if ((int)((uint)(in_d0 < 0.0) << 0x1f) < 0) {
    local_84 = 0x2d;
LAB_0010c190:
    local_88 = 1;
    if (param_8 != 2) goto LAB_0010c196;
LAB_0010c424:
    if (in_d0 != 0.0) {
      iVar8 = (uint)(in_d0 < 0.0001) << 0x1f;
      if (iVar8 < 0) {
        local_94 = 1;
      }
      if (-1 < iVar8) {
        dVar18 = 10.0;
        if (param_6 != 0) {
          dVar18 = 1.0;
          iVar8 = param_6;
          do {
            iVar8 = iVar8 + -1;
            dVar18 = dVar18 * 10.0;
          } while (iVar8 != 0);
        }
        local_94 = (uint)(dVar18 <= in_d0);
      }
      goto LAB_0010c54a;
    }
    uVar15 = 0;
    local_94 = 0;
LAB_0010c438:
    if (param_6 == 0) {
      param_6 = 1;
    }
    if (local_94 == 0) {
      param_6 = param_6 - (uVar15 + 1);
      if (param_6 < 0) {
        return 0;
      }
    }
    else {
      param_6 = param_6 + -1;
LAB_0010c59e:
      if (local_94 == 1) {
        in_d0 = dVar17;
      }
    }
  }
  else {
    if ((int)(param_7 << 0x1e) < 0) {
      local_84 = 0x2b;
      goto LAB_0010c190;
    }
    local_84 = param_7 & 4;
    local_88 = local_84;
    if (local_84 != 0) {
      local_88 = 1;
      local_84 = 0x20;
    }
    if (param_8 == 2) goto LAB_0010c424;
LAB_0010c196:
    if (param_8 != 0) {
      local_94 = param_8;
      if (in_d0 == 0.0) {
        uVar15 = 0;
      }
      else {
LAB_0010c54a:
        if ((int)((uint)(in_d0 < 1.0) << 0x1f) < 0) {
          uVar15 = 0;
          do {
            dVar17 = dVar17 * 10.0;
            uVar15 = uVar15 - 1;
          } while ((int)((uint)(dVar17 < 1.0) << 0x1f) < 0);
        }
        else {
          uVar15 = 0;
        }
        for (; 10.0 < dVar17; dVar17 = dVar17 / 10.0) {
          uVar15 = uVar15 + 1;
        }
        if (param_8 == 2) goto LAB_0010c438;
      }
      goto LAB_0010c59e;
    }
    local_94 = param_8;
    uVar15 = 0;
  }
  if ((int)((uint)(in_d0 < 0.0) << 0x1f) < 0) {
    in_d0 = -in_d0;
  }
  if (4294967296.0 <= in_d0) {
    return 0;
  }
  uVar19 = (uint)(0.0 < in_d0) * (int)(longlong)in_d0;
  if (8 < param_6) {
    param_6 = 9;
  }
  if (param_6 == 0) {
    uVar4 = 1;
    dVar17 = 1.0;
  }
  else {
    if (param_6 == 1) {
      dVar17 = 10.0;
    }
    else if (param_6 == 2) {
      dVar17 = 100.0;
    }
    else if (param_6 == 3) {
      dVar17 = 1000.0;
    }
    else if (param_6 == 4) {
      dVar17 = 10000.0;
    }
    else if (param_6 == 5) {
      dVar17 = 100000.0;
    }
    else if (param_6 == 6) {
      dVar17 = 1000000.0;
    }
    else if (param_6 == 7) {
      dVar17 = 10000000.0;
    }
    else {
      dVar17 = 1000000000.0;
      if (param_6 == 8) {
        dVar17 = 100000000.0;
      }
    }
    uVar4 = (uint)(longlong)dVar17;
    dVar17 = 10.0;
    if (param_6 != 1) {
      if (param_6 == 2) {
        dVar17 = 100.0;
      }
      else if (param_6 == 3) {
        dVar17 = 1000.0;
      }
      else if (param_6 == 4) {
        dVar17 = 10000.0;
      }
      else if (param_6 == 5) {
        dVar17 = 100000.0;
      }
      else if (param_6 == 6) {
        dVar17 = 1000000.0;
      }
      else if (param_6 == 7) {
        dVar17 = 10000000.0;
      }
      else {
        dVar17 = 1000000000.0;
        if (param_6 == 8) {
          dVar17 = 100000000.0;
        }
      }
    }
  }
  dVar17 = (in_d0 - (double)uVar19) * dVar17;
  uVar20 = (uint)(longlong)dVar17;
  if (0.5 <= dVar17 - (double)(longlong)(int)uVar20) {
    uVar20 = uVar20 + 1;
  }
  bVar16 = uVar4 <= uVar20;
  if (bVar16) {
    uVar20 = uVar20 - uVar4;
  }
  iVar8 = 0;
  pcVar9 = acStack_64;
  if (bVar16) {
    uVar19 = uVar19 + 1;
  }
  do {
    iVar14 = iVar8;
    iVar8 = iVar14 + 1;
    uVar10 = uVar19 / 10;
    uVar4 = uVar10;
    if (uVar10 != 0) {
      uVar4 = 1;
    }
    if (0x13 < iVar8) {
      uVar4 = 0;
    }
    *pcVar9 = "0123456789"[uVar19 % 10];
    uVar19 = uVar10;
    pcVar9 = pcVar9 + 1;
  } while (uVar4 != 0);
  if (iVar8 == 0x14) {
    iVar8 = iVar14;
  }
  acStack_64[iVar8] = '\0';
  if (param_6 != 0) {
    iVar14 = 0;
    do {
      iVar13 = iVar14 + 1;
      if ((iVar14 == 0 && param_8 == 2) && (uVar20 % 10 == 0)) {
        param_6 = param_6 + -1;
        iVar13 = 0;
        if (param_6 == 0) goto code_r0x0010c34c;
      }
      else {
        acStack_50[iVar14] = "0123456789"[uVar20 % 10];
        if (param_6 <= iVar13) goto LAB_0010c352;
      }
      uVar20 = uVar20 / 10;
      iVar14 = iVar13;
    } while( true );
  }
  iVar13 = 0;
LAB_0010c352:
  acStack_50[iVar13] = '\0';
  if (local_94 == 1) {
    iVar11 = (uVar15 ^ (int)uVar15 >> 0x1f) - ((int)uVar15 >> 0x1f);
    iVar14 = 0;
    pcVar9 = acStack_3c;
    do {
      iVar12 = iVar14;
      iVar3 = iVar11 * 0x66666667;
      iVar14 = iVar12 + 1;
      iVar1 = iVar11 / 10;
      if (0 < iVar1) {
        iVar3 = 1;
      }
      if (iVar1 < 1) {
        iVar3 = 0;
      }
      if (0x13 < iVar14) {
        iVar3 = 0;
      }
      *pcVar9 = "0123456789"[iVar11 % 10];
      iVar11 = iVar1;
      pcVar9 = pcVar9 + 1;
    } while (iVar3 != 0);
    if (iVar1 != 0) {
      return 0;
    }
    if (iVar14 == 1) {
      iVar14 = iVar12 + 2;
      acStack_3c[1] = 0x30;
    }
    iVar11 = (param_5 - iVar8) - param_6;
    if (0 < param_6) {
      iVar11 = iVar11 + -1;
    }
    local_88 = (iVar11 - local_88) - (iVar14 + 2);
  }
  else {
    iVar14 = 0;
    iVar11 = (param_5 - iVar8) - param_6;
    if (0 < param_6) {
      iVar11 = iVar11 + -1;
    }
    local_88 = iVar11 - local_88;
  }
  local_88 = local_88 & ~((int)local_88 >> 0x1f);
  if ((int)(param_7 << 0x1f) < 0) {
    local_88 = -local_88;
LAB_0010c384:
    if (local_84 != 0) {
      if (param_2 == (int *)0x0 && *param_1 == 0) {
        return 0;
      }
      iVar11 = doapr_outch_part_0(param_1,param_2,param_3,param_4,local_84);
      if (iVar11 == 0) {
        return 0;
      }
    }
  }
  else {
    if (-1 < (int)(param_7 << 0x1b)) {
      if (0 < (int)local_88) {
        piVar5 = param_2;
        if (param_2 != (int *)0x0) {
          piVar5 = (int *)0x1;
        }
        if (param_2 == (int *)0x0 && *param_1 == 0) {
          return 0;
        }
        uVar4 = *param_3;
        uVar19 = *param_4;
        if (uVar19 < uVar4) {
          return 0;
        }
        if (uVar4 == uVar19) {
          uVar20 = (uint)piVar5 & 1;
        }
        else {
          uVar20 = 0;
        }
        if (uVar20 != 0) goto LAB_0010c65a;
LAB_0010c612:
        if (uVar19 <= uVar4) goto LAB_0010c626;
        iVar11 = *param_1;
        if (iVar11 == 0) goto LAB_0010c6c2;
        do {
          *param_3 = uVar4 + 1;
          *(undefined1 *)(iVar11 + uVar4) = 0x20;
LAB_0010c626:
          do {
            local_88 = local_88 - 1;
            if (local_88 == 0) {
              local_88 = 0;
              goto LAB_0010c384;
            }
            piVar7 = piVar5;
            if (*param_1 != 0) {
              piVar7 = (int *)((uint)piVar5 | 1);
            }
            if (piVar7 == (int *)0x0) {
              return 0;
            }
            uVar4 = *param_3;
            uVar19 = *param_4;
            if (uVar19 < uVar4) {
              return 0;
            }
            if (uVar4 == uVar19) {
              uVar20 = (uint)piVar5 & 1;
            }
            else {
              uVar20 = 0;
            }
            if (uVar20 == 0) goto LAB_0010c612;
LAB_0010c65a:
            if (0x7ffffbff < uVar19) {
              return 0;
            }
            pvVar2 = (void *)*param_2;
            uVar19 = uVar19 + 0x400;
            *param_4 = uVar19;
            if (pvVar2 != (void *)0x0) {
              pvVar2 = CRYPTO_realloc(pvVar2,uVar19,"crypto/bio/b_print.c",0x346);
              if (pvVar2 == (void *)0x0) {
                return 0;
              }
              uVar4 = *param_3;
              uVar19 = *param_4;
              *param_2 = (int)pvVar2;
              goto LAB_0010c612;
            }
            pvVar2 = CRYPTO_malloc(uVar19,"crypto/bio/b_print.c",0x33a);
            *param_2 = (int)pvVar2;
            if (pvVar2 == (void *)0x0) {
              ERR_put_error(0x20,0x96,0x41,"crypto/bio/b_print.c",0x33b);
              return 0;
            }
            uVar4 = *param_3;
            if (uVar4 != 0) {
              if ((void *)*param_1 == (void *)0x0) {
                return 0;
              }
              memcpy(pvVar2,(void *)*param_1,uVar4);
              uVar4 = *param_3;
            }
            uVar19 = *param_4;
            *param_1 = 0;
          } while (uVar19 <= uVar4);
LAB_0010c6c2:
          iVar11 = *param_2;
        } while( true );
      }
      goto LAB_0010c384;
    }
    if (local_88 == 0) goto LAB_0010c384;
    piVar5 = param_2;
    if (local_84 != 0) {
      if (param_2 != (int *)0x0) {
        piVar5 = (int *)0x1;
      }
      if (param_2 == (int *)0x0 && *param_1 == 0) {
        return 0;
      }
      iVar11 = doapr_outch_part_0(param_1,param_2,param_3,param_4,local_84);
      if (iVar11 != 0) goto joined_r0x0010c776;
      return 0;
    }
    if (param_2 != (int *)0x0) {
      piVar5 = (int *)0x1;
    }
    do {
      piVar7 = piVar5;
      if (*param_1 != 0) {
        piVar7 = (int *)((uint)piVar5 | 1);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      iVar11 = doapr_outch_part_0(param_1,param_2,param_3,param_4,0x30);
      if (iVar11 == 0) {
        return 0;
      }
joined_r0x0010c776:
      local_88 = local_88 - 1;
    } while (local_88 != 0);
    local_88 = 0;
  }
  if (iVar8 != 0) {
    piVar5 = param_2;
    if (param_2 != (int *)0x0) {
      piVar5 = (int *)0x1;
    }
    pcVar9 = acStack_64 + iVar8;
    do {
      pcVar9 = pcVar9 + -1;
      piVar7 = piVar5;
      if (*param_1 != 0) {
        piVar7 = (int *)((uint)piVar5 | 1);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,*pcVar9);
      if (iVar8 == 0) {
        return 0;
      }
    } while (pcVar9 != acStack_64);
  }
  if ((param_6 != 0) || ((int)(param_7 << 0x1c) < 0)) {
    piVar5 = param_2;
    if (param_2 != (int *)0x0) {
      piVar5 = (int *)0x1;
    }
    if (param_2 == (int *)0x0 && *param_1 == 0) {
      return 0;
    }
    iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,0x2e);
    if (iVar8 == 0) {
      return 0;
    }
    if (iVar13 != 0) {
      pcVar9 = acStack_50 + iVar13;
      do {
        pcVar9 = pcVar9 + -1;
        piVar7 = piVar5;
        if (*param_1 != 0) {
          piVar7 = (int *)((uint)piVar5 | 1);
        }
        if (piVar7 == (int *)0x0) {
          return 0;
        }
        iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,*pcVar9);
        if (iVar8 == 0) {
          return 0;
        }
      } while (pcVar9 != acStack_50);
    }
  }
  uVar19 = param_6 - iVar13 & ~(param_6 - iVar13 >> 0x1f);
  if (uVar19 != 0) {
    piVar5 = param_2;
    if (param_2 != (int *)0x0) {
      piVar5 = (int *)0x1;
    }
    do {
      piVar7 = piVar5;
      if (*param_1 != 0) {
        piVar7 = (int *)((uint)piVar5 | 1);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,0x30);
      if (iVar8 == 0) {
        return 0;
      }
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
  }
  if (local_94 != 1) {
LAB_0010c966:
    if (local_88 != 0) {
      piVar5 = param_2;
      if (param_2 != (int *)0x0) {
        piVar5 = (int *)0x1;
      }
      do {
        piVar7 = piVar5;
        if (*param_1 != 0) {
          piVar7 = (int *)((uint)piVar5 | 1);
        }
        if (piVar7 == (int *)0x0) {
          return 0;
        }
        iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,0x20);
        if (iVar8 == 0) {
          return 0;
        }
        local_88 = local_88 + 1;
      } while (local_88 != 0);
    }
    return 1;
  }
  if ((param_7 & 0x20) == 0) {
    uVar6 = 0x65;
  }
  else {
    uVar6 = 0x45;
  }
  piVar5 = param_2;
  if (param_2 != (int *)0x0) {
    piVar5 = (int *)0x1;
  }
  if ((param_2 != (int *)0x0 || *param_1 != 0) &&
     (iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,uVar6), iVar8 != 0)) {
    piVar7 = piVar5;
    if (*param_1 != 0) {
      piVar7 = (int *)((uint)piVar5 | 1);
    }
    if ((int)uVar15 < 0) {
      uVar6 = 0x2d;
    }
    else {
      uVar6 = 0x2b;
    }
    if ((piVar7 != (int *)0x0) &&
       (iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,uVar6), iVar8 != 0)) {
      pcVar9 = acStack_3c + iVar14;
      if (iVar14 != 0) {
        do {
          piVar7 = piVar5;
          if (*param_1 != 0) {
            piVar7 = (int *)((uint)piVar5 | 1);
          }
          pcVar9 = pcVar9 + -1;
          if (piVar7 == (int *)0x0) {
            return 0;
          }
          iVar8 = doapr_outch_part_0(param_1,param_2,param_3,param_4,*pcVar9);
          if (iVar8 == 0) {
            return 0;
          }
        } while (pcVar9 != acStack_3c);
      }
      goto LAB_0010c966;
    }
  }
  return 0;
code_r0x0010c34c:
  iVar13 = 0;
  goto LAB_0010c352;
}

