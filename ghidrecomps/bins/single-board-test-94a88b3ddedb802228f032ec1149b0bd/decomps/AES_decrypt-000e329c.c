
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
  byte bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  AES_KEY *pAVar17;
  uint uVar18;
  uint uVar19;
  int local_30;
  
  iVar10 = DAT_000e36f8;
  iVar14 = key->rounds >> 1;
  uVar19 = (((uint)in[9] << 0x10 | (uint)in[8] << 0x18) ^ (uint)in[0xb] | (uint)in[10] << 8) ^
           key->rd_key[2];
  uVar15 = (((uint)in[1] << 0x10 | (uint)*in << 0x18) ^ (uint)in[3] | (uint)in[2] << 8) ^
           key->rd_key[0];
  uVar12 = (((uint)in[0xd] << 0x10 | (uint)in[0xc] << 0x18) ^ (uint)in[0xf] | (uint)in[0xe] << 8) ^
           key->rd_key[3];
  uVar18 = (((uint)in[5] << 0x10 | (uint)in[4] << 0x18) ^ (uint)in[7] | (uint)in[6] << 8) ^
           key->rd_key[1];
  pAVar17 = key;
  local_30 = iVar14;
  while( true ) {
    HintPreloadData(pAVar17->rd_key + 0x14);
    HintPreloadData(pAVar17->rd_key + 0x15);
    uVar16 = pAVar17->rd_key[4] ^
             *(uint *)(Td0 + (uVar15 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar18 & 0xff) * 4) ^
             *(uint *)(Td1 + ((uVar12 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar19 << 0x10) >> 0x18) * 4);
    uVar13 = *(uint *)(Td2 + ((uVar12 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar18 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar19 & 0xff) * 4) ^
             pAVar17->rd_key[5] ^ *(uint *)(Td1 + ((uVar15 << 8) >> 0x18) * 4);
    uVar11 = *(uint *)(Td2 + ((uVar15 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar19 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar12 & 0xff) * 4) ^
             pAVar17->rd_key[6] ^ *(uint *)(Td1 + ((uVar18 << 8) >> 0x18) * 4);
    uVar12 = *(uint *)(Td2 + ((uVar18 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td1 + ((uVar19 << 8) >> 0x18) * 4) ^
             pAVar17->rd_key[7] ^
             *(uint *)(Td3 + (uVar15 & 0xff) * 4) ^ *(uint *)(Td0 + (uVar12 >> 0x18) * 4);
    local_30 = local_30 + -1;
    if (local_30 == 0) break;
    uVar15 = *(uint *)(DAT_000e36f8 + (uVar16 >> 0x18) * 4 + 0x308) ^
             *(uint *)(DAT_000e36f8 + (uVar13 & 0xff) * 4 + -0xf8) ^
             ((AES_KEY *)(pAVar17->rd_key + 8))->rd_key[0] ^
             *(uint *)(Td1 + ((uVar12 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar11 << 0x10) >> 0x18) * 4);
    uVar18 = *(uint *)(DAT_000e36f8 + (uVar13 >> 0x18) * 4 + 0x308) ^
             *(uint *)(DAT_000e36f8 + (uVar11 & 0xff) * 4 + -0xf8) ^ pAVar17->rd_key[9] ^
             *(uint *)(Td1 + ((uVar16 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar12 << 0x10) >> 0x18) * 4);
    uVar19 = *(uint *)(DAT_000e36f8 + (uVar11 >> 0x18) * 4 + 0x308) ^
             *(uint *)(DAT_000e36f8 + (uVar12 & 0xff) * 4 + -0xf8) ^ pAVar17->rd_key[10] ^
             *(uint *)(Td1 + ((uVar13 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar16 << 0x10) >> 0x18) * 4);
    uVar12 = *(uint *)(Td1 + ((uVar11 << 8) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar16 & 0xff) * 4) ^
             pAVar17->rd_key[0xb] ^ *(uint *)(Td2 + ((uVar13 << 0x10) >> 0x18) * 4);
    pAVar17 = (AES_KEY *)(pAVar17->rd_key + 8);
  }
  bVar1 = *(byte *)(DAT_000e36f8 + (uVar16 >> 0x18) + 0xf08);
  uVar15 = key->rd_key[iVar14 * 8];
  bVar2 = *(byte *)(DAT_000e36f8 + (uVar13 >> 0x18) + 0xf08);
  bVar3 = *(byte *)(DAT_000e36f8 + (uVar11 & 0xff) + 0xf08);
  bVar4 = *(byte *)(((uVar12 << 8) >> 0x18) + DAT_000e36f8 + 0xf08);
  bVar5 = *(byte *)(DAT_000e36f8 + ((uVar11 << 0x10) >> 0x18) + 0xf08);
  bVar6 = *(byte *)(DAT_000e36f8 + ((uVar16 << 8) >> 0x18) + 0xf08);
  bVar7 = *(byte *)(DAT_000e36f8 + ((uVar12 << 0x10) >> 0x18) + 0xf08);
  out[3] = (byte)uVar15 ^ *(byte *)(DAT_000e36f8 + (uVar13 & 0xff) + 0xf08);
  *out = (byte)(uVar15 >> 0x18) ^ bVar1;
  out[2] = (byte)(uVar15 >> 8) ^ bVar5;
  out[1] = (byte)(uVar15 >> 0x10) ^ bVar4;
  uVar15 = key->rd_key[iVar14 * 8 + 1];
  bVar1 = *(byte *)(iVar10 + (uVar12 & 0xff) + 0xf08);
  bVar4 = *(byte *)(iVar10 + (uVar12 >> 0x18) + 0xf08);
  bVar5 = *(byte *)(iVar10 + (uVar11 >> 0x18) + 0xf08);
  bVar8 = *(byte *)(iVar10 + ((uVar13 << 8) >> 0x18) + 0xf08);
  bVar9 = *(byte *)(iVar10 + ((uVar11 << 8) >> 0x18) + 0xf08);
  out[7] = (byte)uVar15 ^ bVar3;
  out[5] = (byte)(uVar15 >> 0x10) ^ bVar6;
  out[6] = (byte)(uVar15 >> 8) ^ bVar7;
  out[4] = (byte)(uVar15 >> 0x18) ^ bVar2;
  uVar15 = key->rd_key[iVar14 * 8 + 2];
  bVar2 = *(byte *)(((uVar16 << 0x10) >> 0x18) + iVar10 + 0xf08);
  bVar3 = *(byte *)(iVar10 + ((uVar13 << 0x10) >> 0x18) + 0xf08);
  bVar6 = *(byte *)(iVar10 + (uVar16 & 0xff) + 0xf08);
  out[0xb] = bVar1 ^ (byte)uVar15;
  out[8] = (byte)(uVar15 >> 0x18) ^ bVar5;
  out[9] = (byte)(uVar15 >> 0x10) ^ bVar8;
  out[10] = (byte)(uVar15 >> 8) ^ bVar2;
  uVar15 = key->rd_key[iVar14 * 8 + 3];
  out[0xf] = (byte)uVar15 ^ bVar6;
  out[0xc] = (byte)(uVar15 >> 0x18) ^ bVar4;
  out[0xd] = (byte)(uVar15 >> 0x10) ^ bVar9;
  out[0xe] = (byte)(uVar15 >> 8) ^ bVar3;
  return;
}

