
/* WARNING: Unknown calling convention */

int32_t exec_power_cmd(int32_t fd,uint8_t *send_data,uint32_t send_data_len,uint8_t *read_back_data,
                      uint32_t read_back_data_len)

{
  int32_t iVar1;
  char cVar2;
  uint8_t *data;
  uint uVar3;
  uint uVar4;
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
    uVar3 = 0;
    if (send_data_len != 0) {
      do {
        data = send_data + uVar3;
        uVar3 = uVar3 + 1 & 0xff;
        iic_write_reg(fd,&reg_addr,1,data,1,true);
      } while (uVar3 < send_data_len);
    }
    usleep(400000);
    uVar3 = 0;
    if (read_back_data_len != 0) {
      do {
        uVar4 = uVar3 + 1 & 0xff;
        iic_read_reg(fd,&reg_addr,1,read_back_data + uVar3,1,false);
        uVar3 = uVar4;
      } while (uVar4 < read_back_data_len);
    }
    usleep(100000);
    iVar1 = check_read_back_data(send_data,read_back_data,read_back_data_len);
  } while ((iVar1 != 0) && (cVar2 = cVar2 + -1, cVar2 != '\0'));
  pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
  return iVar1;
}

