
void DES_encrypt3(uint *data,DES_key_schedule *ks1,DES_key_schedule *ks2,DES_key_schedule *ks3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (*data ^ data[1] >> 4) & 0xf0f0f0f;
  uVar4 = data[1] ^ uVar2 << 4;
  uVar2 = *data ^ uVar2;
  uVar3 = (uVar4 ^ uVar2 >> 0x10) & 0xffff;
  uVar2 = uVar2 ^ uVar3 << 0x10;
  uVar4 = uVar4 ^ uVar3;
  uVar3 = (uVar2 ^ uVar4 >> 2) & 0x33333333;
  uVar4 = uVar4 ^ uVar3 << 2;
  uVar3 = uVar3 ^ uVar2;
  uVar2 = (uVar4 ^ uVar3 >> 8) & 0xff00ff;
  uVar3 = uVar3 ^ uVar2 << 8;
  uVar4 = uVar4 ^ uVar2;
  uVar2 = (uVar3 ^ uVar4 >> 1) & 0x55555555;
  *data = uVar3 ^ uVar2;
  data[1] = uVar4 ^ uVar2 << 1;
  DES_encrypt2(data,ks1,1);
  DES_encrypt2(data,ks2,0);
  DES_encrypt2(data,ks3,1);
  uVar3 = (*data ^ data[1] >> 1) & 0x55555555;
  uVar2 = data[1] ^ uVar3 << 1;
  uVar3 = uVar3 ^ *data;
  uVar4 = (uVar2 ^ uVar3 >> 8) & 0xff00ff;
  uVar3 = uVar3 ^ uVar4 << 8;
  uVar4 = uVar4 ^ uVar2;
  uVar1 = (uVar3 ^ uVar4 >> 2) & 0x33333333;
  uVar4 = uVar4 ^ uVar1 << 2;
  uVar1 = uVar1 ^ uVar3;
  uVar2 = (uVar4 ^ uVar1 >> 0x10) & 0xffff;
  uVar1 = uVar1 ^ uVar2 << 0x10;
  uVar4 = uVar4 ^ uVar2;
  uVar2 = (uVar1 ^ uVar4 >> 4) & 0xf0f0f0f;
  *data = uVar1 ^ uVar2;
  data[1] = uVar4 ^ uVar2 << 4;
  return;
}

