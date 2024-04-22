
undefined4 znyq7010_axi_init(int *param_1)

{
  FILE *pFVar1;
  uint uVar2;
  
  fd = open("/dev/axi_fpga_dev",2);
  if (fd < 0) {
    if (1 < log_level) {
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: /dev/axi_fpga_dev open failed. fd = %d\n","znyq7010.c",0xda,
                DAT_0004c520,fd);
      }
      fclose(pFVar1);
    }
    goto LAB_0004c4c8;
  }
  axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,fd,0);
  if (axi_fpga_addr == (uint *)0x0) {
    if (log_level < 2) {
      return 0xffffffff;
    }
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n","znyq7010.c",0xe2
              ,DAT_0004c520,axi_fpga_addr);
    }
    goto LAB_0004c42c;
  }
  if (5 < log_level) {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: mmap axi_fpga_addr = 0x%x\n","znyq7010.c",0xe5,DAT_0004c520,
              axi_fpga_addr);
    }
    fclose(pFVar1);
    uVar2 = *axi_fpga_addr;
    if ((uVar2 & 0xffff) != 0xc501) {
      if (log_level < 6) goto LAB_0004c1c4;
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d:%s: data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",
                "znyq7010.c",0xeb,DAT_0004c520,uVar2,0xc501);
      }
      fclose(pFVar1);
    }
    if (5 < log_level) {
      pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: axi_fpga_addr data = 0x%x\n","znyq7010.c",0xee,DAT_0004c520,uVar2)
        ;
      }
      fclose(pFVar1);
    }
  }
LAB_0004c1c4:
  fd_fpga_mem = open("/dev/fpga_mem",2);
  if (-1 < fd_fpga_mem) {
    fpga_mem_addr = mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
    if (fpga_mem_addr != (void *)0x0) {
      if (log_level < 6) {
        job_start_address_1 = (int)fpga_mem_addr + 0x200000;
        job_start_address_2 = (int)fpga_mem_addr + 0x210000;
        nonce2_jobid_address = fpga_mem_addr;
      }
      else {
        pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: mmap fpga_mem_addr = 0x%x\n","znyq7010.c",0xfe,DAT_0004c520,
                  fpga_mem_addr);
        }
        fclose(pFVar1);
        job_start_address_1 = (int)fpga_mem_addr + 0x200000;
        job_start_address_2 = (int)fpga_mem_addr + 0x210000;
        nonce2_jobid_address = fpga_mem_addr;
        if (5 < log_level) {
          pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: job_start_address_1 = 0x%x\n","znyq7010.c",0x104,DAT_0004c520,
                    job_start_address_1);
          }
          fclose(pFVar1);
          if (5 < log_level) {
            pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: job_start_address_2 = 0x%x\n","znyq7010.c",0x105,
                      DAT_0004c520,job_start_address_2);
            }
            fclose(pFVar1);
          }
        }
      }
      set_nonce2_and_job_id_store_address(0x3f000000);
      set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
      *param_1 = job_start_address_1;
      return 0;
    }
    if (log_level < 6) {
      return 0xffffffff;
    }
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n","znyq7010.c",0xfb
              ,DAT_0004c520,fpga_mem_addr);
    }
LAB_0004c42c:
    fclose(pFVar1);
    return 0xffffffff;
  }
  if (5 < log_level) {
    pFVar1 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: /dev/fpga_mem open failed. fd_fpga_mem = %d\n","znyq7010.c",0xf3,
              DAT_0004c520,fd_fpga_mem);
    }
    fclose(pFVar1);
  }
LAB_0004c4c8:
  perror("open");
  return 0xffffffff;
}

