
void get_time(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  socklen_t local_10c;
  int local_108;
  fd_set fStack_104;
  timeval local_84;
  timeval local_7c;
  sockaddr local_74;
  tm local_64;
  time_t tStack_38;
  time_t tStack_34;
  tm *local_30;
  time_t local_2c;
  tm *local_28;
  int local_24;
  int local_20;
  fd_set *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c;
  
  local_108 = -1;
  local_c = 0;
  puts("\n--- get time");
  local_14 = socket(2,1,0);
  if ((int)local_14 < 0) {
    puts("Socket initialisation failed");
    puts("Can\'t get time");
  }
  else {
    puts("Socket initialisation ok");
  }
  memset(&local_74,0,0x10);
  local_74.sa_family = 2;
  local_74.sa_data._2_4_ = inet_addr("202.108.22.5");
  local_74.sa_data._0_2_ = htons(0x50);
  local_18 = fcntl(local_14,3,0);
  fcntl(local_14,4,local_18 | 0x800);
  iVar2 = connect(local_14,&local_74,0x10);
  if (iVar2 == -1) {
    local_7c.tv_sec = 1;
    local_7c.tv_usec = 0;
    cVar1 = sock_connecting();
    if (cVar1 != '\x01') {
      close(local_14);
      puts("Socket isn\'t connecting");
    }
    do {
      local_1c = &fStack_104;
      for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 1) {
        fStack_104.fds_bits[local_10] = 0;
      }
      uVar4 = local_14 + 0x1f;
      if (-1 < (int)local_14) {
        uVar4 = local_14;
      }
      uVar5 = local_14 & 0x1f;
      if ((int)local_14 < 1) {
        uVar5 = -(-local_14 & 0x1f);
      }
      fStack_104.fds_bits[(int)uVar4 >> 5] =
           fStack_104.fds_bits[(int)uVar4 >> 5] | 1 << (uVar5 & 0xff);
      local_20 = select(local_14 + 1,(fd_set *)0x0,&fStack_104,(fd_set *)0x0,&local_7c);
      if (0 < local_20) {
        uVar4 = local_14 + 0x1f;
        if (-1 < (int)local_14) {
          uVar4 = local_14;
        }
        uVar5 = local_14 & 0x1f;
        if ((int)local_14 < 1) {
          uVar5 = -(-local_14 & 0x1f);
        }
        if ((1 << (uVar5 & 0xff) & fStack_104.fds_bits[(int)uVar4 >> 5]) != 0) {
          local_10c = 4;
          local_24 = getsockopt(local_14,1,4,&local_108,&local_10c);
          if ((local_24 == 0) && (local_108 == 0)) {
            local_18 = fcntl(local_14,3,0);
            fcntl(local_14,4,local_18 & 0xfffff7ff);
            puts("Socket connect ok");
            time(&tStack_34);
            local_28 = localtime(&tStack_34);
            printf("year:%04d, month:%02d, day:%02d\n",local_28->tm_year + 0x76c,
                   local_28->tm_mon + 1,local_28->tm_mday);
            printf("hour:%02d, minute:%02d, second:%02d\n",local_28->tm_hour,local_28->tm_min,
                   local_28->tm_sec);
            change_time_format(local_28,&time_data);
            local_c = 1;
          }
        }
      }
    } while ((local_20 < 0) && (iVar2 = interrupted(), iVar2 != 0));
    close(local_14);
  }
  else {
    local_18 = fcntl(local_14,3,0);
    fcntl(local_14,4,local_18 & 0xfffff7ff);
    puts("Socket connect ok ...");
    time(&tStack_34);
    local_28 = localtime(&tStack_34);
    printf("year:%04d, month:%02d, day:%02d\n",local_28->tm_year + 0x76c,local_28->tm_mon + 1,
           local_28->tm_mday);
    printf("hour:%02d, minute:%02d, second:%02d\n",local_28->tm_hour,local_28->tm_min,
           local_28->tm_sec);
    change_time_format(local_28,&time_data);
    local_c = 1;
  }
  if (local_c == 0) {
    if (gIsSetTime != '\0') {
      printf("%s: Start set system date\n","get_time");
      local_64.tm_year = conf._156_4_ + -0x76c;
      local_64.tm_mon = conf._160_4_ + -1;
      local_64.tm_mday = conf._164_4_;
      local_64.tm_min = conf._172_4_;
      local_64.tm_sec = conf._176_4_;
      if (((int)conf._168_4_ < 0) || (0xf < (int)conf._168_4_)) {
        if (((int)conf._168_4_ < 0x10) || (0x17 < (int)conf._168_4_)) {
          printf("%s: hour value in Config.ini is error!\n","get_time");
        }
        else {
          local_64.tm_hour = conf._168_4_ + -0x10;
        }
      }
      else {
        local_64.tm_hour = conf._168_4_ + 8;
      }
      local_84.tv_sec = mktime(&local_64);
      local_84.tv_usec = 0;
      local_2c = local_84.tv_sec;
      iVar2 = settimeofday(&local_84,(timezone *)0x0);
      if (iVar2 < 0) {
        puts("Set system datatime error!");
      }
      else {
        puts("Set system datatime ok!");
      }
      gIsSetTime = '\0';
    }
    time(&tStack_38);
    local_30 = localtime(&tStack_38);
    pcVar3 = asctime(local_30);
    printf("UTC time is : %s\n",pcVar3);
    change_time_format(local_30,&time_data);
  }
  return;
}

