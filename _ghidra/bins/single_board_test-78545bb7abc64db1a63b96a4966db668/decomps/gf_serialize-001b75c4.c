
void gf_serialize(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  bool bVar10;
  bool bVar11;
  uint local_70 [4];
  uint local_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint local_50;
  uint uStack_4c;
  uint uStack_48;
  uint uStack_44;
  uint local_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_28;
  
  local_70[0] = *param_2;
  local_70[1] = param_2[1];
  local_70[2] = param_2[2];
  local_70[3] = param_2[3];
  local_60 = param_2[4];
  uStack_5c = param_2[5];
  uStack_58 = param_2[6];
  uStack_54 = param_2[7];
  local_50 = param_2[8];
  uStack_4c = param_2[9];
  uStack_48 = param_2[10];
  uStack_44 = param_2[0xb];
  local_40 = param_2[0xc];
  uStack_3c = param_2[0xd];
  uStack_38 = param_2[0xe];
  uStack_34 = param_2[0xf];
  uStack_28 = param_4;
  gf_strong_reduce(local_70);
  uVar2 = 0;
  puVar9 = (undefined1 *)(param_1 + -1);
  uVar8 = 0;
  uVar3 = 0;
  uVar4 = 0;
  do {
    bVar11 = 6 < uVar2;
    bVar10 = uVar2 == 7;
    if (uVar2 < 8) {
      bVar11 = 0xe < uVar8;
      bVar10 = uVar8 == 0xf;
    }
    uVar7 = uVar2 - 0x20;
    uVar1 = 0x20 - uVar2;
    uVar5 = uVar4;
    if (!bVar11 || bVar10) {
      uVar6 = local_70[uVar8];
      uVar8 = uVar8 + 1;
      uVar5 = uVar2 & 0xff;
      uVar2 = uVar2 + 0x1c;
      uVar3 = uVar3 | uVar6 << uVar5;
      uVar5 = uVar4 | uVar6 << (uVar7 & 0xff) | uVar6 >> (uVar1 & 0xff);
    }
    puVar9 = puVar9 + 1;
    *puVar9 = (char)uVar3;
    uVar4 = uVar5 >> 8;
    uVar3 = uVar3 >> 8 | uVar5 << 0x18;
    uVar2 = uVar2 - 8;
  } while ((undefined1 *)(param_1 + 0x37) != puVar9);
  return;
}

