
/* WARNING: Unknown calling convention */

int32_t set_bt8d_all_chain(uint32_t baud)

{
  uint uVar1;
  uint32_t val;
  
  uVar1 = get_bt8d_fpga_divider(baud);
  val = 0;
  fpga_read(0xf,&val);
  uVar1 = uVar1 & 0x3f;
  fpga_write(0xf,val & 0xc0c0c0c0 | uVar1 | uVar1 << 8 | uVar1 << 0x10 | uVar1 << 0x18);
  return 0;
}

