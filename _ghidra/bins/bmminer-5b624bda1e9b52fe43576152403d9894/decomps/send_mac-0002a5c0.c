
/* WARNING: Unknown calling convention */

void * send_mac(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  ssize_t sVar8;
  addrinfo *__ai;
  addrinfo *paVar9;
  byte *pbVar10;
  addrinfo *local_cb8;
  int *local_cb0;
  addrinfo **local_cac;
  char *local_ca8;
  addrinfo *local_c7c;
  socklen_t local_c78;
  int local_c74;
  timeval tv_timeout;
  ifreq ifreq;
  addrinfo hints;
  char s [1024];
  char rec [1024];
  
  mac = (char *)malloc(0x20);
  iVar1 = socket(2,1,0);
  if (iVar1 < 0) {
    perror("error sock");
  }
  else {
    ifreq.ifr_ifrn._0_4_ = 0x30687465;
    ifreq.ifr_ifrn.ifrn_name[4] = '\0';
    iVar2 = ioctl(iVar1,0x8927,&ifreq);
    if (iVar2 < 0) {
      perror("error ioctl");
      close(iVar1);
    }
    else {
      pbVar10 = (byte *)(ifreq.ifr_ifru.ifru_slave + 1);
      iVar2 = 0;
      do {
        pbVar10 = pbVar10 + 1;
        pcVar3 = mac + iVar2;
        iVar2 = iVar2 + 3;
        sprintf(pcVar3,"%02X:",(uint)*pbVar10);
        pcVar3 = mac;
      } while (iVar2 != 0x12);
      sVar4 = strlen(mac);
      pcVar3[sVar4 - 1] = '\0';
      close(iVar1);
    }
  }
  local_cb8 = (addrinfo *)&hints;
  local_ca8 = s;
  local_cac = &local_c7c;
  local_cb0 = &local_c74;
  do {
    send_mac::id = send_mac::id + 1;
    snprintf(local_ca8,0x400,"{\"ctrl_board\":\"%s\",\"id\":\"%d\",\"hashboard\":[%s]}",mac,
             send_mac::id,hash_board_id_string);
    hints.ai_protocol = 0;
    hints.ai_family = 0;
    hints.ai_addr = (sockaddr *)0x0;
    hints.ai_addrlen = 0;
    hints.ai_flags = 0;
    hints.ai_canonname = (char *)0x0;
    hints.ai_next = (addrinfo *)0x0;
    hints.ai_socktype = 1;
    iVar1 = getaddrinfo("auth.minerlink.com","7000",local_cb8,local_cac);
    if (iVar1 == 0) {
      if (local_c7c == (addrinfo *)0x0) {
        __ai = (addrinfo *)0x0;
      }
      else {
        paVar9 = local_c7c;
        do {
          uVar5 = socket(paVar9->ai_family,paVar9->ai_socktype,paVar9->ai_protocol);
          if (uVar5 != 0xffffffff) {
            uVar6 = fcntl(uVar5,3,0);
            fcntl(uVar5,4,uVar6 | 0x800);
            iVar1 = connect(uVar5,paVar9->ai_addr,paVar9->ai_addrlen);
            if (iVar1 != -1) {
LAB_0002a7ee:
              block_socket(uVar5);
              block_socket(uVar5);
              local_c74 = 10;
              setsockopt(uVar5,1,0x15,local_cb0,4);
              setsockopt(uVar5,1,0x14,local_cb0,4);
              sVar4 = strlen(local_ca8);
              send(uVar5,local_ca8,sVar4,0);
              memset((fd_set *)rec,0,0x400);
              sVar8 = recv(uVar5,(fd_set *)rec,0x400,0);
              if (sVar8 < 1) {
                freeaddrinfo(local_c7c);
                close(uVar5);
                stop_mining = false;
              }
              else {
                pcVar3 = strstr(rec,"false");
                if (pcVar3 != (char *)0x0) {
                  pcVar3 = (char *)0x1;
                }
                freeaddrinfo(local_c7c);
                close(uVar5);
                stop_mining = SUB41(pcVar3,0);
                if (pcVar3 != (char *)0x0) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
                    builtin_strncpy(rec,"Stop mining!",0xc);
                    rec[0xc] = '!';
                    rec[0xd] = '!';
                    rec[0xe] = '\0';
                    _applog(5,rec,false);
                  }
                  free(mac);
                  return (void *)0x0;
                }
              }
              goto LAB_0002a870;
            }
            tv_timeout.tv_sec = 10;
            tv_timeout.tv_usec = 0;
            piVar7 = __errno_location();
            if (*piVar7 == 0x73) {
              uVar6 = uVar5 + 0x1f & (int)uVar5 >> 0x20;
              if (((int)uVar5 >> 0x1e & 1U) == 0) {
                uVar6 = uVar5;
              }
              iVar1 = (int)uVar6 >> 5;
              uVar6 = 0;
              while( true ) {
                for (; uVar6 < 0x20; uVar6 = uVar6 + 1) {
                  ((fd_set *)rec)->fds_bits[uVar6] = 0;
                }
                ((fd_set *)rec)->fds_bits[iVar1] =
                     1 << ((int)uVar5 % 0x20 & 0xffU) | ((fd_set *)rec)->fds_bits[iVar1];
                iVar2 = select(uVar5 + 1,(fd_set *)0x0,(fd_set *)rec,(fd_set *)0x0,
                               (timeval *)&tv_timeout);
                if (0 < iVar2) break;
                if ((iVar2 == 0) || (*piVar7 != 4)) goto LAB_0002a71e;
                rec[0] = '\0';
                rec[1] = '\0';
                rec[2] = '\0';
                rec[3] = '\0';
                uVar6 = 1;
              }
              if ((((fd_set *)rec)->fds_bits[iVar1] >> ((int)uVar5 % 0x20 & 0xffU) & 1U) != 0) {
                local_c78 = 4;
                iVar1 = getsockopt(uVar5,1,4,local_cb0,&local_c78);
                if ((iVar1 == 0) && (local_c74 == 0)) goto LAB_0002a7ee;
              }
            }
LAB_0002a71e:
            close(uVar5);
          }
          paVar9 = paVar9->ai_next;
          __ai = local_c7c;
        } while (paVar9 != (addrinfo *)0x0);
      }
      freeaddrinfo(__ai);
    }
    stop_mining = false;
LAB_0002a870:
    uVar5 = time((time_t *)0x0);
    srand(uVar5);
    iVar1 = rand();
    sleep(iVar1 % 600 + 0x3c);
  } while( true );
}

