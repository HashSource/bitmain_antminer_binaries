
undefined4 restart_thread(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  
  iVar2 = pthread_mutex_lock(DAT_00016278);
  uVar1 = DAT_0001627c;
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_unlock(DAT_00016278);
    uVar1 = DAT_0001627c;
  }
  else {
    piVar3 = __errno_location();
    snprintf((char *)&local_810,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
             "api.c",uVar1,0x13a8);
    _applog(3,&local_810,1);
    _quit(1);
    iVar2 = pthread_mutex_unlock(DAT_00016278);
    uVar1 = DAT_0001627c;
  }
  DAT_0001627c = uVar1;
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf((char *)&local_810,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
             "api.c",uVar1,0x13a9);
    _applog(3,&local_810,1);
    _quit(1);
  }
  (*selective_yield)();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_810._0_1_ = s_API__restarting_bmminer_00057f2c[0];
    local_810._1_1_ = s_API__restarting_bmminer_00057f2c[1];
    local_810._2_1_ = s_API__restarting_bmminer_00057f2c[2];
    local_810._3_1_ = s_API__restarting_bmminer_00057f2c[3];
    uStack_80c._0_1_ = s_API__restarting_bmminer_00057f2c[4];
    uStack_80c._1_1_ = s_API__restarting_bmminer_00057f2c[5];
    uStack_80c._2_1_ = s_API__restarting_bmminer_00057f2c[6];
    uStack_80c._3_1_ = s_API__restarting_bmminer_00057f2c[7];
    uStack_808._0_1_ = s_API__restarting_bmminer_00057f2c[8];
    uStack_808._1_1_ = s_API__restarting_bmminer_00057f2c[9];
    uStack_808._2_1_ = s_API__restarting_bmminer_00057f2c[10];
    uStack_808._3_1_ = s_API__restarting_bmminer_00057f2c[11];
    uStack_804._0_1_ = s_API__restarting_bmminer_00057f2c[12];
    uStack_804._1_1_ = s_API__restarting_bmminer_00057f2c[13];
    uStack_804._2_1_ = s_API__restarting_bmminer_00057f2c[14];
    uStack_804._3_1_ = s_API__restarting_bmminer_00057f2c[15];
    local_800._0_1_ = s_API__restarting_bmminer_00057f2c[16];
    local_800._1_1_ = s_API__restarting_bmminer_00057f2c[17];
    local_800._2_1_ = s_API__restarting_bmminer_00057f2c[18];
    local_800._3_1_ = s_API__restarting_bmminer_00057f2c[19];
    uStack_7fc._0_1_ = s_API__restarting_bmminer_00057f2c[20];
    uStack_7fc._1_1_ = s_API__restarting_bmminer_00057f2c[21];
    uStack_7fc._2_1_ = s_API__restarting_bmminer_00057f2c[22];
    uStack_7fc._3_1_ = s_API__restarting_bmminer_00057f2c[23];
    _applog(7,&local_810,0);
    app_restart();
    return 0;
  }
  app_restart();
  return 0;
}

