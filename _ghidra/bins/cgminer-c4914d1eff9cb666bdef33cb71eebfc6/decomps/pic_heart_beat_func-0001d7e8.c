
void * pic_heart_beat_func(void *arg)

{
  _Bool _Var1;
  void *arg_local;
  _Bool check_set_voltage_flag;
  uint8_t i;
  
  do {
    while( true ) {
      pthread_mutex_lock((pthread_mutex_t *)&set_voltage_lock);
      _Var1 = set_voltage_flag;
      pthread_mutex_unlock((pthread_mutex_t *)&set_voltage_lock);
      if (_Var1 == false) break;
      sleep(10);
    }
    for (i = '\0'; i < 0x10; i = i + '\x01') {
      if ((dev->chain_exist[i] != 0) && (pattern_info_t.stop_heart_beat[i] == false)) {
        pic_heart_beat_each_chain(i);
      }
    }
    sleep(10);
  } while( true );
}

