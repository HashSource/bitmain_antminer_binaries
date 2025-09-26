
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_asic_register_stage_3(void)

{
  uint8_t which_chain;
  uint32_t freq;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t realFreq;
  
  freq = get_freq_comp((Local_Config_Information->Test_Info).Test_Standard.Test_Loop
                       [gPattern_test_counter].Frequence);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set chain frequency[+Freq_Flex] as %d,target freq:%d\n","set_asic_register_stage_3",
         freq,(Local_Config_Information->Test_Info).Test_Standard.Test_Loop[gPattern_test_counter].
              Frequence);
  snprintf(tmp1,0x100,"Set chain frequency[+Freq_Flex] as %d,target freq:%d",freq,
           (Local_Config_Information->Test_Info).Test_Standard.Test_Loop[gPattern_test_counter].
           Frequence);
  log_to_file(tmp1,time_stamp);
  inc_target_freq(freq);
  which_chain = (uint8_t)gChain;
  if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern == false) {
    if ((Local_Config_Information->Test_Info).Test_Method.Super_Software_Pattern == false) {
      set_chain_ticketmask(which_chain,0x7f);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Set TM as 0x%08x\n","set_asic_register_stage_3",0x7f);
      snprintf(tmp1,0x100,"Set TM as 0x%08x",0x7f);
      log_to_file(tmp1,time_stamp);
    }
    else {
      set_chain_ticketmask(which_chain,0xffff);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Set TM as 0x%08x\n","set_asic_register_stage_3",0xffff);
      snprintf(tmp1,0x100,"Set TM as 0x%08x",0xffff);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    set_chain_ticketmask(which_chain,0x7f);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Set TM as 0x%08x\n","set_asic_register_stage_3",0x7f);
    snprintf(tmp1,0x100,"Set TM as 0x%08x",0x7f);
    log_to_file(tmp1,time_stamp);
  }
  uart_flush_rx(gChain);
  dhash_set_timeout((Local_Config_Information->Test_Info).Test_Speed.Timeout);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Set timeout by using config value: %d\n","set_asic_register_stage_3",
         (Local_Config_Information->Test_Info).Test_Speed.Timeout);
  snprintf(tmp1,0x100,"Set timeout by using config value: %d",
           (Local_Config_Information->Test_Info).Test_Speed.Timeout);
  log_to_file(tmp1,time_stamp);
  if ((Local_Config_Information->Test_Info).Test_Method.Capture_Pattern != false) {
    set_chain_asic_nonce_space_divide
              ((uint8_t)gChain,gAddress_interval,(Local_Config_Information->Hash_Board).Asic_Num);
  }
  return;
}

