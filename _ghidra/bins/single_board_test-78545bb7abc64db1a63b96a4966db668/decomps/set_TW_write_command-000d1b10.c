
/* WARNING: Unknown calling convention */

void set_TW_write_command(uint32_t *value,uint32_t len)

{
  uint32_t address;
  uint uVar1;
  uint32_t *puVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)&tw_cmd_acc_mutex);
  if (len >> 2 != 0) {
    puVar2 = value + -1;
    uVar1 = 0;
    address = 0x10;
    while( true ) {
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 1;
      fpga_write(address,*puVar2);
      if (uVar1 == len >> 2) break;
      if (uVar1 == 0) {
        address = 0x10;
      }
      else {
        address = 0x11;
      }
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)&tw_cmd_acc_mutex);
  return;
}

