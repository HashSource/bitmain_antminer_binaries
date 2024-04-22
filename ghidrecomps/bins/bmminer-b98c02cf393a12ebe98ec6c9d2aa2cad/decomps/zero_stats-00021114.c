
void zero_stats(void)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar11;
  int *piVar12;
  int *piVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  sysinfo local_868;
  char acStack_828 [2048];
  undefined4 *puVar10;
  
  iVar3 = sysinfo(&local_868);
  if (iVar3 == 0) {
    total_tv_start_sys = local_868.uptime;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (5 < opt_log_level)) {
      piVar4 = __errno_location();
      iVar3 = *piVar4;
      pcVar5 = strerror(iVar3);
      snprintf(acStack_828,0x800,"Failed to get sysinfo, errno:%u, reason:%s\n",iVar3,pcVar5);
      _applog(6,acStack_828,0);
    }
    total_tv_start_sys = time((time_t *)0x0);
  }
  cgtime(DAT_00021450);
  copy_time(DAT_00021450 + 0x5c);
  total_rolling._0_4_ = 0;
  total_rolling._4_4_ = 0;
  rolling1._0_4_ = 0;
  rolling1._4_4_ = 0;
  puVar8 = DAT_00021454 + 0x18;
  rolling5._0_4_ = 0;
  rolling5._4_4_ = 0;
  rolling15._0_4_ = 0;
  rolling15._4_4_ = 0;
  total_mhashes_done._0_4_ = 0;
  total_mhashes_done._4_4_ = 0;
  new_total_mhashes_done._0_4_ = 0;
  new_total_mhashes_done._4_4_ = 0;
  puVar9 = DAT_00021454;
  do {
    puVar10 = puVar9 + 2;
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar2 = DAT_00021458;
    puVar9 = puVar10;
  } while (puVar10 != puVar8);
  DAT_00021458[8] = 0;
  puVar2[9] = 0x3ff00000;
  *puVar2 = 0;
  puVar2[1] = 0x3ff00000;
  puVar2[6] = 0;
  puVar2[7] = 0x3ff00000;
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
    piVar13 = pools + total_pools;
    piVar4 = pools;
    do {
      piVar12 = piVar4 + 1;
      iVar3 = *piVar4;
      *(undefined4 *)(iVar3 + 0x74) = 0;
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(undefined4 *)(iVar3 + 0x14) = 0;
      *(undefined4 *)(iVar3 + 0x78) = 0;
      *(undefined4 *)(iVar3 + 0x7c) = 0;
      *(undefined4 *)(iVar3 + 0x80) = 0;
      *(undefined4 *)(iVar3 + 0x84) = 0;
      *(undefined4 *)(iVar3 + 0x160) = 0;
      *(undefined4 *)(iVar3 + 0x28) = 0;
      *(undefined4 *)(iVar3 + 0x2c) = 0;
      *(undefined4 *)(iVar3 + 0x48) = 0;
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(undefined4 *)(iVar3 + 0x50) = 0;
      *(undefined4 *)(iVar3 + 0x54) = 0;
      *(undefined4 *)(iVar3 + 0x58) = 0;
      *(undefined4 *)(iVar3 + 0x5c) = 0;
      *(undefined4 *)(iVar3 + 0x168) = 0;
      *(undefined4 *)(iVar3 + 0x16c) = 0;
      piVar4 = piVar12;
    } while (piVar12 != piVar13);
  }
  zero_bestshare();
  iVar3 = DAT_00021450;
  uVar1 = DAT_00021448;
  if (0 < total_devices) {
    iVar11 = 0;
    do {
      iVar6 = get_devices(iVar11);
      copy_time(iVar6 + 0x170,iVar3);
      iVar7 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
      if (iVar7 != 0) {
        piVar4 = __errno_location();
        iVar3 = *piVar4;
        pcVar5 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
        uVar15 = 0x17cd;
        uVar14 = DAT_0002145c;
LAB_000213f6:
        snprintf(acStack_828,0x800,pcVar5,iVar3,"cgminer.c",uVar14,uVar15);
        _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
        __quit(1);
      }
      *(undefined4 *)(iVar6 + 0x24) = 0;
      *(undefined8 *)(iVar6 + 0x50) = uVar1;
      *(undefined4 *)(iVar6 + 0x28) = 0;
      *(undefined4 *)(iVar6 + 0x2c) = 0;
      *(undefined8 *)(iVar6 + 0x58) = uVar1;
      *(undefined4 *)(iVar6 + 0xdc) = 0;
      *(undefined8 *)(iVar6 + 200) = uVar1;
      *(undefined8 *)(iVar6 + 0xd0) = uVar1;
      *(undefined8 *)(iVar6 + 0xe0) = uVar1;
      *(undefined4 *)(iVar6 + 0xc0) = 0;
      *(undefined4 *)(iVar6 + 0xc4) = 0;
      iVar7 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
      uVar14 = DAT_0002145c;
      if (iVar7 != 0) {
        piVar4 = __errno_location();
        iVar3 = *piVar4;
        pcVar5 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
        uVar15 = 0x17da;
        goto LAB_000213f6;
      }
      iVar11 = iVar11 + 1;
      (*selective_yield)();
      (**(code **)(*(int *)(iVar6 + 4) + 0x60))(iVar6);
    } while (iVar11 < total_devices);
  }
  return;
}

