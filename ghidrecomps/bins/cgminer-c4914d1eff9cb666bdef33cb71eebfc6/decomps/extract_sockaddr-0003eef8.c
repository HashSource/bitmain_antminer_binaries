
_Bool extract_sockaddr(char *url,char **sockaddr_url,char **sockaddr_port)

{
  char *pcVar1;
  char *__s;
  size_t sVar2;
  _Bool _Var3;
  char **sockaddr_port_local;
  char **sockaddr_url_local;
  char *url_local;
  char port [6];
  char url_address [256];
  char *slash;
  char *ipv6_end;
  char *ipv6_begin;
  int port_len;
  int url_len;
  char *port_start;
  char *url_end;
  char *url_begin;
  
  port_start = (char *)0x0;
  port_len = 0;
  *sockaddr_url = url;
  pcVar1 = strstr(url,"//");
  url_begin = url;
  if (pcVar1 != (char *)0x0) {
    url_begin = pcVar1 + 2;
  }
  pcVar1 = strchr(url_begin,0x5b);
  __s = strchr(url_begin,0x5d);
  if (((pcVar1 == (char *)0x0) || (__s == (char *)0x0)) || (__s <= pcVar1)) {
    url_end = strchr(url_begin,0x3a);
  }
  else {
    url_end = strchr(__s,0x3a);
  }
  if (url_end == (char *)0x0) {
    url_len = strlen(url_begin);
  }
  else {
    url_len = (int)url_end - (int)url_begin;
    sVar2 = strlen(url_begin);
    port_len = (sVar2 - url_len) + -1;
    if (port_len < 1) {
      return false;
    }
    port_start = url_end + 1;
  }
  if (url_len < 1) {
    _Var3 = false;
  }
  else {
    if (((pcVar1 != (char *)0x0) && (__s != (char *)0x0)) && (pcVar1 < __s)) {
      url_len = url_len + -2;
      url_begin = url_begin + 1;
    }
    snprintf(url_address,0xfe,"%.*s",url_len,url_begin);
    if (port_len == 0) {
      port._0_2_ = (undefined2)DAT_00087c30;
      port[2] = (char)((uint)DAT_00087c30 >> 0x10);
    }
    else {
      snprintf(port,6,"%.*s",port_len,port_start);
      pcVar1 = strpbrk(port,"/#");
      if (pcVar1 != (char *)0x0) {
        *pcVar1 = '\0';
      }
    }
    pcVar1 = strdup(port);
    *sockaddr_port = pcVar1;
    pcVar1 = strdup(url_address);
    *sockaddr_url = pcVar1;
    _Var3 = true;
  }
  return _Var3;
}

