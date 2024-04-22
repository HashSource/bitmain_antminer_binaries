
/* WARNING: Unknown calling convention */

void BHB91601_S_pre_open_core(uchar which_chain)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint buf_vil_tw [13];
  
  uVar3 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  printf("\n--- %s: Chain : %d\n",DAT_0001c5e4,uVar3);
  uVar4 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar4 & 0xffffffdf);
  write_axi_fpga(0x24,0);
  memset(buf_vil_tw,0,0x34);
  uVar2 = DAT_0001c5e4;
  if (Conf.OpenCoreNum2 != 0) {
    uVar4 = 0;
    do {
      iVar6 = 0;
      do {
        usleep(1000);
        cVar1 = (char)iVar6;
        iVar6 = iVar6 + 1;
        BM1391_enable_core_clock(which_chain,'\0',(char)uVar4 + cVar1 * '@','\x01');
      } while (iVar6 != 4);
      usleep(5000);
      while (uVar5 = read_axi_fpga(3), (uVar5 & 1 << uVar3) == 0) {
        printf("%s: chain%d work fifo not ready: 0x%x\n",uVar2,uVar3);
        usleep(3000);
      }
      buf_vil_tw[0] = uVar3 << 0x10 | 0x1000080;
      set_TW_write_command(buf_vil_tw);
      uVar4 = uVar4 + 1;
      usleep(Conf.OpenCoreGap);
    } while (uVar4 < Conf.OpenCoreNum2);
  }
  return;
}

