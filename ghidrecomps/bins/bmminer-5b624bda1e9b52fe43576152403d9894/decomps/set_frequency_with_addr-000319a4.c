
/* WARNING: Unknown calling convention */

void set_frequency_with_addr(ushort frequency,uchar mode,uchar addr,uchar chain)

{
  byte bVar1;
  ushort uVar2;
  char *pcVar3;
  byte bVar4;
  byte bVar5;
  uint *type;
  uint uVar6;
  uint ret;
  uint uVar7;
  int i;
  uint uVar8;
  uint uVar9;
  uint *in_stack_fffff7a8;
  undefined4 in_stack_fffff7ac;
  uint16_t reg_data_pll2;
  uint reg_data_pll;
  uint reg_data_vil;
  uchar buf [9];
  uint cmd_buf [3];
  char tmp42 [2048];
  
  pcVar3 = DAT_00031c3c;
  uVar7 = (uint)chain;
  type = (uint *)(uint)frequency;
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
  if ((*DAT_00031c3c != '\0') &&
     (((*DAT_00031c40 != '\0' || (*DAT_00031c44 != '\0')) || (6 < *DAT_00031c5c)))) {
    snprintf(tmp42,0x800,DAT_00031c48,DAT_00031c4c);
    _applog(7,tmp42,false);
  }
  get_plldata((int)type,(int)&reg_data_pll,(uint *)&reg_data_pll2,(uint16_t *)&reg_data_vil,
              in_stack_fffff7a8);
  if ((*pcVar3 != '\0') &&
     (((*DAT_00031c40 != '\0' || (*DAT_00031c44 != '\0')) || (6 < *DAT_00031c5c)))) {
    snprintf(tmp42,0x800,DAT_00031c50,DAT_00031c4c);
    _applog(7,tmp42,false);
    in_stack_fffff7a8 = type;
  }
  uVar6 = reg_data_vil;
  uVar8 = *DAT_00031c54;
  if (uVar8 == 0) {
    uVar6 = reg_data_pll & 0xff;
    bVar1 = (byte)(reg_data_pll >> 8);
    bVar5 = (byte)(reg_data_pll >> 0x10);
    buf[1] = bVar5;
    buf[0] = '\a';
    buf[2] = bVar1;
    buf[3] = (uchar)reg_data_pll;
    buf[8] = '\0';
    buf._4_4_ = uVar8;
    cmd_buf[0] = uVar8;
    cmd_buf[1] = uVar8;
    cmd_buf[2] = uVar8;
    bVar4 = CRC5(buf,'\x1b');
    uVar6 = bVar4 | uVar6;
    cmd_buf[0] = (uint)bVar1 << 8 | (uint)bVar5 << 0x10 | 0x7000000 | uVar6;
    buf[3] = (uchar)uVar6;
    set_BC_command_buffer(cmd_buf);
    uVar9 = uVar7 << 0x10 | 0x80800000;
    uVar6 = get_BC_write_command();
    set_BC_write_command(uVar6 & 0xfff0ffff | uVar9);
    cgsleep_us(CONCAT44(in_stack_fffff7ac,in_stack_fffff7a8));
    buf[8] = '\0';
    uVar2 = reg_data_pll2 >> 8;
    bVar1 = (byte)reg_data_pll2;
    buf[2] = (uchar)(reg_data_pll2 >> 8);
    buf[0] = 0x82;
    buf[1] = '\0';
    buf[3] = bVar1;
    buf._4_4_ = uVar8;
    cmd_buf[0] = uVar8;
    cmd_buf[1] = uVar8;
    cmd_buf[2] = uVar8;
    bVar5 = CRC5(buf,'\x1b');
    bVar5 = bVar5 | bVar1;
    buf[3] = bVar5;
    cmd_buf[0] = CONCAT21(uVar2,bVar5) | 0x82000000;
    set_BC_command_buffer(cmd_buf);
    uVar6 = get_BC_write_command();
    set_BC_write_command(uVar6 & 0xfff0ffff | uVar9);
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
    uVar8 = reg_data_vil & 0xff;
    bVar1 = (byte)(reg_data_vil >> 0x10);
    buf._4_2_ = CONCAT11(bVar1,(uchar)(reg_data_vil >> 0x18));
    bVar5 = (byte)(reg_data_vil >> 8);
    buf[7] = (uchar)reg_data_vil;
    buf._4_3_ = CONCAT12(bVar5,buf._4_2_);
    buf[2] = addr;
    buf[3] = '\f';
    buf[8] = CRC5(buf,'@');
    cmd_buf[2] = (uint)buf[8] << 0x18;
    cmd_buf[1] = uVar8 | (uint)bVar1 << 0x10 | uVar6 & 0xff000000 | (uint)bVar5 << 8;
    cmd_buf[0] = buf._0_4_ << 0x18 | 0x9000c | (uint)addr << 8;
    set_BC_command_buffer(cmd_buf);
    uVar6 = get_BC_write_command();
    set_BC_write_command(uVar6 & 0xfff0ffff | uVar7 << 0x10 | 0x80800000);
  }
  *(ushort *)(*DAT_00031c58 + (uVar7 + 0x17fc) * 2 + 2) = frequency;
  cgsleep_us(CONCAT44(in_stack_fffff7ac,in_stack_fffff7a8));
  return;
}

