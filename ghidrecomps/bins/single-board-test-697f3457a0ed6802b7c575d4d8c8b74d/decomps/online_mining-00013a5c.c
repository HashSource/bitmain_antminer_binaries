
void online_mining(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  int chainid;
  
  iVar1 = runtime->chain_id;
  (*runtime->set_ticket_mask)(runtime->chain_status[iVar1].fd,app_conf->ticket_mask);
  usleep(100000);
  (*runtime->set_core_timeout)(runtime->chain_status[iVar1].fd,app_conf->core_timeout);
  usleep(100000);
  (*runtime->set_frequency)(runtime->chain_status[iVar1].fd,app_conf->bringup_freq);
  usleep(100000);
  (*runtime->set_nonce_shift)(runtime->chain_status[iVar1].fd,0,&runtime->nonce_shift);
  usleep(100000);
  equihash_miner_start(runtime);
  equihash_miner_join();
  return;
}

