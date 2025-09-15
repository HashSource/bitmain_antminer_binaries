
uint check_how_many_uart_data_in_fpga(byte param_1)

{
  uint local_c;
  
  local_c = 0;
  if (platform_is_t9 == 0) {
    switch(param_1) {
    case 0:
      fpga_read(v9_fpga_map._268_4_,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 1:
      fpga_read(v9_fpga_map._268_4_,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 2:
      fpga_read(v9_fpga_map._272_4_,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 3:
      fpga_read(v9_fpga_map._272_4_,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 4:
      fpga_read(v9_fpga_map._276_4_,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 5:
      fpga_read(v9_fpga_map._276_4_,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 6:
      fpga_read(v9_fpga_map._280_4_,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 7:
      fpga_read(v9_fpga_map._280_4_,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 8:
      fpga_read(v9_fpga_map._284_4_,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 9:
      fpga_read(v9_fpga_map._284_4_,&local_c);
      local_c = local_c & 0x3ff;
      break;
    default:
      printf("%s:%d","check_how_many_uart_data_in_fpga",0x1c1);
      printf("%s: The uart%d is not supported!!!\n","check_how_many_uart_data_in_fpga",(uint)param_1
            );
      local_c = 0;
    }
  }
  else {
    switch(param_1) {
    case 0:
      fpga_read(DAT_0003565c,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 1:
      fpga_read(DAT_0003565c,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 2:
      fpga_read(DAT_00035660,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 3:
      fpga_read(DAT_00035660,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 4:
      fpga_read(DAT_00035664,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 5:
      fpga_read(DAT_00035664,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 6:
      fpga_read(DAT_00035668,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 7:
      fpga_read(DAT_00035668,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 8:
      fpga_read(DAT_0003566c,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 9:
      fpga_read(DAT_0003566c,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 10:
      fpga_read(DAT_00035670,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 0xb:
      fpga_read(DAT_00035670,&local_c);
      local_c = local_c & 0x3ff;
      break;
    case 0xc:
      fpga_read(DAT_00035674,&local_c);
      local_c = local_c >> 0x10 & 0x3ff;
      break;
    case 0xd:
      fpga_read(DAT_00035674,&local_c);
      local_c = local_c & 0x3ff;
      break;
    default:
      printf("%s:%d","check_how_many_uart_data_in_fpga",0x18a);
      printf("%s: The uart%d is not supported!!!\n","check_how_many_uart_data_in_fpga",(uint)param_1
            );
      local_c = 0;
    }
  }
  return local_c;
}

