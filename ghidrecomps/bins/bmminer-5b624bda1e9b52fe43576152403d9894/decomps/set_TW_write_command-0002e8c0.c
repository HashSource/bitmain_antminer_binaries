
/* WARNING: Unknown calling convention */

void set_TW_write_command(uint *value)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = axi_fpga_addr;
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 4;
    *(undefined4 *)((int)puVar1 + iVar2 + 0x40) = *(undefined4 *)((int)value + iVar2);
    iVar2 = iVar3;
  } while (iVar3 != 0x34);
  return;
}

