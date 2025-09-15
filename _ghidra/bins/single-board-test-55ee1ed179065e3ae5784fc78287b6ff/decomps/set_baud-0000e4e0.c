
void set_baud(byte param_1,byte param_2)

{
  printf("\n--- %s: Chain : %d, baud = %d\n","set_baud",(uint)param_1,(uint)param_2);
  if (Conf._116_4_ == 0x6ba) {
    set_BM1722_asic_register(param_1,0,0x1c,1,(uint)param_2 << 8 | 0x7002001);
  }
  else if (Conf._116_4_ == 0x6bd) {
    set_BM1725_asic_register(param_1,0,0x1c,1,(uint)param_2 << 8 | 0x7002001);
  }
  usleep(50000);
  uart_set_baud(param_1,param_2);
  return;
}

