
/* WARNING: Restarted to delay deadcode elimination for space: stack */

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
  uint *hash2_32;
  uint m;
  
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
  hash1[11] = '\0';
  hash1[12] = '\0';
  hash1[13] = '\0';
  hash1[14] = '\0';
  hash1[15] = '\0';
  hash1[16] = '\0';
  hash1[17] = '\0';
  hash1[18] = '\0';
  hash1[19] = '\0';
  hash1[20] = '\0';
  hash1[21] = '\0';
  hash1[22] = '\0';
  hash1[23] = '\0';
  hash1[24] = '\0';
  hash1[25] = '\0';
  hash1[26] = '\0';
  hash1[27] = '\0';
  hash1[28] = '\0';
  hash1[29] = '\0';
  hash1[30] = '\0';
  hash1[31] = '\0';
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
  hash2[11] = '\0';
  hash2[12] = '\0';
  hash2[13] = '\0';
  hash2[14] = '\0';
  hash2[15] = '\0';
  hash2[16] = '\0';
  hash2[17] = '\0';
  hash2[18] = '\0';
  hash2[19] = '\0';
  hash2[20] = '\0';
  hash2[21] = '\0';
  hash2[22] = '\0';
  hash2[23] = '\0';
  hash2[24] = '\0';
  hash2[25] = '\0';
  hash2[26] = '\0';
  hash2[27] = '\0';
  hash2[28] = '\0';
  hash2[29] = '\0';
  hash2[30] = '\0';
  hash2[31] = '\0';
  nonce_temp = nonce << 0x18 | nonce >> 0x18 | (nonce & 0xff0000) >> 8 | (nonce & 0xff00) << 8;
  if (work == (SCAN_FREQ_WORK *)0x0) {
    iVar1 = 0;
  }
  else {
    ctx.state[0] = *(uint *)work->midstate;
    ctx.state[1] = *(uint *)(work->midstate + 4);
    ctx.state[2] = *(uint *)(work->midstate + 8);
    ctx.state[3] = *(uint *)(work->midstate + 0xc);
    ctx.state[4] = *(uint *)(work->midstate + 0x10);
    ctx.state[5] = *(uint *)(work->midstate + 0x14);
    ctx.state[6] = *(uint *)(work->midstate + 0x18);
    ctx.state[7] = *(uint *)(work->midstate + 0x1c);
    rev((uchar *)ctx.state,0x20);
    ctx.total[0] = 0x50;
    ctx.total[1] = 0;
    memcpy(hash1,work->data,0xc);
    rev(hash1,0xc);
    flip_swab(ctx.buffer,hash1,0xc);
    memcpy(hash1,&nonce_temp,4);
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

