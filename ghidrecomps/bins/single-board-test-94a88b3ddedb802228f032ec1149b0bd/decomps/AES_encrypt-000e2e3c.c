
void AES_encrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  AES_KEY *pAVar13;
  uint uVar14;
  uint uVar15;
  int local_34;
  
  iVar2 = DAT_000e3298;
  uVar7 = (((uint)in[9] << 0x10 | (uint)in[8] << 0x18) ^ (uint)in[0xb] | (uint)in[10] << 8) ^
          key->rd_key[2];
  iVar6 = key->rounds >> 1;
  uVar14 = (((uint)in[1] << 0x10 | (uint)*in << 0x18) ^ (uint)in[3] | (uint)in[2] << 8) ^
           key->rd_key[0];
  uVar5 = (((uint)in[5] << 0x10 | (uint)in[4] << 0x18) ^ (uint)in[7] | (uint)in[6] << 8) ^
          key->rd_key[1];
  uVar10 = (((uint)in[0xd] << 0x10 | (uint)in[0xc] << 0x18) ^ (uint)in[0xf] | (uint)in[0xe] << 8) ^
           key->rd_key[3];
  pAVar13 = key;
  local_34 = iVar6;
  while( true ) {
    HintPreloadData(pAVar13->rd_key + 0x14);
    HintPreloadData(pAVar13->rd_key + 0x15);
    uVar11 = *(uint *)(DAT_000e3298 + (uVar14 >> 0x18) * 4) ^
             *(uint *)(DAT_000e3298 + (uVar10 & 0xff) * 4 + 0xc00) ^ pAVar13->rd_key[4] ^
             *(uint *)(DAT_000e3298 + ((uVar5 << 8) >> 0x18) * 4 + 0x400) ^
             *(uint *)(DAT_000e3298 + ((uVar7 << 0x10) >> 0x18) * 4 + 0x800);
    uVar15 = *(uint *)(DAT_000e3298 + (uVar14 & 0xff) * 4 + 0xc00) ^
             *(uint *)(DAT_000e3298 + (uVar5 >> 0x18) * 4) ^ pAVar13->rd_key[5] ^
             *(uint *)(DAT_000e3298 + ((uVar7 << 8) >> 0x18) * 4 + 0x400) ^
             *(uint *)(DAT_000e3298 + ((uVar10 << 0x10) >> 0x18) * 4 + 0x800);
    uVar8 = *(uint *)(DAT_000e3298 + (uVar7 >> 0x18) * 4) ^
            *(uint *)(DAT_000e3298 + (uVar5 & 0xff) * 4 + 0xc00) ^ pAVar13->rd_key[6] ^
            *(uint *)(DAT_000e3298 + ((uVar10 << 8) >> 0x18) * 4 + 0x400) ^
            *(uint *)(DAT_000e3298 + ((uVar14 << 0x10) >> 0x18) * 4 + 0x800);
    local_34 = local_34 + -1;
    uVar10 = pAVar13->rd_key[7] ^
             *(uint *)(DAT_000e3298 + (uVar7 & 0xff) * 4 + 0xc00) ^
             *(uint *)(DAT_000e3298 + (uVar10 >> 0x18) * 4) ^
             *(uint *)(DAT_000e3298 + ((uVar14 << 8) >> 0x18) * 4 + 0x400) ^
             *(uint *)(DAT_000e3298 + ((uVar5 << 0x10) >> 0x18) * 4 + 0x800);
    if (local_34 == 0) break;
    uVar14 = *(uint *)(DAT_000e3298 + ((uVar15 << 8) >> 0x18) * 4 + 0x400) ^
             *(uint *)(DAT_000e3298 + (uVar11 >> 0x18) * 4) ^
             *(uint *)(DAT_000e3298 + (uVar10 & 0xff) * 4 + 0xc00) ^
             ((AES_KEY *)(pAVar13->rd_key + 8))->rd_key[0] ^
             *(uint *)(DAT_000e3298 + ((uVar8 << 0x10) >> 0x18) * 4 + 0x800);
    uVar5 = *(uint *)(DAT_000e3298 + ((uVar10 << 0x10) >> 0x18) * 4 + 0x800) ^
            *(uint *)(DAT_000e3298 + (uVar11 & 0xff) * 4 + 0xc00) ^
            *(uint *)(DAT_000e3298 + (uVar15 >> 0x18) * 4) ^ pAVar13->rd_key[9] ^
            *(uint *)(DAT_000e3298 + ((uVar8 << 8) >> 0x18) * 4 + 0x400);
    uVar7 = *(uint *)(DAT_000e3298 + (uVar8 >> 0x18) * 4) ^
            *(uint *)(DAT_000e3298 + (uVar15 & 0xff) * 4 + 0xc00) ^ pAVar13->rd_key[10] ^
            *(uint *)(DAT_000e3298 + ((uVar10 << 8) >> 0x18) * 4 + 0x400) ^
            *(uint *)(DAT_000e3298 + ((uVar11 << 0x10) >> 0x18) * 4 + 0x800);
    uVar10 = *(uint *)(DAT_000e3298 + ((uVar11 << 8) >> 0x18) * 4 + 0x400) ^
             pAVar13->rd_key[0xb] ^
             *(uint *)(DAT_000e3298 + (uVar8 & 0xff) * 4 + 0xc00) ^
             *(uint *)(DAT_000e3298 + (uVar10 >> 0x18) * 4) ^
             *(uint *)(DAT_000e3298 + ((uVar15 << 0x10) >> 0x18) * 4 + 0x800);
    pAVar13 = (AES_KEY *)(pAVar13->rd_key + 8);
  }
  uVar14 = key->rd_key[iVar6 * 8];
  uVar12 = *(undefined4 *)(DAT_000e3298 + ((uVar15 << 8) >> 0x18) * 4 + 0xc00);
  uVar4 = *(undefined4 *)(DAT_000e3298 + ((uVar8 << 0x10) >> 0x18) * 4);
  uVar7 = *(uint *)(DAT_000e3298 + (uVar11 >> 0x18) * 4 + 0x800) & 0xff000000 ^
          (uint)*(byte *)(DAT_000e3298 + (uVar10 & 0xff) * 4 + 0x400) ^ uVar14;
  uVar5 = *(uint *)(DAT_000e3298 + (uVar15 >> 0x18) * 4 + 0x800);
  bVar1 = *(byte *)(DAT_000e3298 + (uVar11 & 0xff) * 4 + 0x400);
  iVar3 = DAT_000e3298 + ((uVar8 << 8) >> 0x18) * 4;
  iVar9 = DAT_000e3298 + (uVar8 & 0xff) * 4;
  uVar8 = *(uint *)(DAT_000e3298 + (uVar8 >> 0x18) * 4 + 0x800);
  out[3] = (uchar)uVar7;
  out[1] = (byte)(uVar14 >> 0x10) ^ (byte)((uint)uVar12 >> 0x10);
  out[2] = (byte)((uint)uVar4 >> 8) ^ (byte)(uVar14 >> 8);
  *out = (uchar)(uVar7 >> 0x18);
  uVar7 = key->rd_key[iVar6 * 8 + 1];
  uVar4 = *(undefined4 *)(iVar2 + ((uVar10 << 0x10) >> 0x18) * 4);
  uVar5 = (uint)bVar1 ^ uVar5 & 0xff000000 ^ uVar7;
  bVar1 = *(byte *)(iVar2 + (uVar15 & 0xff) * 4 + 0x400);
  out[5] = (byte)(uVar7 >> 0x10) ^ (byte)((uint)*(undefined4 *)(iVar3 + 0xc00) >> 0x10);
  out[7] = (uchar)uVar5;
  out[4] = (uchar)(uVar5 >> 0x18);
  out[6] = (byte)((uint)uVar4 >> 8) ^ (byte)(uVar7 >> 8);
  uVar4 = *(undefined4 *)(iVar2 + ((uVar10 << 8) >> 0x18) * 4 + 0xc00);
  uVar5 = key->rd_key[iVar6 * 8 + 2];
  uVar12 = *(undefined4 *)(iVar2 + ((uVar11 << 0x10) >> 0x18) * 4);
  uVar7 = *(uint *)(iVar2 + (uVar10 >> 0x18) * 4 + 0x800);
  uVar10 = uVar5 ^ (uint)bVar1 ^ uVar8 & 0xff000000;
  bVar1 = *(byte *)(iVar9 + 0x400);
  out[0xb] = (uchar)uVar10;
  out[10] = (byte)(uVar5 >> 8) ^ (byte)((uint)uVar12 >> 8);
  uVar12 = *(undefined4 *)(iVar2 + ((uVar11 << 8) >> 0x18) * 4 + 0xc00);
  out[8] = (uchar)(uVar10 >> 0x18);
  out[9] = (byte)(uVar5 >> 0x10) ^ (byte)((uint)uVar4 >> 0x10);
  uVar5 = key->rd_key[iVar6 * 8 + 3];
  uVar4 = *(undefined4 *)(iVar2 + ((uVar15 << 0x10) >> 0x18) * 4);
  uVar7 = uVar7 & 0xff000000 ^ (uint)bVar1 ^ uVar5;
  out[0xf] = (uchar)uVar7;
  out[0xc] = (uchar)(uVar7 >> 0x18);
  out[0xd] = (byte)(uVar5 >> 0x10) ^ (byte)((uint)uVar12 >> 0x10);
  out[0xe] = (byte)(uVar5 >> 8) ^ (byte)((uint)uVar4 >> 8);
  return;
}

