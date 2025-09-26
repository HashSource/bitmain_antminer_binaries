
/* WARNING: Unknown calling convention */

int32_t set_dhash_midstate(uint32_t num)

{
  uint32_t value;
  
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffe0ff | (num & 0x1f) << 8);
  return 0;
}

