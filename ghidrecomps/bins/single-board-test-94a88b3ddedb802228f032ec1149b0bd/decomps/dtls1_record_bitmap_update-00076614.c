
void dtls1_record_bitmap_update(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar2 = *(int *)(param_1 + 0x58);
  uVar1 = (uint)*(byte *)(iVar2 + 0xf) - (uint)*(byte *)((int)param_2 + 0xb);
  if ((int)(uVar1 * 0x1000000) < 0) {
    uVar3 = ((int)uVar1 >> 8) + ((uint)*(byte *)(iVar2 + 0xe) - (uint)*(byte *)((int)param_2 + 10));
    uVar8 = ((uint)*(byte *)(iVar2 + 0xd) - (uint)*(byte *)((int)param_2 + 9)) + ((int)uVar3 >> 8);
    uVar7 = ((uint)*(byte *)(iVar2 + 0xc) - (uint)*(byte *)(param_2 + 2)) + ((int)uVar8 >> 8);
    uVar9 = ((uint)*(byte *)(iVar2 + 0xb) - (uint)*(byte *)((int)param_2 + 7)) + ((int)uVar7 >> 8);
    uVar6 = ((uint)*(byte *)(iVar2 + 10) - (uint)*(byte *)((int)param_2 + 6)) + ((int)uVar9 >> 8);
    uVar5 = ((uint)*(byte *)(iVar2 + 9) - (uint)*(byte *)((int)param_2 + 5)) + ((int)uVar6 >> 8);
    uVar4 = ((uint)*(byte *)(iVar2 + 8) - (uint)*(byte *)(param_2 + 1)) + ((int)uVar5 >> 8);
    uVar3 = ~uVar8 | ~uVar3 | ~uVar7 | ~uVar9 | ~uVar6 | ~uVar5 | ~uVar4;
  }
  else {
    uVar3 = ((int)uVar1 >> 8) + ((uint)*(byte *)(iVar2 + 0xe) - (uint)*(byte *)((int)param_2 + 10));
    uVar7 = ((uint)*(byte *)(iVar2 + 0xd) - (uint)*(byte *)((int)param_2 + 9)) + ((int)uVar3 >> 8);
    uVar6 = ((uint)*(byte *)(iVar2 + 0xc) - (uint)*(byte *)(param_2 + 2)) + ((int)uVar7 >> 8);
    uVar9 = ((uint)*(byte *)(iVar2 + 0xb) - (uint)*(byte *)((int)param_2 + 7)) + ((int)uVar6 >> 8);
    uVar5 = ((uint)*(byte *)(iVar2 + 10) - (uint)*(byte *)((int)param_2 + 6)) + ((int)uVar9 >> 8);
    uVar8 = ((uint)*(byte *)(iVar2 + 9) - (uint)*(byte *)((int)param_2 + 5)) + ((int)uVar5 >> 8);
    uVar4 = ((uint)*(byte *)(iVar2 + 8) - (uint)*(byte *)(param_2 + 1)) + ((int)uVar8 >> 8);
    uVar3 = uVar3 | uVar7 | uVar6 | uVar9 | uVar5 | uVar8 | uVar4;
  }
  uVar4 = ((int)uVar4 >> 8) * 0x100;
  if ((uVar3 & 0xff) == 0) {
    uVar4 = uVar4 + (uVar1 & 0xff);
  }
  else {
    uVar4 = uVar4 | 0x80;
  }
  if ((int)uVar4 < 1) {
    if (-uVar4 < 0x1f || uVar4 == 0xffffffe1) {
      *param_2 = *param_2 | 1 << (-uVar4 & 0xff);
    }
  }
  else {
    if (uVar4 < 0x20) {
      *param_2 = *param_2 << (uVar4 & 0xff) | 1;
    }
    else {
      *param_2 = 1;
    }
    uVar1 = *(uint *)(iVar2 + 0xc);
    param_2[1] = *(uint *)(iVar2 + 8);
    param_2[2] = uVar1;
  }
  return;
}

