
/* WARNING: Unknown calling convention */

int32_t exec_power_cmd(int32_t fd,uint8_t *send_data,uint32_t send_data_len,uint8_t *read_back_data,
                      uint32_t read_back_data_len)

{
  byte *pbVar1;
  char cVar2;
  short sVar3;
  uint8_t *data;
  uint uVar4;
  uint uVar5;
  int32_t iVar6;
  uint8_t reg_addr;
  uint8_t byte;
  
  reg_addr = '\0';
  pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
  if (exec_power_cmd::has_sent_0x04 == false) {
    byte = '\x04';
    iic_write_reg(fd,&reg_addr,1,&byte,1,true);
    exec_power_cmd::has_sent_0x04 = true;
  }
  cVar2 = '\x03';
  do {
    uVar4 = 0;
    if (send_data_len != 0) {
      do {
        data = send_data + uVar4;
        uVar4 = uVar4 + 1 & 0xff;
        iic_write_reg(fd,&reg_addr,1,data,1,true);
      } while (uVar4 < send_data_len);
    }
    usleep(400000);
    if (read_back_data_len == 0) {
      iVar6 = -0x7ffffcff;
      usleep(100000);
    }
    else {
      uVar4 = 0;
      do {
        uVar5 = uVar4 + 1 & 0xff;
        iic_read_reg(fd,&reg_addr,1,read_back_data + uVar4,1,false);
        uVar4 = uVar5;
      } while (uVar5 < read_back_data_len);
      usleep(100000);
      if (read_back_data == (uint8_t *)0x0 || send_data == (uint8_t *)0x0) {
        iVar6 = -0x7ffffcff;
      }
      else {
        sVar3 = 0;
        if (2 < read_back_data_len - 2) {
          pbVar1 = read_back_data + 1;
          do {
            pbVar1 = pbVar1 + 1;
            sVar3 = sVar3 + (ushort)*pbVar1;
          } while (pbVar1 != read_back_data + (read_back_data_len - 3));
        }
        if ((((sVar3 == CONCAT11(read_back_data[read_back_data_len - 1],
                                 read_back_data[read_back_data_len - 2])) &&
             (*send_data == *read_back_data)) && (send_data[1] == read_back_data[1])) &&
           ((send_data[3] == read_back_data[3] && (read_back_data_len == read_back_data[2] + 2)))) {
          iVar6 = 0;
          goto LAB_000d45b2;
        }
        iVar6 = -0x7ffffd00;
      }
    }
    cVar2 = cVar2 + -1;
    if (cVar2 == '\0') {
LAB_000d45b2:
      pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
      return iVar6;
    }
  } while( true );
}

