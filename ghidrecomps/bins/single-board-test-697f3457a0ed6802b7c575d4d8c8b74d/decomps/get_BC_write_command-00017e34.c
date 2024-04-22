
/* WARNING: Unknown calling convention */

uint get_BC_write_command(void)

{
  uint uVar1;
  uint ret;
  
  uVar1 = read_axi_fpga(0x30);
  return uVar1;
}

