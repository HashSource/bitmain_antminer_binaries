
void AES_decrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  int local_40;
  
  iVar10 = key->rounds >> 1;
  uVar11 = ((uint)in[0xb] ^ ((uint)in[9] << 0x10 | (uint)in[8] << 0x18) | (uint)in[10] << 8) ^
           key->rd_key[2];
  uVar13 = (((uint)in[5] << 0x10 | (uint)in[4] << 0x18) ^ (uint)in[7] | (uint)in[6] << 8) ^
           key->rd_key[1];
  uVar16 = (((uint)in[1] << 0x10 | (uint)*in << 0x18) ^ (uint)in[3] | (uint)in[2] << 8) ^
           key->rd_key[0];
  uVar9 = (((uint)in[0xd] << 0x10 | (uint)in[0xc] << 0x18) ^ (uint)in[0xf] | (uint)in[0xe] << 8) ^
          key->rd_key[3];
  puVar15 = key->rd_key + 0x14;
  local_40 = iVar10;
  while( true ) {
    HintPreloadData(puVar15);
    uVar17 = *(uint *)(Td0 + (uVar16 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar13 & 0xff) * 4) ^
             puVar15[-0x10] ^ *(uint *)(Td1 + ((uVar9 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar11 << 0x10) >> 0x18) * 4);
    uVar14 = *(uint *)(Td0 + (uVar13 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar11 & 0xff) * 4) ^
             puVar15[-0xf] ^ *(uint *)(Td1 + ((uVar16 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar9 << 0x10) >> 0x18) * 4);
    local_40 = local_40 + -1;
    HintPreloadData(puVar15 + 1);
    uVar12 = *(uint *)(Td2 + ((uVar16 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td1 + ((uVar13 << 8) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar11 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar9 & 0xff) * 4) ^
             puVar15[-0xe];
    uVar9 = *(uint *)(Td2 + ((uVar13 << 0x10) >> 0x18) * 4) ^
            *(uint *)(Td1 + ((uVar11 << 8) >> 0x18) * 4) ^
            *(uint *)(Td0 + (uVar9 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar16 & 0xff) * 4) ^
            puVar15[-0xd];
    if (local_40 == 0) break;
    uVar16 = *(uint *)(Td0 + (uVar17 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar14 & 0xff) * 4) ^
             puVar15[-0xc] ^ *(uint *)(Td1 + ((uVar9 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar12 << 0x10) >> 0x18) * 4);
    uVar13 = *(uint *)(Td2 + ((uVar9 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar14 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar12 & 0xff) * 4) ^
             puVar15[-0xb] ^ *(uint *)(Td1 + ((uVar17 << 8) >> 0x18) * 4);
    uVar11 = *(uint *)(Td2 + ((uVar17 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar9 & 0xff) * 4) ^
             puVar15[-10] ^ *(uint *)(Td1 + ((uVar14 << 8) >> 0x18) * 4);
    uVar9 = *(uint *)(Td1 + ((uVar12 << 8) >> 0x18) * 4) ^
            *(uint *)(Td0 + (uVar9 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar17 & 0xff) * 4) ^
            puVar15[-9] ^ *(uint *)(Td2 + ((uVar14 << 0x10) >> 0x18) * 4);
    puVar15 = puVar15 + 8;
  }
  uVar11 = key->rd_key[iVar10 * 8];
  bVar1 = Td4[uVar17 >> 0x18];
  bVar2 = Td4[(uVar9 << 8) >> 0x18];
  bVar3 = Td4[(uVar12 << 0x10) >> 0x18];
  bVar4 = Td4[uVar12 & 0xff];
  out[3] = (byte)uVar11 ^ Td4[uVar14 & 0xff];
  out[1] = (byte)(uVar11 >> 0x10) ^ bVar2;
  out[2] = (byte)(uVar11 >> 8) ^ bVar3;
  *out = (byte)(uVar11 >> 0x18) ^ bVar1;
  bVar1 = Td4[uVar14 >> 0x18];
  uVar11 = key->rd_key[iVar10 * 8 + 1];
  bVar2 = Td4[(uVar17 << 8) >> 0x18];
  bVar3 = Td4[(uVar9 << 0x10) >> 0x18];
  bVar5 = Td4[uVar9 >> 0x18];
  bVar6 = Td4[uVar9 & 0xff];
  bVar7 = Td4[uVar12 >> 0x18];
  out[7] = bVar4 ^ (byte)uVar11;
  out[4] = (byte)(uVar11 >> 0x18) ^ bVar1;
  out[5] = (byte)(uVar11 >> 0x10) ^ bVar2;
  out[6] = (byte)(uVar11 >> 8) ^ bVar3;
  bVar1 = Td4[(uVar14 << 8) >> 0x18];
  bVar2 = Td4[(uVar17 << 0x10) >> 0x18];
  uVar11 = key->rd_key[iVar10 * 8 + 2];
  bVar3 = Td4[(uVar12 << 8) >> 0x18];
  bVar4 = Td4[uVar17 & 0xff];
  bVar8 = Td4[(uVar14 << 0x10) >> 0x18];
  out[0xb] = bVar6 ^ (byte)uVar11;
  out[10] = (byte)(uVar11 >> 8) ^ bVar2;
  out[9] = (byte)(uVar11 >> 0x10) ^ bVar1;
  out[8] = (byte)(uVar11 >> 0x18) ^ bVar7;
  uVar11 = key->rd_key[iVar10 * 8 + 3];
  out[0xf] = (byte)uVar11 ^ bVar4;
  out[0xc] = (byte)(uVar11 >> 0x18) ^ bVar5;
  out[0xd] = (byte)(uVar11 >> 0x10) ^ bVar3;
  out[0xe] = (byte)(uVar11 >> 8) ^ bVar8;
  return;
}

