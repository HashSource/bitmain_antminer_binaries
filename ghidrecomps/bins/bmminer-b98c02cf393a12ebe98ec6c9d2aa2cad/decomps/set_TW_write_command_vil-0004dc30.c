
void set_TW_write_command_vil(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  pthread_mutex_lock((pthread_mutex_t *)fpga_mutex);
  iVar1 = axi_fpga_addr;
  iVar2 = 1;
  iVar3 = 0;
  do {
    if (iVar3 == 0) {
      *(undefined4 *)(iVar1 + 0x40) = *param_1;
    }
    else {
      *(undefined4 *)(iVar1 + 0x44) = param_1[iVar3];
      if (iVar2 == 0xd) {
        pthread_mutex_unlock((pthread_mutex_t *)fpga_mutex);
        return;
      }
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 1;
  } while( true );
}

