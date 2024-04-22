
/* WARNING: Unknown calling convention */

void init_miner_version(void)

{
  uint uVar1;
  FILE *__stream;
  FILE *pFile;
  int hardware_version;
  
  uVar1 = get_hardware_version();
  pcb_version = (int)uVar1 >> 0x10 & 0x7fff;
  fpga_version = uVar1 & 0xff;
  fpga_major_version = (int)uVar1 >> 8 & 0xff;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: FPGA Version = 0x%04X\n","driver-btm-soc.c",0x1b73,
              "init_miner_version",uVar1 & 0xffff);
    }
    fclose(__stream);
  }
  sprintf(g_miner_version,"%d.%d.%d.%d",(fpga_major_version + -0xb0) * 0x100 + fpga_version,
          pcb_version,1,3);
  return;
}

