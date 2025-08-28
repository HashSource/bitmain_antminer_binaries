
void zero_stats(void)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  sysinfo local_868;
  char acStack_828 [2048];
  undefined4 *puVar7;
  
  iVar1 = sysinfo(&local_868);
  if (iVar1 == 0) {
    total_tv_start_sys = local_868.uptime;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      pcVar3 = strerror(iVar1);
      snprintf(acStack_828,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar1,pcVar3);
      _applog(6,acStack_828,0);
    }
    total_tv_start_sys = time((time_t *)0x0);
  }
  cgtime(&total_tv_start);
  copy_time(&tv_hashmeter);
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
  puVar6 = (undefined4 *)g_local_mhashes_dones;
  do {
    puVar7 = puVar6 + 2;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6 = puVar7;
  } while (puVar7 != &g_local_mhashes_index);
  last_total_secs._0_4_ = 0;
  last_total_secs._4_4_ = 0x3ff00000;
  total_secs._0_4_ = 0;
  total_secs._4_4_ = 0x3ff00000;
  new_total_secs._0_4_ = 0;
  new_total_secs._4_4_ = 0x3ff00000;
  hw_errors = 0;
  g_local_mhashes_index = 0;
  local_work = 0;
  found_blocks = 0;
  total_getworks._0_4_ = 0;
  total_getworks._4_4_ = 0;
  total_accepted._0_4_ = 0;
  total_accepted._4_4_ = 0;
  total_rejected._0_4_ = 0;
  total_rejected._4_4_ = 0;
  g_max_fan = 0;
  g_max_temp = 0;
  total_stale._0_4_ = 0;
  total_stale._4_4_ = 0;
  total_discarded._0_4_ = 0;
  total_discarded._4_4_ = 0;
  total_diff1._0_4_ = 0;
  total_diff1._4_4_ = 0;
  total_go = 0;
  total_ro = 0;
  total_diff_accepted._0_4_ = 0;
  total_diff_accepted._4_4_ = 0;
  total_diff_rejected._0_4_ = 0;
  total_diff_rejected._4_4_ = 0;
  total_diff_stale._0_4_ = 0;
  total_diff_stale._4_4_ = 0;
  if (0 < total_pools) {
    piVar9 = pools + total_pools;
    piVar2 = pools;
    do {
      piVar8 = piVar2 + 1;
      iVar1 = *piVar2;
      *(undefined4 *)(iVar1 + 0x74) = 0;
      *(undefined4 *)(iVar1 + 8) = 0;
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      *(undefined4 *)(iVar1 + 0x78) = 0;
      *(undefined4 *)(iVar1 + 0x7c) = 0;
      *(undefined4 *)(iVar1 + 0x80) = 0;
      *(undefined4 *)(iVar1 + 0x84) = 0;
      *(undefined4 *)(iVar1 + 0x160) = 0;
      *(undefined4 *)(iVar1 + 0x28) = 0;
      *(undefined4 *)(iVar1 + 0x2c) = 0;
      *(undefined4 *)(iVar1 + 0x48) = 0;
      *(undefined4 *)(iVar1 + 0x4c) = 0;
      *(undefined4 *)(iVar1 + 0x50) = 0;
      *(undefined4 *)(iVar1 + 0x54) = 0;
      *(undefined4 *)(iVar1 + 0x58) = 0;
      *(undefined4 *)(iVar1 + 0x5c) = 0;
      *(undefined4 *)(iVar1 + 0x168) = 0;
      *(undefined4 *)(iVar1 + 0x16c) = 0;
      piVar2 = piVar8;
    } while (piVar8 != piVar9);
  }
  zero_bestshare();
  if (0 < total_devices) {
    iVar1 = 0;
    do {
      iVar4 = get_devices(iVar1);
      copy_time(iVar4 + 0x170,&total_tv_start);
      iVar5 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
      if (iVar5 != 0) {
        piVar2 = __errno_location();
        iVar1 = *piVar2;
        pcVar3 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
        uVar10 = 0x17cd;
LAB_000213f6:
        snprintf(acStack_828,0x800,pcVar3,iVar1,"cgminer.c","zero_stats",uVar10);
        _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
        __quit(1);
      }
      *(undefined4 *)(iVar4 + 0x24) = 0;
      *(undefined8 *)(iVar4 + 0x50) = 0;
      *(undefined4 *)(iVar4 + 0x28) = 0;
      *(undefined4 *)(iVar4 + 0x2c) = 0;
      *(undefined8 *)(iVar4 + 0x58) = 0;
      *(undefined4 *)(iVar4 + 0xdc) = 0;
      *(undefined8 *)(iVar4 + 200) = 0;
      *(undefined8 *)(iVar4 + 0xd0) = 0;
      *(undefined8 *)(iVar4 + 0xe0) = 0;
      *(undefined4 *)(iVar4 + 0xc0) = 0;
      *(undefined4 *)(iVar4 + 0xc4) = 0;
      iVar5 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
      if (iVar5 != 0) {
        piVar2 = __errno_location();
        iVar1 = *piVar2;
        pcVar3 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar10 = 0x17da;
        goto LAB_000213f6;
      }
      iVar1 = iVar1 + 1;
      (*selective_yield)();
      (**(code **)(*(int *)(iVar4 + 4) + 0x60))(iVar4);
    } while (iVar1 < total_devices);
  }
  return;
}

