
int set_frequency_with_addr(uint frequency,uchar mode,uchar addr,uchar chain)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *vil_data;
  undefined4 in_stack_fffff7a4;
  uchar chain_local;
  uchar addr_local;
  uchar mode_local;
  uint frequency_local;
  char tmp42 [2048];
  uint reg_data_vil;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  uint cmd_buf [3];
  uchar buf [9];
  uint value;
  uint ret;
  int i;
  uint pll_index;
  uint pll;
  uchar divider;
  int high_index;
  
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
  uVar6 = (uint)chain;
  iVar5 = get_index_from_high_pll(frequency);
  bVar1 = freq_high_pll_1393[iVar5].divider;
  uVar7 = freq_high_pll_1393[iVar5].pll_out;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"set freq %d, pll_out %d\n",freq_high_pll_1393[iVar5].freq,uVar7);
    _applog(5,tmp42,false);
  }
  get_pll_index(uVar7);
  uVar7 = freq_high_pll_1393[iVar5].freq;
  vil_data = &reg_data_vil;
  get_plldata(0x571,uVar7,&reg_data_pll,&reg_data_pll2,vil_data);
  uVar3 = (ushort)uVar7;
  if (opt_multi_version == 0) {
    memset(buf,0,9);
    memset(cmd_buf,0,0xc);
    buf[0] = '\a';
    buf[1] = (uchar)(reg_data_pll >> 0x10);
    buf[2] = (uchar)(reg_data_pll >> 8);
    bVar2 = (byte)reg_data_pll;
    buf[3] = bVar2;
    bVar4 = CRC5(buf,'\x1b');
    buf[3] = bVar4 | bVar2;
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    set_BC_command_buffer(cmd_buf);
    uVar7 = get_BC_write_command();
    set_BC_write_command(uVar7 & 0xfff0ffff | uVar6 << 0x10 | 0x80800000);
    cgsleep_us(CONCAT44(in_stack_fffff7a4,vil_data));
    memset(buf,0,9);
    memset(cmd_buf,0,0xc);
    buf[0] = 0x82;
    buf[1] = '\0';
    buf[2] = (uchar)(reg_data_pll2 >> 8);
    bVar2 = (byte)reg_data_pll2;
    buf[3] = bVar2;
    bVar4 = CRC5(buf,'\x1b');
    buf[3] = bVar4 | bVar2;
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    set_BC_command_buffer(cmd_buf);
    uVar7 = get_BC_write_command();
    set_BC_write_command(uVar7 & 0xfff0ffff | uVar6 << 0x10 | 0x80800000);
    dev->freq[uVar6] = uVar3;
    cgsleep_us(CONCAT44(in_stack_fffff7a4,vil_data));
  }
  else {
    memset(buf,0,9);
    memset(cmd_buf,0,0xc);
    if (mode == '\0') {
      buf[0] = 'A';
    }
    else {
      buf[0] = 'Q';
    }
    buf[1] = '\t';
    buf[3] = '\b';
    buf[4] = (uchar)(reg_data_vil >> 0x18);
    buf[5] = (uchar)(reg_data_vil >> 0x10);
    buf[6] = (uchar)(reg_data_vil >> 8);
    buf[7] = (uchar)reg_data_vil;
    buf[2] = addr;
    buf[8] = CRC5(buf,'@');
    cmd_buf[0] = (uint)buf[3] | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8;
    cmd_buf[1] = (uint)buf[7] | (uint)buf[4] << 0x18 | (uint)buf[5] << 0x10 | (uint)buf[6] << 8;
    cmd_buf[2] = (uint)buf[8] << 0x18;
    set_BC_command_buffer(cmd_buf);
    uVar7 = get_BC_write_command();
    set_BC_write_command(uVar7 & 0xfff0ffff | uVar6 << 0x10 | 0x80800000);
    dev->freq[uVar6] = uVar3;
    cgsleep_us(CONCAT44(in_stack_fffff7a4,vil_data));
  }
  return (uint)bVar1;
}

