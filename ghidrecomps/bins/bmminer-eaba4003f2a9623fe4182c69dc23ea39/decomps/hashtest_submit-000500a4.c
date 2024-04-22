
uint64_t hashtest_submit(thr_info *thr,work *work,uint nonce,uchar *midstate,pool *pool,
                        uint64_t nonce2,uint chain_id)

{
  ulonglong uVar1;
  uint64_t uVar2;
  uint64_t uVar3;
  all_parameters *paVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint __bsx;
  bool bVar8;
  undefined8 uVar9;
  uchar *midstate_local;
  uint nonce_local;
  work *work_local;
  thr_info *thr_local;
  char tmp42 [2048];
  sha2_context ctx;
  uchar hash2 [32];
  uchar hash1 [32];
  uchar which_core_nonce;
  uchar which_asic_nonce;
  uint *hash2_32;
  uint64_t tmp_net_diff;
  uint64_t tmp_pool_diff;
  uint64_t hashes;
  int i;
  
  hashes._0_4_ = 0;
  nonce_local = nonce;
  work_local = work;
  thr_local = thr;
  uVar9 = __fixunsdfdi(*(undefined4 *)&work->sdiff,*(undefined4 *)((int)&work->sdiff + 4));
  if ((int)((ulonglong)uVar9 >> 0x20) != hashtest_submit::pool_diff._4_4_ ||
      (int)uVar9 != (int)hashtest_submit::pool_diff) {
    hashtest_submit::pool_diff =
         __fixunsdfdi(*(undefined4 *)&work_local->sdiff,*(undefined4 *)((int)&work_local->sdiff + 4)
                     );
    hashtest_submit::pool_diff_bit._0_4_ = 0;
    hashtest_submit::pool_diff_bit._4_4_ = 0;
    uVar1 = hashtest_submit::pool_diff;
    while( true ) {
      tmp_pool_diff._0_4_ = (uint)uVar1;
      if (uVar1 == 0) break;
      uVar1 = CONCAT44((uint)(uVar1 >> 0x21),
                       (uint)((uVar1 & 0x100000000) != 0) << 0x1f | (uint)tmp_pool_diff >> 1);
      bVar8 = 0xfffffffe < (uint)hashtest_submit::pool_diff_bit;
      hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit + 1;
      hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ + bVar8;
    }
    bVar8 = (uint)hashtest_submit::pool_diff_bit != 0;
    hashtest_submit::pool_diff_bit._0_4_ = (uint)hashtest_submit::pool_diff_bit - 1;
    hashtest_submit::pool_diff_bit._4_4_ = hashtest_submit::pool_diff_bit._4_4_ + -1 + (uint)bVar8;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: pool_diff:%d work_diff:%d pool_diff_bit:%d ...\n","hashtest_submit",
               (int)hashtest_submit::pool_diff,(int)(hashtest_submit::pool_diff >> 0x20),
               *(undefined4 *)&work_local->sdiff,*(undefined4 *)((int)&work_local->sdiff + 4),
               (uint)hashtest_submit::pool_diff_bit,hashtest_submit::pool_diff_bit._4_4_);
      _applog(7,tmp42,false);
    }
  }
  uVar9 = __fixunsdfdi(current_diff._0_4_,current_diff._4_4_);
  if ((int)((ulonglong)uVar9 >> 0x20) != hashtest_submit::net_diff._4_4_ ||
      (int)uVar9 != (int)hashtest_submit::net_diff) {
    hashtest_submit::net_diff = __fixunsdfdi(current_diff._0_4_,current_diff._4_4_);
    hashtest_submit::net_diff_bit._0_4_ = 0;
    hashtest_submit::net_diff_bit._4_4_ = 0;
    uVar1 = hashtest_submit::net_diff;
    while( true ) {
      tmp_net_diff._0_4_ = (uint)uVar1;
      if (uVar1 == 0) break;
      uVar1 = CONCAT44((uint)(uVar1 >> 0x21),
                       (uint)((uVar1 & 0x100000000) != 0) << 0x1f | (uint)tmp_net_diff >> 1);
      bVar8 = 0xfffffffe < (uint)hashtest_submit::net_diff_bit;
      hashtest_submit::net_diff_bit._0_4_ = (uint)hashtest_submit::net_diff_bit + 1;
      hashtest_submit::net_diff_bit._4_4_ = hashtest_submit::net_diff_bit._4_4_ + bVar8;
    }
    bVar8 = (uint)hashtest_submit::net_diff_bit != 0;
    hashtest_submit::net_diff_bit._0_4_ = (uint)hashtest_submit::net_diff_bit - 1;
    hashtest_submit::net_diff_bit._4_4_ = hashtest_submit::net_diff_bit._4_4_ + -1 + (uint)bVar8;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s:net_diff:%d current_diff:%d net_diff_bit %d ...\n","hashtest_submit",
               (int)hashtest_submit::net_diff,(int)(hashtest_submit::net_diff >> 0x20),
               current_diff._0_4_,current_diff._4_4_,(uint)hashtest_submit::net_diff_bit,
               hashtest_submit::net_diff_bit._4_4_);
      _applog(7,tmp42,false);
    }
  }
  ctx.state[0] = *(uint *)work_local->midstate;
  ctx.state[1] = *(uint *)(work_local->midstate + 4);
  ctx.state[2] = *(uint *)(work_local->midstate + 8);
  ctx.state[3] = *(uint *)(work_local->midstate + 0xc);
  ctx.state[4] = *(uint *)(work_local->midstate + 0x10);
  ctx.state[5] = *(uint *)(work_local->midstate + 0x14);
  ctx.state[6] = *(uint *)(work_local->midstate + 0x18);
  ctx.state[7] = *(uint *)(work_local->midstate + 0x1c);
  ctx.total[0] = 0x50;
  ctx.total[1] = 0;
  memcpy(hash1,work_local->data + 0x40,0xc);
  flip_swab(ctx.buffer,hash1,0xc);
  memcpy(hash1,&nonce_local,4);
  flip_swab(ctx.buffer + 0xc,hash1,4);
  sha2_finish(&ctx,hash1);
  memset(&ctx,0,0xe8);
  sha2(hash1,0x20,hash2);
  flip32(hash1,hash2);
  if (hash1._28_4_ == 0) {
    i = 0;
    while ((i < 7 && (uVar7 = *(uint *)(hash1 + (6 - i) * 4),
                     (uVar7 << 0x18 |
                     uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8) == 0))) {
      i = i + 1;
    }
    bVar8 = hashtest_submit::pool_diff_bit._4_4_ >> 5 <= (uint)(i >> 0x1f);
    if (i >> 0x1f == hashtest_submit::pool_diff_bit._4_4_ >> 5) {
      bVar8 = ((uint)hashtest_submit::pool_diff_bit >> 5 |
              hashtest_submit::pool_diff_bit._4_4_ << 0x1b) <= (uint)i;
    }
    uVar2 = hashtest_submit::pool_diff;
    uVar3 = hashtest_submit::net_diff;
    if (bVar8) {
      uVar7 = nonce_local >> (dev->check_bit + 0x18 & 0xff);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: chain %d which_asic_nonce %d which_core_nonce %d",
                 "hashtest_submit",chain_id,uVar7 & 0xff,nonce_local & 0xff);
        _applog(7,tmp42,false);
      }
      paVar4 = dev;
      uVar7 = uVar7 & 0xff;
      uVar5 = *(uint *)(dev->chain_asic_nonce[chain_id] + uVar7);
      iVar6 = *(int *)((int)dev->chain_asic_nonce[chain_id] + uVar7 * 8 + 4);
      *(uint *)(dev->chain_asic_nonce[chain_id] + uVar7) = uVar5 + 1;
      *(uint *)((int)paVar4->chain_asic_nonce[chain_id] + uVar7 * 8 + 4) =
           iVar6 + (uint)(0xfffffffe < uVar5);
      uVar7 = *(uint *)(hash1 + ((uint)hashtest_submit::pool_diff_bit >> 5 |
                                hashtest_submit::pool_diff_bit._4_4_ << 0x1b) * -4 + 0x18);
      if ((uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18) <
          0xffffffffU >> ((uint)hashtest_submit::pool_diff_bit & 0x1f)) {
        hashes._0_4_ = 0x100;
        if ((double)CONCAT44(current_diff._4_4_,current_diff._0_4_) != 0.0) {
          i = 0;
          while( true ) {
            bVar8 = hashtest_submit::net_diff_bit._4_4_ >> 5 <= (uint)(i >> 0x1f);
            if (i >> 0x1f == hashtest_submit::net_diff_bit._4_4_ >> 5) {
              bVar8 = ((uint)hashtest_submit::net_diff_bit >> 5 |
                      hashtest_submit::net_diff_bit._4_4_ << 0x1b) <= (uint)i;
            }
            if ((bVar8) ||
               (uVar7 = *(uint *)(hash1 + (6 - i) * 4),
               (uVar7 << 0x18 | uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8) !=
               0)) break;
            i = i + 1;
          }
        }
        submit_nonce(thr_local,work_local,nonce_local);
        uVar2 = hashtest_submit::pool_diff;
        uVar3 = hashtest_submit::net_diff;
      }
      else {
        uVar2 = hashtest_submit::pool_diff;
        uVar3 = hashtest_submit::net_diff;
        if (((uint)hash1._24_4_ >> 0x18 | (hash1._24_4_ & 0xff0000) >> 8 |
             (hash1._24_4_ & 0xff00) << 8 | hash1._24_4_ << 0x18) < 0xffffff) {
          hashes._0_4_ = 0x100;
          uVar7 = *(uint *)(h_each_chain + chain_id);
          iVar6 = *(int *)((int)h_each_chain + chain_id * 8 + 4);
          *(uint *)(h_each_chain + chain_id) = uVar7 + 0x100;
          *(uint *)((int)h_each_chain + chain_id * 8 + 4) = iVar6 + (uint)(0xfffffeff < uVar7);
          uVar2 = hashtest_submit::pool_diff;
          uVar3 = hashtest_submit::net_diff;
        }
      }
    }
  }
  else {
    if (dev->chain_exist[chain_id] == 1) {
      inc_hw_errors(thr_local);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"[%s] chain[%d] nonce fail\n","hashtest_submit",chain_id);
        _applog(7,tmp42,false);
      }
      dev->chain_hw[chain_id] = dev->chain_hw[chain_id] + 1;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: HASH2_32[7] != 0","hashtest_submit");
      _applog(7,tmp42,false);
    }
    hashes._0_4_ = 0;
    uVar2 = hashtest_submit::pool_diff;
    uVar3 = hashtest_submit::net_diff;
  }
  hashtest_submit::net_diff._4_4_ = (int)(uVar3 >> 0x20);
  hashtest_submit::net_diff._0_4_ = (int)uVar3;
  hashtest_submit::pool_diff._4_4_ = (int)(uVar2 >> 0x20);
  hashtest_submit::pool_diff._0_4_ = (int)uVar2;
  return (uint64_t)(uint)hashes;
}

