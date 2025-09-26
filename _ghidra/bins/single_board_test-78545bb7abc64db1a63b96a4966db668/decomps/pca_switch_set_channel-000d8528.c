
/* WARNING: Unknown calling convention */

int32_t pca_switch_set_channel(uint8_t chain_id,uint8_t switch_dev_addr,uint8_t channel_id)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint8_t channel;
  int8_t readdata;
  undefined4 local_830;
  char *local_82c;
  char tmp42 [2048];
  
  uVar3 = (uint)switch_dev_addr;
  uVar1 = (uint)chain_id;
  if (3 < uVar1) {
    pcVar4 = "only support 4 chain!!!,err: chain_id:%d\n";
LAB_000d86b6:
    snprintf(tmp42,0x800,pcVar4);
    _applog(0,tmp42,false);
    return -1;
  }
  if (7 < channel_id) {
    pcVar4 = "only support 4 channel!!!,err: channel_id:%d\n";
    goto LAB_000d86b6;
  }
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pca_read_mutex);
  if (iVar2 != 0) {
    builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
    _applog(0,tmp42,false);
    return -4;
  }
  pcVar4 = (char *)g_chain_switch_fd[uVar1];
  if (pcVar4 == (char *)0x0) {
    uVar6 = uVar1 + uVar3 & 7;
    uVar5 = (uVar1 + uVar3) * 0x2000000;
    local_830 = (uint)CONCAT11((char)uVar6,(byte)(uVar5 >> 0x1c)) << 0x10;
    _readdata = uVar1;
    local_82c = pcVar4;
    snprintf(tmp42,0x800,"swtich device addr:0x%x\n",uVar6 << 1 | (uVar5 >> 0x1c) << 4);
    _applog(0,tmp42,false);
    pcVar4 = (char *)iic_init((iic_init_param_t *)&readdata);
    if ((int)pcVar4 < 0) {
      snprintf(tmp42,0x800," open switch error, chain is %d,slave addr is %d\n",uVar1,uVar3);
      _applog(0,tmp42,false);
      goto LAB_000d85c0;
    }
    g_chain_switch_fd[uVar1] = (uint32_t)pcVar4;
    g_chain_switch_addr[uVar1] = local_830._2_1_ << 4 | local_830._3_1_ << 1;
  }
  channel = (uint8_t)(1 << (uint)channel_id);
  _readdata = _readdata & 0xffffff00;
  pcVar4 = (char *)iic_write((int32_t)pcVar4,&channel,1);
  if ((int)pcVar4 < 0) {
    snprintf(tmp42,0x800,"select switch failed, channel :%x, chain is %d,slave addr is %d fd:%d\n",
             (uint)channel,uVar1,uVar3,pcVar4);
    _applog(0,tmp42,false);
  }
  else {
    usleep(10000);
    uVar3 = iic_read(g_chain_switch_fd[uVar1],&readdata,1);
    uVar5 = (int)readdata - (uint)channel;
    if (uVar5 != 0) {
      uVar5 = 1;
    }
    pcVar4 = (char *)(uVar5 | uVar3 >> 0x1f);
    if (pcVar4 != (char *)0x0) {
      snprintf(tmp42,0x800,
               "select switch read back channel :%x, chain is %d, read data[0x%x], ret = %d\n",
               (uint)channel,uVar1,(int)readdata,uVar3);
      _applog(0,tmp42,false);
      pcVar4 = (char *)0x0;
    }
  }
LAB_000d85c0:
  pthread_mutex_unlock((pthread_mutex_t *)&pca_read_mutex);
  return (int32_t)pcVar4;
}

