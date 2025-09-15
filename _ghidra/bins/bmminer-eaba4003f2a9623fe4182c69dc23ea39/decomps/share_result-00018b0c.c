
void share_result(json_t *val,json_t *res,json_t *err,work *work,char *hashshow,_Bool resubmit,
                 char *worktime)

{
  cgpu_info *pcVar1;
  time_t tVar2;
  json_t *json;
  pool *ppVar3;
  uint uVar4;
  pool *pool_00;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  bool bVar8;
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
  char *s;
  char *reason_str;
  json_t *reason_val;
  char *reasontmp;
  cgpu_info *cgpu;
  pool *pool;
  size_t reasonLen;
  
  pool_00 = work->pool;
  pcVar1 = get_thr_cgpu(work->thr_id);
  if (((res == (json_t *)0x0) || (res->type != JSON_TRUE)) &&
     ((work->gbt == false || ((res == (json_t *)0x0 || (res->type != JSON_NULL)))))) {
    _mutex_lock(&stats_lock,"cgminer.c","share_result",0xdba);
    pcVar1->rejected = pcVar1->rejected + 1;
    bVar8 = 0xfffffffe < (uint)total_rejected;
    total_rejected._0_4_ = (uint)total_rejected + 1;
    total_rejected._4_4_ = total_rejected._4_4_ + (uint)bVar8;
    uVar4 = (uint)pool_00->rejected;
    iVar5 = *(int *)((int)&pool_00->rejected + 4);
    *(uint *)&pool_00->rejected = uVar4 + 1;
    *(uint *)((int)&pool_00->rejected + 4) = iVar5 + (uint)(0xfffffffe < uVar4);
    pcVar1->diff_rejected = pcVar1->diff_rejected + work->work_difficulty;
    total_diff_rejected = work->work_difficulty + total_diff_rejected;
    pool_00->diff_rejected = pool_00->diff_rejected + work->work_difficulty;
    pool_00->seq_rejects = pool_00->seq_rejects + 1;
    _mutex_unlock(&stats_lock,"cgminer.c","share_result",0xdc2);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"PROOF OF WORK RESULT: false (booooo)",0x24);
      tmp42[0x24] = '\0';
      _applog(7,tmp42,false);
    }
    if ((opt_quiet != true) && (opt_realquiet != true)) {
      builtin_strncpy(disposition,"reje",4);
      disposition[4] = 'c';
      disposition[5] = 't';
      disposition[6] = '\0';
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
              pcVar7 = json_string_value(err);
              snprintf(reason,0x1f," (%s)",pcVar7);
            }
          }
          else {
            json = json_array_get(err,1);
            if (((json != (json_t *)0x0) && (json != (json_t *)0x0)) && (json->type == JSON_STRING))
            {
              pcVar7 = json_string_value(json);
              snprintf(reason,0x1f," (%s)",pcVar7);
            }
          }
        }
      }
      else {
        pcVar7 = json_string_value(res_local);
        reasonLen = strlen(pcVar7);
        if (0x1c < reasonLen) {
          reasonLen = 0x1c;
        }
        reason[0] = ' ';
        reason[1] = '(';
        _cg_memcpy(reason + 2,pcVar7,reasonLen,"cgminer.c","share_result",0xdea);
        reason[reasonLen + 2] = ')';
        reason[reasonLen + 3] = '\0';
        _cg_memcpy(disposition + 7,pcVar7,reasonLen,"cgminer.c","share_result",0xdef);
        disposition[6] = ':';
        disposition[reasonLen + 7] = '\0';
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        if (resubmit) {
          pcVar7 = "(resubmit)";
        }
        else {
          pcVar7 = "";
        }
        snprintf(tmp42,0x800,"Rejected %s %s %d %s%s %s%s",hashshow,pcVar1->drv->name,
                 pcVar1->device_id,where,reason,pcVar7,worktime);
        _applog(5,tmp42,false);
      }
      sharelog(disposition,work);
    }
    if (((10 < pool_00->seq_rejects) && (work->stale != true)) &&
       ((opt_disable_pool != false &&
        (((1 < enabled_pools &&
          (dVar9 = (double)__aeabi_l2d((uint)total_accepted,total_accepted._4_4_),
          (dVar9 / total_secs) * 60.0 * 3.0 < (double)(longlong)pool_00->seq_rejects)) &&
         (1 < enabled_pools)))))) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d rejected %d sequential shares, disabling!",pool_00->pool_no,
                 pool_00->seq_rejects);
        _applog(4,tmp42,false);
      }
      reject_pool(pool_00);
      ppVar3 = current_pool();
      if (ppVar3 == pool_00) {
        switch_pools((pool *)0x0);
      }
      pool_00->seq_rejects = 0;
    }
  }
  else {
    _mutex_lock(&stats_lock,"cgminer.c","share_result",0xd7b);
    pcVar1->accepted = pcVar1->accepted + 1;
    bVar8 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar8;
    uVar4 = (uint)pool_00->accepted;
    iVar5 = *(int *)((int)&pool_00->accepted + 4);
    *(uint *)&pool_00->accepted = uVar4 + 1;
    *(uint *)((int)&pool_00->accepted + 4) = iVar5 + (uint)(0xfffffffe < uVar4);
    pcVar1->diff_accepted = pcVar1->diff_accepted + work->work_difficulty;
    total_diff_accepted = work->work_difficulty + total_diff_accepted;
    pool_00->diff_accepted = pool_00->diff_accepted + work->work_difficulty;
    _mutex_unlock(&stats_lock,"cgminer.c","share_result",0xd85);
    pool_00->seq_rejects = 0;
    pcVar1->last_share_pool = pool_00->pool_no;
    tVar2 = time((time_t *)0x0);
    pcVar1->last_share_pool_time = tVar2;
    uVar6 = *(undefined4 *)((int)&work->work_difficulty + 4);
    *(undefined4 *)&pcVar1->last_share_diff = *(undefined4 *)&work->work_difficulty;
    *(undefined4 *)((int)&pcVar1->last_share_diff + 4) = uVar6;
    pool_00->last_share_time = pcVar1->last_share_pool_time;
    uVar6 = *(undefined4 *)((int)&work->work_difficulty + 4);
    *(undefined4 *)&pool_00->last_share_diff = *(undefined4 *)&work->work_difficulty;
    *(undefined4 *)((int)&pool_00->last_share_diff + 4) = uVar6;
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      builtin_strncpy(tmp42,"PROOF OF WORK RESULT: true (yay!!!)",0x24);
      _applog(7,tmp42,false);
    }
    if ((opt_quiet != true) && (opt_realquiet != true)) {
      if (total_pools < 2) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          if (resubmit) {
            pcVar7 = "(resubmit)";
          }
          else {
            pcVar7 = "";
          }
          snprintf(tmp42,0x800,"Accepted %s %s %d %s%s",hashshow,pcVar1->drv->name,pcVar1->device_id
                   ,pcVar7,worktime);
          _applog(5,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        if (resubmit) {
          pcVar7 = "(resubmit)";
        }
        else {
          pcVar7 = "";
        }
        snprintf(tmp42,0x800,"Accepted %s %s %d pool %d %s%s",hashshow,pcVar1->drv->name,
                 pcVar1->device_id,work->pool->pool_no,pcVar7,worktime);
        _applog(5,tmp42,false);
      }
    }
    sharelog("accept",work);
    if ((opt_shares != 0) && ((double)(longlong)opt_shares <= total_diff_accepted)) {
      if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Successfully mined %d accepted shares as requested and exiting.",
                 opt_shares);
        _applog(4,tmp42,false);
      }
      kill_work();
      return;
    }
    if (pool_00->enabled == POOL_REJECTING) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Rejecting pool %d now accepting shares, re-enabling!",pool_00->pool_no
                );
        _applog(4,tmp42,false);
      }
      enable_pool(pool_00);
      switch_pools((pool *)0x0);
    }
    if (work->block != false) {
      restart_threads();
    }
  }
  return;
}

