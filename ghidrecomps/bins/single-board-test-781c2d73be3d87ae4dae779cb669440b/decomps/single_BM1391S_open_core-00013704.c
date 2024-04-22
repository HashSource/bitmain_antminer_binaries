
/* WARNING: Unknown calling convention */

void single_BM1391S_open_core(uchar which_chain)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  __useconds_t __useconds;
  int iVar4;
  int iVar5;
  uint buf_vil_tw [13];
  
  uVar2 = (uint)which_chain;
  memset(buf_vil_tw,0,0x34);
  printf("\n--- %s: Chain : %d\n",DAT_000137ec,uVar2);
  gIsOpenCoreEnd = false;
  iVar5 = 0;
  uVar3 = read_axi_fpga(0x40);
  write_axi_fpga(0x40,uVar3 & 0xffffffdf);
  write_axi_fpga(0x24,0);
  memset(buf_vil_tw,0,0x34);
  do {
    iVar4 = 0;
    do {
      usleep(1000);
      cVar1 = (char)iVar4;
      iVar4 = iVar4 + 1;
      BM1391_enable_core_clock(which_chain,'\0',(char)iVar5 + cVar1 * '@','\x01');
    } while (iVar4 != 4);
    __useconds = 5000;
    do {
      usleep(__useconds);
      uVar3 = read_axi_fpga(3);
      __useconds = 3000;
    } while ((uVar3 & 1 << uVar2) == 0);
    iVar5 = iVar5 + 1;
    buf_vil_tw[0] = uVar2 << 0x10 | 0x1000080;
    set_TW_write_command(buf_vil_tw);
    usleep(Conf.OpenCoreGap);
  } while (iVar5 != 0x40);
  uVar3 = read_axi_fpga(0x30);
  write_axi_fpga(0x30,uVar3 | 0x400000);
  gIsOpenCoreEnd = true;
  printf("\n--- %s end: Chain : %d\n",DAT_000137ec,uVar2);
  return;
}

