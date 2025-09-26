
void * pt_read_temp(void *arg)

{
  byte sesnor_id_00;
  byte sensor_dev_addr_00;
  uint8_t switch_dev_addr_00;
  _Bool _Var1;
  int32_t iVar2;
  int iVar3;
  int iVar4;
  pthread_t __th;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  int speed [4];
  uint8_t sensor_addr [8];
  int8_t data [2];
  _Bool power_on_ctrl;
  uint8_t sensor_dev_addr;
  uint8_t switch_dev_addr;
  uint8_t sesnor_id;
  int32_t ret;
  pattern_runtime_ctx *ctx;
  int i_1;
  int read_fail_cnt;
  uint8_t sleep_counter;
  uint8_t i;
  
  sleep_counter = '\0';
  data[0] = -1;
  data[1] = -1;
  sensor_addr[0] = '\0';
  sensor_addr[1] = '\0';
  sensor_addr[2] = '\0';
  sensor_addr[3] = '\0';
  sensor_addr[4] = '\0';
  sensor_addr[5] = '\0';
  sensor_addr[6] = '\0';
  sensor_addr[7] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","pt_read_temp","pt_read_temp");
  snprintf(tmp1,0x100,"Start %s","pt_read_temp");
  log_to_file(tmp1,time_stamp);
  memset((void *)((int)arg + 0x846c0),0xff,8);
  if (*(char *)(*(int *)((int)arg + 0x84690) + 0xbc) != '\x01') {
    for (i = '\0'; (int)(uint)i < *(int *)(*(int *)((int)arg + 0x84690) + 0xb8); i = i + '\x01') {
      sensor_addr[i] =
           (char)((g_rt.config)->board).sensor.sensor_addr[i] +
           (char)((g_rt.config)->board).sensor.sensor_i2c_addr;
    }
    iVar2 = tsensor_open((g_rt.config)->chain,sensor_addr,
                         (uint8_t)*(undefined4 *)(*(int *)((int)arg + 0x84690) + 0xb8));
    if (iVar2 < 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s: chain %d tsensor_open failed\n","pt_read_temp","pt_read_temp",
             (g_rt.config)->chain);
      snprintf(tmp1,0x100,"%s: chain %d tsensor_open failed","pt_read_temp",(g_rt.config)->chain);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : WARNING CAN NOT OPEN TEMP SENSOR ...\n","pt_read_temp");
      builtin_strncpy(tmp1,"WARNING CAN NOT OPEN TEMP SENSOR ...",0x24);
      tmp1[0x24] = '\0';
      log_to_file(tmp1,time_stamp);
      err_exit("sensor err");
      return (void *)0x0;
    }
  }
  pca_switch_disable((uint8_t)(g_rt.config)->chain,'p');
  do {
    if (*(int *)((int)arg + 0x846d8) == 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : %s stop\n","pt_read_temp","pt_read_temp");
      snprintf(tmp1,0x100,"%s stop","pt_read_temp");
      log_to_file(tmp1,time_stamp);
      __th = pthread_self();
      pthread_detach(__th);
      return (void *)0x0;
    }
    for (i = '\0'; (int)(uint)i < *(int *)(*(int *)((int)arg + 0x84690) + 0xb8); i = i + '\x01') {
      if (*(char *)(*(int *)((int)arg + 0x84690) + 0xbc) == '\0') {
        iVar2 = tsensor_read((g_rt.config)->chain,sensor_addr[i],
                             (uint8_t)((g_rt.config)->board).sensor.sensor_reg_addr,(uint8_t *)data,
                             2);
        if (iVar2 == 2) {
          if ((data[0] == -1) || (data[0] == '\0')) {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Read sensor[%d] fail,addr: %d\n","pt_read_temp",(uint)i,
                   (uint)sensor_addr[i]);
            snprintf(tmp1,0x100,"Read sensor[%d] fail,addr: %d",(uint)i,(uint)sensor_addr[i]);
            log_to_file(tmp1,time_stamp);
          }
          else {
            *(int8_t *)((int)arg + (int)(LZ4_compress_destSize + i + 4)) = data[0];
            if ((sleep_counter < 3) || ((uint)sleep_counter % 3 == 0)) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : temp [%d] %d\n","pt_read_temp",(uint)i,(int)data[0]);
              snprintf(tmp1,0x100,"temp [%d] %d",(uint)i,(int)data[0]);
              log_to_file(tmp1,time_stamp);
            }
          }
        }
        else {
          print_time_stamp(time_stamp,0x30);
          printf("%s ",time_stamp);
          printf("%s : Read sensor[%d] fail,addr: %d\n","pt_read_temp",(uint)i,(uint)sensor_addr[i])
          ;
          snprintf(tmp1,0x100,"Read sensor[%d] fail,addr: %d",(uint)i,(uint)sensor_addr[i]);
          log_to_file(tmp1,time_stamp);
        }
LAB_00059446:
        usleep(10);
      }
      else {
        sesnor_id_00 = *(byte *)((i + 0x2e) * 4 + *(int *)((int)arg + 0x84690) + 9);
        switch_dev_addr_00 = *(uint8_t *)(*(int *)((int)arg + 0x84690) + 0xbd);
        sensor_dev_addr_00 = *(byte *)((i + 0x2e) * 4 + *(int *)((int)arg + 0x84690) + 8);
        if ((*(char *)((i + 0x2e) * 4 + *(int *)((int)arg + 0x84690) + 7) == '\x01') ||
           (is_power_on == true)) {
          memset(data,0xff,2);
          iVar2 = pca_switch_read((uint8_t)(g_rt.config)->chain,sesnor_id_00,switch_dev_addr_00,
                                  sensor_dev_addr_00,data,data + 1);
          if (iVar2 == 0) {
            if ((data[0] == -1) || (data[0] == '\0')) {
              print_time_stamp(time_stamp,0x30);
              printf("%s ",time_stamp);
              printf("%s : Read sensor[%d] fail,addr: %d\n","pt_read_temp",(uint)i,
                     (uint)sensor_dev_addr_00);
              snprintf(tmp1,0x100,"Read sensor[%d] fail,addr: %d",(uint)i,(uint)sensor_dev_addr_00);
              log_to_file(tmp1,time_stamp);
            }
            else {
              *(int8_t *)((int)arg + (int)(LZ4_compress_destSize + i + 4)) = data[0];
              if ((sleep_counter < 3) || ((uint)sleep_counter % 3 == 0)) {
                print_time_stamp(time_stamp,0x30);
                printf("%s ",time_stamp);
                printf("%s : temp [%d] %d %d\n","pt_read_temp",(uint)i,(int)data[0],(int)data[1]);
                snprintf(tmp1,0x100,"temp [%d] %d %d",(uint)i,(int)data[0],(int)data[1]);
                log_to_file(tmp1,time_stamp);
              }
            }
          }
          else {
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Read switch sensor fail,sesnor_id: %d\n","pt_read_temp",(uint)sesnor_id_00)
            ;
            snprintf(tmp1,0x100,"Read switch sensor fail,sesnor_id: %d",(uint)sesnor_id_00);
            log_to_file(tmp1,time_stamp);
          }
          goto LAB_00059446;
        }
      }
    }
    if (g_pwm_enable != false) {
      sweep_set_pwm_by_temp();
    }
    for (i_1 = 0; i_1 < 4; i_1 = i_1 + 1) {
      iVar2 = fan_get_realtime_speed(i_1);
      speed[i_1] = iVar2;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : fan:[%d][%d][%d][%d]\n","pt_read_temp",speed[0],speed[1],speed[2],speed[3]);
    snprintf(tmp1,0x100,"fan:[%d][%d][%d][%d]",speed[0],speed[1],speed[2],speed[3]);
    log_to_file(tmp1,time_stamp);
    iVar3 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
    iVar4 = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
    _Var1 = board_temp_protect_check((int8_t)iVar3,(int8_t)iVar4);
    if (!_Var1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : WARNING TEMP OUT OF PROTECT...\n","pt_read_temp");
      builtin_strncpy(tmp1,"WARNING TEMP OUT OF PROTECT...",0x1f);
      log_to_file(tmp1,time_stamp);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      iVar3 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
      iVar4 = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
      printf("%s : WARNING temp max:%d,temp min:%d\n","pt_read_temp",iVar3,iVar4);
      iVar3 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
      iVar4 = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
      snprintf(tmp1,0x100,"WARNING temp max:%d,temp min:%d",iVar3,iVar4);
      log_to_file(tmp1,time_stamp);
      err_exit("temp high");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    sleep(1);
    sleep_counter = sleep_counter + '\x01';
  } while( true );
}

