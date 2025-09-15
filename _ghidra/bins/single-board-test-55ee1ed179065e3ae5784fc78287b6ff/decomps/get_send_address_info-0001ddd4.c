
undefined4
get_send_address_info
          (undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5)

{
  undefined4 local_c;
  
  local_c = 0;
  if (platform_is_t9 == 0) {
    switch(param_1) {
    case 0:
      *param_2 = 0x18;
      *param_3 = v9_fpga_map._172_4_;
      *param_4 = v9_fpga_map._188_4_;
      *param_5 = v9_fpga_map._192_4_;
      break;
    case 1:
      *param_2 = 0x10;
      *param_3 = v9_fpga_map._172_4_;
      *param_4 = v9_fpga_map._196_4_;
      *param_5 = v9_fpga_map._200_4_;
      break;
    case 2:
      *param_2 = 8;
      *param_3 = v9_fpga_map._172_4_;
      *param_4 = v9_fpga_map._204_4_;
      *param_5 = v9_fpga_map._208_4_;
      break;
    case 3:
      *param_2 = 0;
      *param_3 = v9_fpga_map._172_4_;
      *param_4 = v9_fpga_map._212_4_;
      *param_5 = v9_fpga_map._216_4_;
      break;
    case 4:
      *param_2 = 0x18;
      *param_3 = v9_fpga_map._176_4_;
      *param_4 = v9_fpga_map._220_4_;
      *param_5 = v9_fpga_map._224_4_;
      break;
    case 5:
      *param_2 = 0x10;
      *param_3 = v9_fpga_map._176_4_;
      *param_4 = v9_fpga_map._228_4_;
      *param_5 = v9_fpga_map._232_4_;
      break;
    case 6:
      *param_2 = 8;
      *param_3 = v9_fpga_map._176_4_;
      *param_4 = v9_fpga_map._236_4_;
      *param_5 = v9_fpga_map._240_4_;
      break;
    case 7:
      *param_2 = 0;
      *param_3 = v9_fpga_map._176_4_;
      *param_4 = v9_fpga_map._244_4_;
      *param_5 = v9_fpga_map._248_4_;
      break;
    case 8:
      *param_2 = 0x18;
      *param_3 = v9_fpga_map._180_4_;
      *param_4 = v9_fpga_map._252_4_;
      *param_5 = v9_fpga_map._256_4_;
      break;
    case 9:
      *param_2 = 0x10;
      *param_3 = v9_fpga_map._180_4_;
      *param_4 = v9_fpga_map._260_4_;
      *param_5 = v9_fpga_map._264_4_;
      break;
    default:
      printf("%s:%d","get_send_address_info",0xc9);
      printf("%s: The uart %d is not supported!!!\n","get_send_address_info",param_1);
      local_c = 0xffffffff;
    }
  }
  else {
    switch(param_1) {
    case 0:
      *param_2 = 0x18;
      *param_3 = DAT_000355fc;
      *param_4 = DAT_0003560c;
      *param_5 = DAT_00035618;
      break;
    case 1:
      *param_2 = 0x10;
      *param_3 = DAT_000355fc;
      *param_4 = DAT_00035614;
      *param_5 = DAT_00035618;
      break;
    case 2:
      *param_2 = 8;
      *param_3 = DAT_000355fc;
      *param_4 = DAT_0003561c;
      *param_5 = DAT_00035620;
      break;
    case 3:
      *param_2 = 0;
      *param_3 = DAT_000355fc;
      *param_4 = DAT_00035624;
      *param_5 = DAT_00035628;
      break;
    case 4:
      *param_2 = 0x18;
      *param_3 = DAT_00035600;
      *param_4 = DAT_0003562c;
      *param_5 = DAT_00035630;
      break;
    case 5:
      *param_2 = 0x10;
      *param_3 = DAT_00035600;
      *param_4 = DAT_00035634;
      *param_5 = DAT_00035638;
      break;
    case 6:
      *param_2 = 8;
      *param_3 = DAT_00035600;
      *param_4 = DAT_0003563c;
      *param_5 = DAT_00035640;
      break;
    case 7:
      *param_2 = 0;
      *param_3 = DAT_00035600;
      *param_4 = DAT_00035644;
      *param_5 = DAT_00035648;
      break;
    case 8:
      *param_2 = 0x18;
      *param_3 = DAT_00035604;
      *param_4 = DAT_0003564c;
      *param_5 = DAT_00035650;
      break;
    case 9:
      *param_2 = 0x10;
      *param_3 = DAT_00035604;
      *param_4 = DAT_00035654;
      *param_5 = DAT_00035658;
      break;
    case 10:
      *param_2 = 8;
      *param_3 = DAT_00035604;
      *param_4 = DAT_000356c8;
      *param_5 = DAT_000356cc;
      break;
    case 0xb:
      *param_2 = 0;
      *param_3 = DAT_00035604;
      *param_4 = DAT_000356d0;
      *param_5 = DAT_000356d4;
      break;
    case 0xc:
      *param_2 = 0x18;
      *param_3 = DAT_00035608;
      *param_4 = DAT_000356d8;
      *param_5 = DAT_000356dc;
      break;
    case 0xd:
      *param_2 = 0x10;
      *param_3 = DAT_00035608;
      *param_4 = DAT_000356e0;
      *param_5 = DAT_000356e4;
      break;
    default:
      printf("%s:%d","get_send_address_info",0x7c);
      printf("%s: The uart %d is not supported!!!\n","get_send_address_info",param_1);
      local_c = 0xffffffff;
    }
  }
  return local_c;
}

