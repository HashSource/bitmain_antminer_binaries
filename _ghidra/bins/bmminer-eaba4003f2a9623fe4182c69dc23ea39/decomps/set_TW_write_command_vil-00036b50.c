
void set_TW_write_command_vil(uint *value)

{
  uint *value_local;
  uint i;
  
  pthread_mutex_lock((pthread_mutex_t *)&fpga_mutex);
  for (i = 0; i < 0xd; i = i + 1) {
    if (i == 0) {
      axi_fpga_addr[0x10] = *value;
    }
    else {
      axi_fpga_addr[0x11] = value[i];
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)&fpga_mutex);
  return;
}

