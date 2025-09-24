
/* WARNING: Unknown calling convention */

uint32_t read_uart_data_in_fpga(uint32_t which_uart,uint8_t *buf,uint32_t length)

{
  uint8_t uVar1;
  uint32_t uVar2;
  uint8_t *puVar3;
  uint8_t *puVar4;
  uint32_t address;
  uint uVar5;
  uint uVar6;
  uint ret_data;
  char tmp42 [2048];
  
  ret_data = 0;
  switch(which_uart) {
  case 0:
    address = 0x61;
    uVar2 = 0x60;
    break;
  case 1:
    address = 99;
    uVar2 = 0x62;
    break;
  case 2:
    address = 0x65;
    uVar2 = 100;
    break;
  case 3:
    address = 0x67;
    uVar2 = 0x66;
    break;
  case 4:
    address = 0x69;
    uVar2 = 0x68;
    break;
  case 5:
    address = 0x6b;
    uVar2 = 0x6a;
    break;
  case 6:
    address = 0x6d;
    uVar2 = 0x6c;
    break;
  case 7:
    address = 0x6f;
    uVar2 = 0x6e;
    break;
  case 8:
    address = 0x71;
    uVar2 = 0x70;
    break;
  case 9:
    address = 0x73;
    uVar2 = 0x72;
    break;
  case 10:
    address = 0x7d;
    uVar2 = 0x7c;
    break;
  case 0xb:
    address = 0x7f;
    uVar2 = 0x7e;
    break;
  case 0xc:
    address = 0x81;
    uVar2 = 0x80;
    break;
  case 0xd:
    address = 0x83;
    uVar2 = 0x82;
    break;
  default:
    snprintf(tmp42,0x800,"%s: The uart%d is not supported!!!\n","get_read_address_info",which_uart);
    _applog(0,tmp42,false);
    snprintf(tmp42,0x800,"get_read_address_info error, chain_id = %d\n",which_uart);
    _applog(0,tmp42,false);
    return 0;
  }
  fpga_write(uVar2,length & 0x3ff | 0x80000000);
  uVar6 = length >> 2;
  if (uVar6 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = uVar6 * 4;
    puVar3 = buf;
    do {
      fpga_read(address,&ret_data);
      puVar4 = puVar3 + 4;
      puVar3[3] = (uint8_t)ret_data;
      *puVar3 = (uint8_t)(ret_data >> 0x18);
      puVar3[1] = (uint8_t)(ret_data >> 0x10);
      puVar3[2] = (uint8_t)(ret_data >> 8);
      puVar3 = puVar4;
    } while (buf + uVar2 != puVar4);
  }
  uVar5 = length & 3;
  if (uVar5 != 0) {
    fpga_read(address,&ret_data);
    uVar1 = (uint8_t)(ret_data >> 0x10);
    if (uVar5 == 2) {
      buf[uVar6 * 4] = ret_data._3_1_;
      buf[uVar2 + 1] = uVar1;
      uVar2 = uVar2 + 2;
    }
    else if (uVar5 == 3) {
      buf[uVar6 * 4] = ret_data._3_1_;
      buf[uVar2 + 1] = uVar1;
      buf[uVar2 + 2] = (uint8_t)(ret_data >> 8);
      uVar2 = uVar2 + 3;
    }
    else {
      buf[uVar6 * 4] = ret_data._3_1_;
      uVar2 = uVar2 + 1;
    }
  }
  return uVar2;
}

