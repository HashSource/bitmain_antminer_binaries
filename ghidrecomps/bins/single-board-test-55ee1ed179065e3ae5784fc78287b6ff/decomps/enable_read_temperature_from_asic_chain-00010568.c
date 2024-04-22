
void enable_read_temperature_from_asic_chain(undefined param_1,undefined param_2)

{
  if (Conf._116_4_ == 0x6ba) {
    set_BM1722_asic_register(param_1,param_2,0x1c,0,Conf._260_4_ << 8 | 0x7006061);
  }
  else if (Conf._116_4_ == 0x6bd) {
    set_BM1725_asic_register(param_1,param_2,0x1c,0,Conf._260_4_ << 8 | 0x7006061);
  }
  return;
}

