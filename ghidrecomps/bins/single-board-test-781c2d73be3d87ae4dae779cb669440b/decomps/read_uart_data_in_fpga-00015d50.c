
/* WARNING: Unknown calling convention */

uint read_uart_data_in_fpga(uchar which_uart,uchar *buf,uint length)

{
  uchar uVar1;
  uchar uVar2;
  uint uVar3;
  uint uVar4;
  uchar *puVar5;
  uchar *puVar6;
  uint uVar7;
  
  switch(which_uart) {
  case '\0':
    uVar7 = 0x85;
    uVar4 = 0x84;
    break;
  case '\x01':
    uVar7 = 0x87;
    uVar4 = 0x86;
    break;
  case '\x02':
    uVar7 = 0x89;
    uVar4 = 0x88;
    break;
  case '\x03':
    uVar7 = 0x8b;
    uVar4 = 0x8a;
    break;
  case '\x04':
    uVar7 = 0x8d;
    uVar4 = 0x8c;
    break;
  case '\x05':
    uVar7 = 0x8f;
    uVar4 = 0x8e;
    break;
  case '\x06':
    uVar7 = 0x91;
    uVar4 = 0x90;
    break;
  case '\a':
    uVar7 = 0x93;
    uVar4 = 0x92;
    break;
  case '\b':
    uVar7 = 0x95;
    uVar4 = 0x94;
    break;
  case '\t':
    uVar7 = 0x97;
    uVar4 = 0x96;
    break;
  default:
    printf("%s: The uart is not supported!!!\n",DAT_00015e54);
    return 0;
  }
  write_axi_fpga(uVar4,length & 0x3ff | 0x80000000);
  if (length >> 2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = length & 0xfffffffc;
    puVar5 = buf;
    do {
      puVar6 = puVar5 + 4;
      uVar3 = read_axi_fpga(uVar7);
      puVar5[3] = (uchar)uVar3;
      *puVar5 = (uchar)(uVar3 >> 0x18);
      puVar5[1] = (uchar)(uVar3 >> 0x10);
      puVar5[2] = (uchar)(uVar3 >> 8);
      puVar5 = puVar6;
    } while (puVar6 != buf + uVar4);
  }
  uVar3 = length & 3;
  if (uVar3 == 0) {
    return uVar4;
  }
  uVar7 = read_axi_fpga(uVar7);
  uVar1 = (uchar)(uVar7 >> 0x10);
  uVar2 = (uchar)(uVar7 >> 0x18);
  if (uVar3 == 2) {
    buf[length & 0xfffffffc] = uVar2;
    buf[uVar4 + 1] = uVar1;
    return uVar4 + 2;
  }
  if (uVar3 != 3) {
    buf[length & 0xfffffffc] = uVar2;
    return uVar4 + 1;
  }
  buf[length & 0xfffffffc] = uVar2;
  buf[uVar4 + 1] = uVar1;
  buf[uVar4 + 2] = (uchar)(uVar7 >> 8);
  return uVar4 + 3;
}

