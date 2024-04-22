
void DES_encrypt3(uint *data,DES_key_schedule *ks1,DES_key_schedule *ks2,DES_key_schedule *ks3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (*data ^ data[1] >> 4) & 0xf0f0f0f;
  uVar1 = data[1] ^ uVar4 << 4;
  uVar4 = uVar4 ^ *data;
  uVar2 = (uVar1 ^ uVar4 >> 0x10) & 0xffff;
  uVar4 = uVar4 ^ uVar2 << 0x10;
  uVar2 = uVar2 ^ uVar1;
  uVar1 = (uVar4 ^ uVar2 >> 2) & 0x33333333;
  uVar2 = uVar2 ^ uVar1 << 2;
  uVar1 = uVar1 ^ uVar4;
  uVar3 = (uVar2 ^ uVar1 >> 8) & 0xff00ff;
  uVar1 = uVar1 ^ uVar3 << 8;
  uVar3 = uVar3 ^ uVar2;
  uVar4 = (uVar1 ^ uVar3 >> 1) & 0x55555555;
  *data = uVar1 ^ uVar4;
  data[1] = uVar3 ^ uVar4 << 1;
  DES_encrypt2_constprop_0();
  DES_encrypt2_constprop_1(data,ks2);
  DES_encrypt2_constprop_0(data,ks3);
  uVar1 = (*data ^ data[1] >> 1) & 0x55555555;
  uVar2 = data[1] ^ uVar1 << 1;
  uVar1 = uVar1 ^ *data;
  uVar4 = (uVar2 ^ uVar1 >> 8) & 0xff00ff;
  uVar1 = uVar1 ^ uVar4 << 8;
  uVar4 = uVar4 ^ uVar2;
  uVar2 = (uVar1 ^ uVar4 >> 2) & 0x33333333;
  uVar4 = uVar4 ^ uVar2 << 2;
  uVar2 = uVar2 ^ uVar1;
  uVar1 = (uVar4 ^ uVar2 >> 0x10) & 0xffff;
  uVar2 = uVar2 ^ uVar1 << 0x10;
  uVar1 = uVar1 ^ uVar4;
  uVar4 = (uVar2 ^ uVar1 >> 4) & 0xf0f0f0f;
  *data = uVar2 ^ uVar4;
  data[1] = uVar1 ^ uVar4 << 4;
  return;
}

