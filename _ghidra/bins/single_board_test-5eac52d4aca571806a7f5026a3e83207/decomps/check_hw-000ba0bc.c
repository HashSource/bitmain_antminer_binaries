
int check_hw(work_format *work,uint32_t which_midstate,uint32_t nonce)

{
  int iVar1;
  uint32_t nonce_local;
  uint32_t which_midstate_local;
  work_format *work_local;
  sha2_context ctx;
  uint32_t nonce_temp;
  uint8_t hash2 [32];
  uint8_t hash1 [32];
  uint32_t *hash2_32;
  
  memset(hash1,0,0x20);
  memset(hash2,0,0x20);
  nonce_temp = nonce << 0x18 | nonce >> 0x18 | (nonce & 0xff0000) >> 8 | (nonce & 0xff00) << 8;
  if (work == (work_format *)0x0) {
    iVar1 = 0;
  }
  else {
    memcpy(ctx.state,work->midstate + which_midstate,0x20);
    rev((uchar *)ctx.state,0x20);
    ctx.total[0] = 0x50;
    ctx.total[1] = 0;
    memcpy(hash1,work->data,0xc);
    rev(hash1,0xc);
    utils_flip_swab(ctx.buffer,hash1,0xc);
    memcpy(hash1,&nonce_temp,4);
    rev(hash1,4);
    utils_flip_swab(ctx.buffer + 0xc,hash1,4);
    sha2_finish(&ctx,hash1);
    memset(&ctx,0,0xe8);
    sha2(hash1,0x20,hash2);
    flip32(hash1,hash2);
    if (hash1._28_4_ == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}

