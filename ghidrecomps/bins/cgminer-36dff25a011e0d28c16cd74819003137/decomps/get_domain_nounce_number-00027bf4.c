
uint32_t get_domain_nounce_number(uint32_t chain,uint32_t domain)

{
  int iVar1;
  int iVar2;
  uint32_t domain_local;
  uint32_t chain_local;
  int core_id_end;
  int asic_id_end;
  int core_id_start;
  int asic_id_start;
  int j;
  int i;
  uint32_t nounc_num;
  
  nounc_num = 0;
  i = domain & 0xfffffffc;
  iVar1 = (domain & 3) * 0xa8;
  iVar2 = i + 4;
  for (; j = iVar1, i < iVar2; i = i + 1) {
    for (; j < iVar1 + 0xa8; j = j + 1) {
      nounc_num = nounc_num + calc_nonce_info.chain_asic_core_nonce_num[chain][i][j];
    }
  }
  return nounc_num;
}

