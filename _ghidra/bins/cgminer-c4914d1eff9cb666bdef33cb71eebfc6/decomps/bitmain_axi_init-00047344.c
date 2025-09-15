
/* WARNING: Unknown calling convention */

int bitmain_axi_init(void)

{
  int iVar1;
  FILE *pFVar2;
  int __fd;
  uint uVar3;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_5;
  FILE *pFile_6;
  FILE *pFile_10;
  FILE *pFile_11;
  FILE *pFile_9;
  FILE *pFile_8;
  FILE *pFile_7;
  int fd_fpga_mem;
  FILE *pFile_4;
  FILE *pFile_3;
  uint data;
  FILE *pFile_2;
  int fd;
  int ret;
  
  iVar1 = open("/dev/axi_fpga_dev",2);
  if (iVar1 < 0) {
    if (4 < log_level) {
      print_crt_time_to_file(log_file,4);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: /dev/axi_fpga_dev open failed. fd = %d\n","zynq.c",0x30c,
                "bitmain_axi_init",iVar1);
      }
      fclose(pFVar2);
    }
    perror("open");
    iVar1 = -1;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,iVar1,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n","zynq.c",
                  0x314,"bitmain_axi_init",axi_fpga_addr);
        }
        fclose(pFVar2);
      }
      iVar1 = -1;
    }
    else {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: mmap axi_fpga_addr = 0x%x\n","zynq.c",0x317,"bitmain_axi_init",
                  axi_fpga_addr);
        }
        fclose(pFVar2);
      }
      uVar3 = *axi_fpga_addr;
      if (((uVar3 & 0xffff) != 0xc501) && (4 < log_level)) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,
                  "%s:%d:%s: data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",
                  "zynq.c",0x31d,"bitmain_axi_init",uVar3,0xc501);
        }
        fclose(pFVar2);
      }
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: axi_fpga_addr data = 0x%x\n","zynq.c",800,"bitmain_axi_init",
                  uVar3);
        }
        fclose(pFVar2);
      }
      __fd = open("/dev/fpga_mem",2);
      if (__fd < 0) {
        if (4 < log_level) {
          print_crt_time_to_file(log_file,4);
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: /dev/fpga_mem open failed. fd_fpga_mem = %d\n","zynq.c",0x325,
                    "bitmain_axi_init",__fd);
          }
          fclose(pFVar2);
        }
        perror("open");
        iVar1 = -1;
      }
      else {
        fpga_mem_addr = (uint *)mmap((void *)0x0,0x1000000,3,1,__fd,0);
        if (fpga_mem_addr == (uint *)0x0) {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n","zynq.c",
                      0x32d,"bitmain_axi_init",fpga_mem_addr);
            }
            fclose(pFVar2);
          }
          iVar1 = -1;
        }
        else {
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: mmap fpga_mem_addr = 0x%x\n","zynq.c",0x330,
                      "bitmain_axi_init",fpga_mem_addr);
            }
            fclose(pFVar2);
          }
          nonce2_jobid_address = fpga_mem_addr;
          job_start_address_1 = fpga_mem_addr + 0x80000;
          job_start_address_2 = fpga_mem_addr + 0x84000;
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: job_start_address_1 = 0x%x\n","zynq.c",0x336,
                      "bitmain_axi_init",job_start_address_1);
            }
            fclose(pFVar2);
          }
          if (4 < log_level) {
            print_crt_time_to_file(log_file,4);
            pFVar2 = fopen(log_file,"a+");
            if (pFVar2 != (FILE *)0x0) {
              fprintf(pFVar2,"%s:%d:%s: job_start_address_2 = 0x%x\n","zynq.c",0x337,
                      "bitmain_axi_init",job_start_address_2);
            }
            fclose(pFVar2);
          }
          set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
          set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
          dev = (all_parameters *)calloc(0x534c,1);
          if (dev == (all_parameters *)0x0) {
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fprintf(pFVar2,"%s:%d:%s: kmalloc for dev failed.\n","zynq.c",0x33f,
                        "bitmain_axi_init");
              }
              fclose(pFVar2);
            }
            iVar1 = -1;
          }
          else {
            dev->current_job_start_address = job_start_address_1;
            if (4 < log_level) {
              print_crt_time_to_file(log_file,4);
              pFVar2 = fopen(log_file,"a+");
              if (pFVar2 != (FILE *)0x0) {
                fprintf(pFVar2,"%s:%d:%s: kmalloc for dev success.\n","zynq.c",0x345,
                        "bitmain_axi_init");
              }
              fclose(pFVar2);
            }
            close(iVar1);
            close(__fd);
            iVar1 = 0;
          }
        }
      }
    }
  }
  return iVar1;
}

