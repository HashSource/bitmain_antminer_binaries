
uint64_t hashtest_submit(thr_info *thr,work *work,uint32_t nonce,uint8_t *midstate,pool *pool,
                        uint64_t nonce2,uint32_t chain_id)

{
  byte bVar1;
  uint64_t uVar2;
  all_parameters *paVar3;
  FILE *pFVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  DFtype in_d0;
  DFtype a;
  DFtype extraout_d0;
  DFtype extraout_d0_00;
  DFtype a_00;
  DFtype a_01;
  UDItype UVar9;
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
  UVar9 = __fixunsdfdi(in_d0);
  a_00 = a;
  if (UVar9 != hashtest_submit::pool_diff) {
    UVar9 = __fixunsdfdi(a);
    hashtest_submit::pool_diff_bit._0_4_ = 0;
    hashtest_submit::pool_diff_bit._4_4_ = 0;
    hashtest_submit::pool_diff._0_4_ = (uint)UVar9;
    hashtest_submit::pool_diff._4_4_ = (uint)(UVar9 >> 0x20);
    tmp_pool_diff._4_4_ = hashtest_submit::pool_diff._4_4_;
    for (tmp_pool_diff._0_4_ = (uint)hashtest_submit::pool_diff;
        (uint)tmp_pool_diff != 0 || tmp_pool_diff._4_4_ != 0;
        tmp_pool_diff._0_4_ = (uint)(uVar6 != 0) << 0x1f | (uint)tmp_pool_diff >> 1) {
      uVar6 = tmp_pool_diff._4_4_ & 1;
      tmp_pool_diff._4_4_ = tmp_pool_diff._4_4_ >> 1;
      bVar8 = 0xfffffffe < (uint)hashtest_submit::pool_diff_bit;
      hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit + 1;
      hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ + bVar8;
    }
    bVar8 = (uint)hashtest_submit::pool_diff_bit != 0;
    hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit - 1;
    hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ + -1 + (uint)bVar8;
    a_00 = extraout_d0;
    hashtest_submit::pool_diff = UVar9;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: pool_diff:%llu work_diff:%f pool_diff_bit:%llu ...\n",
                "driver-btm-soc.c",0x1d44,"hashtest_submit");
      }
      fclose(pFVar4);
      a_00 = extraout_d0_00;
    }
  }
  UVar9 = __fixunsdfdi(a_00);
  if (UVar9 != hashtest_submit::net_diff) {
    UVar9 = __fixunsdfdi(a_01);
    hashtest_submit::net_diff_bit._0_4_ = 0;
    hashtest_submit::net_diff_bit._4_4_ = 0;
    hashtest_submit::net_diff._0_4_ = (uint)UVar9;
    hashtest_submit::net_diff._4_4_ = (uint)(UVar9 >> 0x20);
    tmp_net_diff._4_4_ = hashtest_submit::net_diff._4_4_;
    for (tmp_net_diff._0_4_ = (uint)hashtest_submit::net_diff;
        (uint)tmp_net_diff != 0 || tmp_net_diff._4_4_ != 0;
        tmp_net_diff._0_4_ = (uint)(uVar6 != 0) << 0x1f | (uint)tmp_net_diff >> 1) {
      uVar6 = tmp_net_diff._4_4_ & 1;
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
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: net_diff:%llu current_diff:%f net_diff_bit %llu ...\n",
                "driver-btm-soc.c",0x1d52,"hashtest_submit");
      }
      fclose(pFVar4);
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
    while ((i < 7 && (uVar6 = __bswap_32(*(uint *)(hash1 + (6 - i) * 4)), uVar6 == 0))) {
      i = i + 1;
    }
    bVar8 = hashtest_submit::pool_diff_bit._4_4_ >> 5 <= (uint)(i >> 0x1f);
    if (i >> 0x1f == hashtest_submit::pool_diff_bit._4_4_ >> 5) {
      bVar8 = ((uint)hashtest_submit::pool_diff_bit >> 5 |
              hashtest_submit::pool_diff_bit._4_4_ << 0x1b) <= (uint)i;
    }
    if (bVar8) {
      uVar6 = nonce >> (dev->check_bit + 0x18 & 0xff);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: chain %d which_asic_nonce %d which_core_nonce %d\n",
                  "driver-btm-soc.c",0x1d92,"hashtest_submit",chain_id,uVar6 & 0xff,nonce & 0xff);
        }
        fclose(pFVar4);
      }
      paVar3 = dev;
      uVar6 = uVar6 & 0xff;
      uVar5 = (uint)dev->chain_asic_nonce[chain_id][uVar6];
      iVar7 = *(int *)((int)dev->chain_asic_nonce[chain_id] + uVar6 * 8 + 4);
      *(uint *)(dev->chain_asic_nonce[chain_id] + uVar6) = uVar5 + 1;
      *(uint *)((int)paVar3->chain_asic_nonce[chain_id] + uVar6 * 8 + 4) =
           iVar7 + (uint)(0xfffffffe < uVar5);
      uVar6 = __bswap_32(*(uint *)(hash1 + ((uint)hashtest_submit::pool_diff_bit >> 5 |
                                           hashtest_submit::pool_diff_bit._4_4_ << 0x1b) * -4 + 0x18
                                  ));
      if (uVar6 < 0xffffffffU >> ((uint)hashtest_submit::pool_diff_bit & 0x1f)) {
        hashes._0_4_ = 0x100;
        if ((double)CONCAT44(current_diff._4_4_,current_diff._0_4_) != 0.0) {
          i = 0;
          while( true ) {
            uVar6 = i >> 0x1f;
            bVar8 = hashtest_submit::net_diff_bit._4_4_ >> 5 <= uVar6;
            if (uVar6 == hashtest_submit::net_diff_bit._4_4_ >> 5) {
              bVar8 = ((uint)hashtest_submit::net_diff_bit >> 5 |
                      hashtest_submit::net_diff_bit._4_4_ << 0x1b) <= (uint)i;
            }
            if ((bVar8) || (uVar5 = __bswap_32(*(uint *)(hash1 + (6 - i) * 4)), uVar5 != 0)) break;
            i = i + 1;
          }
          if (uVar6 == hashtest_submit::net_diff_bit._4_4_ >> 5 &&
              i == ((uint)hashtest_submit::net_diff_bit >> 5 |
                   hashtest_submit::net_diff_bit._4_4_ << 0x1b)) {
            __bswap_32(*(uint *)(hash1 + ((uint)hashtest_submit::net_diff_bit >> 5 |
                                         hashtest_submit::net_diff_bit._4_4_ << 0x1b) * -4 + 0x18));
          }
        }
        submit_nonce(thr,work,nonce);
      }
      else {
        uVar6 = __bswap_32(hash1._24_4_);
        if (uVar6 < 0xffffff) {
          hashes._0_4_ = 0x100;
          uVar2 = h_each_chain[chain_id];
          iVar7 = *(int *)((int)h_each_chain + chain_id * 8 + 4);
          *(uint *)(h_each_chain + chain_id) = (uint)uVar2 + 0x100;
          *(uint *)((int)h_each_chain + chain_id * 8 + 4) = iVar7 + (uint)(0xfffffeff < (uint)uVar2)
          ;
        }
      }
    }
  }
  else {
    if (dev->chain_exist[chain_id] == 1) {
      inc_hw_errors(thr);
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: chain[%d] nonce fail\n","driver-btm-soc.c",0x1d74,
                  "hashtest_submit",chain_id);
        }
        fclose(pFVar4);
      }
      dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
      bVar1 = dev->check_bit;
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: HW: chain[%d] asic[%d] core[%d]\n","driver-btm-soc.c",0x1d7b,
                  "hashtest_submit",chain_id,nonce >> (bVar1 + 0x18 & 0xff) & 0xff,nonce & 0xff);
        }
        fclose(pFVar4);
      }
    }
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar4 = fopen(log_file,"a+");
      if (pFVar4 != (FILE *)0x0) {
        fprintf(pFVar4,"%s:%d:%s: HASH2_32[7] != 0\n","driver-btm-soc.c",0x1d7f,"hashtest_submit");
      }
      fclose(pFVar4);
    }
    hashes._0_4_ = 0;
  }
  return (uint64_t)(uint)hashes;
}

