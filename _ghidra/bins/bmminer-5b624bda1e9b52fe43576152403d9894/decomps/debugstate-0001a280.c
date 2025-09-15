
/* WARNING: Unknown calling convention */

void debugstate(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  __int32_t _Var1;
  _Bool _Var2;
  __int32_t **pp_Var3;
  api_data *paVar4;
  
  if (param == (char *)0x0) goto switchD_0001a2a2_caseD_65;
  pp_Var3 = __ctype_tolower_loc();
  _Var1 = (*pp_Var3)[(byte)*param];
  *param = (char)_Var1;
  switch((char)_Var1) {
  case 'd':
    opt_debug = (_Bool)(opt_debug ^ 1);
    opt_log_output = opt_debug;
    goto joined_r0x0001a42c;
  case 'n':
    opt_log_output = false;
    opt_debug = false;
    opt_quiet = false;
    opt_protocol = false;
    want_per_device_stats = false;
    opt_worktime = false;
    break;
  case 'p':
    opt_log_output = (_Bool)(want_per_device_stats ^ 1);
    want_per_device_stats = opt_log_output;
    break;
  case 'q':
    opt_quiet = (_Bool)(opt_quiet ^ 1);
    break;
  case 'r':
    opt_protocol = (_Bool)(opt_protocol ^ 1);
    if (opt_protocol == false) break;
    goto LAB_0001a2de;
  case 's':
    opt_realquiet = true;
    break;
  case 'v':
    opt_log_output = (_Bool)(opt_log_output ^ 1);
joined_r0x0001a42c:
    if (opt_log_output != false) {
LAB_0001a2de:
      opt_quiet = false;
    }
    break;
  case 'w':
    opt_worktime = (_Bool)(opt_worktime ^ 1);
  }
switchD_0001a2a2_caseD_65:
  message(io_data,0x4f,0,(char *)0x0,isjson);
  if (isjson) {
    _Var2 = io_add(io_data,",\"DEBUG\":[");
    paVar4 = api_add_bool((api_data *)0x0,"Silent",&opt_realquiet,false);
    paVar4 = api_add_bool(paVar4,"Quiet",&opt_quiet,false);
    paVar4 = api_add_bool(paVar4,"Verbose",&opt_log_output,false);
    paVar4 = api_add_bool(paVar4,"Debug",&opt_debug,false);
    paVar4 = api_add_bool(paVar4,"RPCProto",&opt_protocol,false);
    paVar4 = api_add_bool(paVar4,"PerDevice",&want_per_device_stats,false);
    paVar4 = api_add_bool(paVar4,"WorkTime",&opt_worktime,false);
    print_data(io_data,paVar4,true,false);
    if (_Var2) {
      io_data->close = true;
    }
    return;
  }
  io_add(io_data,"DEBUG,");
  paVar4 = api_add_bool((api_data *)0x0,"Silent",&opt_realquiet,isjson);
  paVar4 = api_add_bool(paVar4,"Quiet",&opt_quiet,isjson);
  paVar4 = api_add_bool(paVar4,"Verbose",&opt_log_output,isjson);
  paVar4 = api_add_bool(paVar4,"Debug",&opt_debug,isjson);
  paVar4 = api_add_bool(paVar4,"RPCProto",&opt_protocol,isjson);
  paVar4 = api_add_bool(paVar4,"PerDevice",&want_per_device_stats,isjson);
  paVar4 = api_add_bool(paVar4,"WorkTime",&opt_worktime,isjson);
  print_data(io_data,paVar4,isjson,isjson);
  return;
}

