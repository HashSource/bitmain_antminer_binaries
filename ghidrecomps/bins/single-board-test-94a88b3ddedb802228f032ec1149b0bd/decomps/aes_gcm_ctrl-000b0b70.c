
int * aes_gcm_ctrl(int *param_1,undefined4 param_2,size_t param_3,int *param_4)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  size_t __n;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar7 = param_1[0x18];
  switch(param_2) {
  case 0:
    iVar3 = *param_1;
    *(undefined4 *)(iVar7 + 0xf8) = 0;
    *(undefined4 *)(iVar7 + 0xfc) = 0;
    uVar4 = *(undefined4 *)(iVar3 + 0xc);
    *(int **)(iVar7 + 0x278) = param_1 + 8;
    *(undefined4 *)(iVar7 + 0x284) = 0;
    *(undefined4 *)(iVar7 + 0x27c) = uVar4;
    *(undefined4 *)(iVar7 + 0x280) = 0xffffffff;
    *(undefined4 *)(iVar7 + 0x288) = 0xffffffff;
    return (int *)0x1;
  default:
    return (int *)0xffffffff;
  case 8:
    iVar3 = param_4[0x18];
    if (*(int *)(iVar7 + 0x274) != 0) {
      if (*(int *)(iVar7 + 0x274) != iVar7) {
        return (int *)0x0;
      }
      *(int *)(iVar3 + 0x274) = iVar3;
    }
    bVar9 = *(int **)(iVar7 + 0x278) == param_1 + 8;
    if (bVar9) {
      param_4 = param_4 + 8;
      param_1 = (int *)0x1;
    }
    if (bVar9) {
      *(int **)(iVar3 + 0x278) = param_4;
      return param_1;
    }
    pvVar2 = CRYPTO_malloc(*(int *)(iVar7 + 0x27c),DAT_000b0e5c,0x4ec);
    *(void **)(iVar3 + 0x278) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memcpy(pvVar2,*(void **)(iVar7 + 0x278),*(size_t *)(iVar7 + 0x27c));
      return (int *)0x1;
    }
    break;
  case 9:
    if (0 < (int)param_3) {
      if ((0x10 < (int)param_3) && (*(int *)(iVar7 + 0x27c) < (int)param_3)) {
        if (*(int **)(iVar7 + 0x278) != param_1 + 8) {
          CRYPTO_free(*(int **)(iVar7 + 0x278));
        }
        pvVar2 = CRYPTO_malloc(param_3,DAT_000b0e5c,0x48e);
        *(void **)(iVar7 + 0x278) = pvVar2;
        if (pvVar2 == (void *)0x0) {
          return (int *)0x0;
        }
      }
      *(size_t *)(iVar7 + 0x27c) = param_3;
      return (int *)0x1;
    }
    break;
  case 0x10:
    if (((param_3 - 1 < 0x10) && (param_1[2] != 0)) && (-1 < *(int *)(iVar7 + 0x280))) {
      memcpy(param_4,param_1 + 0xc,param_3);
      return (int *)0x1;
    }
    break;
  case 0x11:
    if ((param_3 - 1 < 0x10) && (param_1[2] == 0)) {
      memcpy(param_1 + 0xc,param_4,param_3);
      *(size_t *)(iVar7 + 0x280) = param_3;
      return (int *)0x1;
    }
    break;
  case 0x12:
    if (param_3 == 0xffffffff) {
      memcpy(*(void **)(iVar7 + 0x278),param_4,*(size_t *)(iVar7 + 0x27c));
      *(undefined4 *)(iVar7 + 0x284) = 1;
      return (int *)0x1;
    }
    if (((3 < (int)param_3) && (7 < (int)(*(int *)(iVar7 + 0x27c) - param_3))) &&
       ((memcpy(*(void **)(iVar7 + 0x278),param_4,param_3), param_1[2] == 0 ||
        (iVar3 = RAND_bytes((uchar *)(*(int *)(iVar7 + 0x278) + param_3),
                            *(int *)(iVar7 + 0x27c) - param_3), 0 < iVar3)))) {
      *(undefined4 *)(iVar7 + 0x284) = 1;
      return (int *)0x1;
    }
    break;
  case 0x13:
    if ((*(int *)(iVar7 + 0x284) != 0) && (*(int *)(iVar7 + 0xf8) != 0)) {
      CRYPTO_gcm128_setiv(iVar7 + 0x100,*(undefined4 *)(iVar7 + 0x278),
                          *(undefined4 *)(iVar7 + 0x27c));
      __n = *(size_t *)(iVar7 + 0x27c);
      if (((int)param_3 < 1) || ((int)__n < (int)param_3)) {
        iVar3 = 0;
      }
      else {
        iVar3 = __n - param_3;
        __n = param_3;
      }
      memcpy(param_4,(void *)(*(int *)(iVar7 + 0x278) + iVar3),__n);
      iVar3 = *(int *)(iVar7 + 0x278);
      iVar8 = *(int *)(iVar7 + 0x27c) + -8;
      iVar6 = iVar3 + iVar8;
      cVar1 = *(char *)(iVar6 + 7) + '\x01';
      *(char *)(iVar6 + 7) = cVar1;
      if (((cVar1 == '\0') &&
          (cVar1 = *(char *)(iVar6 + 6) + '\x01', *(char *)(iVar6 + 6) = cVar1, cVar1 == '\0')) &&
         ((cVar1 = *(char *)(iVar6 + 5) + '\x01', *(char *)(iVar6 + 5) = cVar1, cVar1 == '\0' &&
          ((((cVar1 = *(char *)(iVar6 + 4) + '\x01', *(char *)(iVar6 + 4) = cVar1, cVar1 == '\0' &&
             (cVar1 = *(char *)(iVar6 + 3) + '\x01', *(char *)(iVar6 + 3) = cVar1, cVar1 == '\0'))
            && (cVar1 = *(char *)(iVar6 + 2) + '\x01', *(char *)(iVar6 + 2) = cVar1, cVar1 == '\0'))
           && (cVar1 = *(char *)(iVar6 + 1) + '\x01', *(char *)(iVar6 + 1) = cVar1, cVar1 == '\0')))
          ))) {
        *(char *)(iVar3 + iVar8) = *(char *)(iVar3 + iVar8) + '\x01';
      }
LAB_000b0bee:
      *(undefined4 *)(iVar7 + 0xfc) = 1;
      return (int *)0x1;
    }
    break;
  case 0x16:
    if (param_3 == 0xd) {
      iVar8 = *param_4;
      iVar3 = param_4[1];
      param_1[0xe] = param_4[2];
      param_1[0xc] = iVar8;
      param_1[0xd] = iVar3;
      iVar3 = param_1[2];
      *(undefined *)(param_1 + 0xf) = *(undefined *)(param_4 + 3);
      *(undefined4 *)(iVar7 + 0x288) = 0xd;
      if (iVar3 == 0) {
        sVar5 = -0x18;
      }
      else {
        sVar5 = -8;
      }
      sVar5 = CONCAT11(*(undefined *)((int)param_1 + 0x3b),*(undefined *)(param_1 + 0xf)) + sVar5;
      *(char *)(param_1 + 0xf) = (char)sVar5;
      *(char *)((int)param_1 + 0x3b) = (char)((ushort)sVar5 >> 8);
      return (int *)0x10;
    }
    break;
  case 0x18:
    if (((*(int *)(iVar7 + 0x284) != 0) && (*(int *)(iVar7 + 0xf8) != 0)) && (param_1[2] == 0)) {
      memcpy((void *)(*(int *)(iVar7 + 0x278) + (*(int *)(iVar7 + 0x27c) - param_3)),param_4,param_3
            );
      CRYPTO_gcm128_setiv(iVar7 + 0x100,*(undefined4 *)(iVar7 + 0x278),
                          *(undefined4 *)(iVar7 + 0x27c));
      goto LAB_000b0bee;
    }
  }
  return (int *)0x0;
}

