
void sw_pt_process_nonce(void *return_nonce,void *arg)

{
  void *arg_local;
  void *return_nonce_local;
  
  check_nonce((return_nonce_128bit_t *)return_nonce,(pattern_runtime_ctx *)arg);
  return;
}

