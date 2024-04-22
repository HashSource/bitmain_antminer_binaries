
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char stale_work(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  pthread_rwlock_t *__rwlock;
  int local_830 [2];
  undefined4 local_828;
  undefined4 uStack_824;
  undefined4 uStack_820;
  undefined4 uStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined2 local_800;
  
  cVar1 = opt_debug;
  if (opt_benchmark != '\0') {
    return '\0';
  }
  if (opt_benchfile != 0) {
    return '\0';
  }
  if (*(int *)(param_1 + 0x150) != work_block) {
    if (opt_debug == '\0') {
      return '\x01';
    }
    if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
      return opt_debug;
    }
    local_828 = s_Work_stale_due_to_block_mismatch_0005d8b4._0_4_;
    uStack_824 = s_Work_stale_due_to_block_mismatch_0005d8b4._4_4_;
    uStack_820 = s_Work_stale_due_to_block_mismatch_0005d8b4._8_4_;
    uStack_81c = s_Work_stale_due_to_block_mismatch_0005d8b4._12_4_;
    local_818 = s_Work_stale_due_to_block_mismatch_0005d8b4._16_4_;
    uStack_814 = s_Work_stale_due_to_block_mismatch_0005d8b4._20_4_;
    local_810 = s_Work_stale_due_to_block_mismatch_0005d8b4._24_4_;
    uStack_80c = s_Work_stale_due_to_block_mismatch_0005d8b4._28_4_;
    local_808 = CONCAT31(local_808._1_3_,(char)ram0x0005d8d4);
    _applog(7,&local_828,0);
    return cVar1;
  }
  iVar7 = *(int *)(param_1 + 0x104);
  iVar3 = *(int *)(param_1 + 0x114);
  if (*(int *)(param_1 + 0x114) <= opt_scantime) {
    iVar3 = opt_expiry;
  }
  if ((param_2 == 0) && (*(char *)(iVar7 + 0x280) != '\0')) {
    if ((*(char *)(iVar7 + 0x281) == '\0') || (*(char *)(iVar7 + 0x283) == '\0')) {
      if (opt_debug == '\0') {
        return '\x01';
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
        return '\x01';
      }
      local_828 = s_Work_stale_due_to_stratum_inacti_0005d8d8._0_4_;
      uStack_824 = s_Work_stale_due_to_stratum_inacti_0005d8d8._4_4_;
      uStack_820 = s_Work_stale_due_to_stratum_inacti_0005d8d8._8_4_;
      uStack_81c = s_Work_stale_due_to_stratum_inacti_0005d8d8._12_4_;
      local_818 = s_Work_stale_due_to_stratum_inacti_0005d8d8._16_4_;
      uStack_814 = s_Work_stale_due_to_stratum_inacti_0005d8d8._20_4_;
      local_810 = s_Work_stale_due_to_stratum_inacti_0005d8d8._24_4_;
      uStack_80c = s_Work_stale_due_to_stratum_inacti_0005d8d8._28_4_;
      _applog(7,&local_828,0);
      return cVar1;
    }
    iVar2 = pthread_mutex_lock((pthread_mutex_t *)(iVar7 + 0xd4));
    if (iVar2 != 0) {
LAB_00023a94:
                    /* WARNING: Subroutine does not return */
      _mutex_lock_part_47_constprop_75(DAT_00023aa0,0x1394);
    }
    __rwlock = (pthread_rwlock_t *)(iVar7 + 0xec);
    iVar2 = pthread_rwlock_rdlock(__rwlock);
    if (iVar2 != 0) {
      _rd_lock_part_39_constprop_80(DAT_00023aa0,0x1394);
      goto LAB_00023a94;
    }
    iVar2 = pthread_mutex_unlock((pthread_mutex_t *)(iVar7 + 0xd4));
    if (iVar2 != 0) {
      piVar4 = __errno_location();
      uVar5 = 0x1394;
      pcVar6 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
      goto LAB_00023a4a;
    }
    iVar2 = strcmp(*(char **)(param_1 + 0x120),*(char **)(iVar7 + 0x2a0));
    if (iVar2 == 0) {
      iVar2 = pthread_rwlock_unlock(__rwlock);
      if (iVar2 == 0) {
        (*selective_yield)();
        goto LAB_00023882;
      }
    }
    else {
      iVar3 = pthread_rwlock_unlock(__rwlock);
      if (iVar3 == 0) {
        (*selective_yield)();
        if (opt_debug == '\0') {
          return '\x01';
        }
        if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
          return '\x01';
        }
        pcVar6 = "Work stale due to stratum job_id mismatch";
        goto LAB_00023982;
      }
    }
    piVar4 = __errno_location();
    uVar5 = 0x139b;
    pcVar6 = "WTF RWLOCK ERROR ON UNLOCK! errno=%d in %s %s():%d";
