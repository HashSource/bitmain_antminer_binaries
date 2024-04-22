
/* WARNING: Unknown calling convention */

void sha256(uchar *message,uint len,uchar *digest)

{
  uint32_t *puVar1;
  uint32_t *puVar2;
  sha256_ctx ctx;
  
  puVar1 = (uint32_t *)(ctx.block + 0x7c);
  puVar2 = DAT_0001b7a8;
  do {
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar2;
  } while (puVar2 != DAT_0001b7a8 + 8);
  ctx.tot_len = 0;
  ctx.len = 0;
  sha256_update(&ctx,message,len);
  sha256_final(&ctx,digest);
  return;
}

