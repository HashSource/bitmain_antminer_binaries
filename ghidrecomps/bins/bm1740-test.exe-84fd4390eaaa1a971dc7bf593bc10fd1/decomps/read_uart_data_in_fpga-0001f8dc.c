
uint read_uart_data_in_fpga(byte param_1,int param_2,uint param_3)

{
  undefined uVar1;
  undefined uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  switch(param_1) {
  case 0:
    local_c = 0x44c;
    local_10 = 0x44d;
    break;
  case 1:
    local_c = 0x44e;
    local_10 = 0x44f;
    break;
  case 2:
    local_c = 0x450;
    local_10 = 0x451;
    break;
  case 3:
    local_c = 0x452;
    local_10 = 0x453;
    break;
  case 4:
    local_c = 0x454;
    local_10 = 0x455;
    break;
  case 5:
    local_c = 0x456;
    local_10 = 0x457;
    break;
  case 6:
    local_c = 0x458;
    local_10 = 0x459;
    break;
  case 7:
    local_c = 0x45a;
    local_10 = 0x45b;
    break;
  case 8:
    local_c = 0x45c;
    local_10 = 0x45d;
    break;
  case 9:
    local_c = 0x45e;
    local_10 = 0x45f;
    break;
  default:
    printf("%s: The uart%d is not supported!!!\n","read_uart_data_in_fpga");
    return 0;
  }
  write_axi_fpga(local_c,param_3 & 0x3ff | 0x80000000);
  for (local_14 = 0; local_14 < param_3 >> 2; local_14 = local_14 + 1) {
    uVar3 = read_axi_fpga(local_10);
    *(char *)(param_2 + local_14 * 4) = (char)((uint)uVar3 >> 0x18);
    *(char *)(param_2 + local_14 * 4 + 1) = (char)((uint)uVar3 >> 0x10);
    *(char *)(param_2 + local_14 * 4 + 2) = (char)((uint)uVar3 >> 8);
    *(char *)(param_2 + local_14 * 4 + 3) = (char)uVar3;
  }
  uVar4 = param_3 & 0xfffffffc;
  param_3 = param_3 & 3;
  if (param_3 != 0) {
    uVar3 = read_axi_fpga(local_10);
    uVar2 = (undefined)((uint)uVar3 >> 0x10);
    uVar1 = (undefined)((uint)uVar3 >> 0x18);
    if (param_3 == 2) {
      *(undefined *)(param_2 + local_14 * 4) = uVar1;
      *(undefined *)(param_2 + local_14 * 4 + 1) = uVar2;
      uVar4 = uVar4 + 2;
    }
    else if (param_3 == 3) {
      *(undefined *)(param_2 + local_14 * 4) = uVar1;
      *(undefined *)(param_2 + local_14 * 4 + 1) = uVar2;
      *(char *)(param_2 + local_14 * 4 + 2) = (char)((uint)uVar3 >> 8);
      uVar4 = uVar4 + 3;
    }
    else if (param_3 == 1) {
      *(undefined *)(param_2 + local_14 * 4) = uVar1;
      uVar4 = uVar4 + 1;
    }
    else {
      printf("%s: the uart%d left data is 4*N length, error!!!\n","read_uart_data_in_fpga",
             (uint)param_1);
    }
  }
  return uVar4;
}

