
/* WARNING: Unknown calling convention */

_Bool http_negotiate(pool *pool,int sockd,_Bool http0)

{
  size_t __n;
  ssize_t sVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char cStack_c21;
  char buf [1024];
  char tmp42 [2048];
  
  pcVar4 = pool->sockaddr_url;
  pcVar6 = pool->stratum_port;
  if (http0) {
    snprintf(buf,0x400,"CONNECT %s:%s HTTP/1.0\r\n\r\n",pcVar4,pcVar6);
  }
  else {
    snprintf(buf,0x400,"CONNECT %s:%s HTTP/1.1\r\nHost: %s:%s\r\n\r\n",pcVar4,pcVar6,pcVar4,pcVar6);
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
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
      return false;
    }
    pcVar6 = pool->sockaddr_proxy_url;
    pcVar5 = pool->sockaddr_proxy_port;
    pcVar4 = "Couldn\'t read from proxy %s:%s after sending CONNECT";
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
    if ((iVar2 != 0) && (iVar2 = strcmp(buf,"HTTP/1.0 200"), iVar2 != 0)) {
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
        return false;
      }
      snprintf(tmp42,0x800,"HTTP Error from proxy %s:%s - %s",pool->sockaddr_proxy_url,
               pool->sockaddr_proxy_port,buf);
      goto LAB_0001094a;
    }
    pcVar4 = &cStack_c21;
    do {
      uVar3 = recv_byte(sockd);
      pcVar4 = pcVar4 + 1;
      *pcVar4 = (char)uVar3;
      if ((uVar3 & 0xff) == 0xff) goto LAB_0001091e;
    } while (pcVar4 != buf + 3);
    do {
      iVar2 = strncmp(buf,"\r\n\r\n",4);
      if (iVar2 == 0) {
        if ((opt_debug != false) &&
           (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
          snprintf(tmp42,0x800,"Success negotiating with %s:%s HTTP proxy",pool->sockaddr_proxy_url,
                   pool->sockaddr_proxy_port);
          _applog(7,tmp42,false);
          return true;
        }
        return true;
      }
      buf[0] = buf[1];
      buf[1] = buf[2];
      buf[2] = buf[3];
      uVar3 = recv_byte(sockd);
      buf[3] = (char)uVar3;
    } while ((uVar3 & 0xff) != 0xff);
LAB_0001091e:
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 4)) {
      return false;
    }
    pcVar6 = pool->sockaddr_proxy_url;
    pcVar5 = pool->sockaddr_proxy_port;
    pcVar4 = "Couldn\'t read HTTP byte from proxy %s:%s";
  }
  snprintf(tmp42,0x800,pcVar4,pcVar6,pcVar5);
LAB_0001094a:
  _applog(4,tmp42,false);
  return false;
}

