
/* WARNING: Unknown calling convention */

int32_t disable_dhash_work_gen(void)

{
  uint32_t value;
  
  value = 0;
  fpga_read(0x23,&value);
  fpga_write(0x23,value & 0xffffffdf);
  return 0;
}

