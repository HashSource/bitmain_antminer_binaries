
/* WARNING: Unknown calling convention */

void sha256_init(sha256_ctx *ctx)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_000105d4;
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 4;
    *(undefined4 *)((int)ctx->h + iVar2) = *(undefined4 *)(iVar1 + iVar2);
    iVar2 = iVar3;
  } while (iVar3 != 0x20);
  ctx->len = 0;
  ctx->tot_len = 0;
  return;
}

