
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
          tmp42._0_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._0_4_;
          tmp42._4_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._4_4_;
          tmp42._8_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._8_4_;
          tmp42._12_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._12_4_;
          tmp42._16_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._16_4_;
          tmp42._20_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._20_4_;
          tmp42._24_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._24_4_;
          tmp42._28_4_ = s_Work_stale_due_to_stratum_inacti_000a3b60._28_4_;
          tmp42._32_3_ = (undefined3)ram0x000a3b80;
          _applog(7,tmp42,false);
        }
        return true;
      }
      _cg_rlock(&ppVar4->data_lock,"cgminer.c","stale_work",0x13cb);
      iVar1 = strcmp(work->job_id,(ppVar4->swork).job_id);
      _cg_runlock(&ppVar4->data_lock,"cgminer.c","stale_work",0x13d2);
      if (iVar1 != 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Work_stale_due_to_stratum_job_id_000a3b84[0];
          tmp42[1] = s_Work_stale_due_to_stratum_job_id_000a3b84[1];
          tmp42[2] = s_Work_stale_due_to_stratum_job_id_000a3b84[2];
          tmp42[3] = s_Work_stale_due_to_stratum_job_id_000a3b84[3];
          tmp42[4] = s_Work_stale_due_to_stratum_job_id_000a3b84[4];
          tmp42[5] = s_Work_stale_due_to_stratum_job_id_000a3b84[5];
          tmp42[6] = s_Work_stale_due_to_stratum_job_id_000a3b84[6];
          tmp42[7] = s_Work_stale_due_to_stratum_job_id_000a3b84[7];
          tmp42[8] = s_Work_stale_due_to_stratum_job_id_000a3b84[8];
          tmp42[9] = s_Work_stale_due_to_stratum_job_id_000a3b84[9];
          tmp42[10] = s_Work_stale_due_to_stratum_job_id_000a3b84[10];
          tmp42[11] = s_Work_stale_due_to_stratum_job_id_000a3b84[11];
          tmp42[12] = s_Work_stale_due_to_stratum_job_id_000a3b84[12];
          tmp42[13] = s_Work_stale_due_to_stratum_job_id_000a3b84[13];
          tmp42[14] = s_Work_stale_due_to_stratum_job_id_000a3b84[14];
          tmp42[15] = s_Work_stale_due_to_stratum_job_id_000a3b84[15];
          tmp42[16] = s_Work_stale_due_to_stratum_job_id_000a3b84[16];
          tmp42[17] = s_Work_stale_due_to_stratum_job_id_000a3b84[17];
          tmp42[18] = s_Work_stale_due_to_stratum_job_id_000a3b84[18];
          tmp42[19] = s_Work_stale_due_to_stratum_job_id_000a3b84[19];
          tmp42[20] = s_Work_stale_due_to_stratum_job_id_000a3b84[20];
          tmp42[21] = s_Work_stale_due_to_stratum_job_id_000a3b84[21];
          tmp42[22] = s_Work_stale_due_to_stratum_job_id_000a3b84[22];
          tmp42[23] = s_Work_stale_due_to_stratum_job_id_000a3b84[23];
          tmp42[24] = s_Work_stale_due_to_stratum_job_id_000a3b84[24];
          tmp42[25] = s_Work_stale_due_to_stratum_job_id_000a3b84[25];
          tmp42[26] = s_Work_stale_due_to_stratum_job_id_000a3b84[26];
          tmp42[27] = s_Work_stale_due_to_stratum_job_id_000a3b84[27];
          tmp42[28] = s_Work_stale_due_to_stratum_job_id_000a3b84[28];
          tmp42[29] = s_Work_stale_due_to_stratum_job_id_000a3b84[29];
          tmp42[30] = s_Work_stale_due_to_stratum_job_id_000a3b84[30];
          tmp42[31] = s_Work_stale_due_to_stratum_job_id_000a3b84[31];
          tmp42[32] = s_Work_stale_due_to_stratum_job_id_000a3b84[32];
          tmp42[33] = s_Work_stale_due_to_stratum_job_id_000a3b84[33];
          tmp42[34] = s_Work_stale_due_to_stratum_job_id_000a3b84[34];
          tmp42[35] = s_Work_stale_due_to_stratum_job_id_000a3b84[35];
          tmp42[36] = s_Work_stale_due_to_stratum_job_id_000a3b84[36];
          tmp42[37] = s_Work_stale_due_to_stratum_job_id_000a3b84[37];
          tmp42[38] = s_Work_stale_due_to_stratum_job_id_000a3b84[38];
          tmp42[39] = s_Work_stale_due_to_stratum_job_id_000a3b84[39];
          tmp42._40_2_ = (undefined2)ram0x000a3bac;
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
          tmp42[0] = s_Work_stale_due_to_fail_only_pool_000a3bcc[0];
          tmp42[1] = s_Work_stale_due_to_fail_only_pool_000a3bcc[1];
          tmp42[2] = s_Work_stale_due_to_fail_only_pool_000a3bcc[2];
          tmp42[3] = s_Work_stale_due_to_fail_only_pool_000a3bcc[3];
          tmp42[4] = s_Work_stale_due_to_fail_only_pool_000a3bcc[4];
          tmp42[5] = s_Work_stale_due_to_fail_only_pool_000a3bcc[5];
          tmp42[6] = s_Work_stale_due_to_fail_only_pool_000a3bcc[6];
          tmp42[7] = s_Work_stale_due_to_fail_only_pool_000a3bcc[7];
          tmp42[8] = s_Work_stale_due_to_fail_only_pool_000a3bcc[8];
          tmp42[9] = s_Work_stale_due_to_fail_only_pool_000a3bcc[9];
          tmp42[10] = s_Work_stale_due_to_fail_only_pool_000a3bcc[10];
          tmp42[11] = s_Work_stale_due_to_fail_only_pool_000a3bcc[11];
          tmp42[12] = s_Work_stale_due_to_fail_only_pool_000a3bcc[12];
          tmp42[13] = s_Work_stale_due_to_fail_only_pool_000a3bcc[13];
          tmp42[14] = s_Work_stale_due_to_fail_only_pool_000a3bcc[14];
          tmp42[15] = s_Work_stale_due_to_fail_only_pool_000a3bcc[15];
          tmp42[16] = s_Work_stale_due_to_fail_only_pool_000a3bcc[16];
          tmp42[17] = s_Work_stale_due_to_fail_only_pool_000a3bcc[17];
          tmp42[18] = s_Work_stale_due_to_fail_only_pool_000a3bcc[18];
          tmp42[19] = s_Work_stale_due_to_fail_only_pool_000a3bcc[19];
          tmp42[20] = s_Work_stale_due_to_fail_only_pool_000a3bcc[20];
          tmp42[21] = s_Work_stale_due_to_fail_only_pool_000a3bcc[21];
          tmp42[22] = s_Work_stale_due_to_fail_only_pool_000a3bcc[22];
          tmp42[23] = s_Work_stale_due_to_fail_only_pool_000a3bcc[23];
          tmp42[24] = s_Work_stale_due_to_fail_only_pool_000a3bcc[24];
          tmp42[25] = s_Work_stale_due_to_fail_only_pool_000a3bcc[25];
          tmp42[26] = s_Work_stale_due_to_fail_only_pool_000a3bcc[26];
          tmp42[27] = s_Work_stale_due_to_fail_only_pool_000a3bcc[27];
          tmp42[28] = s_Work_stale_due_to_fail_only_pool_000a3bcc[28];
          tmp42[29] = s_Work_stale_due_to_fail_only_pool_000a3bcc[29];
          tmp42[30] = s_Work_stale_due_to_fail_only_pool_000a3bcc[30];
          tmp42[31] = s_Work_stale_due_to_fail_only_pool_000a3bcc[31];
          tmp42[32] = s_Work_stale_due_to_fail_only_pool_000a3bcc[32];
          tmp42[33] = s_Work_stale_due_to_fail_only_pool_000a3bcc[33];
          tmp42[34] = s_Work_stale_due_to_fail_only_pool_000a3bcc[34];
          tmp42[35] = s_Work_stale_due_to_fail_only_pool_000a3bcc[35];
          tmp42[36] = s_Work_stale_due_to_fail_only_pool_000a3bcc[36];
          tmp42[37] = s_Work_stale_due_to_fail_only_pool_000a3bcc[37];
          tmp42[38] = s_Work_stale_due_to_fail_only_pool_000a3bcc[38];
          tmp42[39] = s_Work_stale_due_to_fail_only_pool_000a3bcc[39];
          tmp42._40_2_ = (undefined2)ram0x000a3bf4;
          _applog(7,tmp42,false);
        }
        _Var3 = true;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Work_stale_due_to_expiry_000a3bb0[0];
        tmp42[1] = s_Work_stale_due_to_expiry_000a3bb0[1];
        tmp42[2] = s_Work_stale_due_to_expiry_000a3bb0[2];
        tmp42[3] = s_Work_stale_due_to_expiry_000a3bb0[3];
        tmp42[4] = s_Work_stale_due_to_expiry_000a3bb0[4];
        tmp42[5] = s_Work_stale_due_to_expiry_000a3bb0[5];
        tmp42[6] = s_Work_stale_due_to_expiry_000a3bb0[6];
        tmp42[7] = s_Work_stale_due_to_expiry_000a3bb0[7];
        tmp42[8] = s_Work_stale_due_to_expiry_000a3bb0[8];
        tmp42[9] = s_Work_stale_due_to_expiry_000a3bb0[9];
        tmp42[10] = s_Work_stale_due_to_expiry_000a3bb0[10];
        tmp42[11] = s_Work_stale_due_to_expiry_000a3bb0[11];
        tmp42[12] = s_Work_stale_due_to_expiry_000a3bb0[12];
        tmp42[13] = s_Work_stale_due_to_expiry_000a3bb0[13];
        tmp42[14] = s_Work_stale_due_to_expiry_000a3bb0[14];
        tmp42[15] = s_Work_stale_due_to_expiry_000a3bb0[15];
        tmp42[16] = s_Work_stale_due_to_expiry_000a3bb0[16];
        tmp42[17] = s_Work_stale_due_to_expiry_000a3bb0[17];
        tmp42[18] = s_Work_stale_due_to_expiry_000a3bb0[18];
        tmp42[19] = s_Work_stale_due_to_expiry_000a3bb0[19];
        tmp42[20] = s_Work_stale_due_to_expiry_000a3bb0[20];
        tmp42[21] = s_Work_stale_due_to_expiry_000a3bb0[21];
        tmp42[22] = s_Work_stale_due_to_expiry_000a3bb0[22];
        tmp42[23] = s_Work_stale_due_to_expiry_000a3bb0[23];
        tmp42[24] = (char)ram0x000a3bc8;
        _applog(7,tmp42,false);
      }
      _Var3 = true;
    }
  }
  else {
    if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      tmp42._0_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._0_4_;
      tmp42._4_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._4_4_;
      tmp42._8_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._8_4_;
      tmp42._12_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._12_4_;
      tmp42._16_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._16_4_;
      tmp42._20_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._20_4_;
      tmp42._24_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._24_4_;
      tmp42._28_4_ = s_Work_stale_due_to_block_mismatch_000a3b3c._28_4_;
      tmp42[32] = (char)ram0x000a3b5c;
      _applog(7,tmp42,false);
    }
    _Var3 = true;
  }
  return _Var3;
}

