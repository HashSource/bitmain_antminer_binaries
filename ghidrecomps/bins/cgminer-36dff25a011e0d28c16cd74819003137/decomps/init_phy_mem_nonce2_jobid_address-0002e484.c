
/* WARNING: Unknown calling convention */

void init_phy_mem_nonce2_jobid_address(void)

{
  FILE *pFVar1;
  sysinfo si;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  
  sysinfo((sysinfo *)&si);
  if (si.totalram < 0x3b9aca01) {
    if (si.totalram < 0x1dcd6501) {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0xf000000;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: Detect 256MB control board of XILINX\n","driver-btm-soc.c",
                  0x1b0f,"init_phy_mem_nonce2_jobid_address");
        }
        fclose(pFVar1);
      }
    }
    else {
      PHY_MEM_NONCE2_JOBID_ADDRESS = 0x1f000000;
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: Detect 512MB control board of XILINX\n","driver-btm-soc.c",
                  0x1b09,"init_phy_mem_nonce2_jobid_address");
        }
        fclose(pFVar1);
      }
    }
  }
  else {
    PHY_MEM_NONCE2_JOBID_ADDRESS = 0x3f000000;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: Detect 1GB control board of XILINX\n","driver-btm-soc.c",0x1b03,
                "init_phy_mem_nonce2_jobid_address");
      }
      fclose(pFVar1);
    }
  }
  return;
}

