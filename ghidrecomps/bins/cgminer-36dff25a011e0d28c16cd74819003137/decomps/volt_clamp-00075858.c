
int volt_clamp(uint8_t chain,uint8_t enable)

{
  byte bVar1;
  byte bVar2;
  FILE *pFVar3;
  uint8_t enable_local;
  uint8_t chain_local;
  uint8_t read_back_data [2];
  uint8_t crc_data [2];
  FILE *pFile;
  FILE *pFile_1;
  ushort crc;
  uint8_t length;
  int retry_count;
  
  retry_count = 0;
  while( true ) {
    if (2 < retry_count) {
      return 0;
    }
    pthread_mutex_lock((pthread_mutex_t *)&iic_mutex);
    usleep(100000);
    write_pic_iic(chain,'U');
    write_pic_iic(chain,0xaa);
    write_pic_iic(chain,'\x05');
    write_pic_iic(chain,'1');
    write_pic_iic(chain,enable);
    write_pic_iic(chain,(uint8_t)((ushort)(enable + 0x36) >> 8));
    write_pic_iic(chain,(uint8_t)(enable + 0x36));
    usleep(500000);
    bVar1 = read_pic_iic(chain);
    bVar2 = read_pic_iic(chain);
    pthread_mutex_unlock((pthread_mutex_t *)&iic_mutex);
    if ((bVar1 == 0x31) && (bVar2 == 1)) break;
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: failed on Chain[%d], b[0] = %d, b[2] = %d!\n","dspic33ep16gs202.c"
                ,0x56,"volt_clamp",(uint)chain,(uint)bVar1,(uint)bVar2);
      }
      fclose(pFVar3);
    }
    sleep(1);
    retry_count = retry_count + 1;
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: Disable pic crab for chain %d success!\n","dspic33ep16gs202.c",0x5b,
              "volt_clamp",(uint)chain);
    }
    fclose(pFVar3);
  }
  return 1;
}

