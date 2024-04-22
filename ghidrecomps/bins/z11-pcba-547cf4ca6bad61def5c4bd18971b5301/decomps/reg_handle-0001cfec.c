
void reg_handle(int param_1,char param_2,undefined param_3)

{
  char acStack_41c [1024];
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  byte local_d;
  int local_c;
  
  local_c = param_1;
  local_d = CRC5_v1(param_1 + 2,(param_2 + -3) * '\b' + '\x03');
  if (local_d == (*(byte *)(local_c + 8) & 0x1f)) {
    local_14 = 3;
    local_18 = (uint)*(byte *)(local_c + 5) << 8 |
               (uint)*(byte *)(local_c + 3) << 0x18 | (uint)*(byte *)(local_c + 4) << 0x10 |
               (uint)*(byte *)(local_c + 6);
    add_reg_item(local_1c,local_18,3);
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
    snprintf(acStack_41c,0x400,"%s CRC error crc = %02x\n","reg_handle",(uint)local_d);
    _applog(0,acStack_41c,0);
  }
  return;
}

