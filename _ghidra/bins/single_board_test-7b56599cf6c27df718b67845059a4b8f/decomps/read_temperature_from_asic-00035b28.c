
void * read_temperature_from_asic(void *arg)

{
  bool bVar1;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  int readcounts;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s start\n","read_temperature_from_asic","read_temperature_from_asic");
  snprintf(tmp1,0x100,"%s start","read_temperature_from_asic");
  log_to_file(tmp1,time_stamp);
  readcounts = 0;
  if (arg != (void *)0x0) {
                    /* WARNING: Load size is inaccurate */
    readcounts = *arg;
  }
  set_chain_asic_synopsys_temp((uint8_t)gChain,0,true,false,false,false);
  usleep(10000);
  set_chain_asic_synopsys_temp((uint8_t)gChain,0,true,true,false,false);
  usleep(10000);
  set_chain_asic_synopsys_temp((uint8_t)gChain,0,true,false,true,false);
  usleep(10000);
  while ((gStart_read_temp_from_asic != false ||
         (bVar1 = readcounts != 0, readcounts = readcounts + -1, bVar1))) {
    memset(&g_asic_temp,0,0x3f0);
    g_asic_temp.max_asic_val._0_4_ = 0;
    g_asic_temp.max_asic_val._4_4_ = 0xc08f4000;
    g_asic_temp.min_asic_val._0_4_ = 0;
    g_asic_temp.min_asic_val._4_4_ = 0x408f4000;
    g_asic_temp.read_succ_size = 0;
    get_register_value_with_ext_data
              (0,0xb4,true,(Local_Config_Information->Hash_Board).Asic_Type,&g_asic_temp);
    if ((gStart_read_temp_from_asic != false) && (readcounts == 0)) {
      sleep(1);
    }
  }
  set_chain_asic_synopsys_temp((uint8_t)gChain,0,false,false,false,true);
  usleep(10000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : %s stop\n","read_temperature_from_asic","read_temperature_from_asic");
  snprintf(tmp1,0x100,"%s stop","read_temperature_from_asic");
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}

