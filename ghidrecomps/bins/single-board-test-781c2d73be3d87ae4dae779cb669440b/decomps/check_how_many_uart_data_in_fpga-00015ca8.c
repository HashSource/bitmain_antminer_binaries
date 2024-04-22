
/* WARNING: Unknown calling convention */

uint check_how_many_uart_data_in_fpga(uchar which_uart)

{
  uint uVar1;
  
  switch((uint)which_uart) {
  case 0:
    uVar1 = read_axi_fpga(0x7c);
    return (uVar1 << 6) >> 0x16;
  case 1:
    uVar1 = read_axi_fpga(0x7c);
    return uVar1 & 0x3ff;
  case 2:
    uVar1 = read_axi_fpga(0x7d);
    return (uVar1 << 6) >> 0x16;
  case 3:
    uVar1 = read_axi_fpga(0x7d);
    return uVar1 & 0x3ff;
  case 4:
    uVar1 = read_axi_fpga(0x7e);
    return (uVar1 << 6) >> 0x16;
  case 5:
    uVar1 = read_axi_fpga(0x7e);
    return uVar1 & 0x3ff;
  case 6:
    uVar1 = read_axi_fpga(0x7f);
    return (uVar1 << 6) >> 0x16;
  case 7:
    uVar1 = read_axi_fpga(0x7f);
    return uVar1 & 0x3ff;
  case 8:
    uVar1 = read_axi_fpga(0x80);
    return (uVar1 << 6) >> 0x16;
  case 9:
    uVar1 = read_axi_fpga(0x80);
    return uVar1 & 0x3ff;
  default:
    printf("%s: The uart%d is not supported!!!\n","check_how_many_uart_data_in_fpga",
           (uint)which_uart);
    return 0;
  }
}

