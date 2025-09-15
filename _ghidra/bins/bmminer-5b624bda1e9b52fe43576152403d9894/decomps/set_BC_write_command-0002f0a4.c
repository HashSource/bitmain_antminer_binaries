
/* WARNING: Unknown calling convention */

void set_BC_write_command(uint value)

{
  int iVar1;
  int iVar2;
  char logstr [256];
  
  axi_fpga_addr[0x30] = value;
  if ((int)value < 0) {
    iVar2 = 0xbb9;
    do {
      iVar1 = get_BC_write_command();
      if (-1 < iVar1) {
        return;
      }
      cgsleep_ms(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    builtin_strncpy(logstr,"Error: set_BC_write_command wait buffer ready timeout!\n",0x38);
    writeInitLogFile(logstr);
  }
  else {
    get_BC_write_command();
  }
  return;
}

