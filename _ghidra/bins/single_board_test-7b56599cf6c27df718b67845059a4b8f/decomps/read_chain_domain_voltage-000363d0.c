
_Bool read_chain_domain_voltage(_Bool logout)

{
  _Bool _Var1;
  int env_temp;
  int32_t iVar2;
  uint32_t uVar3;
  double dVar4;
  _Bool logout_local;
  char time_stamp [48];
  char tmp1 [256];
  double vol;
  
  memset(&g_asic_vol,0,0x3f0);
  g_asic_vol.max_asic_val._0_4_ = 0;
  g_asic_vol.max_asic_val._4_4_ = 0xc08f4000;
  g_asic_vol.min_asic_val._0_4_ = 0;
  g_asic_vol.min_asic_val._4_4_ = 0x408f4000;
  g_asic_vol.read_succ_size = 0;
  set_chain_register_to_get_domain_voltage((uint8_t)gChain,'\0');
  usleep(30000);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : read domain %d voltage.\n","read_chain_domain_voltage",0);
  snprintf(tmp1,0x100,"read domain %d voltage.",0);
  log_to_file(tmp1,time_stamp);
  get_register_value_with_ext_data
            (0,0xbd,true,(Local_Config_Information->Hash_Board).Asic_Type,&g_asic_vol);
  uVar3 = (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[0].Voltage;
  env_temp = get_env_temp();
  iVar2 = get_vol_comp(env_temp);
  dVar4 = (((double)(iVar2 + uVar3) / 100.0) /
          (double)(Local_Config_Information->Hash_Board).Voltage_Domain) / 4.0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ASIC VOL,set max:%.2f\n","read_chain_domain_voltage",
         SUB84(dVar4 * 1.2999999523162842,0),(int)((ulonglong)(dVar4 * 1.2999999523162842) >> 0x20))
  ;
  snprintf(tmp1,0x100,"ASIC VOL,set max:%.2f",tmp1,dVar4 * 1.2999999523162842);
  log_to_file(tmp1,time_stamp);
  _Var1 = check_asic_val(&g_asic_vol,dVar4 * 1.2999999523162842,logout);
  return _Var1;
}

