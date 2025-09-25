
undefined4
fmtint(int *param_1,int *param_2,uint *param_3,uint *param_4,int param_5,int param_6,int param_7,
      int param_8,uint param_9,uint param_10)

{
  size_t sVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  int extraout_r2;
  uint __n;
  int extraout_r3;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  uint uVar9;
  char *pcVar10;
  int *piVar11;
  uint uVar12;
  char *pcVar13;
  char cVar14;
  bool bVar15;
  longlong lVar16;
  char *local_64;
  uint local_58;
  uint local_50;
  char cStack_45;
  char local_44 [32];
  
  param_9 = param_9 & ~((int)param_9 >> 0x1f);
  if ((int)(param_10 << 0x19) < 0) {
    local_58 = 0;
    local_50 = 0;
  }
  else if (param_6 < 0) {
    bVar15 = param_5 != 0;
    param_5 = -param_5;
    local_58 = 1;
    param_6 = -param_6 - (uint)bVar15;
    local_50 = 0x2d;
  }
  else if ((int)(param_10 << 0x1e) < 0) {
    local_58 = 1;
    local_50 = 0x2b;
  }
  else {
    local_58 = param_10 & 4;
    local_50 = local_58;
    if (local_58 != 0) {
      local_58 = 1;
      local_50 = 0x20;
    }
  }
  if ((int)(param_10 << 0x1c) < 0) {
    if (param_7 == 8) {
      local_64 = "0";
    }
    else if (param_7 == 0x10) {
      local_64 = "0x";
    }
    else {
      local_64 = "";
    }
  }
  else {
    local_64 = "";
  }
  pcVar10 = &cStack_45;
  uVar9 = 0;
  pcVar13 = "0123456789ABCDEF";
  lVar16 = CONCAT44(param_6,param_5);
  if ((param_10 & 0x20) == 0) {
    pcVar13 = "0123456789abcdef";
    lVar16 = CONCAT44(param_6,param_5);
  }
  do {
    uVar12 = uVar9;
    uVar8 = (undefined4)((ulonglong)lVar16 >> 0x20);
    __aeabi_uldivmod((int)lVar16,uVar8,param_7,0);
    uVar9 = uVar12 + 1;
    pcVar10 = pcVar10 + 1;
    *pcVar10 = pcVar13[extraout_r2];
    lVar16 = __aeabi_uldivmod((int)lVar16,uVar8,param_7,0);
    iVar5 = extraout_r3;
    if (0x19 < (int)uVar9) {
      iVar5 = 0;
    }
    if (uVar9 == 0x19 || (int)(uVar12 - 0x18) < 0 != SBORROW4(uVar9,0x19)) {
      iVar5 = 1;
    }
    if (lVar16 == 0) {
      iVar5 = 0;
    }
  } while (iVar5 != 0);
  if (uVar9 == 0x1a) {
    uVar9 = uVar12;
  }
  local_44[uVar9] = '\0';
  sVar1 = strlen(local_64);
  uVar12 = param_9 - uVar9;
  if ((int)param_9 <= (int)uVar9) {
    param_9 = uVar9;
  }
  uVar2 = ((param_8 - param_9) - local_58) - sVar1;
  uVar12 = uVar12 & ~((int)uVar12 >> 0x1f);
  uVar2 = uVar2 & ~((int)uVar2 >> 0x1f);
  if ((int)(param_10 << 0x1b) < 0) {
    if ((int)uVar12 < (int)uVar2) {
      uVar12 = uVar2;
    }
    uVar2 = 0;
  }
  else if ((int)(param_10 << 0x1f) < 0) {
    uVar2 = -uVar2;
  }
  else if (uVar2 != 0) {
    piVar11 = param_2;
    if (param_2 != (int *)0x0) {
      piVar11 = (int *)0x1;
    }
    if (param_2 == (int *)0x0 && *param_1 == 0) {
      return 0;
    }
    __n = *param_3;
    uVar4 = *param_4;
    if (uVar4 < __n) {
      return 0;
    }
    if (uVar4 == __n) {
      uVar6 = (uint)piVar11 & 1;
    }
    else {
      uVar6 = 0;
    }
    if (uVar6 != 0) goto LAB_00107d1a;
LAB_00107cd6:
    if (uVar4 <= __n) goto LAB_00107cea;
    iVar5 = *param_1;
    if (iVar5 == 0) goto LAB_00107da6;
    do {
      *param_3 = __n + 1;
      *(undefined1 *)(iVar5 + __n) = 0x20;
LAB_00107cea:
      do {
        uVar2 = uVar2 - 1;
        if (uVar2 == 0) {
          uVar2 = 0;
          goto LAB_00107bec;
        }
        piVar7 = piVar11;
        if (*param_1 != 0) {
          piVar7 = (int *)((uint)piVar11 | 1);
        }
        if (piVar7 == (int *)0x0) {
          return 0;
        }
        __n = *param_3;
        uVar4 = *param_4;
        if (uVar4 < __n) {
          return 0;
        }
        if (uVar4 == __n) {
          uVar6 = (uint)piVar11 & 1;
        }
        else {
          uVar6 = 0;
        }
        if (uVar6 == 0) goto LAB_00107cd6;
LAB_00107d1a:
        if (0x7ffffbff < uVar4) {
          return 0;
        }
        pvVar3 = (void *)*param_2;
        uVar4 = uVar4 + 0x400;
        *param_4 = uVar4;
        if (pvVar3 != (void *)0x0) {
          pvVar3 = CRYPTO_realloc(pvVar3,uVar4,"crypto/bio/b_print.c",0x346);
          if (pvVar3 == (void *)0x0) {
            return 0;
          }
          __n = *param_3;
          uVar4 = *param_4;
          *param_2 = (int)pvVar3;
          goto LAB_00107cd6;
        }
        pvVar3 = CRYPTO_malloc(uVar4,"crypto/bio/b_print.c",0x33a);
        *param_2 = (int)pvVar3;
        if (pvVar3 == (void *)0x0) {
          ERR_put_error(0x20,0x96,0x41,"crypto/bio/b_print.c",0x33b);
          return 0;
        }
        __n = *param_3;
        if (__n != 0) {
          if ((void *)*param_1 == (void *)0x0) {
            return 0;
          }
          memcpy(pvVar3,(void *)*param_1,__n);
          __n = *param_3;
        }
        uVar4 = *param_4;
        *param_1 = 0;
      } while (uVar4 <= __n);
LAB_00107da6:
      iVar5 = *param_2;
    } while( true );
  }
LAB_00107bec:
  if ((local_50 != 0) &&
     ((param_2 == (int *)0x0 && *param_1 == 0 ||
      (iVar5 = doapr_outch_part_0(param_1,param_2,param_3,param_4,local_50), iVar5 == 0)))) {
    return 0;
  }
  cVar14 = *local_64;
  if (cVar14 != '\0') {
    piVar11 = param_2;
    if (param_2 != (int *)0x0) {
      piVar11 = (int *)0x1;
    }
    do {
      piVar7 = piVar11;
      if (*param_1 != 0) {
        piVar7 = (int *)((uint)piVar11 | 1);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      iVar5 = doapr_outch_part_0(param_1,param_2,param_3,param_4,cVar14);
      if (iVar5 == 0) {
        return 0;
      }
      local_64 = local_64 + 1;
      cVar14 = *local_64;
    } while (cVar14 != '\0');
  }
  if (uVar12 != 0) {
    piVar11 = param_2;
    if (param_2 != (int *)0x0) {
      piVar11 = (int *)0x1;
    }
    do {
      piVar7 = piVar11;
      if (*param_1 != 0) {
        piVar7 = (int *)((uint)piVar11 | 1);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      iVar5 = doapr_outch_part_0(param_1,param_2,param_3,param_4,0x30);
      if (iVar5 == 0) {
        return 0;
      }
      uVar12 = uVar12 - 1;
    } while (uVar12 != 0);
  }
  if (uVar9 != 0) {
    pcVar10 = local_44 + uVar9;
    piVar11 = param_2;
    if (param_2 != (int *)0x0) {
      piVar11 = (int *)0x1;
    }
    do {
      pcVar10 = pcVar10 + -1;
      piVar7 = piVar11;
      if (*param_1 != 0) {
        piVar7 = (int *)((uint)piVar11 | 1);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      iVar5 = doapr_outch_part_0(param_1,param_2,param_3,param_4,*pcVar10);
      if (iVar5 == 0) {
        return 0;
      }
    } while (pcVar10 != local_44);
  }
  if (uVar2 != 0) {
    piVar11 = param_2;
    if (param_2 != (int *)0x0) {
      piVar11 = (int *)0x1;
    }
    do {
      piVar7 = piVar11;
      if (*param_1 != 0) {
        piVar7 = (int *)((uint)piVar11 | 1);
      }
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      iVar5 = doapr_outch_part_0(param_1,param_2,param_3,param_4,0x20);
      if (iVar5 == 0) {
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 0);
  }
  return 1;
}

