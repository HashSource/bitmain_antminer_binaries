
void set_baud_one_chain(int baud,int change_fpga_baud,uchar chain)

{
  misc_ctrl_t mVar1;
  int iVar2;
  FILE *__stream;
  undefined4 in_stack_ffffffcc;
  uchar chain_local;
  int change_fpga_baud_local;
  int baud_local;
  misc_ctrl_t misc_reg;
  FILE *pFile;
  int chip_divider;
  
  if (dev->chain_exist[chain] != 0) {
    iVar2 = get_bt8d_chip_divider(baud);
    misc_reg.v._1_1_ = (undefined)(gBM1391_MISC_CONTROL_reg >> 8);
    misc_reg.v._2_2_ = (undefined2)(gBM1391_MISC_CONTROL_reg >> 0x10);
    misc_reg.v._0_1_ = (undefined)gBM1391_MISC_CONTROL_reg;
    misc_reg.v._1_1_ = misc_reg.v._1_1_ & 0xe0 | (byte)iVar2 & 0x1f;
    mVar1 = misc_reg;
    misc_reg.v._3_1_ = (undefined)(gBM1391_MISC_CONTROL_reg >> 0x18);
    misc_reg.v._3_1_ = misc_reg.v._3_1_ & 0xf0 | (byte)(iVar2 >> 5) & 0xf;
    misc_reg.v._0_3_ = (undefined3)mVar1.v;
    if (3000000 < baud) {
      set_baud_ext((uint)chain);
      misc_reg.v = CONCAT13(misc_reg.v._3_1_,misc_reg.v._0_3_) | 0x10000;
    }
    gBM1391_MISC_CONTROL_reg = misc_reg.v;
    send_set_config_command((uint)chain,'\x01','\0','\x18',misc_reg.v);
    if (change_fpga_baud != 0) {
      cgsleep_us(CONCAT44(in_stack_ffffffcc,misc_reg.v));
      set_baud_fpga(baud);
      dev->baud = baud;
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: chain[%d]: chip baud = %d, chip_divider = %d\n","chip1391.c",
                0x12f,"set_baud_one_chain",(uint)chain,baud,iVar2);
      }
      fclose(__stream);
    }
  }
  return;
}

