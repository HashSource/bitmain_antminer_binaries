
void set_BC_command_buffer(undefined4 *param_1)

{
  write_axi_fpga(0x31,*param_1);
  write_axi_fpga(0x32,param_1[1]);
  write_axi_fpga(0x33,param_1[2]);
  return;
}

