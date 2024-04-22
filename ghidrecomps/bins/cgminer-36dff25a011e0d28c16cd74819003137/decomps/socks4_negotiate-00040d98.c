
_Bool socks4_negotiate(pool *pool,int sockd,_Bool socks4a)

{
  int iVar1;
  in_addr_t __netlong;
  _Bool _Var2;
  _Bool socks4a_local;
  int sockd_local;
  pool *pool_local;
  addrinfo servinfobase;
  addrinfo hints;
  addrinfo *servinfo;
  char buf [515];
  sockaddr_in *saddr_in;
  ushort port;
  int len;
  int i;
  in_addr_t inp;
  
  buf[0] = '\x04';
  buf[1] = '\x01';
  iVar1 = atoi(pool->stratum_port);
  buf[2] = (char)((uint)iVar1 >> 8);
  buf[3] = (char)iVar1;
  buf[8] = s_CGMINER_0009fe8c[0];
  buf[9] = s_CGMINER_0009fe8c[1];
  buf[10] = s_CGMINER_0009fe8c[2];
  buf[11] = s_CGMINER_0009fe8c[3];
  buf[12] = s_CGMINER_0009fe8c[4];
  buf[13] = s_CGMINER_0009fe8c[5];
  buf[14] = s_CGMINER_0009fe8c[6];
  buf[15] = s_CGMINER_0009fe8c[7];
  __netlong = inet_addr(pool->sockaddr_url);
  inp = ntohl(__netlong);
  if (inp == 0xffffffff) {
    servinfo = &servinfobase;
    memset(&hints,0,0x20);
    hints.ai_family = 2;
    iVar1 = getaddrinfo(pool->sockaddr_url,(char *)0x0,(addrinfo *)&hints,(addrinfo **)&servinfo);
    socks4a_local = socks4a;
    if (iVar1 == 0) {
      inp = ntohl(*(uint32_t *)(servinfo->ai_addr->sa_data + 2));
      socks4a_local = false;
      freeaddrinfo((addrinfo *)servinfo);
    }
  }
  else {
    socks4a_local = false;
  }
  if (socks4a_local == true) {
    buf[4] = '\0';
    buf[5] = '\0';
    buf[6] = '\0';
    buf[7] = '\x01';
    len = strlen(pool->sockaddr_url);
    if (0xff < len) {
      len = 0xff;
    }
    _cg_memcpy(buf + 0x10,pool->sockaddr_url,len,"util.c","socks4_negotiate",0xb6b);
    iVar1 = len + 0x10;
    len = len + 0x11;
    buf[iVar1] = '\0';
    send(sockd,buf,len,0);
  }
  else {
    if (inp == 0xffffffff) {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf((char *)&hints,0x800,"Invalid IP address specified for socks4 proxy: %s",
                 pool->sockaddr_url);
        _applog(4,(char *)&hints,false);
      }
      return false;
    }
    buf[4] = (char)(inp >> 0x18);
    buf[5] = (char)(inp >> 0x10);
    buf[6] = (char)(inp >> 8);
    buf[7] = (char)inp;
    send(sockd,buf,0x10,0);
  }
  iVar1 = recv_byte(sockd);
  if ((iVar1 == 0) && (iVar1 = recv_byte(sockd), iVar1 == 0x5a)) {
    for (i = 0; i < 6; i = i + 1) {
      recv_byte(sockd);
    }
    _Var2 = true;
  }
  else {
    if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
      snprintf((char *)&hints,0x800,"Bad response from %s:%s SOCKS4 server",pool->sockaddr_proxy_url
               ,pool->sockaddr_proxy_port);
      _applog(4,(char *)&hints,false);
    }
    _Var2 = false;
  }
  return _Var2;
}

