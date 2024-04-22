
void read_fpga_id(char *param_1)

{
  sprintf(param_1,"%08x%08x",*(undefined4 *)(axi_fpga_addr + 0xf4),
          *(undefined4 *)(axi_fpga_addr + 0xf0));
  return;
}

