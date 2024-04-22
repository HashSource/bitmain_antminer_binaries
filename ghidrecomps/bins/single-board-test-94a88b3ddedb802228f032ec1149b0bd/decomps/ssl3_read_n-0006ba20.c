
size_t ssl3_read_n(int param_1,size_t param_2,size_t param_3,int param_4)

{
  char *pcVar1;
  uint uVar2;
  int *piVar3;
  void *pvVar4;
  int iVar5;
  BIO *b;
  size_t __n;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  if ((int)param_2 < 1) {
    return param_2;
  }
  iVar9 = *(int *)(param_1 + 0x58);
  iVar6 = *(int *)(iVar9 + 0xec);
  if (iVar6 == 0) {
    iVar6 = ssl3_setup_read_buffer();
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    iVar6 = *(int *)(iVar9 + 0xec);
  }
  __n = *(size_t *)(iVar9 + 0xf8);
  uVar10 = 3U - iVar6 & 7;
  if (param_4 == 0) {
    if (__n == 0) {
      pvVar4 = (void *)(iVar6 + uVar10);
      *(uint *)(iVar9 + 0xf4) = uVar10;
    }
    else {
      pvVar4 = *(void **)(iVar9 + 0xf4);
      bVar12 = uVar10 == 0;
      uVar2 = uVar10;
      if (!bVar12) {
        uVar2 = __n - 4;
      }
      bVar11 = !bVar12 && SBORROW4(__n,4);
      if ((bVar12 || __n == 4) || (int)uVar2 < 0 != bVar11) {
        pvVar4 = (void *)(iVar6 + (int)pvVar4);
      }
      if ((((!bVar12 && __n != 4) && (int)uVar2 < 0 == bVar11) &&
          (pcVar1 = (char *)(iVar6 + (int)pvVar4), pvVar4 = (void *)(iVar6 + (int)pvVar4),
          *pcVar1 == '\x17')) &&
         (0x7f < CONCAT11(*(undefined *)((int)pvVar4 + 3),*(undefined *)((int)pvVar4 + 4)))) {
        memmove((void *)(iVar6 + uVar10),pvVar4,__n);
        iVar6 = *(int *)(iVar9 + 0xec);
        *(uint *)(iVar9 + 0xf4) = uVar10;
        pvVar4 = (void *)(iVar6 + uVar10);
      }
    }
    *(void **)(param_1 + 0x4c) = pvVar4;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1c < 0) {
    if (param_4 != 0) {
      param_4 = 1;
    }
    if (__n != 0) {
      param_4 = 0;
    }
    if (param_4 != 0) {
      return 0;
    }
    bVar12 = param_2 == __n;
    sVar7 = param_2 - __n;
    if ((int)param_2 > (int)__n) {
      bVar12 = __n == 0;
      sVar7 = __n;
    }
    if (!bVar12 && (int)sVar7 < 0 == ((int)param_2 <= (int)__n && SBORROW4(param_2,__n))) {
      iVar6 = 0;
      param_2 = __n;
      goto LAB_0006ba86;
    }
  }
  if ((int)__n < (int)param_2) {
    pvVar4 = (void *)(iVar6 + uVar10);
    iVar6 = *(int *)(param_1 + 0x50);
    if (*(void **)(param_1 + 0x4c) == pvVar4) {
      iVar5 = *(int *)(iVar9 + 0xf4);
    }
    else {
      memmove(pvVar4,*(void **)(param_1 + 0x4c),iVar6 + __n);
      *(void **)(param_1 + 0x4c) = pvVar4;
      iVar5 = iVar6 + uVar10;
      *(int *)(iVar9 + 0xf4) = iVar5;
    }
    sVar7 = *(int *)(iVar9 + 0xf0) - iVar5;
    if ((int)sVar7 < (int)param_2) {
      ERR_put_error(0x14,0x95,0x44,DAT_0006bc20,0xe6);
      return 0xffffffff;
    }
    if ((*(int *)(param_1 + 0x60) != 0) ||
       (sVar8 = param_2, *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1c < 0)) {
      if ((int)param_3 <= (int)sVar7) {
        sVar7 = param_3;
      }
      sVar8 = sVar7;
      if ((int)param_3 < (int)param_2) {
        sVar8 = param_2;
      }
    }
    piVar3 = __errno_location();
    do {
      b = *(BIO **)(param_1 + 0xc);
      *piVar3 = 0;
      if (b == (BIO *)0x0) {
        ERR_put_error(0x14,0x95,0xd3,DAT_0006bc20,0x101);
        sVar7 = 0xffffffff;
LAB_0006bb7c:
        iVar5 = *(int *)(param_1 + 0x104);
        *(size_t *)(iVar9 + 0xf8) = __n;
        if (-1 < iVar5 << 0x1b) {
          return sVar7;
        }
        if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1c < 0) {
          return sVar7;
        }
        if (iVar6 + __n != 0) {
          return sVar7;
        }
        ssl3_release_read_buffer(param_1);
        return sVar7;
      }
      *(undefined4 *)(param_1 + 0x18) = 3;
      sVar7 = BIO_read(b,(void *)((int)pvVar4 + __n + iVar6),sVar8 - __n);
      if ((int)sVar7 < 1) goto LAB_0006bb7c;
      __n = __n + sVar7;
      if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1c < 0) {
        if ((int)__n <= (int)param_2) {
          param_2 = __n;
        }
        goto LAB_0006bb2c;
      }
      if ((int)param_2 <= (int)__n) {
LAB_0006bb2c:
        iVar6 = *(int *)(param_1 + 0x50);
        *(size_t *)(iVar9 + 0xf8) = __n - param_2;
        *(size_t *)(iVar9 + 0xf4) = *(int *)(iVar9 + 0xf4) + param_2;
        *(size_t *)(param_1 + 0x50) = iVar6 + param_2;
        *(undefined4 *)(param_1 + 0x18) = 1;
        return param_2;
      }
    } while( true );
  }
  iVar6 = __n - param_2;
LAB_0006ba86:
  iVar5 = *(int *)(iVar9 + 0xf4);
  *(size_t *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + param_2;
  *(int *)(iVar9 + 0xf8) = iVar6;
  *(size_t *)(iVar9 + 0xf4) = iVar5 + param_2;
  return param_2;
}

