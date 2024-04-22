
uint read_uart_data_in_fpga(uchar which_uart,uchar *buf,uint length)

{
  uchar uVar1;
  uchar uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint length_local;
  uchar *buf_local;
  uchar which_uart_local;
  char tmp42 [1024];
  uint ret_data;
  uint read_loop;
  uint data;
  uint ret_length;
  uint i;
  uint chain_read_data_addr;
  uint chain_read_enable_addr;
  
  switch(which_uart) {
  case '\0':
    chain_read_enable_addr = 0x44c;
    chain_read_data_addr = 0x44d;
    break;
  case '\x01':
    chain_read_enable_addr = 0x44e;
    chain_read_data_addr = 0x44f;
    break;
  case '\x02':
    chain_read_enable_addr = 0x450;
    chain_read_data_addr = 0x451;
    break;
  case '\x03':
    chain_read_enable_addr = 0x452;
    chain_read_data_addr = 0x453;
    break;
  case '\x04':
    chain_read_enable_addr = 0x454;
    chain_read_data_addr = 0x455;
    break;
  case '\x05':
    chain_read_enable_addr = 0x456;
    chain_read_data_addr = 0x457;
    break;
  case '\x06':
    chain_read_enable_addr = 0x458;
    chain_read_data_addr = 0x459;
    break;
  case '\a':
    chain_read_enable_addr = 0x45a;
    chain_read_data_addr = 0x45b;
    break;
  case '\b':
    chain_read_enable_addr = 0x45c;
    chain_read_data_addr = 0x45d;
    break;
  case '\t':
    chain_read_enable_addr = 0x45e;
    chain_read_data_addr = 0x45f;
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","read_uart_data_in_fpga",
               (uint)which_uart);
      _applog(2,tmp42,false);
    }
    return 0;
  }
  write_axi_fpga(chain_read_enable_addr,length & 0x3ff | 0x80000000);
  for (i = 0; i < length >> 2; i = i + 1) {
    uVar5 = read_axi_fpga(chain_read_data_addr);
    buf[i * 4] = (uchar)(uVar5 >> 0x18);
    buf[i * 4 + 1] = (uchar)(uVar5 >> 0x10);
    buf[i * 4 + 2] = (uchar)(uVar5 >> 8);
    buf[i * 4 + 3] = (uchar)uVar5;
  }
  uVar4 = length & 0xfffffffc;
  uVar5 = length & 3;
  if (uVar5 != 0) {
    uVar3 = read_axi_fpga(chain_read_data_addr);
    uVar2 = (uchar)(uVar3 >> 0x10);
    uVar1 = (uchar)(uVar3 >> 0x18);
    if (uVar5 == 2) {
      buf[i * 4] = uVar1;
      buf[i * 4 + 1] = uVar2;
      uVar4 = uVar4 + 2;
    }
    else if (uVar5 == 3) {
      buf[i * 4] = uVar1;
      buf[i * 4 + 1] = uVar2;
      buf[i * 4 + 2] = (uchar)(uVar3 >> 8);
      uVar4 = uVar4 + 3;
    }
    else if (uVar5 == 1) {
      buf[i * 4] = uVar1;
      uVar4 = uVar4 + 1;
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: the uart%d left data is 4*N length, error!!!\n",
               "read_uart_data_in_fpga",(uint)which_uart);
      _applog(2,tmp42,false);
    }
  }
  return uVar4;
}

