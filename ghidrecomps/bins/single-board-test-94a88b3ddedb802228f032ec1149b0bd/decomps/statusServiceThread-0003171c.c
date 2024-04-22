
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int statusServiceThread(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  undefined4 local_6064;
  undefined local_6060;
  int local_605c;
  undefined2 local_6058;
  undefined local_6056;
  socklen_t local_6054;
  char acStack_6050 [10240];
  undefined4 local_3850;
  undefined4 uStack_384c;
  undefined2 local_3848;
  sockaddr sStack_2850;
  char local_2840 [4];
  char acStack_283c [10236];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  size_t local_2c;
  ssize_t local_28;
  int local_24;
  int local_20;
  uint local_1c;
  ssize_t local_18;
  char *local_14;
  
  local_40 = 3;
  local_3c = 0;
  local_24 = param_1;
  memset(local_2840,0,0x2800);
  local_14 = local_2840;
  local_28 = -1;
  local_2c = 0;
  local_30 = 0;
  local_18 = 0;
  local_6054 = 0;
  local_1c = 0;
  local_6056 = 0;
  local_605c = -1;
  local_20 = 0;
  local_6058 = 0xa0d;
  local_6060 = 0;
  local_6064 = 0xa0d0a0d;
  memset(local_2840,0,0x2800);
  do {
    if (ExitServer == '\x01') goto LAB_00031972;
    local_28 = recvfrom(local_24,local_14,0x27ff - local_18,0,&sStack_2850,&local_6054);
    if (local_28 < 1) {
      close(local_24);
      puts(":statusServiceThread recvfrom<=0");
      return 0;
    }
    local_18 = local_28;
    if (local_28 == 0x27ff) {
      close(local_24);
      puts("BUFSIZE is too small!");
      return 0;
    }
    local_14 = local_2840 + local_28;
    pcVar1 = strstr(local_2840,(char *)&local_6064);
  } while (pcVar1 == (char *)0x0);
  puts("find http request end flag!");
LAB_00031972:
  printf("get http=%s\n",local_2840);
  if ((((local_2840[0] == 'G') && (local_2840[1] == 'E')) && (local_2840[2] == 'T')) &&
     (local_2840[3] == ' ')) {
    pcVar1 = strstr(acStack_283c,"rate");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strstr(acStack_283c,"test");
      if (pcVar1 == (char *)0x0) {
        close(local_24);
        puts("statusServiceThread exit for Error cmd!");
        return 0;
      }
      __isoc99_sscanf(acStack_283c,"/test.%d",&local_605c);
      printf("cmd : get test = %d\n",local_605c);
      if (local_605c != 0x20b) {
        saveTestID(local_605c);
      }
      local_20 = 1;
    }
    else {
      puts("cmd : get rate");
      local_20 = 0;
    }
    local_28 = setsockopt(local_24,1,0x15,&local_40,8);
    if (local_28 == 0) {
      local_28 = setsockopt(local_24,1,0x14,&local_40,8);
      if (local_28 == 0) {
        if (local_20 == 1) {
          if (local_605c == 0x20b) {
            getMinerInfo(&local_3850);
          }
          else {
            sprintf((char *)&local_3850,"OK get test=%d",local_605c);
          }
        }
        else {
          local_34 = readRebootTestNum();
          if (local_34 == 0xd05) {
            searchStatus = 2;
          }
          switch(searchStatus) {
          case 0:
            local_3850._0_1_ = s_searching_00132440[0];
            local_3850._1_1_ = s_searching_00132440[1];
            local_3850._2_1_ = s_searching_00132440[2];
            local_3850._3_1_ = s_searching_00132440[3];
            uStack_384c._0_1_ = s_searching_00132440[4];
            uStack_384c._1_1_ = s_searching_00132440[5];
            uStack_384c._2_1_ = s_searching_00132440[6];
            uStack_384c._3_1_ = s_searching_00132440[7];
            local_3848 = (short)ram0x00132448;
            break;
          case 1:
            iVar3 = is_S11();
            if ((iVar3 == 0) || (iVar3 = is_working_in_low_power_mode(), iVar3 == 0)) {
              uVar2 = GetTotalRate();
              uVar2 = ConvirtTotalRate(uVar2);
              sprintf((char *)&local_3850,"%d",uVar2);
            }
            else {
              local_38 = get_eco_mode_ideal_rate();
              uVar2 = ConvirtTotalRate(local_38);
              sprintf((char *)&local_3850,"%d",uVar2);
            }
            break;
          case 2:
            sprintf((char *)&local_3850,"searchfailed:%s",search_failed_info);
            break;
          case 3:
            uVar2 = GetTotalRate();
            uVar2 = ConvirtTotalRate(uVar2);
            sprintf((char *)&local_3850,"%d",uVar2);
            break;
          default:
            local_3850._0_1_ = s_searching_00132440[0];
            local_3850._1_1_ = s_searching_00132440[1];
            local_3850._2_1_ = s_searching_00132440[2];
            local_3850._3_1_ = s_searching_00132440[3];
            uStack_384c._0_1_ = s_searching_00132440[4];
            uStack_384c._1_1_ = s_searching_00132440[5];
            uStack_384c._2_1_ = s_searching_00132440[6];
            uStack_384c._3_1_ = s_searching_00132440[7];
            local_3848 = (short)ram0x00132448;
          }
        }
        local_2c = strlen((char *)&local_3850);
        local_28 = 0;
        iVar3 = sprintf(acStack_6050,"HTTP/1.0  200  OK%s",&local_6058);
        local_28 = local_28 + iVar3;
        iVar3 = sprintf(acStack_6050 + local_28,"Server: SearchFreqServer%s",&local_6058);
        local_28 = local_28 + iVar3;
        iVar3 = sprintf(acStack_6050 + local_28,"Cache-Control: no-cache%s",&local_6058);
        local_28 = local_28 + iVar3;
        iVar3 = sprintf(acStack_6050 + local_28,"Pragma: no-cache%s",&local_6058);
        local_28 = local_28 + iVar3;
        iVar3 = sprintf(acStack_6050 + local_28,"Content-Type: text/plain%s",&local_6058);
        local_28 = local_28 + iVar3;
        iVar3 = sprintf(acStack_6050 + local_28,"Content-Length: %d%s",local_2c,&local_6058);
        local_28 = local_28 + iVar3;
        iVar3 = sprintf(acStack_6050 + local_28,"Connection: Keep-Alive%s",&local_6064);
        local_28 = local_28 + iVar3;
        puts("send http response...");
        while (ExitServer != '\x01') {
          local_1c = 0;
          do {
            pcVar1 = acStack_6050 + local_1c;
            sVar4 = strlen(acStack_6050);
            local_28 = send(local_24,pcVar1,sVar4 - local_1c,0);
            if ((local_28 == -1) && (piVar5 = __errno_location(), *piVar5 == 0xb)) {
              puts("statusServiceThread send http timeout, try again...");
              usleep(100000);
            }
            else {
              if (local_28 < 1) {
                close(local_24);
                puts("statusServiceThread send http response error");
                return 0;
              }
              local_1c = local_28 + local_1c;
            }
            sVar4 = strlen(acStack_6050);
          } while ((local_1c < sVar4) && (ExitServer != '\x01'));
          sVar4 = strlen(acStack_6050);
          if ((sVar4 <= local_1c) || (ExitServer != '\0')) break;
        }
        puts("send http data...");
        local_1c = 0;
        while( true ) {
          local_28 = send(local_24,(void *)((int)&local_3850 + local_1c),local_2c - local_1c,0);
          printf("send http data ret=%d\n",local_28);
          if (local_28 < 1) break;
          local_1c = local_28 + local_1c;
          if ((((int)local_2c <= (int)local_1c) || (local_30 != 0)) || (ExitServer == '\x01'))
          goto LAB_0003211e;
        }
        local_30 = 1;
        puts("statusServiceThread send http data error");
LAB_0003211e:
        puts("one client disconnected!");
        close(local_24);
      }
      else {
        close(local_24);
        puts("setsockopt SO_RCVTIMEO failed");
        local_1c = 0;
      }
    }
    else {
      close(local_24);
      puts("setsockopt SO_SNDTIMEO failed");
      local_1c = 0;
    }
  }
  else {
    close(local_24);
    puts("statusServiceThread not support http command");
    local_1c = 0;
  }
  return local_1c;
}

