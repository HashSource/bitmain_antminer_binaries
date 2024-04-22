
void set_baud_fpga(int baud)

{
  int iVar1;
  FILE *__stream;
  int iVar2;
  int baud_local;
  fpga_bt8d_t fpga_bt8d;
  FILE *pFile;
  int fpga_divider;
  
  iVar1 = get_bt8d_fpga_divider(baud);
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set fpga_baud = %d, fpga_divider = %d\n","chip1391.c",0x104,
              "set_baud_fpga",baud,iVar1);
    }
    fclose(__stream);
  }
  iVar2 = get_bt8d_control();
  fpga_bt8d.v._2_1_ = (undefined)((uint)iVar2 >> 0x10);
  fpga_bt8d.v._3_1_ = (undefined)((uint)iVar2 >> 0x18);
  fpga_bt8d.v._0_2_ = (undefined2)iVar2;
  fpga_bt8d.v._2_1_ = fpga_bt8d.v._2_1_ & 0xc0 | (byte)iVar1 & 0x3f;
  set_bt8d_control(fpga_bt8d.v);
  return;
}

