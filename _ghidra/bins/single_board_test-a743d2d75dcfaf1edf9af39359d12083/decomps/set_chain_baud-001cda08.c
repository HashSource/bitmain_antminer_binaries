
/* WARNING: Unknown calling convention */

int32_t set_chain_baud(uint8_t which_chain,uint32_t baudrate)

{
  uint uVar1;
  undefined1 uVar2;
  int3 iVar3;
  pll_parameter_t pll1_parameter;
  fast_UART_configuration_t fast_uart_configuration;
  
  if (baudrate < 0x2dc6c1) {
    get_register_cache_value(hashboard_cache_level,which_chain,0,0x28,&fast_uart_configuration.v);
    iVar3 = __aeabi_uidiv(25000000,baudrate << 3);
    uVar1 = fast_uart_configuration.v & 0xfffe00ff;
    fast_uart_configuration.v._0_3_ = (uint3)uVar1 | (iVar3 - 1U & 0xff) << 8;
    fast_uart_configuration.v =
         CONCAT13((char)(uVar1 >> 0x18),fast_uart_configuration.v._0_3_) & 0xa3ffffff;
  }
  else {
    get_register_cache_value(hashboard_cache_level,which_chain,0,0x60,&pll1_parameter.v);
    uVar2 = pll1_parameter.v._3_1_;
    pll1_parameter.v._0_2_ = (ushort)pll1_parameter.v & 0xc088 | 0x111;
    pll1_parameter.v._2_2_ = 0x60;
    pll1_parameter.v = CONCAT13(uVar2,pll1_parameter.v._0_3_) & 0xd0ffffff | 0x50000000;
    send_set_config_command(which_chain,'\x01',0,0x60,pll1_parameter.v);
    usleep(10000);
    send_set_config_command(which_chain,'\x01',0,0x60,pll1_parameter.v);
    usleep(10000);
    get_register_cache_value(hashboard_cache_level,which_chain,0,0x28,&fast_uart_configuration.v);
    iVar3 = __aeabi_uidiv(400000000,baudrate << 3);
    uVar1 = fast_uart_configuration.v & 0xfffe00ff;
    fast_uart_configuration.v._0_3_ = (uint3)uVar1 | (iVar3 - 1U & 0xff) << 8;
    fast_uart_configuration.v =
         CONCAT13((char)(uVar1 >> 0x18),fast_uart_configuration.v._0_3_) & 0xe7ffffff;
    uVar1 = fast_uart_configuration.v >> 0x10 & 0xfc0f;
    fast_uart_configuration.v =
         CONCAT13((char)(uVar1 >> 8),(int3)CONCAT22((short)uVar1,fast_uart_configuration.v._0_2_)) |
         0x84500000;
  }
  send_set_config_command(which_chain,'\x01',0,0x28,fast_uart_configuration.v);
  usleep(10000);
  usleep(50000);
  set_bt8d_chain((uint)which_chain,baudrate);
  return 0;
}

