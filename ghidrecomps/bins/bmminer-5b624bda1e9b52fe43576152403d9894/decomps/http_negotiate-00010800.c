
/* WARNING: Unknown calling convention */

_Bool http_negotiate(pool *pool,int sockd,_Bool http0)

{
  char cVar1;
  size_t __n;
  ssize_t sVar2;
  int len;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char cStack_c21;
  char buf [1024];
  char tmp42 [2048];
  
  pcVar5 = pool->sockaddr_url;
  pcVar7 = pool->stratum_port;
  if (http0) {
    snprintf(buf,0x400,DAT_00010a34,pcVar5,pcVar7);
  }
  else {
    snprintf(buf,0x400,DAT_00010a58,pcVar5,pcVar7,pcVar5,pcVar7);
  }
  pcVar5 = DAT_00010a6c;
  if ((*DAT_00010a6c != '\0') &&
     (((*DAT_00010a38 != '\0' || (*DAT_00010a3c != '\0')) || (6 < *DAT_00010a50)))) {
    snprintf(tmp42,0x800,DAT_00010a40,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port,buf);
    _applog(7,tmp42,false);
  }
  __n = strlen(buf);
  send(sockd,buf,__n,0);
  sVar2 = recv(sockd,buf,0xc,0);
  if (sVar2 < 1) {
    if (((*DAT_00010a38 == '\0') && (*DAT_00010a3c == '\0')) && (*DAT_00010a50 < 4)) {
      return false;
    }
    pcVar7 = pool->sockaddr_proxy_url;
    pcVar6 = pool->sockaddr_proxy_port;
    pcVar5 = DAT_00010a64;
  }
  else {
    cVar1 = *pcVar5;
    buf[sVar2] = '\0';
    if ((cVar1 != '\0') &&
       (((*DAT_00010a38 != '\0' || (*DAT_00010a3c != '\0')) || (6 < *DAT_00010a50)))) {
      snprintf(tmp42,0x800,DAT_00010a44,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port,buf);
      _applog(7,tmp42,false);
    }
    iVar3 = strcmp(buf,DAT_00010a48);
    if ((iVar3 != 0) && (iVar3 = strcmp(buf,DAT_00010a5c), iVar3 != 0)) {
      if (((*DAT_00010a38 == '\0') && (*DAT_00010a3c == '\0')) && (*DAT_00010a50 < 4)) {
        return false;
      }
      snprintf(tmp42,0x800,DAT_00010a60,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port,buf);
      goto LAB_0001094a;
    }
    pcVar7 = &cStack_c21;
    do {
      uVar4 = recv_byte(sockd);
      pcVar7 = pcVar7 + 1;
      *pcVar7 = (char)uVar4;
      if ((uVar4 & 0xff) == 0xff) goto LAB_0001091e;
    } while (pcVar7 != buf + 3);
    do {
      iVar3 = strncmp(buf,DAT_00010a4c,4);
      if (iVar3 == 0) {
        if ((*pcVar5 != '\0') &&
           (((*DAT_00010a38 != '\0' || (*DAT_00010a3c != '\0')) || (6 < *DAT_00010a50)))) {
          snprintf(tmp42,0x800,DAT_00010a68,pool->sockaddr_proxy_url,pool->sockaddr_proxy_port);
          _applog(7,tmp42,false);
          return true;
        }
        return true;
      }
      buf[0] = buf[1];
      buf[1] = buf[2];
      buf[2] = buf[3];
      uVar4 = recv_byte(sockd);
      buf[3] = (char)uVar4;
    } while ((uVar4 & 0xff) != 0xff);
LAB_0001091e:
    if (((*DAT_00010a38 == '\0') && (*DAT_00010a3c == '\0')) && (*DAT_00010a50 < 4)) {
      return false;
    }
    pcVar7 = pool->sockaddr_proxy_url;
    pcVar6 = pool->sockaddr_proxy_port;
    pcVar5 = DAT_00010a54;
  }
  snprintf(tmp42,0x800,pcVar5,pcVar7,pcVar6);
LAB_0001094a:
  _applog(4,tmp42,false);
  return false;
}

