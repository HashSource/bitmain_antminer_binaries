
/* WARNING: Unknown calling convention */

int get_hash_counting_number(void)

{
  uint uVar1;
  char tmp42 [2048];
  int ret;
  
  uVar1 = axi_fpga_addr[0x24];
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: DHASH_ACC_CONTROL is 0x%x\n","get_hash_counting_number",uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

