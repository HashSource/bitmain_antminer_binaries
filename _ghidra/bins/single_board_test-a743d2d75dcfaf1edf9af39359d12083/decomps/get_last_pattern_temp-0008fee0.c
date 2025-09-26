
void get_last_pattern_temp(uint8_t *temp,int cnt)

{
  int cnt_local;
  uint8_t *temp_local;
  int max_cnt;
  
  max_cnt = ((g_rt.config)->board).sensor.sensor_num;
  if (cnt < max_cnt) {
    max_cnt = cnt;
  }
  memcpy(temp,g_rt.tempval,max_cnt);
  return;
}

