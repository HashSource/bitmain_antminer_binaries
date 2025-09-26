
/* WARNING: Unknown calling convention */

void set_BC_nullen_all_chain(_Bool enable_null_work)

{
  uint32_t val;
  
  pthread_mutex_lock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  fpga_read(0x1b,&val);
  pthread_mutex_unlock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  return;
}

