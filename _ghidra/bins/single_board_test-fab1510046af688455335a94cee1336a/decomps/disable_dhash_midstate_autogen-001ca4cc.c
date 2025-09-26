
/* WARNING: Unknown calling convention */

int32_t disable_dhash_midstate_autogen(void)

{
  uint32_t value;
  
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffbfff);
  return 0;
}

