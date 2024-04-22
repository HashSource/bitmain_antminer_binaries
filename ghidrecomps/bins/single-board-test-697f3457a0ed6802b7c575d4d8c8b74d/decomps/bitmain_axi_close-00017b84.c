
/* WARNING: Unknown calling convention */

void bitmain_axi_close(void)

{
  int iVar1;
  char tmp42 [1024];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","bitmain_axi_close");
    _applog(2,tmp42,false);
  }
  iVar1 = munmap(axi_fpga_addr,0x1200);
  if ((iVar1 < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level))))
  {
    tmp42[0] = s_munmap_failed__00034d60[0];
    tmp42[1] = s_munmap_failed__00034d60[1];
    tmp42[2] = s_munmap_failed__00034d60[2];
    tmp42[3] = s_munmap_failed__00034d60[3];
    tmp42[4] = s_munmap_failed__00034d60[4];
    tmp42[5] = s_munmap_failed__00034d60[5];
    tmp42[6] = s_munmap_failed__00034d60[6];
    tmp42[7] = s_munmap_failed__00034d60[7];
    tmp42[8] = s_munmap_failed__00034d60[8];
    tmp42[9] = s_munmap_failed__00034d60[9];
    tmp42[10] = s_munmap_failed__00034d60[10];
    tmp42[11] = s_munmap_failed__00034d60[11];
    tmp42[12] = s_munmap_failed__00034d60[12];
    tmp42[13] = s_munmap_failed__00034d60[13];
    tmp42[14] = s_munmap_failed__00034d60[14];
    tmp42[15] = s_munmap_failed__00034d60[15];
    _applog(2,tmp42,false);
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if ((iVar1 < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level))))
  {
    tmp42[0] = s_munmap_failed__00034d60[0];
    tmp42[1] = s_munmap_failed__00034d60[1];
    tmp42[2] = s_munmap_failed__00034d60[2];
    tmp42[3] = s_munmap_failed__00034d60[3];
    tmp42[4] = s_munmap_failed__00034d60[4];
    tmp42[5] = s_munmap_failed__00034d60[5];
    tmp42[6] = s_munmap_failed__00034d60[6];
    tmp42[7] = s_munmap_failed__00034d60[7];
    tmp42[8] = s_munmap_failed__00034d60[8];
    tmp42[9] = s_munmap_failed__00034d60[9];
    tmp42[10] = s_munmap_failed__00034d60[10];
    tmp42[11] = s_munmap_failed__00034d60[11];
    tmp42[12] = s_munmap_failed__00034d60[12];
    tmp42[13] = s_munmap_failed__00034d60[13];
    tmp42[14] = s_munmap_failed__00034d60[14];
    tmp42[15] = s_munmap_failed__00034d60[15];
    _applog(2,tmp42,false);
  }
  close(fd_fpga);
  close(fd_fpga_mem);
  return;
}

