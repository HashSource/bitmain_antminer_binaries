
/* WARNING: Unknown calling convention */

void sha2_update(sha2_context *ctx,uchar *input,int ilen)

{
  undefined4 in_r3;
  uint uVar1;
  uint uVar2;
  size_t __n;
  int fill;
  uchar *data;
  int iVar3;
  uint uVar4;
  uint left;
  
  if (0 < ilen) {
    uVar4 = ctx->total[0] & 0x3f;
    uVar1 = ilen + ctx->total[0];
    ctx->total[0] = uVar1;
    uVar2 = uVar1;
    if (uVar1 < (uint)ilen) {
      uVar2 = ctx->total[1];
    }
    __n = 0x40 - uVar4;
    if (uVar1 < (uint)ilen) {
      uVar2 = uVar2 + 1;
    }
    if (uVar1 < (uint)ilen) {
      ctx->total[1] = uVar2;
    }
    if (uVar4 != 0 && (int)__n <= ilen) {
      ilen = ilen - __n;
      memcpy(ctx->buffer + uVar4,input,__n);
      input = input + __n;
      uVar4 = 0;
      sha2_process(ctx,ctx->buffer);
    }
    data = input;
    iVar3 = ilen;
    if (0x3f < ilen) {
      do {
        iVar3 = iVar3 + -0x40;
        sha2_process(ctx,data);
        data = data + 0x40;
      } while (0x3f < iVar3);
      uVar2 = ilen - 0x40;
      ilen = uVar2 - (uVar2 & 0xffffffc0);
      input = input + ((uVar2 >> 6) + 1) * 0x40;
    }
    if (0 < ilen) {
                    /* WARNING: Could not recover jumptable at 0x0000a384. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_LAB_0005f264)(ctx->buffer + uVar4,input,ilen,in_r3);
      return;
    }
  }
  return;
}

