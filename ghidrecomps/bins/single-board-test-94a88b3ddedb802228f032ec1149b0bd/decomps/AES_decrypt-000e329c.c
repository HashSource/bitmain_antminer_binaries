
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
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  AES_KEY *pAVar16;
  uint uVar17;
  uint uVar18;
  int local_30;
  
  iVar13 = key->rounds >> 1;
  uVar18 = (((uint)in[9] << 0x10 | (uint)in[8] << 0x18) ^ (uint)in[0xb] | (uint)in[10] << 8) ^
           key->rd_key[2];
  uVar14 = (((uint)in[1] << 0x10 | (uint)*in << 0x18) ^ (uint)in[3] | (uint)in[2] << 8) ^
           key->rd_key[0];
  uVar11 = (((uint)in[0xd] << 0x10 | (uint)in[0xc] << 0x18) ^ (uint)in[0xf] | (uint)in[0xe] << 8) ^
           key->rd_key[3];
  uVar17 = (((uint)in[5] << 0x10 | (uint)in[4] << 0x18) ^ (uint)in[7] | (uint)in[6] << 8) ^
           key->rd_key[1];
  pAVar16 = key;
  local_30 = iVar13;
  while( true ) {
    HintPreloadData(pAVar16->rd_key + 0x14);
    HintPreloadData(pAVar16->rd_key + 0x15);
    uVar15 = pAVar16->rd_key[4] ^
             *(uint *)(Td0 + (uVar14 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar17 & 0xff) * 4) ^
             *(uint *)(Td1 + ((uVar11 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar18 << 0x10) >> 0x18) * 4);
    uVar12 = *(uint *)(Td2 + ((uVar11 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar17 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar18 & 0xff) * 4) ^
             pAVar16->rd_key[5] ^ *(uint *)(Td1 + ((uVar14 << 8) >> 0x18) * 4);
    uVar10 = *(uint *)(Td2 + ((uVar14 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar18 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar11 & 0xff) * 4) ^
             pAVar16->rd_key[6] ^ *(uint *)(Td1 + ((uVar17 << 8) >> 0x18) * 4);
    uVar11 = *(uint *)(Td2 + ((uVar17 << 0x10) >> 0x18) * 4) ^
             *(uint *)(Td1 + ((uVar18 << 8) >> 0x18) * 4) ^
             pAVar16->rd_key[7] ^
             *(uint *)(Td3 + (uVar14 & 0xff) * 4) ^ *(uint *)(Td0 + (uVar11 >> 0x18) * 4);
    local_30 = local_30 + -1;
    if (local_30 == 0) break;
    uVar14 = *(uint *)(Td0 + (uVar15 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar12 & 0xff) * 4) ^
             ((AES_KEY *)(pAVar16->rd_key + 8))->rd_key[0] ^
             *(uint *)(Td1 + ((uVar11 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar10 << 0x10) >> 0x18) * 4);
    uVar17 = *(uint *)(Td0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar10 & 0xff) * 4) ^
             pAVar16->rd_key[9] ^ *(uint *)(Td1 + ((uVar15 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar11 << 0x10) >> 0x18) * 4);
    uVar18 = *(uint *)(Td0 + (uVar10 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar11 & 0xff) * 4) ^
             pAVar16->rd_key[10] ^ *(uint *)(Td1 + ((uVar12 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar15 << 0x10) >> 0x18) * 4);
    uVar11 = *(uint *)(Td1 + ((uVar10 << 8) >> 0x18) * 4) ^
             *(uint *)(Td0 + (uVar11 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar15 & 0xff) * 4) ^
             pAVar16->rd_key[0xb] ^ *(uint *)(Td2 + ((uVar12 << 0x10) >> 0x18) * 4);
    pAVar16 = (AES_KEY *)(pAVar16->rd_key + 8);
  }
  bVar1 = (&Td4)[uVar15 >> 0x18];
  uVar14 = key->rd_key[iVar13 * 8];
  bVar2 = (&Td4)[uVar12 >> 0x18];
  bVar3 = (&Td4)[uVar10 & 0xff];
  bVar4 = (&Td4)[(uVar11 << 8) >> 0x18];
  bVar5 = (&Td4)[(uVar10 << 0x10) >> 0x18];
  bVar6 = (&Td4)[(uVar15 << 8) >> 0x18];
  bVar7 = (&Td4)[(uVar11 << 0x10) >> 0x18];
  out[3] = (byte)uVar14 ^ (&Td4)[uVar12 & 0xff];
  *out = (byte)(uVar14 >> 0x18) ^ bVar1;
  out[2] = (byte)(uVar14 >> 8) ^ bVar5;
  out[1] = (byte)(uVar14 >> 0x10) ^ bVar4;
  uVar14 = key->rd_key[iVar13 * 8 + 1];
  bVar1 = (&Td4)[uVar11 & 0xff];
  bVar4 = (&Td4)[uVar11 >> 0x18];
  bVar5 = (&Td4)[uVar10 >> 0x18];
  bVar8 = (&Td4)[(uVar12 << 8) >> 0x18];
  bVar9 = (&Td4)[(uVar10 << 8) >> 0x18];
  out[7] = (byte)uVar14 ^ bVar3;
  out[5] = (byte)(uVar14 >> 0x10) ^ bVar6;
  out[6] = (byte)(uVar14 >> 8) ^ bVar7;
  out[4] = (byte)(uVar14 >> 0x18) ^ bVar2;
  uVar14 = key->rd_key[iVar13 * 8 + 2];
  bVar2 = (&Td4)[(uVar15 << 0x10) >> 0x18];
  bVar3 = (&Td4)[(uVar12 << 0x10) >> 0x18];
  bVar6 = (&Td4)[uVar15 & 0xff];
  out[0xb] = bVar1 ^ (byte)uVar14;
  out[8] = (byte)(uVar14 >> 0x18) ^ bVar5;
  out[9] = (byte)(uVar14 >> 0x10) ^ bVar8;
  out[10] = (byte)(uVar14 >> 8) ^ bVar2;
  uVar14 = key->rd_key[iVar13 * 8 + 3];
  out[0xf] = (byte)uVar14 ^ bVar6;
  out[0xc] = (byte)(uVar14 >> 0x18) ^ bVar4;
  out[0xd] = (byte)(uVar14 >> 0x10) ^ bVar9;
  out[0xe] = (byte)(uVar14 >> 8) ^ bVar3;
  return;
}

