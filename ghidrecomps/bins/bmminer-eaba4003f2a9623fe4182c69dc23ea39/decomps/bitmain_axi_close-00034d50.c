
/* WARNING: Unknown calling convention */

int bitmain_axi_close(void)

{
  int iVar1;
  char tmp42 [2048];
  int ret;
  
  iVar1 = munmap(axi_fpga_addr,0x160);
  if (((iVar1 < 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    tmp42[0] = s_munmap_failed__00076374[0];
    tmp42[1] = s_munmap_failed__00076374[1];
    tmp42[2] = s_munmap_failed__00076374[2];
    tmp42[3] = s_munmap_failed__00076374[3];
    tmp42[4] = s_munmap_failed__00076374[4];
    tmp42[5] = s_munmap_failed__00076374[5];
    tmp42[6] = s_munmap_failed__00076374[6];
    tmp42[7] = s_munmap_failed__00076374[7];
    tmp42[8] = s_munmap_failed__00076374[8];
    tmp42[9] = s_munmap_failed__00076374[9];
    tmp42[10] = s_munmap_failed__00076374[10];
    tmp42[11] = s_munmap_failed__00076374[11];
    tmp42[12] = s_munmap_failed__00076374[12];
    tmp42[13] = s_munmap_failed__00076374[13];
    tmp42[14] = s_munmap_failed__00076374[14];
    tmp42[15] = s_munmap_failed__00076374[15];
    _applog(7,tmp42,false);
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if (((iVar1 < 0) && (opt_debug != false)) &&
     ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
    tmp42[0] = s_munmap_failed__00076374[0];
    tmp42[1] = s_munmap_failed__00076374[1];
    tmp42[2] = s_munmap_failed__00076374[2];
    tmp42[3] = s_munmap_failed__00076374[3];
    tmp42[4] = s_munmap_failed__00076374[4];
    tmp42[5] = s_munmap_failed__00076374[5];
    tmp42[6] = s_munmap_failed__00076374[6];
    tmp42[7] = s_munmap_failed__00076374[7];
    tmp42[8] = s_munmap_failed__00076374[8];
    tmp42[9] = s_munmap_failed__00076374[9];
    tmp42[10] = s_munmap_failed__00076374[10];
    tmp42[11] = s_munmap_failed__00076374[11];
    tmp42[12] = s_munmap_failed__00076374[12];
    tmp42[13] = s_munmap_failed__00076374[13];
    tmp42[14] = s_munmap_failed__00076374[14];
    tmp42[15] = s_munmap_failed__00076374[15];
    _applog(7,tmp42,false);
  }
  close(fd);
  iVar1 = fd_fpga_mem;
  close(fd_fpga_mem);
  return iVar1;
}

