
void reset_global_arg(void)

{
  int iVar1;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  printf("\n--- %s\n","reset_global_arg");
  memset(lcd_output,0x20,0x40);
  write_lcd(0,lcd_output,0x40);
  memset(gReceive_Nonce_Num,0,0x10);
  memset(gValid_Nonce_Num,0,0x10);
  memset(gHw_Nonce_Num,0,0x10);
  memset(reg_value_buf,0,0x1410);
  memset(gWorks_For_Hw_Check,0,0x7f8);
  pthread_mutex_init((pthread_mutex_t *)reg_mutex,(pthread_mutexattr_t *)0x0);
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    *(undefined4 *)(time_counter + local_c * 4) = 0;
    *(undefined *)((int)&gWork_Num_For_Hw_Check + local_c) = 0;
    *(undefined *)((int)&gIsOpenCoreEnd + local_c) = 0;
    *(undefined *)((int)&gStartTest + local_c) = 0;
    if (pattern_test_time == '\0') {
      *(undefined *)((int)&gT1_offset_value + local_c) = 0;
      *(undefined *)((int)&gT2_offset_value + local_c) = 0;
      *(undefined *)((int)&gT3_offset_value + local_c) = 0;
    }
    *(undefined *)((int)&Sensor1_OK + local_c) = 1;
    *(undefined *)((int)&Sensor2_OK + local_c) = 1;
    *(undefined *)((int)&Sensor3_OK + local_c) = 1;
    *(undefined4 *)(Sensor1_temp + local_c * 4) = 0;
    *(undefined4 *)(Sensor2_temp + local_c * 4) = 0;
    *(undefined4 *)(Sensor3_temp + local_c * 4) = 0;
    *(undefined4 *)(last_Sensor1_temp + local_c * 4) = 0;
    *(undefined4 *)(last_Sensor2_temp + local_c * 4) = 0;
    *(undefined4 *)(last_Sensor3_temp + local_c * 4) = 0;
    *(undefined4 *)(highest_temp + local_c * 4) = 0;
    *(undefined4 *)(lowest_temp + local_c * 4) = 0;
    *(undefined4 *)(gGlobalHighestTemp + local_c * 4) = 0;
    *(undefined4 *)(temp_change + local_c * 4) = 0;
    *(undefined *)((int)&gHigherThanAlarmTemp + local_c) = 0;
    *(undefined *)((int)&gHigherThanMaxTempGap + local_c) = 0;
    *(undefined4 *)(gMaxTempGap_value + local_c * 4) = 0;
    *(undefined *)((int)&gIsReadTemp + local_c) = 1;
    *(undefined *)((int)&gReadingTemp + local_c) = 0;
    *(undefined *)((int)&gNotReadOutTemp + local_c) = 0;
    pthread_mutex_init((pthread_mutex_t *)(HW_check_mutex + local_c * 0x18),
                       (pthread_mutexattr_t *)0x0);
    cgpu[local_c + 0x1004b8] = 0;
    *(undefined4 *)(gRepeated_Nonce_Id + local_c * 4) = 0;
    *(undefined4 *)(gValid_Nonce_Num + local_c * 4) = 0;
    *(undefined4 *)(gSend_Work_Num + local_c * 4) = 0;
    for (local_10 = 0; local_10 < (uint)Conf._108_4_; local_10 = local_10 + 1) {
      iVar1 = *(int *)(cgpu + (local_10 + 0x20028) * 4);
      for (local_14 = 0; local_14 < (uint)Conf._112_4_; local_14 = local_14 + 1) {
        *(undefined4 *)
         (gAsic_Core_Nonce_Num + ((local_c * 0x100 + local_10) * 0x200 + local_14) * 4) = 0;
        for (local_18 = 0; local_18 < (uint)Conf._64_4_; local_18 = local_18 + 1) {
          *(undefined4 *)
           (iVar1 + (local_14 * Conf._64_4_ + local_18) * 0xcc + (local_c + 0x2e) * 4 + 4) = 0;
        }
      }
    }
  }
  clear_register_value_buf();
  return;
}

