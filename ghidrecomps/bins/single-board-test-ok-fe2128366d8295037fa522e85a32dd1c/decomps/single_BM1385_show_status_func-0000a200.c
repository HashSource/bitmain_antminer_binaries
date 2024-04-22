
void single_BM1385_show_status_func(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  time_counter = 0;
  do {
    memset(lcd_buffer + 0x20,0x20,0x40);
    sprintf(DAT_0000a2ac,"   time %ds",time_counter);
    sprintf(DAT_0000a2b0,"   nonce=%d",*(undefined4 *)(gValid_Nonce_Num + (uint)bVar1 * 4));
    time_counter = time_counter + 1;
    write(lcd_fd,lcd_buffer + 0x20,0x40);
    set_fan_speed(10);
    usleep(1000000);
  } while( true );
}

