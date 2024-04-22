
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool stratum_send(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  pthread_mutex_t *__mutex;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 local_7f8;
  undefined4 uStack_7f4;
  undefined4 uStack_7f0;
  undefined4 uStack_7ec;
  undefined2 local_7e8;
  
  if ((opt_protocol != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (4 < opt_log_level)))) {
    snprintf((char *)&local_818,0x800,"SEND: %s",param_2);
    _applog(5,&local_818,0);
  }
  __mutex = (pthread_mutex_t *)(param_1 + 0xb0);
  iVar3 = pthread_mutex_lock(__mutex);
  if (iVar3 != 0) {
    piVar4 = __errno_location();
    snprintf((char *)&local_818,0x800,"WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d",*piVar4,
             "util.c",DAT_000471a8,0x698);
    _applog(3,&local_818,1);
    _quit(1);
  }
  if (*(char *)((int)param_1 + 0x281) == '\0') {
    iVar5 = 3;
    iVar3 = pthread_mutex_unlock(__mutex);
    if (iVar3 == 0) {
      (*selective_yield)();
      goto LAB_00046ffe;
    }
LAB_00046fb4:
    uVar1 = DAT_000471a8;
    piVar4 = __errno_location();
    snprintf((char *)&local_818,0x800,"WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d",*piVar4,
             "util.c",uVar1,0x69e);
    _applog(3,&local_818,1);
    _quit(1);
  }
  else {
    iVar5 = __stratum_send(param_1,param_2,param_3);
    iVar3 = pthread_mutex_unlock(__mutex);
    if (iVar3 != 0) goto LAB_00046fb4;
  }
  (*selective_yield)();
  if (iVar5 == 2) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_818._0_1_ = s_Failed_to_send_in_stratum_send_00067228[0];
      local_818._1_1_ = s_Failed_to_send_in_stratum_send_00067228[1];
      local_818._2_1_ = s_Failed_to_send_in_stratum_send_00067228[2];
      local_818._3_1_ = s_Failed_to_send_in_stratum_send_00067228[3];
      uStack_814._0_1_ = s_Failed_to_send_in_stratum_send_00067228[4];
      uStack_814._1_1_ = s_Failed_to_send_in_stratum_send_00067228[5];
      uStack_814._2_1_ = s_Failed_to_send_in_stratum_send_00067228[6];
      uStack_814._3_1_ = s_Failed_to_send_in_stratum_send_00067228[7];
      uStack_810._0_1_ = s_Failed_to_send_in_stratum_send_00067228[8];
      uStack_810._1_1_ = s_Failed_to_send_in_stratum_send_00067228[9];
      uStack_810._2_1_ = s_Failed_to_send_in_stratum_send_00067228[10];
      uStack_810._3_1_ = s_Failed_to_send_in_stratum_send_00067228[11];
      uStack_80c._0_1_ = s_Failed_to_send_in_stratum_send_00067228[12];
      uStack_80c._1_1_ = s_Failed_to_send_in_stratum_send_00067228[13];
      uStack_80c._2_1_ = s_Failed_to_send_in_stratum_send_00067228[14];
      uStack_80c._3_1_ = s_Failed_to_send_in_stratum_send_00067228[15];
      local_808._0_1_ = s_Failed_to_send_in_stratum_send_00067228[16];
      local_808._1_1_ = s_Failed_to_send_in_stratum_send_00067228[17];
      local_808._2_1_ = s_Failed_to_send_in_stratum_send_00067228[18];
      local_808._3_1_ = s_Failed_to_send_in_stratum_send_00067228[19];
      uStack_804._0_1_ = s_Failed_to_send_in_stratum_send_00067228[20];
      uStack_804._1_1_ = s_Failed_to_send_in_stratum_send_00067228[21];
      uStack_804._2_1_ = s_Failed_to_send_in_stratum_send_00067228[22];
      uStack_804._3_1_ = s_Failed_to_send_in_stratum_send_00067228[23];
      uStack_800._0_1_ = s_Failed_to_send_in_stratum_send_00067228[24];
      uStack_800._1_1_ = s_Failed_to_send_in_stratum_send_00067228[25];
      uStack_800._2_1_ = s_Failed_to_send_in_stratum_send_00067228[26];
      uStack_800._3_1_ = s_Failed_to_send_in_stratum_send_00067228[27];
      _applog(7,&local_818,0);
      suspend_stratum(param_1);
      return false;
    }
  }
  else {
    if (iVar5 == 3) {
LAB_00046ffe:
      cVar2 = opt_debug;
      if ((opt_debug != '\0') &&
         (((use_syslog != '\0' || (opt_log_output != '\0')) || (cVar2 = '\0', 6 < opt_log_level))))
      {
        local_818._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[0];
        local_818._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[1];
        local_818._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[2];
        local_818._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[3];
        uStack_814._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[4];
        uStack_814._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[5];
        uStack_814._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[6];
        uStack_814._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[7];
        uStack_810._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[8];
        uStack_810._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[9];
        uStack_810._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[10];
        uStack_810._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[11];
        uStack_80c._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[12];
        uStack_80c._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[13];
        uStack_80c._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[14];
        uStack_80c._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[15];
        local_808._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[16];
        local_808._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[17];
        local_808._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[18];
        local_808._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[19];
        uStack_804._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[20];
        uStack_804._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[21];
        uStack_804._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[22];
        uStack_804._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[23];
        uStack_800._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[24];
        uStack_800._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[25];
        uStack_800._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[26];
        uStack_800._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[27];
        uStack_7fc._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[28];
        uStack_7fc._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[29];
        uStack_7fc._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[30];
        uStack_7fc._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[31];
        local_7f8._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[32];
        local_7f8._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[33];
        local_7f8._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[34];
        local_7f8._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[35];
        uStack_7f4._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[36];
        uStack_7f4._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[37];
        uStack_7f4._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[38];
        uStack_7f4._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[39];
        uStack_7f0._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[40];
        uStack_7f0._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[41];
        uStack_7f0._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[42];
        uStack_7f0._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[43];
        uStack_7ec._0_1_ = s_Stratum_send_failed_due_to_no_po_00067248[44];
        uStack_7ec._1_1_ = s_Stratum_send_failed_due_to_no_po_00067248[45];
        uStack_7ec._2_1_ = s_Stratum_send_failed_due_to_no_po_00067248[46];
        uStack_7ec._3_1_ = s_Stratum_send_failed_due_to_no_po_00067248[47];
        local_7e8 = (undefined2)ram0x00067278;
        _applog(7,&local_818,0);
        cVar2 = '\0';
      }
      return (bool)cVar2;
    }
    if (iVar5 != 1) {
      return iVar5 == 0;
    }
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf((char *)&local_818,0x800,"Write select failed on pool %d sock",*param_1);
      _applog(7,&local_818,0);
    }
  }
  suspend_stratum(param_1);
  return false;
}

