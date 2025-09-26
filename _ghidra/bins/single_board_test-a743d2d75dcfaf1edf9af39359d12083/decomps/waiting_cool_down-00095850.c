
_Bool waiting_cool_down(uint32_t max_wait_time,int8_t *temp,int8_t sensor_num,int gap)

{
  int8_t iVar1;
  int8_t iVar2;
  int gap_local;
  int8_t sensor_num_local;
  int8_t *temp_local;
  uint32_t max_wait_time_local;
  char tmp42 [256];
  uint8_t i;
  uint32_t wait_time;
  _Bool result;
  
  wait_time = 0;
  do {
    iVar1 = pf_get_max_value(temp,sensor_num);
    iVar2 = pf_get_min_value(temp,sensor_num);
    if (((int)iVar1 - (int)iVar2 < gap) && (iVar1 = pf_get_min_value(temp,sensor_num), iVar1 < '$'))
    {
      builtin_strncpy(tmp42,"Hashboard cool down, begin test ...",0x24);
      puts(tmp42);
      return true;
    }
    sleep(1);
    wait_time = wait_time + 1;
    if (wait_time % 10 == 0) {
      snprintf(tmp42,0x100,"Waiting for Hashboard cool down for %d seconds ...",wait_time);
      puts(tmp42);
    }
  } while (wait_time <= max_wait_time);
  snprintf(tmp42,0x100,"Wait for Hashboard cool down for %d seconds, break",wait_time);
  puts(tmp42);
  return false;
}

