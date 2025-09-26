
uint8_t chip_temp_calibration(uint32_t cur_vol)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar4;
  int8_t local_980;
  uint32_t cur_vol_local;
  char time_stamp [48];
  char tmp1 [2048];
  float chip_temp_read [5];
  float cal_baord_temp [5];
  float evntemp_rate2 [5];
  float power_rate2 [5];
  float chip_temp_constanc [5];
  float chip_temp_cal [5];
  float real_chip_power [5];
  float read_baord_temp [5];
  float chip_temp1 [5];
  float evntemp_rate [5];
  float power_rate [5];
  float chip_temp_base [5];
  float chip_vdd;
  int evntemp_temp;
  float chip_temp_ratio;
  float single_chip_power;
  float power;
  float leakage;
  int avg_num;
  int bin;
  int i_5;
  int i_4;
  int i_3;
  int i_2;
  int i_1;
  int which_chain;
  int i;
  float total_power;
  
  total_power = 0.0;
  fVar5 = (float)(Local_Config_Information->Test_Info).Test_Standard.leakage_current / 1000.0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: leakage = %f\n","chip_temp_calibration",SUB84((double)fVar5,0),
         (int)((ulonglong)(double)fVar5 >> 0x20));
  snprintf(tmp1,0x800,"leakage = %f",tmp1,(double)fVar5);
  log_to_file(tmp1,time_stamp);
  sleep(10);
  for (i = 0; i < 10; i = i + 1) {
    for (which_chain = 0; which_chain < 3; which_chain = which_chain + 1) {
      chain_switch_disable(which_chain);
    }
    fVar6 = bitmain_get_power_ac_power();
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: power is %f\n","chip_temp_calibration",SUB84((double)fVar6,0),
           (int)((ulonglong)(double)fVar6 >> 0x20));
    snprintf(tmp1,0x800,"power is %f",tmp1,(double)fVar6);
    log_to_file(tmp1,time_stamp);
    total_power = total_power + fVar6;
    sleep(6);
  }
  fVar6 = total_power / 10.0 - 200.0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: avg power is %f\n","chip_temp_calibration",SUB84((double)fVar6,0),
         (int)((ulonglong)(double)fVar6 >> 0x20));
  snprintf(tmp1,0x800,"avg power is %f",tmp1,(double)fVar6);
  log_to_file(tmp1,time_stamp);
  chip_temp_base[0] = 0.16;
  chip_temp_base[1] = 0.17;
  chip_temp_base[2] = -0.13667;
  chip_temp_base[3] = 0.14;
  chip_temp_base[4] = 0.05;
  power_rate[0] = 1.68;
  power_rate[1] = 2.4867;
  power_rate[2] = 2.2178;
  power_rate[3] = 2.52;
  power_rate[4] = 1.8467;
  evntemp_rate[0] = 1.0;
  evntemp_rate[1] = 1.0;
  evntemp_rate[2] = 1.004;
  evntemp_rate[3] = 1.0;
  evntemp_rate[4] = 1.0;
  chip_temp1[0] = 0.0;
  chip_temp1[1] = 0.0;
  chip_temp1[2] = 0.0;
  chip_temp1[3] = 0.0;
  chip_temp1[4] = 0.0;
  read_baord_temp[0] = 0.0;
  read_baord_temp[1] = 0.0;
  read_baord_temp[2] = 0.0;
  read_baord_temp[3] = 0.0;
  read_baord_temp[4] = 0.0;
  real_chip_power[0] = 0.0;
  real_chip_power[1] = 0.0;
  real_chip_power[2] = 0.0;
  real_chip_power[3] = 0.0;
  real_chip_power[4] = 0.0;
  fVar7 = (((float)cur_vol / (float)(Local_Config_Information->Hash_Board).Voltage_Domain) / 4.0) /
          100.0;
  uVar1 = (Local_Config_Information->Hash_Board).Asic_Num;
  iVar2 = (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch[0];
  for (i_1 = 0; i_1 < 5; i_1 = i_1 + 1) {
    read_baord_temp[i_1] =
         (float)(longlong)
                (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch
                     [i_1 + 2];
  }
  for (i_2 = 0; i_2 < 5; i_2 = i_2 + 1) {
    chip_temp1[i_2] =
         chip_temp_base[i_2] + power_rate[i_2] * (fVar6 / (float)uVar1) +
         evntemp_rate[i_2] * (float)(longlong)iVar2;
    dVar4 = exp((double)chip_temp1[i_2] * 0.0292);
    real_chip_power[i_2] =
         (float)((((double)(fVar5 * fVar7) * dVar4 * 0.1129) / 0.24836575324132612) / 0.25 +
                (double)fVar7 * 0.2912 * (double)fVar7 * 50.0);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: chip %d temp %f chip_vdd %f,leakage %f real_chip_power %f\n","chip_temp_calibration"
           ,i_2,real_chip_power + i_2,(double)chip_temp1[i_2],(double)fVar7,(double)fVar5,
           (double)real_chip_power[i_2]);
    snprintf(tmp1,0x800,"chip %d temp %f chip_vdd %f,leakage %f real_chip_power %f",i_2,
             (double)chip_temp1[i_2],(double)fVar7,(double)fVar5,(double)real_chip_power[i_2]);
    log_to_file(tmp1,time_stamp);
  }
  chip_temp_cal[0] = 0.0;
  chip_temp_cal[1] = 0.0;
  chip_temp_cal[2] = 0.0;
  chip_temp_cal[3] = 0.0;
  chip_temp_cal[4] = 0.0;
  for (i_3 = 0; i_3 < 5; i_3 = i_3 + 1) {
    chip_temp_cal[i_3] =
         chip_temp_base[i_3] + power_rate[i_3] * real_chip_power[i_3] +
         evntemp_rate[i_3] * (float)(longlong)iVar2;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    dVar4 = (double)chip_temp1[i_3];
    printf("%s: evntemp_temp %d chip %d temp %f chip_vdd %f,leakage %f real_chip_power %f\n",
           "chip_temp_calibration",iVar2,i_3,dVar4,(double)fVar7,(double)fVar5,
           (double)real_chip_power[i_3]);
    snprintf(tmp1,0x800,"evntemp_temp %d chip %d temp %f chip_vdd %f,leakage %f real_chip_power %f",
             iVar2,i_3,(int)((ulonglong)dVar4 >> 0x20),(double)chip_temp1[i_3],(double)fVar7,
             (double)fVar5,(double)real_chip_power[i_3]);
    log_to_file(tmp1,time_stamp);
  }
  chip_temp_constanc[0] = 2.41;
  chip_temp_constanc[1] = 2.9867;
  chip_temp_constanc[2] = 0.14;
  chip_temp_constanc[3] = 1.83;
  chip_temp_constanc[4] = 0.5;
  power_rate2[0] = 1.2533;
  power_rate2[1] = 1.8;
  power_rate2[2] = 1.72;
  power_rate2[3] = 2.0267;
  power_rate2[4] = 1.4467;
  evntemp_rate2[0] = 0.972;
  evntemp_rate2[1] = 0.96;
  evntemp_rate2[2] = 1.0;
  evntemp_rate2[3] = 0.988;
  evntemp_rate2[4] = 1.0;
  cal_baord_temp[0] = 0.0;
  cal_baord_temp[1] = 0.0;
  cal_baord_temp[2] = 0.0;
  cal_baord_temp[3] = 0.0;
  cal_baord_temp[4] = 0.0;
  chip_temp_read[0] = 0.0;
  chip_temp_read[1] = 0.0;
  chip_temp_read[2] = 0.0;
  chip_temp_read[3] = 0.0;
  chip_temp_read[4] = 0.0;
  for (i_4 = 0; i_4 < 5; i_4 = i_4 + 1) {
    chip_temp_read[i_4] =
         (float)(longlong)
                (int)gHistory_Result[gPattern_test_counter].sensor_local_temperature_from_switch
                     [i_4 + 7] * 1.15;
    cal_baord_temp[i_4] =
         chip_temp_constanc[i_4] + power_rate2[i_4] * real_chip_power[i_4] +
         evntemp_rate2[i_4] * (float)(longlong)iVar2;
    local_980 = (int8_t)(int)(chip_temp_read[i_4] - chip_temp_cal[i_4]);
    gSensor_Offset[i_4] = local_980;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    uVar3 = (undefined4)((ulonglong)(double)cal_baord_temp[i_4] >> 0x20);
    printf("%s: chip_temp_cal %f chip_temp_read %f gSensor_Offset %d  cal_baord_temp %f \n",
           "chip_temp_calibration",SUB84((double)chip_temp_cal[i_4],0),
           (int)((ulonglong)(double)chip_temp_cal[i_4] >> 0x20),(double)chip_temp_read[i_4],
           (int)gSensor_Offset[i_4]);
    snprintf(tmp1,0x800,"chip_temp_cal %f chip_temp_read %f gSensor_Offset %d  cal_baord_temp %f ",
             tmp1,(double)chip_temp_cal[i_4],(double)chip_temp_read[i_4],(int)gSensor_Offset[i_4],
             uVar3,(double)cal_baord_temp[i_4]);
    log_to_file(tmp1,time_stamp);
  }
  i_5 = 0;
  while( true ) {
    if (4 < i_5) {
      return '\0';
    }
    iVar2 = (int)(cal_baord_temp[i_5] - read_baord_temp[i_5]);
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    if (10 < iVar2) break;
    i_5 = i_5 + 1;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: sensor calibration fail since cal_baord temp diff to much index %d diff %f\n",
         "chip_temp_calibration",i_5,read_baord_temp + i_5,
         (double)(cal_baord_temp[i_5] - read_baord_temp[i_5]));
  snprintf(tmp1,0x800,"sensor calibration fail since cal_baord temp diff to much index %d diff %f",
           i_5,(double)(cal_baord_temp[i_5] - read_baord_temp[i_5]));
  log_to_file(tmp1,time_stamp);
  gHistory_Result[gPattern_test_counter].sensor_calibration_OK = false;
  return '\0';
}

