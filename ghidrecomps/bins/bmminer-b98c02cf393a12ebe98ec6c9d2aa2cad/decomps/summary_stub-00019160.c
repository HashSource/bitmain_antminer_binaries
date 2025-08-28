
void summary_stub(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 local_848;
  undefined4 local_844;
  undefined8 local_840;
  undefined4 local_838;
  undefined4 uStack_834;
  undefined4 local_830;
  undefined4 uStack_82c;
  char acStack_828 [2048];
  
  local_838 = 0;
  uStack_834 = 0;
  local_830 = 0;
  uStack_82c = 0;
  local_840 = 0;
  local_848 = 0;
  local_844 = 0;
  uVar1 = api_add_data_full(*param_1,"Elapsed",0xd,&total_secs,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"GHS 5s",1,"14189.74",0);
  *param_1 = uVar1;
  local_840 = 0x40cbe14147ae147b;
  uVar1 = api_add_data_full(uVar1,"GHS av",0x11,&local_840,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Found Blocks",7,&local_848,1);
  *param_1 = uVar1;
  local_838 = 0x14;
  uStack_834 = 0;
  uVar1 = api_add_data_full(uVar1,"Getworks",0xb,&local_838,1);
  *param_1 = uVar1;
  local_838 = 0x52;
  uStack_834 = 0;
  uVar1 = api_add_data_full(uVar1,"Accepted",0xb,&local_838,1);
  *param_1 = uVar1;
  local_838 = 0;
  uStack_834 = 0;
  uVar1 = api_add_data_full(uVar1,"Rejected",0xb,&local_838,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Hardware Errors",6,&local_844,1);
  *param_1 = uVar1;
  local_840 = 0x4017a3d70a3d70a4;
  uVar1 = api_add_data_full(uVar1,"Utility",0x14,&local_840,0);
  *param_1 = uVar1;
  local_838 = 0;
  uStack_834 = 0;
  uVar1 = api_add_data_full(uVar1,"Discarded",0xb,&local_838,1);
  *param_1 = uVar1;
  local_838 = 0;
  uStack_834 = 0;
  uVar1 = api_add_data_full(uVar1,"Stale",0xb,&local_838,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Get Failures",7,&local_848,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Local Work",7,&local_work,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Remote Failures",7,&local_848,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Network Blocks",7,&new_blocks,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Total MH",0x12,&total_mhashes_done,1);
  *param_1 = uVar1;
  local_840 = 0;
  uVar1 = api_add_data_full(uVar1,"Work Utility",0x14,&local_840,0);
  *param_1 = uVar1;
  local_840 = 0x4134800000000000;
  uVar1 = api_add_data_full(uVar1,"Difficulty Accepted",0x18,&local_840,1);
  *param_1 = uVar1;
  local_840 = 0x40d0000000000000;
  uVar1 = api_add_data_full(uVar1,"Difficulty Rejected",0x18,&local_840,1);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Difficulty Stale",0x18,&total_diff_stale,1);
  *param_1 = uVar1;
  local_830 = 0x34621d;
  uStack_82c = 0;
  uVar1 = api_add_data_full(uVar1,"Best Share",10,&local_830,1);
  *param_1 = uVar1;
  local_840 = 0;
  uVar1 = api_add_data_full(uVar1,"Device Hardware%",0x19,&local_840,0);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Device Rejected%",0x19,&local_840,0);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Pool Rejected%",0x19,&local_840,0);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Pool Stale%",0x19,&local_840,0);
  *param_1 = uVar1;
  uVar1 = api_add_data_full(uVar1,"Last getwork",0x10,&last_getwork,0);
  *param_1 = uVar1;
  if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 5)) {
    return;
  }
  snprintf(acStack_828,0x800,"root %d",uVar1);
  _applog(5,acStack_828,0);
  return;
}

