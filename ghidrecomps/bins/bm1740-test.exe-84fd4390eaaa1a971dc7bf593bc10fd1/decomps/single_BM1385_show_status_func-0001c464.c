
void single_BM1385_show_status_func(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  time_counter = 0;
  do {
    memset(lcd_buffer + 0x20,0x20,0x40);
    sprintf(DAT_0001c510,"   time %ds",time_counter);
    sprintf(DAT_0001c514,"   nonce=%d",(&gValid_Nonce_Num)[bVar1]);
    time_counter = time_counter + 1;
    write(lcd_fd,lcd_buffer + 0x20,0x40);
    set_fan_speed(10);
    usleep(1000000);
  } while( true );
}

