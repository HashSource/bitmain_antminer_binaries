
undefined4 finish_hash(uint *param_1,uint *param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  undefined uStack_89;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint local_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint local_48 [4];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  local_68 = param_1[4];
  uStack_64 = param_1[5];
  uStack_60 = param_1[6];
  uStack_5c = param_1[7];
  uVar5 = *param_1;
  uVar6 = param_1[1];
  local_58 = param_1[8];
  uStack_54 = param_1[9];
  uStack_50 = param_1[10];
  uStack_4c = param_1[0xb];
  local_48[0] = param_1[0xc];
  local_48[1] = param_1[0xd];
  local_48[2] = param_1[0xe];
  local_48[3] = param_1[0xf];
  local_38 = param_1[0x10];
  uStack_34 = param_1[0x11];
  uStack_30 = param_1[0x12];
  uStack_2c = param_1[0x13];
  if (param_1[3] != 0) {
    iVar4 = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    memcpy(&local_88,param_1 + 0x14,param_1[3]);
    hash_step(param_1[2],&local_68,&local_88);
    iVar2 = 0;
    do {
      iVar4 = (uint)*(byte *)((int)local_48 + iVar2) + (uint)*(byte *)((int)&local_88 + iVar2) +
              iVar4;
      *(char *)((int)local_48 + iVar2) = (char)iVar4;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 >> 8;
    } while (iVar2 != 0x20);
    uVar3 = param_1[3];
    bVar7 = CARRY4(uVar5,uVar3);
    uVar5 = uVar5 + uVar3;
    uVar6 = uVar6 + ((int)uVar3 >> 0x1f) + (uint)bVar7;
  }
  uVar3 = uVar5 << 3;
  uVar5 = uVar6 << 3 | uVar5 >> 0x1d;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  if ((int)(uVar5 - (uVar3 == 0)) < 0 == (SBORROW4(uVar5,(uint)(uVar3 == 0)) != false)) {
    puVar1 = &uStack_89;
    do {
      puVar1 = puVar1 + 1;
      *puVar1 = (char)uVar3;
      uVar3 = uVar3 >> 8 | uVar5 << 0x18;
      uVar5 = (int)uVar5 >> 8;
    } while ((uVar3 | uVar5) != 0);
  }
  hash_step(param_1[2],&local_68,&local_88);
  hash_step(param_1[2],&local_68,local_48);
  *param_2 = local_68;
  param_2[1] = uStack_64;
  param_2[2] = uStack_60;
  param_2[3] = uStack_5c;
  param_2[4] = local_58;
  param_2[5] = uStack_54;
  param_2[6] = uStack_50;
  param_2[7] = uStack_4c;
  return 1;
}

