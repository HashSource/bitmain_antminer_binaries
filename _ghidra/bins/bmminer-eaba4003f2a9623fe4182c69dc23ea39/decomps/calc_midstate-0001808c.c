
void calc_midstate(work *work)

{
  work *work_local;
  sha256_ctx ctx;
  uchar data [64];
  uint *data32;
  
  flip64(data,work);
  sha256_init(&ctx);
  sha256_update(&ctx,data,0x40);
  _cg_memcpy(work->midstate,ctx.h,0x20,"cgminer.c","calc_midstate",0x884);
  endian_flip32(work->midstate,work->midstate);
  return;
}

