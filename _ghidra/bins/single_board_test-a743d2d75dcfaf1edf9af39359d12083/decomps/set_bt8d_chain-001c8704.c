
/* WARNING: Unknown calling convention */

int32_t set_bt8d_chain(uint32_t chain,uint32_t baud)

{
  uint uVar1;
  uint val_00;
  uint32_t val;
  
  uVar1 = get_bt8d_fpga_divider(baud);
  val = 0;
  fpga_read(0xf,&val);
  if (chain == 0) {
    val_00 = val & 0xffffffc0 | uVar1 & 0x3f;
  }
  else if (chain == 1) {
    val_00 = val & 0xffffc0ff | (uVar1 & 0x3f) << 8;
  }
  else if (chain == 2) {
    val_00 = val & 0xffc0ffff | (uVar1 & 0x3f) << 0x10;
  }
  else {
    val_00 = val;
    if (chain == 3) {
      val_00 = val & 0xc0ffffff | (uVar1 & 0x3f) << 0x18;
    }
  }
  fpga_write(0xf,val_00);
  return 0;
}

