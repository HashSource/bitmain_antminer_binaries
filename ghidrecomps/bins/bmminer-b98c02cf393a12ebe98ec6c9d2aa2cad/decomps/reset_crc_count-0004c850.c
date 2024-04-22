
void reset_crc_count(int param_1)

{
  if (param_1 == 0) {
    *(undefined4 *)(axi_fpga_addr + 0xf8) = 0;
    return;
  }
  *(undefined4 *)(axi_fpga_addr + 0xf8) = 0x80000000;
  return;
}

