
void read_asic_register(uchar chain,uchar mode,uchar chip_addr,uchar reg_addr)

{
  FILE *pFVar1;
  int iVar2;
  uint uVar3;
  uchar reg_addr_local;
  uchar chip_addr_local;
  uchar mode_local;
  uchar chain_local;
  uint cmd_buf [3];
  uchar buf [5];
  uint value;
  FILE *pFile_1;
  uint ret;
  FILE *pFile;
  int wait_count;
  
  buf[4] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  wait_count = 0;
  buf[0] = 'B';
  if (mode != '\0') {
    buf[0] = 'R';
  }
  buf[1] = '\x05';
  buf[2] = chip_addr;
  buf[3] = reg_addr;
  buf[4] = CRC5(buf,' ');
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,
              "%s:%d:%s: VIL buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x\n",
              "chip1391.c",0x17a,"read_asic_register",buf._0_4_ & 0xff,(uint)buf._0_4_ >> 8 & 0xff,
              (uint)buf._0_4_ >> 0x10 & 0xff,(uint)buf._0_4_ >> 0x18,(uint)buf[4]);
    }
    fclose(pFVar1);
  }
  cmd_buf[0] = buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
               ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 | (uint)buf._0_4_ >> 0x18;
  cmd_buf[1] = (uint)buf[4] << 0x18;
  do {
    iVar2 = get_BC_write_command();
    if (-1 < iVar2) goto LAB_00078ccc;
    cgsleep_ms(1);
    wait_count = wait_count + 1;
  } while (wait_count < 0xbb9);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      iVar2 = get_hash_on_plug();
      fprintf(pFVar1,"%s:%d:%s: Error: clement debug: wait BC ready timeout, PLUG ON=0x%08x..\n",
              "chip1391.c",0x18c,"read_asic_register",iVar2);
    }
    fclose(pFVar1);
  }
LAB_00078ccc:
  set_BC_command_buffer(cmd_buf);
  uVar3 = get_BC_write_command();
  set_BC_write_command((uint)chain << 0x10 | uVar3 & 0xfff0ffff | 0x80800000);
  return;
}

