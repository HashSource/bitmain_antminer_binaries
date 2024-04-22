
int check_hw(SCAN_FREQ_WORK *work,uint nonce,_Bool print)

{
  int iVar1;
  _Bool print_local;
  uint nonce_local;
  SCAN_FREQ_WORK *work_local;
  sha2_context ctx;
  uint nonce_temp;
  uchar hash2 [32];
  uchar hash1 [32];
  uint32_t *hash2_32;
  uint m;
  
  memset(hash1,0,0x20);
  memset(hash2,0,0x20);
  hash1._0_4_ = nonce << 0x18 | nonce >> 0x18 | nonce >> 8 & 0xff00 | (nonce & 0xff00) << 8;
  if (work == (SCAN_FREQ_WORK *)0x0) {
    iVar1 = 0;
  }
  else {
    memcpy(ctx.state,work->midstate,0x20);
    rev((uchar *)ctx.state,0x20);
    ctx.total[0] = 0x50;
    ctx.total[1] = 0;
    memcpy(hash1,work->data,0xc);
    rev(hash1,0xc);
    flip_swab(ctx.buffer,hash1,0xc);
    rev(hash1,4);
    flip_swab(ctx.buffer + 0xc,hash1,4);
    sha2_finish(&ctx,hash1);
    memset(&ctx,0,0xe8);
    sha2(hash1,0x20,hash2);
    flip32(hash1,hash2);
    if (hash1._28_4_ == 0) {
      iVar1 = 0;
    }
    else {
      if (print) {
        printf("\n%s: Got a HW!\n","check_hw");
        printf("hash1=0x");
        for (m = 0; m < 0x20; m = m + 1) {
          printf("%02x",(uint)hash1[m]);
        }
        putchar(10);
        printf("midstate=0x");
        for (m = 0; m < 0x20; m = m + 1) {
          printf("%02x",(uint)work->midstate[m]);
        }
        printf("\tdata2=0x");
        for (m = 0; m < 0xc; m = m + 1) {
          printf("%02x",(uint)work->data[m]);
        }
        printf("\treturn nonce=0x%08x, but it should be nonce=0x%08x\n",nonce,work->nonce);
      }
      iVar1 = 1;
    }
  }
  return iVar1;
}

