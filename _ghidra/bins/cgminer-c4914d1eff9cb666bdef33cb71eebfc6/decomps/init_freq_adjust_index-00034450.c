
void init_freq_adjust_index(int base_freq)

{
  int base_freq_local;
  int domain;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    for (domain = 0; domain < 6; domain = domain + 1) {
      freq_adjust_index[chain][domain] = (float)(longlong)base_freq;
    }
  }
  return;
}

