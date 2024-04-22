
/* WARNING: Unknown calling convention */

int dsPIC33EP16GS202_read_out_4_voltage
              (uchar which_iic,uchar which_chain,uint *vol0,uint *vol1,uint *vol2,uint *vol3)

{
  undefined4 uVar1;
  uchar uVar2;
  uint uVar3;
  uchar *puVar4;
  uchar *puVar5;
  uint config_data;
  byte *pbVar6;
  uchar send_data [6];
  uchar read_back_data [13];
  uchar auStack_2b [7];
  
  send_data[2] = '\x04';
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  pbVar6 = send_data;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  config_data = (uint)which_chain << 0x10 | 0x400000 | (uint)which_iic << 0x1a;
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[11] = '\0';
  read_back_data[12] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '(';
  send_data[4] = '\0';
  send_data[5] = ',';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  while (i2c_write(uVar3 | config_data), pbVar6 != send_data + 5) {
    pbVar6 = pbVar6 + 1;
    uVar3 = (uint)*pbVar6;
  }
  usleep(300000);
  puVar4 = read_back_data;
  do {
    uVar2 = i2c_read(config_data);
    puVar5 = puVar4 + 1;
    *puVar4 = uVar2;
    puVar4 = puVar5;
  } while (auStack_2b != puVar5);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[1] == '(') && (read_back_data[2] == '\x01')) {
    *vol0 = (uint)CONCAT11(read_back_data[3],read_back_data[4]);
    *vol1 = (uint)CONCAT11(read_back_data[5],read_back_data[6]);
    uVar1 = DAT_000244c4;
    *vol2 = (uint)CONCAT11(read_back_data[7],read_back_data[8]);
    *vol3 = (uint)CONCAT11(read_back_data[9],read_back_data[10]);
    printf("\n--- %s ADC0 = %d, ADC1 = %d, ADC2 = %d, ADC3 = %d\n",uVar1,*vol0,*vol1,*vol2,
           (uint)CONCAT11(read_back_data[9],read_back_data[10]));
    return 1;
  }
  printf("\n--- %s failed!\n\n",DAT_000244c4);
  return 0;
}

