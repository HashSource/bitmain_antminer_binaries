
void adc_get_domain_voltage(uint8_t which_chain,uint32_t which_asic_address,uint8_t domain)

{
  uint32_t uVar1;
  size_t sVar2;
  int extraout_r1;
  uint32_t which_asic_address_local;
  uint8_t domain_local;
  uint8_t which_chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  char temp [10];
  char data [2048];
  float vol_out [256];
  uint32_t Adc_inpiut_sel [5];
  uint8_t domain_index [4];
  uint32_t vol_arry [256];
  uint32_t loop_num;
  uint32_t vol;
  uint32_t adc_voltage;
  uint32_t phase0_avg;
  uint32_t end_loop;
  uint32_t max_loop;
  int asic_2;
  int asic_1;
  int i;
  int asic;
  uint32_t loop;
  float min_vol;
  float max_vol;
  float domain_vol;
  uint32_t vol_sum;
  
  memset(vol_arry,0,0x400);
  domain_index[0] = '\0';
  domain_index[1] = '\x01';
  domain_index[2] = '\x03';
  domain_index[3] = '\x04';
  Adc_inpiut_sel[0] = 1;
  Adc_inpiut_sel[1] = 2;
  Adc_inpiut_sel[2] = 3;
  Adc_inpiut_sel[3] = 4;
  Adc_inpiut_sel[4] = 5;
  memset(vol_out,0,0x400);
  memset(data,0,0x800);
  temp[0] = '\0';
  temp[1] = '\0';
  temp[2] = '\0';
  temp[3] = '\0';
  temp[4] = '\0';
  temp[5] = '\0';
  temp[6] = '\0';
  temp[7] = '\0';
  temp[8] = '\0';
  temp[9] = '\0';
  max_vol = 0.0;
  min_vol = 10.0;
  memset(data,0,0x800);
  send_set_config_command
            (which_chain,'\x01',which_asic_address,0xb8,
             Adc_inpiut_sel[domain_index[domain]] << 0xd | 0x230c030d);
  send_set_config_command(which_chain,'\x01',which_asic_address,0xb9,0x3f014381);
  send_set_config_command(which_chain,'\x01',which_asic_address,0xba,0x40010);
  send_set_config_command(which_chain,'\x01',which_asic_address,0xbb,0x3340e80);
  for (asic = 0; (uint)asic < (Local_Config_Information->Hash_Board).Asic_Num; asic = asic + 1) {
    for (loop = 0; loop < 2; loop = loop + 1) {
      gADC_Data_Out.Data_out[asic][loop] = 0;
      gADC_Data_Out.counter[asic] = 0;
    }
  }
  for (i = 0; (uint)i < 2; i = i + 1) {
    send_set_config_command
              (which_chain,'\x01',which_asic_address,0xb8,
               Adc_inpiut_sel[domain_index[domain]] << 0xd | 0x232c030d);
    usleep(60000);
    get_register_value(which_asic_address,0x11,false,
                       (Local_Config_Information->Hash_Board).Asic_Type);
  }
  for (asic_1 = 0; (uint)asic_1 < (Local_Config_Information->Hash_Board).Asic_Num;
      asic_1 = asic_1 + 1) {
    vol_sum = 0;
    for (loop = 0; loop < 2; loop = loop + 1) {
      if (loop != 0) {
        vol_sum = (gADC_Data_Out.Data_out[asic_1][loop] & 0x7fff) + vol_sum;
      }
    }
    uVar1 = __aeabi_uidiv(vol_sum,loop - 1);
    vol_arry[asic_1] = uVar1;
  }
  for (asic_2 = 0; (uint)asic_2 < (Local_Config_Information->Hash_Board).Asic_Num;
      asic_2 = asic_2 + 1) {
    memset(temp,0,10);
    domain_vol = (float)(((double)vol_arry[asic_2] / 2048.0) / 8.0 - 1.0);
    if (1 < domain) {
      domain_vol = domain_vol + domain_vol;
    }
    snprintf(temp,10,"%.3f ",temp,(double)domain_vol);
    strcat(data,temp);
    __aeabi_uidivmod(asic_2 + 1,(Local_Config_Information->Hash_Board).Asic_Num_Per_Voltage_Domain);
    if (extraout_r1 == 0) {
      sVar2 = strlen(data);
      (data + sVar2)[0] = '\n';
      (data + sVar2)[1] = '\0';
    }
    if (max_vol < domain_vol) {
      max_vol = domain_vol;
    }
    if ((int)((uint)(domain_vol < min_vol) << 0x1f) < 0) {
      min_vol = domain_vol;
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: domain %d vol :\n%s\n\n","adc_get_domain_voltage",(uint)domain,data);
  snprintf(tmp1,0x800,"domain %d vol :\n%s\n",(uint)domain,data);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: max_vol %f,min_vol %f, %f\n\n","adc_get_domain_voltage",SUB84((double)max_vol,0),
         (int)((ulonglong)(double)max_vol >> 0x20),(double)min_vol,(double)(max_vol / min_vol));
  snprintf(tmp1,0x800,"max_vol %f,min_vol %f, %f\n",tmp1,(double)max_vol,(double)min_vol,
           (double)(max_vol / min_vol));
  log_to_file(tmp1,time_stamp);
  return;
}

