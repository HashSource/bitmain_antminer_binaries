
void CRYPTO_ccm128_aad(byte *param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  code *pcVar7;
  uint uVar8;
  
  pcVar7 = *(code **)(param_1 + 0x28);
  if (param_3 != 0) {
    bVar1 = *param_1;
    pbVar6 = param_1 + 0x10;
    *param_1 = bVar1 | 0x40;
    (*pcVar7)(param_1,pbVar6,*(undefined4 *)(param_1 + 0x2c),bVar1 | 0x40,param_4);
    uVar4 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar4 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar4);
    bVar1 = (byte)(param_3 >> 8);
    if (param_3 < 0xff00) {
      bVar3 = param_1[0x10] ^ bVar1;
      uVar4 = 2;
      bVar2 = param_1[0x11] ^ (byte)param_3;
    }
    else {
      bVar3 = ~param_1[0x10];
      uVar4 = 6;
      bVar2 = param_1[0x11] ^ 0xfe;
      param_1[0x12] = param_1[0x12] ^ (byte)(param_3 >> 0x18);
      param_1[0x13] = param_1[0x13] ^ (byte)(param_3 >> 0x10);
      param_1[0x14] = param_1[0x14] ^ bVar1;
      param_1[0x15] = param_1[0x15] ^ (byte)param_3;
    }
    param_1[0x11] = bVar2;
    param_1[0x10] = bVar3;
    do {
      while( true ) {
        uVar8 = param_3;
        if (param_3 != 0) {
          uVar8 = 1;
        }
        if (uVar4 < 0x10) {
          uVar5 = uVar8 & 1;
        }
        else {
          uVar5 = 0;
        }
        if (uVar5 == 0) break;
        param_3 = param_3 - 1;
        param_1[uVar4 + 0x10] = param_1[uVar4 + 0x10] ^ *param_2;
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 1;
      }
      (*pcVar7)(pbVar6,pbVar6,*(undefined4 *)(param_1 + 0x2c),uVar4 + 1,param_4);
      uVar4 = *(uint *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar4 + 1;
      *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar4);
      uVar4 = 0;
    } while (uVar8 != 0);
  }
  return;
}

