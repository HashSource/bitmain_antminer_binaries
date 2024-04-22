
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * single_BM1391_show_status_func(void *arg)

{
  byte which_chain_00;
  uchar which_chain;
  
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  time_counter = 0;
  do {
    memset(lcd_output,0x20,0x40);
    if ((gIsReadTemp != false) && (gIsOpenCoreEnd != false)) {
      gReadingTemp = true;
      usleep(Conf.timeout * 0xf);
      if (Conf.sensor_model - 1 < 2) {
        BM1391_read_asic_temperature_local_remote(which_chain_00);
      }
      else if (Conf.sensor_model - 3 < 6) {
        BM1391_read_asic_temperature_local(which_chain_00);
      }
      else {
        printf("\n%s: please config sensor_model in Config.ini\n",DAT_00014f84);
      }
      fan_control('\x06');
      gReadingTemp = false;
    }
    sprintf(lcd_output[0],"   time %ds",time_counter);
    sprintf(DAT_00014f7c,"   nonce=%d",gValid_Nonce_Num[which_chain_00]);
    sprintf(DAT_00014f80,"   T1 %d `C",Sensor1_temp);
    time_counter = time_counter + 1;
    write(lcd_fd,lcd_output,0x40);
    if (gStartTest != false) {
      printf("\ngValid_Nonce_Num = %d\n",gValid_Nonce_Num[which_chain_00]);
    }
    usleep(800000);
  } while( true );
}

