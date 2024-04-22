
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void submit_work_async(void *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  bool bVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  void *local_824 [2];
  pthread_t pStack_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined4 local_7f8;
  
  puVar5 = *(undefined4 **)((int)param_1 + 0x104);
  local_824[0] = param_1;
  cgtime((int)param_1 + 0x1b0);
  if (opt_benchmark != '\0') {
    iVar1 = get_thread(*(undefined4 *)((int)local_824[0] + 0x100));
    iVar7 = *(int *)(iVar1 + 0x24);
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
    if (iVar1 != 0) {
      piVar2 = __errno_location();
      iVar1 = *piVar2;
      uVar6 = 0x2194;
      uVar8 = DAT_00029220;
LAB_000290da:
      pcVar4 = "WTF MUTEX ERROR ON LOCK! errno=%d in %s %s():%d";
      goto LAB_000290ea;
    }
    dVar11 = *(double *)(iVar7 + 200);
    dVar12 = *(double *)(puVar5 + 0x12);
    dVar10 = *(double *)((int)local_824[0] + 0x178);
    uVar3 = puVar5[2];
    iVar1 = puVar5[3];
    *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) + 1;
    puVar5[2] = uVar3 + 1;
    puVar5[3] = iVar1 + (uint)(0xfffffffe < uVar3);
    total_diff_accepted = total_diff_accepted + dVar10;
    *(double *)(iVar7 + 200) = dVar11 + dVar10;
    bVar9 = 0xfffffffe < (uint)total_accepted;
    total_accepted._0_4_ = (uint)total_accepted + 1;
    *(double *)(puVar5 + 0x12) = dVar12 + dVar10;
    total_accepted._4_4_ = total_accepted._4_4_ + (uint)bVar9;
    iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
    if (iVar1 == 0) {
      (*selective_yield)();
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 5)) {
        return;
      }
      snprintf((char *)&local_818,0x800,"Accepted %s %d benchmark share nonce %08x",
               *(undefined4 *)(*(int *)(iVar7 + 4) + 8),*(undefined4 *)(iVar7 + 8),
               *(undefined4 *)((int)local_824[0] + 0x4c));
      _applog(5,&local_818,0);
      return;
    }
    piVar2 = __errno_location();
    iVar1 = *piVar2;
    uVar6 = 0x219b;
LAB_00029282:
    pcVar4 = "WTF MUTEX ERROR ON UNLOCK! errno=%d in %s %s():%d";
    uVar8 = DAT_000292c0;
