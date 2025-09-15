
/* WARNING: Unknown calling convention */

void sha256_init(sha256_ctx *ctx)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)ctx->h + iVar1) = *(undefined4 *)((int)sha256_h0 + iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 0x20);
  ctx->len = 0;
  ctx->tot_len = 0;
  return;
}

