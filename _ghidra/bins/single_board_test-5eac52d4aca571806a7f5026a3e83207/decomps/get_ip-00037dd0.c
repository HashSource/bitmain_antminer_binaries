
int32_t get_ip(char *ip)

{
  int __fd;
  int iVar1;
  char *__s;
  size_t __n;
  int32_t iVar2;
  char *ip_local;
  ifreq ifr;
  int32_t inet_sock;
  char *temp;
  
  __fd = socket(2,2,0);
  memset(&ifr,0,0x10);
  memcpy(&ifr,&DAT_001e8424,4);
  iVar1 = ioctl(__fd,0x8915,&ifr);
  if (iVar1 == 0) {
    __s = inet_ntoa((in_addr)ifr.ifr_ifru.ifru_map.mem_end);
    __n = strlen(__s);
    memcpy(ip,__s,__n);
    close(__fd);
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

