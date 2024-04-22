
/* WARNING: Unknown calling convention */

void BHB91603_S_open_core(uchar which_chain)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint buf_vil_tw [13];
  
  uVar4 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  printf("\n--- %s: Chain : %d\n",DAT_00017138,uVar4);
  gIsOpenCoreEnd = false;
  gIsOpeningCore = true;
  uVar3 = read_axi_fpga(0x40);
  uVar2 = DAT_00017138;
  iVar5 = 0;
  write_axi_fpga(0x40,uVar3 & 0xffffffdf);
  write_axi_fpga(0x24,0);
  memset(buf_vil_tw,0,0x34);
  do {
    iVar6 = 0;
    do {
      usleep(1000);
      cVar1 = (char)iVar6;
      iVar6 = iVar6 + 1;
      BM1391_enable_core_clock(which_chain,'\0',(char)iVar5 + cVar1 * '@','\x01');
    } while (iVar6 != 4);
    usleep(5000);
    while (uVar3 = read_axi_fpga(3), (uVar3 & 1 << uVar4) == 0) {
      printf("%s: chain%d work fifo not ready: 0x%x\n",uVar2,uVar4);
      usleep(3000);
    }
    iVar5 = iVar5 + 1;
    buf_vil_tw[0] = uVar4 << 0x10 | 0x1000080;
    set_TW_write_command(buf_vil_tw);
    usleep(Conf.OpenCoreGap);
  } while (iVar5 != 0x40);
  uVar4 = read_axi_fpga(0x30);
  write_axi_fpga(0x30,uVar4 | 0x400000);
  gIsOpeningCore = false;
  gIsOpenCoreEnd = true;
  return;
}

