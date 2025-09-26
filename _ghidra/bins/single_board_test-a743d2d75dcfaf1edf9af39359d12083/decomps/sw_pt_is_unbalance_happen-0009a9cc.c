
int32_t sw_pt_is_unbalance_happen(uint32_t chain)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  int actual_core_domain;
  uint32_t nonce_num_domain_threshold;
  uint32_t nonce_num_domain_avg;
  int32_t is_unbalance_happen;
  uint32_t core_domain;
  uint32_t domain;
  
  is_unbalance_happen = 0;
  uVar1 = __aeabi_uidiv(g_rt.stats.nonce_num_chain,(g_rt.config)->domains);
  uVar2 = __aeabi_uidiv(uVar1,(g_rt.config)->asic_domain_num);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: nonce_num_chain: %d, domains: %d, asic_domain_num: %d\n","sw_pt_is_unbalance_happen",
         g_rt.stats.nonce_num_chain,(g_rt.config)->domains,(g_rt.config)->asic_domain_num);
  snprintf(tmp1,0x800,"nonce_num_chain: %d, domains: %d, asic_domain_num: %d",
           g_rt.stats.nonce_num_chain,(g_rt.config)->domains,(g_rt.config)->asic_domain_num);
  log_to_file(tmp1,time_stamp);
  uVar2 = uVar2 >> 1;
  if (uVar2 == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Domain unbalance happen: nonce is 0\n","sw_pt_is_unbalance_happen");
    builtin_strncpy(tmp1,"Domain unbalance happen: nonce is 0",0x24);
    log_to_file(tmp1,time_stamp);
    is_unbalance_happen = 1;
  }
  else {
    for (domain = 0; domain < (uint)(g_rt.config)->domains; domain = domain + 1) {
      for (core_domain = 0; core_domain < (uint)(g_rt.config)->asic_domain_num;
          core_domain = core_domain + 1) {
        iVar3 = core_domain + domain * (g_rt.config)->asic_domain_num;
        if (g_rt.stats.nonce_num_domain[iVar3] < uVar2) {
          is_unbalance_happen = 1;
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s: Domain unbalance happen, chain = %d,  coredomain = %d, nonce_num_domain = %d, threshold = %d.\n"
                 ,"sw_pt_is_unbalance_happen",chain,iVar3,g_rt.stats.nonce_num_domain[iVar3],uVar2);
          snprintf(tmp1,0x800,
                   "Domain unbalance happen, chain = %d,  coredomain = %d, nonce_num_domain = %d, threshold = %d."
                   ,chain,iVar3,g_rt.stats.nonce_num_domain[iVar3],uVar2);
          log_to_file(tmp1,time_stamp);
        }
      }
    }
  }
  return is_unbalance_happen;
}

