
/* WARNING: Unknown calling convention */

int32_t get_bt8d_chain(uint32_t chain)

{
  uint fpgadiv;
  int iVar1;
  uint32_t val;
  
  val = 0;
  fpga_read(0xf,&val);
  if (chain == 0) {
    iVar1 = get_bt8d_fpga_baud(val & 0x3f);
    return iVar1;
  }
  if (chain == 1) {
    fpgadiv = (val << 0x12) >> 0x1a;
  }
  else if (chain == 2) {
    fpgadiv = (val << 10) >> 0x1a;
  }
  else {
    if (chain != 3) {
      return -1;
    }
    fpgadiv = (val << 2) >> 0x1a;
  }
  iVar1 = get_bt8d_fpga_baud(fpgadiv);
  return iVar1;
}

