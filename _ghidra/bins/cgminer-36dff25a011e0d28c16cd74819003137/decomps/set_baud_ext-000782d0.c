
void set_baud_ext(int chain)

{
  int chain_local;
  fast_UART_configuration_t fast_uart_conf;
  pll_parameter_t pll_param;
  
  send_set_config_command(chain,'\x01','\0','h',0xc0700111);
  send_set_config_command(chain,'\x01','\0','h',0xc0700111);
  send_set_config_command(chain,'\x01','\0','(',0x600000f);
  return;
}

