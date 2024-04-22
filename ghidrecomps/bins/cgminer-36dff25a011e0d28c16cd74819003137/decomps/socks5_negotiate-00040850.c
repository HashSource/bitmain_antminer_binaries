
_Bool socks5_negotiate(pool *pool,int sockd)

{
  int iVar1;
  uint uVar2;
  _Bool _Var3;
  int sockd_local;
  pool *pool_local;
  char tmp42 [2048];
  char buf [515];
  uchar atyp;
  ushort port;
  uchar uclen;
  int len;
  int i;
  
  buf[0] = '\x05';
  buf[1] = '\x01';
  buf[2] = '\0';
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Attempting to negotiate with %s:%s SOCKS5 proxy",pool->sockaddr_proxy_url,
             pool->sockaddr_proxy_port);
    _applog(7,tmp42,false);
  }
  send(sockd,buf,3,0);
  iVar1 = recv_byte(sockd);
  if ((iVar1 == 5) && (uVar2 = recv_byte(sockd), uVar2 == (byte)buf[2])) {
    buf[0] = '\x05';
    buf[1] = '\x01';
    buf[2] = '\0';
    buf[3] = '\x03';
    len = strlen(pool->sockaddr_url);
    if (0xff < len) {
      len = 0xff;
    }
    buf[4] = (char)len;
    _cg_memcpy(buf + 5,pool->sockaddr_url,len,"util.c","socks5_negotiate",0xb05);
    iVar1 = atoi(pool->stratum_port);
    port._0_1_ = (char)iVar1;
    buf[len + 5] = (char)((uint)iVar1 >> 8);
    buf[len + 6] = (char)port;
    send(sockd,buf,len + 7,0);
    iVar1 = recv_byte(sockd);
    if ((iVar1 == 5) && (iVar1 = recv_byte(sockd), iVar1 == 0)) {
      recv_byte(sockd);
      iVar1 = recv_byte(sockd);
      if ((char)iVar1 == '\x01') {
        for (i = 0; i < 4; i = i + 1) {
          recv_byte(sockd);
        }
      }
      else {
        if ((char)iVar1 != '\x03') {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Bad response from %s:%s SOCKS5 server",pool->sockaddr_proxy_url,
                     pool->sockaddr_proxy_port);
            _applog(4,tmp42,false);
          }
          return false;
        }
        iVar1 = recv_byte(sockd);
        for (i = 0; i < iVar1; i = i + 1) {
          recv_byte(sockd);
        }
      }
      for (i = 0; i < 2; i = i + 1) {
        recv_byte(sockd);
      }
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Success negotiating with %s:%s SOCKS5 proxy",pool->sockaddr_proxy_url,
                 pool->sockaddr_proxy_port);
        _applog(7,tmp42,false);
      }
      _Var3 = true;
    }
    else {
      if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
        snprintf(tmp42,0x800,"Bad response from %s:%s SOCKS5 server",pool->sockaddr_proxy_url,
                 pool->sockaddr_proxy_port);
        _applog(4,tmp42,false);
      }
      _Var3 = false;
    }
  }
  else {
    if ((use_syslog != false) || ((opt_log_output != false || (3 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Bad response from %s:%s SOCKS5 server",pool->sockaddr_proxy_url,
               pool->sockaddr_proxy_port);
      _applog(4,tmp42,false);
    }
    _Var3 = false;
  }
  return _Var3;
}

