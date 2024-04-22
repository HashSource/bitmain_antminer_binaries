
void minecoin(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  message(param_1,0x4e,0,0,param_4);
  pcVar4 = ",\"COIN\":[";
  if (param_4 == 0) {
    pcVar4 = "COIN,";
  }
  uVar1 = io_add(param_1,pcVar4);
  uVar2 = api_add_data_full(0,"Hash Method",2,"sha256",0);
  iVar3 = pthread_mutex_lock((pthread_mutex_t *)ch_lock);
  if (iVar3 != 0) {
    _mutex_lock_part_3_constprop_27(DAT_0001840c,0xec1);
  }
  _rd_lock_constprop_25(DAT_00018408,DAT_0001840c,0xec1);
  iVar3 = pthread_mutex_unlock((pthread_mutex_t *)ch_lock);
  if (iVar3 != 0) {
    _mutex_unlock_noyield_part_5_constprop_32(DAT_0001840c,0xec1);
  }
  uVar2 = api_add_data_full(uVar2,"Current Block Time",0xf,&block_timeval,1);
  uVar2 = api_add_data_full(uVar2,"Current Block Hash",1,current_hash,1);
  iVar3 = pthread_rwlock_unlock(DAT_00018408);
  if (iVar3 != 0) {
    _rw_unlock_part_4_constprop_30(DAT_0001840c,0xec4);
  }
  (*selective_yield)();
  uVar2 = api_add_data_full(uVar2,&DAT_00058304,0xe,&have_longpoll,0);
  uVar2 = api_add_data_full(uVar2,"Network Difficulty",0x18,&current_diff,1);
  print_data(param_1,uVar2,param_4,0);
  if ((param_4 & uVar1) != 0) {
    *(undefined *)(param_1 + 0xd) = 1;
  }
  return;
}

