
void set_TW_write_command_vil
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  pthread_mutex_lock((pthread_mutex_t *)fpga_mutex);
  iVar1 = axi_fpga_addr;
  iVar3 = 1;
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      *(undefined4 *)(iVar1 + 0x40) = *param_1;
    }
    else {
      uVar2 = param_1[iVar4];
      *(undefined4 *)(iVar1 + 0x44) = uVar2;
      if (iVar3 == 0xd) {
        (*(code *)PTR_pthread_mutex_unlock_0007ce1c)(DAT_0004dc6c,uVar2,0xd,param_4);
        return;
      }
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 1;
  } while( true );
}

