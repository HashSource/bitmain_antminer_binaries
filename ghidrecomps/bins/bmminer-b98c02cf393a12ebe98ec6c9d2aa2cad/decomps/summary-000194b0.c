
void summary(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  bool bVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  DItype DVar11;
  undefined4 in_stack_ffffff74;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_74;
  double local_70;
  double local_68;
  double local_60;
  double local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  double dStack_38;
  
  local_74 = 0;
  uVar6 = param_4;
  message(param_1,0xb,0,0);
  pcVar5 = ",\"SUMMARY\":[";
  if (param_4 == 0) {
    pcVar5 = "SUMMARY,";
  }
  uVar2 = io_add(param_1,pcVar5);
  if (is_certification == '\0') {
    iVar3 = pthread_mutex_lock((pthread_mutex_t *)hash_lock);
    if (iVar3 != 0) {
      _mutex_lock_part_3_constprop_27(DAT_00019a3c,0xb32);
    }
    DVar11 = __fixdfdi((DFtype)CONCAT44(in_stack_ffffff74,uVar6));
    total_diff1 = DVar11;
    local_70 = (double)__aeabi_l2d((undefined4)total_accepted,total_accepted._4_4_);
    dVar9 = total_secs;
    local_80 = (undefined4)DVar11;
    uStack_7c = (undefined4)((ulonglong)DVar11 >> 0x20);
    if (total_secs == 0.0) {
      local_70 = local_70 * DAT_00019908;
      local_68 = ((total_mhashes_done - new_total_mhashes_done) / DAT_00019900) /
                 (total_secs - new_total_secs);
      dVar8 = (double)__aeabi_l2d(local_80,uStack_7c);
      dVar10 = 1.0;
    }
    else {
      local_70 = (local_70 / total_secs) * DAT_00019908;
      local_68 = ((total_mhashes_done - new_total_mhashes_done) / DAT_00019900) /
                 (total_secs - new_total_secs);
      dVar8 = (double)__aeabi_l2d(local_80,uStack_7c);
      dVar10 = dVar9;
    }
    local_58 = (double)(longlong)mined_time_record + dVar9;
    local_60 = (dVar8 / dVar10) * DAT_00019908;
    local_74 = api_add_data_full(local_74,"Elapsed",0xd,&local_58,1);
    local_74 = api_add_data_full(local_74,"GHS 5s",1,displayed_hash_rate,0);
    local_74 = api_add_data_full(local_74,"GHS av",0x11,&local_68,0);
    local_74 = api_add_data_full(local_74,"Found Blocks",7,&found_blocks,1);
    local_74 = api_add_data_full(local_74,"Getworks",0xb,&total_getworks,1);
    local_74 = api_add_data_full(local_74,"Accepted",0xb,&total_accepted,1);
    local_74 = api_add_data_full(local_74,"Rejected",0xb,&total_rejected,1);
    local_74 = api_add_data_full(local_74,"Hardware Errors",6,&hw_errors,1);
    local_74 = api_add_data_full(local_74,"Utility",0x14,&local_70,0);
    local_74 = api_add_data_full(local_74,"Discarded",0xb,&total_discarded,1);
    local_74 = api_add_data_full(local_74,"Stale",0xb,&total_stale,1);
    local_74 = api_add_data_full(local_74,"Get Failures",7,&total_go,1);
    local_74 = api_add_data_full(local_74,"Local Work",7,&local_work,1);
    local_74 = api_add_data_full(local_74,"Remote Failures",7,&total_ro,1);
    local_74 = api_add_data_full(local_74,"Network Blocks",7,&new_blocks,1);
    local_74 = api_add_data_full(local_74,"Total MH",0x12,&total_mhashes_done,1);
    local_74 = api_add_data_full(local_74,"Work Utility",0x14,&local_60,0);
    local_74 = api_add_data_full(local_74,"Difficulty Accepted",0x18,&total_diff_accepted,1);
    local_74 = api_add_data_full(local_74,"Difficulty Rejected",0x18,&total_diff_rejected,1);
    local_74 = api_add_data_full(local_74,"Difficulty Stale",0x18,&total_diff_stale,1);
    uVar4 = api_add_data_full(local_74,"Best Share",10,&best_diff,1);
    uVar6 = total_diff1._4_4_ + ((int)hw_errors >> 0x1f) + (uint)CARRY4((uint)total_diff1,hw_errors)
    ;
    dVar9 = DAT_00019910;
    local_74 = uVar4;
    if (((uint)total_diff1 + hw_errors | uVar6) != 0) {
      lVar1 = (longlong)(int)hw_errors;
      dVar9 = (double)__aeabi_l2d((uint)total_diff1 + hw_errors,uVar6);
      dVar9 = (double)lVar1 / dVar9;
    }
    uStack_4c = (undefined4)((ulonglong)dVar9 >> 0x20);
    local_50 = SUB84(dVar9,0);
    uVar4 = api_add_data_full(uVar4,"Device Hardware%",0x19,&local_50,0);
    dVar9 = DAT_00019910;
    local_74 = uVar4;
    if (((uint)total_diff1 | total_diff1._4_4_) != 0) {
      dVar9 = (double)__aeabi_l2d();
      dVar9 = total_diff_rejected / dVar9;
    }
    uStack_44 = (undefined4)((ulonglong)dVar9 >> 0x20);
    local_48 = SUB84(dVar9,0);
    local_74 = api_add_data_full(uVar4,"Device Rejected%",0x19,&local_48,0);
    dVar10 = total_diff_rejected + total_diff_accepted + total_diff_stale;
    dVar9 = DAT_00019910;
    if (dVar10 != 0.0) {
      dVar9 = total_diff_rejected / dVar10;
    }
    uStack_3c = (undefined4)((ulonglong)dVar9 >> 0x20);
    local_40 = SUB84(dVar9,0);
    local_74 = api_add_data_full(local_74,"Pool Rejected%",0x19,&local_40,0);
    dVar9 = total_diff_accepted + total_diff_rejected + total_diff_stale;
    dStack_38 = DAT_00019910;
    if (dVar9 != 0.0) {
      dStack_38 = total_diff_stale / dVar9;
    }
    local_74 = api_add_data_full(local_74,"Pool Stale%",0x19,&dStack_38,0);
    local_74 = api_add_data_full(local_74,"Last getwork",0x10,&last_getwork,0);
    iVar3 = pthread_mutex_unlock((pthread_mutex_t *)hash_lock);
    if (iVar3 != 0) {
      _mutex_unlock_noyield_part_5_constprop_32(DAT_00019a3c,0xb65);
    }
    (*selective_yield)();
  }
  else {
    summary_stub(&local_74);
  }
  print_data(param_1,local_74,param_4,0);
  bVar7 = (param_4 & uVar2) != 0;
  if (bVar7) {
    uVar2 = 1;
  }
  if (bVar7) {
    *(char *)(param_1 + 0xd) = (char)uVar2;
  }
  return;
}

