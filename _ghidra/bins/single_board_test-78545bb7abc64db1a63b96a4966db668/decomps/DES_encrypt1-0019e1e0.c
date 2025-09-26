
void DES_encrypt1(uint *data,DES_key_schedule *ks,int enc)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = (*data ^ data[1] >> 4) & 0xf0f0f0f;
  uVar4 = data[1] ^ uVar2 << 4;
  uVar2 = uVar2 ^ *data;
  uVar3 = (uVar4 ^ uVar2 >> 0x10) & 0xffff;
  uVar2 = uVar2 ^ uVar3 << 0x10;
  uVar3 = uVar3 ^ uVar4;
  uVar4 = (uVar2 ^ uVar3 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar4 << 2;
  uVar4 = uVar4 ^ uVar2;
  uVar2 = (uVar3 ^ uVar4 >> 8) & 0xff00ff;
  uVar4 = uVar4 ^ uVar2 << 8;
  uVar3 = uVar3 ^ uVar2;
  uVar2 = (uVar4 ^ uVar3 >> 1) & 0x55555555;
  uVar3 = uVar3 ^ uVar2 << 1;
  uVar2 = uVar2 ^ uVar4;
  uVar2 = uVar2 >> 0x1d | uVar2 << 3;
  uVar4 = uVar3 >> 0x1d | uVar3 << 3;
  if (enc == 0) {
    uVar5 = ks->ks[0xf].deslong[0] ^ uVar2;
    uVar1 = *(uint *)((int)ks->ks + 0x7c) ^ uVar2;
    uVar3 = uVar1 >> 4;
    uVar7 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 | uVar1 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
    uVar1 = uVar7 ^ ks->ks[0xe].deslong[0];
    uVar3 = uVar7 ^ *(uint *)((int)ks->ks + 0x74);
    uVar4 = uVar3 >> 4;
    uVar5 = *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 | uVar3 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[0xd].deslong[0];
    uVar4 = uVar5 ^ *(uint *)((int)ks->ks + 0x6c);
    uVar2 = uVar4 >> 4;
    uVar1 = uVar7 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[0xc].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 100) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[0xb].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x5c) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[10].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x54) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[9].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x4c) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[8].deslong[0] ^ uVar1;
    uVar4 = *(uint *)((int)ks->ks + 0x44) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[7].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x3c) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[6].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x34) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[5].deslong[0] ^ uVar5;
    uVar4 = *(uint *)((int)ks->ks + 0x2c) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[4].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x24) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[3].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x1c) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar6 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar1 = ks->ks[2].deslong[0] ^ uVar6;
    uVar4 = *(uint *)((int)ks->ks + 0x14) ^ uVar6;
    uVar2 = uVar4 >> 4;
    uVar3 = ks->ks[0].deslong[0];
    uVar7 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar5 = ks->ks[0].deslong[1];
    uVar4 = uVar7 ^ ks->ks[1].deslong[0];
    uVar1 = *(uint *)((int)ks->ks + 0xc) ^ uVar7;
    uVar2 = uVar1 >> 4;
    uVar2 = uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar1 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  }
  else {
    uVar5 = ks->ks[0].deslong[0] ^ uVar2;
    uVar1 = ks->ks[0].deslong[1] ^ uVar2;
    uVar3 = uVar1 >> 4;
    uVar7 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 | uVar1 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
    uVar1 = uVar7 ^ ks->ks[1].deslong[0];
    uVar3 = uVar7 ^ *(uint *)((int)ks->ks + 0xc);
    uVar4 = uVar3 >> 4;
    uVar5 = *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 | uVar3 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[2].deslong[0];
    uVar4 = uVar5 ^ *(uint *)((int)ks->ks + 0x14);
    uVar2 = uVar4 >> 4;
    uVar1 = uVar7 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[3].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x1c) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[4].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x24) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[5].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x2c) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[6].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x34) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[7].deslong[0] ^ uVar1;
    uVar4 = *(uint *)((int)ks->ks + 0x3c) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[8].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x44) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[9].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x4c) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[10].deslong[0] ^ uVar5;
    uVar4 = *(uint *)((int)ks->ks + 0x54) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar1 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar1 ^ ks->ks[0xb].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x5c) ^ uVar1;
    uVar2 = uVar4 >> 4;
    uVar5 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar5 ^ ks->ks[0xc].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 100) ^ uVar5;
    uVar2 = uVar4 >> 4;
    uVar6 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar1 = ks->ks[0xd].deslong[0] ^ uVar6;
    uVar4 = *(uint *)((int)ks->ks + 0x6c) ^ uVar6;
    uVar2 = uVar4 >> 4;
    uVar3 = ks->ks[0xf].deslong[0];
    uVar7 = *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
    uVar5 = *(uint *)((int)ks->ks + 0x7c);
    uVar4 = uVar7 ^ ks->ks[0xe].deslong[0];
    uVar1 = *(uint *)((int)ks->ks + 0x74) ^ uVar7;
    uVar2 = uVar1 >> 4;
    uVar2 = *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 | uVar1 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4);
  }
  uVar3 = uVar2 ^ uVar3;
  uVar4 = (uVar5 ^ uVar2) >> 4;
  uVar1 = uVar2 >> 3 | uVar2 << 0x1d;
  uVar2 = *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 | (uVar5 ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          uVar7 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4);
  uVar2 = uVar2 >> 3 | uVar2 << 0x1d;
  uVar4 = (uVar1 ^ uVar2 >> 1) & 0x55555555;
  uVar2 = uVar2 ^ uVar4 << 1;
  uVar4 = uVar4 ^ uVar1;
  uVar3 = (uVar2 ^ uVar4 >> 8) & 0xff00ff;
  uVar4 = uVar4 ^ uVar3 << 8;
  uVar3 = uVar3 ^ uVar2;
  uVar1 = (uVar4 ^ uVar3 >> 2) & 0x33333333;
  uVar3 = uVar3 ^ uVar1 << 2;
  uVar1 = uVar1 ^ uVar4;
  uVar2 = (uVar3 ^ uVar1 >> 0x10) & 0xffff;
  uVar1 = uVar1 ^ uVar2 << 0x10;
  uVar3 = uVar3 ^ uVar2;
  uVar2 = (uVar1 ^ uVar3 >> 4) & 0xf0f0f0f;
  *data = uVar1 ^ uVar2;
  data[1] = uVar3 ^ uVar2 << 4;
  return;
}

