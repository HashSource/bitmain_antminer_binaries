
_Bool http_negotiate(pool *pool,int sockd,_Bool http0)

{
  size_t __n;
  ssize_t sVar1;
  int iVar2;
  _Bool http0_local;
  int sockd_local;
  pool *pool_local;
  char tmp42 [2048];
  char buf [1024];
  int len;
  int i;
  
  if (http0) {
    snprintf(buf,0x400,"CONNECT %s:%s HTTP/1.0\r\n\r\n",pool->sockaddr_url,pool->stratum_port);
  }
  else {
    snprintf(buf,0x400,"CONNECT %s:%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n",pool->sockaddr_url,
             pool->stratum_port,pool->sockaddr_url,pool->stratum_port);
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"Sending proxy %s:%s - %s",pool->sockaddr_proxy_url,
             pool->sockaddr_proxy_port,buf);
    _applog(7,tmp42,false);
  }
  __n = strlen(buf);
  send(sockd,buf,__n,0);
  sVar1 = recv(sockd,buf,0xc,0);
  if (sVar1 < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"Couldn\'t read from proxy %s:%s after sending CONNECT",
               pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
      _applog(4,tmp42,false);
    }
  }
  else {
    buf[sVar1] = '\0';
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Received from proxy %s:%s - %s",pool->sockaddr_proxy_url,
               pool->sockaddr_proxy_port,buf);
      _applog(7,tmp42,false);
    }
    iVar2 = strcmp(buf,"HTTP/1.1 200");
    if ((iVar2 == 0) || (iVar2 = strcmp(buf,"HTTP/1.0 200"), iVar2 == 0)) {
      for (i = 0; i < 4; i = i + 1) {
        iVar2 = recv_byte(sockd);
        buf[i] = (char)iVar2;
        if (buf[i] == -1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            snprintf(tmp42,0x800,"Couldn\'t read HTTP byte from proxy %s:%s",
                     pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
            _applog(4,tmp42,false);
          }
          return false;
        }
      }
      do {
        iVar2 = strncmp(buf,"\r\n\r\n",4);
        if (iVar2 == 0) {
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            snprintf(tmp42,0x800,"Success negotiating with %s:%s HTTP proxy",
                     pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
            _applog(7,tmp42,false);
          }
          return true;
        }
        for (i = 0; i < 3; i = i + 1) {
          buf[i] = buf[i + 1];
        }
        iVar2 = recv_byte(sockd);
        buf[3] = (char)iVar2;
      } while (buf[3] != -1);
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"Couldn\'t read HTTP byte from proxy %s:%s",pool->sockaddr_proxy_url,
                 pool->sockaddr_proxy_port);
        _applog(4,tmp42,false);
      }
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
      snprintf(tmp42,0x800,"HTTP Error from proxy %s:%s - %s",pool->sockaddr_proxy_url,
               pool->sockaddr_proxy_port,buf);
      _applog(4,tmp42,false);
    }
  }
  return false;
}

