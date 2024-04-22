
/* WARNING: Unknown calling convention */

void set_BC_write_command(uint value)

{
  char cVar1;
  
  if ((int)value < 0) {
    cVar1 = 'e';
    do {
      if (-1 < (int)axi_fpga_addr[0x30]) goto LAB_00025de4;
      usleep(1000);
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
    printf("\n%s: timeout\n\n",DAT_00025e20);
  }
LAB_00025de4:
  axi_fpga_addr[0x30] = value;
  return;
}

