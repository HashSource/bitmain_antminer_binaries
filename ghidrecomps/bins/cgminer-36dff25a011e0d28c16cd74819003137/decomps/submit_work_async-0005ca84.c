
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void submit_work_async(work *work)

{
  _Bool _Var1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  work *work_local;
  char tmp42 [2048];
  pthread_t submit_thread;
  cgpu_info *cgpu;
  pool *pool;
  
  pool = work->pool;
  work_local = work;
  cgtime(&work->tv_work_found);
  if (opt_benchmark == false) {
    _Var1 = stale_work(work_local,true);
    if (_Var1) {
      if (opt_submit_stale == false) {
        if (pool->submit_old == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
            snprintf(tmp42,0x800,"Pool %d stale share detected, discarding",pool->pool_no);
            _applog(5,tmp42,false);
          }
          sharelog("discard",work_local);
          _mutex_lock(&stats_lock,"cgminer.c","submit_work_async",0x21e7);
          bVar4 = 0xfffffffe < (uint)total_stale;
          total_stale._0_4_ = (uint)total_stale + 1;
          total_stale._4_4_ = total_stale._4_4_ + (uint)bVar4;
          pool->stale_shares = pool->stale_shares + 1;
          total_diff_stale = work_local->work_difficulty + total_diff_stale;
          pool->diff_stale = pool->diff_stale + work_local->work_difficulty;
          _mutex_unlock(&stats_lock,"cgminer.c","submit_work_async",0x21ee);
          _free_work(&work_local,"cgminer.c","submit_work_async",0x21f0);
          return;
        }
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Pool %d stale share detected, submitting as pool requested",
                   pool->pool_no);
          _applog(5,tmp42,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"Pool %d stale share detected, submitting as user requested",
                 pool->pool_no);
        _applog(5,tmp42,false);
      }
      work_local->stale = true;
    }
    if (work_local->stratum == false) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_Pushing_submit_work_to_work_thre_000a4d3c[0];
        tmp42[1] = s_Pushing_submit_work_to_work_thre_000a4d3c[1];
        tmp42[2] = s_Pushing_submit_work_to_work_thre_000a4d3c[2];
        tmp42[3] = s_Pushing_submit_work_to_work_thre_000a4d3c[3];
        tmp42[4] = s_Pushing_submit_work_to_work_thre_000a4d3c[4];
        tmp42[5] = s_Pushing_submit_work_to_work_thre_000a4d3c[5];
        tmp42[6] = s_Pushing_submit_work_to_work_thre_000a4d3c[6];
        tmp42[7] = s_Pushing_submit_work_to_work_thre_000a4d3c[7];
        tmp42[8] = s_Pushing_submit_work_to_work_thre_000a4d3c[8];
        tmp42[9] = s_Pushing_submit_work_to_work_thre_000a4d3c[9];
        tmp42[10] = s_Pushing_submit_work_to_work_thre_000a4d3c[10];
        tmp42[11] = s_Pushing_submit_work_to_work_thre_000a4d3c[11];
        tmp42[12] = s_Pushing_submit_work_to_work_thre_000a4d3c[12];
        tmp42[13] = s_Pushing_submit_work_to_work_thre_000a4d3c[13];
        tmp42[14] = s_Pushing_submit_work_to_work_thre_000a4d3c[14];
        tmp42[15] = s_Pushing_submit_work_to_work_thre_000a4d3c[15];
        tmp42[16] = s_Pushing_submit_work_to_work_thre_000a4d3c[16];
        tmp42[17] = s_Pushing_submit_work_to_work_thre_000a4d3c[17];
        tmp42[18] = s_Pushing_submit_work_to_work_thre_000a4d3c[18];
        tmp42[19] = s_Pushing_submit_work_to_work_thre_000a4d3c[19];
        tmp42[20] = s_Pushing_submit_work_to_work_thre_000a4d3c[20];
        tmp42[21] = s_Pushing_submit_work_to_work_thre_000a4d3c[21];
        tmp42[22] = s_Pushing_submit_work_to_work_thre_000a4d3c[22];
        tmp42[23] = s_Pushing_submit_work_to_work_thre_000a4d3c[23];
        tmp42[24] = s_Pushing_submit_work_to_work_thre_000a4d3c[24];
        tmp42[25] = s_Pushing_submit_work_to_work_thre_000a4d3c[25];
        tmp42[26] = s_Pushing_submit_work_to_work_thre_000a4d3c[26];
        tmp42[27] = s_Pushing_submit_work_to_work_thre_000a4d3c[27];
        tmp42[28] = s_Pushing_submit_work_to_work_thre_000a4d3c[28];
        tmp42[29] = s_Pushing_submit_work_to_work_thre_000a4d3c[29];
        tmp42[30] = s_Pushing_submit_work_to_work_thre_000a4d3c[30];
        tmp42[31] = s_Pushing_submit_work_to_work_thre_000a4d3c[31];
        tmp42._32_3_ = (undefined3)ram0x000a4d5c;
        _applog(5,tmp42,false);
      }
      iVar3 = pthread_create(&submit_thread,(pthread_attr_t *)0x0,submit_work_thread,work_local);
      if (iVar3 != 0) {
        tmp42[0] = s_Failed_to_create_submit_work_thr_000a4d60[0];
        tmp42[1] = s_Failed_to_create_submit_work_thr_000a4d60[1];
        tmp42[2] = s_Failed_to_create_submit_work_thr_000a4d60[2];
        tmp42[3] = s_Failed_to_create_submit_work_thr_000a4d60[3];
        tmp42[4] = s_Failed_to_create_submit_work_thr_000a4d60[4];
        tmp42[5] = s_Failed_to_create_submit_work_thr_000a4d60[5];
        tmp42[6] = s_Failed_to_create_submit_work_thr_000a4d60[6];
        tmp42[7] = s_Failed_to_create_submit_work_thr_000a4d60[7];
        tmp42[8] = s_Failed_to_create_submit_work_thr_000a4d60[8];
        tmp42[9] = s_Failed_to_create_submit_work_thr_000a4d60[9];
        tmp42[10] = s_Failed_to_create_submit_work_thr_000a4d60[10];
        tmp42[11] = s_Failed_to_create_submit_work_thr_000a4d60[11];
        tmp42[12] = s_Failed_to_create_submit_work_thr_000a4d60[12];
        tmp42[13] = s_Failed_to_create_submit_work_thr_000a4d60[13];
        tmp42[14] = s_Failed_to_create_submit_work_thr_000a4d60[14];
        tmp42[15] = s_Failed_to_create_submit_work_thr_000a4d60[15];
        tmp42[16] = s_Failed_to_create_submit_work_thr_000a4d60[16];
        tmp42[17] = s_Failed_to_create_submit_work_thr_000a4d60[17];
        tmp42[18] = s_Failed_to_create_submit_work_thr_000a4d60[18];
        tmp42[19] = s_Failed_to_create_submit_work_thr_000a4d60[19];
        tmp42[20] = s_Failed_to_create_submit_work_thr_000a4d60[20];
        tmp42[21] = s_Failed_to_create_submit_work_thr_000a4d60[21];
        tmp42[22] = s_Failed_to_create_submit_work_thr_000a4d60[22];
        tmp42[23] = s_Failed_to_create_submit_work_thr_000a4d60[23];
        tmp42[24] = s_Failed_to_create_submit_work_thr_000a4d60[24];
        tmp42[25] = s_Failed_to_create_submit_work_thr_000a4d60[25];
        tmp42[26] = s_Failed_to_create_submit_work_thr_000a4d60[26];
        tmp42[27] = s_Failed_to_create_submit_work_thr_000a4d60[27];
        tmp42[28] = s_Failed_to_create_submit_work_thr_000a4d60[28];
        tmp42[29] = s_Failed_to_create_submit_work_thr_000a4d60[29];
        tmp42[30] = s_Failed_to_create_submit_work_thr_000a4d60[30];
        tmp42[31] = s_Failed_to_create_submit_work_thr_000a4d60[31];
        tmp42[32] = s_Failed_to_create_submit_work_thr_000a4d60[32];
        tmp42[33] = s_Failed_to_create_submit_work_thr_000a4d60[33];
        tmp42[34] = s_Failed_to_create_submit_work_thr_000a4d60[34];
        tmp42[35] = s_Failed_to_create_submit_work_thr_000a4d60[35];
        _applog(3,tmp42,true);
        _quit(1);
      }
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Pushing pool %d work to stratum queue",pool->pool_no);
        _applog(7,tmp42,false);
      }
      if ((pool->stratum_q == (thread_q *)0x0) ||
         (_Var1 = tq_push(pool->stratum_q,work_local), !_Var1)) {
        if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
          tmp42[0] = s_Discarding_work_from_removed_poo_000a4d18[0];
          tmp42[1] = s_Discarding_work_from_removed_poo_000a4d18[1];
          tmp42[2] = s_Discarding_work_from_removed_poo_000a4d18[2];
          tmp42[3] = s_Discarding_work_from_removed_poo_000a4d18[3];
          tmp42[4] = s_Discarding_work_from_removed_poo_000a4d18[4];
          tmp42[5] = s_Discarding_work_from_removed_poo_000a4d18[5];
          tmp42[6] = s_Discarding_work_from_removed_poo_000a4d18[6];
          tmp42[7] = s_Discarding_work_from_removed_poo_000a4d18[7];
          tmp42[8] = s_Discarding_work_from_removed_poo_000a4d18[8];
          tmp42[9] = s_Discarding_work_from_removed_poo_000a4d18[9];
          tmp42[10] = s_Discarding_work_from_removed_poo_000a4d18[10];
          tmp42[11] = s_Discarding_work_from_removed_poo_000a4d18[11];
          tmp42[12] = s_Discarding_work_from_removed_poo_000a4d18[12];
          tmp42[13] = s_Discarding_work_from_removed_poo_000a4d18[13];
          tmp42[14] = s_Discarding_work_from_removed_poo_000a4d18[14];
          tmp42[15] = s_Discarding_work_from_removed_poo_000a4d18[15];
          tmp42[16] = s_Discarding_work_from_removed_poo_000a4d18[16];
          tmp42[17] = s_Discarding_work_from_removed_poo_000a4d18[17];
          tmp42[18] = s_Discarding_work_from_removed_poo_000a4d18[18];
          tmp42[19] = s_Discarding_work_from_removed_poo_000a4d18[19];
          tmp42[20] = s_Discarding_work_from_removed_poo_000a4d18[20];
          tmp42[21] = s_Discarding_work_from_removed_poo_000a4d18[21];
          tmp42[22] = s_Discarding_work_from_removed_poo_000a4d18[22];
          tmp42[23] = s_Discarding_work_from_removed_poo_000a4d18[23];
          tmp42[24] = s_Discarding_work_from_removed_poo_000a4d18[24];
          tmp42[25] = s_Discarding_work_from_removed_poo_000a4d18[25];
          tmp42[26] = s_Discarding_work_from_removed_poo_000a4d18[26];
          tmp42[27] = s_Discarding_work_from_removed_poo_000a4d18[27];
          tmp42[28] = s_Discarding_work_from_removed_poo_000a4d18[28];
          tmp42[29] = s_Discarding_work_from_removed_poo_000a4d18[29];
          tmp42[30] = s_Discarding_work_from_removed_poo_000a4d18[30];
          tmp42[31] = s_Discarding_work_from_removed_poo_000a4d18[31];
          tmp42[32] = (char)(short)ram0x000a4d38;
          tmp42[33] = (char)((ushort)(short)ram0x000a4d38 >> 8);
          _applog(4,tmp42,false);
        }
        if ((pool->stratum_q == (thread_q *)0x0) &&
           (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Pushing pool %d work to stratum queue",pool->pool_no);
          _applog(5,tmp42,false);
        }
        _free_work(&work_local,"cgminer.c","submit_work_async",0x21fe);
      }
    }
  }
  else {
    cgpu = get_thr_cgpu(work_local->thr_id);
    _mutex_lock(&stats_lock,"cgminer.c","submit_work_async",0x21cb);
    cgpu->accepted = cgpu->accepted + 1;
    bVar4 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar4;
    uVar2 = *(uint *)&pool->accepted;
    iVar3 = *(int *)((int)&pool->accepted + 4);
    *(uint *)&pool->accepted = uVar2 + 1;
    *(uint *)((int)&pool->accepted + 4) = iVar3 + (uint)(0xfffffffe < uVar2);
    cgpu->diff_accepted = cgpu->diff_accepted + work_local->work_difficulty;
    total_diff_accepted = work_local->work_difficulty + total_diff_accepted;
    pool->diff_accepted = pool->diff_accepted + work_local->work_difficulty;
    _mutex_unlock(&stats_lock,"cgminer.c","submit_work_async",0x21d2);
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"Accepted %s %d benchmark share nonce %08x",cgpu->drv->name,
               cgpu->device_id,*(undefined4 *)(work_local->data + 0x4c));
      _applog(5,tmp42,false);
    }
  }
  return;
}

