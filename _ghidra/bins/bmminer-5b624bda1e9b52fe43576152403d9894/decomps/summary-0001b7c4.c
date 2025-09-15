
/* WARNING: Unknown calling convention */

void summary(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  longlong lVar1;
  int64_t iVar2;
  ulonglong uVar3;
  _Bool _Var4;
  int iVar5;
  undefined4 uVar6;
  api_data *paVar7;
  char *buf;
  char *func;
  char *func_00;
  int line;
  int line_00;
  double dVar8;
  double dVar9;
  _Bool io_open;
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
  
  message(io_data,0xb,0,(char *)0x0,isjson);
  buf = "SUMMARY,";
  if (isjson) {
    buf = ",\"SUMMARY\":[";
  }
  _Var4 = io_add(io_data,buf);
  iVar5 = pthread_mutex_lock((pthread_mutex_t *)&hash_lock);
  if (iVar5 != 0) {
    _mutex_lock((pthread_mutex_t *)"summary",(char *)0xaf2,func,line);
  }
  dVar8 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  total_diff1 = __aeabi_d2lz(SUB84(dVar8,0),(int)((ulonglong)dVar8 >> 0x20));
  uVar3 = (ulonglong)total_diff1 >> 0x20;
  uVar6 = (undefined4)total_diff1;
  local_68 = (double)__aeabi_l2d((undefined4)total_accepted,total_accepted._4_4_);
  if (total_secs == 0.0) {
    dVar8 = 1.0;
  }
  else {
    local_68 = local_68 / total_secs;
    dVar8 = total_secs;
  }
  local_68 = local_68 * 60.0;
  local_60 = ((total_mhashes_done - new_total_mhashes_done) / 1000.0) /
             (total_secs - new_total_secs);
  dVar9 = (double)__aeabi_l2d(uVar6,(int)uVar3);
  local_58 = (dVar9 / dVar8) * 60.0;
  paVar7 = api_add_elapsed((api_data *)0x0,"Elapsed",&total_secs,true);
  paVar7 = api_add_string(paVar7,"GHS 5s",displayed_hash_rate,false);
  paVar7 = api_add_mhs(paVar7,"GHS av",&local_60,false);
  paVar7 = api_add_uint(paVar7,"Found Blocks",&found_blocks,true);
  paVar7 = api_add_int64(paVar7,"Getworks",&total_getworks,true);
  paVar7 = api_add_int64(paVar7,"Accepted",&total_accepted,true);
  paVar7 = api_add_int64(paVar7,"Rejected",&total_rejected,true);
  paVar7 = api_add_int(paVar7,"Hardware Errors",&hw_errors,true);
  paVar7 = api_add_utility(paVar7,"Utility",&local_68,false);
  paVar7 = api_add_int64(paVar7,"Discarded",&total_discarded,true);
  paVar7 = api_add_int64(paVar7,"Stale",&total_stale,true);
  paVar7 = api_add_uint(paVar7,"Get Failures",&total_go,true);
  paVar7 = api_add_uint(paVar7,"Local Work",&local_work,true);
  paVar7 = api_add_uint(paVar7,"Remote Failures",&total_ro,true);
  paVar7 = api_add_uint(paVar7,"Network Blocks",&new_blocks,true);
  paVar7 = api_add_mhtotal(paVar7,"Total MH",&total_mhashes_done,true);
  paVar7 = api_add_utility(paVar7,"Work Utility",&local_58,false);
  paVar7 = api_add_diff(paVar7,"Difficulty Accepted",&total_diff_accepted,true);
  paVar7 = api_add_diff(paVar7,"Difficulty Rejected",&total_diff_rejected,true);
  paVar7 = api_add_diff(paVar7,"Difficulty Stale",&total_diff_stale,true);
  paVar7 = api_add_uint64(paVar7,"Best Share",&best_diff,true);
  iVar5 = total_diff1._4_4_ + (hw_errors >> 0x1f) + (uint)CARRY4((uint)total_diff1,hw_errors);
  if ((uint)total_diff1 + hw_errors == 0 && iVar5 == 0) {
    dVar8 = 0.0;
  }
  else {
    lVar1 = (longlong)hw_errors;
    dVar8 = (double)__aeabi_l2d((uint)total_diff1 + hw_errors,iVar5);
    dVar8 = (double)lVar1 / dVar8;
  }
  uStack_4c = (undefined4)((ulonglong)dVar8 >> 0x20);
  local_50 = SUB84(dVar8,0);
  paVar7 = api_add_percent(paVar7,"Device Hardware%",(double *)&local_50,false);
  if (total_diff1 == 0) {
    dVar8 = 0.0;
  }
  else {
    dVar8 = (double)__aeabi_l2d();
    dVar8 = total_diff_rejected / dVar8;
  }
  uStack_44 = (undefined4)((ulonglong)dVar8 >> 0x20);
  local_48 = SUB84(dVar8,0);
  paVar7 = api_add_percent(paVar7,"Device Rejected%",(double *)&local_48,false);
  dVar8 = total_diff_rejected + total_diff_accepted + total_diff_stale;
  if (dVar8 == 0.0) {
    dVar8 = 0.0;
  }
  else {
    dVar8 = total_diff_rejected / dVar8;
  }
  uStack_3c = (undefined4)((ulonglong)dVar8 >> 0x20);
  local_40 = SUB84(dVar8,0);
  paVar7 = api_add_percent(paVar7,"Pool Rejected%",(double *)&local_40,false);
  dStack_38 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  if (dStack_38 == 0.0) {
    dStack_38 = 0.0;
  }
  else {
    dStack_38 = total_diff_stale / dStack_38;
  }
  paVar7 = api_add_percent(paVar7,"Pool Stale%",&dStack_38,false);
  paVar7 = api_add_time(paVar7,"Last getwork",&last_getwork,false);
  iVar5 = pthread_mutex_unlock((pthread_mutex_t *)&hash_lock);
  if (iVar5 != 0) {
    _mutex_unlock_noyield((pthread_mutex_t *)"summary",(char *)0xb24,func_00,line_00);
  }
  (*selective_yield)();
  print_data(io_data,paVar7,isjson,false);
  iVar2 = total_diff1;
  if (_Var4 && isjson) {
    io_data->close = true;
    iVar2 = total_diff1;
  }
  total_diff1._4_4_ = (int)((ulonglong)iVar2 >> 0x20);
  total_diff1._0_4_ = (uint)iVar2;
  return;
}

