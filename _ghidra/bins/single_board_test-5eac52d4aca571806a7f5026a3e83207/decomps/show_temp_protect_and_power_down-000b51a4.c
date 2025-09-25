
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void show_temp_protect_and_power_down(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  gStart_show_on_lcd = false;
  lcd_clear_result();
  lcd_show(0,(Local_Config_Information->Hash_Board).Board_Name);
  lcd_show(1,"Max temp");
  lcd_show(2,"out of range");
  pwm_set(gFan,100);
  chain_reset_low(gChain);
  sleep(1);
  if ((Local_Config_Information->Hash_Board).Sensor_Info.Read_Temperature_From_Pic != false) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : drive mos low\n","show_temp_protect_and_power_down");
    builtin_strncpy(tmp1,"drive mos lo",0xc);
    tmp1[0xc] = 'w';
    tmp1[0xd] = '\0';
    log_to_file(tmp1,time_stamp);
    disable_dc_dc((uint8_t)gChain);
    sleep(1);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Please check zhiju and reset POWER.\n","show_temp_protect_and_power_down");
  builtin_strncpy(tmp1,"Please check zhiju and reset POWER.",0x24);
  log_to_file(tmp1,time_stamp);
  bitmain_power_off();
                    /* WARNING: Subroutine does not return */
  exit(1);
}

