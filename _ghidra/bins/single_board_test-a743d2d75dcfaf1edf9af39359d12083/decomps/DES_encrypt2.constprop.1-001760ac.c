
void DES_encrypt2_constprop_1(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *param_1 >> 0x1d | *param_1 << 3;
  uVar1 = param_2[0x1e] ^ uVar3;
  uVar2 = (param_2[0x1f] ^ uVar3) >> 4;
  uVar5 = *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          (param_1[1] >> 0x1d | param_1[1] << 3) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (param_2[0x1f] ^ uVar3) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar1 = uVar5 ^ param_2[0x1c];
  uVar2 = (uVar5 ^ param_2[0x1d]) >> 4;
  uVar4 = uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar5 ^ param_2[0x1d]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar4 ^ param_2[0x1a];
  uVar2 = (uVar4 ^ param_2[0x1b]) >> 4;
  uVar1 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar4 ^ param_2[0x1b]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar1 ^ param_2[0x18];
  uVar2 = (uVar1 ^ param_2[0x19]) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar1 ^ param_2[0x19]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar4 ^ param_2[0x16];
  uVar2 = (uVar4 ^ param_2[0x17]) >> 4;
  uVar1 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar4 ^ param_2[0x17]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar1 ^ param_2[0x14];
  uVar2 = (uVar1 ^ param_2[0x15]) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar1 ^ param_2[0x15]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar4 ^ param_2[0x12];
  uVar2 = (uVar4 ^ param_2[0x13]) >> 4;
  uVar1 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar4 ^ param_2[0x13]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar1 ^ param_2[0x10];
  uVar2 = (uVar1 ^ param_2[0x11]) >> 4;
  uVar4 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar1 ^ param_2[0x11]) << 0x1c) >> 0x1a) + 0x1c0) * 4
                   ) ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar4 ^ param_2[0xe];
  uVar2 = (uVar4 ^ param_2[0xf]) >> 4;
  uVar5 = *(uint *)(&DES_SPtrans + (((uVar2 | (uVar4 ^ param_2[0xf]) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
            *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
            *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar5 ^ param_2[0xc];
  uVar2 = (uVar5 ^ param_2[0xd]) >> 4;
  uVar1 = *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4) ^
          uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar5 ^ param_2[0xd]) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4);
  uVar3 = uVar1 ^ param_2[10];
  uVar2 = (uVar1 ^ param_2[0xb]) >> 4;
  uVar4 = uVar5 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar1 ^ param_2[0xb]) << 0x1c) >> 0x1a) + 0x1c0) * 4)
          ^ *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar3 = uVar4 ^ param_2[8];
  uVar2 = (uVar4 ^ param_2[9]) >> 4;
  uVar3 = *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar4 ^ param_2[9]) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4);
  uVar1 = uVar3 ^ param_2[6];
  uVar2 = (uVar3 ^ param_2[7]) >> 4;
  uVar1 = uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar3 ^ param_2[7]) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar4 = uVar1 ^ param_2[4];
  uVar2 = (uVar1 ^ param_2[5]) >> 4;
  uVar4 = *(uint *)(&DES_SPtrans + (((uVar2 | (uVar1 ^ param_2[5]) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          uVar3 ^ *(uint *)(&DES_SPtrans + ((uVar4 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar4 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar4 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar2 = (uVar4 ^ param_2[3]) >> 4;
  uVar3 = uVar4 ^ param_2[2];
  uVar3 = uVar1 ^ *(uint *)(&DES_SPtrans + ((uVar3 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar3 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar3 << 8) >> 0x1a) + 0x100) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (uVar4 ^ param_2[3]) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  uVar1 = *param_2 ^ uVar3;
  uVar2 = (param_2[1] ^ uVar3) >> 4;
  uVar2 = *(uint *)(&DES_SPtrans + (((uVar1 << 8) >> 0x1a) + 0x100) * 4) ^
          uVar4 ^ *(uint *)(&DES_SPtrans + ((uVar1 >> 0x1a) + 0x180) * 4) ^
          *(uint *)(&DES_SPtrans + ((uVar1 << 0x18) >> 0x1a) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar1 << 0x10) >> 0x1a) + 0x80) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 | (param_2[1] ^ uVar3) << 0x1c) >> 0x1a) + 0x1c0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x18) >> 0x1a) + 0x40) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 0x10) >> 0x1a) + 0xc0) * 4) ^
          *(uint *)(&DES_SPtrans + (((uVar2 << 8) >> 0x1a) + 0x140) * 4);
  *param_1 = uVar3 >> 3 | uVar3 << 0x1d;
  param_1[1] = uVar2 >> 3 | uVar2 << 0x1d;
  return;
}

