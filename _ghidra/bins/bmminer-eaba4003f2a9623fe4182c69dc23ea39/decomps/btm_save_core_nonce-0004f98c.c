
void btm_save_core_nonce(int asic,int core,int chain)

{
  int chain_local;
  int core_local;
  int asic_local;
  
  if ((((asic < 0) || (0x6c < asic)) || (core < 0)) ||
     (((0xd0 < core || (chain < 0)) || (0x10 < chain)))) {
    printf("[%s] asic[%d]-core[%d]-chain[%d] input error!!","btm_save_core_nonce",asic,core,chain);
  }
  else if (dev->chain_exist[chain] == 1) {
    asic_core_nonce_num_chain[chain][asic][core] = asic_core_nonce_num_chain[chain][asic][core] + 1;
  }
  else {
    printf("[%s] chain num is not exist\n","btm_save_core_nonce",chain);
  }
  return;
}

