
undefined4 hash_block(uint *param_1,void *param_2,uint param_3)

{
  byte *pbVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  void *local_2c;
  
  uVar5 = param_1[3];
  local_2c = param_2;
  if (uVar5 != 0) {
    uVar6 = 0x20 - uVar5;
    if (param_3 < 0x20 - uVar5) {
      uVar6 = param_3;
    }
    memcpy((void *)((int)param_1 + uVar5 + 0x50),param_2,uVar6);
    uVar5 = param_1[3];
    param_1[3] = uVar6 + uVar5;
    if ((int)(uVar6 + uVar5) < 0x20) {
      return 1;
    }
    param_3 = param_3 - uVar6;
    local_2c = (void *)((int)param_2 + uVar6);
    hash_step(param_1[2],param_1 + 4,param_1 + 0x14);
    iVar2 = 0;
    iVar4 = 0;
    puVar3 = param_1 + 0xc;
    do {
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + (uint)*(byte *)(puVar3 + 8) + (uint)*(byte *)puVar3;
      *(byte *)puVar3 = (byte)iVar2;
      iVar2 = iVar2 >> 8;
      puVar3 = (uint *)((int)puVar3 + 1);
    } while (iVar4 != 0x20);
    uVar5 = *param_1;
    param_1[3] = 0;
    *param_1 = uVar5 + 0x20;
    param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar5);
  }
  if (0x1f < param_3) {
    pvVar7 = local_2c;
    uVar5 = param_3;
    do {
      hash_step(param_1[2],param_1 + 4,pvVar7);
      iVar2 = 0;
      iVar4 = 0;
      puVar3 = param_1 + 0xc;
      do {
        pbVar1 = (byte *)((int)pvVar7 + iVar4);
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + (uint)*pbVar1 + (uint)*(byte *)puVar3;
        *(byte *)puVar3 = (byte)iVar2;
        iVar2 = iVar2 >> 8;
        puVar3 = (uint *)((int)puVar3 + 1);
      } while (iVar4 != 0x20);
      uVar6 = *param_1;
      uVar5 = uVar5 - 0x20;
      pvVar7 = (void *)((int)pvVar7 + 0x20);
      *param_1 = uVar6 + 0x20;
      param_1[1] = param_1[1] + (uint)(0xffffffdf < uVar6);
    } while (0x1f < uVar5);
    uVar5 = param_3 - 0x20;
    param_3 = param_3 & 0x1f;
    local_2c = (void *)((int)local_2c + (uVar5 & 0xffffffe0) + 0x20);
  }
  if (param_3 != 0) {
    param_1[3] = param_3;
    memcpy(param_1 + 0x14,local_2c,param_3);
  }
  return 1;
}

