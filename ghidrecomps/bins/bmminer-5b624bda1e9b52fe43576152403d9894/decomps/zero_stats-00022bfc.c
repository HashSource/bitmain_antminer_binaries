
/* WARNING: Unknown calling convention */

void zero_stats(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  code **ppcVar14;
  int iVar15;
  int *piVar16;
  char *pcVar17;
  time_t tVar18;
  cgpu_info *pcVar19;
  cgpu_info *cgpu;
  undefined8 *puVar20;
  int *func;
  int *piVar21;
  undefined8 *puVar22;
  pool *pool;
  int iVar23;
  int iVar24;
  sysinfo sInfo;
  char tmp42 [2048];
  
  iVar15 = sysinfo((sysinfo *)&sInfo);
  if (iVar15 == 0) {
    *DAT_00022e70 = sInfo.uptime;
  }
  else {
    if (((*DAT_00022e64 != '\0') || (*DAT_00022e68 != '\0')) || (5 < *DAT_00022eb0)) {
      piVar16 = __errno_location();
      iVar15 = *piVar16;
      pcVar17 = strerror(iVar15);
      snprintf(tmp42,0x800,DAT_00022e6c,iVar15,pcVar17);
      _applog(6,tmp42,false);
    }
    tVar18 = time((time_t *)0x0);
    *DAT_00022e70 = tVar18;
  }
  cgtime(DAT_00022e74);
  puVar3 = DAT_00022e84;
  puVar2 = DAT_00022e80;
  puVar1 = DAT_00022e7c;
  copy_time(DAT_00022e78,DAT_00022e78 + -1);
  puVar5 = DAT_00022e94;
  puVar4 = DAT_00022e90;
  puVar22 = DAT_00022e8c;
  *DAT_00022e88 = 0;
  puVar20 = puVar22 + 0xc;
  *puVar1 = 0;
  *puVar2 = 0;
  *puVar3 = 0;
  *puVar4 = 0;
  *puVar5 = 0;
  do {
    *puVar22 = 0;
    piVar16 = DAT_00022e9c;
    puVar6 = DAT_00022e98;
    puVar22 = puVar22 + 1;
  } while (puVar22 != puVar20);
  puVar22 = (undefined8 *)(DAT_00022e98 + 8);
  *DAT_00022e98 = 0;
  puVar6[1] = 0x3ff00000;
  puVar8 = DAT_00022ecc;
  puVar7 = DAT_00022ec8;
  iVar15 = DAT_00022ec4;
  puVar3 = DAT_00022ec0;
  puVar2 = DAT_00022ebc;
  puVar1 = DAT_00022eb8;
  func = (int *)0x0;
  *puVar22 = 0x3ff0000000000000;
  *(undefined8 *)(puVar6 + 10) = 0x3ff0000000000000;
  iVar23 = *piVar16;
  *puVar7 = 0;
  *puVar1 = 0;
  *puVar2 = 0;
  *puVar3 = 0;
  *puVar8 = 0;
  puVar10 = DAT_00022ed8;
  puVar9 = DAT_00022ed4;
  puVar8 = DAT_00022ed0;
  puVar7 = DAT_00022ea4;
  puVar6 = DAT_00022ea0;
  *(undefined4 *)(iVar15 + 0x588) = 0;
  puVar13 = DAT_00022ee4;
  puVar12 = DAT_00022ee0;
  puVar11 = DAT_00022edc;
  hw_errors = 0;
  local_work = 0;
  total_go = 0;
  *puVar6 = 0;
  *puVar7 = 0;
  *puVar8 = 0;
  puVar8[1] = 0;
  *puVar9 = 0;
  puVar9[1] = 0;
  *puVar10 = 0;
  puVar10[1] = 0;
  *puVar12 = 0;
  puVar12[1] = 0;
  *puVar11 = 0;
  puVar11[1] = 0;
  *puVar13 = 0;
  puVar13[1] = 0;
  if (0 < iVar23) {
    piVar21 = *DAT_00022ea8;
    piVar16 = piVar21;
    do {
      func = piVar16 + 1;
      iVar15 = *piVar16;
      *(undefined4 *)(iVar15 + 0x74) = 0;
      *(undefined4 *)(iVar15 + 8) = 0;
      *(undefined4 *)(iVar15 + 0xc) = 0;
      *(undefined4 *)(iVar15 + 0x10) = 0;
      *(undefined4 *)(iVar15 + 0x14) = 0;
      *(undefined4 *)(iVar15 + 0x78) = 0;
      *(undefined4 *)(iVar15 + 0x7c) = 0;
      *(undefined4 *)(iVar15 + 0x80) = 0;
      *(undefined4 *)(iVar15 + 0x84) = 0;
      *(undefined4 *)(iVar15 + 0x160) = 0;
      *(undefined4 *)(iVar15 + 0x28) = 0;
      *(undefined4 *)(iVar15 + 0x2c) = 0;
      *(undefined8 *)(iVar15 + 0x48) = 0;
      *(undefined8 *)(iVar15 + 0x50) = 0;
      *(undefined8 *)(iVar15 + 0x58) = 0;
      *(undefined8 *)(iVar15 + 0x168) = 0;
      piVar16 = func;
    } while (func != piVar21 + iVar23);
  }
  piVar16 = DAT_00022ee8;
  zero_bestshare();
  ppcVar14 = DAT_00022eec;
  iVar15 = *piVar16;
  if (0 < iVar15) {
    iVar23 = 0;
    do {
      iVar24 = iVar23 + 1;
      pcVar19 = get_devices(iVar23);
      cgpu = (cgpu_info *)&pcVar19->dev_start_tv;
      copy_time((timeval *)cgpu,DAT_00022e74);
      iVar23 = pthread_mutex_lock(DAT_00022eac);
      if (iVar23 != 0) {
        _mutex_lock(DAT_00022eb4,(char *)0x17b6,(char *)func,iVar15);
      }
      pcVar19->accepted = 0;
      pcVar19->rejected = 0;
      pcVar19->total_mhashes = 0.0;
      pcVar19->hw_errors = 0;
      pcVar19->utility = 0.0;
      pcVar19->last_share_pool_time = 0;
      *(undefined4 *)&pcVar19->diff1 = 0;
      *(undefined4 *)((int)&pcVar19->diff1 + 4) = 0;
      pcVar19->diff_accepted = 0.0;
      pcVar19->diff_rejected = 0.0;
      pcVar19->last_share_diff = 0.0;
      iVar23 = pthread_mutex_unlock(DAT_00022eac);
      if (iVar23 != 0) {
        _mutex_unlock_noyield(DAT_00022eb4,(char *)0x17c3,(char *)func,iVar15);
      }
      (**ppcVar14)();
      (*pcVar19->drv->zero_stats)(pcVar19);
      iVar15 = *piVar16;
      iVar23 = iVar24;
    } while (iVar24 < iVar15);
  }
  return;
}

