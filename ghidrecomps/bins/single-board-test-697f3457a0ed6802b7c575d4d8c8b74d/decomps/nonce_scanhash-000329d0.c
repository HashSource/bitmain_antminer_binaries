
void * nonce_scanhash(void *args)

{
  _Bool _Var1;
  int iVar2;
  void *args_local;
  uint8_t work [140];
  char tmp42 [1024];
  nonce_rb_format nonce_tmp;
  int ticket_mask;
  int nonceNum;
  int valid;
  int chainid;
  runtime_base_t *runtime;
  int asic;
  int asic_index;
  
  nonceNum = 0;
  runtime = (runtime_base_t *)args;
  nonce_fifo_num(&nonceNum);
  while (nonceNum != 0) {
    nonceNum = nonceNum + -1;
    pop_nonce(&nonce_tmp);
    chainid = (int)nonce_tmp.chain_id;
    memset(work,0,0x8c);
    work_list_find(nonce_tmp.work_id,work);
    memcpy(&runtime->nonce_verify_info,work,(runtime->nonce_verify_info).work_len);
    memcpy((runtime->nonce_verify_info).nonce,nonce_tmp.chip_nonce,
           (runtime->nonce_verify_info).nonce_len);
    memcpy((runtime->nonce_verify_info).sol,&nonce_tmp,(runtime->nonce_verify_info).sol_len);
    memset((runtime->nonce_verify_info).target,0,(runtime->nonce_verify_info).target_len);
    ticket_mask = 0;
    valid = (*runtime->nonce_verify)(&runtime->nonce_verify_info,&ticket_mask,runtime->nonce_shift);
    if (runtime->new_block != false) {
      runtime->new_block = false;
      memset(runtime->chain_status[chainid].one_work_nonce_each_asic,0,
             runtime->chain_status[chainid].design_asic_num << 2);
      memset(runtime->chain_status[chainid].one_work_invalid_nonce_each_asic,0,
             runtime->chain_status[chainid].design_asic_num << 2);
      memset(runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type,0,
             runtime->chain_status[chainid].design_asic_num * 0xc);
    }
    if (valid == 0) {
      runtime->valid_nonce_total = runtime->valid_nonce_total + 1;
      for (asic_index = 0; asic_index < 3; asic_index = asic_index + 1) {
        iVar2 = __aeabi_idiv(nonce_tmp.chip_addr,runtime->addr_interval);
        if (iVar2 == asic_index) {
          runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index] =
               runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index] + 1;
          runtime->chain_status[chainid].nonce_num_each_asic[asic_index] =
               runtime->chain_status[chainid].nonce_num_each_asic[asic_index] + 1;
          if (g_patten.start != 0) {
            is_patten_match(asic_index,nonce_tmp.chip_nonce,nonce_tmp.Nonce);
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
            snprintf(tmp42,0x400,
                     "Success:valid nonce: chainid=%d chipaddr=%02x nonces=%d total=%d tm=%d err=%d\n"
                     ,chainid,(uint)nonce_tmp.chip_addr,
                     runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index],
                     runtime->submit_nonce,ticket_mask,valid);
            _applog(1,tmp42,false);
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
            snprintf(tmp42,0x400,"SHA256:%02x%02x%02x%02x\n",(uint)nonce_tmp.sha256[0],
                     (uint)nonce_tmp.sha256[1],(uint)nonce_tmp.sha256[2],(uint)nonce_tmp.sha256[3]);
            _applog(4,tmp42,false);
          }
        }
      }
      if ((app_conf->work_mode == 1) &&
         (_Var1 = (*runtime->nonce_verify_target_match)
                            ((runtime->nonce_verify_info).target,g_work_info.target), _Var1 != false
         )) {
        (*runtime->nonce_submit)
                  (nonce_tmp.Nonce,(runtime->nonce_verify_info).work,g_work_info.fixed_nonce_bytes,
                   DAT_00033020);
      }
    }
    else {
      runtime->invalid_nonce_total = runtime->invalid_nonce_total + 1;
      for (asic = 0; asic < 3; asic = asic + 1) {
        iVar2 = __aeabi_idiv(nonce_tmp.chip_addr,runtime->addr_interval);
        if (iVar2 == asic) {
          runtime->chain_status[chainid].nonce_invalid_num_each_asic[asic] =
               runtime->chain_status[chainid].nonce_invalid_num_each_asic[asic] + 1;
          runtime->chain_status[chainid].one_work_invalid_nonce_each_asic[asic] =
               runtime->chain_status[chainid].one_work_invalid_nonce_each_asic[asic] + 1;
          if (valid == 1) {
            runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][1] =
                 runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][1] + 1;
          }
          else if (valid == 2) {
            runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][2] =
                 runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][2] + 1;
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
            snprintf(tmp42,0x400,
                     "Fail:invalid nonce: chainid=%d chipaddr=%02x nonces=%d tm=%d errtype=%d\n",
                     chainid,(uint)nonce_tmp.chip_addr,
                     runtime->chain_status[chainid].one_work_invalid_nonce_each_asic[asic],
                     ticket_mask,valid);
            _applog(0,tmp42,false);
          }
        }
      }
    }
  }
  return (void *)0x0;
}

