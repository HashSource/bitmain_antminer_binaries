
void debugstate(io_data *io_data,long c,char *param,_Bool isjson,char group)

{
  uint uVar1;
  _Bool _Var2;
  int iVar3;
  api_data *paVar4;
  _Bool isjson_local;
  char *param_local;
  long c_local;
  io_data *io_data_local;
  _Bool io_open;
  api_data *root;
  
  if (param == (char *)0x0) {
    param_local = BLANK;
  }
  else {
    iVar3 = tolower((uint)(byte)*param);
    *param = (char)iVar3;
    param_local = param;
  }
  switch(*param_local) {
  case 'd':
    opt_debug = opt_debug != true;
    opt_log_output = opt_debug;
    if (opt_debug) {
      opt_quiet = false;
    }
    break;
  case 'n':
    opt_log_output = false;
    opt_debug = false;
    opt_quiet = false;
    opt_protocol = false;
    want_per_device_stats = false;
    opt_worktime = false;
    break;
  case 'p':
    opt_log_output = want_per_device_stats != true;
    want_per_device_stats = opt_log_output;
    break;
  case 'q':
    opt_quiet = opt_quiet != true;
    break;
  case 'r':
    opt_protocol = opt_protocol != true;
    if (opt_protocol) {
      opt_quiet = false;
    }
    break;
  case 's':
    opt_realquiet = true;
    break;
  case 'v':
    opt_log_output = opt_log_output != true;
    if (opt_log_output) {
      opt_quiet = false;
    }
    break;
  case 'w':
    opt_worktime = opt_worktime != true;
  }
  message(io_data,0x4f,0,(char *)0x0,isjson);
  if (isjson) {
    uVar1 = 0xe2a0;
  }
  else {
    uVar1 = 0xe2ac;
  }
  _Var2 = io_add(io_data,(char *)(uVar1 | 0xa0000));
  paVar4 = api_add_bool((api_data *)0x0,"Silent",&opt_realquiet,false);
  paVar4 = api_add_bool(paVar4,"Quiet",&opt_quiet,false);
  paVar4 = api_add_bool(paVar4,"Verbose",&opt_log_output,false);
  paVar4 = api_add_bool(paVar4,"Debug",&opt_debug,false);
  paVar4 = api_add_bool(paVar4,"RPCProto",&opt_protocol,false);
  paVar4 = api_add_bool(paVar4,"PerDevice",&want_per_device_stats,false);
  paVar4 = api_add_bool(paVar4,"WorkTime",&opt_worktime,false);
  print_data(io_data,paVar4,isjson,false);
  if ((isjson) && (_Var2)) {
    io_close(io_data);
  }
  return;
}

