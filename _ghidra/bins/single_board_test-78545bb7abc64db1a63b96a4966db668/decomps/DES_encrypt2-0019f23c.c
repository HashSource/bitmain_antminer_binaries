
void DES_encrypt2(uint *data,DES_key_schedule *ks,int enc)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = *data >> 0x1d | *data << 3;
  uVar4 = data[1] >> 0x1d | data[1] << 3;
  if (enc == 0) {
    uVar6 = ks->ks[0xf].deslong[0] ^ uVar1;
    uVar2 = *(uint *)((int)ks->ks + 0x7c) ^ uVar1;
    uVar3 = uVar2 >> 4;
    uVar6 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar6 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
    uVar2 = uVar6 ^ ks->ks[0xe].deslong[0];
    uVar3 = *(uint *)((int)ks->ks + 0x74) ^ uVar6;
    uVar4 = uVar3 >> 4;
    uVar2 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar2 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 | uVar3 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[0xd].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x6c) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[0xc].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 100) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[0xb].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x5c) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[10].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x54) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[9].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x4c) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[8].deslong[0] ^ uVar6;
    uVar4 = *(uint *)((int)ks->ks + 0x44) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[7].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x3c) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[6].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x34) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[5].deslong[0] ^ uVar2;
    uVar4 = *(uint *)((int)ks->ks + 0x2c) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[4].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x24) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar9 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar2 = uVar9 ^ ks->ks[3].deslong[0];
    uVar3 = *(uint *)((int)ks->ks + 0x1c) ^ uVar9;
    uVar1 = uVar3 >> 4;
    uVar4 = ks->ks[1].deslong[0];
    uVar8 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar2 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar3 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar7 = ks->ks[2].deslong[0] ^ uVar8;
    uVar5 = *(uint *)((int)ks->ks + 0x14) ^ uVar8;
    uVar3 = uVar5 >> 4;
    uVar2 = *(uint *)((int)ks->ks + 0xc);
    uVar6 = ks->ks[0].deslong[0];
    uVar1 = ks->ks[0].deslong[1];
    uVar3 = *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar9 ^ *(uint *)(&DES_SPtrans + ((uVar7 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar7 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar7 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar7 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 | uVar5 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
  }
  else {
    uVar6 = ks->ks[0].deslong[0] ^ uVar1;
    uVar2 = ks->ks[0].deslong[1] ^ uVar1;
    uVar3 = uVar2 >> 4;
    uVar6 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar6 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 | uVar2 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x140) * 4);
    uVar2 = uVar6 ^ ks->ks[1].deslong[0];
    uVar3 = *(uint *)((int)ks->ks + 0xc) ^ uVar6;
    uVar4 = uVar3 >> 4;
    uVar2 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar2 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 | uVar3 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[2].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x14) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[3].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x1c) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[4].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x24) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[5].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x2c) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[6].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x34) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[7].deslong[0] ^ uVar6;
    uVar4 = *(uint *)((int)ks->ks + 0x3c) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar2 ^ ks->ks[8].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x44) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[9].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x4c) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar2 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = ks->ks[10].deslong[0] ^ uVar2;
    uVar4 = *(uint *)((int)ks->ks + 0x54) ^ uVar2;
    uVar1 = uVar4 >> 4;
    uVar6 = uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar3 = uVar6 ^ ks->ks[0xb].deslong[0];
    uVar4 = *(uint *)((int)ks->ks + 0x5c) ^ uVar6;
    uVar1 = uVar4 >> 4;
    uVar7 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar2 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar4 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar2 = uVar7 ^ ks->ks[0xc].deslong[0];
    uVar3 = *(uint *)((int)ks->ks + 100) ^ uVar7;
    uVar1 = uVar3 >> 4;
    uVar4 = ks->ks[0xe].deslong[0];
    uVar8 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            uVar6 ^ *(uint *)(&DES_SPtrans + ((uVar2 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar2 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar3 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar5 = ks->ks[0xd].deslong[0] ^ uVar8;
    uVar3 = *(uint *)((int)ks->ks + 0x6c) ^ uVar8;
    uVar1 = uVar3 >> 4;
    uVar2 = *(uint *)((int)ks->ks + 0x74);
    uVar6 = ks->ks[0xf].deslong[0];
    uVar3 = *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0xc0) * 4) ^
            uVar7 ^ *(uint *)(&DES_SPtrans + ((uVar5 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar5 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x100) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 | uVar3 << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 0x18) >> 0x1a) + 0x40) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x140) * 4);
    uVar1 = *(uint *)((int)ks->ks + 0x7c);
  }
  uVar4 = uVar3 ^ uVar4;
  uVar5 = (uVar2 ^ uVar3) >> 4;
  uVar2 = uVar8 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 | (uVar2 ^ uVar3) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar5 << 8) >> 0x1a) + 0x140) * 4);
  uVar6 = uVar2 ^ uVar6;
  uVar4 = (uVar1 ^ uVar2) >> 4;
  uVar1 = *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x140) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 | (uVar1 ^ uVar2) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar6 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar6 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar6 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar6 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0xc0) * 4);
  *data = uVar2 >> 3 | uVar2 << 0x1d;
  data[1] = uVar1 >> 3 | uVar1 << 0x1d;
  return;
}

