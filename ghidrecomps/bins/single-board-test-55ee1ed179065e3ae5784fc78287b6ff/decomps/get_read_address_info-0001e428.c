
undefined4 get_read_address_info(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_c;
  
  local_c = 0;
  if (platform_is_t9 == 0) {
    switch(param_1) {
    case 0:
      *param_2 = v9_fpga_map._296_4_;
      *param_3 = v9_fpga_map._300_4_;
      break;
    case 1:
      *param_2 = v9_fpga_map._304_4_;
      *param_3 = v9_fpga_map._308_4_;
      break;
    case 2:
      *param_2 = v9_fpga_map._312_4_;
      *param_3 = v9_fpga_map._316_4_;
      break;
    case 3:
      *param_2 = v9_fpga_map._320_4_;
      *param_3 = v9_fpga_map._324_4_;
      break;
    case 4:
      *param_2 = v9_fpga_map._328_4_;
      *param_3 = v9_fpga_map._332_4_;
      break;
    case 5:
      *param_2 = v9_fpga_map._336_4_;
      *param_3 = v9_fpga_map._340_4_;
      break;
    case 6:
      *param_2 = v9_fpga_map._344_4_;
      *param_3 = v9_fpga_map._348_4_;
      break;
    case 7:
      *param_2 = v9_fpga_map._352_4_;
      *param_3 = v9_fpga_map._356_4_;
      break;
    case 8:
      *param_2 = v9_fpga_map._360_4_;
      *param_3 = v9_fpga_map._364_4_;
      break;
    case 9:
      *param_2 = v9_fpga_map._368_4_;
      *param_3 = v9_fpga_map._372_4_;
      break;
    default:
      printf("%s:%d","get_read_address_info",0x146);
      printf("%s: The uart%d is not supported!!!\n","get_read_address_info",param_1);
      local_c = 0xffffffff;
    }
  }
  else {
    switch(param_1) {
    case 0:
      *param_2 = DAT_00035678;
      *param_3 = DAT_0003567c;
      break;
    case 1:
      *param_2 = DAT_00035680;
      *param_3 = DAT_00035684;
      break;
    case 2:
      *param_2 = DAT_00035688;
      *param_3 = DAT_0003568c;
      break;
    case 3:
      *param_2 = DAT_00035690;
      *param_3 = DAT_00035694;
      break;
    default:
      printf("%s:%d","get_read_address_info",0x10c);
      printf("%s: The uart%d is not supported!!!\n","get_read_address_info",param_1);
      local_c = 0xffffffff;
      break;
    case 8:
      *param_2 = DAT_000356b8;
      *param_3 = DAT_000356bc;
      break;
    case 9:
      *param_2 = DAT_000356c0;
      *param_3 = DAT_000356c4;
      break;
    case 10:
      *param_2 = DAT_000356e8;
      *param_3 = DAT_000356ec;
      break;
    case 0xb:
      *param_2 = DAT_000356f0;
      *param_3 = DAT_000356f4;
      break;
    case 0xc:
      *param_2 = DAT_000356f8;
      *param_3 = DAT_000356fc;
      break;
    case 0xd:
      *param_2 = DAT_00035700;
      *param_3 = DAT_00035704;
    }
  }
  return local_c;
}

