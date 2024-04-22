
void equihash_nonce_submit(uint8_t *nonce,uint8_t *verify,int fixed_nonce_bytes,char *job_id)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  uint64_t uVar4;
  char *job_id_local;
  int fixed_nonce_bytes_local;
  uint8_t *verify_local;
  uint8_t *nonce_local;
  char tmp42 [1024];
  
  iVar1 = equihash_nonce_submit::golden_nonce;
  bVar3 = 0xfffffffe < (uint)equihash_nonce_submit::total;
  equihash_nonce_submit::total._0_4_ = (uint)equihash_nonce_submit::total + 1;
  equihash_nonce_submit::total._4_4_ = equihash_nonce_submit::total._4_4_ + (uint)bVar3;
  if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
    equihash_nonce_submit::golden_nonce = equihash_nonce_submit::golden_nonce + 1;
    snprintf(tmp42,0x400,"Golden Nonce Found! %d\n",iVar1);
    _applog(3,tmp42,false);
  }
  print_solver_line(nonce,verify,fixed_nonce_bytes,job_id);
  bVar3 = 0xfffffffe < (uint)equihash_nonce_submit::total_shares;
  equihash_nonce_submit::total_shares._0_4_ = (uint)equihash_nonce_submit::total_shares + 1;
  equihash_nonce_submit::total_shares._4_4_ =
       equihash_nonce_submit::total_shares._4_4_ + (uint)bVar3;
  uVar4 = miner_now();
  equihash_nonce_submit::t1._0_4_ = (uint)uVar4;
  equihash_nonce_submit::t1._4_4_ = (uint)(uVar4 >> 0x20);
  uVar2 = equihash_nonce_submit::status_period._4_4_ +
          equihash_nonce_submit::t0._4_4_ +
          CARRY4((uint)equihash_nonce_submit::status_period,(uint)equihash_nonce_submit::t0);
  bVar3 = equihash_nonce_submit::t1._4_4_ <= uVar2;
  if (uVar2 == equihash_nonce_submit::t1._4_4_) {
    bVar3 = (uint)equihash_nonce_submit::t1 <=
            (uint)equihash_nonce_submit::status_period + (uint)equihash_nonce_submit::t0;
  }
  if (!bVar3) {
    equihash_nonce_submit::t0._0_4_ = (uint)equihash_nonce_submit::t1;
    equihash_nonce_submit::t0._4_4_ = equihash_nonce_submit::t1._4_4_;
    equihash_nonce_submit::t1 = uVar4;
    printf("status: %lld %lld\n",(uint)equihash_nonce_submit::total,
           (uint)equihash_nonce_submit::total,equihash_nonce_submit::total._4_4_,
           (uint)equihash_nonce_submit::total_shares,equihash_nonce_submit::total_shares._4_4_);
    fflush(stdout);
    uVar4 = equihash_nonce_submit::t1;
  }
  equihash_nonce_submit::t1 = uVar4;
  return;
}

