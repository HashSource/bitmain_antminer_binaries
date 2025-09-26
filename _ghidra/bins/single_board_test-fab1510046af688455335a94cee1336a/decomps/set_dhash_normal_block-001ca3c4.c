
/* WARNING: Unknown calling convention */

int32_t set_dhash_normal_block(void)

{
  uint32_t value;
  
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffff7f);
  return 0;
}

