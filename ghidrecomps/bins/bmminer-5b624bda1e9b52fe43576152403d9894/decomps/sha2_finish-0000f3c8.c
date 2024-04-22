
/* WARNING: Unknown calling convention */

void sha2_finish(sha2_context *ctx,uchar *output)

{
  int iVar1;
  uint high;
  uint uVar2;
  uint last;
  uint padn;
  uint uVar3;
  int iVar4;
  uint low;
  uchar msglen [8];
  
  uVar3 = ctx->total[0];
  uVar2 = uVar3 & 0x3f;
  iVar4 = uVar3 << 3;
  iVar1 = ctx->total[1] << 3;
  msglen[3] = (byte)(uVar3 >> 0x1d) | (byte)iVar1;
  msglen[6] = (uchar)((uint)iVar4 >> 8);
  if (uVar2 < 0x38) {
    padn = 0x38 - uVar2;
  }
  else {
    padn = 0x78 - uVar2;
  }
  msglen[7] = (uchar)iVar4;
  msglen[1] = (uchar)((uint)iVar1 >> 0x10);
  msglen[2] = (uchar)((uint)iVar1 >> 8);
  msglen[0] = (uchar)((uint)iVar1 >> 0x18);
  msglen[4] = (uchar)((uint)iVar4 >> 0x18);
  msglen[5] = (uchar)((uint)iVar4 >> 0x10);
  sha2_update(ctx,DAT_0000f4cc,padn);
  sha2_update(ctx,msglen,8);
  *output = *(uchar *)((int)ctx->state + 3);
  output[1] = (uchar)*(undefined2 *)((int)ctx->state + 2);
  output[2] = (uchar)(ctx->state[0] >> 8);
  output[3] = (uchar)ctx->state[0];
  output[4] = *(uchar *)((int)ctx->state + 7);
  output[5] = (uchar)*(undefined2 *)((int)ctx->state + 6);
  output[6] = (uchar)(ctx->state[1] >> 8);
  output[7] = (uchar)ctx->state[1];
  output[8] = *(uchar *)((int)ctx->state + 0xb);
  output[9] = (uchar)*(undefined2 *)((int)ctx->state + 10);
  output[10] = (uchar)(ctx->state[2] >> 8);
  output[0xb] = (uchar)ctx->state[2];
  output[0xc] = *(uchar *)((int)ctx->state + 0xf);
  output[0xd] = (uchar)*(undefined2 *)((int)ctx->state + 0xe);
  output[0xe] = (uchar)(ctx->state[3] >> 8);
  output[0xf] = (uchar)ctx->state[3];
  output[0x10] = *(uchar *)((int)ctx->state + 0x13);
  output[0x11] = (uchar)*(undefined2 *)((int)ctx->state + 0x12);
  output[0x12] = (uchar)(ctx->state[4] >> 8);
  output[0x13] = (uchar)ctx->state[4];
  output[0x14] = *(uchar *)((int)ctx->state + 0x17);
  output[0x15] = (uchar)*(undefined2 *)((int)ctx->state + 0x16);
  output[0x16] = (uchar)(ctx->state[5] >> 8);
  output[0x17] = (uchar)ctx->state[5];
  output[0x18] = *(uchar *)((int)ctx->state + 0x1b);
  output[0x19] = (uchar)*(undefined2 *)((int)ctx->state + 0x1a);
  output[0x1a] = (uchar)(ctx->state[6] >> 8);
  output[0x1b] = (uchar)ctx->state[6];
  output[0x1c] = *(uchar *)((int)ctx->state + 0x1f);
  output[0x1d] = (uchar)*(undefined2 *)((int)ctx->state + 0x1e);
  output[0x1e] = (uchar)(ctx->state[7] >> 8);
  output[0x1f] = (uchar)ctx->state[7];
  return;
}

