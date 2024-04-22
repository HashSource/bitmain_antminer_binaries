
void bitmain_axi_close(void)

{
  undefined4 local_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  int local_14;
  
  local_14 = 0;
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf((char *)&local_414,0x400,"--- %s\n","bitmain_axi_close");
    _applog(2,&local_414,0);
  }
  local_14 = munmap(axi_fpga_addr,0x1200);
  if ((local_14 < 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level))))
  {
    local_414._0_1_ = s_munmap_failed__00033f20[0];
    local_414._1_1_ = s_munmap_failed__00033f20[1];
    local_414._2_1_ = s_munmap_failed__00033f20[2];
    local_414._3_1_ = s_munmap_failed__00033f20[3];
    uStack_410._0_1_ = s_munmap_failed__00033f20[4];
    uStack_410._1_1_ = s_munmap_failed__00033f20[5];
    uStack_410._2_1_ = s_munmap_failed__00033f20[6];
    uStack_410._3_1_ = s_munmap_failed__00033f20[7];
    uStack_40c._0_1_ = s_munmap_failed__00033f20[8];
    uStack_40c._1_1_ = s_munmap_failed__00033f20[9];
    uStack_40c._2_1_ = s_munmap_failed__00033f20[10];
    uStack_40c._3_1_ = s_munmap_failed__00033f20[11];
    uStack_408._0_1_ = s_munmap_failed__00033f20[12];
    uStack_408._1_1_ = s_munmap_failed__00033f20[13];
    uStack_408._2_1_ = s_munmap_failed__00033f20[14];
    uStack_408._3_1_ = s_munmap_failed__00033f20[15];
    _applog(2,&local_414,0);
  }
  local_14 = munmap(fpga_mem_addr,0x1000000);
  if ((local_14 < 0) && (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level))))
  {
    local_414._0_1_ = s_munmap_failed__00033f20[0];
    local_414._1_1_ = s_munmap_failed__00033f20[1];
    local_414._2_1_ = s_munmap_failed__00033f20[2];
    local_414._3_1_ = s_munmap_failed__00033f20[3];
    uStack_410._0_1_ = s_munmap_failed__00033f20[4];
    uStack_410._1_1_ = s_munmap_failed__00033f20[5];
    uStack_410._2_1_ = s_munmap_failed__00033f20[6];
    uStack_410._3_1_ = s_munmap_failed__00033f20[7];
    uStack_40c._0_1_ = s_munmap_failed__00033f20[8];
    uStack_40c._1_1_ = s_munmap_failed__00033f20[9];
    uStack_40c._2_1_ = s_munmap_failed__00033f20[10];
    uStack_40c._3_1_ = s_munmap_failed__00033f20[11];
    uStack_408._0_1_ = s_munmap_failed__00033f20[12];
    uStack_408._1_1_ = s_munmap_failed__00033f20[13];
    uStack_408._2_1_ = s_munmap_failed__00033f20[14];
    uStack_408._3_1_ = s_munmap_failed__00033f20[15];
    _applog(2,&local_414,0);
  }
  close(fd_fpga);
  close(fd_fpga_mem);
  return;
}

