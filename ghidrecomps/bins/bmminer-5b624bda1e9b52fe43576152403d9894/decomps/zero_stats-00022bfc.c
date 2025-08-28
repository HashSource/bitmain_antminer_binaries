
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zero_stats(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  cgpu_info *pcVar4;
  pool **pppVar5;
  char *func;
  char *func_00;
  double *pdVar7;
  pool *ppVar8;
  int line;
  int line_00;
  pool **pppVar9;
  int iVar10;
  sysinfo sInfo;
  char tmp42 [2048];
  pool **pppVar6;
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  if (iVar1 == 0) {
    total_tv_start_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      pcVar3 = strerror(iVar1);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
      _applog(6,tmp42,false);
    }
    total_tv_start_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_start);
  copy_time(&tv_hashmeter,&total_tv_start);
  pdVar7 = g_local_mhashes_dones;
  rolling5 = 0.0;
  total_rolling = 0.0;
  rolling1 = 0.0;
  rolling15 = 0.0;
  total_mhashes_done = 0.0;
  new_total_mhashes_done = 0.0;
  do {
    *pdVar7 = 0.0;
    pdVar7 = pdVar7 + 1;
  } while (pdVar7 != (double *)&g_local_mhashes_index);
  total_secs._0_4_ = 0;
  total_secs._4_4_ = 0x3ff00000;
  new_total_secs = 1.0;
  last_total_secs = 1.0;
  g_max_fan = 0;
  total_diff_accepted = 0.0;
  total_diff_rejected = 0.0;
  total_diff_stale = 0.0;
  g_max_temp = 0;
  g_local_mhashes_index = 0;
  hw_errors = 0;
  local_work = 0;
  total_go = 0;
  total_ro = 0;
  found_blocks = 0;
  total_getworks._0_4_ = 0;
  total_getworks._4_4_ = 0;
  total_accepted._0_4_ = 0;
  total_accepted._4_4_ = 0;
  total_rejected._0_4_ = 0;
  total_rejected._4_4_ = 0;
  total_stale._0_4_ = 0;
  total_stale._4_4_ = 0;
  total_discarded._0_4_ = 0;
  total_discarded._4_4_ = 0;
  total_diff1._0_4_ = 0;
  total_diff1._4_4_ = 0;
  if (0 < total_pools) {
    pppVar9 = pools + total_pools;
    pppVar5 = pools;
    do {
      pppVar6 = pppVar5 + 1;
      ppVar8 = *pppVar5;
      ppVar8->getwork_requested = 0;
      *(undefined4 *)&ppVar8->accepted = 0;
      *(undefined4 *)((int)&ppVar8->accepted + 4) = 0;
      *(undefined4 *)&ppVar8->rejected = 0;
      *(undefined4 *)((int)&ppVar8->rejected + 4) = 0;
      ppVar8->stale_shares = 0;
      ppVar8->discarded_work = 0;
      ppVar8->getfail_occasions = 0;
      ppVar8->remotefail_occasions = 0;
      ppVar8->last_share_time = 0;
      *(undefined4 *)&ppVar8->diff1 = 0;
      *(undefined4 *)((int)&ppVar8->diff1 + 4) = 0;
      ppVar8->diff_accepted = 0.0;
      ppVar8->diff_rejected = 0.0;
      ppVar8->diff_stale = 0.0;
      ppVar8->last_share_diff = 0.0;
      pppVar5 = pppVar6;
    } while (pppVar6 != pppVar9);
  }
  zero_bestshare();
  if (0 < total_devices) {
    iVar1 = 0;
    do {
      iVar10 = iVar1 + 1;
      pcVar4 = get_devices(iVar1);
      copy_time(&pcVar4->dev_start_tv,&total_tv_start);
      iVar1 = pthread_mutex_lock((pthread_mutex_t *)&hash_lock);
      if (iVar1 != 0) {
        _mutex_lock((pthread_mutex_t *)"zero_stats",(char *)0x17b6,func,line);
      }
      pcVar4->accepted = 0;
      pcVar4->rejected = 0;
      pcVar4->total_mhashes = 0.0;
      pcVar4->hw_errors = 0;
      pcVar4->utility = 0.0;
      pcVar4->last_share_pool_time = 0;
      *(undefined4 *)&pcVar4->diff1 = 0;
      *(undefined4 *)((int)&pcVar4->diff1 + 4) = 0;
      pcVar4->diff_accepted = 0.0;
      pcVar4->diff_rejected = 0.0;
      pcVar4->last_share_diff = 0.0;
      iVar1 = pthread_mutex_unlock((pthread_mutex_t *)&hash_lock);
      if (iVar1 != 0) {
        _mutex_unlock_noyield((pthread_mutex_t *)"zero_stats",(char *)0x17c3,func_00,line_00);
      }
      (*selective_yield)();
      (*pcVar4->drv->zero_stats)(pcVar4);
      iVar1 = iVar10;
    } while (iVar10 < total_devices);
  }
  return;
}

