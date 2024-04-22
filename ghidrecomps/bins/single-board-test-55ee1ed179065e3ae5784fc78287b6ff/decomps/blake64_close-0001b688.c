
void blake64_close(int param_1,byte param_2,uint param_3,int param_4,uint param_5)

{
  uint uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  int iVar2;
  undefined4 *puVar3;
  byte abStack_b8 [111];
  byte local_49;
  undefined auStack_48 [8];
  undefined auStack_40 [12];
  int local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  int iStack_24;
  int local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  
  local_18 = *(int *)(param_1 + 0x80);
  local_1c = local_18 * 8 + param_3;
  local_20 = 0x80 >> (param_3 & 0xff);
  abStack_b8[local_18] = (byte)local_20 | param_2 & -(byte)local_20;
  local_28 = local_1c + *(uint *)(param_1 + 0xe8);
  iStack_24 = *(int *)(param_1 + 0xec) + (uint)CARRY4(local_1c,*(uint *)(param_1 + 0xe8));
  local_30 = *(undefined4 *)(param_1 + 0xf0);
  uStack_2c = *(undefined4 *)(param_1 + 0xf4);
  if ((local_18 == 0) && (param_3 == 0)) {
    *(undefined4 *)(param_1 + 0xe8) = 0xfffffc00;
    *(undefined4 *)(param_1 + 0xec) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf0) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf4) = 0xffffffff;
  }
  else if ((*(uint *)(param_1 + 0xe8) | *(uint *)(param_1 + 0xec)) == 0) {
    *(uint *)(param_1 + 0xe8) = local_1c - 0x400;
    *(uint *)(param_1 + 0xec) = (0x3ff < local_1c) - 1;
    iVar2 = *(int *)(param_1 + 0xf0);
    *(int *)(param_1 + 0xf0) = iVar2 + -1;
    *(uint *)(param_1 + 0xf4) = *(int *)(param_1 + 0xf4) + -1 + (uint)(iVar2 != 0);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xe8);
    *(uint *)(param_1 + 0xe8) = uVar1 - (0x400 - local_1c);
    *(uint *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) - (uint)(uVar1 < 0x400 - local_1c);
  }
  if (local_1c < 0x37f) {
    memset(abStack_b8 + local_18 + 1,0,0x6f - local_18);
    if (param_5 == 8) {
      local_49 = local_49 | 1;
    }
    sph_enc64be_aligned(auStack_48);
    sph_enc64be_aligned(auStack_40,extraout_r1,local_28,iStack_24);
    blake64(param_1,abStack_b8 + local_18,0x80 - local_18);
  }
  else {
    memset(abStack_b8 + local_18 + 1,0,0x7f - local_18);
    blake64(param_1,abStack_b8 + local_18,0x80 - local_18);
    *(undefined4 *)(param_1 + 0xe8) = 0xfffffc00;
    *(undefined4 *)(param_1 + 0xec) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf0) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xf4) = 0xffffffff;
    memset(abStack_b8,0,0x70);
    if (param_5 == 8) {
      local_49 = 1;
    }
    sph_enc64be_aligned(auStack_48);
    sph_enc64be_aligned(auStack_40,extraout_r1_00,local_28,iStack_24);
    blake64(param_1,abStack_b8,0x80);
  }
  local_34 = param_4;
  for (local_14 = 0; local_14 < param_5; local_14 = local_14 + 1) {
    iVar2 = local_34 + local_14 * 8;
    puVar3 = (undefined4 *)(param_1 + (local_14 + 0x11) * 8);
    sph_enc64be(iVar2,iVar2,*puVar3,puVar3[1]);
  }
  return;
}

