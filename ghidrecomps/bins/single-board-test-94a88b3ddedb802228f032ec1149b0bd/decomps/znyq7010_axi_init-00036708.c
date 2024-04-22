
undefined4 znyq7010_axi_init(int *param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  uint uVar3;
  
  fd = open("/dev/axi_fpga_dev",2);
  if (fd < 0) {
    if (1 < log_level) {
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d: /dev/axi_fpga_dev open failed. fd = %d\n","znyq7010.c",0xda,fd);
      }
      fclose(pFVar1);
    }
    perror("open");
    uVar2 = 0xffffffff;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,fd,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if (1 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n","znyq7010.c",
                  0xe2,axi_fpga_addr);
        }
        fclose(pFVar1);
      }
      uVar2 = 0xffffffff;
    }
    else {
      if (5 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: mmap axi_fpga_addr = 0x%x\n","znyq7010.c",0xe5,axi_fpga_addr);
        }
        fclose(pFVar1);
      }
      uVar3 = *axi_fpga_addr;
      if (((uVar3 & 0xffff) != 0xc501) && (5 < log_level)) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,
                  "%s:%d: data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",
                  "znyq7010.c",0xeb,uVar3,0xc501);
        }
        fclose(pFVar1);
      }
      if (5 < log_level) {
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d: axi_fpga_addr data = 0x%x\n","znyq7010.c",0xee,uVar3);
        }
        fclose(pFVar1);
      }
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        if (5 < log_level) {
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d: /dev/fpga_mem open failed. fd_fpga_mem = %d\n","znyq7010.c",0xf3,
                    fd_fpga_mem);
          }
          fclose(pFVar1);
        }
        perror("open");
        uVar2 = 0xffffffff;
      }
      else {
        fpga_mem_addr = mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (void *)0x0) {
          if (5 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d: mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n","znyq7010.c"
                      ,0xfb,fpga_mem_addr);
            }
            fclose(pFVar1);
          }
          uVar2 = 0xffffffff;
        }
        else {
          if (5 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d: mmap fpga_mem_addr = 0x%x\n","znyq7010.c",0xfe,fpga_mem_addr);
            }
            fclose(pFVar1);
          }
          nonce2_jobid_address = fpga_mem_addr;
          job_start_address_1 = (int)fpga_mem_addr + 0x200000;
          job_start_address_2 = (int)fpga_mem_addr + 0x210000;
          if (5 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d: job_start_address_1 = 0x%x\n","znyq7010.c",0x104,
                      job_start_address_1);
            }
            fclose(pFVar1);
          }
          if (5 < log_level) {
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d: job_start_address_2 = 0x%x\n","znyq7010.c",0x105,
                      job_start_address_2);
            }
            fclose(pFVar1);
          }
          set_nonce2_and_job_id_store_address(0x3f000000);
          set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
          *param_1 = job_start_address_1;
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}

