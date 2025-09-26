
uint read_n(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  void *__dest;
  size_t sVar5;
  undefined4 extraout_r3;
  BIO *b;
  undefined4 uVar6;
  size_t sVar7;
  int iVar8;
  uint local_30;
  
  iVar1 = *(int *)(param_1 + 0x54);
  sVar5 = *(size_t *)(iVar1 + 0x28);
  if ((int)param_2 <= (int)sVar5) {
    if (param_4 == 0) {
      iVar4 = *(int *)(iVar1 + 0x2c);
      *(int *)(param_1 + 0x4c) = *(int *)(iVar1 + 0x30) + iVar4;
      uVar3 = param_2;
    }
    else {
      iVar4 = *(int *)(iVar1 + 0x2c);
      uVar3 = *(int *)(param_1 + 0x50) + param_2;
    }
    *(uint *)(param_1 + 0x50) = uVar3;
    *(size_t *)(iVar1 + 0x28) = sVar5 - param_2;
    *(uint *)(iVar1 + 0x2c) = iVar4 + param_2;
    return param_2;
  }
  if (*(int *)(param_1 + 0x60) == 0) {
    param_3 = param_2;
  }
  uVar3 = 0x8001;
  if (param_3 < 0x8001) {
    uVar3 = param_3;
  }
  if (sVar5 == 0) {
    iVar4 = *(int *)(param_1 + 0x50);
    if ((iVar4 != 0) && (param_4 != 0)) goto LAB_0011e300;
    uVar6 = *(undefined4 *)(iVar1 + 0x30);
    iVar4 = 0;
    iVar8 = 0;
    *(undefined4 *)(param_1 + 0x4c) = uVar6;
    sVar7 = 0;
    if ((int)param_2 < 1) goto LAB_0011e32c;
  }
  else {
    if (param_4 == 0) {
      iVar4 = 0;
      if (*(int *)(iVar1 + 0x2c) == 0) {
        __dest = *(void **)(iVar1 + 0x30);
      }
      else {
        memcpy(*(void **)(iVar1 + 0x30),
               (void *)((int)*(void **)(iVar1 + 0x30) + *(int *)(iVar1 + 0x2c)),sVar5);
        iVar1 = *(int *)(param_1 + 0x54);
        __dest = *(void **)(iVar1 + 0x30);
        *(undefined4 *)(iVar1 + 0x2c) = 0;
      }
    }
    else {
      iVar4 = *(int *)(param_1 + 0x50);
LAB_0011e300:
      __dest = *(void **)(iVar1 + 0x30);
      if (*(void **)(param_1 + 0x4c) != __dest) {
        memcpy(__dest,*(void **)(param_1 + 0x4c),iVar4 + sVar5);
        iVar1 = *(int *)(param_1 + 0x54);
        __dest = *(void **)(iVar1 + 0x30);
      }
    }
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(void **)(param_1 + 0x4c) = __dest;
  }
  piVar2 = __errno_location();
  do {
    b = *(BIO **)(param_1 + 0xc);
    *piVar2 = 0;
    if (b == (BIO *)0x0) {
      ERR_put_error(0x14,0x70,0xd3,"s2_pkt.c",0x170);
      local_30 = 0xffffffff;
LAB_0011e2ee:
      *(size_t *)(*(int *)(param_1 + 0x54) + 0x28) =
           *(int *)(*(int *)(param_1 + 0x54) + 0x28) + sVar5;
      return local_30;
    }
    *(undefined4 *)(param_1 + 0x18) = 3;
    local_30 = BIO_read(b,(void *)(*(int *)(*(int *)(param_1 + 0x54) + 0x30) + iVar4 + sVar5),
                        uVar3 - sVar5);
    if ((int)local_30 < 1) goto LAB_0011e2ee;
    sVar5 = sVar5 + local_30;
  } while ((int)sVar5 < (int)param_2);
  iVar1 = *(int *)(param_1 + 0x54);
  uVar6 = extraout_r3;
  sVar7 = sVar5;
  iVar8 = iVar4;
LAB_0011e32c:
  if ((int)param_2 < (int)sVar7) {
    iVar8 = iVar8 + param_2;
  }
  else {
    uVar6 = 0;
  }
  if ((int)param_2 < (int)sVar7) {
    sVar5 = sVar7 - param_2;
  }
  else {
    *(undefined4 *)(iVar1 + 0x2c) = uVar6;
    sVar5 = sVar7;
  }
  if ((int)sVar7 <= (int)param_2) {
    *(undefined4 *)(iVar1 + 0x28) = uVar6;
  }
  if ((int)param_2 < (int)sVar7) {
    *(int *)(iVar1 + 0x2c) = iVar8;
  }
  if ((int)param_2 < (int)sVar7) {
    *(size_t *)(iVar1 + 0x28) = sVar5;
  }
  uVar3 = param_2;
  if (param_4 != 0) {
    uVar3 = param_2 + *(int *)(param_1 + 0x50);
  }
  *(uint *)(param_1 + 0x50) = uVar3;
  *(undefined4 *)(param_1 + 0x18) = 1;
  return param_2;
}

