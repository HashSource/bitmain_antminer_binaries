
int32_t get_local_ip(char *ifname,char *ip)

{
  int __fd;
  size_t sVar1;
  int iVar2;
  char *__s;
  int32_t iVar3;
  char *ip_local;
  char *ifname_local;
  ifreq ifr;
  int32_t inet_sock;
  char *temp;
  
  __fd = socket(2,2,0);
  memset(&ifr,0,0x10);
  sVar1 = strlen(ifname);
  memcpy(&ifr,ifname,sVar1);
  iVar2 = ioctl(__fd,0x8915,&ifr);
  if (iVar2 == 0) {
    __s = inet_ntoa((in_addr)ifr.ifr_ifru.ifru_map.mem_end);
    sVar1 = strlen(__s);
    memcpy(ip,__s,sVar1);
    close(__fd);
    iVar3 = 0;
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}

