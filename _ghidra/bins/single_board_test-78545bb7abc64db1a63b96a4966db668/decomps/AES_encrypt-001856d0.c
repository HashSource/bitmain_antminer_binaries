
void AES_encrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  int local_40;
  
  iVar5 = key->rounds >> 1;
  uVar7 = key->rd_key[3] ^
          ((uint)in[0xf] ^ ((uint)in[0xd] << 0x10 | (uint)in[0xc] << 0x18) | (uint)in[0xe] << 8);
  uVar2 = key->rd_key[1] ^
          ((uint)in[7] ^ ((uint)in[5] << 0x10 | (uint)in[4] << 0x18) | (uint)in[6] << 8);
  uVar8 = (((uint)in[1] << 0x10 | (uint)*in << 0x18) ^ (uint)in[3] | (uint)in[2] << 8) ^
          key->rd_key[0];
  uVar10 = (((uint)in[9] << 0x10 | (uint)in[8] << 0x18) ^ (uint)in[0xb] | (uint)in[10] << 8) ^
           key->rd_key[2];
  puVar9 = key->rd_key + 0x14;
  local_40 = iVar5;
  while( true ) {
    uVar12 = *(uint *)(&Te0 + (uVar7 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar10 & 0xff) * 4) ^
             puVar9[-0xd] ^ *(uint *)(Te1 + ((uVar8 << 8) >> 0x18) * 4) ^
             *(uint *)(Te2 + ((uVar2 << 0x10) >> 0x18) * 4);
    HintPreloadData(puVar9);
    uVar11 = *(uint *)(&Te0 + (uVar8 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar7 & 0xff) * 4) ^
             puVar9[-0x10] ^ *(uint *)(Te1 + ((uVar2 << 8) >> 0x18) * 4) ^
             *(uint *)(Te2 + ((uVar10 << 0x10) >> 0x18) * 4);
    HintPreloadData(puVar9 + 1);
    uVar3 = *(uint *)(&Te0 + (uVar2 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar8 & 0xff) * 4) ^
            puVar9[-0xf] ^ *(uint *)(Te1 + ((uVar10 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar7 << 0x10) >> 0x18) * 4);
    local_40 = local_40 + -1;
    uVar7 = *(uint *)(Te2 + ((uVar8 << 0x10) >> 0x18) * 4) ^
            *(uint *)(Te1 + ((uVar7 << 8) >> 0x18) * 4) ^
            *(uint *)(Te3 + (uVar2 & 0xff) * 4) ^ *(uint *)(&Te0 + (uVar10 >> 0x18) * 4) ^
            puVar9[-0xe];
    if (local_40 == 0) break;
    uVar8 = *(uint *)(&Te0 + (uVar11 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar12 & 0xff) * 4) ^
            puVar9[-0xc] ^ *(uint *)(Te1 + ((uVar3 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar7 << 0x10) >> 0x18) * 4);
    uVar2 = *(uint *)(Te1 + ((uVar7 << 8) >> 0x18) * 4) ^
            puVar9[-0xb] ^
            *(uint *)(&Te0 + (uVar3 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar11 & 0xff) * 4) ^
            *(uint *)(Te2 + ((uVar12 << 0x10) >> 0x18) * 4);
    uVar10 = *(uint *)(&Te0 + (uVar7 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar3 & 0xff) * 4) ^
             puVar9[-10] ^ *(uint *)(Te1 + ((uVar12 << 8) >> 0x18) * 4) ^
             *(uint *)(Te2 + ((uVar11 << 0x10) >> 0x18) * 4);
    uVar7 = *(uint *)(Te2 + ((uVar3 << 0x10) >> 0x18) * 4) ^
            *(uint *)(Te1 + ((uVar11 << 8) >> 0x18) * 4) ^
            puVar9[-9] ^
            *(uint *)(Te3 + (uVar7 & 0xff) * 4) ^ *(uint *)(&Te0 + (uVar12 >> 0x18) * 4);
    puVar9 = puVar9 + 8;
  }
  uVar2 = *(uint *)(Te2 + (uVar3 >> 0x18) * 4);
  uVar6 = *(undefined4 *)(Te3 + ((uVar3 << 8) >> 0x18) * 4);
  uVar8 = key->rd_key[iVar5 * 8];
  uVar4 = *(undefined4 *)(&Te0 + ((uVar7 << 0x10) >> 0x18) * 4);
  uVar10 = *(uint *)(Te2 + (uVar11 >> 0x18) * 4) & 0xff000000 ^ (uint)(byte)Te1[(uVar12 & 0xff) * 4]
           ^ uVar8;
  out[3] = (uchar)uVar10;
  bVar1 = Te1[(uVar11 & 0xff) * 4];
  *out = (uchar)(uVar10 >> 0x18);
  out[1] = (byte)((uint)uVar6 >> 0x10) ^ (byte)(uVar8 >> 0x10);
  out[2] = (byte)((uint)uVar4 >> 8) ^ (byte)(uVar8 >> 8);
  uVar8 = key->rd_key[iVar5 * 8 + 1];
  uVar6 = *(undefined4 *)(Te3 + ((uVar7 << 8) >> 0x18) * 4);
  uVar4 = *(undefined4 *)(&Te0 + ((uVar12 << 0x10) >> 0x18) * 4);
  uVar2 = uVar2 & 0xff000000 ^ (uint)bVar1 ^ uVar8;
  uVar10 = *(uint *)(Te2 + (uVar7 >> 0x18) * 4);
  bVar1 = Te1[(uVar3 & 0xff) * 4];
  out[7] = (uchar)uVar2;
  out[4] = (uchar)(uVar2 >> 0x18);
  uVar13 = *(undefined4 *)(Te3 + ((uVar12 << 8) >> 0x18) * 4);
  out[5] = (byte)(uVar8 >> 0x10) ^ (byte)((uint)uVar6 >> 0x10);
  out[6] = (byte)((uint)uVar4 >> 8) ^ (byte)(uVar8 >> 8);
  uVar2 = key->rd_key[iVar5 * 8 + 2];
  uVar6 = *(undefined4 *)(&Te0 + ((uVar11 << 0x10) >> 0x18) * 4);
  uVar10 = uVar10 & 0xff000000 ^ (uint)bVar1 ^ uVar2;
  uVar8 = *(uint *)(Te2 + (uVar12 >> 0x18) * 4);
  bVar1 = Te1[(uVar7 & 0xff) * 4];
  out[0xb] = (uchar)uVar10;
  uVar4 = *(undefined4 *)(Te3 + ((uVar11 << 8) >> 0x18) * 4);
  out[8] = (uchar)(uVar10 >> 0x18);
  out[9] = (byte)(uVar2 >> 0x10) ^ (byte)((uint)uVar13 >> 0x10);
  out[10] = (byte)(uVar2 >> 8) ^ (byte)((uint)uVar6 >> 8);
  uVar2 = key->rd_key[iVar5 * 8 + 3];
  uVar6 = *(undefined4 *)(&Te0 + ((uVar3 << 0x10) >> 0x18) * 4);
  uVar7 = uVar2 ^ (uint)bVar1 ^ uVar8 & 0xff000000;
  out[0xf] = (uchar)uVar7;
  out[0xc] = (uchar)(uVar7 >> 0x18);
  out[0xd] = (byte)((uint)uVar4 >> 0x10) ^ (byte)(uVar2 >> 0x10);
  out[0xe] = (byte)((uint)uVar6 >> 8) ^ (byte)(uVar2 >> 8);
  return;
}

