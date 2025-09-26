
/* WARNING: Unknown calling convention */

void _set_dhash_acc_control(uint32_t value)

{
  fpga_write(0x23,value);
  return;
}

