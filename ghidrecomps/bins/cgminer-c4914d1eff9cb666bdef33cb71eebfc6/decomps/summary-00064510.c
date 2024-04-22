
void summary(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  longlong lVar1;
  uint uVar2;
  char *buf;
  double dVar3;
  double dVar4;
  undefined4 in_stack_ffffff7c;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  double stalep;
  double prejp;
  double rejp;
  double hwp;
  int hw_errors_temp;
  double work_utility;
  double ghs;
  double utility;
  _Bool io_open;
  api_data *root;
  
  root = (api_data *)0x0;
  hw_errors_temp = get_hw_errors();
  uVar2 = (uint)isjson;
  message(io_data,0xb,0,(char *)0x0,isjson);
  if (isjson) {
    buf = ",\"SUMMARY\":[";
  }
  else {
    buf = "SUMMARY,";
  }
  io_open = io_add(io_data,buf);
  _mutex_lock(&hash_lock,"api-btm.c","summary",0xae5);
  total_diff1 = __fixdfdi((DFtype)CONCAT44(in_stack_ffffff7c,uVar2));
  dVar3 = (double)__aeabi_l2d((undefined4)total_accepted,total_accepted._4_4_);
  dVar4 = total_secs;
  if (total_secs == 0.0) {
    dVar4 = 1.0;
  }
  utility = (dVar3 / dVar4) * DAT_00064938;
  ghs = getAVGhashrate();
  dVar3 = (double)__aeabi_l2d((uint)total_diff1,total_diff1._4_4_);
  dVar4 = total_secs;
  if (total_secs == 0.0) {
    dVar4 = 1.0;
  }
  work_utility = (dVar3 / dVar4) * DAT_00064938;
  root = api_add_elapsed(root,"Elapsed",&total_secs,true);
  root = api_add_string(root,"GHS 5s",displayed_hash_rate,false);
  root = api_add_mhs(root,"GHS av",&ghs,false);
  root = api_add_uint(root,"Found Blocks",&found_blocks,true);
  root = api_add_int64(root,"Getworks",&total_getworks,true);
  root = api_add_int64(root,"Accepted",&total_accepted,true);
  root = api_add_int64(root,"Rejected",&total_rejected,true);
  root = api_add_int(root,"Hardware Errors",&hw_errors_temp,true);
  root = api_add_utility(root,"Utility",&utility,false);
  root = api_add_int64(root,"Discarded",&total_discarded,true);
  root = api_add_int64(root,"Stale",&total_stale,true);
  root = api_add_uint(root,"Get Failures",&total_go,true);
  root = api_add_uint(root,"Local Work",&local_work,true);
  root = api_add_uint(root,"Remote Failures",&total_ro,true);
  root = api_add_uint(root,"Network Blocks",&new_blocks,true);
  root = api_add_mhtotal(root,"Total MH",&total_mhashes_done,true);
  root = api_add_utility(root,"Work Utility",&work_utility,false);
  root = api_add_diff(root,"Difficulty Accepted",&total_diff_accepted,true);
  root = api_add_diff(root,"Difficulty Rejected",&total_diff_rejected,true);
  root = api_add_diff(root,"Difficulty Stale",&total_diff_stale,true);
  root = api_add_uint64(root,"Best Share",&best_diff,true);
  hwp = DAT_00064940;
  if ((hw_errors_temp + (uint)total_diff1 |
      (hw_errors_temp >> 0x1f) + total_diff1._4_4_ + CARRY4(hw_errors_temp,(uint)total_diff1)) != 0)
  {
    lVar1 = (longlong)hw_errors_temp;
    dVar4 = (double)__aeabi_l2d(hw_errors_temp + (uint)total_diff1,
                                (hw_errors_temp >> 0x1f) +
                                total_diff1._4_4_ + CARRY4(hw_errors_temp,(uint)total_diff1));
    hwp = (double)lVar1 / dVar4;
  }
  root = api_add_percent(root,"Device Hardware%",&hwp,false);
  dVar4 = total_diff_rejected;
  rejp = DAT_00064940;
  if (((uint)total_diff1 | total_diff1._4_4_) != 0) {
    dVar3 = (double)__aeabi_l2d((uint)total_diff1,total_diff1._4_4_);
    rejp = dVar4 / dVar3;
  }
  root = api_add_percent(root,"Device Rejected%",&rejp,false);
  prejp = DAT_00064940;
  if (total_diff_accepted + total_diff_rejected + total_diff_stale != 0.0) {
    prejp = total_diff_rejected / (total_diff_accepted + total_diff_rejected + total_diff_stale);
  }
  root = api_add_percent(root,"Pool Rejected%",&prejp,false);
  stalep = DAT_00064940;
  if (total_diff_accepted + total_diff_rejected + total_diff_stale != 0.0) {
    stalep = total_diff_stale / (total_diff_accepted + total_diff_rejected + total_diff_stale);
  }
  root = api_add_percent(root,"Pool Stale%",&stalep,false);
  root = api_add_time(root,"Last getwork",&last_getwork,false);
  _mutex_unlock(&hash_lock,"api-btm.c","summary",0xb12);
  root = print_data(io_data,root,isjson,false);
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
  }
  return;
}

