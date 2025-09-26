
void * recv_routine(void *arg)

{
  uint32_t uVar1;
  pthread_t __th;
  void *arg_local;
  char tmp42 [256];
  return_nonce_128bit_t reg_buf;
  pattern_runtime_ctx *ctx;
  uint32_t nonce_number;
  uint32_t i;
  
  nonce_number = 0;
  i = 0;
  ctx = (pattern_runtime_ctx *)arg;
  snprintf(tmp42,0x100,"BTC start %s","recv_routine");
  puts(tmp42);
  flush_nonce3_buffer();
  while (ctx->recv_nonce != 0) {
    usleep(5);
    uVar1 = get_nonce_number_in_fifo();
    nonce_number = uVar1 >> 1;
    if (nonce_number != 0) {
      for (i = 0; i < nonce_number; i = i + 1) {
        get_return_nonce_128bit(reg_buf.buf);
        if ((reg_buf.buf[0]._3_1_ & 0x80) == 0) {
          (*(ctx->pt_ops).process_reg)(&reg_buf,arg);
        }
        else if (ctx->pause_recv_nonce == 0) {
          (*(ctx->pt_ops).process_nonce)(&reg_buf,arg);
        }
        else {
          builtin_strncpy(tmp42,"already stoped recv nonc",0x18);
          tmp42[0x18] = 'e';
          tmp42[0x19] = '!';
          tmp42[0x1a] = '\0';
          puts(tmp42);
        }
      }
    }
  }
  snprintf(tmp42,0x100,"BTC recv %s stop","recv_routine");
  puts(tmp42);
  __th = pthread_self();
  pthread_detach(__th);
  return (void *)0x0;
}

