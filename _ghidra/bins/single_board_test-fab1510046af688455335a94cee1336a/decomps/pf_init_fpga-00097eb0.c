
/* WARNING: Unknown calling convention */

_Bool pf_init_fpga(void)

{
  uint32_t uVar1;
  uint32_t fpga_data;
  
  stop_dhash_work_gen();
  usleep(1000000);
  reset_fpga(0);
  usleep(150000);
  disable_bypass_mode();
  enable_sync_header();
  uVar1 = _get_dhash_acc_control();
  _set_dhash_acc_control(uVar1 & 0xffff3f1f | 0x8080);
  set_dhash_midstate(8);
  usleep(50000);
  return true;
}

