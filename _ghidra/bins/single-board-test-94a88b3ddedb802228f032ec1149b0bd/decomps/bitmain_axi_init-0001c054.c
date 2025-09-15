
undefined4 bitmain_axi_init(void)

{
  FILE *pFVar1;
  undefined4 uVar2;
  uint uVar3;
  
  cgpu._600_4_ = open("/dev/axi_fpga_dev",2);
  if ((int)cgpu._600_4_ < 0) {
    if (3 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: /dev/axi_fpga_dev open failed. fd = %d\n","driver-bitmain.c",0x6e6,
                cgpu._600_4_);
      }
      fclose(pFVar1);
    }
    perror("open");
    uVar2 = 0xffffffff;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,cgpu._600_4_,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n",
                  "driver-bitmain.c",0x6ee,axi_fpga_addr);
        }
        fclose(pFVar1);
      }
      uVar2 = 0xffffffff;
    }
    else {
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: mmap axi_fpga_addr = 0x%x\n","driver-bitmain.c",0x6f1,axi_fpga_addr
                 );
        }
        fclose(pFVar1);
      }
      uVar3 = *axi_fpga_addr;
      if (3 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: axi_fpga_addr data = 0x%x\n","driver-bitmain.c",0x6f6,
                  uVar3 & 0xffff);
        }
        fclose(pFVar1);
      }
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        if (3 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d: /dev/fpga_mem open failed. fd_fpga_mem = %d\n","driver-bitmain.c"
                    ,0x6fb,fd_fpga_mem);
          }
          fclose(pFVar1);
        }
        perror("open");
        uVar2 = 0xffffffff;
      }
      else {
        fpga_mem_addr = mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (void *)0x0) {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d: mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n",
                      "driver-bitmain.c",0x703,fpga_mem_addr);
            }
            fclose(pFVar1);
          }
          uVar2 = 0xffffffff;
        }
        else {
          if (3 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d: mmap fpga_mem_addr = 0x%x\n","driver-bitmain.c",0x706,
                      fpga_mem_addr);
            }
            fclose(pFVar1);
          }
          nonce2_jobid_address = fpga_mem_addr;
          set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
          reg_value_buf = malloc(0x1020);
          if (reg_value_buf == (void *)0x0) {
            if (3 < log_level) {
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"%s:%d: %s: malloc reg_value_buf failed\n","driver-bitmain.c",0x710,
                        "bitmain_axi_init");
              }
              fclose(pFVar1);
            }
            uVar2 = 0xfffffffc;
          }
          else {
            memset(reg_value_buf,0,0x1020);
            uVar2 = 0;
          }
        }
      }
    }
  }
  return uVar2;
}

