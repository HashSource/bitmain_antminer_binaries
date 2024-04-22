
int get_asic_nonce_num(int chain,int asic,int timeslice)

{
  int timeslice_local;
  int asic_local;
  int chain_local;
  int nonce;
  int index;
  int i;
  
  nonce = 0;
  for (i = 1; i <= timeslice; i = i + 1) {
    if (nonce_times % 0x3c - i < 0) {
      index = (nonce_times % 0x3c - i) + 0x3c;
    }
    else {
      index = nonce_times % 0x3c - i;
    }
    nonce = *(int *)(nonce_num[chain][asic] + index) + nonce;
  }
  return nonce;
}

