
void chain_inactive(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint local_824;
  byte local_820;
  uint local_81c;
  int local_818;
  undefined4 local_814;
  char acStack_810 [2052];
  
  local_820 = 5;
  local_81c = 0;
  local_818 = 0;
  local_814 = 0;
  if (opt_multi_version != 0) {
    local_824 = 0x555;
    uVar2 = CRC5(&local_824,0x20);
    local_820 = (byte)uVar2;
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_810,0x800,
               "%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x\n",DAT_00034014,
               0x55,5,0,0,uVar2);
      _applog(7,acStack_810,0);
      uVar2 = (uint)local_820;
    }
    local_818 = uVar2 << 0x18;
    local_81c = local_824 << 0x18 | (local_824 >> 8 & 0xff) << 0x10 |
                (local_824 >> 0x10 & 0xff) << 8 | local_824 >> 0x18;
    while (uVar2 = get_BC_write_command(), (int)uVar2 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(&local_81c);
    set_BC_write_command(param_1 << 0x10 | 0x80800000U | uVar2 & 0xfff0ffff);
    return;
  }
  local_824 = 0x85;
  uVar1 = CRC5(&local_824,0x1b);
  local_824 = CONCAT13((char)uVar1,(undefined3)local_824);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_810,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
             DAT_00034014,0x85,0,0,uVar1);
    _applog(7,acStack_810,0);
  }
  local_81c = local_824 << 0x18 | (local_824 >> 8 & 0xff) << 0x10 | (local_824 >> 0x10 & 0xff) << 8
              | local_824 >> 0x18;
  set_BC_command_buffer(&local_81c);
  uVar2 = get_BC_write_command();
  set_BC_write_command(param_1 << 0x10 | 0x80800000U | uVar2 & 0xfff0ffff);
  return;
}

