
undefined4 blake2b_init(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  if ((param_2 - 1 < 0x40) && (param_4 < 0x41)) {
    puVar5 = DAT_00009340 + 0x10;
    puVar2 = DAT_00009340;
    puVar4 = (undefined4 *)(param_1 + 0x78);
    do {
      puVar1 = puVar2 + 2;
      uVar3 = puVar2[3];
      puVar4[2] = *puVar1;
      puVar4[3] = uVar3;
      puVar2 = puVar1;
      puVar4 = puVar4 + 2;
    } while (puVar1 != puVar5);
    *(uint *)(param_1 + 0xd4) = param_2;
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) ^ param_2 ^ 0x1010000 ^ param_4 << 8;
    *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(param_1 + 0xd0) = 0;
    *(undefined4 *)(param_1 + 0xc0) = 0;
    *(undefined4 *)(param_1 + 0xc4) = 0;
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0xcc) = 0;
    uVar6 = param_4;
    do {
      *(undefined *)(param_1 + uVar6) = 0;
      uVar6 = uVar6 + 1;
    } while (uVar6 != 0x80);
    if (param_4 != 0) {
      blake2b_update(param_1,param_3,param_4);
      *(undefined4 *)(param_1 + 0xd0) = 0x80;
    }
    return 0;
  }
  return 0xffffffff;
}

