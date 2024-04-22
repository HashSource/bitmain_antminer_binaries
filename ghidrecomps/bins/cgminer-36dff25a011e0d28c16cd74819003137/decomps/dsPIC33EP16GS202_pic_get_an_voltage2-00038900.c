
double dsPIC33EP16GS202_pic_get_an_voltage2(uchar which_iic)

{
  uint8_t uVar1;
  FILE *pFVar2;
  double dVar3;
  uchar which_iic_local;
  uchar read_back_data [9];
  uchar crc_data [2];
  FILE *pFile;
  FILE *pFile_1;
  ushort crc;
  uchar length;
  int retry_count;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  retry_count = 0;
  while( true ) {
    if (1 < retry_count) {
      return DAT_00038c68;
    }
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    write_pic_iic(which_iic,'U');
    write_pic_iic(which_iic,0xaa);
    write_pic_iic(which_iic,'\x04');
    write_pic_iic(which_iic,')');
    write_pic_iic(which_iic,'\0');
    write_pic_iic(which_iic,'-');
    usleep(500000);
    uVar1 = read_pic_iic(which_iic);
    read_back_data[0] = uVar1;
    uVar1 = read_pic_iic(which_iic);
    read_back_data[1] = uVar1;
    uVar1 = read_pic_iic(which_iic);
    read_back_data[2] = uVar1;
    uVar1 = read_pic_iic(which_iic);
    read_back_data[3] = uVar1;
    uVar1 = read_pic_iic(which_iic);
    read_back_data[4] = uVar1;
    uVar1 = read_pic_iic(which_iic);
    read_back_data._4_2_ = CONCAT11(uVar1,read_back_data[4]);
    uVar1 = read_pic_iic(which_iic);
    read_back_data._4_3_ = CONCAT12(uVar1,read_back_data._4_2_);
    uVar1 = read_pic_iic(which_iic);
    read_back_data[7] = uVar1;
    read_back_data[8] = read_pic_iic(which_iic);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    if ((read_back_data[1] == ')') && (read_back_data[2] == '\x01')) break;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: Couldn\'t hear AN voltage response from IIC[%d]\n","power.c",0x416
                ,"dsPIC33EP16GS202_pic_get_an_voltage2",(uint)which_iic);
      }
      fclose(pFVar2);
    }
    dump_mem("read_back_data:",read_back_data,9);
    sleep(1);
    retry_count = retry_count + 1;
  }
  if (5 < log_level) {
    print_crt_time_to_file(log_file,5);
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: Receive AN voltage response from IIC[%d]\n","power.c",0x41c,
              "dsPIC33EP16GS202_pic_get_an_voltage2",(uint)which_iic);
    }
    fclose(pFVar2);
  }
  dVar3 = decode_an_voltage_buf(read_back_data);
  return dVar3;
}

