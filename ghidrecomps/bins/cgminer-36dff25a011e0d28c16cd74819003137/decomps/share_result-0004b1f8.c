
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void share_result(json_t *val,json_t *res,json_t *err,work *work,char *hashshow,_Bool resubmit,
                 char *worktime)

{
  time_t tVar1;
  json_t *json;
  char *pcVar2;
  pool *ppVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  work *work_local;
  json_t *err_local;
  json_t *res_local;
  json_t *val_local;
  char reason [32];
  char disposition [36];
  char tmp42 [2048];
  char where [20];
  double utility;
  char *reasontmp;
  char *s;
  char *reason_str;
  json_t *reason_val;
  cgpu_info *cgpu;
  pool *pool;
  size_t reasonLen;
  
  pool = work->pool;
  cgpu = get_thr_cgpu(work->thr_id);
  if (((res == (json_t *)0x0) || (res->type != JSON_TRUE)) &&
     ((work->gbt == false || ((res == (json_t *)0x0 || (res->type != JSON_NULL)))))) {
    _mutex_lock(&stats_lock,"cgminer.c","share_result",0xdea);
    cgpu->rejected = cgpu->rejected + 1;
    bVar7 = 0xfffffffe < (uint)total_rejected;
    total_rejected._0_4_ = (uint)total_rejected + 1;
    total_rejected._4_4_ = total_rejected._4_4_ + (uint)bVar7;
    uVar4 = *(uint *)&pool->rejected;
    iVar5 = *(int *)((int)&pool->rejected + 4);
    *(uint *)&pool->rejected = uVar4 + 1;
    *(uint *)((int)&pool->rejected + 4) = iVar5 + (uint)(0xfffffffe < uVar4);
    cgpu->diff_rejected = cgpu->diff_rejected + work->work_difficulty;
    total_diff_rejected = work->work_difficulty + total_diff_rejected;
    pool->diff_rejected = pool->diff_rejected + work->work_difficulty;
    pool->seq_rejects = pool->seq_rejects + 1;
    _mutex_unlock(&stats_lock,"cgminer.c","share_result",0xdf2);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[0];
      tmp42[1] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[1];
      tmp42[2] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[2];
      tmp42[3] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[3];
      tmp42[4] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[4];
      tmp42[5] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[5];
      tmp42[6] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[6];
      tmp42[7] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[7];
      tmp42[8] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[8];
      tmp42[9] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[9];
      tmp42[10] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[10];
      tmp42[11] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[11];
      tmp42[12] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[12];
      tmp42[13] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[13];
      tmp42[14] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[14];
      tmp42[15] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[15];
      tmp42[16] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[16];
      tmp42[17] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[17];
      tmp42[18] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[18];
      tmp42[19] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[19];
      tmp42[20] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[20];
      tmp42[21] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[21];
      tmp42[22] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[22];
      tmp42[23] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[23];
      tmp42[24] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[24];
      tmp42[25] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[25];
      tmp42[26] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[26];
      tmp42[27] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[27];
      tmp42[28] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[28];
      tmp42[29] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[29];
      tmp42[30] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[30];
      tmp42[31] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[31];
      tmp42[32] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[32];
      tmp42[33] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[33];
      tmp42[34] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[34];
      tmp42[35] = s_PROOF_OF_WORK_RESULT__false__boo_000a3700[35];
      tmp42[36] = (char)ram0x000a3724;
      _applog(7,tmp42,false);
    }
    if ((opt_quiet != true) && (opt_realquiet != true)) {
      disposition[0] = s_reject_000a37a8[0];
      disposition[1] = s_reject_000a37a8[1];
      disposition[2] = s_reject_000a37a8[2];
      disposition[3] = s_reject_000a37a8[3];
      disposition._4_2_ = (undefined2)ram0x000a37ac;
      disposition[6] = (char)((uint)ram0x000a37ac >> 0x10);
      memset(disposition + 7,0,0x1d);
      reason[0] = '\0';
      if (total_pools < 2) {
        where[0] = '\0';
      }
      else {
        snprintf(where,0x14,"pool %d",work->pool->pool_no);
      }
      res_local = res;
      if (work->gbt != true) {
        res_local = json_object_get(val,"reject-reason");
      }
      if (res_local == (json_t *)0x0) {
        if ((work->stratum != false) && (err != (json_t *)0x0)) {
          if ((err == (json_t *)0x0) || (err->type != JSON_ARRAY)) {
            if ((err != (json_t *)0x0) && (err->type == JSON_STRING)) {
              pcVar2 = json_string_value(err);
              snprintf(reason,0x1f," (%s)",pcVar2);
            }
          }
          else {
            json = json_array_get(err,1);
            if (((json != (json_t *)0x0) && (json != (json_t *)0x0)) && (json->type == JSON_STRING))
            {
              pcVar2 = json_string_value(json);
              snprintf(reason,0x1f," (%s)",pcVar2);
            }
          }
        }
      }
      else {
        reasontmp = json_string_value(res_local);
        reasonLen = strlen(reasontmp);
        if (0x1c < reasonLen) {
          reasonLen = 0x1c;
        }
        reason[0] = ' ';
        reason[1] = '(';
        _cg_memcpy(reason + 2,reasontmp,reasonLen,"cgminer.c","share_result",0xe1a);
        reason[reasonLen + 2] = ')';
        reason[reasonLen + 3] = '\0';
        _cg_memcpy(disposition + 7,reasontmp,reasonLen,"cgminer.c","share_result",0xe1f);
        disposition[6] = ':';
        disposition[reasonLen + 7] = '\0';
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        if (resubmit) {
          uVar4 = 0x363c;
        }
        else {
          uVar4 = 0x1bd4;
        }
        snprintf(tmp42,0x800,"Rejected %s %s %d %s%s %s%s version 0x%x",hashshow,cgpu->drv->name,
                 cgpu->device_id,where,reason,uVar4 | 0xa0000,worktime,work->version);
        _applog(5,tmp42,false);
      }
      sharelog(disposition,work);
    }
    if (((10 < pool->seq_rejects) && (work->stale != true)) &&
       ((opt_disable_pool != false && (1 < enabled_pools)))) {
      dVar8 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_);
      dVar9 = (double)(longlong)pool->seq_rejects;
      dVar8 = (dVar8 / total_secs) * DAT_0004bef8 * 3.0;
      if ((dVar9 != dVar8 && dVar9 < dVar8 == (NAN(dVar9) || NAN(dVar8))) && (1 < enabled_pools)) {
        if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Pool %d rejected %d sequential shares, disabling!",pool->pool_no,
                   pool->seq_rejects);
          _applog(4,tmp42,false);
        }
        reject_pool(pool);
        ppVar3 = current_pool();
        if (pool == ppVar3) {
          switch_pools((pool *)0x0);
        }
        pool->seq_rejects = 0;
      }
    }
  }
  else {
    _mutex_lock(&stats_lock,"cgminer.c","share_result",0xdab);
    cgpu->accepted = cgpu->accepted + 1;
    bVar7 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar7;
    uVar4 = *(uint *)&pool->accepted;
    iVar5 = *(int *)((int)&pool->accepted + 4);
    *(uint *)&pool->accepted = uVar4 + 1;
    *(uint *)((int)&pool->accepted + 4) = iVar5 + (uint)(0xfffffffe < uVar4);
    cgpu->diff_accepted = cgpu->diff_accepted + work->work_difficulty;
    total_diff_accepted = work->work_difficulty + total_diff_accepted;
    pool->diff_accepted = pool->diff_accepted + work->work_difficulty;
    _mutex_unlock(&stats_lock,"cgminer.c","share_result",0xdb5);
    pool->seq_rejects = 0;
    cgpu->last_share_pool = pool->pool_no;
    tVar1 = time((time_t *)0x0);
    cgpu->last_share_pool_time = tVar1;
    uVar6 = *(undefined4 *)((int)&work->work_difficulty + 4);
    *(undefined4 *)&cgpu->last_share_diff = *(undefined4 *)&work->work_difficulty;
    *(undefined4 *)((int)&cgpu->last_share_diff + 4) = uVar6;
    pool->last_share_time = cgpu->last_share_pool_time;
    uVar6 = *(undefined4 *)((int)&work->work_difficulty + 4);
    *(undefined4 *)&pool->last_share_diff = *(undefined4 *)&work->work_difficulty;
    *(undefined4 *)((int)&pool->last_share_diff + 4) = uVar6;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      tmp42[0] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[0];
      tmp42[1] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[1];
      tmp42[2] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[2];
      tmp42[3] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[3];
      tmp42[4] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[4];
      tmp42[5] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[5];
      tmp42[6] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[6];
      tmp42[7] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[7];
      tmp42[8] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[8];
      tmp42[9] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[9];
      tmp42[10] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[10];
      tmp42[11] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[11];
      tmp42[12] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[12];
      tmp42[13] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[13];
      tmp42[14] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[14];
      tmp42[15] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[15];
      tmp42[16] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[16];
      tmp42[17] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[17];
      tmp42[18] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[18];
      tmp42[19] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[19];
      tmp42[20] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[20];
      tmp42[21] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[21];
      tmp42[22] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[22];
      tmp42[23] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[23];
      tmp42[24] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[24];
      tmp42[25] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[25];
      tmp42[26] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[26];
      tmp42[27] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[27];
      tmp42[28] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[28];
      tmp42[29] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[29];
      tmp42[30] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[30];
      tmp42[31] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[31];
      tmp42[32] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[32];
      tmp42[33] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[33];
      tmp42[34] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[34];
      tmp42[35] = s_PROOF_OF_WORK_RESULT__true__yay__000a3618[35];
      _applog(7,tmp42,false);
    }
    if ((opt_quiet != true) && (opt_realquiet != true)) {
      if (total_pools < 2) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          if (resubmit) {
            uVar4 = 0x363c;
          }
          else {
            uVar4 = 0x1bd4;
          }
          snprintf(tmp42,0x800,"Accepted %s %s %d %s%s",hashshow,cgpu->drv->name,cgpu->device_id,
                   uVar4 | 0xa0000,worktime);
          _applog(5,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        if (resubmit) {
          uVar4 = 0x363c;
        }
        else {
          uVar4 = 0x1bd4;
        }
        snprintf(tmp42,0x800,"Accepted %s %s %d pool %d %s%s",hashshow,cgpu->drv->name,
                 cgpu->device_id,work->pool->pool_no,uVar4 | 0xa0000,worktime);
        _applog(5,tmp42,false);
      }
    }
    sharelog("accept",work);
    if ((opt_shares == 0) || (total_diff_accepted < (double)(longlong)opt_shares)) {
      if (pool->enabled == POOL_REJECTING) {
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(tmp42,0x800,"Rejecting pool %d now accepting shares, re-enabling!",pool->pool_no)
          ;
          _applog(4,tmp42,false);
        }
        enable_pool(pool);
        switch_pools((pool *)0x0);
      }
      if (work->block != false) {
        restart_threads();
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Successfully mined %d accepted shares as requested and exiting.",
                 opt_shares);
        _applog(4,tmp42,false);
      }
      kill_work();
    }
  }
  return;
}

