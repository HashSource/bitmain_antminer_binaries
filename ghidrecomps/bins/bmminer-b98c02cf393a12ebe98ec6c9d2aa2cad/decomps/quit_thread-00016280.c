
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 quit_thread(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined local_7fc;
  
  iVar2 = pthread_mutex_lock(DAT_00016398);
  uVar1 = DAT_0001639c;
  if (iVar2 == 0) {
    iVar2 = pthread_mutex_unlock(DAT_00016398);
    uVar1 = DAT_0001639c;
  }
  else {
    piVar3 = __errno_location();
    snprintf((char *)&local_810,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar3,
             "api.c",uVar1,0x139a);
    _applog(3,&local_810,1);
    _quit(1);
    iVar2 = pthread_mutex_unlock(DAT_00016398);
    uVar1 = DAT_0001639c;
  }
  DAT_0001639c = uVar1;
  if (iVar2 != 0) {
    piVar3 = __errno_location();
    snprintf((char *)&local_810,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar3,
             "api.c",uVar1,0x139b);
    _applog(3,&local_810,1);
    _quit(1);
  }
  (*selective_yield)();
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_810._0_1_ = s_API__killing_bmminer_00057f44[0];
    local_810._1_1_ = s_API__killing_bmminer_00057f44[1];
    local_810._2_1_ = s_API__killing_bmminer_00057f44[2];
    local_810._3_1_ = s_API__killing_bmminer_00057f44[3];
    uStack_80c._0_1_ = s_API__killing_bmminer_00057f44[4];
    uStack_80c._1_1_ = s_API__killing_bmminer_00057f44[5];
    uStack_80c._2_1_ = s_API__killing_bmminer_00057f44[6];
    uStack_80c._3_1_ = s_API__killing_bmminer_00057f44[7];
    uStack_808._0_1_ = s_API__killing_bmminer_00057f44[8];
    uStack_808._1_1_ = s_API__killing_bmminer_00057f44[9];
    uStack_808._2_1_ = s_API__killing_bmminer_00057f44[10];
    uStack_808._3_1_ = s_API__killing_bmminer_00057f44[11];
    uStack_804._0_1_ = s_API__killing_bmminer_00057f44[12];
    uStack_804._1_1_ = s_API__killing_bmminer_00057f44[13];
    uStack_804._2_1_ = s_API__killing_bmminer_00057f44[14];
    uStack_804._3_1_ = s_API__killing_bmminer_00057f44[15];
    uStack_800._0_1_ = s_API__killing_bmminer_00057f44[16];
    uStack_800._1_1_ = s_API__killing_bmminer_00057f44[17];
    uStack_800._2_1_ = s_API__killing_bmminer_00057f44[18];
    uStack_800._3_1_ = s_API__killing_bmminer_00057f44[19];
    local_7fc = (undefined)ram0x00057f58;
    _applog(7,&local_810,0);
    kill_work();
    return 0;
  }
  kill_work();
  return 0;
}

