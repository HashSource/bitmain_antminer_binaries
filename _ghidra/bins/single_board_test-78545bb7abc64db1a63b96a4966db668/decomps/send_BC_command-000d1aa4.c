
/* WARNING: Unknown calling convention */

void send_BC_command(uint32_t *value,int chain)

{
  uint32_t tmp;
  
  pthread_mutex_lock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  fpga_write(0x1c,*value);
  fpga_write(0x1d,value[1]);
  fpga_write(0x1e,value[2]);
  fpga_read(0x1c,&tmp);
  fpga_read(0x1d,&tmp);
  fpga_read(0x1e,&tmp);
  fpga_read(0x1b,&tmp);
  set_BC_write_command(tmp & 0xfff0ffff | 0x80800000 | chain << 0x10);
  pthread_mutex_unlock((pthread_mutex_t *)&bc_cmd_acc_mutex);
  return;
}

