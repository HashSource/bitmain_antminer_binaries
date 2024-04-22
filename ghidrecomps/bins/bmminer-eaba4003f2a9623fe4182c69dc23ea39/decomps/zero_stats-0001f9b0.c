
/* WARNING: Unknown calling convention */

void zero_stats(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  cgpu_info *pcVar4;
  pool *ppVar5;
  char tmp42 [2048];
  sysinfo sInfo;
  cgpu_info *cgpu;
  pool *pool;
  int i;
  
  iVar1 = sysinfo((sysinfo *)&sInfo);
  if (iVar1 == 0) {
    total_tv_start_sys = sInfo.uptime;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (5 < opt_log_level)) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
      _applog(6,tmp42,false);
    }
    total_tv_start_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_start);
  copy_time(&tv_hashmeter,&total_tv_start);
  total_rolling._0_4_ = 0;
  total_rolling._4_4_ = 0;
  rolling1._0_4_ = 0;
  rolling1._4_4_ = 0;
  rolling5._0_4_ = 0;
  rolling5._4_4_ = 0;
  rolling15._0_4_ = 0;
  rolling15._4_4_ = 0;
  total_mhashes_done._0_4_ = 0;
  total_mhashes_done._4_4_ = 0;
  new_total_mhashes_done._0_4_ = 0;
  new_total_mhashes_done._4_4_ = 0;
  for (i = 0; i < 0xc; i = i + 1) {
    *(undefined4 *)(g_local_mhashes_dones + i) = 0;
    *(undefined4 *)((int)g_local_mhashes_dones + i * 8 + 4) = 0;
  }
  g_local_mhashes_index = 0;
  g_max_fan = 0;
  g_max_temp = 0;
  total_getworks._0_4_ = 0;
  total_getworks._4_4_ = 0;
  total_accepted._0_4_ = 0;
  total_accepted._4_4_ = 0;
  total_rejected._0_4_ = 0;
  total_rejected._4_4_ = 0;
  hw_errors = 0;
  total_stale._0_4_ = 0;
  total_stale._4_4_ = 0;
  total_discarded._0_4_ = 0;
  total_discarded._4_4_ = 0;
  local_work = 0;
  total_go = 0;
  total_ro = 0;
  total_secs._0_4_ = 0;
  total_secs._4_4_ = 0x3ff00000;
  new_total_secs._0_4_ = 0;
  new_total_secs._4_4_ = 0x3ff00000;
  last_total_secs._0_4_ = 0;
  last_total_secs._4_4_ = 0x3ff00000;
  total_diff1._0_4_ = 0;
  total_diff1._4_4_ = 0;
  found_blocks = 0;
  total_diff_accepted._0_4_ = 0;
  total_diff_accepted._4_4_ = 0;
  total_diff_rejected._0_4_ = 0;
  total_diff_rejected._4_4_ = 0;
  total_diff_stale._0_4_ = 0;
  total_diff_stale._4_4_ = 0;
  for (i = 0; i < total_pools; i = i + 1) {
    ppVar5 = pools[i];
    ppVar5->getwork_requested = 0;
    *(undefined4 *)&ppVar5->accepted = 0;
    *(undefined4 *)((int)&ppVar5->accepted + 4) = 0;
    *(undefined4 *)&ppVar5->rejected = 0;
    *(undefined4 *)((int)&ppVar5->rejected + 4) = 0;
    ppVar5->stale_shares = 0;
    ppVar5->discarded_work = 0;
    ppVar5->getfail_occasions = 0;
    ppVar5->remotefail_occasions = 0;
    ppVar5->last_share_time = 0;
    *(undefined4 *)&ppVar5->diff1 = 0;
    *(undefined4 *)((int)&ppVar5->diff1 + 4) = 0;
    *(undefined4 *)&ppVar5->diff_accepted = 0;
    *(undefined4 *)((int)&ppVar5->diff_accepted + 4) = 0;
    *(undefined4 *)&ppVar5->diff_rejected = 0;
    *(undefined4 *)((int)&ppVar5->diff_rejected + 4) = 0;
    *(undefined4 *)&ppVar5->diff_stale = 0;
    *(undefined4 *)((int)&ppVar5->diff_stale + 4) = 0;
    *(undefined4 *)&ppVar5->last_share_diff = 0;
    *(undefined4 *)((int)&ppVar5->last_share_diff + 4) = 0;
  }
  zero_bestshare();
  for (i = 0; i < total_devices; i = i + 1) {
    pcVar4 = get_devices(i);
    copy_time(&pcVar4->dev_start_tv,&total_tv_start);
    _mutex_lock(&hash_lock,"cgminer.c","zero_stats",0x17bd);
    *(undefined4 *)&pcVar4->total_mhashes = 0;
    *(undefined4 *)((int)&pcVar4->total_mhashes + 4) = 0;
    pcVar4->accepted = 0;
    pcVar4->rejected = 0;
    pcVar4->hw_errors = 0;
    *(undefined4 *)&pcVar4->utility = 0;
    *(undefined4 *)((int)&pcVar4->utility + 4) = 0;
    pcVar4->last_share_pool_time = 0;
    *(undefined4 *)&pcVar4->diff1 = 0;
    *(undefined4 *)((int)&pcVar4->diff1 + 4) = 0;
    *(undefined4 *)&pcVar4->diff_accepted = 0;
    *(undefined4 *)((int)&pcVar4->diff_accepted + 4) = 0;
    *(undefined4 *)&pcVar4->diff_rejected = 0;
    *(undefined4 *)((int)&pcVar4->diff_rejected + 4) = 0;
    *(undefined4 *)&pcVar4->last_share_diff = 0;
    *(undefined4 *)((int)&pcVar4->last_share_diff + 4) = 0;
    _mutex_unlock(&hash_lock,"cgminer.c","zero_stats",0x17ca);
    (*pcVar4->drv->zero_stats)(pcVar4);
  }
  return;
}

