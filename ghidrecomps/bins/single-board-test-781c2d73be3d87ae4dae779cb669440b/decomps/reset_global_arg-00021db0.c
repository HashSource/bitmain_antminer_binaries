
/* WARNING: Unknown calling convention */

void reset_global_arg(void)

{
  pthread_mutex_t *__mutex;
  _Bool (*pa_Var1) [4];
  int iVar2;
  
  printf("\n--- %s\n",DAT_00021f58);
  gChain = 0xff;
  time_counter = 0;
  gHighest_Temp = 0;
  gWork_Num_For_Hw_Check = '\0';
  Sensor1_temp = 0;
  Sensor2_temp = 0;
  Sensor3_temp = 0;
  Sensor4_temp = 0;
  last_Sensor1_temp = 0;
  last_Sensor2_temp = 0;
  last_Sensor3_temp = 0;
  last_Sensor4_temp = 0;
  highest_temp = 0;
  lowest_temp = 0;
  gGlobalHighestTemp = 0;
  temp_change = 0;
  gNotReadOutTemp = false;
  gIsOpenCoreEnd = false;
  gT1_offset_value = '\0';
  gT2_offset_value = '\0';
  gT3_offset_value = '\0';
  gT4_offset_value = '\0';
  gHigherThanMaxTempGap = false;
  gMaxTempGap_value = 0;
  gIsReadTemp = false;
  gReadingTemp = false;
  gEEPROM_error = false;
  gStartTest = false;
  Sensor1_OK = '\x01';
  Sensor2_OK = '\x01';
  Sensor3_OK = '\x01';
  Sensor4_OK = '\x01';
  gBegin_Get_Nonce = false;
  gValid_Nonce_Num[0] = 0;
  gHw_Nonce_Num[0] = 0;
  gRepeated_Nonce_Id[0] = 0;
  gValid_Nonce_Num[1] = 0;
  gValid_Nonce_Num[2] = 0;
  gValid_Nonce_Num[3] = 0;
  gHw_Nonce_Num[1] = 0;
  gHw_Nonce_Num[2] = 0;
  gHw_Nonce_Num[3] = 0;
  gRepeated_Nonce_Id[1] = 0;
  gRepeated_Nonce_Id[2] = 0;
  gRepeated_Nonce_Id[3] = 0;
  start_receive = false;
  memset(reg_value_buf,0,0x1008);
  memset(gWorks_For_Hw_Check,0,0x2200);
  memset(gAT24C02_data_map,0xff,0x100);
  memset(gSensor_read_ok_counter,0,0x40);
  memset(lcd_output,0x20,0x40);
  write(lcd_fd,lcd_output,0x40);
  iVar2 = 0;
  pthread_mutex_init(DAT_00021f5c,(pthread_mutexattr_t *)0x0);
  pa_Var1 = gSensor_OK;
  do {
    pthread_mutex_init((pthread_mutex_t *)((int)uart_send_mutex + iVar2),(pthread_mutexattr_t *)0x0)
    ;
    pthread_mutex_init((pthread_mutex_t *)((int)uart_receive_mutex + iVar2),
                       (pthread_mutexattr_t *)0x0);
    __mutex = (pthread_mutex_t *)((int)HW_check_mutex + iVar2);
    iVar2 = iVar2 + 0x18;
    pthread_mutex_init(__mutex,(pthread_mutexattr_t *)0x0);
    (*pa_Var1)[0] = true;
    (*pa_Var1)[1] = true;
    (*pa_Var1)[2] = true;
    (*pa_Var1)[3] = true;
    pa_Var1 = pa_Var1 + 1;
  } while (iVar2 != 0x60);
  clear_register_value_buf();
  return;
}

