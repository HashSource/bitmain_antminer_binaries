
/* WARNING: Unknown calling convention */

void calc_midstate(work *work)

{
  uint *src;
  uint uVar1;
  int iVar2;
  uchar data [64];
  sha256_ctx ctx;
  
  iVar2 = 0;
  do {
    uVar1 = *(uint *)(work->data + iVar2);
    *(uint *)(data + iVar2) =
         uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
    iVar2 = iVar2 + 4;
  } while (iVar2 != 0x40);
  sha256_init(&ctx);
  sha256_update(&ctx,data,0x40);
  _cg_memcpy(work->midstate,ctx.h,0x20,DAT_0001e1b0,DAT_0001e1ac,0x87d);
  return;
}

