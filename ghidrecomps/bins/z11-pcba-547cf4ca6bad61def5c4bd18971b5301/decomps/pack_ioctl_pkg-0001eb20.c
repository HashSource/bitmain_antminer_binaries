
undefined4
pack_ioctl_pkg(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

{
  undefined4 uVar1;
  char acStack_420 [1024];
  undefined *local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined *local_14;
  
  switch(param_3) {
  case 0:
    local_14 = param_4;
    uVar1 = makeup_get_status_cmd(param_1,param_2,param_4[1],*param_4,param_4[2]);
    break;
  case 1:
    local_18 = param_4;
    uVar1 = makeup_set_config_cmd
                      (param_1,param_2,param_4[1],*param_4,param_4[2],*(undefined4 *)(param_4 + 4));
    break;
  case 2:
    local_20 = param_4;
    uVar1 = makeup_work_pkg(param_1,param_4);
    break;
  case 3:
    local_1c = param_4;
    uVar1 = makeup_set_address_cmd(param_1,param_2,*param_4);
    break;
  case 4:
    uVar1 = makeup_chain_inactive_cmd(param_1,param_2);
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
      snprintf(acStack_420,0x400,"unknow ioctl type %d\n",param_3);
      _applog(0,acStack_420,0);
    }
    uVar1 = 0;
  }
  return uVar1;
}

