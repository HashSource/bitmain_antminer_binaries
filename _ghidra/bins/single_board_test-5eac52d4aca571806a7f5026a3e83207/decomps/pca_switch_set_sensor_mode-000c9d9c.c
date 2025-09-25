
/* WARNING: Unknown calling convention */

int32_t pca_switch_set_sensor_mode
                  (uint8_t chain_id,uint8_t sesnor_id,uint8_t switch_dev_addr,
                  uint8_t sensor_dev_addr)

{
  uint uVar1;
  int iVar2;
  int32_t iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint8_t channel;
  uint8_t disable_channel;
  int8_t readdata;
  uint8_t config_reg;
  uint8_t data;
  undefined3 uStack_833;
  undefined4 local_830;
  char *local_82c;
  char tmp42 [2048];
  
  uVar6 = (uint)switch_dev_addr;
  uVar4 = (uint)sesnor_id;
  uVar1 = (uint)chain_id;
  if (uVar1 < 4) {
    if (uVar4 < 8) {
      iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pca_read_mutex);
      if (iVar2 != 0) {
        builtin_strncpy(tmp42,"failed to pca_switch_read lock\n",0x20);
        _applog(0,tmp42,false);
        return -4;
      }
      pcVar7 = (char *)g_chain_switch_fd[uVar1];
      if (pcVar7 == (char *)0x0) {
        local_830 = (CONCAT11((char)(uVar1 + uVar6),(byte)((uVar1 + uVar6) * 0x2000000 >> 0x1c)) &
                    0x7ff) << 0x10;
        _data = uVar1;
        local_82c = pcVar7;
        pcVar7 = (char *)iic_init((iic_init_param_t *)&data);
        if (-1 < (int)pcVar7) {
          g_chain_switch_fd[uVar1] = (uint32_t)pcVar7;
          g_chain_switch_addr[uVar1] = local_830._3_1_ << 1 | local_830._2_1_ << 4;
          goto LAB_000c9df0;
        }
LAB_000c9f34:
        snprintf(tmp42,0x800," open switch error, chain is %d,slave addr is %d\n",uVar1,uVar6);
        _applog(0,tmp42,false);
      }
      else {
LAB_000c9df0:
        channel = (uint8_t)(1 << uVar4);
        disable_channel = '\0';
        if (clear_sensor_fd == false) {
          memset(g_chain_sensor_fd,0,0x80);
          clear_sensor_fd = true;
        }
        iVar3 = iic_write((int32_t)pcVar7,&disable_channel,1);
        if (iVar3 < 0) {
          snprintf(tmp42,0x800,
                   "disable all channel, channel :%x, chain is %d,slave addr is %d fd:%d\n",
                   (uint)channel,uVar1,uVar6,iVar3);
          goto LAB_000ca038;
        }
        usleep(10000);
        iVar3 = iic_write(g_chain_switch_fd[uVar1],&channel,1);
        if (iVar3 < 0) {
          snprintf(tmp42,0x800,
                   "select switch failed, channel :%x, chain is %d,slave addr is %d fd:%d\n",
                   (uint)channel,uVar1,uVar6,iVar3);
          goto LAB_000ca038;
        }
        usleep(10000);
        readdata = '\0';
        iic_read(g_chain_switch_fd[uVar1],&readdata,1);
        if ((char *)g_chain_sensor_fd[uVar1][uVar4] == (char *)0x0) {
          uVar8 = sensor_dev_addr & 7;
          uVar5 = (uint)sensor_dev_addr << 0x19;
          local_830 = (uint)CONCAT11((char)uVar8,(byte)(uVar5 >> 0x1c)) << 0x10;
          _data = uVar1;
          local_82c = (char *)g_chain_sensor_fd[uVar1][uVar4];
          snprintf(tmp42,0x800,"swtich device addr:0x%x\n",uVar8 << 1 | (uVar5 >> 0x1c) << 4);
          _applog(0,tmp42,false);
          pcVar7 = (char *)iic_init((iic_init_param_t *)&data);
          if ((int)pcVar7 < 0) goto LAB_000c9f34;
          g_chain_sensor_fd[uVar1][uVar4] = (uint32_t)pcVar7;
        }
        iVar3 = iic_write(g_chain_switch_fd[uVar1],&channel,1);
        if (iVar3 < 0) {
          pcVar7 = (char *)0xffffffff;
          snprintf(tmp42,0x800,
                   "select switch failed, channel :%x, chain is %d,slave addr is %d fd:%d\n",
                   (uint)channel,uVar1,uVar6,iVar3);
          _applog(0,tmp42,false);
        }
        else {
          usleep(10000);
          config_reg = '\x03';
          _data = _data & 0xffffff00;
          iVar3 = iic_read_reg(g_chain_sensor_fd[uVar1][uVar4],&config_reg,1,&data,1,true);
          if (iVar3 < 0) {
            pcVar7 = (char *)0xffffffff;
            snprintf(tmp42,0x800,
                     "read extend mode failed, channel :%x, chain is %d,slave addr is %d fd:%d\n",
                     (uint)channel,uVar1,uVar6,iVar3);
            _applog(0,tmp42,false);
          }
          else {
            iVar2 = _data << 0x1d;
            if (iVar2 < 0) {
              pcVar7 = (char *)0x0;
            }
            else {
              config_reg = '\t';
              _data = CONCAT31(uStack_833,4);
              iVar3 = iic_write_reg(g_chain_sensor_fd[uVar1][uVar4],&config_reg,1,&data,1,true);
              if (iVar3 < 0) {
                snprintf(tmp42,0x800,
                         "set extend mode failed, channel :%x, chain is %d,slave addr is %d fd:%d\n"
                         ,(uint)channel,uVar1,uVar6,iVar3);
                pcVar7 = (char *)0xffffffff;
                _applog(0,tmp42,SUB41((uint)iVar2 >> 0x1f,0));
              }
              else {
                usleep(80000);
                pcVar7 = (char *)0x0;
              }
            }
          }
        }
      }
      pthread_mutex_unlock((pthread_mutex_t *)&pca_read_mutex);
      return (int32_t)pcVar7;
    }
    pcVar7 = "only support 4 channel!!!,err: sesnor_id:%d";
  }
  else {
    pcVar7 = "only support 4 chain!!!,err: chain_id:%d";
    uVar4 = uVar1;
  }
  snprintf(tmp42,0x800,pcVar7,uVar4);
LAB_000ca038:
  _applog(0,tmp42,false);
  return -1;
}

