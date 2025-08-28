
/* WARNING: Unknown calling convention */

void set_frequency_with_addr(ushort frequency,uchar mode,uchar addr,uchar chain)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *in_stack_fffff7a8;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  uint reg_data_vil;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  uVar8 = (uint)chain;
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  reg_data_pll = 0;
  reg_data_pll2 = 0;
  reg_data_vil = 0;
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"\n--- %s\n","set_frequency_with_addr");
    _applog(7,tmp42,false);
  }
  get_plldata((uint)frequency,(int)&reg_data_pll,(uint *)&reg_data_pll2,(uint16_t *)&reg_data_vil,
              in_stack_fffff7a8);
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: frequency = %d\n","set_frequency_with_addr",(uint)frequency);
    _applog(7,tmp42,false);
  }
  uVar7 = reg_data_vil;
  iVar3 = opt_multi_version;
  if (opt_multi_version == 0) {
    buf[4] = (undefined1)opt_multi_version;
    buf[5] = opt_multi_version._1_1_;
    buf[6] = opt_multi_version._2_1_;
    buf[7] = opt_multi_version._3_1_;
    uVar7 = reg_data_pll & 0xff;
    cmd_buf[1] = opt_multi_version;
    bVar1 = (byte)(reg_data_pll >> 8);
    bVar6 = (byte)(reg_data_pll >> 0x10);
    buf[1] = bVar6;
    buf[0] = '\a';
    buf[2] = bVar1;
    buf[3] = (uchar)reg_data_pll;
    cmd_buf[0] = opt_multi_version;
    buf[8] = '\0';
    cmd_buf[2] = opt_multi_version;
    bVar5 = CRC5(buf,'\x1b');
    uVar7 = bVar5 | uVar7;
    cmd_buf[0] = (uint)bVar1 << 8 | (uint)bVar6 << 0x10 | 0x7000000 | uVar7;
    buf[3] = (uchar)uVar7;
    set_BC_command_buffer(cmd_buf);
    uVar9 = uVar8 << 0x10 | 0x80800000;
    uVar7 = get_BC_write_command();
    set_BC_write_command(uVar7 & 0xfff0ffff | uVar9);
    cgsleep_us(3000);
    iVar4 = opt_multi_version;
    buf[8] = '\0';
    cmd_buf[2] = iVar3;
    uVar2 = reg_data_pll2 >> 8;
    bVar1 = (byte)reg_data_pll2;
    buf[2] = (uchar)(reg_data_pll2 >> 8);
    buf[0] = 0x82;
    buf[1] = '\0';
    buf[3] = bVar1;
    cmd_buf[0] = iVar3;
    opt_multi_version._0_1_ = (undefined1)iVar3;
    opt_multi_version._1_1_ = SUB41(iVar3,1);
    opt_multi_version._2_1_ = SUB41(iVar3,2);
    opt_multi_version._3_1_ = SUB41(iVar3,3);
    buf[4] = (undefined1)opt_multi_version;
    buf[5] = opt_multi_version._1_1_;
    buf[6] = opt_multi_version._2_1_;
    buf[7] = opt_multi_version._3_1_;
    cmd_buf[1] = iVar3;
    opt_multi_version = iVar4;
    bVar6 = CRC5(buf,'\x1b');
    bVar6 = bVar6 | bVar1;
    buf[3] = bVar6;
    cmd_buf[0] = CONCAT21(uVar2,bVar6) | 0x82000000;
    set_BC_command_buffer(cmd_buf);
    uVar7 = get_BC_write_command();
    set_BC_write_command(uVar7 & 0xfff0ffff | uVar9);
    uVar7 = 5000;
  }
  else {
    cmd_buf[1] = 0;
    cmd_buf[0] = 0;
    buf[8] = '\0';
    cmd_buf[2] = 0;
    if (mode == '\0') {
      buf[0] = 'H';
    }
    else {
      buf[0] = 'X';
    }
    buf[1] = '\t';
    uVar9 = reg_data_vil & 0xff;
    bVar1 = (byte)(reg_data_vil >> 0x10);
    buf[5] = bVar1;
    buf[4] = (uchar)(reg_data_vil >> 0x18);
    bVar6 = (byte)(reg_data_vil >> 8);
    buf[7] = (uchar)reg_data_vil;
    buf[6] = bVar6;
    buf[2] = addr;
    buf[3] = '\f';
    buf[8] = CRC5(buf,'@');
    cmd_buf[2] = (uint)buf[8] << 0x18;
    cmd_buf[1] = uVar9 | (uint)bVar1 << 0x10 | uVar7 & 0xff000000 | (uint)bVar6 << 8;
    cmd_buf[0] = buf._0_4_ << 0x18 | 0x9000c | (uint)addr << 8;
    set_BC_command_buffer(cmd_buf);
    uVar7 = get_BC_write_command();
    set_BC_write_command(uVar7 & 0xfff0ffff | uVar8 << 0x10 | 0x80800000);
    uVar7 = 10000;
  }
  dev->freq[uVar8] = frequency;
  cgsleep_us((ulonglong)uVar7);
  return;
}

