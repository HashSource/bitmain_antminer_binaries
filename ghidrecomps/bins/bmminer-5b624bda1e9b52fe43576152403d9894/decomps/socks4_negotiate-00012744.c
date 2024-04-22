
/* WARNING: Unknown calling convention */

_Bool socks4_negotiate(pool *pool,int sockd,_Bool socks4a)

{
  ushort port;
  long lVar1;
  in_addr_t iVar2;
  in_addr_t inp;
  int iVar3;
  size_t n;
  int len;
  uint uVar4;
  char *__s;
  addrinfo *servinfo;
  addrinfo servinfobase;
  char buf [515];
  char tmp42 [2048];
  
  buf[0] = '\x04';
  buf[1] = '\x01';
  lVar1 = strtol(pool->stratum_port,(char **)0x0,10);
  buf[3] = (char)lVar1;
  buf[2] = (char)((uint)lVar1 >> 8);
  buf._8_4_ = *DAT_000128d8;
  buf._12_4_ = DAT_000128d8[1];
  iVar2 = inet_addr(pool->sockaddr_url);
  uVar4 = iVar2 << 0x18 | (iVar2 >> 8 & 0xff) << 0x10 | (iVar2 >> 0x10 & 0xff) << 8 | iVar2 >> 0x18;
  if (uVar4 == 0xffffffff) {
    servinfo = &servinfobase;
    tmp42[8] = '\0';
    tmp42[9] = '\0';
    tmp42[10] = '\0';
    tmp42[11] = '\0';
    tmp42[12] = '\0';
    tmp42[13] = '\0';
    tmp42[14] = '\0';
    tmp42[15] = '\0';
    tmp42[16] = '\0';
    tmp42[17] = '\0';
    tmp42[18] = '\0';
    tmp42[19] = '\0';
    tmp42[20] = '\0';
    tmp42[21] = '\0';
    tmp42[22] = '\0';
    tmp42[23] = '\0';
    tmp42[24] = '\0';
    tmp42[25] = '\0';
    tmp42[26] = '\0';
    tmp42[27] = '\0';
    tmp42[28] = '\0';
    tmp42[29] = '\0';
    tmp42[30] = '\0';
    tmp42[31] = '\0';
    tmp42[0] = '\0';
    tmp42[1] = '\0';
    tmp42[2] = '\0';
    tmp42[3] = '\0';
    tmp42[4] = '\x02';
    tmp42[5] = '\0';
    tmp42[6] = '\0';
    tmp42[7] = '\0';
    iVar3 = getaddrinfo(pool->sockaddr_url,(char *)0x0,(addrinfo *)tmp42,(addrinfo **)&servinfo);
    if (iVar3 == 0) {
      uVar4 = *(uint *)(servinfo->ai_addr->sa_data + 2);
      freeaddrinfo((addrinfo *)servinfo);
      uVar4 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
              uVar4 >> 0x18;
      if (uVar4 == 0xffffffff) goto LAB_000128b2;
      goto LAB_00012790;
    }
    if (!socks4a) {
LAB_000128b2:
      if (((*DAT_000128dc == '\0') && (*DAT_000128e0 == '\0')) && (*DAT_000128e4 < 4)) {
        return false;
      }
      snprintf(tmp42,0x800,DAT_000128f4,pool->sockaddr_url);
      goto LAB_000127e6;
    }
    __s = pool->sockaddr_url;
    buf[4] = '\0';
    buf[5] = '\0';
    buf[6] = '\0';
    buf[7] = '\x01';
    n = strlen(__s);
    if (0xfe < (int)n) {
      n = 0xff;
    }
    _cg_memcpy(buf + 0x10,__s,n,DAT_000128f0,DAT_000128ec,0xab2);
    buf[n + 0x10] = '\0';
    send(sockd,buf,n + 0x11,0);
  }
  else {
LAB_00012790:
    buf[7] = (char)uVar4;
    buf[4] = (char)(uVar4 >> 0x18);
    buf[5] = (char)(uVar4 >> 0x10);
    buf[6] = (char)(uVar4 >> 8);
    send(sockd,buf,0x10,0);
  }
  iVar3 = recv_byte(sockd);
  if ((iVar3 == 0) && (iVar3 = recv_byte(sockd), iVar3 == 0x5a)) {
    iVar3 = 6;
    do {
      recv_byte(sockd);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return true;
  }
  if (((*DAT_000128dc == '\0') && (*DAT_000128e0 == '\0')) && (*DAT_000128e4 < 4)) {
    return false;
  }
  snprintf(tmp42,0x800,DAT_000128e8,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
LAB_000127e6:
  _applog(4,tmp42,false);
  return false;
}

