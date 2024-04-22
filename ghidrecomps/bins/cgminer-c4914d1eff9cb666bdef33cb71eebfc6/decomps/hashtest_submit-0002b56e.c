
uint64_t hashtest_submit(thr_info *thr,work *work,uint32_t nonce,uint8_t *midstate,pool *pool,
                        uint64_t nonce2,uint32_t chain_id)

{
  byte bVar1;
  all_parameters *paVar2;
  FILE *pFVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  UDItype UVar9;
  char *in_stack_fffffe18;
  undefined4 in_stack_fffffe1c;
  uint8_t *midstate_local;
  uint32_t nonce_local;
  work *work_local;
  thr_info *thr_local;
  sha2_context ctx;
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
  UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffffe1c,in_stack_fffffe18));
  bVar7 = (int)(UVar9 >> 0x20) != hashtest_submit::pool_diff._4_4_;
  bVar8 = (int)UVar9 != (uint)hashtest_submit::pool_diff;
  if (bVar7 || bVar8) {
    UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffffe1c,in_stack_fffffe18));
    hashtest_submit::pool_diff_bit._0_4_ = 0;
    hashtest_submit::pool_diff_bit._4_4_ = 0;
    hashtest_submit::pool_diff._0_4_ = (uint)UVar9;
    hashtest_submit::pool_diff._4_4_ = (uint)(UVar9 >> 0x20);
    tmp_pool_diff._4_4_ = hashtest_submit::pool_diff._4_4_;
    for (tmp_pool_diff._0_4_ = (uint)hashtest_submit::pool_diff;
        ((uint)tmp_pool_diff | tmp_pool_diff._4_4_) != 0;
        tmp_pool_diff._0_4_ = (uint)(uVar4 != 0) << 0x1f | (uint)tmp_pool_diff >> 1) {
      uVar4 = tmp_pool_diff._4_4_ & 1;
      tmp_pool_diff._4_4_ = tmp_pool_diff._4_4_ >> 1;
      bVar8 = 0xfffffffe < (uint)hashtest_submit::pool_diff_bit;
      hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit + 1;
      hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ + bVar8;
    }
    bVar8 = (uint)hashtest_submit::pool_diff_bit != 0;
    hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit - 1;
    hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ + -1 + (uint)bVar8;
    hashtest_submit::pool_diff = UVar9;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        in_stack_fffffe18 = "hashtest_submit";
        fprintf(pFVar3,"%s:%d:%s: pool_diff:%llu work_diff:%f pool_diff_bit:%llu ...\n",
                "driver-btm-soc.c",0x1d44);
      }
      fclose(pFVar3);
    }
  }
  UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffffe1c,in_stack_fffffe18));
  bVar7 = (int)(UVar9 >> 0x20) != hashtest_submit::net_diff._4_4_;
  bVar8 = (int)UVar9 != (uint)hashtest_submit::net_diff;
  if (bVar7 || bVar8) {
    UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffffe1c,in_stack_fffffe18));
    hashtest_submit::net_diff_bit._0_4_ = 0;
    hashtest_submit::net_diff_bit._4_4_ = 0;
    hashtest_submit::net_diff._0_4_ = (uint)UVar9;
    hashtest_submit::net_diff._4_4_ = (uint)(UVar9 >> 0x20);
    tmp_net_diff._4_4_ = hashtest_submit::net_diff._4_4_;
    for (tmp_net_diff._0_4_ = (uint)hashtest_submit::net_diff;
        ((uint)tmp_net_diff | tmp_net_diff._4_4_) != 0;
        tmp_net_diff._0_4_ = (uint)(uVar4 != 0) << 0x1f | (uint)tmp_net_diff >> 1) {
      uVar4 = tmp_net_diff._4_4_ & 1;
      tmp_net_diff._4_4_ = tmp_net_diff._4_4_ >> 1;
      bVar8 = 0xfffffffe < (uint)hashtest_submit::net_diff_bit;
      hashtest_submit::net_diff_bit._0_4_ = (uint)hashtest_submit::net_diff_bit + 1;
      hashtest_submit::net_diff_bit._4_4_ = hashtest_submit::net_diff_bit._4_4_ + bVar8;
    }
    bVar8 = (uint)hashtest_submit::net_diff_bit != 0;
    hashtest_submit::net_diff_bit._0_4_ = (uint)hashtest_submit::net_diff_bit - 1;
    hashtest_submit::net_diff_bit._4_4_ = hashtest_submit::net_diff_bit._4_4_ + -1 + (uint)bVar8;
    hashtest_submit::net_diff = UVar9;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: net_diff:%llu current_diff:%f net_diff_bit %llu ...\n",
                "driver-btm-soc.c",0x1d52,"hashtest_submit");
      }
      fclose(pFVar3);
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
    i = 0;
    while ((i < 7 && (uVar4 = __bswap_32(*(uint *)(hash1 + (6 - i) * 4)), uVar4 == 0))) {
      i = i + 1;
    }
    bVar8 = hashtest_submit::pool_diff_bit._4_4_ >> 5 <= (uint)(i >> 0x1f);
    if (i >> 0x1f == hashtest_submit::pool_diff_bit._4_4_ >> 5) {
      bVar8 = ((uint)hashtest_submit::pool_diff_bit >> 5 |
              hashtest_submit::pool_diff_bit._4_4_ << 0x1b) <= (uint)i;
    }
    if (bVar8) {
      uVar4 = nonce >> (dev->check_bit + 0x18 & 0xff);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain %d which_asic_nonce %d which_core_nonce %d\n",
                  "driver-btm-soc.c",0x1d92,"hashtest_submit",chain_id,uVar4 & 0xff,nonce & 0xff);
        }
        fclose(pFVar3);
      }
      paVar2 = dev;
      uVar4 = uVar4 & 0xff;
      uVar5 = *(uint *)(dev->chain_asic_nonce[chain_id] + uVar4);
      iVar6 = *(int *)((int)dev->chain_asic_nonce[chain_id] + uVar4 * 8 + 4);
      *(uint *)(dev->chain_asic_nonce[chain_id] + uVar4) = uVar5 + 1;
      *(uint *)((int)paVar2->chain_asic_nonce[chain_id] + uVar4 * 8 + 4) =
           iVar6 + (uint)(0xfffffffe < uVar5);
      uVar4 = __bswap_32(*(uint *)(hash1 + ((uint)hashtest_submit::pool_diff_bit >> 5 |
                                           hashtest_submit::pool_diff_bit._4_4_ << 0x1b) * -4 + 0x18
                                  ));
      if (uVar4 < 0xffffffffU >> ((uint)hashtest_submit::pool_diff_bit & 0x1f)) {
        hashes._0_4_ = 0x100;
        if ((double)CONCAT44(current_diff._4_4_,current_diff._0_4_) != 0.0) {
          i = 0;
          while( true ) {
            uVar4 = i >> 0x1f;
            bVar8 = hashtest_submit::net_diff_bit._4_4_ >> 5 <= uVar4;
            if (uVar4 == hashtest_submit::net_diff_bit._4_4_ >> 5) {
              bVar8 = ((uint)hashtest_submit::net_diff_bit >> 5 |
                      hashtest_submit::net_diff_bit._4_4_ << 0x1b) <= (uint)i;
            }
            if ((bVar8) || (uVar5 = __bswap_32(*(uint *)(hash1 + (6 - i) * 4)), uVar5 != 0)) break;
            i = i + 1;
          }
          if (uVar4 == hashtest_submit::net_diff_bit._4_4_ >> 5 &&
              i == ((uint)hashtest_submit::net_diff_bit >> 5 |
                   hashtest_submit::net_diff_bit._4_4_ << 0x1b)) {
            __bswap_32(*(uint *)(hash1 + ((uint)hashtest_submit::net_diff_bit >> 5 |
                                         hashtest_submit::net_diff_bit._4_4_ << 0x1b) * -4 + 0x18));
          }
        }
        submit_nonce(thr,work,nonce);
      }
      else {
        uVar4 = __bswap_32(hash1._24_4_);
        if (uVar4 < 0xffffff) {
          hashes._0_4_ = 0x100;
          uVar4 = *(uint *)(h_each_chain + chain_id);
          iVar6 = *(int *)((int)h_each_chain + chain_id * 8 + 4);
          *(uint *)(h_each_chain + chain_id) = uVar4 + 0x100;
          *(uint *)((int)h_each_chain + chain_id * 8 + 4) = iVar6 + (uint)(0xfffffeff < uVar4);
        }
      }
    }
  }
  else {
    if (dev->chain_exist[chain_id] == 1) {
      inc_hw_errors(thr);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: chain[%d] nonce fail\n","driver-btm-soc.c",0x1d74,
                  "hashtest_submit",chain_id);
        }
        fclose(pFVar3);
      }
      dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
      bVar1 = dev->check_bit;
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: HW: chain[%d] asic[%d] core[%d]\n","driver-btm-soc.c",0x1d7b,
                  "hashtest_submit",chain_id,nonce >> (bVar1 + 0x18 & 0xff) & 0xff,nonce & 0xff);
        }
        fclose(pFVar3);
      }
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: HASH2_32[7] != 0\n","driver-btm-soc.c",0x1d7f,"hashtest_submit");
      }
      fclose(pFVar3);
    }
    hashes._0_4_ = 0;
  }
  return (uint64_t)(uint)hashes;
}

