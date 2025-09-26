
/* WARNING: Unknown calling convention */

void set_BC_baud(int baud)

{
  uint32_t val;
  
  pthread_mutex_lock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  usleep(50000);
  fpga_read(0x1b,&val);
  set_BC_write_command(val & 0xffffffc0 | baud & 0x3fU);
  pthread_mutex_unlock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  return;
}

