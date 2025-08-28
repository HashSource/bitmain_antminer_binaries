
/* WARNING: Unknown calling convention */

void set_TW_write_command_vil(uint *value)

{
  uint *puVar1;
  int iVar2;
  
  pthread_mutex_lock((pthread_mutex_t *)&fpga_mutex);
  puVar1 = axi_fpga_addr;
  iVar2 = 1;
  do {
    if (iVar2 == 1) {
      puVar1[0x10] = *value;
    }
    else {
      puVar1[0x11] = value[iVar2 + -1];
      if (iVar2 == 0xd) {
        (*(code *)(undefined *)0x0)(&fpga_mutex);
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while( true );
}

