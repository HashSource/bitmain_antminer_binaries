
undefined4 BLAKE2b_Init(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  bool bVar7;
  uint local_58 [4];
  undefined1 local_48;
  undefined1 local_47;
  undefined4 local_46;
  undefined4 local_42;
  undefined4 local_3e;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_58[0] = 0x1010040;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[1] = 0;
  local_48 = 0;
  local_47 = 0;
  local_46 = 0;
  local_38 = 0;
  local_28 = 0;
  local_42 = 0;
  local_3e = 0;
  local_3a = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  memset(param_1,0,0xe8);
  puVar3 = param_1;
  puVar5 = &blake2b_IV;
  do {
    uVar1 = puVar5[1];
    uVar2 = puVar5[2];
    uVar4 = puVar5[3];
    bVar7 = puVar5 != (uint *)&UNK_0024b5b8;
    *puVar3 = *puVar5;
    puVar3[1] = uVar1;
    puVar3[2] = uVar2;
    puVar3[3] = uVar4;
    puVar3 = puVar3 + 4;
    puVar5 = puVar5 + 4;
  } while (bVar7);
  puVar3 = local_58;
  puVar5 = param_1;
  do {
    uVar1 = *puVar3;
    uVar2 = puVar3[1];
    puVar3 = puVar3 + 2;
    puVar6 = puVar5 + 2;
    *puVar5 = *puVar5 ^ uVar1;
    puVar5[1] = puVar5[1] ^ uVar2;
    puVar5 = puVar6;
  } while (param_1 + 0x10 != puVar6);
  return 1;
}

