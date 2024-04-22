
/* WARNING: Unknown calling convention */

void sha256_transf(sha256_ctx *ctx,uchar *message,uint block_nb)

{
  uint *puVar1;
  uint uVar2;
  uint32_t *puVar3;
  uint32_t *puVar4;
  int iVar5;
  uint32_t t1;
  int j;
  uint uVar6;
  uint *puVar7;
  uchar *sub_block;
  uint uVar8;
  int iVar9;
  uint local_164;
  uint32_t local_14c;
  uint32_t wv [8];
  uint32_t w [64];
  
  if (0 < (int)block_nb) {
    local_164 = 0;
    do {
      puVar7 = wv + 7;
      j = 0;
      do {
        iVar5 = j * 4 + local_164 * 0x40;
        iVar9 = j * 4;
        j = j + 1;
        puVar7 = puVar7 + 1;
        *puVar7 = (uint)message[iVar5 + 3] | (uint)message[iVar9 + local_164 * 0x40] << 0x18 |
                  (uint)message[iVar5 + 2] << 8 | (uint)message[iVar5 + 1] << 0x10;
      } while (j != 0x10);
      puVar7 = w;
      do {
        uVar6 = puVar7[0xe];
        puVar1 = puVar7 + 1;
        uVar2 = *puVar1;
        puVar7[0x10] = ((uVar2 >> 0x12 | uVar2 << 0xe) ^ (uVar2 >> 7 | uVar2 << 0x19) ^ uVar2 >> 3)
                       + *puVar7 + puVar7[9] +
                         ((uVar6 >> 0x13 | uVar6 << 0xd) ^ (uVar6 >> 0x11 | uVar6 << 0xf) ^
                         uVar6 >> 10);
        puVar7 = puVar1;
      } while (w + 0x30 != puVar1);
      puVar3 = &local_14c;
      puVar4 = (uint32_t *)(ctx->block + 0x7c);
      do {
        puVar4 = puVar4 + 1;
        puVar3 = puVar3 + 1;
        *puVar3 = *puVar4;
      } while (ctx->h + 7 != puVar4);
      iVar9 = 0;
      do {
        uVar8 = wv[2];
        uVar6 = wv[5];
        uVar2 = wv[6];
        wv[2] = wv[1];
        wv[1] = wv[0];
        wv[5] = wv[4];
        puVar3 = w + iVar9;
        puVar4 = sha256_k + iVar9;
        iVar9 = iVar9 + 1;
        iVar5 = wv[7] + (uVar2 & ~wv[5] ^ wv[5] & uVar6) +
                        ((wv[5] >> 0xb | wv[5] << 0x15) ^ (wv[5] >> 6 | wv[5] << 0x1a) ^
                        (wv[5] >> 0x19 | wv[5] << 7)) + *puVar3 + *puVar4;
        wv[4] = iVar5 + wv[3];
        wv[0] = ((wv[1] >> 0xd | wv[1] << 0x13) ^ (wv[1] >> 2 | wv[1] << 0x1e) ^
                (wv[1] >> 0x16 | wv[1] << 10)) + ((uVar8 ^ wv[2]) & wv[1] ^ wv[2] & uVar8) + iVar5;
        wv[7] = uVar2;
        wv[6] = uVar6;
        wv[3] = uVar8;
      } while (iVar9 != 0x40);
      puVar7 = wv;
      uVar2 = wv[0];
      puVar3 = ctx->h;
      while( true ) {
        *puVar3 = *puVar3 + uVar2;
        if ((sha256_ctx *)(puVar3 + 1) == ctx + 1) break;
        puVar7 = puVar7 + 1;
        uVar2 = *puVar7;
        puVar3 = puVar3 + 1;
      }
      local_164 = local_164 + 1;
    } while (local_164 != block_nb);
  }
  return;
}

