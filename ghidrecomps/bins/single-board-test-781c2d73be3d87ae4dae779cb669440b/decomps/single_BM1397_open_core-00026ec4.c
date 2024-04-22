
/* WARNING: Unknown calling convention */

void single_BM1397_open_core(uchar which_chain)

{
  uint uVar1;
  uint uVar2;
  __useconds_t __useconds;
  uint uVar3;
  uint uVar4;
  uint buf_vil_tw [13];
  
  uVar1 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  printf("\n--- %s: Chain : %d\n",DAT_00026fac,uVar1);
  gIsOpenCoreEnd = false;
  uVar4 = 0;
  uVar2 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar2 & 0xffffffdf);
  write_axi_fpga(0x24,0);
  memset(buf_vil_tw,0,0x34);
  do {
    uVar2 = uVar4;
    do {
      usleep(1000);
      uVar3 = uVar2 + 0x54;
      BM1397_enable_core_clock(which_chain,'\0',uVar2,'\x01');
      uVar2 = uVar3;
    } while (uVar3 != uVar4 + 0x150);
    __useconds = 5000;
    do {
      usleep(__useconds);
      uVar2 = read_axi_fpga(3);
      __useconds = 3000;
    } while ((1 << uVar1 & uVar2) == 0);
    uVar4 = uVar4 + 1;
    buf_vil_tw[0] = uVar1 << 0x10 | 0x1000080;
    set_TW_write_command(buf_vil_tw);
    usleep(Conf.OpenCoreGap);
  } while (uVar4 != 0x54);
  uVar2 = read_axi_fpga(0x30);
  write_axi_fpga(0x30,uVar2 | 0x400000);
  gIsOpenCoreEnd = true;
  printf("\n--- %s end: Chain : %d\n",DAT_00026fac,uVar1);
  return;
}

