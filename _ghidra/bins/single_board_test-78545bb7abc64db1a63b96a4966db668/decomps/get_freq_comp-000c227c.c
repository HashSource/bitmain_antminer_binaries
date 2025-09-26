
int get_freq_comp(int32_t freq)

{
  int32_t freq_local;
  char time_stamp [48];
  char tmp1 [256];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : base:%d,Flex:%d\n","get_freq_comp",freq,
         (Local_Config_Information->Test_Info).Freq_Flex);
  snprintf(tmp1,0x100,"base:%d,Flex:%d",freq,(Local_Config_Information->Test_Info).Freq_Flex);
  log_to_file(tmp1,time_stamp);
  return freq + (Local_Config_Information->Test_Info).Freq_Flex;
}

