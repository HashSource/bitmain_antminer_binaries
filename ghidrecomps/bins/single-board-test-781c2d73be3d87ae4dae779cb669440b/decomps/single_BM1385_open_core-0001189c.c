
/* WARNING: Unknown calling convention */

void single_BM1385_open_core(uchar which_chain)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint OpenCoreNum1;
  uint uVar6;
  uint OpenCoreNum2;
  uint uVar7;
  uchar data [64];
  
  memset(data,0,0x40);
  uVar7 = Conf.OpenCoreNum2;
  uVar6 = Conf.OpenCoreNum1;
  data[0] = 0xff;
  iVar5 = 0x32;
  printf("\n--- %s: Chain : %d\n",DAT_0001196c,(uint)which_chain);
  gIsOpenCoreEnd = false;
  memset(data,0,0x40);
  BM1385_set_gateblk(which_chain,'\0',true);
  do {
    uart_send(which_chain,data,0x40);
    usleep(Conf.OpenCoreGap);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  memset(data,0,0x40);
  BM1385_set_gateblk(which_chain,'\0',true);
  uVar4 = 0;
  do {
    if (uVar4 < 0x20) {
      uVar2 = uVar6 >> 1;
      uVar3 = uVar7;
      uVar1 = uVar6;
    }
    else {
      uVar2 = uVar6;
      uVar3 = uVar7 >> 1;
      uVar1 = uVar7;
    }
    uVar7 = uVar3;
    uVar6 = uVar2;
    if ((uVar1 & 1) != 0) {
      data[52] = 0xff;
    }
    uVar4 = uVar4 + 1;
    uart_send(which_chain,data,0x40);
    usleep(Conf.OpenCoreGap);
  } while (uVar4 != 0x32);
  gIsOpenCoreEnd = true;
  return;
}

