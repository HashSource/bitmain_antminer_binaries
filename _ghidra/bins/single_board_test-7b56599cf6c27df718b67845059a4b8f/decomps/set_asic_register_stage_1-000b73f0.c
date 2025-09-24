
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void set_asic_register_stage_1(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  set_chain_core_srst((uint8_t)gChain,false);
  set_chain_ticketmask((uint8_t)gChain,0xffffffff);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : set TM to 0xffffffff\n","set_asic_register_stage_1");
  builtin_strncpy(tmp1,"set TM to 0xffffffff",0x14);
  tmp1[0x14] = '\0';
  log_to_file(tmp1,time_stamp);
  uart_flush_rx(gChain);
  usleep(50000);
  return;
}

