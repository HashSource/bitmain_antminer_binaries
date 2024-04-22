
uint CRC16(int param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 != 0) {
    uVar3 = 0xff;
    uVar2 = 0xff;
    pbVar1 = (byte *)(param_1 + -1);
    do {
      pbVar1 = pbVar1 + 1;
      uVar4 = *pbVar1 ^ uVar3;
      uVar3 = (byte)chCRCHTalbe[uVar4] ^ uVar2;
      uVar2 = (uint)(byte)chCRCLTalbe[uVar4];
    } while (pbVar1 != (byte *)((param_2 - 1U & 0xffff) + param_1));
    return uVar3 | uVar2 << 8;
  }
  return 0xffff;
}

