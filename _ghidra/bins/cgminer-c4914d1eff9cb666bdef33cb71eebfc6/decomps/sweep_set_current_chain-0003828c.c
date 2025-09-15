
void sweep_set_current_chain(int chain_count)

{
  int chain_count_local;
  int count;
  int chain;
  
  count = 0;
  check_chain();
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (count != chain_count) {
        dev->chain_exist[chain] = 0;
      }
      count = count + 1;
    }
  }
  dev->chain_num = '\x01';
  return;
}

