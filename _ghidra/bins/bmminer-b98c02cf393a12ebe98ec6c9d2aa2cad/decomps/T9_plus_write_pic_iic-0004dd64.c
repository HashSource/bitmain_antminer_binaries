
void T9_plus_write_pic_iic(int param_1,int param_2,int param_3,uint param_4,byte param_5)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(axi_fpga_addr + 0x30);
  while (-1 < iVar2) {
    usleep(1000);
    iVar2 = *(int *)(axi_fpga_addr + 0x30);
  }
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x2000000;
  }
  if (param_2 != 0) {
    uVar1 = uVar1 | param_3 << 8 | 0x1000000;
  }
  set_iic(uVar1 | param_5 | 0x400000 | (param_4 & 0xf) << 0x10);
  return;
}

