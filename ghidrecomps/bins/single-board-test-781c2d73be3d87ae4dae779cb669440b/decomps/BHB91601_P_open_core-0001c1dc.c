
/* WARNING: Unknown calling convention */

void BHB91601_P_open_core(uchar which_chain)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint buf_vil_tw [13];
  
  uVar3 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  printf("\n--- %s: Chain : %d\n",DAT_0001c2d8,uVar3);
  gIsOpenCoreEnd = false;
  gIsOpeningCore = true;
  uVar2 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar2 & 0xffffffdf);
  uVar1 = DAT_0001c2d8;
  iVar4 = 0;
  write_axi_fpga(0x24,0);
  memset(buf_vil_tw,0,0x34);
  do {
    BM1391_enable_core_clock(which_chain,'\0',(uchar)iVar4,'\x01');
    usleep(5000);
    while (uVar2 = read_axi_fpga(3), (uVar2 & 1 << uVar3) == 0) {
      printf("%s: chain%d work fifo not ready: 0x%x\n",uVar1,uVar3);
      usleep(3000);
    }
    iVar4 = iVar4 + 1;
    buf_vil_tw[0] = uVar3 << 0x10 | 0x1000080;
    set_TW_write_command(buf_vil_tw);
    usleep(Conf.OpenCoreGap);
  } while (iVar4 != 0x100);
  uVar3 = read_axi_fpga(0x30);
  write_axi_fpga(0x30,uVar3 | 0x400000);
  gIsOpeningCore = false;
  gIsOpenCoreEnd = true;
  return;
}

