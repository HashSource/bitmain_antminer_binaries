
/* WARNING: Unknown calling convention */

uint32_t get_QN_write_data_command(void)

{
  uint32_t val;
  
  fpga_read(0x12,&val);
  return val;
}

