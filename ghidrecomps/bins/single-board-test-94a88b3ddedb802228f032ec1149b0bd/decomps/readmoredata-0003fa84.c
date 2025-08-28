
uint readmoredata(void *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint __n;
  
  iVar7 = *(int *)(*param_4 + 0x14c);
  uVar4 = *(uint *)(iVar7 + 8);
  iVar5 = *(int *)(iVar7 + 0xc);
  if (uVar4 == 0 && iVar5 == 0) {
    uVar4 = 0;
  }
  else {
    __n = param_2 * param_3;
    *(bool *)(*param_4 + 0x14b) = *(int *)(iVar7 + 0x58) == 1;
    if (-iVar5 < (int)(uint)(__n < uVar4)) {
      memcpy(param_1,*(void **)(iVar7 + 0x10),__n);
      uVar4 = *(uint *)(iVar7 + 8);
      *(uint *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + __n;
      *(uint *)(iVar7 + 8) = uVar4 - __n;
      *(uint *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) - (uint)(uVar4 < __n);
      return __n;
    }
    memcpy(param_1,*(void **)(iVar7 + 0x10),uVar4);
    iVar5 = *(int *)(iVar7 + 0x50);
    iVar6 = *(int *)(iVar7 + 0x54);
    uVar4 = *(uint *)(iVar7 + 8);
    if (iVar5 == 0 && iVar6 == 0) {
      *(int *)(iVar7 + 8) = iVar5;
      *(int *)(iVar7 + 0xc) = iVar6;
      return uVar4;
    }
    iVar1 = *(int *)(iVar7 + 0x58);
    iVar3 = *param_4;
    *(int *)(iVar7 + 8) = iVar5;
    *(int *)(iVar7 + 0xc) = iVar6;
    *(undefined4 *)(iVar7 + 0x10) = *(undefined4 *)(iVar7 + 0x48);
    uVar2 = *(undefined4 *)(iVar7 + 0x40);
    *(undefined4 *)(iVar3 + 0x86c4) = *(undefined4 *)(iVar7 + 0x44);
    *(undefined4 *)(iVar3 + 0x86c0) = uVar2;
    *(int *)(iVar7 + 0x58) = iVar1 + 1;
    *(undefined4 *)(iVar7 + 0x50) = 0;
    *(undefined4 *)(iVar7 + 0x54) = 0;
  }
  return uVar4;
}

