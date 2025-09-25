
void power_down_and_fan(uint32_t chain)

{
  uint32_t chain_local;
  
  pf_power_down(chain);
  sleep(2);
  pwm_set(g_fan,100);
  return;
}

