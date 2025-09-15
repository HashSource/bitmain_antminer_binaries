
void chain_inactive(uchar chain)

{
  FILE *pFVar1;
  uint uVar2;
  uchar chain_local;
  uint cmd_buf [3];
  uchar buf [5];
  FILE *pFile;
  uint value;
  uint ret;
  FILE *pFile_1;
  
  buf[3] = '\0';
  buf[4] = '\x05';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  if (opt_multi_version == 0) {
    buf[0] = 0x83;
    buf[1] = '\0';
    buf[2] = '\0';
    buf[3] = CRC5(buf,'\x1b');
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n","asic.c",
                0x1e6,"chain_inactive",(uint)buf[0],(uint)buf[1],(uint)buf[2],(uint)buf[3]);
      }
      fclose(pFVar1);
    }
    cmd_buf[0] = (uint)buf[2] << 8 | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[3];
    set_BC_command_buffer(cmd_buf);
    uVar2 = get_BC_write_command();
    set_BC_write_command(uVar2 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  else {
    buf[0] = 'S';
    buf[1] = '\x05';
    buf[2] = '\0';
    buf[3] = '\0';
    buf[4] = CRC5(buf,' ');
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x\n"
                ,"asic.c",0x1f6,"chain_inactive",(uint)buf[0],(uint)buf[1],(uint)buf[2],(uint)buf[3]
                ,(uint)buf[4]);
      }
      fclose(pFVar1);
    }
    cmd_buf[0] = (uint)buf[2] << 8 | (uint)buf[0] << 0x18 | (uint)buf[1] << 0x10 | (uint)buf[3];
    cmd_buf[1] = (uint)buf[4] << 0x18;
    while( true ) {
      uVar2 = get_BC_write_command();
      if (-1 < (int)uVar2) break;
      cgsleep_ms(1);
    }
    set_BC_command_buffer(cmd_buf);
    set_BC_write_command(uVar2 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  return;
}

