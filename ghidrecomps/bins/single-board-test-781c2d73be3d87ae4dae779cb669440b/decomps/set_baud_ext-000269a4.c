
/* WARNING: Unknown calling convention */

void set_baud_ext(uchar which_chain,uchar chip_addr,_Bool mode)

{
  fast_UART_configuration_t fast_uart_conf;
  
  printf("\n--- %s: set baud ext\n",DAT_000269f8);
  BM1397_set_config(which_chain,chip_addr,'h',0xc0700111,mode);
  BM1397_set_config(which_chain,chip_addr,'(',0x600000f,mode);
  return;
}

