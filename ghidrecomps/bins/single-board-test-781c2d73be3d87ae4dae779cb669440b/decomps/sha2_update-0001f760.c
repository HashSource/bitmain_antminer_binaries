
/* WARNING: Unknown calling convention */

void sha2_update(sha2_context *ctx,uchar *input,int ilen)

{
  uchar *__dest;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint32_t left;
  size_t __n;
  int fill;
  
  if (ilen < 1) {
    return;
  }
  uVar3 = ctx->total[0] & 0x3f;
  uVar1 = ctx->total[0] + ilen;
  ctx->total[0] = uVar1;
  uVar2 = uVar1;
  if (uVar1 < (uint)ilen) {
    uVar2 = ctx->total[1];
  }
  __n = 0x40 - uVar3;
  if (uVar1 < (uint)ilen) {
    uVar2 = uVar2 + 1;
  }
  if (uVar1 < (uint)ilen) {
    ctx->total[1] = uVar2;
  }
  uVar2 = uVar3;
  if (uVar3 != 0) {
    uVar2 = 1;
  }
  if (ilen < (int)__n) {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    if (0x3f < ilen) {
      do {
        ilen = ilen + -0x40;
        sha2_process(ctx,input);
        input = input + 0x40;
joined_r0x0001f7e0:
      } while (0x3f < ilen);
      if (ilen < 1) {
        return;
      }
    }
    (*(code *)PTR_memcpy_00030134)(ctx->buffer + uVar3,input,ilen);
    return;
  }
  __dest = ctx->buffer + uVar3;
  ilen = ilen - __n;
  uVar3 = 0;
  memcpy(__dest,input,__n);
  sha2_process(ctx,ctx->buffer);
  input = input + __n;
  goto joined_r0x0001f7e0;
}

