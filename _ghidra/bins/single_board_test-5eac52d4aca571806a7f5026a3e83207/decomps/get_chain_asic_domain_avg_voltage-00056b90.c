
float get_chain_asic_domain_avg_voltage(uint8_t which_chain,uint8_t which_domain)

{
  int iVar1;
  float fVar3;
  double dVar2;
  uint8_t which_domain_local;
  uint8_t which_chain_local;
  char time_stamp [48];
  char tmp1 [256];
  float vol [65];
  float vol_avg;
  int32_t asic_num;
  float vol_sum;
  int32_t asic;
  
  iVar1 = (g_rt.config)->asics;
  vol_sum = 0.0;
  memset(vol,0,0x104);
  for (asic = 0; asic < (g_rt.config)->asics; asic = asic + 1) {
    fVar3 = adc_get_domain_voltage
                      (which_chain,'\0',asic * (g_rt.config)->interval,(uint)which_domain);
    vol[asic] = fVar3;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : chain%d, domain%d, asic %03d, voltage:%f\n","get_chain_asic_domain_avg_voltage",
           (uint)which_chain,(uint)which_domain,asic);
    snprintf(tmp1,0x100,"chain%d, domain%d, asic %03d, voltage:%f",(uint)which_chain,
             (uint)which_domain,asic,(double)vol[asic]);
    log_to_file(tmp1,time_stamp);
    g_asic_vol_domain[asic][which_domain] = vol[asic];
  }
  asic = 0;
  while( true ) {
    if ((g_rt.config)->asics <= asic) {
      fVar3 = vol_sum / (float)(longlong)iVar1;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      dVar2 = (double)fVar3;
      printf("%s : chain%d, domain%d, asic avg voltage:%f\n","get_chain_asic_domain_avg_voltage",
             (uint)which_chain,(uint)which_domain,dVar2);
      snprintf(tmp1,0x100,"chain%d, domain%d, asic avg voltage:%f",(uint)which_chain,
               (uint)which_domain,(int)((ulonglong)dVar2 >> 0x20),(double)fVar3);
      log_to_file(tmp1,time_stamp);
      return fVar3;
    }
    if (vol[asic] == 0.0) break;
    vol_sum = vol_sum + vol[asic];
    asic = asic + 1;
  }
  return -1.0;
}

