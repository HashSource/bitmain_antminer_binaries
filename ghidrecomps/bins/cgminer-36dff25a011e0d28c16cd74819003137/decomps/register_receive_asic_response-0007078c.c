
void register_receive_asic_response(int chain,uint8_t asic,uint8_t reg,reg_status_t *reg_status)

{
  reg_status_t *reg_status_local;
  uint8_t reg_local;
  uint8_t asic_local;
  int chain_local;
  _Bool found;
  int try_count;
  
  try_count = 10;
  found = false;
  while ((found != true && (try_count != 0))) {
    cgsleep_ms(300);
    pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
    if (reg_value_buf.reg_value_num != 0) {
      found = register_process_asic_response(chain,asic,reg,&reg_status->reg_response);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    try_count = try_count + -1;
  }
  if (found != false) {
    reg_status->found = '\x01';
  }
  return;
}

