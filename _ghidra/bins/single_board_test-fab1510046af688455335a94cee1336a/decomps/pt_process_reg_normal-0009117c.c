
void pt_process_reg_normal(void *nonce)

{
  void *nonce_local;
  char tmp42 [256];
  return_nonce_128bit_t *return_nonce;
  
  if ((*(byte *)((int)nonce + 3) & 0x60) == 0) {
                    /* WARNING: Load size is inaccurate */
    if ((*nonce & 0xf) == (g_rt.config)->chain) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      reg_value_buf->reg_buffer[reg_value_buf->p_wr].reg_value = *(uint32_t *)((int)nonce + 4);
      reg_value_buf->reg_buffer[reg_value_buf->p_wr].crc = *(byte *)((int)nonce + 3) & 0x1f;
      reg_value_buf->reg_buffer[reg_value_buf->p_wr].chip_address = (uint)*(byte *)((int)nonce + 2);
      reg_value_buf->reg_buffer[reg_value_buf->p_wr].reg_address = (uint)*(byte *)((int)nonce + 1);
                    /* WARNING: Load size is inaccurate */
      reg_value_buf->reg_buffer[reg_value_buf->p_wr].chain_number = *nonce & 0xf;
      if (reg_value_buf->p_wr < 0x1fe) {
        reg_value_buf->p_wr = reg_value_buf->p_wr + 1;
      }
      else {
        reg_value_buf->p_wr = 0;
      }
      if (reg_value_buf->reg_value_num < 0x1ff) {
        reg_value_buf->reg_value_num = reg_value_buf->reg_value_num + 1;
      }
      else {
        reg_value_buf->reg_value_num = 0x1ff;
      }
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    }
    else {
                    /* WARNING: Load size is inaccurate */
      snprintf(tmp42,0x100,"receive register value from chain: %d, but not gChain: %d",*nonce & 0xf,
               (g_rt.config)->chain);
      puts(tmp42);
    }
  }
  else {
    gHashboard_received_crc_error_work = gHashboard_received_crc_error_work + 1;
    snprintf(tmp42,0x100,"gHashboard_received_crc_error_work = %d",
             gHashboard_received_crc_error_work);
    puts(tmp42);
  }
  return;
}

