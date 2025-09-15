
/* WARNING: Unknown calling convention */

int bitmain_axi_init(void)

{
  FILE *pFVar1;
  uint uVar2;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_5;
  FILE *pFile_6;
  FILE *pFile_10;
  FILE *pFile_11;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  FILE *pFile_4;
  FILE *pFile_3;
  uint data;
  FILE *pFile_2;
  int ret;
  
  ret = 0;
  fd = open("/dev/axi_fpga_dev",2);
  if (fd < 0) {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: /dev/axi_fpga_dev open failed. fd = %d\n","driver-btm-soc.c",0x4d7
                ,"bitmain_axi_init",fd);
      }
      fclose(pFVar1);
    }
    perror("open");
    ret = -1;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,fd,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: mmap axi_fpga_addr failed. axi_fpga_addr = %p\n",
                  "driver-btm-soc.c",0x4df,"bitmain_axi_init",axi_fpga_addr);
        }
        fclose(pFVar1);
      }
      ret = -1;
    }
    else {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: mmap axi_fpga_addr = %p\n","driver-btm-soc.c",0x4e2,
                  "bitmain_axi_init",axi_fpga_addr);
        }
        fclose(pFVar1);
      }
      uVar2 = *axi_fpga_addr;
      if (((uVar2 & 0xffff) != 0xc501) && (4 < log_level)) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,
                  "%s:%d:%s: data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",
                  "driver-btm-soc.c",0x4e8,"bitmain_axi_init",uVar2,0xc501);
        }
        fclose(pFVar1);
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: axi_fpga_addr data = 0x%x\n","driver-btm-soc.c",0x4eb,
                  "bitmain_axi_init",uVar2);
        }
        fclose(pFVar1);
      }
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar1 = fopen(log_file,"a+");
          if (pFVar1 != (FILE *)0x0) {
            fprintf(pFVar1,"%s:%d:%s: /dev/fpga_mem open failed. fd_fpga_mem = %d\n",
                    "driver-btm-soc.c",0x4f0,"bitmain_axi_init",fd_fpga_mem);
          }
          fclose(pFVar1);
        }
        perror("open");
        ret = -1;
      }
      else {
        fpga_mem_addr = (uint *)mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (uint *)0x0) {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: mmap fpga_mem_addr failed. fpga_mem_addr = %p\n",
                      "driver-btm-soc.c",0x4f8,"bitmain_axi_init",fpga_mem_addr);
            }
            fclose(pFVar1);
          }
          ret = -1;
        }
        else {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: mmap fpga_mem_addr = %p\n","driver-btm-soc.c",0x4fb,
                      "bitmain_axi_init",fpga_mem_addr);
            }
            fclose(pFVar1);
          }
          nonce2_jobid_address = fpga_mem_addr;
          job_start_address_1 = fpga_mem_addr + 0x80000;
          job_start_address_2 = fpga_mem_addr + 0x84000;
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: job_start_address_1 = %p\n","driver-btm-soc.c",0x501,
                      "bitmain_axi_init",job_start_address_1);
            }
            fclose(pFVar1);
          }
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,"%s:%d:%s: job_start_address_2 = %p\n","driver-btm-soc.c",0x502,
                      "bitmain_axi_init",job_start_address_2);
            }
            fclose(pFVar1);
          }
          set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
          set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
          dev = (all_parameters *)calloc(0x5518,1);
          if (dev == (all_parameters *)0x0) {
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"%s:%d:%s: kmalloc for dev failed.\n","driver-btm-soc.c",0x50a,
                        "bitmain_axi_init");
              }
              fclose(pFVar1);
            }
            ret = -1;
          }
          else {
            dev->current_job_start_address = job_start_address_1;
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar1 = fopen(log_file,"a+");
              if (pFVar1 != (FILE *)0x0) {
                fprintf(pFVar1,"%s:%d:%s: kmalloc for dev success.\n","driver-btm-soc.c",0x510,
                        "bitmain_axi_init");
              }
              fclose(pFVar1);
            }
          }
        }
      }
    }
  }
  return ret;
}

