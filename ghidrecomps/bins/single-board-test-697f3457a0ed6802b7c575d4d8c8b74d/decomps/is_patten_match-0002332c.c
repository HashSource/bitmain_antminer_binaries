
int is_patten_match(int asic_index,uint8_t *nonce,uint8_t *sol)

{
  int iVar1;
  int iVar2;
  uint8_t *sol_local;
  uint8_t *nonce_local;
  int asic_index_local;
  int sol_ret;
  int nonce_ret;
  int ret;
  
  if (g_patten.cur_asic == asic_index) {
    pthread_mutex_lock(DAT_0002350c);
    iVar1 = memcmp(g_patten.cur_work + g_patten.work_bin_len,nonce,g_patten.nonce_bin_len);
    iVar2 = memcmp(g_patten.cur_work + g_patten.nonce_bin_len + g_patten.work_bin_len,sol,
                   g_patten.sol_bin_len);
    if ((iVar1 == 0) && (iVar2 == 0)) {
      g_patten.is_nonce_match
      [g_patten.cur_patten +
       g_patten.patten_num * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)] = '\x01';
      g_patten.recv_nonces = g_patten.recv_nonces + 1;
      g_patten.total_rate =
           (float)(longlong)g_patten.recv_nonces / (float)(longlong)g_patten.total_pattens;
      g_patten.asic_recv_nonces[g_patten.cur_asic] =
           g_patten.asic_recv_nonces[g_patten.cur_asic] + 1;
      ret = 0;
    }
    else {
      dump_str(stderr,"Not Match Recv:",nonce,g_patten.nonce_bin_len);
      dump_str(stderr,"Not Match Expect:",g_patten.cur_work + g_patten.work_bin_len,
               g_patten.nonce_bin_len);
      ret = -1;
    }
    pthread_mutex_unlock(DAT_0002350c);
  }
  else {
    printf("asic is not match %d vs %d\n",asic_index,g_patten.cur_asic);
    ret = -1;
  }
  return ret;
}

