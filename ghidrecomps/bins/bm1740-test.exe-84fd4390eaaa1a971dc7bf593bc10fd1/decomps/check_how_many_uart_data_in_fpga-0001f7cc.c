
uint check_how_many_uart_data_in_fpga(byte param_1)

{
  int iVar1;
  uint uVar2;
  
  switch(param_1) {
  case 0:
    iVar1 = read_axi_fpga(0x440);
    uVar2 = iVar1 >> 0x10 & 0x3ff;
    break;
  case 1:
    uVar2 = read_axi_fpga(0x440);
    uVar2 = uVar2 & 0x3ff;
    break;
  case 2:
    iVar1 = read_axi_fpga(0x441);
    uVar2 = iVar1 >> 0x10 & 0x3ff;
    break;
  case 3:
    uVar2 = read_axi_fpga(0x441);
    uVar2 = uVar2 & 0x3ff;
    break;
  case 4:
    iVar1 = read_axi_fpga(0x442);
    uVar2 = iVar1 >> 0x10 & 0x3ff;
    break;
  case 5:
    uVar2 = read_axi_fpga(0x442);
    uVar2 = uVar2 & 0x3ff;
    break;
  case 6:
    iVar1 = read_axi_fpga(0x443);
    uVar2 = iVar1 >> 0x10 & 0x3ff;
    break;
  case 7:
    uVar2 = read_axi_fpga(0x443);
    uVar2 = uVar2 & 0x3ff;
    break;
  case 8:
    iVar1 = read_axi_fpga(0x444);
    uVar2 = iVar1 >> 0x10 & 0x3ff;
    break;
  case 9:
    uVar2 = read_axi_fpga(0x444);
    uVar2 = uVar2 & 0x3ff;
    break;
  default:
    printf("%s: The uart%d is not supported!!!\n","check_how_many_uart_data_in_fpga",(uint)param_1);
    uVar2 = 0;
  }
  return uVar2;
}