LAB_000290ea:
    snprintf((char *)&local_818,0x800,pcVar4,iVar1,"cgminer.c",uVar8,uVar6);
    _applog(3,&local_818,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
  iVar1 = stale_work(local_824[0],1);
  if (iVar1 != 0) {
    if (opt_submit_stale == '\0') {
      if (*(char *)(puVar5 + 0x1a) == '\0') {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
          snprintf((char *)&local_818,0x800,"Pool %d stale share detected, discarding",*puVar5);
          _applog(5,&local_818,0);
        }
        sharelog("discard",local_824[0]);
        iVar1 = pthread_mutex_lock((pthread_mutex_t *)stats_lock);
        if (iVar1 != 0) {
          piVar2 = __errno_location();
          iVar1 = *piVar2;
          uVar6 = 0x21b0;
          uVar8 = DAT_000292c0;
          goto LAB_000290da;
        }
        dVar10 = *(double *)((int)local_824[0] + 0x178);
        bVar9 = 0xfffffffe < (uint)total_stale;
        total_stale._0_4_ = (uint)total_stale + 1;
        total_diff_stale = total_diff_stale + dVar10;
        total_stale._4_4_ = total_stale._4_4_ + (uint)bVar9;
        puVar5[0x1e] = puVar5[0x1e] + 1;
        *(double *)(puVar5 + 0x16) = *(double *)(puVar5 + 0x16) + dVar10;
        iVar1 = pthread_mutex_unlock((pthread_mutex_t *)stats_lock);
        if (iVar1 == 0) {
          (*selective_yield)();
          _free_work(local_824,"cgminer.c",DAT_00029220,0x21b9);
          return;
        }
        piVar2 = __errno_location();
        iVar1 = *piVar2;
        uVar6 = 0x21b7;
        goto LAB_00029282;
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
        pcVar4 = "Pool %d stale share detected, submitting as pool requested";
        goto LAB_00028eca;
      }
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (4 < opt_log_level)) {
      pcVar4 = "Pool %d stale share detected, submitting as user requested";
LAB_00028eca:
      snprintf((char *)&local_818,0x800,pcVar4,*puVar5);
      _applog(5,&local_818,0);
    }
    *(undefined *)((int)local_824[0] + 0x119) = 1;
  }
  iVar1 = is_network_error();
  if (iVar1 != 0) {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_818._0_1_ = s_Work_stale_due_to_network_error_0005e624[0];
      local_818._1_1_ = s_Work_stale_due_to_network_error_0005e624[1];
      local_818._2_1_ = s_Work_stale_due_to_network_error_0005e624[2];
      local_818._3_1_ = s_Work_stale_due_to_network_error_0005e624[3];
      uStack_814._0_1_ = s_Work_stale_due_to_network_error_0005e624[4];
      uStack_814._1_1_ = s_Work_stale_due_to_network_error_0005e624[5];
      uStack_814._2_1_ = s_Work_stale_due_to_network_error_0005e624[6];
      uStack_814._3_1_ = s_Work_stale_due_to_network_error_0005e624[7];
      uStack_810._0_1_ = s_Work_stale_due_to_network_error_0005e624[8];
      uStack_810._1_1_ = s_Work_stale_due_to_network_error_0005e624[9];
      uStack_810._2_1_ = s_Work_stale_due_to_network_error_0005e624[10];
      uStack_810._3_1_ = s_Work_stale_due_to_network_error_0005e624[11];
      uStack_80c._0_1_ = s_Work_stale_due_to_network_error_0005e624[12];
      uStack_80c._1_1_ = s_Work_stale_due_to_network_error_0005e624[13];
      uStack_80c._2_1_ = s_Work_stale_due_to_network_error_0005e624[14];
      uStack_80c._3_1_ = s_Work_stale_due_to_network_error_0005e624[15];
      local_808._0_1_ = s_Work_stale_due_to_network_error_0005e624[16];
      local_808._1_1_ = s_Work_stale_due_to_network_error_0005e624[17];
      local_808._2_1_ = s_Work_stale_due_to_network_error_0005e624[18];
      local_808._3_1_ = s_Work_stale_due_to_network_error_0005e624[19];
      uStack_804._0_1_ = s_Work_stale_due_to_network_error_0005e624[20];
      uStack_804._1_1_ = s_Work_stale_due_to_network_error_0005e624[21];
      uStack_804._2_1_ = s_Work_stale_due_to_network_error_0005e624[22];
      uStack_804._3_1_ = s_Work_stale_due_to_network_error_0005e624[23];
      uStack_800._0_1_ = s_Work_stale_due_to_network_error_0005e624[24];
      uStack_800._1_1_ = s_Work_stale_due_to_network_error_0005e624[25];
      uStack_800._2_1_ = s_Work_stale_due_to_network_error_0005e624[26];
      uStack_800._3_1_ = s_Work_stale_due_to_network_error_0005e624[27];
      uStack_7fc._0_1_ = s_Work_stale_due_to_network_error_0005e624[28];
      uStack_7fc._1_1_ = s_Work_stale_due_to_network_error_0005e624[29];
      uStack_7fc._2_1_ = s_Work_stale_due_to_network_error_0005e624[30];
      uStack_7fc._3_1_ = s_Work_stale_due_to_network_error_0005e624[31];
      _applog(7,&local_818,0);
    }
    _free_work(local_824,"cgminer.c",DAT_00029220,0x21c2);
    return;
  }
  if (*(char *)((int)local_824[0] + 0x11c) == '\0') {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      local_818._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[0];
      local_818._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[1];
      local_818._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[2];
      local_818._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[3];
      uStack_814._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[4];
      uStack_814._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[5];
      uStack_814._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[6];
      uStack_814._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[7];
      uStack_810._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[8];
      uStack_810._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[9];
      uStack_810._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[10];
      uStack_810._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[11];
      uStack_80c._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[12];
      uStack_80c._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[13];
      uStack_80c._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[14];
      uStack_80c._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[15];
      local_808._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[16];
      local_808._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[17];
      local_808._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[18];
      local_808._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[19];
      uStack_804._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[20];
      uStack_804._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[21];
      uStack_804._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[22];
      uStack_804._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[23];
      uStack_800._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[24];
      uStack_800._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[25];
      uStack_800._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[26];
      uStack_800._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[27];
      uStack_7fc._0_1_ = s_Pushing_submit_work_to_work_thre_0005e690[28];
      uStack_7fc._1_1_ = s_Pushing_submit_work_to_work_thre_0005e690[29];
      uStack_7fc._2_1_ = s_Pushing_submit_work_to_work_thre_0005e690[30];
      uStack_7fc._3_1_ = s_Pushing_submit_work_to_work_thre_0005e690[31];
      _applog(7,&local_818,0);
    }
    iVar1 = pthread_create(&pStack_81c,(pthread_attr_t *)0x0,submit_work_thread + 1,local_824[0]);
    if (iVar1 == 0) {
      return;
    }
    local_818._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[0];
    local_818._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[1];
    local_818._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[2];
    local_818._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[3];
    uStack_814._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[4];
    uStack_814._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[5];
    uStack_814._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[6];
    uStack_814._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[7];
    uStack_810._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[8];
    uStack_810._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[9];
    uStack_810._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[10];
    uStack_810._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[11];
    uStack_80c._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[12];
    uStack_80c._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[13];
    uStack_80c._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[14];
    uStack_80c._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[15];
    local_808._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[16];
    local_808._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[17];
    local_808._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[18];
    local_808._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[19];
    uStack_804._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[20];
    uStack_804._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[21];
    uStack_804._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[22];
    uStack_804._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[23];
    uStack_800._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[24];
    uStack_800._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[25];
    uStack_800._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[26];
    uStack_800._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[27];
    uStack_7fc._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[28];
    uStack_7fc._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[29];
    uStack_7fc._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[30];
    uStack_7fc._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[31];
    local_7f8._0_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[32];
    local_7f8._1_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[33];
    local_7f8._2_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[34];
    local_7f8._3_1_ = s_Failed_to_create_submit_work_thr_0005e6b4[35];
    _applog(3,&local_818,1);
                    /* WARNING: Subroutine does not return */
    __quit(1);
  }
  if (opt_debug == '\0') {
    iVar1 = puVar5[0xb6];
    if (iVar1 == 0) goto LAB_00028fd4;
LAB_000291dc:
    iVar1 = tq_push(iVar1,local_824[0]);
    if (iVar1 != 0) {
      return;
    }
LAB_0002924c:
    if (opt_debug == '\0') goto LAB_00028fd4;
    if (use_syslog == '\0') goto LAB_00028fa2;
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (6 < opt_log_level)) {
      snprintf((char *)&local_818,0x800,"Pushing pool %d work to stratum queue",*puVar5);
      _applog(7,&local_818,0);
      iVar1 = puVar5[0xb6];
      if (iVar1 != 0) goto LAB_000291dc;
      goto LAB_0002924c;
    }
    iVar1 = puVar5[0xb6];
    if (iVar1 != 0) goto LAB_000291dc;
