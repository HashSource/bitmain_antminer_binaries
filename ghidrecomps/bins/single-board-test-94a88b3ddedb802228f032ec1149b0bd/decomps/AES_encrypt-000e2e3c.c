
void AES_encrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  AES_KEY *pAVar11;
  uint uVar12;
  uint uVar13;
  int local_34;
  
  uVar6 = (((uint)in[9] << 0x10 | (uint)in[8] << 0x18) ^ (uint)in[0xb] | (uint)in[10] << 8) ^
          key->rd_key[2];
  iVar5 = key->rounds >> 1;
  uVar12 = (((uint)in[1] << 0x10 | (uint)*in << 0x18) ^ (uint)in[3] | (uint)in[2] << 8) ^
           key->rd_key[0];
  uVar3 = (((uint)in[5] << 0x10 | (uint)in[4] << 0x18) ^ (uint)in[7] | (uint)in[6] << 8) ^
          key->rd_key[1];
  uVar8 = (((uint)in[0xd] << 0x10 | (uint)in[0xc] << 0x18) ^ (uint)in[0xf] | (uint)in[0xe] << 8) ^
          key->rd_key[3];
  pAVar11 = key;
  local_34 = iVar5;
  while( true ) {
    HintPreloadData(pAVar11->rd_key + 0x14);
    HintPreloadData(pAVar11->rd_key + 0x15);
    uVar9 = *(uint *)(&Te0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar8 & 0xff) * 4) ^
            pAVar11->rd_key[4] ^ *(uint *)(Te1 + ((uVar3 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar6 << 0x10) >> 0x18) * 4);
    uVar13 = *(uint *)(Te3 + (uVar12 & 0xff) * 4) ^ *(uint *)(&Te0 + (uVar3 >> 0x18) * 4) ^
             pAVar11->rd_key[5] ^ *(uint *)(Te1 + ((uVar6 << 8) >> 0x18) * 4) ^
             *(uint *)(Te2 + ((uVar8 << 0x10) >> 0x18) * 4);
    uVar7 = *(uint *)(&Te0 + (uVar6 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar3 & 0xff) * 4) ^
            pAVar11->rd_key[6] ^ *(uint *)(Te1 + ((uVar8 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar12 << 0x10) >> 0x18) * 4);
    local_34 = local_34 + -1;
    uVar8 = pAVar11->rd_key[7] ^
            *(uint *)(Te3 + (uVar6 & 0xff) * 4) ^ *(uint *)(&Te0 + (uVar8 >> 0x18) * 4) ^
            *(uint *)(Te1 + ((uVar12 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar3 << 0x10) >> 0x18) * 4);
    if (local_34 == 0) break;
    uVar12 = *(uint *)(Te1 + ((uVar13 << 8) >> 0x18) * 4) ^
             *(uint *)(&Te0 + (uVar9 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar8 & 0xff) * 4) ^
             ((AES_KEY *)(pAVar11->rd_key + 8))->rd_key[0] ^
             *(uint *)(Te2 + ((uVar7 << 0x10) >> 0x18) * 4);
    uVar3 = *(uint *)(Te2 + ((uVar8 << 0x10) >> 0x18) * 4) ^
            *(uint *)(Te3 + (uVar9 & 0xff) * 4) ^ *(uint *)(&Te0 + (uVar13 >> 0x18) * 4) ^
            pAVar11->rd_key[9] ^ *(uint *)(Te1 + ((uVar7 << 8) >> 0x18) * 4);
    uVar6 = *(uint *)(&Te0 + (uVar7 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar13 & 0xff) * 4) ^
            pAVar11->rd_key[10] ^ *(uint *)(Te1 + ((uVar8 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar9 << 0x10) >> 0x18) * 4);
    uVar8 = *(uint *)(Te1 + ((uVar9 << 8) >> 0x18) * 4) ^
            pAVar11->rd_key[0xb] ^
            *(uint *)(Te3 + (uVar7 & 0xff) * 4) ^ *(uint *)(&Te0 + (uVar8 >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar13 << 0x10) >> 0x18) * 4);
    pAVar11 = (AES_KEY *)(pAVar11->rd_key + 8);
  }
  uVar12 = key->rd_key[iVar5 * 8];
  uVar10 = *(undefined4 *)(Te3 + ((uVar13 << 8) >> 0x18) * 4);
  uVar2 = *(undefined4 *)(&Te0 + ((uVar7 << 0x10) >> 0x18) * 4);
  uVar6 = *(uint *)(Te2 + (uVar9 >> 0x18) * 4) & 0xff000000 ^ (uint)(byte)Te1[(uVar8 & 0xff) * 4] ^
          uVar12;
  uVar3 = *(uint *)(Te2 + (uVar13 >> 0x18) * 4);
  bVar1 = Te1[(uVar9 & 0xff) * 4];
  uVar4 = *(uint *)(Te2 + (uVar7 >> 0x18) * 4);
  out[3] = (uchar)uVar6;
  out[1] = (byte)(uVar12 >> 0x10) ^ (byte)((uint)uVar10 >> 0x10);
  out[2] = (byte)((uint)uVar2 >> 8) ^ (byte)(uVar12 >> 8);
  *out = (uchar)(uVar6 >> 0x18);
  uVar6 = key->rd_key[iVar5 * 8 + 1];
  uVar2 = *(undefined4 *)(&Te0 + ((uVar8 << 0x10) >> 0x18) * 4);
  uVar3 = (uint)bVar1 ^ uVar3 & 0xff000000 ^ uVar6;
  bVar1 = Te1[(uVar13 & 0xff) * 4];
  out[5] = (byte)(uVar6 >> 0x10) ^
           (byte)((uint)*(undefined4 *)(Te3 + ((uVar7 << 8) >> 0x18) * 4) >> 0x10);
  out[7] = (uchar)uVar3;
  out[4] = (uchar)(uVar3 >> 0x18);
  out[6] = (byte)((uint)uVar2 >> 8) ^ (byte)(uVar6 >> 8);
  uVar2 = *(undefined4 *)(Te3 + ((uVar8 << 8) >> 0x18) * 4);
  uVar3 = key->rd_key[iVar5 * 8 + 2];
  uVar10 = *(undefined4 *)(&Te0 + ((uVar9 << 0x10) >> 0x18) * 4);
  uVar6 = *(uint *)(Te2 + (uVar8 >> 0x18) * 4);
  uVar8 = uVar3 ^ (uint)bVar1 ^ uVar4 & 0xff000000;
  bVar1 = Te1[(uVar7 & 0xff) * 4];
  out[0xb] = (uchar)uVar8;
  out[10] = (byte)(uVar3 >> 8) ^ (byte)((uint)uVar10 >> 8);
  uVar10 = *(undefined4 *)(Te3 + ((uVar9 << 8) >> 0x18) * 4);
  out[8] = (uchar)(uVar8 >> 0x18);
  out[9] = (byte)(uVar3 >> 0x10) ^ (byte)((uint)uVar2 >> 0x10);
  uVar3 = key->rd_key[iVar5 * 8 + 3];
  uVar2 = *(undefined4 *)(&Te0 + ((uVar13 << 0x10) >> 0x18) * 4);
  uVar6 = uVar6 & 0xff000000 ^ (uint)bVar1 ^ uVar3;
  out[0xf] = (uchar)uVar6;
  out[0xc] = (uchar)(uVar6 >> 0x18);
  out[0xd] = (byte)(uVar3 >> 0x10) ^ (byte)((uint)uVar10 >> 0x10);
  out[0xe] = (byte)(uVar3 >> 8) ^ (byte)((uint)uVar2 >> 8);
  return;
}

