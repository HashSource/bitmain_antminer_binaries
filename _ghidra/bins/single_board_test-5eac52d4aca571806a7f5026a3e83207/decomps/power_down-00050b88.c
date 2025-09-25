
void power_down(uint32_t chain)

{
  uint32_t chain_local;
  
  g_rt.read_sensor_power_by_hashboard = 0;
  pf_power_down(chain);
  sleep(2);
  return;
}

