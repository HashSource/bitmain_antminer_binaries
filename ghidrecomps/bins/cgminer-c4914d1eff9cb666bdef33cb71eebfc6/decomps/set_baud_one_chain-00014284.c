
void set_baud_one_chain(uchar bauddiv,int change_fpga_baud,uint8_t chain)

{
  uchar uVar1;
  byte bVar2;
  FILE *pFVar3;
  uint uVar4;
  char *in_stack_ffffffa0;
  uint in_stack_ffffffa4;
  int change_fpga_baud_local;
  uint8_t chain_local;
  uchar bauddiv_local;
  uint cmd_buf [4];
  uchar buf [10];
  FILE *pFile_3;
  FILE *pFile_2;
  FILE *pFile;
  uint value;
  uint ret;
  FILE *pFile_1;
  
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  cmd_buf[3] = 0;
  if (dev->chain_exist[chain] == 1) {
    if (opt_multi_version == 0) {
      buf._0_4_ = CONCAT12(bauddiv,0x1006) & 0xff1fffff;
      buf._0_4_ = buf._0_4_ | 0x80;
      uVar1 = CRC5(buf,'\x1b');
      buf[3] = uVar1;
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          in_stack_ffffffa4 = buf._0_4_ & 0xff;
          in_stack_ffffffa0 = "set_baud_one_chain";
          fprintf(pFVar3,"%s:%d:%s: buf[0]=0x%x, buf[1]=0x%x, buf[2]=0x%x, buf[3]=0x%x\n","asic.c",
                  0x44c,"set_baud_one_chain",in_stack_ffffffa4,(uint)buf._0_4_ >> 8 & 0xff,
                  (uint)buf._0_4_ >> 0x10 & 0xff,(uint)buf._0_4_ >> 0x18);
        }
        fclose(pFVar3);
      }
      cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                   buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                   (uint)buf._0_4_ >> 0x18;
      set_BC_command_buffer(cmd_buf);
      uVar4 = get_BC_write_command();
      set_BC_write_command(uVar4 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
    }
    else {
      uVar4 = gBM1393_MISC_CONTROL_reg & 0xffffe0ff;
      gBM1393_MISC_CONTROL_reg = uVar4 | (bauddiv & 0x1f) << 8;
      buf[0] = 'Q';
      buf[1] = '\t';
      buf[2] = '\0';
      buf[3] = '\x18';
      buf._4_2_ = CONCAT11((uchar)(uVar4 >> 0x10),(uchar)(uVar4 >> 0x18));
      buf._4_3_ = CONCAT12((uchar)(gBM1393_MISC_CONTROL_reg >> 8),buf._4_2_);
      buf[7] = (uchar)uVar4;
      bVar2 = CRC5(buf,'@');
      buf[8] = bVar2;
      cmd_buf[0] = ((uint)buf._0_4_ >> 0x10 & 0xff) << 8 |
                   buf._0_4_ << 0x18 | ((uint)buf._0_4_ >> 8 & 0xff) << 0x10 |
                   (uint)buf._0_4_ >> 0x18;
      cmd_buf[1] = ((uint)buf._4_4_ >> 0x10 & 0xff) << 8 |
                   buf._4_4_ << 0x18 | ((uint)buf._4_4_ >> 8 & 0xff) << 0x10 |
                   (uint)buf._4_4_ >> 0x18;
      cmd_buf[2] = (uint)bVar2 << 0x18;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          in_stack_ffffffa0 = "set_baud_one_chain";
          in_stack_ffffffa4 = cmd_buf[0];
          fprintf(pFVar3,"%s:%d:%s: cmd_buf[0]=0x%x, cmd_buf[1]=0x%x, cmd_buf[2]=0x%x, misc=0x%x\n",
                  "asic.c",0x466,"set_baud_one_chain",cmd_buf[0],cmd_buf[1],cmd_buf[2],
                  gBM1393_MISC_CONTROL_reg);
        }
        fclose(pFVar3);
      }
      set_BC_command_buffer(cmd_buf);
      uVar4 = get_BC_write_command();
      set_BC_write_command(uVar4 & 0xfff0ffff | (uint)chain << 0x10 | 0x80800000);
    }
    if (change_fpga_baud != 0) {
      cgsleep_us(CONCAT44(in_stack_ffffffa4,in_stack_ffffffa0));
      uVar4 = get_BC_write_command();
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: read bc write is 0x%0x\n","asic.c",0x473,"set_baud_one_chain",
                  uVar4);
        }
        fclose(pFVar3);
      }
      set_BC_write_command(bauddiv & 0x3f | uVar4 & 0xffffffc0);
      dev->baud = bauddiv;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar3 = fopen(log_file,"a+");
        if (pFVar3 != (FILE *)0x0) {
          fprintf(pFVar3,"%s:%d:%s: set baud %d\n","asic.c",0x478,"set_baud_one_chain",
                  (uint)dev->baud);
        }
        fclose(pFVar3);
      }
    }
  }
  return;
}

