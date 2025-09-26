
int32_t get_eth_mac(int8_t *device,uint8_t *mac)

{
  int __fd;
  int iVar1;
  int32_t iVar2;
  int8_t *piVar3;
  int8_t *piVar4;
  ifreq ifreq;
  char tmp42 [2048];
  
  __fd = socket(2,1,0);
  if (__fd < 0) {
    builtin_strncpy(tmp42,"error so",8);
    tmp42[8] = 'c';
    tmp42[9] = 'k';
    tmp42[10] = '\0';
    _applog(0,tmp42,false);
    iVar2 = -1;
  }
  else {
    ifreq.ifr_ifrn._0_4_ = 0x30687465;
    ifreq.ifr_ifrn.ifrn_name[4] = '\0';
    iVar1 = ioctl(__fd,0x8927,&ifreq);
    if (iVar1 < 0) {
      builtin_strncpy(tmp42,"error ioctl",0xc);
      _applog(0,tmp42,false);
      close(__fd);
      iVar2 = -2;
    }
    else {
      piVar3 = ifreq.ifr_ifru.ifru_slave + 1;
      piVar4 = device + -1;
      do {
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
        *piVar4 = *piVar3;
      } while (piVar4 != device + 5);
      close(__fd);
      iVar2 = 0;
    }
  }
  return iVar2;
}

