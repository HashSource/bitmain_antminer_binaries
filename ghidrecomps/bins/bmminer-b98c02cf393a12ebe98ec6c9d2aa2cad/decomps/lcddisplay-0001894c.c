
void lcddisplay(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  double local_c8;
  undefined2 local_c0 [16];
  char acStack_a0 [32];
  char acStack_80 [32];
  undefined2 local_60;
  undefined local_5e;
  undefined2 local_40;
  undefined local_3e;
  
  memset(local_c0,0,0x20);
  memset(acStack_a0,0,0x20);
  memset(acStack_80,0,0x20);
  memset(&local_60,0,0x20);
  memset(&local_40,0,0x20);
  iVar1 = current_pool();
  message(param_1,7,0,0,param_4);
  iVar3 = param_4;
  if (param_4 != 0) {
    iVar3 = io_add(param_1,",\"POOLS\":[");
  }
  local_c0[0] = 0x30;
  local_c8 = ((total_mhashes_done - new_total_mhashes_done) / DAT_00018b30) /
             (total_secs - new_total_secs);
  uVar2 = api_add_data_full(0,&DAT_000584cc,1,local_c0,0);
  uVar2 = api_add_data_full(uVar2,"GHS5s",0x11,&g_displayed_rolling,0);
  uVar2 = api_add_data_full(uVar2,"GHSavg",0x11,&local_c8,0);
  sprintf(acStack_a0,"%d",g_max_fan);
  uVar2 = api_add_data_full(uVar2,&DAT_000584e0,1,acStack_a0,0);
  sprintf(acStack_80,"%d",g_max_temp);
  uVar2 = api_add_data_full(uVar2,&DAT_000584e4,1,acStack_80,0);
  if (iVar1 == 0) {
    local_60 = (undefined2)DAT_000584ec;
    local_5e = (undefined)((uint)DAT_000584ec >> 0x10);
    local_40 = local_60;
    local_3e = local_5e;
    uVar2 = api_add_data_full(uVar2,&DAT_000584f0,1,&local_60,0);
    uVar2 = api_add_data_full(uVar2,&DAT_000584f8,1,&local_40,0);
  }
  else {
    uVar2 = api_add_data_full(uVar2,&DAT_000584f0,1,*(undefined4 *)(iVar1 + 0xa4),0);
    uVar2 = api_add_data_full(uVar2,&DAT_000584f8,1,*(undefined4 *)(iVar1 + 0xac),0);
  }
  print_data(param_1,uVar2,param_4,param_4);
  if (iVar3 != 0) {
    *(undefined *)(param_1 + 0xd) = 1;
  }
  return;
}

