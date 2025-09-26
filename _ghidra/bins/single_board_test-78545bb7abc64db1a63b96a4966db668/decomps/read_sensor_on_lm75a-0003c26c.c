
int32_t read_sensor_on_lm75a(int32_t chain,int32_t index)

{
  int32_t iVar1;
  int32_t index_local;
  int32_t chain_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t tmp_addr;
  uint8_t resp [2];
  
  resp[0] = '\0';
  resp[1] = '\0';
  iVar1 = LM75A_open(chain,(uint8_t)index);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    tmp_addr = '\0';
    iic_read_reg(_g_lm75a_sensor[chain * 2 + index].sensor_fd,&tmp_addr,2,resp,2,true);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : %s we read lm75a fd : %d chain %d read temp %d\n","read_sensor_on_lm75a",
           "read_sensor_on_lm75a",_g_lm75a_sensor[chain * 2 + index].sensor_fd,chain,
           (int)(char)resp[0]);
    snprintf(tmp1,0x100,"%s we read lm75a fd : %d chain %d read temp %d","read_sensor_on_lm75a",
             _g_lm75a_sensor[chain * 2 + index].sensor_fd,chain,(int)(char)resp[0]);
    log_to_file(tmp1,time_stamp);
    iVar1 = (int32_t)(char)resp[0];
  }
  return iVar1;
}

