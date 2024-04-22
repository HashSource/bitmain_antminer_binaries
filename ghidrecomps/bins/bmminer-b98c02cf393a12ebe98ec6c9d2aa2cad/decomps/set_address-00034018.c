
void set_address(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_830;
  undefined4 local_82c;
  undefined local_828;
  uint local_824;
  int local_820;
  undefined4 local_81c;
  char acStack_818 [2052];
  
  local_82c = 0;
  local_828 = 0;
  local_824 = 0;
  local_820 = 0;
  local_81c = 0;
  if (opt_multi_version != 0) {
    local_830 = CONCAT22((ushort)param_3 & 0xff,0x541);
    bVar1 = CRC5(&local_830,0x20);
    local_820 = (uint)bVar1 << 0x18;
    local_82c = CONCAT31(local_82c._1_3_,bVar1);
    local_824 = param_3 << 8 | 0x41050000;
    while (uVar3 = get_BC_write_command(), (int)uVar3 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(&local_824);
    set_BC_write_command(param_1 << 0x10 | 0x80800000U | uVar3 & 0xfff0ffff);
    return;
  }
  local_830._0_1_ = 1;
  uVar4 = 1;
  if (param_2 != 0) {
    uVar4 = 0x81;
    local_830._0_1_ = 0x81;
  }
  local_830 = (uint)CONCAT11((char)param_3,(undefined)local_830);
  uVar2 = CRC5(&local_830,0x1b);
  local_830 = CONCAT13((char)uVar2,(undefined3)local_830);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    snprintf(acStack_818,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
             DAT_00034148,uVar4,param_3,0,uVar2);
    _applog(7,acStack_818,0);
  }
  local_824 = local_830 << 0x18 | (local_830 >> 8 & 0xff) << 0x10 | (local_830 >> 0x10 & 0xff) << 8
              | local_830 >> 0x18;
  set_BC_command_buffer(&local_824);
  uVar3 = get_BC_write_command();
  set_BC_write_command(param_1 << 0x10 | 0x80800000U | uVar3 & 0xfff0ffff);
  return;
}

