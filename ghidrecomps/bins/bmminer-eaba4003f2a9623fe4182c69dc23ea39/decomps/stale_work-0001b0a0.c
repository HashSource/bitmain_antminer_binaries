
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
          tmp42._0_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._0_4_;
          tmp42._4_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._4_4_;
          tmp42._8_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._8_4_;
          tmp42._12_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._12_4_;
          tmp42._16_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._16_4_;
          tmp42._20_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._20_4_;
          tmp42._24_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._24_4_;
          tmp42._28_4_ = s_Work_stale_due_to_stratum_inacti_00072f88._28_4_;
          tmp42._32_3_ = (undefined3)ram0x00072fa8;
          _applog(7,tmp42,false);
        }
        return true;
      }
      _cg_rlock(&ppVar4->data_lock,"cgminer.c","stale_work",0x1384);
      iVar1 = strcmp(work->job_id,(ppVar4->swork).job_id);
      _cg_runlock(&ppVar4->data_lock,"cgminer.c","stale_work",0x138b);
      if (iVar1 != 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Work_stale_due_to_stratum_job_id_00072fac[0];
          tmp42[1] = s_Work_stale_due_to_stratum_job_id_00072fac[1];
          tmp42[2] = s_Work_stale_due_to_stratum_job_id_00072fac[2];
          tmp42[3] = s_Work_stale_due_to_stratum_job_id_00072fac[3];
          tmp42[4] = s_Work_stale_due_to_stratum_job_id_00072fac[4];
          tmp42[5] = s_Work_stale_due_to_stratum_job_id_00072fac[5];
          tmp42[6] = s_Work_stale_due_to_stratum_job_id_00072fac[6];
          tmp42[7] = s_Work_stale_due_to_stratum_job_id_00072fac[7];
          tmp42[8] = s_Work_stale_due_to_stratum_job_id_00072fac[8];
          tmp42[9] = s_Work_stale_due_to_stratum_job_id_00072fac[9];
          tmp42[10] = s_Work_stale_due_to_stratum_job_id_00072fac[10];
          tmp42[11] = s_Work_stale_due_to_stratum_job_id_00072fac[11];
          tmp42[12] = s_Work_stale_due_to_stratum_job_id_00072fac[12];
          tmp42[13] = s_Work_stale_due_to_stratum_job_id_00072fac[13];
          tmp42[14] = s_Work_stale_due_to_stratum_job_id_00072fac[14];
          tmp42[15] = s_Work_stale_due_to_stratum_job_id_00072fac[15];
          tmp42[16] = s_Work_stale_due_to_stratum_job_id_00072fac[16];
          tmp42[17] = s_Work_stale_due_to_stratum_job_id_00072fac[17];
          tmp42[18] = s_Work_stale_due_to_stratum_job_id_00072fac[18];
          tmp42[19] = s_Work_stale_due_to_stratum_job_id_00072fac[19];
          tmp42[20] = s_Work_stale_due_to_stratum_job_id_00072fac[20];
          tmp42[21] = s_Work_stale_due_to_stratum_job_id_00072fac[21];
          tmp42[22] = s_Work_stale_due_to_stratum_job_id_00072fac[22];
          tmp42[23] = s_Work_stale_due_to_stratum_job_id_00072fac[23];
          tmp42[24] = s_Work_stale_due_to_stratum_job_id_00072fac[24];
          tmp42[25] = s_Work_stale_due_to_stratum_job_id_00072fac[25];
          tmp42[26] = s_Work_stale_due_to_stratum_job_id_00072fac[26];
          tmp42[27] = s_Work_stale_due_to_stratum_job_id_00072fac[27];
          tmp42[28] = s_Work_stale_due_to_stratum_job_id_00072fac[28];
          tmp42[29] = s_Work_stale_due_to_stratum_job_id_00072fac[29];
          tmp42[30] = s_Work_stale_due_to_stratum_job_id_00072fac[30];
          tmp42[31] = s_Work_stale_due_to_stratum_job_id_00072fac[31];
          tmp42[32] = s_Work_stale_due_to_stratum_job_id_00072fac[32];
          tmp42[33] = s_Work_stale_due_to_stratum_job_id_00072fac[33];
          tmp42[34] = s_Work_stale_due_to_stratum_job_id_00072fac[34];
          tmp42[35] = s_Work_stale_due_to_stratum_job_id_00072fac[35];
          tmp42[36] = s_Work_stale_due_to_stratum_job_id_00072fac[36];
          tmp42[37] = s_Work_stale_due_to_stratum_job_id_00072fac[37];
          tmp42[38] = s_Work_stale_due_to_stratum_job_id_00072fac[38];
          tmp42[39] = s_Work_stale_due_to_stratum_job_id_00072fac[39];
          tmp42._40_2_ = (undefined2)ram0x00072fd4;
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
         ((ppVar2 = current_pool(), ppVar2 == ppVar4 ||
          (((work->mandatory == true || (pool_strategy == POOL_LOADBALANCE)) ||
           (pool_strategy == POOL_BALANCE)))))) {
        _Var3 = false;
      }
      else {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          tmp42[0] = s_Work_stale_due_to_fail_only_pool_00072ff4[0];
          tmp42[1] = s_Work_stale_due_to_fail_only_pool_00072ff4[1];
          tmp42[2] = s_Work_stale_due_to_fail_only_pool_00072ff4[2];
          tmp42[3] = s_Work_stale_due_to_fail_only_pool_00072ff4[3];
          tmp42[4] = s_Work_stale_due_to_fail_only_pool_00072ff4[4];
          tmp42[5] = s_Work_stale_due_to_fail_only_pool_00072ff4[5];
          tmp42[6] = s_Work_stale_due_to_fail_only_pool_00072ff4[6];
          tmp42[7] = s_Work_stale_due_to_fail_only_pool_00072ff4[7];
          tmp42[8] = s_Work_stale_due_to_fail_only_pool_00072ff4[8];
          tmp42[9] = s_Work_stale_due_to_fail_only_pool_00072ff4[9];
          tmp42[10] = s_Work_stale_due_to_fail_only_pool_00072ff4[10];
          tmp42[11] = s_Work_stale_due_to_fail_only_pool_00072ff4[11];
          tmp42[12] = s_Work_stale_due_to_fail_only_pool_00072ff4[12];
          tmp42[13] = s_Work_stale_due_to_fail_only_pool_00072ff4[13];
          tmp42[14] = s_Work_stale_due_to_fail_only_pool_00072ff4[14];
          tmp42[15] = s_Work_stale_due_to_fail_only_pool_00072ff4[15];
          tmp42[16] = s_Work_stale_due_to_fail_only_pool_00072ff4[16];
          tmp42[17] = s_Work_stale_due_to_fail_only_pool_00072ff4[17];
          tmp42[18] = s_Work_stale_due_to_fail_only_pool_00072ff4[18];
          tmp42[19] = s_Work_stale_due_to_fail_only_pool_00072ff4[19];
          tmp42[20] = s_Work_stale_due_to_fail_only_pool_00072ff4[20];
          tmp42[21] = s_Work_stale_due_to_fail_only_pool_00072ff4[21];
          tmp42[22] = s_Work_stale_due_to_fail_only_pool_00072ff4[22];
          tmp42[23] = s_Work_stale_due_to_fail_only_pool_00072ff4[23];
          tmp42[24] = s_Work_stale_due_to_fail_only_pool_00072ff4[24];
          tmp42[25] = s_Work_stale_due_to_fail_only_pool_00072ff4[25];
          tmp42[26] = s_Work_stale_due_to_fail_only_pool_00072ff4[26];
          tmp42[27] = s_Work_stale_due_to_fail_only_pool_00072ff4[27];
          tmp42[28] = s_Work_stale_due_to_fail_only_pool_00072ff4[28];
          tmp42[29] = s_Work_stale_due_to_fail_only_pool_00072ff4[29];
          tmp42[30] = s_Work_stale_due_to_fail_only_pool_00072ff4[30];
          tmp42[31] = s_Work_stale_due_to_fail_only_pool_00072ff4[31];
          tmp42[32] = s_Work_stale_due_to_fail_only_pool_00072ff4[32];
          tmp42[33] = s_Work_stale_due_to_fail_only_pool_00072ff4[33];
          tmp42[34] = s_Work_stale_due_to_fail_only_pool_00072ff4[34];
          tmp42[35] = s_Work_stale_due_to_fail_only_pool_00072ff4[35];
          tmp42[36] = s_Work_stale_due_to_fail_only_pool_00072ff4[36];
          tmp42[37] = s_Work_stale_due_to_fail_only_pool_00072ff4[37];
          tmp42[38] = s_Work_stale_due_to_fail_only_pool_00072ff4[38];
          tmp42[39] = s_Work_stale_due_to_fail_only_pool_00072ff4[39];
          tmp42._40_2_ = (undefined2)ram0x0007301c;
          _applog(7,tmp42,false);
        }
        _Var3 = true;
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        tmp42[0] = s_Work_stale_due_to_expiry_00072fd8[0];
        tmp42[1] = s_Work_stale_due_to_expiry_00072fd8[1];
        tmp42[2] = s_Work_stale_due_to_expiry_00072fd8[2];
        tmp42[3] = s_Work_stale_due_to_expiry_00072fd8[3];
        tmp42[4] = s_Work_stale_due_to_expiry_00072fd8[4];
        tmp42[5] = s_Work_stale_due_to_expiry_00072fd8[5];
        tmp42[6] = s_Work_stale_due_to_expiry_00072fd8[6];
        tmp42[7] = s_Work_stale_due_to_expiry_00072fd8[7];
        tmp42[8] = s_Work_stale_due_to_expiry_00072fd8[8];
        tmp42[9] = s_Work_stale_due_to_expiry_00072fd8[9];
        tmp42[10] = s_Work_stale_due_to_expiry_00072fd8[10];
        tmp42[11] = s_Work_stale_due_to_expiry_00072fd8[11];
        tmp42[12] = s_Work_stale_due_to_expiry_00072fd8[12];
        tmp42[13] = s_Work_stale_due_to_expiry_00072fd8[13];
        tmp42[14] = s_Work_stale_due_to_expiry_00072fd8[14];
        tmp42[15] = s_Work_stale_due_to_expiry_00072fd8[15];
        tmp42[16] = s_Work_stale_due_to_expiry_00072fd8[16];
        tmp42[17] = s_Work_stale_due_to_expiry_00072fd8[17];
        tmp42[18] = s_Work_stale_due_to_expiry_00072fd8[18];
        tmp42[19] = s_Work_stale_due_to_expiry_00072fd8[19];
        tmp42[20] = s_Work_stale_due_to_expiry_00072fd8[20];
        tmp42[21] = s_Work_stale_due_to_expiry_00072fd8[21];
        tmp42[22] = s_Work_stale_due_to_expiry_00072fd8[22];
        tmp42[23] = s_Work_stale_due_to_expiry_00072fd8[23];
        tmp42[24] = (char)ram0x00072ff0;
        _applog(7,tmp42,false);
      }
      _Var3 = true;
    }
  }
  else {
    if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
      tmp42._0_4_ = s_Work_stale_due_to_block_mismatch_00072f64._0_4_;
      tmp42._4_4_ = s_Work_stale_due_to_block_mismatch_00072f64._4_4_;
      tmp42._8_4_ = s_Work_stale_due_to_block_mismatch_00072f64._8_4_;
      tmp42._12_4_ = s_Work_stale_due_to_block_mismatch_00072f64._12_4_;
      tmp42._16_4_ = s_Work_stale_due_to_block_mismatch_00072f64._16_4_;
      tmp42._20_4_ = s_Work_stale_due_to_block_mismatch_00072f64._20_4_;
      tmp42._24_4_ = s_Work_stale_due_to_block_mismatch_00072f64._24_4_;
      tmp42._28_4_ = s_Work_stale_due_to_block_mismatch_00072f64._28_4_;
      tmp42[32] = (char)ram0x00072f84;
      _applog(7,tmp42,false);
    }
    _Var3 = true;
  }
  return _Var3;
}

