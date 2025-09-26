
/* WARNING: Unknown calling convention */

int32_t stop_dhash_work_gen(void)

{
  uint32_t value;
  
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffffbf);
  return 0;
}

