
/* WARNING: Unknown calling convention */

void sha256_final(sha256_ctx *ctx,uchar *digest)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint len_b;
  int iVar4;
  uint block_nb;
  uint block_nb_00;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  uVar3 = ctx->len;
  bVar9 = (uVar3 & 0x3f) < 0x38;
  if (bVar9) {
    iVar2 = 0x40;
  }
  else {
    iVar2 = 0x80;
  }
  iVar4 = (ctx->tot_len + uVar3) * 8;
  if (bVar9) {
    iVar5 = 0x3c;
    iVar6 = 0x3d;
    iVar7 = 0x3e;
    iVar8 = 0x3f;
    block_nb_00 = 1;
  }
  else {
    iVar5 = 0x7c;
    iVar6 = 0x7d;
    iVar7 = 0x7e;
    iVar8 = 0x7f;
    block_nb_00 = 2;
  }
  memset(ctx->block + uVar3,0,iVar2 - uVar3);
  ctx->block[ctx->len] = 0x80;
  ctx->block[iVar8] = (uchar)iVar4;
  ctx->block[iVar7] = (uchar)((uint)iVar4 >> 8);
  ctx->block[iVar6] = (uchar)((uint)iVar4 >> 0x10);
  ctx->block[iVar5] = (uchar)((uint)iVar4 >> 0x18);
  sha256_transf(ctx,ctx->block,block_nb_00);
  iVar2 = 0;
  do {
    digest[iVar2 * 4 + 3] = (uchar)ctx->h[0];
    digest[iVar2 * 4 + 2] = (uchar)(ctx->h[0] >> 8);
    digest[iVar2 * 4 + 1] = (uchar)*(undefined2 *)((int)ctx->h + 2);
    puVar1 = ctx->h;
    ctx = (sha256_ctx *)&ctx->len;
    digest[iVar2 * 4] = *(uchar *)((int)puVar1 + 3);
    iVar2 = iVar2 + 1;
  } while (iVar2 != 8);
  return;
}

