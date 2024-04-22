
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

_Bool stale_work(work *work,_Bool share)

{
  int iVar1;
  pool *ppVar2;
  _Bool _Var3;
  pool *ppVar4;
  _Bool share_local;
  work *work_local;
  char tmp42 [2048];
  timeval now;
  int getwork_delay;
  pool *pool;
  _Bool same_job;
  time_t work_expiry;
  
  if ((opt_benchmark) || (opt_benchfile != (char *)0x0)) {
    _Var3 = false;
  }
  else if (work->work_block == work_block) {
    if (opt_scantime < work->rolltime) {
      work_expiry = work->rolltime;
    }
    else {
      work_expiry = opt_expiry;
    }
    ppVar4 = work->pool;
    if ((!share) && (ppVar4->has_stratum != false)) {
      if ((ppVar4->stratum_active != true) || (ppVar4->stratum_notify != true)) {
        if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
          tmp42._0_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._0_4_;
          tmp42._4_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._4_4_;
          tmp42._8_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._8_4_;
          tmp42._12_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._12_4_;
          tmp42._16_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._16_4_;
          tmp42._20_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._20_4_;
          tmp42._24_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._24_4_;
          tmp42._28_4_ = s_Work_stale_due_to_stratum_inacti_0008c7a4._28_4_;
          tmp42._32_3_ = (undefined3)ram0x0008c7c4;
          _applog(7,tmp42,false);
        }
        return true;
      }
      _cg_rlock(&ppVar4->data_lock,"cgminer.c","stale_work",0x13ce);
      iVar1 = strcmp(work->job_id,(ppVar4->swork).job_id);
      _cg_runlock(&ppVar4->data_lock,"cgminer.c","stale_work",0x13d5);
      if (iVar1 != 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Work_stale_due_to_stratum_job_id_0008c7c8[0];
          tmp42[1] = s_Work_stale_due_to_stratum_job_id_0008c7c8[1];
          tmp42[2] = s_Work_stale_due_to_stratum_job_id_0008c7c8[2];
          tmp42[3] = s_Work_stale_due_to_stratum_job_id_0008c7c8[3];
          tmp42[4] = s_Work_stale_due_to_stratum_job_id_0008c7c8[4];
          tmp42[5] = s_Work_stale_due_to_stratum_job_id_0008c7c8[5];
          tmp42[6] = s_Work_stale_due_to_stratum_job_id_0008c7c8[6];
          tmp42[7] = s_Work_stale_due_to_stratum_job_id_0008c7c8[7];
          tmp42[8] = s_Work_stale_due_to_stratum_job_id_0008c7c8[8];
          tmp42[9] = s_Work_stale_due_to_stratum_job_id_0008c7c8[9];
          tmp42[10] = s_Work_stale_due_to_stratum_job_id_0008c7c8[10];
          tmp42[11] = s_Work_stale_due_to_stratum_job_id_0008c7c8[11];
          tmp42[12] = s_Work_stale_due_to_stratum_job_id_0008c7c8[12];
          tmp42[13] = s_Work_stale_due_to_stratum_job_id_0008c7c8[13];
          tmp42[14] = s_Work_stale_due_to_stratum_job_id_0008c7c8[14];
          tmp42[15] = s_Work_stale_due_to_stratum_job_id_0008c7c8[15];
          tmp42[16] = s_Work_stale_due_to_stratum_job_id_0008c7c8[16];
          tmp42[17] = s_Work_stale_due_to_stratum_job_id_0008c7c8[17];
          tmp42[18] = s_Work_stale_due_to_stratum_job_id_0008c7c8[18];
          tmp42[19] = s_Work_stale_due_to_stratum_job_id_0008c7c8[19];
          tmp42[20] = s_Work_stale_due_to_stratum_job_id_0008c7c8[20];
          tmp42[21] = s_Work_stale_due_to_stratum_job_id_0008c7c8[21];
          tmp42[22] = s_Work_stale_due_to_stratum_job_id_0008c7c8[22];
          tmp42[23] = s_Work_stale_due_to_stratum_job_id_0008c7c8[23];
          tmp42[24] = s_Work_stale_due_to_stratum_job_id_0008c7c8[24];
          tmp42[25] = s_Work_stale_due_to_stratum_job_id_0008c7c8[25];
          tmp42[26] = s_Work_stale_due_to_stratum_job_id_0008c7c8[26];
          tmp42[27] = s_Work_stale_due_to_stratum_job_id_0008c7c8[27];
          tmp42[28] = s_Work_stale_due_to_stratum_job_id_0008c7c8[28];
          tmp42[29] = s_Work_stale_due_to_stratum_job_id_0008c7c8[29];
          tmp42[30] = s_Work_stale_due_to_stratum_job_id_0008c7c8[30];
          tmp42[31] = s_Work_stale_due_to_stratum_job_id_0008c7c8[31];
          tmp42[32] = s_Work_stale_due_to_stratum_job_id_0008c7c8[32];
          tmp42[33] = s_Work_stale_due_to_stratum_job_id_0008c7c8[33];
          tmp42[34] = s_Work_stale_due_to_stratum_job_id_0008c7c8[34];
          tmp42[35] = s_Work_stale_due_to_stratum_job_id_0008c7c8[35];
          tmp42[36] = s_Work_stale_due_to_stratum_job_id_0008c7c8[36];
          tmp42[37] = s_Work_stale_due_to_stratum_job_id_0008c7c8[37];
          tmp42[38] = s_Work_stale_due_to_stratum_job_id_0008c7c8[38];
          tmp42[39] = s_Work_stale_due_to_stratum_job_id_0008c7c8[39];
          tmp42._40_2_ = (undefined2)ram0x0008c7f0;
          _applog(7,tmp42,false);
        }
        return true;
      }
    }
    work_expiry = work_expiry -
                  (int)(longlong)((ppVar4->cgminer_pool_stats).getwork_wait_rolling * 5.0 + 1.0);
    if (work_expiry < 5) {
      work_expiry = 5;
    }
    cgtime(&now);
    if (now.tv_sec - (work->tv_staged).tv_sec < work_expiry) {
      if (((opt_fail_only == false) || (share)) ||
         ((ppVar2 = current_pool(), ppVar4 == ppVar2 ||
          (((work->mandatory == true || (pool_strategy == POOL_LOADBALANCE)) ||
           (pool_strategy == POOL_BALANCE)))))) {
        _Var3 = false;
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Work_stale_due_to_fail_only_pool_0008c810[0];
          tmp42[1] = s_Work_stale_due_to_fail_only_pool_0008c810[1];
          tmp42[2] = s_Work_stale_due_to_fail_only_pool_0008c810[2];
          tmp42[3] = s_Work_stale_due_to_fail_only_pool_0008c810[3];
          tmp42[4] = s_Work_stale_due_to_fail_only_pool_0008c810[4];
          tmp42[5] = s_Work_stale_due_to_fail_only_pool_0008c810[5];
          tmp42[6] = s_Work_stale_due_to_fail_only_pool_0008c810[6];
          tmp42[7] = s_Work_stale_due_to_fail_only_pool_0008c810[7];
          tmp42[8] = s_Work_stale_due_to_fail_only_pool_0008c810[8];
          tmp42[9] = s_Work_stale_due_to_fail_only_pool_0008c810[9];
          tmp42[10] = s_Work_stale_due_to_fail_only_pool_0008c810[10];
          tmp42[11] = s_Work_stale_due_to_fail_only_pool_0008c810[11];
          tmp42[12] = s_Work_stale_due_to_fail_only_pool_0008c810[12];
          tmp42[13] = s_Work_stale_due_to_fail_only_pool_0008c810[13];
          tmp42[14] = s_Work_stale_due_to_fail_only_pool_0008c810[14];
          tmp42[15] = s_Work_stale_due_to_fail_only_pool_0008c810[15];
          tmp42[16] = s_Work_stale_due_to_fail_only_pool_0008c810[16];
          tmp42[17] = s_Work_stale_due_to_fail_only_pool_0008c810[17];
          tmp42[18] = s_Work_stale_due_to_fail_only_pool_0008c810[18];
          tmp42[19] = s_Work_stale_due_to_fail_only_pool_0008c810[19];
          tmp42[20] = s_Work_stale_due_to_fail_only_pool_0008c810[20];
          tmp42[21] = s_Work_stale_due_to_fail_only_pool_0008c810[21];
          tmp42[22] = s_Work_stale_due_to_fail_only_pool_0008c810[22];
          tmp42[23] = s_Work_stale_due_to_fail_only_pool_0008c810[23];
          tmp42[24] = s_Work_stale_due_to_fail_only_pool_0008c810[24];
          tmp42[25] = s_Work_stale_due_to_fail_only_pool_0008c810[25];
          tmp42[26] = s_Work_stale_due_to_fail_only_pool_0008c810[26];
          tmp42[27] = s_Work_stale_due_to_fail_only_pool_0008c810[27];
          tmp42[28] = s_Work_stale_due_to_fail_only_pool_0008c810[28];
          tmp42[29] = s_Work_stale_due_to_fail_only_pool_0008c810[29];
          tmp42[30] = s_Work_stale_due_to_fail_only_pool_0008c810[30];
          tmp42[31] = s_Work_stale_due_to_fail_only_pool_0008c810[31];
          tmp42[32] = s_Work_stale_due_to_fail_only_pool_0008c810[32];
          tmp42[33] = s_Work_stale_due_to_fail_only_pool_0008c810[33];
          tmp42[34] = s_Work_stale_due_to_fail_only_pool_0008c810[34];
          tmp42[35] = s_Work_stale_due_to_fail_only_pool_0008c810[35];
          tmp42[36] = s_Work_stale_due_to_fail_only_pool_0008c810[36];
          tmp42[37] = s_Work_stale_due_to_fail_only_pool_0008c810[37];
          tmp42[38] = s_Work_stale_due_to_fail_only_pool_0008c810[38];
          tmp42[39] = s_Work_stale_due_to_fail_only_pool_0008c810[39];
          tmp42._40_2_ = (undefined2)ram0x0008c838;
          _applog(7,tmp42,false);
        }
        _Var3 = true;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Work_stale_due_to_expiry_0008c7f4[0];
        tmp42[1] = s_Work_stale_due_to_expiry_0008c7f4[1];
        tmp42[2] = s_Work_stale_due_to_expiry_0008c7f4[2];
        tmp42[3] = s_Work_stale_due_to_expiry_0008c7f4[3];
        tmp42[4] = s_Work_stale_due_to_expiry_0008c7f4[4];
        tmp42[5] = s_Work_stale_due_to_expiry_0008c7f4[5];
        tmp42[6] = s_Work_stale_due_to_expiry_0008c7f4[6];
        tmp42[7] = s_Work_stale_due_to_expiry_0008c7f4[7];
        tmp42[8] = s_Work_stale_due_to_expiry_0008c7f4[8];
        tmp42[9] = s_Work_stale_due_to_expiry_0008c7f4[9];
        tmp42[10] = s_Work_stale_due_to_expiry_0008c7f4[10];
        tmp42[11] = s_Work_stale_due_to_expiry_0008c7f4[11];
        tmp42[12] = s_Work_stale_due_to_expiry_0008c7f4[12];
        tmp42[13] = s_Work_stale_due_to_expiry_0008c7f4[13];
        tmp42[14] = s_Work_stale_due_to_expiry_0008c7f4[14];
        tmp42[15] = s_Work_stale_due_to_expiry_0008c7f4[15];
        tmp42[16] = s_Work_stale_due_to_expiry_0008c7f4[16];
        tmp42[17] = s_Work_stale_due_to_expiry_0008c7f4[17];
        tmp42[18] = s_Work_stale_due_to_expiry_0008c7f4[18];
        tmp42[19] = s_Work_stale_due_to_expiry_0008c7f4[19];
        tmp42[20] = s_Work_stale_due_to_expiry_0008c7f4[20];
        tmp42[21] = s_Work_stale_due_to_expiry_0008c7f4[21];
        tmp42[22] = s_Work_stale_due_to_expiry_0008c7f4[22];
        tmp42[23] = s_Work_stale_due_to_expiry_0008c7f4[23];
        tmp42[24] = (char)ram0x0008c80c;
        _applog(7,tmp42,false);
      }
      _Var3 = true;
    }
  }
  else {
    if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      tmp42._0_4_ = s_Work_stale_due_to_block_mismatch_0008c780._0_4_;
      tmp42._4_4_ = s_Work_stale_due_to_block_mismatch_0008c780._4_4_;
      tmp42._8_4_ = s_Work_stale_due_to_block_mismatch_0008c780._8_4_;
      tmp42._12_4_ = s_Work_stale_due_to_block_mismatch_0008c780._12_4_;
      tmp42._16_4_ = s_Work_stale_due_to_block_mismatch_0008c780._16_4_;
      tmp42._20_4_ = s_Work_stale_due_to_block_mismatch_0008c780._20_4_;
      tmp42._24_4_ = s_Work_stale_due_to_block_mismatch_0008c780._24_4_;
      tmp42._28_4_ = s_Work_stale_due_to_block_mismatch_0008c780._28_4_;
      tmp42[32] = (char)ram0x0008c7a0;
      _applog(7,tmp42,false);
    }
    _Var3 = true;
  }
  return _Var3;
}

