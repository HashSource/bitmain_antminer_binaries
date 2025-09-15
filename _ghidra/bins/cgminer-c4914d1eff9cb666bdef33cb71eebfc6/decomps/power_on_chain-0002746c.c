
void power_on_chain(int chain)

{
  int chain_local;
  
  disable_pic_dac((uint8_t)chain);
  set_reset_hashboard(chain,1);
  sleep(1);
  enable_pic_dac((uint8_t)chain);
  sleep(1);
  set_reset_hashboard(chain,0);
  sleep(1);
  return;
}

