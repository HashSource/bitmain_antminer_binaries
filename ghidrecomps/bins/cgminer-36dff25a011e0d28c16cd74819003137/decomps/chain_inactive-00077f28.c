
void chain_inactive(uchar chain)

{
  FILE *__stream;
  uint uVar1;
  uchar chain_local;
  uint cmd_buf [3];
  uchar buf [5];
  uint value;
  uint ret;
  FILE *pFile;
  
  buf[4] = '\x05';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  buf[0] = 'S';
  buf[1] = '\x05';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = CRC5(buf,' ');
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x\n"
              ,"chip1391.c",0x60,"chain_inactive",(uint)buf[0],(uint)buf[1],(uint)buf[2],
              (uint)buf[3],(uint)buf[4]);
    }
    fclose(__stream);
  }
  cmd_buf[0] = (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[2] << 8 | (uint)buf[3];
  cmd_buf[1] = (uint)buf[4] << 0x18;
  while( true ) {
    uVar1 = get_BC_write_command();
    if (-1 < (int)uVar1) break;
    cgsleep_ms(1);
  }
  set_BC_command_buffer(cmd_buf);
  set_BC_write_command((uint)chain << 0x10 | uVar1 & 0xfff0ffff | 0x80800000);
  return;
}

