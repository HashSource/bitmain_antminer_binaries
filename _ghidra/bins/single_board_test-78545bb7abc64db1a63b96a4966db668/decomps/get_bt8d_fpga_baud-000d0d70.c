
/* WARNING: Unknown calling convention */

int get_bt8d_fpga_baud(int fpgadiv)

{
  int iVar1;
  
  if (fpgadiv == 0) {
    return 3000000;
  }
  if (fpgadiv == 1) {
    return 1500000;
  }
  if (fpgadiv == 3) {
    return 6000000;
  }
  if (fpgadiv != 4) {
    iVar1 = 25000000;
    if (fpgadiv != 5) {
      iVar1 = 0x1c200;
    }
    return iVar1;
  }
  return 12000000;
}

