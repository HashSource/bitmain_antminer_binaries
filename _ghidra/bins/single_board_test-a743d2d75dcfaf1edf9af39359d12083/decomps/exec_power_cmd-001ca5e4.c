
/* WARNING: Unknown calling convention */

int32_t exec_power_cmd(int32_t fd,uint8_t *send_data,uint32_t send_data_len,uint8_t *read_back_data,
                      uint32_t read_back_data_len)

{
  int32_t iVar1;
  char cVar2;
  uint8_t *puVar3;
  uint uVar4;
  uint8_t reg_addr;
  
  reg_addr = '\0';
  cVar2 = '\x03';
  pthread_mutex_lock((pthread_mutex_t *)&power_mutex);
  do {
    uVar4 = 0;
    if (send_data_len != 0) {
      do {
        puVar3 = send_data + uVar4;
        uVar4 = uVar4 + 1 & 0xff;
        iic_write_reg(fd,&reg_addr,1,puVar3,1,true);
      } while (uVar4 < send_data_len);
    }
    usleep(400000);
    uVar4 = 0;
    if (read_back_data_len != 0) {
      do {
        puVar3 = read_back_data + uVar4;
        uVar4 = uVar4 + 1 & 0xff;
        iic_read_reg(fd,&reg_addr,1,puVar3,1,true);
      } while (uVar4 < read_back_data_len);
    }
    usleep(100000);
    iVar1 = check_read_back_data(send_data,read_back_data,read_back_data_len);
  } while ((iVar1 != 0) && (cVar2 = cVar2 + -1, cVar2 != '\0'));
  pthread_mutex_unlock((pthread_mutex_t *)&power_mutex);
  return iVar1;
}

