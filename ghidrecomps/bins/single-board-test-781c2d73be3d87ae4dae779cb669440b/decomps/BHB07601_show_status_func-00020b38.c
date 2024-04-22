
/* WARNING: Unknown calling convention */

void * BHB07601_show_status_func(void *arg)

{
  byte which_chain_00;
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  chain_info *chain_info;
  undefined4 *__s;
  uchar which_chain;
  uint uVar6;
  
  puVar1 = DAT_00020db0;
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *arg;
  uVar6 = (uint)which_chain_00;
  printf("\n--- %s: which_chain = %d, which_i2c = %d\n",DAT_00020db4,uVar6,
         (uint)*(byte *)((int)arg + 1));
  __s = puVar1 + -8;
  time_counter = 0;
  do {
    memset(__s,0x20,0x40);
    fan_control(*(uchar *)(DAT_00020db8 + 0x328));
    if (((gIsReadTemp != false) && (gIsOpenCoreEnd != false)) &&
       (time_counter == (time_counter / 10) * 10)) {
      gReadingTemp = true;
      usleep(Conf.timeout * 0xf);
      if (Conf.sensor_model - 1 < 2) {
        BM1397_read_asic_temperature_local_remote(which_chain_00);
      }
      else if (Conf.sensor_model - 3 < 6) {
        BM1397_read_asic_temperature_local(which_chain_00);
      }
      else {
        printf("\n%s: please config sensor_model in Config.ini\n",DAT_00020db4);
      }
      gReadingTemp = false;
    }
    sprintf((char *)__s,"   time %ds",time_counter);
    sprintf(DAT_00020dbc,"   nonce=%d",gValid_Nonce_Num[uVar6]);
    uVar5 = s_temp_setting_err__0002b930._16_2_;
    uVar4 = s_temp_setting_err__0002b930._12_4_;
    uVar3 = s_temp_setting_err__0002b930._8_4_;
    uVar2 = s_temp_setting_err__0002b930._4_4_;
    if (Conf.TempSensor1 == 0) {
      *puVar1 = s_temp_setting_err__0002b930._0_4_;
      puVar1[1] = uVar2;
      *(undefined2 *)(puVar1 + 4) = uVar5;
      puVar1[2] = uVar3;
      puVar1[3] = uVar4;
    }
    else if (Conf.TempSensor2 == 0) {
      sprintf((char *)DAT_00020db0,"   T1 %d `C",Sensor1_temp);
    }
    else if (Conf.TempSensor3 == 0) {
      sprintf((char *)DAT_00020db0,"   T1 %d `C",Sensor1_temp);
      sprintf(DAT_00020dc0,"   T2 %d `C",Sensor2_temp);
    }
    else if (Conf.TempSensor4 == 0) {
      sprintf((char *)DAT_00020db0," T1:%d   T2:%d",Sensor1_temp,Sensor2_temp);
      sprintf(DAT_00020dc0," T3:%d",Sensor3_temp);
    }
    else {
      sprintf((char *)DAT_00020db0," T1:%d   T2:%d",Sensor1_temp,Sensor2_temp);
      sprintf(DAT_00020dc0," T3:%d   T4:%d",Sensor3_temp,Sensor4_temp);
    }
    time_counter = time_counter + 1;
    write(lcd_fd,__s,0x40);
    if (gStartTest != false) {
      printf("\ngValid_Nonce_Num = %d\n",gValid_Nonce_Num[uVar6]);
    }
    usleep(1000000);
    if (gHigherThanAlarmTemp != false) {
      printf("Temp is higer than AlarmTemp %d\n",Conf.AlarmTemp);
      kill_hashboard();
    }
  } while( true );
}

