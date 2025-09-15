
void get_domain_nonce_data(uint32_t *buf,uint32_t *len)

{
  uint32_t uVar1;
  uint32_t *len_local;
  uint32_t *buf_local;
  uint32_t nonce_num;
  uint32_t index;
  int domain_id;
  int chain_id;
  
  index = 0;
  for (chain_id = 0; chain_id < 0x10; chain_id = chain_id + 1) {
    if (dev->chain_exist[chain_id] == 1) {
      for (domain_id = 0; domain_id < 0x18; domain_id = domain_id + 1) {
        uVar1 = get_domain_nounce_number(chain_id,domain_id);
        buf[index] = uVar1;
        index = index + 1;
      }
    }
  }
  *len = index;
  return;
}

