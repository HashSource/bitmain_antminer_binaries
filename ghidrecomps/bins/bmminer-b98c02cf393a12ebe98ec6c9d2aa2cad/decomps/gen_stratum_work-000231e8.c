
void gen_stratum_work(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  time_t tVar4;
  void *__ptr;
  void *__ptr_00;
  int *piVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  char *__format;
  undefined4 uVar10;
  pthread_rwlock_t *__rwlock;
  uint local_890;
  uint uStack_88c;
  uint local_888 [7];
  uint uStack_86c;
  uint local_868 [8];
  undefined auStack_848 [32];
  char acStack_828 [2052];
  
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)(param_1 + 0xd4));
  if (iVar2 != 0) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __format = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar3 = 0x204a;
    uVar6 = DAT_00023648;
LAB_0002357c:
    snprintf(acStack_828,0x800,__format,iVar2,"cgminer.c",uVar6,uVar3);
    _applog(3,acStack_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
  __rwlock = (pthread_rwlock_t *)(param_1 + 0xec);
  iVar2 = pthread_rwlock_wrlock(__rwlock);
  uVar6 = DAT_00023648;
  uVar3 = DAT_00023550;
  if (iVar2 != 0) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __format = "WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar3 = 0x204a;
    goto LAB_0002357c;
  }
  puVar9 = (uint *)(param_1 + 0x270);
  local_890 = *puVar9;
  uStack_88c = *(uint *)(param_1 + 0x274);
  _cg_memcpy(*(int *)(param_1 + 0x620) + *(int *)(param_1 + 0x628),&local_890,
             *(undefined4 *)(param_1 + 0x278),"cgminer.c",DAT_00023550,0x204f);
  uVar8 = *puVar9;
  iVar2 = *(int *)(param_1 + 0x274);
  uVar6 = *(undefined4 *)(param_1 + 0x278);
  *puVar9 = uVar8 + 1;
  *(uint *)(param_1 + 0x274) = iVar2 + (uint)(0xfffffffe < uVar8);
  *(uint *)(param_2 + 0x128) = uVar8;
  *(int *)(param_2 + 300) = iVar2;
  *(undefined4 *)(param_2 + 0x130) = uVar6;
  iVar2 = pthread_rwlock_unlock(__rwlock);
  uVar6 = uVar3;
  if (iVar2 != 0) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __format = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar3 = 0x2055;
    goto LAB_0002357c;
  }
  iVar2 = pthread_rwlock_rdlock(__rwlock);
  if (iVar2 != 0) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __format = "WTF RDLOCK ERROR ON LOCK! errno=%d in %s %s():%d";
    uVar3 = 0x2055;
    goto LAB_0002357c;
  }
  iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(param_1 + 0xd4));
  if (iVar2 != 0) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __format = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar3 = 0x2055;
    goto LAB_0002357c;
  }
  sha256(*(undefined4 *)(param_1 + 0x620),*(undefined4 *)(param_1 + 0x624),acStack_828);
  sha256(acStack_828,0x20,local_888);
  _cg_memcpy(local_868,local_888,0x20,"cgminer.c",uVar3,0x2059);
  if (0 < *(int *)(param_1 + 0x6ac)) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      _cg_memcpy(auStack_848,*(undefined4 *)(*(int *)(param_1 + 0x2a4) + iVar1),0x20,"cgminer.c",
                 uVar3,0x205d);
      sha256(local_868,0x40,acStack_828);
      sha256(acStack_828,0x20,local_888);
      _cg_memcpy(local_868,local_888,0x20,"cgminer.c",uVar3,0x205f);
    } while (iVar2 < *(int *)(param_1 + 0x6ac));
  }
  puVar9 = &uStack_86c;
  puVar7 = &uStack_88c;
  do {
    puVar9 = puVar9 + 1;
    uVar8 = *puVar9;
    puVar7 = puVar7 + 1;
    *puVar7 = uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
              uVar8 >> 0x18;
  } while (puVar9 != local_868 + 7);
  _cg_memcpy(param_2,param_1 + 0x62c,0x70,"cgminer.c",uVar3,0x2068);
  _cg_memcpy(param_2 + 0x24,local_888,0x20,"cgminer.c",uVar3,0x2069);
  uVar3 = *(undefined4 *)(param_1 + 0x2a0);
  uVar10 = *(undefined4 *)(param_1 + 0x724);
  *(undefined4 *)(param_2 + 0x138) = *(undefined4 *)(param_1 + 0x720);
  *(undefined4 *)(param_2 + 0x13c) = uVar10;
  uVar3 = __strdup(uVar3);
  *(undefined4 *)(param_2 + 0x120) = uVar3;
  uVar3 = __strdup(*(undefined4 *)(param_1 + 0x264));
  *(undefined4 *)(param_2 + 0x140) = uVar3;
  uVar3 = __strdup(param_1 + 0x70c);
  *(undefined4 *)(param_2 + 0x134) = uVar3;
  iVar2 = pthread_rwlock_unlock(__rwlock);
  if (iVar2 != 0) {
    piVar5 = __errno_location();
    iVar2 = *piVar5;
    __format = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar3 = 0x2074;
    goto LAB_0002357c;
  }
  (*selective_yield)();
  if (opt_debug == '\0') goto LAB_000233bc;
  __ptr = (void *)bin2hex(param_2,0x70);
  __ptr_00 = (void *)bin2hex(local_888,0x20);
  if (opt_debug != '\0') {
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
LAB_000234b6:
      if ((opt_log_output == '\0') && (opt_log_level < 7)) {
LAB_000234c8:
        if ((opt_log_output != '\0') || (6 < opt_log_level)) {
LAB_000234da:
          snprintf(acStack_828,0x800,"Work job_id %s nonce2 %llu ntime %s",
                   *(undefined4 *)(param_2 + 0x120),*(uint *)(param_2 + 0x128),
                   *(undefined4 *)(param_2 + 300),*(undefined4 *)(param_2 + 0x134));
          _applog(7,acStack_828,0);
        }
      }
      else {
LAB_00023518:
        snprintf(acStack_828,0x800,"Generated stratum header %s",__ptr);
        _applog(7,acStack_828,0);
        if (opt_debug != '\0') {
          if (use_syslog == '\0') goto LAB_000234c8;
          goto LAB_000234da;
        }
      }
    }
    else {
      snprintf(acStack_828,0x800,"Generated stratum merkle %s",__ptr_00);
      _applog(7,acStack_828,0);
      if (opt_debug != '\0') {
        if (use_syslog == '\0') goto LAB_000234b6;
        goto LAB_00023518;
      }
    }
  }
  free(__ptr);
  free(__ptr_00);
LAB_000233bc:
  calc_midstate(param_2);
  set_target((int)*(undefined8 *)(param_2 + 0x138),param_2 + 0xa0);
  local_work = local_work + 1;
  tVar4 = time((time_t *)0x0);
  if (5 < tVar4 - local_work_lasttime) {
    local_work_lasttime = time((time_t *)0x0);
    local_work_last = local_work;
  }
  uVar6 = work_block;
  *(undefined4 *)(param_2 + 0xf8) = 0;
  *(undefined4 *)(param_2 + 0x150) = uVar6;
  *(undefined *)(param_2 + 0x118) = 0;
  *(undefined *)(param_2 + 0x1b8) = 0x53;
  *(undefined4 *)(param_2 + 0xf4) = 0x3c;
  *(int *)(param_2 + 0x104) = param_1;
  *(undefined *)(param_2 + 0x11c) = 1;
  calc_diff((int)*(undefined8 *)(param_2 + 0x138),param_2);
  cgtime(param_2 + 0x108);
  return;
}

