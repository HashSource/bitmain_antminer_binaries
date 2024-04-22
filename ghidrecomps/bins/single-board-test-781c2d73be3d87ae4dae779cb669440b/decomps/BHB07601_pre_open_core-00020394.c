
/* WARNING: Unknown calling convention */

void BHB07601_pre_open_core(uchar which_chain)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint buf_vil_tw [13];
  
  uVar2 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  printf("\n--- %s: Chain : %d\n",DAT_00020474,uVar2);
  uVar3 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar3 & 0xffffffdf);
  write_axi_fpga(0x24,0);
  memset(buf_vil_tw,0,0x34);
  uVar1 = DAT_00020474;
  if (Conf.OpenCoreNum2 != 0) {
    uVar3 = 0;
    do {
      uVar4 = uVar3;
      do {
        usleep(1000);
        uVar5 = uVar4 + 0x54;
        BM1397_enable_core_clock(which_chain,'\0',uVar4,'\x01');
        uVar4 = uVar5;
      } while (uVar3 + 0x150 != uVar5);
      usleep(5000);
      while (uVar4 = read_axi_fpga(3), (1 << uVar2 & uVar4) == 0) {
        printf("%s: chain%d work fifo not ready: 0x%x\n",uVar1,uVar2);
        usleep(3000);
      }
      uVar3 = uVar3 + 1;
      buf_vil_tw[0] = uVar2 << 0x10 | 0x1000080;
      set_TW_write_command(buf_vil_tw);
      usleep(Conf.OpenCoreGap);
    } while (uVar3 < Conf.OpenCoreNum2);
  }
  return;
}

