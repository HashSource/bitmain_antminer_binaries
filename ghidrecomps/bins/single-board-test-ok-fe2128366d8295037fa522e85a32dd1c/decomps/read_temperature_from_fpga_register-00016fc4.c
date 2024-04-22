
byte read_temperature_from_fpga_register(byte param_1)

{
  uint uVar1;
  byte local_9;
  
  local_9 = 0;
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
    uVar1 = read_axi_fpga(8);
    local_9 = (byte)(uVar1 >> ((param_1 & 0x1f) << 3));
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    uVar1 = read_axi_fpga(9);
    local_9 = (byte)(uVar1 >> ((param_1 - 4) * 8 & 0xff));
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    uVar1 = read_axi_fpga(10);
    local_9 = (byte)(uVar1 >> ((param_1 - 8) * 8 & 0xff));
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    uVar1 = read_axi_fpga(0xb);
    local_9 = (byte)(uVar1 >> ((param_1 - 0xc) * 8 & 0xff));
    break;
  default:
    printf("%s: which_chain = %d, but it is wrong! \n","read_temperature_from_fpga_register",
           (uint)gChain);
  }
  printf("\n%s: Chain%d temperature is %d\n\n","read_temperature_from_fpga_register",(uint)param_1,
         (uint)local_9);
  if (local_9 != 0) {
    gSensor_OK[(uint)param_1 * 4] = 1;
  }
  if ((int)Conf[224] <= (int)(uint)local_9) {
    gStartTest = 1;
  }
  if ((int)Conf[226] < (int)(uint)local_9) {
    gHigherThanAlarmTemp = 1;
  }
  return local_9;
}

