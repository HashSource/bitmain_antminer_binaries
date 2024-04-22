
/* WARNING: Unknown calling convention */

void sha256(uchar *message,uint len,uchar *digest)

{
  int iVar1;
  int iVar2;
  sha256_ctx ctx;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)ctx.h + iVar1) = *(undefined4 *)(DAT_0001074c + iVar1);
    iVar1 = iVar2;
  } while (iVar2 != 0x20);
  ctx.len = 0;
  ctx.tot_len = 0;
  sha256_update(&ctx,message,len);
  sha256_final(&ctx,digest);
  return;
}

