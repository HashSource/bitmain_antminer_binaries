
undefined4 asic_baud_to_fpga_baud(byte param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 1;
    break;
  case 1:
    uVar1 = 3;
    break;
  case 2:
    uVar1 = 5;
    break;
  default:
    printf("%s: Don\'t support ASIC baud = %d, error!!!\n","asic_baud_to_fpga_baud",(uint)param_1);
    uVar1 = 0x35;
    break;
  case 6:
    uVar1 = 0xd;
    break;
  case 0x1a:
    uVar1 = 0x35;
  }
  return uVar1;
}

