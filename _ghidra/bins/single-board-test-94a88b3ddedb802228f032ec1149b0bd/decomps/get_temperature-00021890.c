
uint get_temperature(uint param_1)

{
  int iVar1;
  uint local_c;
  
  local_c = 0;
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
    iVar1 = get_temperature_0_3();
    local_c = iVar1 >> ((param_1 & 0x1f) << 3) & 0xff;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    iVar1 = get_temperature_4_7();
    local_c = iVar1 >> ((param_1 - 4) * 8 & 0xff) & 0xff;
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
    iVar1 = get_temperature_8_11();
    local_c = iVar1 >> ((param_1 - 8) * 8 & 0xff) & 0xff;
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    iVar1 = get_temperature_12_15();
    local_c = iVar1 >> ((param_1 - 0xc) * 8 & 0xff) & 0xff;
    break;
  default:
    printf("Chain = %d, but it is wrong! \n",param_1);
  }
  return local_c;
}

