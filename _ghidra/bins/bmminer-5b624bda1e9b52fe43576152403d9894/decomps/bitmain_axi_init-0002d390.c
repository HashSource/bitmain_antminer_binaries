
/* WARNING: Unknown calling convention */

int bitmain_axi_init(void)

{
  _Bool _Var1;
  int __fd;
  char *pcVar2;
  uint uVar3;
  char tmp42 [2048];
  
  __fd = open("/dev/axi_fpga_dev",2);
  fd = __fd;
  if (__fd < 0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      pcVar2 = "/dev/axi_fpga_dev open failed. fd = %d\n";
LAB_0002d738:
      snprintf(tmp42,0x800,pcVar2,__fd);
      _applog(7,tmp42,false);
    }
LAB_0002d746:
    perror("open");
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x160,3,1,__fd,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if (opt_debug == false) {
        return -1;
      }
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
        return -1;
      }
      pcVar2 = "mmap axi_fpga_addr failed. axi_fpga_addr = 0x%x\n";
    }
    else {
      if (opt_debug != false) {
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
          uVar3 = *axi_fpga_addr;
          if ((undefined1 *)(uVar3 & 0xffff) == &LAB_0000c500_1) {
LAB_0002d5d0:
            if ((use_syslog == false) && (opt_log_output == false)) goto LAB_0002d4dc;
          }
          else {
LAB_0002d4ce:
            if ((opt_log_output != false) || (6 < opt_log_level)) {
LAB_0002d5aa:
              snprintf(tmp42,0x800,
                       "data = 0x%x, and it\'s not equal to HARDWARE_VERSION_VALUE : 0x%x\n",uVar3,
                       &LAB_0000c500_1);
              _applog(7,tmp42,false);
              goto LAB_0002d5ca;
            }
LAB_0002d4dc:
            if (opt_log_level < 7) goto LAB_0002d3d0;
          }
          snprintf(tmp42,0x800,"axi_fpga_addr data = 0x%x\n",uVar3);
          _applog(7,tmp42,false);
        }
        else {
          snprintf(tmp42,0x800,"mmap axi_fpga_addr = 0x%x\n",axi_fpga_addr);
          _applog(7,tmp42,false);
          uVar3 = *axi_fpga_addr;
          if ((undefined1 *)(uVar3 & 0xffff) == &LAB_0000c500_1) {
LAB_0002d5ca:
            if (opt_debug != false) goto LAB_0002d5d0;
          }
          else if (opt_debug != false) {
            if (use_syslog == false) goto LAB_0002d4ce;
            goto LAB_0002d5aa;
          }
        }
      }
LAB_0002d3d0:
      __fd = open("/dev/fpga_mem",2);
      fd_fpga_mem = __fd;
      if (__fd < 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          pcVar2 = "/dev/fpga_mem open failed. fd_fpga_mem = %d\n";
          goto LAB_0002d738;
        }
        goto LAB_0002d746;
      }
      fpga_mem_addr = (uint *)mmap((void *)0x0,0x1000000,3,1,__fd,0);
      if (fpga_mem_addr != (uint *)0x0) {
        if (opt_debug == false) {
          job_start_address_1 = fpga_mem_addr + 0x80000;
          job_start_address_2 = fpga_mem_addr + 0x84000;
          nonce2_jobid_address = fpga_mem_addr;
          goto LAB_0002d41c;
        }
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
          job_start_address_1 = fpga_mem_addr + 0x80000;
          job_start_address_2 = fpga_mem_addr + 0x84000;
        }
        else {
          snprintf(tmp42,0x800,"mmap fpga_mem_addr = 0x%x\n",fpga_mem_addr);
          _applog(7,tmp42,false);
          job_start_address_1 = fpga_mem_addr + 0x80000;
          job_start_address_2 = fpga_mem_addr + 0x84000;
          nonce2_jobid_address = fpga_mem_addr;
          if (opt_debug == false) goto LAB_0002d41c;
        }
        nonce2_jobid_address = fpga_mem_addr;
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
LAB_0002d582:
          if (opt_log_level < 7) goto LAB_0002d41c;
        }
        else {
          snprintf(tmp42,0x800,"job_start_address_1 = 0x%x\n");
          _applog(7,tmp42,false);
          if (opt_debug == false) goto LAB_0002d41c;
          if ((use_syslog == false) && (opt_log_output == false)) goto LAB_0002d582;
        }
        snprintf(tmp42,0x800,"job_start_address_2 = 0x%x\n",job_start_address_2);
        _applog(7,tmp42,false);
LAB_0002d41c:
        set_nonce2_and_job_id_store_address(PHY_MEM_NONCE2_JOBID_ADDRESS);
        set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
        dev = (all_parameters *)calloc(0x301c,1);
        _Var1 = opt_debug;
        if (dev != (all_parameters *)0x0) {
          dev->current_job_start_address = job_start_address_1;
          if (_Var1 != false) {
            if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
              return 0;
            }
            builtin_strncpy(tmp42,"kmalloc for dev success.",0x18);
            tmp42[0x18] = '\n';
            tmp42[0x19] = '\0';
            _applog(7,tmp42,false);
          }
          return 0;
        }
        if (opt_debug == false) {
          dev = (all_parameters *)0x0;
          return -1;
        }
        if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
          dev = (all_parameters *)0x0;
          return -1;
        }
        builtin_strncpy(tmp42,"kmalloc for dev failed.\n",0x18);
        tmp42._24_2_ = (ushort)(byte)tmp42[0x19] << 8;
        _applog(7,tmp42,false);
        return -1;
      }
      if (opt_debug == false) {
        return -1;
      }
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
        return -1;
      }
      pcVar2 = "mmap fpga_mem_addr failed. fpga_mem_addr = 0x%x\n";
      fpga_mem_addr = (uint *)0x0;
    }
    snprintf(tmp42,0x800,pcVar2,0);
    _applog(7,tmp42,false);
  }
  return -1;
}

