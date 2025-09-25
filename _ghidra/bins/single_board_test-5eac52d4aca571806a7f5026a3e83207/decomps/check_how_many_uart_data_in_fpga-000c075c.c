
/* WARNING: Unknown calling convention */

uint32_t check_how_many_uart_data_in_fpga(uchar which_uart)

{
  uint uVar1;
  uint32_t val;
  char tmp42 [2048];
  
  val = 0;
  switch((uint)which_uart) {
  case 0:
    fpga_read(0x59,&val);
    uVar1 = val >> 0x10 & 0x3ff;
    break;
  case 1:
    fpga_read(0x59,&val);
    uVar1 = val & 0x3ff;
    break;
  case 2:
    fpga_read(0x5a,&val);
    uVar1 = val >> 0x10 & 0x3ff;
    break;
  case 3:
    fpga_read(0x5a,&val);
    uVar1 = val & 0x3ff;
    break;
  case 4:
    fpga_read(0x5b,&val);
    uVar1 = val >> 0x10 & 0x3ff;
    break;
  case 5:
    fpga_read(0x5b,&val);
    uVar1 = val & 0x3ff;
    break;
  case 6:
    fpga_read(0x5c,&val);
    uVar1 = val >> 0x10 & 0x3ff;
    break;
  case 7:
    fpga_read(0x5c,&val);
    uVar1 = val & 0x3ff;
    break;
  case 8:
    fpga_read(0x5d,&val);
    uVar1 = val >> 0x10 & 0x3ff;
    break;
  case 9:
    fpga_read(0x5d,&val);
    uVar1 = val & 0x3ff;
    break;
  case 10:
    fpga_read(0x5e,&val);
    uVar1 = val >> 0x10 & 0x3ff;
    break;
  case 0xb:
    fpga_read(0x5e,&val);
    uVar1 = val & 0x3ff;
    break;
  case 0xc:
    fpga_read(0x5f,&val);
    uVar1 = val >> 0x10 & 0x3ff;
    break;
  case 0xd:
    fpga_read(0x5f,&val);
    uVar1 = val & 0x3ff;
    break;
  default:
    snprintf(tmp42,0x800,"%s: The uart%d is not supported!!!\n","check_how_many_uart_data_in_fpga",
             (uint)which_uart);
    _applog(0,tmp42,false);
    uVar1 = 0;
  }
  return uVar1;
}

