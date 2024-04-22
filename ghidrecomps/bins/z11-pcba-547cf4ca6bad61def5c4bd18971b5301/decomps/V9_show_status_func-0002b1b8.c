
undefined4 V9_show_status_func(void)

{
  int local_c;
  
  local_c = 0;
  while (show_id_alive != 0) {
    usleep(1000000);
    memset(lcd_buffer + 0x20,0x20,0x40);
    sprintf(lcd_buffer + 0x20,"time %ds",local_c);
    sprintf(DAT_0002b2a4,"nonce=%d %d %d  ",one_work_nonce_each_asic._0_4_,
            one_work_nonce_each_asic._4_4_,one_work_nonce_each_asic._8_4_);
    sprintf(DAT_0002b2a8,"%d-%d\'C %d-%d\'C",(uint)sensor_info._1_1_,(uint)(byte)sensor_info,
            (uint)sensor_info._5_1_,(uint)sensor_info._4_1_);
    local_c = local_c + 1;
    write(cgpu._36_4_,lcd_buffer + 0x20,0x40);
  }
  return 0;
}

