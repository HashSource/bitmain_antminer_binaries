
/* WARNING: Unknown calling convention */

int32_t enable_dhash_vil_mode(void)

{
  uint32_t value;
  
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value | 0x8000);
  return 0;
}

