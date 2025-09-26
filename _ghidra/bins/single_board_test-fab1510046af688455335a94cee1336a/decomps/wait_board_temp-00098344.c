
int wait_board_temp(int8_t *tempval,int8_t sensor_num,int32_t target_temp)

{
  int8_t iVar1;
  int iVar2;
  int32_t target_temp_local;
  int8_t sensor_num_local;
  int8_t *tempval_local;
  char tmp42 [256];
  int k;
  int32_t temp;
  
  snprintf(tmp42,0x100,"wait board temp come to %d",target_temp);
  puts(tmp42);
  iVar1 = pf_get_max_value(tempval,sensor_num);
  temp = (int32_t)iVar1;
  k = 0;
  if (target_temp == 0) {
LAB_00098444:
    iVar2 = 0;
  }
  else {
    do {
      if (target_temp <= temp) goto LAB_00098444;
      iVar1 = pf_get_max_value(tempval,sensor_num);
      temp = (int32_t)iVar1;
      sleep(1);
      k = k + 1;
      if (k % 5 == 0) {
        snprintf(tmp42,0x100,"get curr board min temp:%d, loop time %ds",temp,k);
        puts(tmp42);
      }
    } while (k < 0x12d);
    printf("can not warm up to target temp:%d!!!",target_temp);
    iVar2 = -1;
  }
  return iVar2;
}

