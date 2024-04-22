
int read_uart_data_in_fpga(byte param_1,int param_2,uint param_3)

{
  undefined uVar1;
  undefined uVar2;
  char acStack_424 [1024];
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = 0;
  local_1c = 0;
  local_20 = 0;
  local_14 = 0;
  local_24 = 0;
  local_18 = 0;
  switch(param_1) {
  case 0:
    local_c = 0x44c;
    local_10 = 0x44d;
    break;
  case 1:
    local_c = 0x44e;
    local_10 = 0x44f;
    break;
  case 2:
    local_c = 0x450;
    local_10 = 0x451;
    break;
  case 3:
    local_c = 0x452;
    local_10 = 0x453;
    break;
  case 4:
    local_c = 0x454;
    local_10 = 0x455;
    break;
  case 5:
    local_c = 0x456;
    local_10 = 0x457;
    break;
  case 6:
    local_c = 0x458;
    local_10 = 0x459;
    break;
  case 7:
    local_c = 0x45a;
    local_10 = 0x45b;
    break;
  case 8:
    local_c = 0x45c;
    local_10 = 0x45d;
    break;
  case 9:
    local_c = 0x45e;
    local_10 = 0x45f;
    break;
  default:
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_424,0x400,"%s: The uart%d is not supported!!!\n","read_uart_data_in_fpga",
               (uint)param_1);
      _applog(2,acStack_424,0);
    }
    return 0;
  }
  local_1c = param_3 & 0x3ff | 0x80000000;
  write_axi_fpga(local_c,local_1c);
  local_20 = param_3 >> 2;
  for (local_14 = 0; local_14 < local_20; local_14 = local_14 + 1) {
    local_24 = read_axi_fpga(local_10);
    *(char *)(local_14 * 4 + param_2) = (char)((uint)local_24 >> 0x18);
    *(char *)(local_14 * 4 + 1 + param_2) = (char)((uint)local_24 >> 0x10);
    *(char *)(local_14 * 4 + 2 + param_2) = (char)((uint)local_24 >> 8);
    *(char *)(local_14 * 4 + 3 + param_2) = (char)local_24;
  }
  local_18 = local_20 << 2;
  local_20 = param_3 & 3;
  if (local_20 != 0) {
    local_24 = read_axi_fpga(local_10);
    uVar2 = (undefined)((uint)local_24 >> 0x10);
    uVar1 = (undefined)((uint)local_24 >> 0x18);
    if (local_20 == 2) {
      *(undefined *)(local_14 * 4 + param_2) = uVar1;
      *(undefined *)(local_14 * 4 + 1 + param_2) = uVar2;
      local_18 = local_18 + 2;
    }
    else if (local_20 == 3) {
      *(undefined *)(local_14 * 4 + param_2) = uVar1;
      *(undefined *)(local_14 * 4 + 1 + param_2) = uVar2;
      *(char *)(local_14 * 4 + 2 + param_2) = (char)((uint)local_24 >> 8);
      local_18 = local_18 + 3;
    }
    else if (local_20 == 1) {
      *(undefined *)(local_14 * 4 + param_2) = uVar1;
      local_18 = local_18 + 1;
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_424,0x400,"%s: the uart%d left data is 4*N length, error!!!\n",
               "read_uart_data_in_fpga",(uint)param_1);
      _applog(2,acStack_424,0);
    }
  }
  return local_18;
}

