
void * recv_routine(void *arg)

{
  uint32_t uVar1;
  pthread_t __th;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  return_nonce_128bit_t reg_buf;
  pattern_runtime_ctx *ctx;
  uint32_t nonce_number;
  uint32_t i;
  
  nonce_number = 0;
  i = 0;
  ctx = (pattern_runtime_ctx *)arg;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : BTC start %s\n","recv_routine","recv_routine");
  snprintf(tmp1,0x100,"BTC start %s","recv_routine");
  log_to_file(tmp1,time_stamp);
  flush_nonce3_buffer();
  while (ctx->recv_nonce != 0) {
    usleep(5);
    uVar1 = get_nonce_number_in_fifo();
    nonce_number = uVar1 >> 1;
    if (nonce_number != 0) {
      for (i = 0; i < nonce_number; i = i + 1) {
        get_return_nonce_128bit(reg_buf.buf);
        if (ctx->pause_recv_nonce == 0) {
          if ((reg_buf.buf[0]._3_1_ & 0x80) == 0) {
            (*(ctx->pt_ops).process_reg)(&reg_buf,arg);
          }
          else {
            (*(ctx->pt_ops).process_nonce)(&reg_buf,arg);
          }
        }
      }
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : BTC recv %s stop\n","recv_routine","recv_routine");
  snprintf(tmp1,0x100,"BTC recv %s stop","recv_routine");
  log_to_file(tmp1,time_stamp);
  __th = pthread_self();
  pthread_detach(__th);
  return (void *)0x0;
}

