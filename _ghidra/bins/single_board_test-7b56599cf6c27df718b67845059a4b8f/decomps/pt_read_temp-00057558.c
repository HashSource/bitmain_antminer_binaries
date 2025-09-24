
void * pt_read_temp(void *arg)

{
  undefined4 uVar1;
  _Bool _Var2;
  int32_t iVar3;
  int iVar4;
  int iVar5;
  pthread_t __th;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  int speed [4];
  uint8_t sensor_addr [2];
  int8_t data [2];
  int32_t ret;
  pattern_runtime_ctx *ctx;
  int i_1;
  int read_fail_cnt;
  uint8_t sleep_counter;
  uint8_t i;
  
  sleep_counter = '\0';
  data[0] = -1;
  data[1] = -1;
  read_fail_cnt = 0;
  sensor_addr[0] = '\0';
  sensor_addr[1] = '\0';
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Start %s\n","pt_read_temp","pt_read_temp");
  snprintf(tmp1,0x100,"Start %s","pt_read_temp");
  log_to_file(tmp1,time_stamp);
  for (i = '\0'; (int)(uint)i < *(int *)(*(int *)((int)arg + 0x23628) + 0x94); i = i + '\x01') {
    sensor_addr[i] =
         (char)((g_rt.config)->board).sensor.sensor_addr[i] +
         (char)((g_rt.config)->board).sensor.sensor_i2c_addr;
  }
  iVar3 = tsensor_open((g_rt.config)->chain,sensor_addr,
                       (uint8_t)*(undefined4 *)(*(int *)((int)arg + 0x23628) + 0x94));
  if (iVar3 < 0) {
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
  }
  else {
    while (*(int *)((int)arg + 0x2366c) != 0) {
      for (i = '\0'; (int)(uint)i < *(int *)(*(int *)((int)arg + 0x23628) + 0x94); i = i + '\x01') {
        memset(data,-1,2);
        iVar3 = tsensor_read((g_rt.config)->chain,sensor_addr[i],
                             (uint8_t)((g_rt.config)->board).sensor.sensor_reg_addr,(uint8_t *)data,
                             2);
        if (iVar3 == 2) {
          if ((data[0] == -1) || (data[0] == '\0')) {
            read_fail_cnt = read_fail_cnt + 1;
            print_time_stamp(time_stamp,0x30);
            printf("%s ",time_stamp);
            printf("%s : Read sensor[%d] fail,addr: %d\n","pt_read_temp",(uint)i,
                   (uint)sensor_addr[i]);
            snprintf(tmp1,0x100,"Read sensor[%d] fail,addr: %d",(uint)i,(uint)sensor_addr[i]);
            log_to_file(tmp1,time_stamp);
          }
          else {
            *(int8_t *)((int)arg + i + 0x23658) = data[0];
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
          read_fail_cnt = read_fail_cnt + 1;
        }
      }
      if (g_pwm_enable != false) {
        sweep_set_pwm_by_temp();
      }
      for (i_1 = 0; i_1 < 4; i_1 = i_1 + 1) {
        iVar3 = fan_get_realtime_speed(i_1);
        speed[i_1] = iVar3;
      }
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : fan:[%d][%d][%d][%d]\n","pt_read_temp",speed[0],speed[1],speed[2],speed[3]);
      snprintf(tmp1,0x100,"fan:[%d][%d][%d][%d]",speed[0],speed[1],speed[2],speed[3]);
      log_to_file(tmp1,time_stamp);
      if (0 < read_fail_cnt) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : WARNING READ TEMP SENSOR ERR...\n","pt_read_temp");
        builtin_strncpy(tmp1,"WARNING READ TEMP SENSOR ERR...",0x20);
        log_to_file(tmp1,time_stamp);
        err_exit("sensor err");
      }
      iVar4 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
      iVar5 = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
      _Var2 = board_temp_protect_check((int8_t)iVar4,(int8_t)iVar5);
      if (!_Var2) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : WARNING TEMP OUT OF PROTECT...\n","pt_read_temp");
        uVar1 = tmp1._28_4_;
        builtin_strncpy(tmp1,"WARNING TEMP OUT OF PROTECT...",0x1f);
        tmp1[0x1f] = SUB41(uVar1,3);
        log_to_file(tmp1,time_stamp);
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        iVar4 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
        iVar5 = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
        printf("%s : WARNING temp max:%d,temp min:%d\n","pt_read_temp",iVar4,iVar5);
        iVar4 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
        iVar5 = pf_get_min_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
        snprintf(tmp1,0x100,"WARNING temp max:%d,temp min:%d",iVar4,iVar5);
        log_to_file(tmp1,time_stamp);
        err_exit("temp high");
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      sleep(1);
      sleep_counter = sleep_counter + '\x01';
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s stop\n","pt_read_temp","pt_read_temp");
    snprintf(tmp1,0x100,"%s stop","pt_read_temp");
    log_to_file(tmp1,time_stamp);
    __th = pthread_self();
    pthread_detach(__th);
  }
  return (void *)0x0;
}

