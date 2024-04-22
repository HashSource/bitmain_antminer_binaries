
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

int bitmain_axi_init(void)

{
  uint uVar1;
  int iVar2;
  char tmp42 [2048];
  uint data;
  int ret;
  
  ret = 0;
  fd = open("/dev/axi_fpga_dev",2);
  if (fd < 0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"/dev/axi_fpga_dev open failed. fd = %d\n",fd);
      _applog(7,tmp42,false);
    }
    perror("open");
    ret = -1;
  }
  else {
    iVar2 = fd;
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,fd,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n",0);
        _applog(7,tmp42,false);
      }
      ret = -1;
    }
    else {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"mmap axi_fpga_addr = 0x%x\n",axi_fpga_addr);
        _applog(7,tmp42,false);
      }
      uVar1 = *axi_fpga_addr;
      if ((((uVar1 & 0xffff) != 0xc501) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        iVar2 = 0xc501;
        snprintf(tmp42,0x800,"data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",
                 uVar1,0xc501);
        _applog(7,tmp42,false);
      }
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"axi_fpga_addr data = 0x%x\n",uVar1,iVar2);
        _applog(7,tmp42,false);
      }
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"/dev/fpga_mem open failed. fd_fpga_mem = %d\n",fd_fpga_mem);
          _applog(7,tmp42,false);
        }
        perror("open");
        ret = -1;
      }
      else {
        fpga_mem_addr = (uint *)mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (uint *)0x0) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n",0);
            _applog(7,tmp42,false);
          }
          ret = -1;
        }
        else {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"mmap fpga_mem_addr = 0x%x\n",fpga_mem_addr);
            _applog(7,tmp42,false);
          }
          nonce2_jobid_address = fpga_mem_addr;
          job_start_address_1 = fpga_mem_addr + 0x80000;
          job_start_address_2 = fpga_mem_addr + 0x84000;
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"job_start_address_1 = 0x%x\n",job_start_address_1);
            _applog(7,tmp42,false);
          }
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"job_start_address_2 = 0x%x\n",job_start_address_2);
            _applog(7,tmp42,false);
          }
          set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
          set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
          dev = (all_parameters *)calloc(0x5478,1);
          if (dev == (all_parameters *)0x0) {
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              tmp42[0] = s_kmalloc_for_dev_failed__0007633c[0];
              tmp42[1] = s_kmalloc_for_dev_failed__0007633c[1];
              tmp42[2] = s_kmalloc_for_dev_failed__0007633c[2];
              tmp42[3] = s_kmalloc_for_dev_failed__0007633c[3];
              tmp42[4] = s_kmalloc_for_dev_failed__0007633c[4];
              tmp42[5] = s_kmalloc_for_dev_failed__0007633c[5];
              tmp42[6] = s_kmalloc_for_dev_failed__0007633c[6];
              tmp42[7] = s_kmalloc_for_dev_failed__0007633c[7];
              tmp42[8] = s_kmalloc_for_dev_failed__0007633c[8];
              tmp42[9] = s_kmalloc_for_dev_failed__0007633c[9];
              tmp42[10] = s_kmalloc_for_dev_failed__0007633c[10];
              tmp42[11] = s_kmalloc_for_dev_failed__0007633c[11];
              tmp42[12] = s_kmalloc_for_dev_failed__0007633c[12];
              tmp42[13] = s_kmalloc_for_dev_failed__0007633c[13];
              tmp42[14] = s_kmalloc_for_dev_failed__0007633c[14];
              tmp42[15] = s_kmalloc_for_dev_failed__0007633c[15];
              tmp42[16] = s_kmalloc_for_dev_failed__0007633c[16];
              tmp42[17] = s_kmalloc_for_dev_failed__0007633c[17];
              tmp42[18] = s_kmalloc_for_dev_failed__0007633c[18];
              tmp42[19] = s_kmalloc_for_dev_failed__0007633c[19];
              tmp42[20] = s_kmalloc_for_dev_failed__0007633c[20];
              tmp42[21] = s_kmalloc_for_dev_failed__0007633c[21];
              tmp42[22] = s_kmalloc_for_dev_failed__0007633c[22];
              tmp42[23] = s_kmalloc_for_dev_failed__0007633c[23];
              tmp42[24] = (char)ram0x00076354;
              _applog(7,tmp42,false);
            }
            ret = -1;
          }
          else {
            dev->current_job_start_address = job_start_address_1;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              tmp42[0] = s_kmalloc_for_dev_success__00076358[0];
              tmp42[1] = s_kmalloc_for_dev_success__00076358[1];
              tmp42[2] = s_kmalloc_for_dev_success__00076358[2];
              tmp42[3] = s_kmalloc_for_dev_success__00076358[3];
              tmp42[4] = s_kmalloc_for_dev_success__00076358[4];
              tmp42[5] = s_kmalloc_for_dev_success__00076358[5];
              tmp42[6] = s_kmalloc_for_dev_success__00076358[6];
              tmp42[7] = s_kmalloc_for_dev_success__00076358[7];
              tmp42[8] = s_kmalloc_for_dev_success__00076358[8];
              tmp42[9] = s_kmalloc_for_dev_success__00076358[9];
              tmp42[10] = s_kmalloc_for_dev_success__00076358[10];
              tmp42[11] = s_kmalloc_for_dev_success__00076358[11];
              tmp42[12] = s_kmalloc_for_dev_success__00076358[12];
              tmp42[13] = s_kmalloc_for_dev_success__00076358[13];
              tmp42[14] = s_kmalloc_for_dev_success__00076358[14];
              tmp42[15] = s_kmalloc_for_dev_success__00076358[15];
              tmp42[16] = s_kmalloc_for_dev_success__00076358[16];
              tmp42[17] = s_kmalloc_for_dev_success__00076358[17];
              tmp42[18] = s_kmalloc_for_dev_success__00076358[18];
              tmp42[19] = s_kmalloc_for_dev_success__00076358[19];
              tmp42[20] = s_kmalloc_for_dev_success__00076358[20];
              tmp42[21] = s_kmalloc_for_dev_success__00076358[21];
              tmp42[22] = s_kmalloc_for_dev_success__00076358[22];
              tmp42[23] = s_kmalloc_for_dev_success__00076358[23];
              tmp42._24_2_ = (undefined2)ram0x00076370;
              _applog(7,tmp42,false);
            }
          }
        }
      }
    }
  }
  return ret;
}

