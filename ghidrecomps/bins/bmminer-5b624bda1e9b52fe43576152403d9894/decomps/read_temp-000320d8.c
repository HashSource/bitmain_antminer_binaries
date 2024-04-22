
/* WARNING: Unknown calling convention */
/* Local variable i:uint[Stack[0x4]:4] conflicts with parameter, skipped. */

void read_temp(uchar device,uint reg,uchar data,uchar write,uchar chip_addr,int chain)

{
  uint ret;
  uint uVar1;
  uchar buf [9];
  uint cmd_buf [3];
  
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
  if (*DAT_000321b0 == 0) {
    printf(DAT_000321b4);
  }
  else {
    buf[6] = (uchar)reg;
    buf[5] = write | device;
    uVar1 = (uint)buf[5];
    buf[2] = chip_addr;
    buf[3] = ' ';
    buf[4] = '\x01';
    buf[0] = 'H';
    buf[1] = '\t';
    buf[7] = data;
    buf[8] = CRC5(buf,'@');
    cmd_buf[2] = (uint)buf[8] << 0x18;
    cmd_buf[0] = (uint)chip_addr << 8 | 0x48090020;
    cmd_buf[1] = data | 0x1000000 | (reg & 0xff) << 8 | uVar1 << 0x10;
    while (uVar1 = get_BC_write_command(), (int)uVar1 < 0) {
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(chain << 0x10 | 0x80800000U | uVar1 & 0xfff0ffff);
  }
  return;
}

