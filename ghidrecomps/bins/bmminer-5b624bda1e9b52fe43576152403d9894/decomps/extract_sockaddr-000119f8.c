
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

_Bool extract_sockaddr(char *url,char **sockaddr_url,char **sockaddr_port)

{
  char cVar1;
  char *pcVar2;
  char *url_begin;
  char *ipv6_begin;
  char *__s;
  char *ipv6_end;
  char *pcVar3;
  char *url_end;
  size_t sVar4;
  char *slash;
  size_t sVar5;
  int url_len;
  char *pcVar6;
  char port [6];
  char url_address [256];
  
  *sockaddr_url = url;
  pcVar2 = strstr(url,DAT_00011b14);
  if (pcVar2 != (char *)0x0) {
    url = pcVar2 + 2;
  }
  pcVar2 = strchr(url,0x5b);
  __s = strchr(url,0x5d);
  if ((__s == (char *)0x0 || pcVar2 == (char *)0x0) || (__s <= pcVar2)) {
    pcVar3 = strchr(url,0x3a);
    if (pcVar3 == (char *)0x0) goto LAB_00011ad0;
LAB_00011a44:
    sVar5 = (int)pcVar3 - (int)url;
    sVar4 = strlen(url);
    if ((int)(char *)(~sVar5 + sVar4) < 1) {
      return false;
    }
    pcVar6 = pcVar3 + 1;
    pcVar3 = (char *)(~sVar5 + sVar4);
  }
  else {
    pcVar3 = strchr(__s,0x3a);
    if (pcVar3 != (char *)0x0) goto LAB_00011a44;
LAB_00011ad0:
    sVar5 = strlen(url);
    pcVar6 = pcVar3;
  }
  if ((int)sVar5 < 1) {
    return false;
  }
  if ((__s != (char *)0x0 && pcVar2 != (char *)0x0) && (pcVar2 < __s)) {
    sVar5 = sVar5 - 2;
    url = url + 1;
  }
  snprintf(url_address,0xfe,DAT_00011b18,sVar5,url);
  if (pcVar3 == (char *)0x0) {
    port._0_2_ = (undefined2)*DAT_00011b1c;
    port[2] = (char)((uint)*DAT_00011b1c >> 0x10);
  }
  else {
    pcVar2 = port;
    snprintf(pcVar2,6,DAT_00011b18,pcVar3,pcVar6);
    if (port[0] != '\0') {
      if ((port[0] != '/') && (port[0] != '#')) {
        pcVar2 = port;
        do {
          pcVar2 = pcVar2 + 1;
          cVar1 = *pcVar2;
          if (cVar1 == '\0') goto LAB_00011af2;
        } while ((cVar1 != '/') && (cVar1 != '#'));
        if (pcVar2 == (char *)0x0) goto LAB_00011af2;
      }
      *pcVar2 = '\0';
    }
  }
LAB_00011af2:
  pcVar2 = (char *)__strdup(port);
  *sockaddr_port = pcVar2;
  pcVar2 = (char *)__strdup(url_address);
  *sockaddr_url = pcVar2;
  return true;
}

