
void k_alloc_items(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  size_t __nmemb;
  char acStack_818 [2048];
  
  if (*(char *)(param_1 + 1) == '\0') {
    iVar7 = param_1[10];
  }
  else {
    snprintf(acStack_818,0x800,"List %s store can\'t %s() - from %s %s() line %d in %s %s():%d",
             *param_1,"k_alloc_items",param_2,param_3,param_4,"klist.c","k_alloc_items",0x13);
    _applog(3,acStack_818,1);
    _quit(1);
    iVar7 = param_1[10];
  }
  if (iVar7 < 1) {
    __nmemb = param_1[9];
  }
  else {
    iVar6 = param_1[6];
    if (iVar7 <= iVar6) {
      return;
    }
    __nmemb = param_1[9];
    if (iVar7 < (int)(iVar6 + __nmemb)) {
      __nmemb = iVar7 - iVar6;
    }
  }
  iVar7 = param_1[0xc];
  param_1[0xc] = iVar7 + 1;
  pvVar2 = realloc((void *)param_1[0xd],(iVar7 + 1) * 4);
  param_1[0xd] = pvVar2;
  if (pvVar2 == (void *)0x0) {
    snprintf(acStack_818,0x800,"List %s item_memory failed to realloc count=%d in %s %s():%d",
             *param_1,param_1[0xc],"klist.c","k_alloc_items",0x21);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  puVar3 = (undefined4 *)calloc(__nmemb,0x10);
  if (puVar3 == (undefined4 *)0x0) {
    snprintf(acStack_818,0x800,
             "List %s failed to calloc %d new items - total was %d, limit was %d in %s %s():%d",
             *param_1,__nmemb,param_1[6],param_1[10],"klist.c","k_alloc_items",0x26);
    _applog(3,acStack_818,1);
    _quit(1);
  }
  iVar7 = param_1[6];
  puVar4 = (undefined4 *)param_1[0xd];
  puVar4[param_1[0xc] + 0x3fffffff] = puVar3;
  uVar5 = *param_1;
  if (2 < (int)__nmemb) {
    puVar4 = puVar3 + __nmemb * 4;
  }
  param_1[6] = iVar7 + __nmemb;
  param_1[7] = __nmemb;
  puVar8 = puVar3 + 4;
  if (2 < (int)__nmemb) {
    puVar8 = puVar3 + 8;
  }
  param_1[8] = __nmemb;
  *puVar3 = uVar5;
  puVar3[1] = 0;
  puVar3[2] = puVar3 + 4;
  if (2 < (int)__nmemb) {
    do {
      puVar8[-4] = uVar5;
      puVar8[-3] = puVar8 + -8;
      puVar8[-2] = puVar8;
      puVar8 = puVar8 + 4;
    } while (puVar4 != puVar8);
  }
  cVar1 = *(char *)(param_1 + 0xb);
  iVar7 = __nmemb + 0xfffffff;
  param_1[3] = puVar3;
  puVar4 = puVar3 + iVar7 * 4;
  puVar3[iVar7 * 4] = uVar5;
  puVar4[1] = puVar3 + iVar7 * 4 + -4;
  puVar4[2] = 0;
  if (cVar1 != '\0') {
    param_1[4] = puVar4;
  }
  iVar7 = param_1[0xe];
  do {
    param_1[0xe] = iVar7 + 1;
    pvVar2 = realloc((void *)param_1[0xf],(iVar7 + 1) * 4);
    param_1[0xf] = pvVar2;
    if (pvVar2 == (void *)0x0) {
      snprintf(acStack_818,0x800,"List %s data_memory failed to realloc count=%d in %s %s():%d",
               *param_1,param_1[0xe],"klist.c","k_alloc_items",0x45);
      _applog(3,acStack_818,1);
      _quit(1);
    }
    pvVar2 = calloc(1,param_1[5]);
    puVar3[3] = pvVar2;
    if (pvVar2 == (void *)0x0) {
      snprintf(acStack_818,0x800,"List %s failed to calloc item data in %s %s():%d",*param_1,
               "klist.c","k_alloc_items",0x49);
      _applog(3,acStack_818,1);
      _quit(1);
      pvVar2 = (void *)puVar3[3];
    }
    iVar7 = param_1[0xe];
    *(void **)(param_1[0xf] + (iVar7 + 0x3fffffff) * 4) = pvVar2;
    puVar3 = (undefined4 *)puVar3[2];
  } while (puVar3 != (undefined4 *)0x0);
  return;
}

