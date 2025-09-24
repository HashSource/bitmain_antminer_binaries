
/* WARNING: Unknown calling convention */

int find_bad_ri_asic(void)

{
  _Bool _Var1;
  char time_stamp [48];
  char tmp1 [256];
  _Bool dummy_state_temp;
  uint8_t asic;
  int bad_asic_index;
  
  _Var1 = gFind_dummy_data;
  gFind_dummy_data = false;
  bad_asic_index = -1;
  set_chain_inactive((uint8_t)gChain);
  usleep(30000);
  set_chain_asic_address((uint8_t)gChain,gAddress_interval);
  usleep(20000);
  asic = (uint8_t)(Local_Config_Information->Hash_Board).Asic_Num;
  while (asic = asic + 0xff, asic != '\0') {
    set_asic_ri_disa((uint8_t)gChain,gAddress_interval * asic,'\x01');
    get_register_value(0,0,true,(Local_Config_Information->Hash_Board).Asic_Type);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : disa asic:%d,find asic num:%d,dummy_data:%d\n","find_bad_ri_asic",(uint)asic,
           gAsic_num,(uint)gFind_dummy_data);
    snprintf(tmp1,0x100,"disa asic:%d,find asic num:%d,dummy_data:%d",(uint)asic,gAsic_num,
             (uint)gFind_dummy_data);
    log_to_file(tmp1,time_stamp);
    if (asic + 1 != gAsic_num) {
      bad_asic_index = (int)asic;
    }
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bad asic index(from 0):%d,\n","find_bad_ri_asic",bad_asic_index);
  snprintf(tmp1,0x100,"bad asic index(from 0):%d,",bad_asic_index);
  log_to_file(tmp1,time_stamp);
  gFind_dummy_data = _Var1;
  return bad_asic_index;
}

