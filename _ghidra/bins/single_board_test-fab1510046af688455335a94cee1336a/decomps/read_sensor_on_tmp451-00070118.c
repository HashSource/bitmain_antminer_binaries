
int32_t read_sensor_on_tmp451(int32_t chain,uint8_t is_remote)

{
  uint8_t is_remote_local;
  int32_t chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint8_t regaddr [2];
  uint8_t offset [2];
  uint8_t resp [2];
  int32_t ret;
  
  resp[0] = '\0';
  resp[1] = '\0';
  offset[0] = '\0';
  offset[1] = '\0';
  regaddr[0] = '\v';
  regaddr[1] = '\f';
  is_remote_local = is_remote;
  chain_local = chain;
  TMP451_open(chain);
  iic_read_reg(_g_tmp451_sensor.sensor_fd,&is_remote_local,1,resp,1,true);
  iic_read_reg(_g_tmp451_sensor.sensor_fd,regaddr,1,offset,1,true);
  iic_read_reg(_g_tmp451_sensor.sensor_fd,regaddr + 1,1,offset + 1,1,true);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: %s we read tmp451 fd :d%d chain %d is_remote %d read temp %d \n",
         "read_sensor_on_tmp451","read_sensor_on_tmp451",_g_tmp451_sensor.sensor_fd,chain_local,
         (uint)is_remote_local,(int)(char)resp[0]);
  snprintf(tmp1,0x800,"%s we read tmp451 fd :d%d chain %d is_remote %d read temp %d ",
           "read_sensor_on_tmp451",_g_tmp451_sensor.sensor_fd,chain_local,(uint)is_remote_local,
           (int)(char)resp[0]);
  log_to_file(tmp1,time_stamp);
  return (uint)resp[0];
}

