
/* WARNING: Unknown calling convention */

int32_t pca_switch_read(uint8_t chain_id,uint8_t sesnor_id,uint8_t switch_dev_addr,
                       uint8_t sensor_dev_addr,int8_t *pcb_temp,int8_t *asic_temp)

{
  uint8_t uVar1;
  uint uVar2;
  int iVar3;
  int32_t iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint8_t channel;
  uint8_t disable_channel;
  uint8_t config_reg;
  uint8_t data;
  uint8_t reg;
  undefined3 uStack_833;
  undefined4 local_830;
  char *local_82c;
  uint8_t buf [2];
  char cStack_826;
  char cStack_825;
  
  uVar6 = (uint)switch_dev_addr;
  uVar5 = (uint)sesnor_id;
  uVar2 = (uint)chain_id;
  if (uVar2 < 4) {
    if (uVar5 < 8) {
      iVar3 = pthread_mutex_lock((pthread_mutex_t *)&pca_read_mutex);
      if (iVar3 != 0) {
        buf[0] = 'f';
        buf[1] = 'a';
        cStack_826 = 'i';
        cStack_825 = 'l';
        _applog(0,(char *)buf,false);
        return -4;
      }
      pcVar7 = (char *)g_chain_switch_fd[uVar2];
      if (pcVar7 == (char *)0x0) {
        local_830 = (CONCAT11((char)(uVar6 + uVar2),(byte)((uVar6 + uVar2) * 0x2000000 >> 0x1c)) &
                    0x7ff) << 0x10;
        _reg = uVar2;
        local_82c = pcVar7;
        pcVar7 = (char *)iic_init((iic_init_param_t *)&reg);
        if ((int)pcVar7 < 0) {
          snprintf((char *)buf,0x800," open switch error, chain is %d,slave addr is %d\n",uVar2,
                   uVar6);
          _applog(0,(char *)buf,false);
          goto LAB_000d835a;
        }
        g_chain_switch_fd[uVar2] = (uint32_t)pcVar7;
        g_chain_switch_addr[uVar2] = local_830._2_1_ << 4 | local_830._3_1_ << 1;
      }
      disable_channel = '\0';
      channel = (uint8_t)(1 << uVar5);
      if (clear_sensor_fd == false) {
        memset(g_chain_sensor_fd,0,0x80);
        clear_sensor_fd = true;
      }
      iVar4 = iic_write((int32_t)pcVar7,&disable_channel,1);
      if (-1 < iVar4) {
        usleep(20000);
        iVar4 = iic_write(g_chain_switch_fd[uVar2],&channel,1);
        if (iVar4 < 0) {
          snprintf((char *)buf,0x800,
                   "select switch failed, channel :%x, chain is %d,slave addr is %d fd:%d\n",
                   (uint)channel,uVar2,uVar6,iVar4);
          goto LAB_000d8484;
        }
        usleep(20000);
        if ((char *)g_chain_sensor_fd[uVar2][uVar5] == (char *)0x0) {
          uVar9 = sensor_dev_addr & 7;
          uVar8 = (uint)sensor_dev_addr << 0x19;
          local_830 = (uint)CONCAT11((char)uVar9,(byte)(uVar8 >> 0x1c)) << 0x10;
          _reg = uVar2;
          local_82c = (char *)g_chain_sensor_fd[uVar2][uVar5];
          snprintf((char *)buf,0x800,"swtich device addr:0x%x\n",uVar9 << 1 | (uVar8 >> 0x1c) << 4);
          _applog(0,(char *)buf,false);
          pcVar7 = (char *)iic_init((iic_init_param_t *)&reg);
          if ((int)pcVar7 < 0) {
            snprintf((char *)buf,0x800," open switch error, chain is %d,slave addr is %d\n",uVar2,
                     uVar6);
            _applog(0,(char *)buf,false);
            goto LAB_000d835a;
          }
          g_chain_sensor_fd[uVar2][uVar5] = (uint32_t)pcVar7;
        }
        usleep(20000);
        config_reg = '\x03';
        data = '\0';
        iic_read_reg(g_chain_sensor_fd[uVar2][uVar5],&config_reg,1,&data,1,true);
        if (-1 < (int)((uint)data << 0x1d)) {
          config_reg = '\t';
          data = '\x04';
          iic_write_reg(g_chain_sensor_fd[uVar2][uVar5],&config_reg,1,&data,1,true);
          usleep(80000);
        }
        pcVar7 = (char *)0x0;
        _buf = _buf & 0xffff0000;
        _reg = _reg & 0xffffff00;
        iic_read_reg(g_chain_sensor_fd[uVar2][uVar5],&reg,2,buf,2,true);
        uVar1 = buf[0];
        _buf = _buf & 0xffff0000;
        _reg = CONCAT31(uStack_833,1);
        *pcb_temp = uVar1 + 0xc0;
        usleep(20000);
        iic_read_reg(g_chain_sensor_fd[uVar2][uVar5],&reg,2,buf,2,true);
        *asic_temp = buf[0] + 0xc0;
        usleep(20000);
        iic_write(g_chain_switch_fd[uVar2],&disable_channel,1);
        usleep(20000);
LAB_000d835a:
        pthread_mutex_unlock((pthread_mutex_t *)&pca_read_mutex);
        return (int32_t)pcVar7;
      }
      snprintf((char *)buf,0x800,
               "disable all channel, channel :%x, chain is %d,slave addr is %d fd:%d\n",
               (uint)channel,uVar2,uVar6,iVar4);
      goto LAB_000d8484;
    }
    pcVar7 = "only support 4 channel!!!,err: sesnor_id:%d";
  }
  else {
    pcVar7 = "only support 4 chain!!!,err: chain_id:%d";
    uVar5 = uVar2;
  }
  snprintf((char *)buf,0x800,pcVar7,uVar5);
LAB_000d8484:
  _applog(0,(char *)buf,false);
  return -1;
}

