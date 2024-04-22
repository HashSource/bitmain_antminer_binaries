
int itemstats_isra_17(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                     char param_6)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int local_34;
  double local_30;
  double dStack_28;
  
  local_30 = ((total_mhashes_done - new_total_mhashes_done) / DAT_00018ca0) /
             (total_secs - new_total_secs);
  local_34 = param_2;
  uVar1 = api_add_data_full(0,"STATS",6,&local_34,0);
  uVar1 = api_add_data_full(uVar1,"ID",1,param_3,0);
  dStack_28 = (double)(longlong)mined_time_record + total_secs;
  uVar1 = api_add_data_full(uVar1,"Elapsed",0xd,&dStack_28,0);
  uVar1 = api_add_data_full(uVar1,"Calls",8,param_4,0);
  uVar1 = api_add_data_full(uVar1,&DAT_00058518,0xf,param_4 + 4,0);
  uVar1 = api_add_data_full(uVar1,&DAT_00058520,0xf,param_4 + 0xc,0);
  uVar1 = api_add_data_full(uVar1,&DAT_00058524,0xf,param_4 + 0x14,0);
  uVar1 = api_add_data_full(uVar1,"GHS 5s",1,displayed_hash_rate,0);
  iVar2 = api_add_data_full(uVar1,"GHS av",0x11,&local_30,0);
  iVar4 = iVar2;
  if ((param_5 != 0) && (iVar4 = param_5, iVar2 != 0)) {
    iVar4 = *(int *)(param_5 + 0x10);
    *(undefined4 *)(param_5 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
    *(int *)(*(int *)(iVar2 + 0x10) + 0x14) = param_5;
    *(int *)(iVar4 + 0x14) = iVar2;
    *(int *)(iVar2 + 0x10) = iVar4;
    iVar4 = iVar2;
  }
  cVar3 = param_6;
  if (param_6 != '\0') {
    if (local_34 < 1) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
    }
  }
  print_data(param_1,iVar4,param_6,cVar3);
  return local_34 + 1;
}

