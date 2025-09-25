
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void disable_dhash_chip_work(void)

{
  uint32_t val;
  uint32_t value;
  
  val = 0;
  fpga_read(0x1b,&val);
  val = val & 0xffbfffff;
  fpga_write(0x1b,val);
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffffbf);
  return;
}

