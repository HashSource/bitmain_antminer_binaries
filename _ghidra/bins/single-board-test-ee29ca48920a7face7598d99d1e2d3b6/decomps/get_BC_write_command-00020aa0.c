
undefined4 get_BC_write_command(void)

{
  undefined4 uVar1;
  
  uVar1 = read_axi_fpga(0x30);
  return uVar1;
}

