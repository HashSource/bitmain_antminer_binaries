
/* WARNING: Unknown calling convention */

int32_t pca_switch_disable(uint8_t chain_id,uint8_t switch_dev_addr)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  char *ctx;
  uint uVar4;
  uint uVar5;
  uint8_t channel;
  undefined4 local_828;
  char *local_824;
  char tmp42 [2048];
  
  uVar3 = (uint)switch_dev_addr;
  uVar1 = (uint)chain_id;
  if (3 < uVar1) {
    snprintf(tmp42,0x800,"only support 4 chain!!!,err: chain_id:%d\n",uVar1);
    _applog(0,tmp42,false);
    return -1;
  }
  iVar2 = pthread_mutex_lock((pthread_mutex_t *)&pca_read_mutex);
  if (iVar2 != 0) {
    builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
    _applog(0,tmp42,false);
    return -4;
  }
  ctx = (char *)g_chain_switch_fd[uVar1];
  if (ctx == (char *)0x0) {
    uVar5 = uVar1 + uVar3 & 7;
    uVar4 = (uVar1 + uVar3) * 0x2000000;
    local_828 = (uint)CONCAT11((char)uVar5,(byte)(uVar4 >> 0x1c)) << 0x10;
    _channel = uVar1;
    local_824 = ctx;
    snprintf(tmp42,0x800,"swtich device addr:0x%x\n",uVar5 << 1 | (uVar4 >> 0x1c) << 4);
    _applog(0,tmp42,false);
    ctx = (char *)iic_init((iic_init_param_t *)&channel);
    if ((int)ctx < 0) {
      snprintf(tmp42,0x800," open switch error, chain is %d,slave addr is %d\n",uVar1,uVar3);
      _applog(0,tmp42,false);
      goto LAB_000c9c92;
    }
    g_chain_switch_fd[uVar1] = (uint32_t)ctx;
    g_chain_switch_addr[uVar1] = local_828._3_1_ << 1 | local_828._2_1_ << 4;
  }
  _channel = _channel & 0xffffff00;
  ctx = (char *)iic_write((int32_t)ctx,&channel,1);
  if ((int)ctx < 0) {
    snprintf(tmp42,0x800,"select switch failed, channel :%x, chain is %d,slave addr is %d fd:%d\n",
             _channel & 0xff,uVar1,uVar3,ctx);
    _applog(0,tmp42,false);
  }
  else {
    usleep(10000);
  }
LAB_000c9c92:
  pthread_mutex_unlock((pthread_mutex_t *)&pca_read_mutex);
  return (int32_t)ctx;
}