LAB_00028fa2:
    if ((opt_log_output == '\0') && (opt_log_level < 7)) goto LAB_00028fd4;
  }
  local_818._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[0];
  local_818._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[1];
  local_818._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[2];
  local_818._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[3];
  uStack_814._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[4];
  uStack_814._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[5];
  uStack_814._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[6];
  uStack_814._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[7];
  uStack_810._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[8];
  uStack_810._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[9];
  uStack_810._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[10];
  uStack_810._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[11];
  uStack_80c._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[12];
  uStack_80c._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[13];
  uStack_80c._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[14];
  uStack_80c._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[15];
  local_808._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[16];
  local_808._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[17];
  local_808._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[18];
  local_808._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[19];
  uStack_804._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[20];
  uStack_804._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[21];
  uStack_804._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[22];
  uStack_804._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[23];
  uStack_800._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[24];
  uStack_800._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[25];
  uStack_800._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[26];
  uStack_800._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[27];
  uStack_7fc._0_1_ = s_Discarding_work_from_removed_poo_0005e66c[28];
  uStack_7fc._1_1_ = s_Discarding_work_from_removed_poo_0005e66c[29];
  uStack_7fc._2_1_ = s_Discarding_work_from_removed_poo_0005e66c[30];
  uStack_7fc._3_1_ = s_Discarding_work_from_removed_poo_0005e66c[31];
  local_7f8 = CONCAT22(local_7f8._2_2_,(short)ram0x0005e68c);
  _applog(7,&local_818,0);
LAB_00028fd4:
  _free_work(local_824,"cgminer.c",DAT_00029220,0x21ca);
  return;
}

