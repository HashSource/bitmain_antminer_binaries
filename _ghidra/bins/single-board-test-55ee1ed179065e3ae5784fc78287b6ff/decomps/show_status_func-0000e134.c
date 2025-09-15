
void show_status_func(byte *param_1)

{
  byte bVar1;
  
  bVar1 = *param_1;
  *(undefined4 *)(time_counter + (uint)bVar1 * 4) = 0;
  do {
    memset(lcd_output,0x20,0x40);
    sprintf(lcd_output,"   time %ds",*(undefined4 *)(time_counter + (uint)bVar1 * 4));
    sprintf(lcd_output + 0x10,"   nonce=%d",*(undefined4 *)(gValid_Nonce_Num + (uint)bVar1 * 4));
    sprintf(lcd_output + 0x20,"   HW=%d",*(undefined4 *)(gHw_Nonce_Num + (uint)bVar1 * 4));
    if ((*(char *)((int)&gIsReadTemp + (uint)bVar1) != '\0') &&
       (*(char *)((int)&gIsOpenCoreEnd + (uint)bVar1) != '\0')) {
      sprintf(lcd_output + 0x30,"   temp %d `C",*(undefined4 *)(highest_temp + (uint)bVar1 * 4));
    }
    write_lcd(0,lcd_output,0x40);
    usleep(1000000);
    *(int *)(time_counter + (uint)bVar1 * 4) = *(int *)(time_counter + (uint)bVar1 * 4) + 1;
  } while( true );
}

