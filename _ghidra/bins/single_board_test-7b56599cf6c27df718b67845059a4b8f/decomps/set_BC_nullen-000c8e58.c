
/* WARNING: Unknown calling convention */

void set_BC_nullen(int chain,_Bool enable_null_work)

{
  uint uVar1;
  uint32_t value;
  uint32_t val;
  
  pthread_mutex_lock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  fpga_read(0x1b,&val);
  uVar1 = val & 0xfff0ffff | chain << 0x10;
  if (enable_null_work) {
    value = uVar1 | 0xc00000;
  }
  else {
    value = uVar1 & 0xffbfffff | 0x800000;
  }
  set_BC_write_command(value);
  pthread_mutex_unlock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  return;
}

