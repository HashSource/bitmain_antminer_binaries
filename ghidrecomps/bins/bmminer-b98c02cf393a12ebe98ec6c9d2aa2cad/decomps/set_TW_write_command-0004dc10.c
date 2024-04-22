
void set_TW_write_command(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + -4);
  puVar1 = (undefined4 *)(axi_fpga_addr + 0x3c);
  do {
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar2;
  } while (puVar2 != (undefined4 *)(param_1 + 0x30));
  return;
}

