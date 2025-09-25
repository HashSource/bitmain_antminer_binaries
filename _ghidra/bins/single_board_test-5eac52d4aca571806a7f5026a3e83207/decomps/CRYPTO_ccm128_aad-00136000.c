
void CRYPTO_ccm128_aad(byte *param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  code *pcVar6;
  
  if (param_3 != 0) {
    bVar1 = *param_1;
    pcVar6 = *(code **)(param_1 + 0x28);
    pbVar5 = param_1 + 0x10;
    *param_1 = bVar1 | 0x40;
    (*pcVar6)(param_1,pbVar5,*(undefined4 *)(param_1 + 0x2c),bVar1 | 0x40,param_4);
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
      for (; param_3 != 0 && uVar4 < 0x10; param_3 = param_3 - 1) {
        param_1[uVar4 + 0x10] = *param_2 ^ param_1[uVar4 + 0x10];
        uVar4 = uVar4 + 1;
        param_2 = param_2 + 1;
      }
      (*pcVar6)(pbVar5,pbVar5,*(undefined4 *)(param_1 + 0x2c),uVar4 + 1,param_4);
      uVar4 = *(uint *)(param_1 + 0x20);
      *(uint *)(param_1 + 0x20) = uVar4 + 1;
      *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar4);
      uVar4 = 0;
    } while (param_3 != 0);
    return;
  }
  return;
}

