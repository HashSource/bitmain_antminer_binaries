
void keyDiversifyCryptoPro(undefined4 param_1,undefined4 *param_2,int param_3,byte *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  
  uVar8 = param_2[2];
  iVar7 = 0;
  uVar1 = param_2[1];
  uVar4 = param_2[3];
  *(undefined4 *)param_4 = *param_2;
  *(undefined4 *)(param_4 + 4) = uVar1;
  *(undefined4 *)(param_4 + 8) = uVar8;
  *(undefined4 *)(param_4 + 0xc) = uVar4;
  uVar1 = param_2[5];
  uVar8 = param_2[6];
  uVar4 = param_2[7];
  *(undefined4 *)(param_4 + 0x10) = param_2[4];
  *(undefined4 *)(param_4 + 0x14) = uVar1;
  *(undefined4 *)(param_4 + 0x18) = uVar8;
  *(undefined4 *)(param_4 + 0x1c) = uVar4;
  do {
    uVar5 = (uint)*(byte *)(param_3 + iVar7);
    uVar6 = (uint)*param_4 | (uint)param_4[3] << 0x18 |
            (uint)param_4[1] << 8 | (uint)param_4[2] << 0x10;
    bVar9 = (*(byte *)(param_3 + iVar7) & 1) != 0;
    uVar3 = uVar6;
    if (!bVar9) {
      uVar3 = 0;
    }
    uVar2 = (uint)param_4[4] | (uint)param_4[7] << 0x18 |
            (uint)param_4[5] << 8 | (uint)param_4[6] << 0x10;
    if (bVar9) {
      uVar6 = 0;
    }
    if ((int)(uVar5 << 0x1e) < 0) {
      uVar3 = uVar3 + uVar2;
    }
    else {
      uVar6 = uVar6 + uVar2;
    }
    iVar7 = iVar7 + 1;
    uVar2 = (uint)param_4[9] << 8 | (uint)param_4[10] << 0x10 |
            (uint)param_4[8] | (uint)param_4[0xb] << 0x18;
    if ((int)(uVar5 << 0x1d) < 0) {
      uVar3 = uVar3 + uVar2;
    }
    else {
      uVar6 = uVar6 + uVar2;
    }
    uVar2 = (uint)param_4[0xd] << 8 | (uint)param_4[0xe] << 0x10 |
            (uint)param_4[0xc] | (uint)param_4[0xf] << 0x18;
    if ((int)(uVar5 << 0x1c) < 0) {
      uVar3 = uVar3 + uVar2;
    }
    else {
      uVar6 = uVar6 + uVar2;
    }
    uVar2 = (uint)param_4[0x11] << 8 | (uint)param_4[0x12] << 0x10 |
            (uint)param_4[0x10] | (uint)param_4[0x13] << 0x18;
    if ((int)(uVar5 << 0x1b) < 0) {
      uVar3 = uVar3 + uVar2;
    }
    else {
      uVar6 = uVar6 + uVar2;
    }
    uVar2 = (uint)param_4[0x15] << 8 | (uint)param_4[0x16] << 0x10 |
            (uint)param_4[0x14] | (uint)param_4[0x17] << 0x18;
    if ((int)(uVar5 << 0x1a) < 0) {
      uVar3 = uVar3 + uVar2;
    }
    else {
      uVar6 = uVar6 + uVar2;
    }
    uVar2 = (uint)param_4[0x19] << 8 | (uint)param_4[0x1a] << 0x10 |
            (uint)param_4[0x18] | (uint)param_4[0x1b] << 0x18;
    if ((int)(uVar5 << 0x19) < 0) {
      uVar3 = uVar3 + uVar2;
    }
    else {
      uVar6 = uVar6 + uVar2;
    }
    uVar2 = (uint)param_4[0x1c] | (uint)param_4[0x1f] << 0x18 |
            (uint)param_4[0x1d] << 8 | (uint)param_4[0x1e] << 0x10;
    if ((int)(uVar5 << 0x18) < 0) {
      uVar3 = uVar3 + uVar2;
    }
    else {
      uVar6 = uVar6 + uVar2;
    }
    local_30 = (undefined1)uVar3;
    local_2c = (undefined1)uVar6;
    local_2d = (undefined1)(uVar3 >> 0x18);
    local_2b = (undefined1)(uVar6 >> 8);
    local_2a = (undefined1)(uVar6 >> 0x10);
    local_2f = (undefined1)(uVar3 >> 8);
    local_2e = (undefined1)(uVar3 >> 0x10);
    local_29 = (undefined1)(uVar6 >> 0x18);
    gost_key(param_1,param_4);
    gost_enc_cfb(param_1,&local_30,param_4,param_4,4);
  } while (iVar7 != 8);
  return;
}

