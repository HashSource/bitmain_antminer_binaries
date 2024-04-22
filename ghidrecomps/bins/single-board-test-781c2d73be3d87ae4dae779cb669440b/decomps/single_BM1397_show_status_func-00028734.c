
/* WARNING: Unknown calling convention */
/* Local variable chain_info:chain_info *[r0:4] conflicts with parameter, skipped. */

void * single_BM1397_show_status_func(void *arg)

{
  byte which_chain_00;
  uchar which_chain;
  
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  time_counter = 0;
  do {
    memset(lcd_output,0x20,0x40);
    if ((gIsReadTemp != false) && (gIsOpenCoreEnd != false)) {
      printf("%s 1: start_receive = %d\n",DAT_000288e0,(uint)start_receive);
      printf("%s 1: gIsReadTemp = %d\n",DAT_000288e0,(uint)gIsReadTemp);
      printf("%s 1: Conf.sensor_model = %d\n",DAT_000288e0,Conf.sensor_model);
      gReadingTemp = true;
      usleep(Conf.timeout * 0xf);
      if (Conf.sensor_model - 1 < 2) {
        printf("%s %d\n",DAT_000288e0,0x8d7);
        BM1397_read_asic_temperature_local_remote(which_chain_00);
      }
      else if (Conf.sensor_model - 3 < 6) {
        printf("%s %d\n",DAT_000288e0,0x8dd);
        BM1397_read_asic_temperature_local(which_chain_00);
      }
      else {
        printf("\n%s: please config sensor_model in Config.ini\n",DAT_000288e0);
      }
      fan_control('\x06');
      gReadingTemp = false;
    }
    sprintf(lcd_output[0],"   time %ds",time_counter);
    sprintf(DAT_000288d8,"   nonce=%d",gValid_Nonce_Num[which_chain_00]);
    sprintf(DAT_000288dc,"   T1 %d `C",Sensor1_temp);
    time_counter = time_counter + 1;
    write(lcd_fd,lcd_output,0x40);
    if (gStartTest != false) {
      printf("\ngValid_Nonce_Num = %d\n",gValid_Nonce_Num[which_chain_00]);
    }
    usleep(800000);
  } while( true );
}

