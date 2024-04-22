
void set_reset_hashboard(int chainIndex,int resetBit)

{
  uint uVar1;
  FILE *__stream;
  int resetBit_local;
  int chainIndex_local;
  FILE *pFile;
  uint resetFlag;
  uint ret;
  
  uVar1 = 1 << (chainIndex & 0xffU);
  if (resetBit < 1) {
    ret = ~uVar1 & axi_fpga_addr[0xd];
  }
  else {
    ret = axi_fpga_addr[0xd] | uVar1;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: set_reset_hashboard = 0x%08x\n","zynq.c",0xbf,
              "set_reset_hashboard",ret);
    }
    fclose(__stream);
  }
  axi_fpga_addr[0xd] = ret;
  return;
}

