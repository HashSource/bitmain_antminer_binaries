
void SM4_decrypt(byte *param_1,undefined1 *param_2,uint *param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar5 = (uint)param_1[5] << 0x10 | (uint)param_1[4] << 0x18 | (uint)param_1[7] |
          (uint)param_1[6] << 8;
  uVar7 = (uint)param_1[0xb] | (uint)param_1[9] << 0x10 | (uint)param_1[8] << 0x18 |
          (uint)param_1[10] << 8;
  uVar8 = (uint)param_1[0xd] << 0x10 | (uint)param_1[0xc] << 0x18 | (uint)param_1[0xf] |
          (uint)param_1[0xe] << 8;
  uVar6 = uVar7 ^ uVar5 ^ param_3[0x1f] ^ uVar8;
  uVar10 = (uint)(byte)SM4_S[uVar6 & 0xff] | (uint)(byte)SM4_S[uVar6 >> 0x18] << 0x18 |
           (uint)(byte)SM4_S[(uVar6 << 8) >> 0x18] << 0x10;
  uVar11 = uVar10 | (uint)(byte)SM4_S[(uVar6 << 0x10) >> 0x18] << 8;
  uVar11 = ((uint)param_1[1] << 0x10 | (uint)*param_1 << 0x18 | (uint)param_1[3] |
           (uint)param_1[2] << 8) ^ uVar11 ^
           (((uint)(byte)SM4_S[uVar6 >> 0x18] << 0x18) >> 0x1e | uVar11 << 2) ^
           (uVar10 >> 0x16 | uVar11 << 10) ^ (uVar11 >> 0xe | uVar11 << 0x12) ^
           (uVar11 >> 8 | (uint)(byte)SM4_S[uVar6 & 0xff] << 0x18);
  uVar10 = uVar8 ^ uVar7 ^ param_3[0x1e] ^ uVar11;
  uVar6 = (uint)(byte)SM4_S[uVar10 & 0xff] | (uint)(byte)SM4_S[uVar10 >> 0x18] << 0x18 |
          (uint)(byte)SM4_S[(uVar10 << 8) >> 0x18] << 0x10;
  uVar12 = uVar6 | (uint)(byte)SM4_S[(uVar10 << 0x10) >> 0x18] << 8;
  uVar10 = uVar5 ^ uVar12 ^ (((uint)(byte)SM4_S[uVar10 >> 0x18] << 0x18) >> 0x1e | uVar12 << 2) ^
           (uVar6 >> 0x16 | uVar12 << 10) ^ (uVar12 >> 0xe | uVar12 << 0x12) ^
           (uVar12 >> 8 | (uint)(byte)SM4_S[uVar10 & 0xff] << 0x18);
  uVar12 = uVar8 ^ param_3[0x1d] ^ uVar11 ^ uVar10;
  uVar6 = (uint)(byte)SM4_S[uVar12 & 0xff] | (uint)(byte)SM4_S[uVar12 >> 0x18] << 0x18 |
          (uint)(byte)SM4_S[(uVar12 << 8) >> 0x18] << 0x10;
  uVar5 = uVar6 | (uint)(byte)SM4_S[(uVar12 << 0x10) >> 0x18] << 8;
  uVar7 = uVar7 ^ uVar5 ^ (((uint)(byte)SM4_S[uVar12 >> 0x18] << 0x18) >> 0x1e | uVar5 << 2) ^
          (uVar6 >> 0x16 | uVar5 << 10) ^ (uVar5 >> 0xe | uVar5 << 0x12) ^
          (uVar5 >> 8 | (uint)(byte)SM4_S[uVar12 & 0xff] << 0x18);
  uVar5 = uVar11 ^ uVar10 ^ param_3[0x1c] ^ uVar7;
  uVar6 = (uint)(byte)SM4_S[uVar5 & 0xff] | (uint)(byte)SM4_S[uVar5 >> 0x18] << 0x18 |
          (uint)(byte)SM4_S[(uVar5 << 8) >> 0x18] << 0x10;
  uVar12 = uVar6 | (uint)(byte)SM4_S[(uVar5 << 0x10) >> 0x18] << 8;
  uVar5 = uVar8 ^ uVar12 ^ (((uint)(byte)SM4_S[uVar5 >> 0x18] << 0x18) >> 0x1e | uVar12 << 2) ^
          (uVar6 >> 0x16 | uVar12 << 10) ^ (uVar12 >> 0xe | uVar12 << 0x12) ^
          (uVar12 >> 8 | (uint)(byte)SM4_S[uVar5 & 0xff] << 0x18);
  uVar6 = uVar10 ^ param_3[0x1b] ^ uVar7 ^ uVar5;
  uVar12 = uVar11 ^ *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar6 = uVar7 ^ param_3[0x1a] ^ uVar5 ^ uVar12;
  uVar11 = uVar10 ^ *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar6 = uVar5 ^ param_3[0x19] ^ uVar12 ^ uVar11;
  uVar10 = uVar7 ^ *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar6 = uVar12 ^ uVar11 ^ param_3[0x18] ^ uVar10;
  uVar5 = uVar5 ^ *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar6 = uVar11 ^ param_3[0x17] ^ uVar10 ^ uVar5;
  uVar12 = uVar12 ^ *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar6 = uVar10 ^ param_3[0x16] ^ uVar5 ^ uVar12;
  uVar7 = uVar11 ^ *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar6 = uVar5 ^ param_3[0x15] ^ uVar12 ^ uVar7;
  uVar8 = uVar10 ^ *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar6 = uVar12 ^ uVar7 ^ param_3[0x14] ^ uVar8;
  uVar10 = *(uint *)(&SM4_SBOX_T + (uVar6 >> 0x18) * 4) ^ uVar5 ^
           (*(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar6 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar6 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar7 ^ param_3[0x13] ^ uVar8 ^ uVar10;
  uVar11 = uVar12 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar8 ^ param_3[0x12] ^ uVar10 ^ uVar11;
  uVar6 = uVar7 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar10 ^ param_3[0x11] ^ uVar11 ^ uVar6;
  uVar12 = uVar8 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar11 ^ uVar6 ^ param_3[0x10] ^ uVar12;
  uVar7 = uVar10 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar6 ^ param_3[0xf] ^ uVar12 ^ uVar7;
  uVar10 = uVar11 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar12 ^ param_3[0xe] ^ uVar7 ^ uVar10;
  uVar11 = uVar6 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = param_3[0xd] ^ uVar7 ^ uVar10 ^ uVar11;
  uVar6 = uVar12 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = param_3[0xc] ^ uVar10 ^ uVar11 ^ uVar6;
  uVar7 = uVar7 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar11 ^ param_3[0xb] ^ uVar6 ^ uVar7;
  uVar10 = uVar10 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = param_3[10] ^ uVar6 ^ uVar7 ^ uVar10;
  uVar11 = uVar11 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = param_3[9] ^ uVar7 ^ uVar10 ^ uVar11;
  uVar12 = uVar6 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar10 ^ uVar11 ^ param_3[8] ^ uVar12;
  uVar6 = *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^ uVar7 ^
          (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar11 ^ param_3[7] ^ uVar12 ^ uVar6;
  uVar8 = uVar10 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar12 ^ param_3[6] ^ uVar6 ^ uVar8;
  uVar9 = uVar11 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
          (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
          *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
          (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
          *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar6 ^ param_3[5] ^ uVar8 ^ uVar9;
  uVar13 = uVar12 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar5 = uVar8 ^ uVar9 ^ param_3[4] ^ uVar13;
  uVar12 = uVar6 ^ *(uint *)(&SM4_SBOX_T + (uVar5 >> 0x18) * 4) ^
           (*(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) >> 0x18 |
           *(uint *)(&SM4_SBOX_T + (uVar5 & 0xff) * 4) << 8) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) >> 8 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 8) >> 0x18) * 4) << 0x18) ^
           (*(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) >> 0x10 |
           *(uint *)(&SM4_SBOX_T + ((uVar5 << 0x10) >> 0x18) * 4) << 0x10);
  uVar7 = uVar9 ^ param_3[3] ^ uVar13 ^ uVar12;
  uVar10 = *param_3;
  uVar5 = (uint)(byte)SM4_S[uVar7 & 0xff] | (uint)(byte)SM4_S[uVar7 >> 0x18] << 0x18 |
          (uint)(byte)SM4_S[(uVar7 << 8) >> 0x18] << 0x10;
  uVar11 = param_3[1];
  uVar6 = uVar5 | (uint)(byte)SM4_S[(uVar7 << 0x10) >> 0x18] << 8;
  uVar7 = uVar8 ^ uVar6 ^ (((uint)(byte)SM4_S[uVar7 >> 0x18] << 0x18) >> 0x1e | uVar6 << 2) ^
          (uVar5 >> 0x16 | uVar6 << 10) ^ (uVar6 >> 0xe | uVar6 << 0x12) ^
          (uVar6 >> 8 | (uint)(byte)SM4_S[uVar7 & 0xff] << 0x18);
  uVar5 = uVar13 ^ param_3[2] ^ uVar12 ^ uVar7;
  param_2[0xf] = (char)uVar7;
  bVar1 = SM4_S[uVar5 >> 0x18];
  bVar2 = SM4_S[uVar5 & 0xff];
  bVar3 = SM4_S[(uVar5 << 8) >> 0x18];
  bVar4 = SM4_S[(uVar5 << 0x10) >> 0x18];
  param_2[0xc] = (char)(uVar7 >> 0x18);
  param_2[0xe] = (char)(uVar7 >> 8);
  uVar5 = (uint)bVar2 | (uint)bVar1 << 0x18 | (uint)bVar3 << 0x10;
  param_2[0xd] = (char)(uVar7 >> 0x10);
  uVar6 = uVar5 | (uint)bVar4 << 8;
  uVar5 = uVar9 ^ uVar6 ^ (((uint)bVar1 << 0x18) >> 0x1e | uVar6 << 2) ^
          (uVar5 >> 0x16 | uVar6 << 10) ^ (uVar6 >> 0xe | uVar6 << 0x12) ^
          (uVar6 >> 8 | (uint)bVar2 << 0x18);
  uVar6 = uVar11 ^ uVar12 ^ uVar7 ^ uVar5;
  param_2[0xb] = (char)uVar5;
  bVar1 = SM4_S[uVar6 >> 0x18];
  bVar2 = SM4_S[uVar6 & 0xff];
  bVar3 = SM4_S[(uVar6 << 8) >> 0x18];
  bVar4 = SM4_S[(uVar6 << 0x10) >> 0x18];
  param_2[10] = (char)(uVar5 >> 8);
  param_2[9] = (char)(uVar5 >> 0x10);
  uVar6 = (uint)bVar2 | (uint)bVar1 << 0x18 | (uint)bVar3 << 0x10;
  param_2[8] = (char)(uVar5 >> 0x18);
  uVar11 = uVar6 | (uint)bVar4 << 8;
  uVar6 = uVar13 ^ uVar11 ^ (((uint)bVar1 << 0x18) >> 0x1e | uVar11 << 2) ^
          (uVar6 >> 0x16 | uVar11 << 10) ^ (uVar11 >> 0xe | uVar11 << 0x12) ^
          (uVar11 >> 8 | (uint)bVar2 << 0x18);
  uVar5 = uVar7 ^ uVar5 ^ uVar10 ^ uVar6;
  bVar1 = SM4_S[uVar5 >> 0x18];
  bVar2 = SM4_S[uVar5 & 0xff];
  bVar3 = SM4_S[(uVar5 << 8) >> 0x18];
  param_2[7] = (char)uVar6;
  bVar4 = SM4_S[(uVar5 << 0x10) >> 0x18];
  param_2[4] = (char)(uVar6 >> 0x18);
  param_2[5] = (char)(uVar6 >> 0x10);
  uVar7 = (uint)bVar2 | (uint)bVar1 << 0x18 | (uint)bVar3 << 0x10;
  param_2[6] = (char)(uVar6 >> 8);
  uVar5 = uVar7 | (uint)bVar4 << 8;
  uVar5 = uVar12 ^ uVar5 ^ (((uint)bVar1 << 0x18) >> 0x1e | uVar5 << 2) ^
          (uVar7 >> 0x16 | uVar5 << 10) ^ (uVar5 >> 0xe | uVar5 << 0x12) ^
          (uVar5 >> 8 | (uint)bVar2 << 0x18);
  param_2[3] = (char)uVar5;
  *param_2 = (char)(uVar5 >> 0x18);
  param_2[1] = (char)(uVar5 >> 0x10);
  param_2[2] = (char)(uVar5 >> 8);
  return;
}

