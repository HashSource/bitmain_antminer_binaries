
/* WARNING: Unknown calling convention */

void sha256_transf(sha256_ctx *ctx,uchar *message,uint block_nb)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uchar *sub_block;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  sha256_ctx *psVar7;
  int iVar8;
  int iVar9;
  uint t1;
  uint local_158;
  uint local_154;
  uint local_150;
  uint wv [8];
  uint w [64];
  
  if (0 < (int)block_nb) {
    local_150 = 0;
    do {
      iVar8 = 0;
      puVar5 = wv + 7;
      do {
        iVar3 = iVar8 * 4 + local_150 * 0x40;
        iVar9 = iVar8 * 4;
        iVar8 = iVar8 + 1;
        puVar5 = puVar5 + 1;
        *puVar5 = (uint)message[iVar3 + 3] | (uint)message[iVar9 + local_150 * 0x40] << 0x18 |
                  (uint)message[iVar3 + 2] << 8 | (uint)message[iVar3 + 1] << 0x10;
      } while (iVar8 != 0x10);
      puVar5 = w;
      iVar8 = 0;
      do {
        uVar4 = puVar5[0xe];
        uVar6 = puVar5[1];
        piVar1 = (int *)((int)w + iVar8);
        iVar8 = iVar8 + 4;
        puVar5[0x10] = ((uVar6 >> 7 | uVar6 << 0x19) ^ (uVar6 >> 0x12 | uVar6 << 0xe) ^ uVar6 >> 3)
                       + ((uVar4 >> 0x11 | uVar4 << 0xf) ^ (uVar4 >> 0x13 | uVar4 << 0xd) ^
                         uVar4 >> 10) + puVar5[9] + *piVar1;
        puVar5 = puVar5 + 1;
      } while (iVar8 != 0xc0);
      iVar8 = 0;
      do {
        *(undefined4 *)((int)wv + iVar8) = *(undefined4 *)((int)ctx->h + iVar8);
        iVar8 = iVar8 + 4;
      } while (iVar8 != 0x20);
      local_154 = wv[3];
      iVar8 = 0;
      local_158 = wv[5];
      wv[5] = local_158;
      do {
        local_158 = wv[5];
        uVar6 = wv[6];
        uVar4 = wv[1];
        wv[5] = wv[4];
        wv[1] = wv[0];
        wv[3] = wv[2];
        piVar1 = (int *)((int)w + iVar8);
        piVar2 = (int *)((int)sha256_k + iVar8);
        iVar8 = iVar8 + 4;
        iVar9 = wv[7] + (uVar6 & ~wv[5] ^ local_158 & wv[5]) +
                        *piVar1 + *piVar2 +
                        ((wv[5] >> 6 | wv[5] << 0x1a) ^ (wv[5] >> 0xb | wv[5] << 0x15) ^
                        (wv[5] >> 0x19 | wv[5] << 7));
        wv[4] = local_154 + iVar9;
        wv[0] = ((wv[1] >> 2 | wv[1] << 0x1e) ^ (wv[1] >> 0xd | wv[1] << 0x13) ^
                (wv[1] >> 0x16 | wv[1] << 10)) + ((uVar4 ^ wv[3]) & wv[1] ^ wv[3] & uVar4) + iVar9;
        wv[2] = uVar4;
        wv[6] = local_158;
        wv[7] = uVar6;
        local_154 = wv[3];
      } while (iVar8 != 0x100);
      wv[6] = local_158;
      psVar7 = ctx;
      uVar4 = wv[0];
      iVar8 = 0;
      while( true ) {
        psVar7->h[0] = psVar7->h[0] + uVar4;
        psVar7 = (sha256_ctx *)&psVar7->len;
        if (iVar8 + 4 == 0x20) break;
        uVar4 = *(uint *)((int)wv + iVar8 + 4);
        iVar8 = iVar8 + 4;
      }
      local_150 = local_150 + 1;
    } while (block_nb != local_150);
  }
  return;
}

