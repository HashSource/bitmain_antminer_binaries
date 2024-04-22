
/* WARNING: Unknown calling convention */

int check_hw(work *work,uint nonce,_Bool print)

{
  undefined uVar1;
  uchar uVar2;
  uchar t_1;
  uchar t;
  uchar *puVar3;
  uchar *puVar4;
  uint32_t *puVar5;
  uint32_t *puVar6;
  uchar *puVar7;
  byte *pbVar8;
  undefined *puVar9;
  uchar t_2;
  uint32_t *hash2_32;
  byte bStack_149;
  uchar hash1 [32];
  uchar hash2 [32];
  sha2_context ctx;
  
  memset(hash1,0,0x20);
  memset(hash2,0,0x20);
  ctx.state[0] = *(uint32_t *)work->midstate;
  ctx.state[1] = *(uint32_t *)(work->midstate + 4);
  ctx.state[2] = *(uint32_t *)(work->midstate + 8);
  ctx.state[3] = *(uint32_t *)(work->midstate + 0xc);
  ctx.state[4] = *(uint32_t *)(work->midstate + 0x10);
  ctx.state[5] = *(uint32_t *)(work->midstate + 0x14);
  ctx.state[6] = *(uint32_t *)(work->midstate + 0x18);
  ctx.state[7] = *(uint32_t *)(work->midstate + 0x1c);
  puVar5 = ctx.state;
  puVar9 = (undefined *)((int)ctx.state + 0x1f);
  do {
    uVar1 = *(undefined *)puVar5;
    puVar6 = (uint32_t *)((int)puVar5 + 1);
    *(undefined *)puVar5 = *puVar9;
    *puVar9 = uVar1;
    puVar5 = puVar6;
    puVar9 = puVar9 + -1;
  } while (ctx.state + 4 != puVar6);
  ctx.total[0] = 0x50;
  hash1._0_4_ = *(undefined4 *)work->data;
  hash1._4_4_ = *(undefined4 *)(work->data + 4);
  hash1._8_4_ = *(undefined4 *)(work->data + 8);
  ctx.total[1] = 0;
  puVar3 = hash1;
  puVar7 = hash1 + 0xb;
  do {
    uVar2 = *puVar3;
    puVar4 = puVar3 + 1;
    *puVar3 = *puVar7;
    *puVar7 = uVar2;
    puVar3 = puVar4;
    puVar7 = puVar7 + -1;
  } while (hash1 + 6 != puVar4);
  flip_swab(ctx.buffer,hash1,0xc);
  hash1._0_4_ = nonce;
  flip_swab(ctx.buffer + 0xc,hash1,4);
  sha2_finish(&ctx,hash1);
  memset(&ctx,0,0xe8);
  sha2(hash1,0x20,hash2);
  flip32(hash1,hash2);
  if ((hash1._28_4_ != 0) && (hash1._28_4_ = 1, print)) {
    printf("\n%s: Got a HW!\n",DAT_00022130);
    pbVar8 = &bStack_149;
    printf("hash1=0x");
    do {
      pbVar8 = pbVar8 + 1;
      printf("%02x",(uint)*pbVar8);
    } while (pbVar8 != hash1 + 0x1f);
    putchar(10);
    printf("midstate=0x");
    puVar3 = work->data + 0xb;
    do {
      puVar3 = puVar3 + 1;
      printf("%02x",(uint)*puVar3);
    } while (work->midstate + 0x1f != puVar3);
    pbVar8 = (byte *)((int)&work->nonce + 3);
    printf("\tdata2=0x");
    do {
      pbVar8 = pbVar8 + 1;
      printf("%02x",(uint)*pbVar8);
    } while (work->data + 0xb != pbVar8);
    printf("\treturn nonce=0x%08x, but it should be nonce=0x%08x\n",nonce,work->nonce);
    return 1;
  }
  return hash1._28_4_;
}

