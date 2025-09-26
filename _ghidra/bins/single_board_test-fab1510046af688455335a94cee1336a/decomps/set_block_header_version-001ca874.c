
/* WARNING: Unknown calling convention */

void set_block_header_version(uint32_t value,uint32_t num,uint32_t mask)

{
  uint uVar1;
  int bits;
  int iVar2;
  uint uVar3;
  uint val;
  uint val_00;
  bool bVar4;
  uchar index [8];
  
  iVar2 = 0;
  uVar1 = 0;
  index[0] = '\0';
  index[1] = '\0';
  index[2] = '\0';
  index[3] = '\0';
  index[4] = '\0';
  index[5] = '\0';
  index[6] = '\0';
  index[7] = '\0';
  do {
    bVar4 = (1 << (uVar1 & 0xff) & mask) != 0;
    if (bVar4) {
      index[iVar2] = (uchar)uVar1;
    }
    uVar1 = uVar1 + 1;
    if (bVar4) {
      iVar2 = iVar2 + 1;
    }
  } while (iVar2 < 8 && uVar1 < 0x20);
  if (num == 4) {
    fpga_write(0x2e,value);
    uVar1 = 1 << index[0] | value;
    fpga_write(0x3a,uVar1);
    uVar3 = 1 << index[1];
    fpga_write(0x3b,value | uVar3);
    fpga_write(0x3c,uVar1 | uVar3);
    return;
  }
  if (num == 8) {
    fpga_write(0x2e,value);
    val = 1 << index[0] | value;
    fpga_write(0x3a,val);
    val_00 = value | 1 << index[1];
    uVar3 = 1 << index[1] | val;
    fpga_write(0x3b,val_00);
    uVar1 = 1 << index[2];
    fpga_write(0x3c,value | uVar1);
    fpga_write(0x3d,uVar3);
    fpga_write(0x3e,val | uVar1);
    fpga_write(0x3f,val_00 | uVar1);
    fpga_write(0x40,uVar1 | uVar3);
    return;
  }
  fpga_write(0x2e,value);
  return;
}

