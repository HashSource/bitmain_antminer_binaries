
void BF_decrypt(uint *data,BF_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = key->P[0x11] ^ *data;
  uVar1 = key->P[0x10] ^ data[1] ^
          key->S[(uVar3 & 0xff) + 0x300] +
          (key->S[((uVar3 << 0x10) >> 0x18) + 0x200] ^
          key->S[uVar3 >> 0x18] + key->S[((uVar3 << 8) >> 0x18) + 0x100]);
  uVar4 = uVar3 ^ key->P[0xf] ^
          key->S[(uVar1 & 0xff) + 0x300] +
          (key->S[((uVar1 << 8) >> 0x18) + 0x100] + key->S[uVar1 >> 0x18] ^
          key->S[((uVar1 << 0x10) >> 0x18) + 0x200]);
  uVar3 = uVar1 ^ key->P[0xe] ^
          key->S[(uVar4 & 0xff) + 0x300] +
          (key->S[((uVar4 << 0x10) >> 0x18) + 0x200] ^
          key->S[((uVar4 << 8) >> 0x18) + 0x100] + key->S[uVar4 >> 0x18]);
  uVar1 = key->P[0xd] ^ uVar4 ^
          key->S[(uVar3 & 0xff) + 0x300] +
          (key->S[((uVar3 << 0x10) >> 0x18) + 0x200] ^
          key->S[((uVar3 << 8) >> 0x18) + 0x100] + key->S[uVar3 >> 0x18]);
  uVar3 = key->P[0xc] ^ uVar3 ^
          key->S[(uVar1 & 0xff) + 0x300] +
          (key->S[((uVar1 << 0x10) >> 0x18) + 0x200] ^
          key->S[uVar1 >> 0x18] + key->S[((uVar1 << 8) >> 0x18) + 0x100]);
  uVar1 = key->P[0xb] ^ uVar1 ^
          key->S[(uVar3 & 0xff) + 0x300] +
          (key->S[((uVar3 << 0x10) >> 0x18) + 0x200] ^
          key->S[uVar3 >> 0x18] + key->S[((uVar3 << 8) >> 0x18) + 0x100]);
  uVar4 = uVar3 ^ key->P[10] ^
          key->S[(uVar1 & 0xff) + 0x300] +
          (key->S[((uVar1 << 8) >> 0x18) + 0x100] + key->S[uVar1 >> 0x18] ^
          key->S[((uVar1 << 0x10) >> 0x18) + 0x200]);
  uVar3 = uVar1 ^ key->P[9] ^
          key->S[(uVar4 & 0xff) + 0x300] +
          (key->S[((uVar4 << 0x10) >> 0x18) + 0x200] ^
          key->S[((uVar4 << 8) >> 0x18) + 0x100] + key->S[uVar4 >> 0x18]);
  uVar1 = key->P[8] ^ uVar4 ^
          key->S[(uVar3 & 0xff) + 0x300] +
          (key->S[((uVar3 << 0x10) >> 0x18) + 0x200] ^
          key->S[((uVar3 << 8) >> 0x18) + 0x100] + key->S[uVar3 >> 0x18]);
  uVar3 = key->P[7] ^ uVar3 ^
          key->S[(uVar1 & 0xff) + 0x300] +
          (key->S[((uVar1 << 0x10) >> 0x18) + 0x200] ^
          key->S[((uVar1 << 8) >> 0x18) + 0x100] + key->S[uVar1 >> 0x18]);
  uVar1 = key->P[6] ^ uVar1 ^
          key->S[(uVar3 & 0xff) + 0x300] +
          (key->S[((uVar3 << 0x10) >> 0x18) + 0x200] ^
          key->S[uVar3 >> 0x18] + key->S[((uVar3 << 8) >> 0x18) + 0x100]);
  uVar4 = key->S[(uVar1 & 0xff) + 0x300] +
          (key->S[((uVar1 << 0x10) >> 0x18) + 0x200] ^
          key->S[uVar1 >> 0x18] + key->S[((uVar1 << 8) >> 0x18) + 0x100]) ^ key->P[5] ^ uVar3;
  uVar3 = key->S[(uVar4 & 0xff) + 0x300] +
          (key->S[((uVar4 << 0x10) >> 0x18) + 0x200] ^
          key->S[uVar4 >> 0x18] + key->S[((uVar4 << 8) >> 0x18) + 0x100]) ^ key->P[4] ^ uVar1;
  uVar6 = key->P[1];
  uVar1 = key->P[3] ^ uVar4 ^
          key->S[(uVar3 & 0xff) + 0x300] +
          (key->S[((uVar3 << 8) >> 0x18) + 0x100] + key->S[uVar3 >> 0x18] ^
          key->S[((uVar3 << 0x10) >> 0x18) + 0x200]);
  uVar3 = key->S[(uVar1 & 0xff) + 0x300] +
          (key->S[((uVar1 << 0x10) >> 0x18) + 0x200] ^
          key->S[uVar1 >> 0x18] + key->S[((uVar1 << 8) >> 0x18) + 0x100]) ^ uVar3 ^ key->P[2];
  uVar7 = key->S[((uVar3 << 8) >> 0x18) + 0x100];
  uVar5 = key->S[uVar3 >> 0x18];
  uVar2 = key->S[((uVar3 << 0x10) >> 0x18) + 0x200];
  uVar4 = key->S[(uVar3 & 0xff) + 0x300];
  *data = key->P[0] ^ uVar3;
  data[1] = uVar4 + (uVar7 + uVar5 ^ uVar2) ^ uVar1 ^ uVar6;
  return;
}

