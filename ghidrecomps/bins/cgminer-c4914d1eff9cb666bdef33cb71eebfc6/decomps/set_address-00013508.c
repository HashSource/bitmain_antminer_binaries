
void set_address(uchar chain,uchar mode,uchar address)

{
  uchar uVar1;
  byte bVar2;
  FILE *__stream;
  uint uVar3;
  uchar address_local;
  uchar mode_local;
  uchar chain_local;
  uint cmd_buf [3];
  uchar buf [9];
  FILE *pFile;
  uint value;
  uint ret;
  
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (opt_multi_version == 0) {
    buf._0_4_ = (uint)address << 8;
    if (mode != '\0') {
      buf[2] = '\0';
      buf[3] = '\0';
      buf[1] = address;
      buf[0] = 0x80;
    }
    uVar1 = CRC5(buf,'\x1b');
    buf[3] = uVar1;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n","asic.c",
                0x215,"set_address",buf._0_4_ & 0xff,(uint)buf._0_4_ >> 8 & 0xff,
                (uint)buf._0_4_ >> 0x10 & 0xff,(uint)buf._0_4_ >> 0x18);
      }
      fclose(__stream);
    }
    cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18
    ;
    set_BC_command_buffer(cmd_buf);
    uVar3 = get_BC_write_command();
    set_BC_write_command(uVar3 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  else {
    buf[2] = address;
    buf[0] = '@';
    buf[1] = '\x05';
    buf[3] = '\0';
    bVar2 = CRC5(buf,' ');
    buf[4] = bVar2;
    cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18
    ;
    cmd_buf[1] = (uint)bVar2 << 0x18;
    while( true ) {
      uVar3 = get_BC_write_command();
      if (-1 < (int)uVar3) break;
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(uVar3 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  return;
}

