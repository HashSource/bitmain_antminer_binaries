
/* WARNING: Unknown calling convention */

int get_bt8d_fpga_divider(int baud)

{
  if (baud == 0x1c200) {
    return 0x1a;
  }
  if (baud == 1000000) {
    return 2;
  }
  if ((double)(longlong)baud == 1500000.0) {
    return 1;
  }
  if (baud != 3000000) {
    if (baud == 6000000) {
      return 3;
    }
    if (baud != 12000000) {
      if (baud == 25000000) {
        baud = 5;
      }
      return baud;
    }
    return 4;
  }
  return 0;
}

