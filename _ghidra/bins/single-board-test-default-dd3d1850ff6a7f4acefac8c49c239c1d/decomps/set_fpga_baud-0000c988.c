
void set_fpga_baud(undefined1 param_1)

{
  undefined1 uVar1;
  
  uVar1 = asic_baud_to_fpga_baud(param_1);
  write_axi_fpga(0xf,uVar1);
  return;
}

