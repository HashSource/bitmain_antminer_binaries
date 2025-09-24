
int http_parse_url(char *url,char *host,char *file,int *port)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  int *port_local;
  char *file_local;
  char *host_local;
  char *url_local;
  char *ptr2;
  int len;
  char *ptr1;
  
  if ((((url == (char *)0x0) || (host == (char *)0x0)) || (file == (char *)0x0)) ||
     (port == (int *)0x0)) {
    iVar4 = -1;
  }
  else {
    iVar4 = strncmp(url,"http://",7);
    if (iVar4 == 0) {
      ptr1 = url + 7;
    }
    else {
      iVar4 = strncmp(url,"https://",8);
      if (iVar4 != 0) {
        return -1;
      }
      ptr1 = url + 8;
    }
    pcVar1 = strchr(ptr1,0x2f);
    if (pcVar1 == (char *)0x0) {
      sVar2 = strlen(ptr1);
      memcpy(host,ptr1,sVar2);
      sVar2 = strlen(ptr1);
      host[sVar2] = '\0';
    }
    else {
      sVar2 = strlen(ptr1);
      sVar3 = strlen(pcVar1);
      memcpy(host,ptr1,sVar2 - sVar3);
      host[sVar2 - sVar3] = '\0';
      if (pcVar1[1] != '\0') {
        sVar2 = strlen(pcVar1);
        memcpy(file,pcVar1 + 1,sVar2 - 1);
        sVar2 = strlen(pcVar1);
        file[sVar2 - 1] = '\0';
      }
    }
    pcVar1 = strchr(host,0x3a);
    if (pcVar1 == (char *)0x0) {
      *port = 0x50;
    }
    else {
      *pcVar1 = '\0';
      iVar4 = atoi(pcVar1 + 1);
      *port = iVar4;
    }
    iVar4 = 0;
  }
  return iVar4;
}

