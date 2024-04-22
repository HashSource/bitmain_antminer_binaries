
void user_i2c_enable(runtime_base_t *runtime,uchar chainid)

{
  uchar chainid_local;
  runtime_base_t *runtime_local;
  int i;
  
  for (i = 0; i < runtime->chain_status[runtime->chain_id].design_asic_num; i = i + 1) {
    (*runtime->i2c_enable)(runtime->chain_status[chainid].fd,(char)runtime->addr_interval * (char)i)
    ;
  }
  return;
}

