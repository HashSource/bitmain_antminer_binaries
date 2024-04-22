
void set_TW_write_command_vil(undefined4 *param_1)

{
  uint local_c;
  
  pthread_mutex_lock((pthread_mutex_t *)fpga_mutex);
  for (local_c = 0; local_c < 0xd; local_c = local_c + 1) {
    if (local_c == 0) {
      *(undefined4 *)(axi_fpga_addr + 0x40) = *param_1;
    }
    else {
      *(undefined4 *)(axi_fpga_addr + 0x44) = param_1[local_c];
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)fpga_mutex);
  return;
}

