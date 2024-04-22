
uint readmoredata(void *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = *(int *)(*param_4 + 0x14c);
  uVar4 = *(uint *)(iVar6 + 8);
  uVar5 = *(uint *)(iVar6 + 0xc);
  if ((uVar4 | uVar5) == 0) {
    uVar4 = 0;
  }
  else {
    uVar7 = param_2 * param_3;
    *(bool *)(*param_4 + 0x14b) = *(int *)(iVar6 + 0x58) == 1;
    if ((int)(-(uint)(uVar7 < uVar4) - uVar5) < 0 !=
        (SBORROW4(-uVar5,(uint)(uVar7 < uVar4)) != false)) {
      memcpy(param_1,*(void **)(iVar6 + 0x10),uVar7);
      uVar4 = *(uint *)(iVar6 + 8);
      *(uint *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + uVar7;
      *(uint *)(iVar6 + 8) = uVar4 - uVar7;
      *(uint *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) - (uint)(uVar4 < uVar7);
      return uVar7;
    }
    memcpy(param_1,*(void **)(iVar6 + 0x10),uVar4);
    uVar5 = *(uint *)(iVar6 + 0x50);
    uVar7 = *(uint *)(iVar6 + 0x54);
    uVar4 = *(uint *)(iVar6 + 8);
    if ((uVar5 | uVar7) == 0) {
      *(uint *)(iVar6 + 8) = uVar5;
      *(uint *)(iVar6 + 0xc) = uVar7;
      return uVar4;
    }
    iVar1 = *(int *)(iVar6 + 0x58);
    iVar3 = *param_4;
    *(uint *)(iVar6 + 8) = uVar5;
    *(uint *)(iVar6 + 0xc) = uVar7;
    *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar6 + 0x48);
    uVar2 = *(undefined4 *)(iVar6 + 0x40);
    *(undefined4 *)(iVar3 + 0x86c4) = *(undefined4 *)(iVar6 + 0x44);
    *(undefined4 *)(iVar3 + 0x86c0) = uVar2;
    *(int *)(iVar6 + 0x58) = iVar1 + 1;
    *(undefined4 *)(iVar6 + 0x50) = 0;
    *(undefined4 *)(iVar6 + 0x54) = 0;
  }
  return uVar4;
}

