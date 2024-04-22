
void inc_dev_status(int max_fan,int max_temp)

{
  int max_temp_local;
  int max_fan_local;
  
  _mutex_lock(&stats_lock,"cgminer.c","inc_dev_status",0x21da);
  g_max_fan = max_fan;
  g_max_temp = max_temp;
  _mutex_unlock(&stats_lock,"cgminer.c","inc_dev_status",0x21dd);
  return;
}

