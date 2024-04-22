
void register_receive_core_response(int chain,uint8_t asic,core_reg_status_t *core_reg_status)

{
  int iVar1;
  core_reg_status_t *core_reg_status_local;
  uint8_t asic_local;
  int chain_local;
  _Bool found;
  int try_count;
  
  try_count = 10;
  found = false;
  while ((found != true && (iVar1 = try_count + -1, try_count != 0))) {
    pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
    if (reg_value_buf.reg_value_num != 0) {
      found = register_process_core_response(chain,asic,core_reg_status);
    }
    pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    try_count = iVar1;
    if (found != true) {
      cgsleep_ms(300);
    }
  }
  if (found != false) {
    core_reg_status->found = '\x01';
  }
  return;
}