LAB_00023a4a:
    snprintf((char *)&local_828,0x800,pcVar6,*piVar4,"cgminer.c",DAT_00023aa0,uVar5);
    _applog(3,&local_828,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
LAB_00023882:
  iVar3 = iVar3 - (int)(longlong)(*(double *)(iVar7 + 0x1c0) * 5.0 + 1.0);
  cgtime(local_830);
  cVar1 = opt_debug;
  if (iVar3 < 5) {
    iVar3 = 5;
  }
  if (local_830[0] - *(int *)(param_1 + 0x108) < iVar3) {
    if (opt_fail_only <= param_2) {
      return '\0';
    }
    iVar3 = current_pool();
    if (iVar7 == iVar3) {
      return '\0';
    }
    if (*(char *)(param_1 + 0x11a) != '\0') {
      return '\0';
    }
    if (pool_strategy - 3U < 2) {
      return '\0';
    }
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      pcVar6 = "Work stale due to fail only pool mismatch";
LAB_00023982:
      cVar1 = opt_debug;
      local_828 = *(undefined4 *)pcVar6;
      uStack_824 = *(undefined4 *)((int)pcVar6 + 4);
      uStack_820 = *(undefined4 *)((int)pcVar6 + 8);
      uStack_81c = *(undefined4 *)((int)pcVar6 + 0xc);
      local_818 = *(undefined4 *)((int)pcVar6 + 0x10);
      uStack_814 = *(undefined4 *)((int)pcVar6 + 0x14);
      local_810 = *(undefined4 *)((int)pcVar6 + 0x18);
      uStack_80c = *(undefined4 *)((int)pcVar6 + 0x1c);
      local_808 = *(undefined4 *)((int)pcVar6 + 0x20);
      uStack_804 = *(undefined4 *)((int)pcVar6 + 0x24);
      local_800 = (undefined2)*(undefined4 *)((int)pcVar6 + 0x28);
      _applog(7,&local_828,0);
      return cVar1;
    }
  }
  else if ((opt_debug != '\0') &&
          (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    local_828._0_1_ = s_Work_stale_due_to_expiry_0005d928[0];
    local_828._1_1_ = s_Work_stale_due_to_expiry_0005d928[1];
    local_828._2_1_ = s_Work_stale_due_to_expiry_0005d928[2];
    local_828._3_1_ = s_Work_stale_due_to_expiry_0005d928[3];
    uStack_824._0_1_ = s_Work_stale_due_to_expiry_0005d928[4];
    uStack_824._1_1_ = s_Work_stale_due_to_expiry_0005d928[5];
    uStack_824._2_1_ = s_Work_stale_due_to_expiry_0005d928[6];
    uStack_824._3_1_ = s_Work_stale_due_to_expiry_0005d928[7];
    uStack_820._0_1_ = s_Work_stale_due_to_expiry_0005d928[8];
    uStack_820._1_1_ = s_Work_stale_due_to_expiry_0005d928[9];
    uStack_820._2_1_ = s_Work_stale_due_to_expiry_0005d928[10];
    uStack_820._3_1_ = s_Work_stale_due_to_expiry_0005d928[11];
    uStack_81c._0_1_ = s_Work_stale_due_to_expiry_0005d928[12];
    uStack_81c._1_1_ = s_Work_stale_due_to_expiry_0005d928[13];
    uStack_81c._2_1_ = s_Work_stale_due_to_expiry_0005d928[14];
    uStack_81c._3_1_ = s_Work_stale_due_to_expiry_0005d928[15];
    local_818._0_1_ = s_Work_stale_due_to_expiry_0005d928[16];
    local_818._1_1_ = s_Work_stale_due_to_expiry_0005d928[17];
    local_818._2_1_ = s_Work_stale_due_to_expiry_0005d928[18];
    local_818._3_1_ = s_Work_stale_due_to_expiry_0005d928[19];
    uStack_814._0_1_ = s_Work_stale_due_to_expiry_0005d928[20];
    uStack_814._1_1_ = s_Work_stale_due_to_expiry_0005d928[21];
    uStack_814._2_1_ = s_Work_stale_due_to_expiry_0005d928[22];
    uStack_814._3_1_ = s_Work_stale_due_to_expiry_0005d928[23];
    local_810 = CONCAT31(local_810._1_3_,(char)ram0x0005d940);
    _applog(7,&local_828,0);
    return cVar1;
  }
  return '\x01';
}

