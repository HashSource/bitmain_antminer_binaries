
/* WARNING: Unknown calling convention */

uint32_t _get_dhash_acc_control(void)

{
  uint32_t value;
  
  value = 0;
  fpga_read(0x23,&value);
  return value;
}

