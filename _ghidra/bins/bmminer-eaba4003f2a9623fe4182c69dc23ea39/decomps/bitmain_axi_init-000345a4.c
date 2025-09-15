
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
              builtin_strncpy(tmp42,"kmalloc for dev failed.\n",0x18);
              tmp42._24_2_ = (ushort)(byte)tmp42[0x19] << 8;
              _applog(7,tmp42,false);
            }
            ret = -1;
          }
          else {
            dev->current_job_start_address = job_start_address_1;
            if ((opt_debug != false) &&
               (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
              builtin_strncpy(tmp42,"kmalloc for dev success.",0x18);
              tmp42[0x18] = '\n';
              tmp42[0x19] = '\0';
              _applog(7,tmp42,false);
            }
          }
        }
      }
    }
  }
  return ret;
}

