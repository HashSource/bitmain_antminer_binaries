
/* WARNING: Unknown calling convention */

void BHB07601_open_core(uchar which_chain)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint buf_vil_tw [13];
  
  uVar3 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  printf("\n--- %s: Chain : %d\n",DAT_00020390,uVar3);
  uVar1 = DAT_00020390;
  gIsOpenCoreEnd = false;
  gIsOpeningCore = true;
  uVar5 = 0;
  uVar2 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar2 & 0xffffffdf);
  write_axi_fpga(0x24,0);
  memset(buf_vil_tw,0,0x34);
  do {
    uVar2 = uVar5;
    do {
      usleep(1000);
      uVar4 = uVar2 + 0x54;
      BM1397_enable_core_clock(which_chain,'\0',uVar2,'\x01');
      uVar2 = uVar4;
    } while (uVar4 != uVar5 + 0x150);
    usleep(5000);
    while (uVar2 = read_axi_fpga(3), (1 << uVar3 & uVar2) == 0) {
      printf("%s: chain%d work fifo not ready: 0x%x\n",uVar1,uVar3);
      usleep(3000);
    }
    uVar5 = uVar5 + 1;
    buf_vil_tw[0] = uVar3 << 0x10 | 0x1000080;
    set_TW_write_command(buf_vil_tw);
    usleep(Conf.OpenCoreGap);
  } while (uVar5 != 0x54);
  uVar3 = read_axi_fpga(0x30);
  write_axi_fpga(0x30,uVar3 | 0x400000);
  gIsOpeningCore = false;
  gIsOpenCoreEnd = true;
  return;
}

