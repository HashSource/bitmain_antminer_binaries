
void read_asic_register(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint3 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  FILE *__stream;
  undefined4 uVar5;
  int iVar6;
  uint local_82c;
  byte local_828;
  uint local_824;
  int local_820;
  undefined4 local_81c;
  char acStack_818 [2052];
  
  local_828 = 0;
  local_824 = 0;
  local_820 = 0;
  local_81c = 0;
  if (opt_multi_version == 0) {
    uVar5 = 4;
    uVar1 = (uint3)CONCAT11((char)param_4,(char)param_3);
    local_82c = CONCAT31(uVar1,4);
    if (param_2 != 0) {
      uVar5 = 0x84;
      local_82c = CONCAT31(uVar1,0x84);
    }
    uVar2 = CRC5(&local_82c,0x1b);
    local_82c = CONCAT13((char)uVar2,(undefined3)local_82c);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_818,0x800,"%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n",
               DAT_00031964,uVar5,param_3,param_4,uVar2);
      _applog(7,acStack_818,0);
    }
    local_824 = local_82c << 0x18 | (local_82c >> 8 & 0xff) << 0x10 |
                (local_82c >> 0x10 & 0xff) << 8 | local_82c >> 0x18;
  }
  else {
    if (param_2 == 0) {
      uVar5 = 0x44;
      local_82c._0_1_ = 0x44;
    }
    else {
      uVar5 = 0x54;
      local_82c._0_1_ = 0x54;
    }
    local_82c._0_3_ = CONCAT12((char)param_3,CONCAT11(5,(undefined)local_82c));
    local_82c = CONCAT13((char)param_4,(undefined3)local_82c);
    uVar3 = CRC5(&local_82c,0x20);
    local_828 = (byte)uVar3;
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_818,0x800,
               "%s:VIL buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x",DAT_00031964
               ,uVar5,5,param_3,param_4,uVar3);
      _applog(7,acStack_818,0);
      uVar3 = (uint)local_828;
    }
    local_820 = uVar3 << 0x18;
    iVar6 = 0xbb9;
    local_824 = local_82c << 0x18 | (local_82c >> 8 & 0xff) << 0x10 |
                (local_82c >> 0x10 & 0xff) << 8 | local_82c >> 0x18;
    do {
      iVar4 = get_BC_write_command();
      if (-1 < iVar4) goto LAB_00031824;
      cgsleep_ms(1);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (3 < log_level) {
      __stream = fopen(log_file,(char *)&DAT_0005e760);
      if (__stream != (FILE *)0x0) {
        uVar5 = get_hash_on_plug();
        fprintf(__stream,"%s:%d:%s: Error: clement debug: wait BC ready timeout, PLUG ON=0x%08x..\n"
                ,"driver-btm-c5.c",0x14d1,DAT_00031964,uVar5);
      }
      fclose(__stream);
    }
  }
LAB_00031824:
  set_BC_command_buffer(&local_824);
  uVar3 = get_BC_write_command();
  set_BC_write_command(uVar3 & 0xfff0ffff | param_1 << 0x10 | 0x80800000U);
  return;
}

