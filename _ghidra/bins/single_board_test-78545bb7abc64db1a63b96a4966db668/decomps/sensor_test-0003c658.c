
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sensor_test(void)

{
  uint8_t data [2];
  uint8_t addr [10];
  int8_t asic_temp;
  int8_t pcb_temp;
  int32_t ret;
  int32_t temp;
  
  pcb_temp = '\0';
  asic_temp = '\0';
  temp = 0;
  addr[0] = '\0';
  addr[1] = '\0';
  addr[2] = '\0';
  addr[3] = '\0';
  addr[4] = '\0';
  addr[5] = '\0';
  addr[6] = '\0';
  addr[7] = '\0';
  addr[8] = '\0';
  addr[9] = '\0';
  data[0] = '\0';
  data[1] = '\0';
  pca_switch_disable('\x01','p');
  pca_switch_disable('\x02','p');
  ret = 0;
  addr[0] = 'H';
  addr[1] = 'L';
  tsensor_open(2,addr,'\x02');
  pca_switch_set_channel('\x02','p','\x06');
  tsensor_read(2,addr[0],'\0',data,2);
  printf("index_%d temp:%d\n",0,(uint)data[0]);
  pca_switch_set_channel('\x02','p','\x05');
  tsensor_read(2,addr[1],'\0',data,2);
  printf("index_%d temp:%d\n",1,(uint)data[0]);
  pca_switch_read('\x02','\0','p','L',&pcb_temp,&asic_temp);
  printf("\n\nsensor_id = %d,pcb_temp=%d,asic_temp=%d\n\n",0,(int)pcb_temp,(int)asic_temp);
  pca_switch_read('\x02','\x01','p','L',&pcb_temp,&asic_temp);
  printf("\n\nsensor_id = %d,pcb_temp=%d,asic_temp=%d\n\n",1,(int)pcb_temp,(int)asic_temp);
  pca_switch_read('\x02','\x02','p','L',&pcb_temp,&asic_temp);
  printf("\n\nsensor_id = %d,pcb_temp=%d,asic_temp=%d\n\n",2,(int)pcb_temp,(int)asic_temp);
  pca_switch_read('\x02','\x04','p','L',&pcb_temp,&asic_temp);
  printf("\n\nsensor_id = %d,pcb_temp=%d,asic_temp=%d\n\n",4,(int)pcb_temp,(int)asic_temp);
  pca_switch_read('\x02','\x05','p','L',&pcb_temp,&asic_temp);
  printf("\n\nsensor_id = %d,pcb_temp=%d,asic_temp=%d\n\n",5,(int)pcb_temp,(int)asic_temp);
  return;
}

