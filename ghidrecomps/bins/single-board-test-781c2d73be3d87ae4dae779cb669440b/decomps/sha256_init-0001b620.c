
/* WARNING: Unknown calling convention */

void sha256_init(sha256_ctx *ctx)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  
  puVar2 = (uint32_t *)(ctx->block + 0x7c);
  puVar1 = DAT_0001b644;
  do {
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar1;
  } while (puVar2 != ctx->h + 7);
  ctx->len = 0;
  ctx->tot_len = 0;
  return;
}

