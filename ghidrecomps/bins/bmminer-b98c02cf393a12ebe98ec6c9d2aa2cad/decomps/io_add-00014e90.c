
undefined4 io_add(uint *param_1,char *param_2)

{
  size_t sVar1;
  void *pvVar2;
  void *__dest;
  uint uVar3;
  size_t __size;
  int iVar4;
  float fVar5;
  
  sVar1 = strlen(param_2);
  __dest = (void *)param_1[2];
  iVar4 = (int)__dest - (int)(void *)param_1[1];
  uVar3 = iVar4 + 0xc + sVar1;
  if (*param_1 < uVar3) {
    __size = *param_1 + 0x20000;
    if (__size < uVar3) {
      fVar5 = (float)FixedToFP(uVar3,0x20,0x20,0x10,1,0);
      __size = ((uint)(0.0 < fVar5) * (int)fVar5 + 2) * 0x10000;
    }
    pvVar2 = realloc((void *)param_1[1],__size);
    __dest = (void *)((int)pvVar2 + iVar4);
    param_1[1] = (uint)pvVar2;
    param_1[2] = (uint)__dest;
    *param_1 = __size;
  }
  memcpy(__dest,param_2,sVar1 + 1);
  param_1[2] = sVar1 + param_1[2];
  return 1;
}

