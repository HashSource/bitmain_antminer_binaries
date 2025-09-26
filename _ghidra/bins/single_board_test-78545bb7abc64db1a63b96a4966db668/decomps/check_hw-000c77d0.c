
/* WARNING: Restarted to delay deadcode elimination for space: stack */

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
  
  hash1[0] = '\0';
  hash1[1] = '\0';
  hash1[2] = '\0';
  hash1[3] = '\0';
  hash1[4] = '\0';
  hash1[5] = '\0';
  hash1[6] = '\0';
  hash1[7] = '\0';
  hash1[8] = '\0';
  hash1[9] = '\0';
  hash1[10] = '\0';
  hash1[0xb] = '\0';
  hash1[0xc] = '\0';
  hash1[0xd] = '\0';
  hash1[0xe] = '\0';
  hash1[0xf] = '\0';
  hash1[0x10] = '\0';
  hash1[0x11] = '\0';
  hash1[0x12] = '\0';
  hash1[0x13] = '\0';
  hash1[0x14] = '\0';
  hash1[0x15] = '\0';
  hash1[0x16] = '\0';
  hash1[0x17] = '\0';
  hash1[0x18] = '\0';
  hash1[0x19] = '\0';
  hash1[0x1a] = '\0';
  hash1[0x1b] = '\0';
  hash1[0x1c] = '\0';
  hash1[0x1d] = '\0';
  hash1[0x1e] = '\0';
  hash1[0x1f] = '\0';
  hash2[0] = '\0';
  hash2[1] = '\0';
  hash2[2] = '\0';
  hash2[3] = '\0';
  hash2[4] = '\0';
  hash2[5] = '\0';
  hash2[6] = '\0';
  hash2[7] = '\0';
  hash2[8] = '\0';
  hash2[9] = '\0';
  hash2[10] = '\0';
  hash2[0xb] = '\0';
  hash2[0xc] = '\0';
  hash2[0xd] = '\0';
  hash2[0xe] = '\0';
  hash2[0xf] = '\0';
  hash2[0x10] = '\0';
  hash2[0x11] = '\0';
  hash2[0x12] = '\0';
  hash2[0x13] = '\0';
  hash2[0x14] = '\0';
  hash2[0x15] = '\0';
  hash2[0x16] = '\0';
  hash2[0x17] = '\0';
  hash2[0x18] = '\0';
  hash2[0x19] = '\0';
  hash2[0x1a] = '\0';
  hash2[0x1b] = '\0';
  hash2[0x1c] = '\0';
  hash2[0x1d] = '\0';
  hash2[0x1e] = '\0';
  hash2[0x1f] = '\0';
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

