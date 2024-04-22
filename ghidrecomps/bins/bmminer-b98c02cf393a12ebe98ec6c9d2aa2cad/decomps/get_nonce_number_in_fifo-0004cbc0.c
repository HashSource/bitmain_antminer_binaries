
undefined4 get_nonce_number_in_fifo(void)

{
  return *(undefined4 *)(axi_fpga_addr + 0x18);
}

