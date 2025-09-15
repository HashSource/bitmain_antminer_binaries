
void read_asic_register(uchar chain,uchar mode,uchar chip_addr,uchar reg_addr)

{
  uchar uVar1;
  FILE *pFVar2;
  uint uVar3;
  int iVar4;
  uchar reg_addr_local;
  uchar chip_addr_local;
  uchar mode_local;
  uchar chain_local;
  uint cmd_buf [3];
  uchar buf [5];
  FILE *pFile;
  uint value;
  FILE *pFile_2;
  uint ret;
  FILE *pFile_1;
  int wait_count;
  
  buf[4] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  wait_count = 0;
  if (opt_multi_version == 0) {
    buf[1] = chip_addr;
    buf[0] = '\x02';
    buf[2] = reg_addr;
    buf[3] = '\0';
    if (mode != '\0') {
      buf._0_4_ = CONCAT31((uint3)buf._0_3_ >> 8,2) | 0x80;
    }
    uVar1 = CRC5(buf,'\x1b');
    buf[3] = uVar1;
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n","asic.c",
                0x3c4,"read_asic_register",buf._0_4_ & 0xff,(uint)buf._0_4_ >> 8 & 0xff,
                (uint)buf._0_4_ >> 0x10 & 0xff,(uint)buf._0_4_ >> 0x18);
      }
      fclose(pFVar2);
    }
    cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18
    ;
    set_BC_command_buffer(cmd_buf);
    uVar3 = get_BC_write_command();
    set_BC_write_command(uVar3 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  else {
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
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,
                "%s:%d:%s: VIL buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x, buf[4]=0x%x\n",
                "asic.c",0x3d6,"read_asic_register",buf._0_4_ & 0xff,(uint)buf._0_4_ >> 8 & 0xff,
                (uint)buf._0_4_ >> 0x10 & 0xff,(uint)buf._0_4_ >> 0x18,(uint)buf[4]);
      }
      fclose(pFVar2);
    }
    cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                 buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 | (uint)buf._0_4_ >> 0x18
    ;
    cmd_buf[1] = (uint)buf[4] << 0x18;
    do {
      iVar4 = get_BC_write_command();
      if (-1 < iVar4) goto LAB_00014154;
      cgsleep_ms(1);
      wait_count = wait_count + 1;
    } while (wait_count < 0xbb9);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        iVar4 = get_hash_on_plug();
        fprintf(pFVar2,"%s:%d:%s: Error: clement debug: wait BC ready timeout, PLUG ON=0x%08x..\n",
                "asic.c",0x3e5,"read_asic_register",iVar4);
      }
      fclose(pFVar2);
    }
LAB_00014154:
    set_BC_command_buffer(cmd_buf);
    uVar3 = get_BC_write_command();
    set_BC_write_command(uVar3 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
  }
  return;
}

