
/* WARNING: Unknown calling convention */

uchar read_temperature_from_fpga_register(uchar which_chain)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)which_chain;
  switch(uVar1) {
  case 0:
  case 1:
  case 2:
  case 3:
    uVar2 = read_axi_fpga(8);
    uVar2 = uVar2 >> ((uVar1 & 0x1f) << 3) & 0xff;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    uVar2 = read_axi_fpga(9);
    uVar2 = uVar2 >> ((uVar1 - 4) * 8 & 0xff) & 0xff;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    uVar2 = read_axi_fpga(10);
    uVar2 = uVar2 >> ((uVar1 - 8) * 8 & 0xff) & 0xff;
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    uVar2 = read_axi_fpga(0xb);
    uVar2 = uVar2 >> ((uVar1 - 0xc) * 8 & 0xff) & 0xff;
    break;
  default:
    uVar2 = 0;
    printf("%s: which_chain = %d, but it is wrong! \n","read_temperature_from_fpga_register",
           (uint)gChain);
    printf("\n%s: Chain%d temperature is %d\n\n","read_temperature_from_fpga_register",uVar1,0);
    goto LAB_0002463a;
  }
  printf("\n%s: Chain%d temperature is %d\n\n","read_temperature_from_fpga_register",uVar1,uVar2);
  if (uVar2 != 0) {
    gSensor_OK[uVar1][0] = true;
  }
LAB_0002463a:
  if (Conf.StartTemp <= (int)uVar2) {
    gStartTest = true;
  }
  if (Conf.AlarmTemp < (int)uVar2) {
    gHigherThanAlarmTemp = true;
  }
  return (uchar)uVar2;
}

