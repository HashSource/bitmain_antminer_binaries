
/* WARNING: Unknown calling convention */

void sha256_final(sha256_ctx *ctx,uchar *digest)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint32_t *puVar4;
  uchar *message;
  int iVar5;
  uint len_b;
  int iVar6;
  int iVar7;
  int iVar8;
  uint block_nb;
  uint block_nb_00;
  bool bVar9;
  
  uVar2 = ctx->len;
  message = ctx->block;
  bVar9 = (uVar2 & 0x3f) < 0x38;
  if (bVar9) {
    iVar1 = 0x40;
  }
  else {
    iVar1 = 0x80;
  }
  if (bVar9) {
    iVar3 = 0x3c;
    iVar6 = 0x3d;
    iVar7 = 0x3e;
    iVar8 = 0x3f;
    block_nb_00 = 1;
  }
  else {
    iVar3 = 0x7c;
    iVar6 = 0x7d;
    iVar7 = 0x7e;
    iVar8 = 0x7f;
    block_nb_00 = 2;
  }
  iVar5 = (ctx->tot_len + uVar2) * 8;
  memset(message + uVar2,0,iVar1 - uVar2);
  ctx->block[ctx->len] = 0x80;
  message[iVar8] = (uchar)iVar5;
  message[iVar7] = (uchar)((uint)iVar5 >> 8);
  message[iVar6] = (uchar)((uint)iVar5 >> 0x10);
  message[iVar3] = (uchar)((uint)iVar5 >> 0x18);
  sha256_transf(ctx,message,block_nb_00);
  iVar1 = 0;
  puVar4 = ctx->h;
  do {
    digest[iVar1 * 4 + 3] = (uchar)*puVar4;
    digest[iVar1 * 4 + 2] = (uchar)(*puVar4 >> 8);
    digest[iVar1 * 4 + 1] = (uchar)(*puVar4 >> 0x10);
    digest[iVar1 * 4] = *(uchar *)((int)puVar4 + 3);
    iVar1 = iVar1 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar1 != 8);
  return;
}

