
undefined4 dtls1_record_replay_check(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar6 = (uint)*(byte *)(param_1 + 0xf21) << 0x10 | (uint)*(byte *)(param_1 + 0xf20) << 0x18 |
          (uint)*(byte *)(param_1 + 0xf22) << 8 | (uint)*(byte *)(param_1 + 0xf23);
  uVar3 = (uint)*(byte *)(param_1 + 0xf27) | (uint)*(byte *)(param_1 + 0xf24) << 0x18 |
          (uint)*(byte *)(param_1 + 0xf25) << 0x10 | (uint)*(byte *)(param_1 + 0xf26) << 8;
  uVar7 = (uint)*(byte *)((int)param_2 + 7) |
          (uint)*(byte *)((int)param_2 + 6) << 8 |
          (uint)(byte)param_2[1] << 0x18 | (uint)*(byte *)((int)param_2 + 5) << 0x10;
  uVar4 = (uint)*(byte *)((int)param_2 + 10) << 8 |
          (uint)(byte)param_2[2] << 0x18 | (uint)*(byte *)((int)param_2 + 0xb) |
          (uint)*(byte *)((int)param_2 + 9) << 0x10;
  uVar1 = uVar3 - uVar4;
  uVar2 = (uVar6 - uVar7) - (uint)(uVar3 < uVar4);
  bVar8 = uVar6 <= uVar7;
  uVar5 = uVar2 >> 0x1f;
  if (uVar7 == uVar6) {
    bVar8 = uVar3 <= uVar4;
  }
  if (bVar8) {
    uVar5 = 0;
  }
  if (uVar5 == 0) {
    bVar8 = uVar7 <= uVar6;
    if (uVar6 == uVar7) {
      bVar8 = uVar4 <= uVar3;
    }
    if ((int)(uint)(uVar1 == 0) <= (int)uVar2 && !bVar8) {
      return 0;
    }
    if (((int)uVar2 < (int)(uint)(uVar1 < 0x81)) &&
       (((int)((uVar2 + 1) - (uint)(uVar1 < 0xffffff80)) < 0 !=
         (SBORROW4(uVar2,-1) != SBORROW4(uVar2 + 1,(uint)(uVar1 < 0xffffff80))) ||
        (((int)uVar1 < 1 &&
         ((uVar1 != 0xffffffe1 && 0x1e < (int)-uVar1 ||
          ((int)((*param_2 >> (-uVar1 & 0xff)) << 0x1f) < 0)))))))) {
      return 0;
    }
  }
  SSL3_RECORD_set_seq_num(param_1 + 0x8f8,param_1 + 0xf20);
  return 1;
}

