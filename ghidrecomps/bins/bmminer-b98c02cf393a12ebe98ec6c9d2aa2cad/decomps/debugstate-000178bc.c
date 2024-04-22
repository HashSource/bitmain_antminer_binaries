
void debugstate(int param_1,undefined4 param_2,byte *param_3,int param_4)

{
  __int32_t **pp_Var1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
  if (param_3 == (byte *)0x0) goto switchD_000178de_caseD_65;
  pp_Var1 = __ctype_tolower_loc();
  bVar4 = *(byte *)(*pp_Var1 + *param_3);
  *param_3 = bVar4;
  switch(bVar4) {
  case 100:
    opt_log_output = opt_debug ^ 1;
    opt_debug = opt_log_output;
    if (opt_log_output == 0) break;
    goto LAB_00017926;
  case 0x6e:
    opt_log_output = 0;
    opt_debug = 0;
    opt_quiet = 0;
    opt_protocol = 0;
    want_per_device_stats = 0;
    opt_worktime = 0;
    break;
  case 0x70:
    opt_log_output = want_per_device_stats ^ 1;
    want_per_device_stats = opt_log_output;
    break;
  case 0x71:
    opt_quiet = opt_quiet ^ 1;
    break;
  case 0x72:
    opt_protocol = opt_protocol ^ 1;
    bVar4 = opt_protocol;
    goto joined_r0x00017b98;
  case 0x73:
    opt_realquiet = 1;
    break;
  case 0x76:
    opt_log_output = opt_log_output ^ 1;
    bVar4 = opt_log_output;
joined_r0x00017b98:
    if (bVar4 != 0) {
LAB_00017926:
      opt_quiet = 0;
    }
    break;
  case 0x77:
    opt_worktime = opt_worktime ^ 1;
  }
switchD_000178de_caseD_65:
  message(param_1,0x4f,0,0,param_4);
  if (param_4 != 0) {
    iVar2 = io_add(param_1,",\"DEBUG\":[");
    uVar3 = api_add_data_full(0,"Silent",0xe,&opt_realquiet,0);
    uVar3 = api_add_data_full(uVar3,"Quiet",0xe,&opt_quiet,0);
    uVar3 = api_add_data_full(uVar3,"Verbose",0xe,&opt_log_output,0);
    uVar3 = api_add_data_full(uVar3,"Debug",0xe,&opt_debug,0);
    uVar3 = api_add_data_full(uVar3,"RPCProto",0xe,&opt_protocol,0);
    uVar3 = api_add_data_full(uVar3,"PerDevice",0xe,&want_per_device_stats,0);
    uVar3 = api_add_data_full(uVar3,"WorkTime",0xe,&opt_worktime,0);
    print_data(param_1,uVar3,1,0);
    if (iVar2 != 0) {
      *(undefined *)(param_1 + 0xd) = 1;
    }
    return;
  }
  io_add(param_1,"DEBUG,");
  uVar3 = api_add_data_full(0,"Silent",0xe,&opt_realquiet,0);
  uVar3 = api_add_data_full(uVar3,"Quiet",0xe,&opt_quiet,0);
  uVar3 = api_add_data_full(uVar3,"Verbose",0xe,&opt_log_output,0);
  uVar3 = api_add_data_full(uVar3,"Debug",0xe,&opt_debug,0);
  uVar3 = api_add_data_full(uVar3,"RPCProto",0xe,&opt_protocol,0);
  uVar3 = api_add_data_full(uVar3,"PerDevice",0xe,&want_per_device_stats,0);
  uVar3 = api_add_data_full(uVar3,"WorkTime",0xe,&opt_worktime,0);
  print_data(param_1,uVar3,0,0);
  return;
}

