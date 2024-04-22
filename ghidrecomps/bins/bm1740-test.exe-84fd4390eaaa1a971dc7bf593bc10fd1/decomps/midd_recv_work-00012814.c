
uint midd_recv_work(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  if (bm_nonce_rb._8_4_ == 0) {
    uVar1 = rt_ringbuffer_get(bm_nonce_rb,param_1,param_2 & 0xffff);
  }
  else {
    uVar1 = rt_ringbuffer_data_len(bm_nonce_rb);
    if (param_2 <= uVar1) {
      uVar1 = rt_ringbuffer_get(bm_nonce_rb,param_1,param_2 & 0xffff);
    }
  }
  return uVar1;
}

