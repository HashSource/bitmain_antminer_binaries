
void pt_process_reg_normal(void *nonce)

{
  void *nonce_local;
  return_nonce_128bit_t *return_nonce;
  
  pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
  reg_value_buf->reg_buffer[reg_value_buf->p_wr].reg_value = *(uint32_t *)((int)nonce + 4);
  reg_value_buf->reg_buffer[reg_value_buf->p_wr].crc = *(byte *)((int)nonce + 3) & 0x1f;
  reg_value_buf->reg_buffer[reg_value_buf->p_wr].chip_address = (uint)*(byte *)((int)nonce + 2);
  reg_value_buf->reg_buffer[reg_value_buf->p_wr].reg_address = (uint)*(byte *)((int)nonce + 1);
                    /* WARNING: Load size is inaccurate */
  reg_value_buf->reg_buffer[reg_value_buf->p_wr].chain_number = *nonce & 0xf;
  if (reg_value_buf->p_wr < 0xffe) {
    reg_value_buf->p_wr = reg_value_buf->p_wr + 1;
  }
  else {
    reg_value_buf->p_wr = 0;
  }
  if (reg_value_buf->reg_value_num < 0xfff) {
    reg_value_buf->reg_value_num = reg_value_buf->reg_value_num + 1;
  }
  else {
    reg_value_buf->reg_value_num = 0xfff;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  return;
}

