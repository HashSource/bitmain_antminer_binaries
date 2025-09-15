
void set_asic_address(runtime_base_t *runtime,uchar chainid)

{
  uchar chainid_local;
  runtime_base_t *runtime_local;
  int i;
  
  (*runtime->chain_inactive)(runtime->chain_status[chainid].fd);
  for (i = 0; i < runtime->chain_status[chainid].design_asic_num; i = i + 1) {
    (*runtime->set_address)
              (runtime->chain_status[chainid].fd,(char)runtime->addr_interval * (char)i);
  }
  return;
}

