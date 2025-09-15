
uint64_t hashtest_submit(thr_info *thr,work *work,uint32_t nonce,uint8_t *midstate,pool *pool,
                        uint64_t nonce2,uint32_t chain_id)

{
  uint64_t uVar1;
  FILE *pFVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint64_t *puVar8;
  bool bVar9;
  uint64_t uVar10;
  uint8_t *midstate_local;
  uint32_t nonce_local;
  work *work_local;
  thr_info *thr_local;
  sha2_context ctx;
  nonce_format_t nonce_tmp;
  uchar hash2 [32];
  uchar hash1 [32];
  FILE *pFile_4;
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile_5;
  uchar which_core_nonce;
  uchar which_asic_nonce;
  uint32_t *hash2_32;
  FILE *pFile_1;
  FILE *pFile;
  uint64_t tmp_net_diff;
  uint64_t tmp_pool_diff;
  uint64_t hashes;
  int i;
  
  hashes._0_4_ = 0;
  uVar10 = __fixunsdfdi(*(undefined4 *)&work->sdiff,*(undefined4 *)((int)&work->sdiff + 4));
  if (uVar10 != hashtest_submit::pool_diff) {
    hashtest_submit::pool_diff =
         __fixunsdfdi(*(undefined4 *)&work->sdiff,*(undefined4 *)((int)&work->sdiff + 4));
    hashtest_submit::pool_diff_bit._0_4_ = 0;
    hashtest_submit::pool_diff_bit._4_4_ = 0;
    uVar10 = hashtest_submit::pool_diff;
    while( true ) {
      tmp_pool_diff._0_4_ = (uint)uVar10;
      if (uVar10 == 0) break;
      uVar10 = CONCAT44((uint)(uVar10 >> 0x21),
                        (uint)((byte)(uVar10 >> 0x20) & 1) << 0x1f | (uint)tmp_pool_diff >> 1);
      bVar9 = 0xfffffffe < (uint)hashtest_submit::pool_diff_bit;
      hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit + 1;
      hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ + bVar9;
    }
    bVar9 = (uint)hashtest_submit::pool_diff_bit == 0;
    hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit - 1;
    hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ - bVar9;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: pool_diff:%lld work_diff:%f pool_diff_bit:%lld ...\n",
                "driver-btm-soc.c",0x21b6,"hashtest_submit");
      }
      fclose(pFVar2);
    }
  }
  uVar10 = __fixunsdfdi(current_diff._0_4_,current_diff._4_4_);
  if (uVar10 != hashtest_submit::net_diff) {
    hashtest_submit::net_diff = __fixunsdfdi(current_diff._0_4_,current_diff._4_4_);
    hashtest_submit::net_diff_bit._0_4_ = 0;
    hashtest_submit::net_diff_bit._4_4_ = 0;
    uVar10 = hashtest_submit::net_diff;
    while( true ) {
      tmp_net_diff._0_4_ = (uint)uVar10;
      if (uVar10 == 0) break;
      uVar10 = CONCAT44((uint)(uVar10 >> 0x21),
                        (uint)((byte)(uVar10 >> 0x20) & 1) << 0x1f | (uint)tmp_net_diff >> 1);
      bVar9 = 0xfffffffe < (uint)hashtest_submit::net_diff_bit;
      hashtest_submit::net_diff_bit._0_4_ = (uint)hashtest_submit::net_diff_bit + 1;
      hashtest_submit::net_diff_bit._4_4_ = hashtest_submit::net_diff_bit._4_4_ + bVar9;
    }
    bVar9 = (uint)hashtest_submit::net_diff_bit == 0;
    hashtest_submit::net_diff_bit._0_4_ = (uint)hashtest_submit::net_diff_bit - 1;
    hashtest_submit::net_diff_bit._4_4_ = hashtest_submit::net_diff_bit._4_4_ - bVar9;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: net_diff:%lld current_diff:%f net_diff_bit %lld ...\n",
                "driver-btm-soc.c",0x21c4,"hashtest_submit");
      }
      fclose(pFVar2);
    }
  }
  memcpy(ctx.state,work->midstate,0x20);
  ctx.total[0] = 0x50;
  ctx.total[1] = 0;
  memcpy(hash1,work->data + 0x40,0xc);
  flip_swab(ctx.buffer,hash1,0xc);
  hash1._0_4_ = nonce;
  flip_swab(ctx.buffer + 0xc,hash1,4);
  sha2_finish(&ctx,hash1);
  memset(&ctx,0,0xe8);
  sha2(hash1,0x20,hash2);
  flip32(hash1,hash2);
  if (hash1._28_4_ == 0) {
    for (i = 0; i < 7; i = i + 1) {
      uVar5 = __bswap_32(*(uint *)(hash1 + (6 - i) * 4));
      if (uVar5 != 0) break;
    }
    bVar9 = hashtest_submit::pool_diff_bit._4_4_ >> 5 <= (uint)(i >> 0x1f);
    if (i >> 0x1f == hashtest_submit::pool_diff_bit._4_4_ >> 5) {
      bVar9 = ((uint)hashtest_submit::pool_diff_bit >> 5 |
              hashtest_submit::pool_diff_bit._4_4_ << 0x1b) <= (uint)i;
    }
    uVar10 = hashtest_submit::pool_diff;
    uVar1 = hashtest_submit::net_diff;
    if (bVar9) {
      uVar3 = get_asic_id((nonce_format_t)nonce);
      uVar4 = get_core_id((nonce_format_t)nonce);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain %d which_asic_nonce %d which_core_nonce %d\n",
                  "driver-btm-soc.c",0x2205,"hashtest_submit",chain_id,uVar3 & 0xff,uVar4 & 0xff);
        }
        fclose(pFVar2);
      }
      puVar8 = dev->chain_asic_nonce[chain_id] + (uVar3 & 0xff);
      uVar5 = (uint)*puVar8;
      iVar7 = *(int *)((int)puVar8 + 4);
      puVar8 = dev->chain_asic_nonce[chain_id] + (uVar3 & 0xff);
      *(uint *)puVar8 = uVar5 + 1;
      *(uint *)((int)puVar8 + 4) = iVar7 + (uint)(0xfffffffe < uVar5);
      uVar5 = __bswap_32(*(uint *)(hash1 + ((uint)hashtest_submit::pool_diff_bit >> 5 |
                                           hashtest_submit::pool_diff_bit._4_4_ << 0x1b) * -4 + 0x18
                                  ));
      if (uVar5 < 0xffffffffU >> ((uint)hashtest_submit::pool_diff_bit & 0x1f)) {
        hashes._0_4_ = 0x100;
        if ((double)CONCAT44(current_diff._4_4_,current_diff._0_4_) != 0.0) {
          i = 0;
          while( true ) {
            uVar5 = i >> 0x1f;
            bVar9 = hashtest_submit::net_diff_bit._4_4_ >> 5 <= uVar5;
            if (uVar5 == hashtest_submit::net_diff_bit._4_4_ >> 5) {
              bVar9 = ((uint)hashtest_submit::net_diff_bit >> 5 |
                      hashtest_submit::net_diff_bit._4_4_ << 0x1b) <= (uint)i;
            }
            if (bVar9) break;
            uVar6 = __bswap_32(*(uint *)(hash1 + (6 - i) * 4));
            if (uVar6 != 0) break;
            i = i + 1;
          }
          if (uVar5 == hashtest_submit::net_diff_bit._4_4_ >> 5 &&
              i == ((uint)hashtest_submit::net_diff_bit >> 5 |
                   hashtest_submit::net_diff_bit._4_4_ << 0x1b)) {
            __bswap_32(*(uint *)(hash1 + ((uint)hashtest_submit::net_diff_bit >> 5 |
                                         hashtest_submit::net_diff_bit._4_4_ << 0x1b) * -4 + 0x18));
          }
        }
        submit_nonce(thr,work,nonce);
        uVar10 = hashtest_submit::pool_diff;
        uVar1 = hashtest_submit::net_diff;
      }
      else {
        uVar5 = __bswap_32(hash1._24_4_);
        uVar10 = hashtest_submit::pool_diff;
        uVar1 = hashtest_submit::net_diff;
        if (uVar5 < 0xffffff) {
          hashes._0_4_ = 0x100;
          uVar10 = h_each_chain[chain_id];
          iVar7 = *(int *)((int)h_each_chain + chain_id * 8 + 4);
          *(uint *)(h_each_chain + chain_id) = (uint)uVar10 + 0x100;
          *(uint *)((int)h_each_chain + chain_id * 8 + 4) =
               iVar7 + (uint)(0xfffffeff < (uint)uVar10);
          uVar10 = hashtest_submit::pool_diff;
          uVar1 = hashtest_submit::net_diff;
        }
      }
    }
  }
  else {
    if (dev->chain_exist[chain_id] == 1) {
      inc_hw_errors(thr);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: chain[%d] nonce fail\n","driver-btm-soc.c",0x21e6,
                  "hashtest_submit",chain_id);
        }
        fclose(pFVar2);
      }
      dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
      uVar3 = get_asic_id((nonce_format_t)nonce);
      uVar4 = get_core_id((nonce_format_t)nonce);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: HW: chain[%d] asic[%d] core[%d]\n","driver-btm-soc.c",0x21ed,
                  "hashtest_submit",chain_id,uVar3 & 0xff,uVar4 & 0xff);
        }
        fclose(pFVar2);
      }
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: HASH2_32[7] != 0\n","driver-btm-soc.c",0x21f1,"hashtest_submit");
      }
      fclose(pFVar2);
    }
    hashes._0_4_ = 0;
    uVar10 = hashtest_submit::pool_diff;
    uVar1 = hashtest_submit::net_diff;
  }
  hashtest_submit::net_diff._4_4_ = (undefined4)(uVar1 >> 0x20);
  hashtest_submit::net_diff._0_4_ = (undefined4)uVar1;
  hashtest_submit::pool_diff._4_4_ = (undefined4)(uVar10 >> 0x20);
  hashtest_submit::pool_diff._0_4_ = (undefined4)uVar10;
  return (uint64_t)(uint)hashes;
}

