
int get_macBytes(char *device,uchar *mac)

{
  int iVar1;
  int iVar2;
  ifreq ifreq;
  
  iVar1 = socket(2,1,0);
  if (iVar1 < 0) {
    perror("error sock");
    iVar1 = 2;
  }
  else {
    ifreq.ifr_ifrn._0_4_ = 0x30687465;
    ifreq.ifr_ifrn.ifrn_name[4] = '\0';
    iVar2 = ioctl(iVar1,0x8927,&ifreq);
    if (iVar2 < 0) {
      perror("error ioctl");
      close(iVar1);
      iVar1 = 3;
    }
    else {
      iVar2 = 0;
      do {
        device[iVar2] = ifreq.ifr_ifru.ifru_slave[iVar2 + 2];
        iVar2 = iVar2 + 1;
      } while (iVar2 != 6);
      close(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

