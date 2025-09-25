
void dtls1_record_bitmap_update(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar7 = (uint)*(byte *)(param_1 + 0xf21) << 0x10 | (uint)*(byte *)(param_1 + 0xf20) << 0x18 |
          (uint)*(byte *)(param_1 + 0xf22) << 8 | (uint)*(byte *)(param_1 + 0xf23);
  uVar2 = (uint)*(byte *)(param_1 + 0xf26) << 8 |
          (uint)*(byte *)(param_1 + 0xf27) | (uint)*(byte *)(param_1 + 0xf24) << 0x18 |
          (uint)*(byte *)(param_1 + 0xf25) << 0x10;
  uVar5 = (uint)*(byte *)((int)param_2 + 7) |
          (uint)*(byte *)((int)param_2 + 6) << 8 |
          (uint)*(byte *)((int)param_2 + 5) << 0x10 | (uint)(byte)param_2[1] << 0x18;
  uVar3 = (uint)*(byte *)((int)param_2 + 0xb) | (uint)(byte)param_2[2] << 0x18 |
          (uint)*(byte *)((int)param_2 + 9) << 0x10 | (uint)*(byte *)((int)param_2 + 10) << 8;
  uVar4 = uVar2 - uVar3;
  uVar6 = (uVar7 - uVar5) - (uint)(uVar2 < uVar3);
  bVar8 = uVar7 <= uVar5;
  uVar1 = uVar6 >> 0x1f;
  if (uVar5 == uVar7) {
    bVar8 = uVar2 <= uVar3;
  }
  if (bVar8) {
    uVar1 = 0;
  }
  if (uVar1 == 0) {
    bVar8 = uVar5 <= uVar7;
    if (uVar7 == uVar5) {
      bVar8 = uVar3 <= uVar2;
    }
    if ((int)(uint)(uVar4 == 0) <= (int)uVar6 && !bVar8) {
      return;
    }
    if ((int)uVar6 < (int)(uint)(uVar4 < 0x81)) {
      if ((int)((uVar6 + 1) - (uint)(uVar4 < 0xffffff80)) < 0 !=
          (SBORROW4(uVar6,-1) != SBORROW4(uVar6 + 1,(uint)(uVar4 < 0xffffff80)))) {
        return;
      }
      if ((int)uVar4 < 1) {
        if (uVar4 == 0xffffffe1 || (int)-uVar4 < 0x1f) {
          *param_2 = 1 << (-uVar4 & 0xff) | *param_2;
        }
        return;
      }
      if ((int)uVar4 < 0x20) {
        *param_2 = *param_2 << (uVar4 & 0xff) | 1;
        goto LAB_000fc68e;
      }
    }
  }
  *param_2 = 1;
LAB_000fc68e:
  uVar1 = *(uint *)(param_1 + 0xf24);
  param_2[1] = *(uint *)(param_1 + 0xf20);
  param_2[2] = uVar1;
  return;
}

