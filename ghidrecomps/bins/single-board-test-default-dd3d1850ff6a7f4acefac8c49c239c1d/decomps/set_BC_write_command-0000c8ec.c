
void set_BC_write_command(int param_1)

{
  int iVar1;
  byte local_9;
  
  local_9 = 0;
  if (param_1 < 0) {
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) goto LAB_0000c938;
      usleep(1000);
      local_9 = local_9 + 1;
    } while (local_9 < 0x65);
    printf("\n%s: timeout\n\n","set_BC_write_command");
  }
LAB_0000c938:
  write_axi_fpga(0x30,param_1);
  return;
}

