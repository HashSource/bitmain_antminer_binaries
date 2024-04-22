
void summary(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  longlong lVar1;
  uint uVar2;
  int64_t iVar3;
  double dVar4;
  double dVar5;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  double stalep;
  double prejp;
  double rejp;
  double hwp;
  double work_utility;
  double ghs;
  double utility;
  _Bool io_open;
  api_data *root;
  
  root = (api_data *)0x0;
  message(io_data,0xb,0,(char *)0x0,isjson);
  if (isjson) {
    uVar2 = 0xdeb8;
  }
  else {
    uVar2 = 0xdec8;
  }
  io_open = io_add(io_data,(char *)(uVar2 | 0xa0000));
  _mutex_lock(&hash_lock,"api-btm.c","summary",0xae4);
  dVar5 = total_diff_accepted + total_diff_rejected + total_diff_stale;
  total_diff1 = __fixdfdi(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  dVar4 = (double)__aeabi_l2d((undefined4)total_accepted,total_accepted._4_4_);
  dVar5 = total_secs;
  if (total_secs == 0.0) {
    dVar5 = 1.0;
  }
  utility = (dVar4 / dVar5) * DAT_0007fb18;
  ghs = get_AVG_hashrate();
  dVar4 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
  dVar5 = total_secs;
  if (total_secs == 0.0) {
    dVar5 = 1.0;
  }
  work_utility = (dVar4 / dVar5) * DAT_0007fb18;
  root = api_add_elapsed(root,"Elapsed",&total_secs,true);
  root = api_add_string(root,"GHS 5s",displayed_hash_rate,false);
  root = api_add_mhs(root,"GHS av",&ghs,false);
  root = api_add_uint(root,"Found Blocks",&found_blocks,true);
  root = api_add_int64(root,"Getworks",&total_getworks,true);
  root = api_add_int64(root,"Accepted",&total_accepted,true);
  root = api_add_int64(root,"Rejected",&total_rejected,true);
  root = api_add_int(root,"Hardware Errors",&hw_errors,true);
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
  hwp = DAT_0007fb20;
  if (total_diff1 + hw_errors != 0) {
    lVar1 = (longlong)hw_errors;
    dVar5 = (double)__aeabi_l2d((int)(total_diff1 + hw_errors),
                                (int)((ulonglong)(total_diff1 + hw_errors) >> 0x20));
    hwp = (double)lVar1 / dVar5;
  }
  root = api_add_percent(root,"Device Hardware%",&hwp,false);
  dVar5 = total_diff_rejected;
  rejp = DAT_0007fb20;
  if (total_diff1 != 0) {
    dVar4 = (double)__aeabi_l2d((undefined4)total_diff1,total_diff1._4_4_);
    rejp = dVar5 / dVar4;
  }
  root = api_add_percent(root,"Device Rejected%",&rejp,false);
  prejp = DAT_0007fb20;
  if (total_diff_accepted + total_diff_rejected + total_diff_stale != 0.0) {
    prejp = total_diff_rejected / (total_diff_accepted + total_diff_rejected + total_diff_stale);
  }
  root = api_add_percent(root,"Pool Rejected%",&prejp,false);
  stalep = DAT_0007fb20;
  if (total_diff_accepted + total_diff_rejected + total_diff_stale != 0.0) {
    stalep = total_diff_stale / (total_diff_accepted + total_diff_rejected + total_diff_stale);
  }
  root = api_add_percent(root,"Pool Stale%",&stalep,false);
  root = api_add_time(root,"Last getwork",&last_getwork,false);
  _mutex_unlock(&hash_lock,"api-btm.c","summary",0xb11);
  root = print_data(io_data,root,isjson,false);
  iVar3 = total_diff1;
  if ((isjson) && (io_open != false)) {
    io_close(io_data);
    iVar3 = total_diff1;
  }
  total_diff1._4_4_ = (undefined4)((ulonglong)iVar3 >> 0x20);
  total_diff1._0_4_ = (undefined4)iVar3;
  return;
}

