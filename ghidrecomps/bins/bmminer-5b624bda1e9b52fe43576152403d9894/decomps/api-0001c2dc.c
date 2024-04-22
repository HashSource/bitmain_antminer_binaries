
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void api(int api_thr_id)

{
  bool bVar1;
  pthread_mutex_t *ppVar2;
  io_list *piVar3;
  _Bool _Var4;
  _Bool addrok;
  int *arg;
  long *apisock;
  io_data *io_data_00;
  io_data *io_data_1;
  char *pcVar5;
  io_list *piVar6;
  io_list *io_list;
  int iVar7;
  int __not_first_call;
  size_t sVar8;
  char *buf_1;
  char *pcVar9;
  char *colon;
  char *pcVar10;
  byte *__dest;
  char *buf_2;
  byte *pbVar11;
  char *comma;
  ushort **ppuVar12;
  int iVar13;
  char *end;
  char *slash;
  long lVar14;
  int iVar15;
  int __res_3;
  time_t tVar16;
  time_t bindstart;
  long c;
  time_t tVar17;
  size_t sVar18;
  int n;
  char *param;
  json_t *pjVar19;
  undefined2 *puVar20;
  json_t *json;
  int *piVar21;
  json_t *json_val;
  json_t *__s;
  char cVar22;
  int __res;
  __int32_t *p_Var23;
  byte *pbVar24;
  int mask;
  json_t *pjVar25;
  int __res_4;
  byte bVar26;
  bool bVar27;
  int __res_1;
  io_list *piVar28;
  int __res_2;
  int i;
  int iVar29;
  int iVar30;
  thr_info *thr;
  json_type jVar31;
  char *ptr;
  CMDS *pCVar32;
  uchar *__s1_1;
  addrinfo *paVar33;
  int iVar34;
  undefined *puVar35;
  IPACCESS *__buf;
  addrinfo *host;
  json_t *pjVar36;
  int unaff_r6;
  char *api_groups;
  uchar *__s1;
  _Bool *p_Var37;
  byte *pbVar38;
  char *pcVar39;
  char *cmdptr;
  json_t *pjVar40;
  uint uVar41;
  json_t *__s_00;
  char *binderror;
  char *ptr_1;
  double dVar42;
  json_int_t jVar43;
  io_data *io_data;
  char *local_4bf8;
  __int32_t **local_4bec;
  char *local_4be8;
  void *__cancel_arg;
  undefined2 *local_4bd4;
  short port;
  char *next;
  char group;
  _Bool firstjoin;
  char *connectaddr;
  socklen_t clisiz;
  addrinfo *res;
  int optval;
  char port_s [10];
  addrinfo hints;
  thr_info bye_thr;
  char cmdbuf [100];
  sockaddr_storage cli;
  json_error_t json_err;
  __pthread_unwind_buf_t __cancel_buf;
  char cmdbuf_1 [100];
  char buf [8192];
  char param_buf [8192];
  
  iVar13 = opt_api_port;
  arg = (int *)malloc(4);
  _Var4 = opt_api_listen;
  *arg = -1;
  if (_Var4 == false) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(param_buf,0x800,"API not running%s"," - API will not be available");
      _applog(7,param_buf,false);
    }
    goto LAB_0001c364;
  }
  io_data_00 = (io_data *)malloc(0x10);
  pcVar5 = (char *)malloc(0x10000);
  *pcVar5 = '\0';
  io_data_00->ptr = pcVar5;
  io_data_00->cur = pcVar5;
  io_data_00->close = false;
  io_data_00->siz = 0x10000;
  io_data_00->sock = true;
  piVar6 = (io_list *)malloc(0xc);
  piVar6->io_data = io_data_00;
  piVar3 = io_head;
  if (io_head == (io_list *)0x0) {
    piVar6->prev = piVar6;
    piVar6->next = piVar6;
    io_head = piVar6;
  }
  else {
    piVar28 = io_head->prev;
    piVar6->next = io_head;
    piVar6->prev = piVar28;
    piVar3->prev = piVar6;
    piVar6->prev->next = piVar6;
  }
  iVar7 = pthread_mutex_init(DAT_0001c648,(pthread_mutexattr_t *)0x0);
  ppVar2 = DAT_0001d8b0;
  if (iVar7 != 0) {
    piVar21 = __errno_location();
    snprintf(param_buf,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar21,"api.c",
             ppVar2,0x14c5);
    _applog(3,param_buf,true);
    _quit(1);
  }
  iVar7 = __sigsetjmp(&__cancel_buf,0);
  if (iVar7 == 0) {
    __pthread_register_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
    api_groups = opt_api_groups;
    my_thr_id = api_thr_id;
    if (opt_api_groups == (char *)0x0) {
      sVar8 = 1;
      api_groups = "";
    }
    else {
      sVar8 = strlen(opt_api_groups);
      sVar8 = sVar8 + 1;
    }
    pcVar5 = (char *)malloc(sVar8);
    if (pcVar5 == (char *)0x0) {
      param_buf[0] = s_Failed_to_malloc_ipgroups_buf_00047fb8[0];
      param_buf[1] = s_Failed_to_malloc_ipgroups_buf_00047fb8[1];
      param_buf[2] = s_Failed_to_malloc_ipgroups_buf_00047fb8[2];
      param_buf[3] = s_Failed_to_malloc_ipgroups_buf_00047fb8[3];
      param_buf[4] = s_Failed_to_malloc_ipgroups_buf_00047fb8[4];
      param_buf[5] = s_Failed_to_malloc_ipgroups_buf_00047fb8[5];
      param_buf[6] = s_Failed_to_malloc_ipgroups_buf_00047fb8[6];
      param_buf[7] = s_Failed_to_malloc_ipgroups_buf_00047fb8[7];
      param_buf[8] = s_Failed_to_malloc_ipgroups_buf_00047fb8[8];
      param_buf[9] = s_Failed_to_malloc_ipgroups_buf_00047fb8[9];
      param_buf[10] = s_Failed_to_malloc_ipgroups_buf_00047fb8[10];
      param_buf[11] = s_Failed_to_malloc_ipgroups_buf_00047fb8[11];
      param_buf[12] = s_Failed_to_malloc_ipgroups_buf_00047fb8[12];
      param_buf[13] = s_Failed_to_malloc_ipgroups_buf_00047fb8[13];
      param_buf[14] = s_Failed_to_malloc_ipgroups_buf_00047fb8[14];
      param_buf[15] = s_Failed_to_malloc_ipgroups_buf_00047fb8[15];
      param_buf[16] = s_Failed_to_malloc_ipgroups_buf_00047fb8[16];
      param_buf[17] = s_Failed_to_malloc_ipgroups_buf_00047fb8[17];
      param_buf[18] = s_Failed_to_malloc_ipgroups_buf_00047fb8[18];
      param_buf[19] = s_Failed_to_malloc_ipgroups_buf_00047fb8[19];
      param_buf[20] = s_Failed_to_malloc_ipgroups_buf_00047fb8[20];
      param_buf[21] = s_Failed_to_malloc_ipgroups_buf_00047fb8[21];
      param_buf[22] = s_Failed_to_malloc_ipgroups_buf_00047fb8[22];
      param_buf[23] = s_Failed_to_malloc_ipgroups_buf_00047fb8[23];
      param_buf[24] = s_Failed_to_malloc_ipgroups_buf_00047fb8[24];
      param_buf[25] = s_Failed_to_malloc_ipgroups_buf_00047fb8[25];
      param_buf[26] = s_Failed_to_malloc_ipgroups_buf_00047fb8[26];
      param_buf[27] = s_Failed_to_malloc_ipgroups_buf_00047fb8[27];
      param_buf._28_2_ = (undefined2)ram0x00047fd4;
      _applog(3,param_buf,true);
      _quit(1);
      strcpy((char *)0x0,api_groups);
      local_4bec = __ctype_toupper_loc();
    }
    else {
      memcpy(pcVar5,api_groups,sVar8);
      if (*pcVar5 == '\0') {
        local_4bec = __ctype_toupper_loc();
      }
      else {
        local_4bec = __ctype_toupper_loc();
        ptr = pcVar5;
        do {
          pcVar9 = strchr(ptr,0x2c);
          local_4bf8 = pcVar9;
          if (pcVar9 != (char *)0x0) {
            local_4bf8 = pcVar9 + 1;
            *pcVar9 = '\0';
          }
          if (ptr[1] != ':') {
            pcVar9 = strchr(ptr,0x3a);
            if (pcVar9 != (char *)0x0) {
              *pcVar9 = '\0';
            }
            snprintf(buf,0x800,"API invalid group name \'%s\'",ptr);
            _applog(3,buf,true);
            _quit(1);
          }
          p_Var23 = *local_4bec;
          uVar41 = (uint)*(byte *)(p_Var23 + (byte)*ptr);
          if ((p_Var23[uVar41] < p_Var23[0x41]) || (p_Var23[0x5a] < p_Var23[uVar41])) {
            snprintf(buf,0x800,"API invalid group name \'%c\'");
            _applog(3,buf,true);
            _quit(1);
            p_Var23 = *local_4bec;
          }
          if (uVar41 == p_Var23[0x57]) {
            snprintf(buf,0x800,"API group name can\'t be \'%c\'",uVar41);
            _applog(3,buf,true);
            _quit(1);
            p_Var23 = *local_4bec;
          }
          if (uVar41 == p_Var23[0x52]) {
            snprintf(buf,0x800,"API group name can\'t be \'%c\'",uVar41);
            _applog(3,buf,true);
            _quit(1);
            p_Var23 = *local_4bec;
          }
          if (apigroups[p_Var23[uVar41] - p_Var23[0x41]].commands != (char *)0x0) {
            snprintf(buf,0x800,"API duplicate group name \'%c\'",(uint)(byte)*ptr);
            _applog(3,buf,true);
            _quit(1);
          }
          bVar1 = false;
          param_buf[0] = '|';
          param_buf[1] = '\0';
          if ((ptr + 2 != (char *)0x0) && (ptr[2] != '\0')) {
            local_4be8 = param_buf + 1;
            pcVar9 = ptr + 2;
            do {
              pcVar10 = strchr(pcVar9,0x3a);
              pcVar39 = pcVar10;
              if (pcVar10 != (char *)0x0) {
                pcVar39 = pcVar10 + 1;
                *pcVar10 = '\0';
              }
              if ((*pcVar9 == '*') && (pcVar9[1] == '\0')) {
                bVar1 = true;
              }
              else {
                if (cmds[0].name != (char *)0x0) {
                  pCVar32 = cmds;
                  iVar7 = 0;
                  pcVar10 = cmds[0].name;
                  do {
                    iVar34 = strcasecmp(pcVar9,pcVar10);
                    if (iVar34 == 0) {
                      sprintf(cmdbuf_1,"|%s|",pcVar10);
                      pcVar9 = strstr(param_buf,cmdbuf_1);
                      if (pcVar9 == (char *)0x0) {
                        pcVar9 = cmds[iVar7].name;
                        strcpy(local_4be8,pcVar9);
                        sVar8 = strlen(pcVar9);
                        local_4be8[sVar8] = '|';
                        local_4be8[sVar8 + 1] = '\0';
                        local_4be8 = local_4be8 + sVar8 + 1;
                      }
                      goto joined_r0x0001c61a;
                    }
                    pCVar32 = pCVar32 + 1;
                    pcVar10 = pCVar32->name;
                    iVar7 = iVar7 + 1;
                  } while (pcVar10 != (char *)0x0);
                }
                snprintf(buf,0x800,"API unknown command \'%s\' in group \'%c\'",pcVar9,uVar41);
                _applog(3,buf,true);
                _quit(1);
              }
joined_r0x0001c61a:
            } while ((pcVar39 != (char *)0x0) && (pcVar9 = pcVar39, *pcVar39 != '\0'));
            if ((bVar1) && (cmds[0].name != (char *)0x0)) {
              p_Var37 = &cmds[0].iswritemode;
              do {
                while (*p_Var37 != false) {
LAB_0001c64c:
                  piVar21 = (int *)(p_Var37 + 4);
                  p_Var37 = p_Var37 + 0xc;
                  if (*piVar21 == 0) goto LAB_0001c69e;
                }
                sprintf(cmdbuf_1,"|%s|");
                pcVar9 = strstr(param_buf,cmdbuf_1);
                if (pcVar9 != (char *)0x0) goto LAB_0001c64c;
                pcVar9 = ((CMDS *)(p_Var37 + -8))->name;
                strcpy(local_4be8,pcVar9);
                sVar8 = strlen(pcVar9);
                local_4be8[sVar8] = '|';
                local_4be8[sVar8 + 1] = '\0';
                local_4be8 = local_4be8 + sVar8 + 1;
                piVar21 = (int *)(p_Var37 + 4);
                p_Var37 = p_Var37 + 0xc;
              } while (*piVar21 != 0);
            }
          }
LAB_0001c69e:
          iVar34 = (*local_4bec)[uVar41];
          iVar7 = (*local_4bec)[0x41];
          sVar8 = strlen(param_buf);
          pcVar9 = (char *)malloc(sVar8 + 1);
          apigroups[iVar34 - iVar7].commands = pcVar9;
          if (pcVar9 == (char *)0x0) {
            buf[0] = s_Failed_to_malloc_group_commands_b_00048050[0];
            buf[1] = s_Failed_to_malloc_group_commands_b_00048050[1];
            buf[2] = s_Failed_to_malloc_group_commands_b_00048050[2];
            buf[3] = s_Failed_to_malloc_group_commands_b_00048050[3];
            buf[4] = s_Failed_to_malloc_group_commands_b_00048050[4];
            buf[5] = s_Failed_to_malloc_group_commands_b_00048050[5];
            buf[6] = s_Failed_to_malloc_group_commands_b_00048050[6];
            buf[7] = s_Failed_to_malloc_group_commands_b_00048050[7];
            buf[8] = s_Failed_to_malloc_group_commands_b_00048050[8];
            buf[9] = s_Failed_to_malloc_group_commands_b_00048050[9];
            buf[10] = s_Failed_to_malloc_group_commands_b_00048050[10];
            buf[11] = s_Failed_to_malloc_group_commands_b_00048050[11];
            buf[12] = s_Failed_to_malloc_group_commands_b_00048050[12];
            buf[13] = s_Failed_to_malloc_group_commands_b_00048050[13];
            buf[14] = s_Failed_to_malloc_group_commands_b_00048050[14];
            buf[15] = s_Failed_to_malloc_group_commands_b_00048050[15];
            buf[16] = s_Failed_to_malloc_group_commands_b_00048050[16];
            buf[17] = s_Failed_to_malloc_group_commands_b_00048050[17];
            buf[18] = s_Failed_to_malloc_group_commands_b_00048050[18];
            buf[19] = s_Failed_to_malloc_group_commands_b_00048050[19];
            buf[20] = s_Failed_to_malloc_group_commands_b_00048050[20];
            buf[21] = s_Failed_to_malloc_group_commands_b_00048050[21];
            buf[22] = s_Failed_to_malloc_group_commands_b_00048050[22];
            buf[23] = s_Failed_to_malloc_group_commands_b_00048050[23];
            buf[24] = s_Failed_to_malloc_group_commands_b_00048050[24];
            buf[25] = s_Failed_to_malloc_group_commands_b_00048050[25];
            buf[26] = s_Failed_to_malloc_group_commands_b_00048050[26];
            buf[27] = s_Failed_to_malloc_group_commands_b_00048050[27];
            buf[28] = s_Failed_to_malloc_group_commands_b_00048050[28];
            buf[29] = s_Failed_to_malloc_group_commands_b_00048050[29];
            buf[30] = s_Failed_to_malloc_group_commands_b_00048050[30];
            buf[31] = s_Failed_to_malloc_group_commands_b_00048050[31];
            buf[32] = s_Failed_to_malloc_group_commands_b_00048050[32];
            buf[33] = s_Failed_to_malloc_group_commands_b_00048050[33];
            buf[34] = s_Failed_to_malloc_group_commands_b_00048050[34];
            buf[35] = s_Failed_to_malloc_group_commands_b_00048050[35];
            _applog(3,buf,true);
            _quit(1);
          }
          strcpy(pcVar9,param_buf);
        } while ((local_4bf8 != (char *)0x0) && (ptr = local_4bf8, *local_4bf8 != '\0'));
      }
    }
    param_buf._1_3_ = SUB43(param_buf._0_4_,1) & 0xffff00;
    param_buf[0] = '|';
    pCVar32 = cmds;
    pcVar9 = param_buf + 1;
    pcVar39 = cmds[0].name;
    while (pcVar39 != (char *)0x0) {
      while (pCVar32->iswritemode != false) {
        pCVar32 = pCVar32 + 1;
        pcVar39 = pCVar32->name;
        if (pcVar39 == (char *)0x0) goto LAB_0001c7f4;
      }
      strcpy(pcVar9,pcVar39);
      sVar8 = strlen(pcVar39);
      pcVar9[sVar8] = '|';
      pcVar9[sVar8 + 1] = '\0';
      pcVar9 = pcVar9 + sVar8 + 1;
      pCVar32 = pCVar32 + 1;
      pcVar39 = pCVar32->name;
    }
LAB_0001c7f4:
    p_Var23 = *local_4bec;
    iVar7 = p_Var23[0x52];
    if (iVar7 + 0x80U < 0x180) {
      iVar7 = p_Var23[iVar7];
    }
    iVar34 = p_Var23[0x41];
    sVar8 = strlen(param_buf);
    pcVar9 = (char *)malloc(sVar8 + 1);
    apigroups[iVar7 - iVar34].commands = pcVar9;
    if (pcVar9 == (char *)0x0) {
      buf[0] = s_Failed_to_malloc_noprivgroup_com_00048074[0];
      buf[1] = s_Failed_to_malloc_noprivgroup_com_00048074[1];
      buf[2] = s_Failed_to_malloc_noprivgroup_com_00048074[2];
      buf[3] = s_Failed_to_malloc_noprivgroup_com_00048074[3];
      buf[4] = s_Failed_to_malloc_noprivgroup_com_00048074[4];
      buf[5] = s_Failed_to_malloc_noprivgroup_com_00048074[5];
      buf[6] = s_Failed_to_malloc_noprivgroup_com_00048074[6];
      buf[7] = s_Failed_to_malloc_noprivgroup_com_00048074[7];
      buf[8] = s_Failed_to_malloc_noprivgroup_com_00048074[8];
      buf[9] = s_Failed_to_malloc_noprivgroup_com_00048074[9];
      buf[10] = s_Failed_to_malloc_noprivgroup_com_00048074[10];
      buf[11] = s_Failed_to_malloc_noprivgroup_com_00048074[11];
      buf[12] = s_Failed_to_malloc_noprivgroup_com_00048074[12];
      buf[13] = s_Failed_to_malloc_noprivgroup_com_00048074[13];
      buf[14] = s_Failed_to_malloc_noprivgroup_com_00048074[14];
      buf[15] = s_Failed_to_malloc_noprivgroup_com_00048074[15];
      buf[16] = s_Failed_to_malloc_noprivgroup_com_00048074[16];
      buf[17] = s_Failed_to_malloc_noprivgroup_com_00048074[17];
      buf[18] = s_Failed_to_malloc_noprivgroup_com_00048074[18];
      buf[19] = s_Failed_to_malloc_noprivgroup_com_00048074[19];
      buf[20] = s_Failed_to_malloc_noprivgroup_com_00048074[20];
      buf[21] = s_Failed_to_malloc_noprivgroup_com_00048074[21];
      buf[22] = s_Failed_to_malloc_noprivgroup_com_00048074[22];
      buf[23] = s_Failed_to_malloc_noprivgroup_com_00048074[23];
      buf[24] = s_Failed_to_malloc_noprivgroup_com_00048074[24];
      buf[25] = s_Failed_to_malloc_noprivgroup_com_00048074[25];
      buf[26] = s_Failed_to_malloc_noprivgroup_com_00048074[26];
      buf[27] = s_Failed_to_malloc_noprivgroup_com_00048074[27];
      buf[28] = s_Failed_to_malloc_noprivgroup_com_00048074[28];
      buf[29] = s_Failed_to_malloc_noprivgroup_com_00048074[29];
      buf[30] = s_Failed_to_malloc_noprivgroup_com_00048074[30];
      buf[31] = s_Failed_to_malloc_noprivgroup_com_00048074[31];
      buf[32] = s_Failed_to_malloc_noprivgroup_com_00048074[32];
      buf[33] = s_Failed_to_malloc_noprivgroup_com_00048074[33];
      buf[34] = s_Failed_to_malloc_noprivgroup_com_00048074[34];
      buf[35] = s_Failed_to_malloc_noprivgroup_com_00048074[35];
      buf[36] = s_Failed_to_malloc_noprivgroup_com_00048074[36];
      buf[37] = s_Failed_to_malloc_noprivgroup_com_00048074[37];
      buf[38] = s_Failed_to_malloc_noprivgroup_com_00048074[38];
      buf[39] = s_Failed_to_malloc_noprivgroup_com_00048074[39];
      buf._40_2_ = (undefined2)ram0x0004809c;
      _applog(3,buf,true);
      _quit(1);
    }
    strcpy(pcVar9,param_buf);
    free(pcVar5);
    pcVar5 = opt_api_allow;
    if (opt_api_allow != (char *)0x0) {
      sVar8 = strlen(opt_api_allow);
      __dest = (byte *)malloc(sVar8 + 1);
      if (__dest == (byte *)0x0) {
        param_buf[0] = s_Failed_to_malloc_ipaccess_buf_000480a0[0];
        param_buf[1] = s_Failed_to_malloc_ipaccess_buf_000480a0[1];
        param_buf[2] = s_Failed_to_malloc_ipaccess_buf_000480a0[2];
        param_buf[3] = s_Failed_to_malloc_ipaccess_buf_000480a0[3];
        param_buf[4] = s_Failed_to_malloc_ipaccess_buf_000480a0[4];
        param_buf[5] = s_Failed_to_malloc_ipaccess_buf_000480a0[5];
        param_buf[6] = s_Failed_to_malloc_ipaccess_buf_000480a0[6];
        param_buf[7] = s_Failed_to_malloc_ipaccess_buf_000480a0[7];
        param_buf[8] = s_Failed_to_malloc_ipaccess_buf_000480a0[8];
        param_buf[9] = s_Failed_to_malloc_ipaccess_buf_000480a0[9];
        param_buf[10] = s_Failed_to_malloc_ipaccess_buf_000480a0[10];
        param_buf[11] = s_Failed_to_malloc_ipaccess_buf_000480a0[11];
        param_buf[12] = s_Failed_to_malloc_ipaccess_buf_000480a0[12];
        param_buf[13] = s_Failed_to_malloc_ipaccess_buf_000480a0[13];
        param_buf[14] = s_Failed_to_malloc_ipaccess_buf_000480a0[14];
        param_buf[15] = s_Failed_to_malloc_ipaccess_buf_000480a0[15];
        param_buf[16] = s_Failed_to_malloc_ipaccess_buf_000480a0[16];
        param_buf[17] = s_Failed_to_malloc_ipaccess_buf_000480a0[17];
        param_buf[18] = s_Failed_to_malloc_ipaccess_buf_000480a0[18];
        param_buf[19] = s_Failed_to_malloc_ipaccess_buf_000480a0[19];
        param_buf[20] = s_Failed_to_malloc_ipaccess_buf_000480a0[20];
        param_buf[21] = s_Failed_to_malloc_ipaccess_buf_000480a0[21];
        param_buf[22] = s_Failed_to_malloc_ipaccess_buf_000480a0[22];
        param_buf[23] = s_Failed_to_malloc_ipaccess_buf_000480a0[23];
        param_buf[24] = s_Failed_to_malloc_ipaccess_buf_000480a0[24];
        param_buf[25] = s_Failed_to_malloc_ipaccess_buf_000480a0[25];
        param_buf[26] = s_Failed_to_malloc_ipaccess_buf_000480a0[26];
        param_buf[27] = s_Failed_to_malloc_ipaccess_buf_000480a0[27];
        param_buf._28_2_ = (undefined2)ram0x000480bc;
        _applog(3,param_buf,true);
        _quit(1);
        pcVar5 = opt_api_allow;
      }
      strcpy((char *)__dest,pcVar5);
      pbVar24 = __dest + -1;
      sVar8 = 1;
      while( true ) {
        pbVar24 = pbVar24 + 1;
        if (*pbVar24 == 0) break;
        if (*pbVar24 == 0x2c) {
          sVar8 = sVar8 + 1;
        }
      }
      ipaccess = (IPACCESS *)calloc(sVar8,0x24);
      if (ipaccess == (IPACCESS *)0x0) {
        param_buf[0] = s_Failed_to_calloc_ipaccess_000480c0[0];
        param_buf[1] = s_Failed_to_calloc_ipaccess_000480c0[1];
        param_buf[2] = s_Failed_to_calloc_ipaccess_000480c0[2];
        param_buf[3] = s_Failed_to_calloc_ipaccess_000480c0[3];
        param_buf[4] = s_Failed_to_calloc_ipaccess_000480c0[4];
        param_buf[5] = s_Failed_to_calloc_ipaccess_000480c0[5];
        param_buf[6] = s_Failed_to_calloc_ipaccess_000480c0[6];
        param_buf[7] = s_Failed_to_calloc_ipaccess_000480c0[7];
        param_buf[8] = s_Failed_to_calloc_ipaccess_000480c0[8];
        param_buf[9] = s_Failed_to_calloc_ipaccess_000480c0[9];
        param_buf[10] = s_Failed_to_calloc_ipaccess_000480c0[10];
        param_buf[11] = s_Failed_to_calloc_ipaccess_000480c0[11];
        param_buf[12] = s_Failed_to_calloc_ipaccess_000480c0[12];
        param_buf[13] = s_Failed_to_calloc_ipaccess_000480c0[13];
        param_buf[14] = s_Failed_to_calloc_ipaccess_000480c0[14];
        param_buf[15] = s_Failed_to_calloc_ipaccess_000480c0[15];
        param_buf[16] = s_Failed_to_calloc_ipaccess_000480c0[16];
        param_buf[17] = s_Failed_to_calloc_ipaccess_000480c0[17];
        param_buf[18] = s_Failed_to_calloc_ipaccess_000480c0[18];
        param_buf[19] = s_Failed_to_calloc_ipaccess_000480c0[19];
        param_buf[20] = s_Failed_to_calloc_ipaccess_000480c0[20];
        param_buf[21] = s_Failed_to_calloc_ipaccess_000480c0[21];
        param_buf[22] = s_Failed_to_calloc_ipaccess_000480c0[22];
        param_buf[23] = s_Failed_to_calloc_ipaccess_000480c0[23];
        param_buf[24] = (char)(short)ram0x000480d8;
        param_buf[25] = (char)((ushort)(short)ram0x000480d8 >> 8);
        _applog(3,param_buf,true);
        _quit(1);
      }
      iVar7 = 0;
      ips = 0;
      if ((__dest == (byte *)0x0) || (bVar26 = *__dest, pbVar24 = __dest, bVar26 == 0)) {
        free(__dest);
      }
      else {
        do {
          if (bVar26 == 0x20 || bVar26 == 9) {
            do {
              pbVar24 = pbVar24 + 1;
              bVar26 = *pbVar24;
            } while (bVar26 == 0x20 || bVar26 == 9);
          }
          if (bVar26 == 0x2c) {
            pbVar38 = pbVar24 + 1;
          }
          else {
            pbVar11 = (byte *)strchr((char *)pbVar24,0x2c);
            pbVar38 = pbVar11;
            if (pbVar11 != (byte *)0x0) {
              pbVar38 = pbVar11 + 1;
              *pbVar11 = 0;
            }
            ppuVar12 = __ctype_b_loc();
            p_Var23 = *local_4bec;
            cVar22 = *(char *)(p_Var23 + 0x52);
            if (((int)((uint)(*ppuVar12)[*pbVar24] << 0x15) < 0) && (pbVar24[1] == 0x3a)) {
              iVar34 = p_Var23[*pbVar24];
              if ((iVar34 == p_Var23[0x57]) ||
                 (apigroups[iVar34 - p_Var23[0x41]].commands != (char *)0x0)) {
                cVar22 = (char)iVar34;
              }
              pbVar24 = pbVar24 + 2;
            }
            __buf = ipaccess + iVar7;
            __buf->group = cVar22;
            bVar26 = *pbVar24;
            if ((((bVar26 == 0x30) && (pbVar24[1] == 0x2f)) && (pbVar24[2] == 0x30)) &&
               (pbVar24[3] == 0)) {
              iVar34 = 0;
              puVar35 = &__buf[-1].field_0x23;
              do {
                iVar34 = iVar34 + 1;
                puVar35[1] = 0;
                puVar35[0x11] = 0;
                puVar35 = puVar35 + 1;
              } while (iVar34 != 0x10);
              iVar7 = iVar7 + 1;
              ips = iVar7;
            }
            else {
              slash = strchr((char *)pbVar24,0x2f);
              if (slash == (char *)0x0) {
                iVar34 = 0;
                do {
                  iVar30 = iVar34 + 1;
                  (__buf->mask).__in6_u.__u6_addr8[iVar34] = 0xff;
                  iVar34 = iVar30;
                } while (iVar30 != 0x10);
                sVar8 = strlen((char *)pbVar24);
                bVar26 = *pbVar24;
                slash = (char *)(pbVar24 + sVar8);
              }
              if ((bVar26 == 0x5b) && (slash[-1] == ']')) {
                bVar1 = true;
                pbVar11 = pbVar24 + 1;
                *pbVar24 = 0;
                slash[-1] = '\0';
              }
              else {
                bVar1 = false;
                pbVar11 = pbVar24;
              }
              if (*slash == '\0') {
LAB_0001ca6e:
                iVar34 = 0;
                do {
                  (__buf->ip).__in6_u.__u6_addr8[iVar34] = '\0';
                  iVar34 = iVar34 + 1;
                } while (iVar34 != 0x10);
                if (bVar1) {
                  iVar34 = inet_pton(10,(char *)pbVar11,__buf);
                }
                else {
                  sprintf(param_buf,"::ffff:%s",pbVar11);
                  iVar7 = ips;
                  __buf = ipaccess + ips;
                  iVar34 = inet_pton(10,param_buf,__buf);
                }
                if (iVar34 == 1) {
                  iVar34 = 0;
                  do {
                    iVar34 = iVar34 + 1;
                    (__buf->ip).__in6_u.__u6_addr8[0] =
                         (__buf->ip).__in6_u.__u6_addr8[0] & (__buf->mask).__in6_u.__u6_addr8[0];
                    __buf = (IPACCESS *)((__buf->ip).__in6_u.__u6_addr8 + 1);
                  } while (iVar34 != 0x10);
                  iVar7 = iVar7 + 1;
                  ips = iVar7;
                }
              }
              else {
                *slash = '\0';
                lVar14 = strtol(slash + 1,(char **)0x0,10);
                if (0 < lVar14) {
                  if (bVar1) {
                    iVar34 = 0;
                  }
                  else {
                    iVar34 = 0x60;
                  }
                  iVar34 = lVar14 + iVar34;
                  if (iVar34 < 0x81) {
                    iVar15 = 0;
                    iVar30 = 0;
                    do {
                      iVar29 = iVar30 + 1;
                      (__buf->mask).__in6_u.__u6_addr8[iVar30] = '\0';
                      iVar30 = iVar29;
                    } while (iVar29 != 0x10);
                    uVar41 = 7;
                    for (; 0 < iVar34; iVar34 = iVar34 + -1) {
                      (__buf->mask).__in6_u.__u6_addr8[iVar15] =
                           (byte)(1 << (uVar41 & 0xff)) | (__buf->mask).__in6_u.__u6_addr8[iVar15];
                      if (uVar41 == 0) {
                        iVar15 = iVar15 + 1;
                        uVar41 = 7;
                      }
                      else {
                        uVar41 = uVar41 - 1;
                      }
                    }
                    goto LAB_0001ca6e;
                  }
                }
              }
            }
          }
        } while ((pbVar38 != (byte *)0x0) && (bVar26 = *pbVar38, pbVar24 = pbVar38, bVar26 != 0));
        free(__dest);
        if (iVar7 != 0) goto LAB_0001c98a;
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(param_buf,0x800,"API not running (no valid IPs specified)%s",
                 " - API will not be available");
        _applog(4,param_buf,false);
      }
      goto LAB_0001c364;
    }
LAB_0001c98a:
    unaff_r6 = (int)(short)iVar13;
    cgsleep_ms(opt_log_interval * 1000);
    sprintf(port_s,"%d",unaff_r6);
    hints.ai_flags = 1;
    hints.ai_family = 0;
    hints.ai_socktype = 0;
    hints.ai_protocol = 0;
    hints.ai_addrlen = 0;
    hints.ai_addr = (sockaddr *)0x0;
    hints.ai_canonname = (char *)0x0;
    hints.ai_next = (addrinfo *)0x0;
    iVar13 = getaddrinfo(opt_api_host,port_s,(addrinfo *)&hints,(addrinfo **)&res);
    if (iVar13 == 0) {
      paVar33 = res;
      if (res == (addrinfo *)0x0) {
        iVar13 = *arg;
      }
      else {
        do {
          iVar13 = socket(res->ai_family,1,0);
          *arg = iVar13;
          if (0 < iVar13) goto LAB_0001cc48;
          paVar33 = paVar33->ai_next;
        } while (paVar33 != (addrinfo *)0x0);
      }
      if (iVar13 == -1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          piVar21 = __errno_location();
          pcVar5 = strerror(*piVar21);
          snprintf(param_buf,0x800,"API initialisation failed (%s)%s",pcVar5,
                   " - API will not be available");
          _applog(3,param_buf,false);
        }
        freeaddrinfo((addrinfo *)res);
        free(arg);
        return;
      }
      paVar33 = (addrinfo *)0x0;
LAB_0001cc48:
      optval = 1;
      iVar13 = setsockopt(iVar13,1,2,&optval,4);
      if (((iVar13 < 0) && (opt_debug != false)) &&
         ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
        piVar21 = __errno_location();
        pcVar5 = strerror(*piVar21);
        snprintf(param_buf,0x800,"API setsockopt SO_REUSEADDR failed (ignored): %s",pcVar5);
        _applog(7,param_buf,false);
      }
      tVar16 = time((time_t *)0x0);
      while (iVar13 = bind(*arg,(sockaddr *)paVar33->ai_addr,paVar33->ai_addrlen), iVar13 < 0) {
        piVar21 = __errno_location();
        binderror = strerror(*piVar21);
        tVar17 = time((time_t *)0x0);
        if (0x3d < tVar17 - tVar16) goto LAB_0001d50c;
        if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          snprintf(param_buf,0x800,"API bind to port %d failed - trying again in 30sec",unaff_r6);
          _applog(4,param_buf,false);
        }
        cgsleep_ms(30000);
      }
      freeaddrinfo((addrinfo *)res);
      iVar13 = listen(*arg,100);
      if (iVar13 < 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          piVar21 = __errno_location();
          pcVar5 = strerror(*piVar21);
          snprintf(param_buf,0x800,"API3 initialisation failed (%s)%s",pcVar5,
                   " - API will not be available");
          _applog(3,param_buf,false);
        }
        close(*arg);
        goto LAB_0001c364;
      }
      if (opt_api_allow == (char *)0x0) {
        if (opt_api_network == false) {
          if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
            iVar13 = *arg;
            pcVar5 = "API running in local read access mode on port %d (%d)";
            goto LAB_0001ccf2;
          }
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
          pcVar5 = "API running in UNRESTRICTED read access mode on port %d (%d)";
          iVar13 = *arg;
LAB_0001ccf2:
          snprintf(param_buf,0x800,pcVar5,unaff_r6,iVar13);
          _applog(4,param_buf,false);
        }
      }
      else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        pcVar5 = "API running in IP access mode on port %d (%d)";
        iVar13 = *arg;
        goto LAB_0001ccf2;
      }
      if (opt_api_mcast != false) {
        mcast_init();
      }
      strbufs = _k_new_list("StrBufs",0xc,2,0,false,"api.c",DAT_0001cfb8,0x1535);
      pjVar25 = (json_t *)(uint)bye;
      if (pjVar25 == (json_t *)0x0) {
        bVar1 = false;
        json = (json_t *)0x0;
        do {
          pjVar25 = (json_t *)&clisiz;
          clisiz = 0x80;
          iVar13 = accept(*arg,(sockaddr *)&cli,(socklen_t *)pjVar25);
          if (iVar13 < 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              piVar21 = __errno_location();
              pcVar5 = strerror(*piVar21);
              snprintf(cmdbuf_1,0x800,"API failed (%s)%s (%d)",pcVar5," - API will not be available"
                       ,*arg);
              pjVar25 = (json_t *)0x0;
              _applog(3,cmdbuf_1,false);
            }
            break;
          }
          pjVar25 = (json_t *)&group;
          _Var4 = check_connect(&cli,&connectaddr,(char *)pjVar25);
          if ((opt_debug != false) &&
             (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
            pcVar5 = "Accepted";
            if (!_Var4) {
              pcVar5 = "Ignored";
            }
            snprintf(cmdbuf_1,0x800,"API: connection from %s - %s",connectaddr,pcVar5);
            pjVar25 = (json_t *)0x0;
            _applog(7,cmdbuf_1,false);
          }
          if (_Var4) {
            sVar18 = recv(iVar13,buf,0x1fff,0);
            if ((int)sVar18 < 0) {
              buf._0_4_ = buf._0_4_ & 0xffffff00;
              pjVar25 = (json_t *)0x0;
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) ||
                  (pjVar25 = (json_t *)0x0, 6 < opt_log_level)))) {
                piVar21 = __errno_location();
                pcVar5 = strerror(*piVar21);
                snprintf(cmdbuf_1,0x800,"API: recv failed: %s",pcVar5);
                pjVar25 = (json_t *)0x0;
                _applog(7,cmdbuf_1,false);
              }
            }
            else {
              buf[sVar18] = '\0';
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(cmdbuf_1,0x800,"API: recv command: (%d) \'%s\'",sVar18,buf);
                _applog(7,cmdbuf_1,false);
              }
              pjVar36 = (json_t *)0x0;
              when = time((time_t *)0x0);
              io_data_00->cur = io_data_00->ptr;
              *io_data_00->ptr = '\0';
              io_data_00->close = false;
              if (buf[0] != '{') {
                pcVar5 = strchr(buf,0x7c);
                if (pcVar5 == (char *)0x0) {
                  __s = (json_t *)buf;
                  pjVar36 = (json_t *)0x0;
                  pjVar40 = (json_t *)0x0;
                }
                else {
                  __s = (json_t *)buf;
                  pjVar40 = (json_t *)(pcVar5 + 1);
                  *pcVar5 = '\0';
                }
                goto LAB_0001d0dc;
              }
              json = json_loadb(buf,sVar18,0,&json_err);
              if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
                iVar7 = 0x17;
LAB_0001d43a:
                message(io_data_00,iVar7,0,(char *)0x0,true);
                pjVar25 = (json_t *)0x1;
                send_result(io_data_00,iVar13,true);
                pjVar36 = json;
                if (json != (json_t *)0x0) {
                  pjVar36 = (json_t *)0x1;
                }
                pjVar40 = (json_t *)0x1;
                if (bVar1) {
LAB_0001d2a2:
                  pjVar25 = pjVar40;
                  send_result(io_data_00,iVar13,SUB41(pjVar25,0));
                }
              }
              else {
                pjVar25 = json_object_get(json,"command");
                if (pjVar25 == (json_t *)0x0) {
                  iVar7 = 0x18;
                  goto LAB_0001d43a;
                }
                if (pjVar25->type != JSON_STRING) {
                  iVar7 = 0xe;
                  goto LAB_0001d43a;
                }
                __s = (json_t *)json_string_value(pjVar25);
                pjVar40 = json_object_get(json,"parameter");
                if (pjVar40 == (json_t *)0x0) {
LAB_0001d856:
                  pjVar36 = (json_t *)0x1;
                }
                else {
                  jVar31 = pjVar40->type;
                  if (jVar31 == JSON_STRING) {
                    pjVar40 = (json_t *)json_string_value(pjVar40);
                    pjVar36 = (json_t *)0x1;
                  }
                  else if (jVar31 == JSON_INTEGER) {
                    jVar43 = json_integer_value(pjVar40);
                    pjVar40 = (json_t *)param_buf;
                    pjVar36 = (json_t *)0x1;
                    sprintf((char *)pjVar40,"%d",(int)jVar43);
                  }
                  else {
                    if (jVar31 != JSON_REAL) {
                      pjVar40 = (json_t *)0x0;
                      goto LAB_0001d856;
                    }
                    dVar42 = json_real_value(pjVar40);
                    pjVar40 = (json_t *)param_buf;
                    pjVar36 = (json_t *)0x1;
                    sprintf((char *)pjVar40,"%f",SUB84(dVar42,0),(int)((ulonglong)dVar42 >> 0x20));
                  }
                }
LAB_0001d0dc:
                pcVar5 = strchr((char *)__s,0x2b);
                if (pcVar5 == (char *)0x0) {
                  firstjoin = false;
                  bVar1 = false;
                  local_4bd4 = (undefined2 *)0x0;
                }
                else {
                  firstjoin = true;
                  sVar8 = strlen((char *)__s);
                  local_4bd4 = (undefined2 *)malloc(sVar8 + 3);
                  if (local_4bd4 == (undefined2 *)0x0) {
                    snprintf(cmdbuf_1,0x800,"OOM cmdsbuf in %s %s():%d","api.c",DAT_0001d3b4,0x15a4)
                    ;
                    _applog(3,cmdbuf_1,true);
                    _quit(1);
                  }
                  bVar1 = true;
                  pjVar40 = (json_t *)0x0;
                  *local_4bd4 = 0x7c;
                }
                pjVar25 = (json_t *)cmdbuf;
                __s_00 = __s;
                do {
                  if (bVar1) {
                    pjVar19 = (json_t *)strchr((char *)__s_00,0x2b);
                    __s = pjVar19;
                    if (pjVar19 != (json_t *)0x0) {
                      __s = (json_t *)((int)&pjVar19->type + 1);
                      *(undefined *)&pjVar19->type = 0;
                    }
                    pjVar19 = __s;
                    if (*(char *)&__s_00->type != '\0') goto LAB_0001d180;
                  }
                  else {
LAB_0001d180:
                    _Var4 = SUB41(pjVar36,0);
                    pjVar19 = __s;
                    if (cmds[0].name != (char *)0x0) {
                      pCVar32 = cmds;
                      iVar7 = 0;
                      pcVar5 = cmds[0].name;
                      do {
                        iVar34 = strcmp((char *)__s_00,pcVar5);
                        if (iVar34 == 0) {
                          pjVar25 = __s_00;
                          sprintf((char *)(json_t *)cmdbuf,"|%s|");
                          if (bVar1) {
                            pcVar5 = strstr((char *)local_4bd4,(char *)(json_t *)cmdbuf);
                            if (pcVar5 != (char *)0x0) goto LAB_0001d1c8;
                            sVar8 = strlen((char *)local_4bd4);
                            puVar20 = (undefined2 *)
                                      stpcpy((char *)((int)local_4bd4 + sVar8),(char *)__s_00);
                            *puVar20 = DAT_000472e4;
                            head_join(io_data_00,(char *)__s_00,_Var4,&firstjoin);
                            pjVar25 = (json_t *)(uint)cmds[iVar7].joinable;
                            if (pjVar25 == (json_t *)0x0) {
                              message(io_data_00,0x2d,0,cmds[iVar7].name,_Var4);
                              tail_join(io_data_00,_Var4);
                              goto LAB_0001d1c8;
                            }
                          }
                          cVar22 = group;
                          p_Var23 = *local_4bec;
                          if ((p_Var23[(byte)group] == p_Var23[0x57]) ||
                             (pjVar25 = (json_t *)
                                        strstr(apigroups[p_Var23[(byte)group] - p_Var23[0x41]].
                                               commands,(char *)(json_t *)cmdbuf),
                             pjVar25 != (json_t *)0x0)) {
                            pjVar25 = pjVar40;
                            (*cmds[iVar7].func)(io_data_00,iVar13,(char *)pjVar40,_Var4,cVar22);
                          }
                          else {
                            message(io_data_00,0x2d,0,cmds[iVar7].name,_Var4);
                            if ((opt_debug != false) &&
                               (((use_syslog != false || (opt_log_output != false)) ||
                                (6 < opt_log_level)))) {
                              snprintf(cmdbuf_1,0x800,
                                       "API: access denied to \'%s\' for \'%s\' command",connectaddr
                                       ,cmds[iVar7].name);
                              pjVar25 = (json_t *)0x0;
                              _applog(7,cmdbuf_1,false);
                            }
                          }
                          if (!bVar1) goto LAB_0001d228;
                          goto LAB_0001d28c;
                        }
                        pCVar32 = pCVar32 + 1;
                        pcVar5 = pCVar32->name;
                        iVar7 = iVar7 + 1;
                      } while (pcVar5 != (char *)0x0);
                    }
                    if (bVar1) {
                      head_join(io_data_00,(char *)__s_00,_Var4,&firstjoin);
                      pjVar25 = (json_t *)0x0;
                      message(io_data_00,0xe,0,(char *)0x0,_Var4);
LAB_0001d28c:
                      tail_join(io_data_00,_Var4);
                    }
                    else {
                      message(io_data_00,0xe,0,(char *)0x0,_Var4);
LAB_0001d228:
                      pjVar25 = pjVar36;
                      send_result(io_data_00,iVar13,_Var4);
                      pjVar19 = __s_00;
                    }
                  }
LAB_0001d1c8:
                  bVar27 = bVar1;
                  if (pjVar19 == (json_t *)0x0) {
                    bVar27 = false;
                  }
                  __s_00 = pjVar19;
                } while (bVar27);
                pjVar40 = pjVar36;
                if (bVar1) goto LAB_0001d2a2;
              }
              if ((pjVar36 != (json_t *)0x0) && (json->type == JSON_OBJECT)) {
                pjVar25 = (json_t *)(json->refcount + 1);
                if ((pjVar25 != (json_t *)0x0) &&
                   (sVar18 = json->refcount - 1, json->refcount = sVar18, sVar18 == 0)) {
                  json_delete(json);
                }
              }
            }
          }
          close(iVar13);
        } while (bye == false);
      }
      __pthread_unregister_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
      tidyup(arg);
      free(arg);
      pcVar5 = (char *)(uint)opt_debug;
      if (((char *)(uint)opt_debug != (char *)0x0) &&
         (((use_syslog != false || (opt_log_output != false)) ||
          (pcVar5 = (char *)opt_log_level, 6 < opt_log_level)))) {
        if (do_a_quit == false) {
          if (do_a_restart == false) {
            if (bye == false) {
              pcVar5 = "UNKNOWN!";
            }
            else {
              pcVar5 = "BYE";
            }
          }
          else {
            pcVar5 = "RESTART";
          }
        }
        else {
          pcVar5 = "QUIT";
        }
        snprintf(cmdbuf_1,0x800,"API: terminating due to: %s");
        pjVar25 = (json_t *)0x0;
        _applog(7,cmdbuf_1,false);
      }
      iVar13 = pthread_mutex_lock(DAT_0001cfbc);
      if (iVar13 != 0) {
        _mutex_lock(DAT_0001d8b0,(char *)0x1607,(char *)pjVar25,(int)pcVar5);
      }
      if (do_a_restart == false) {
        thr = (thr_info *)(uint)do_a_quit;
        if (thr == (thr_info *)0x0) goto LAB_0001ceaa;
        thr = &bye_thr;
        pjVar25 = (json_t *)(quit_thread + 1);
        iVar13 = thr_info_create(thr,(pthread_attr_t *)0x0,quit_thread + 1,thr);
        if (iVar13 != 0) {
          _mutex_unlock(&quit_restart_lock,DAT_0001d8b0->__size,(char *)0x1616,(int)thr);
          cmdbuf_1[0] = s_API_failed_to_initiate_a_clean_q_000483a8[0];
          cmdbuf_1[1] = s_API_failed_to_initiate_a_clean_q_000483a8[1];
          cmdbuf_1[2] = s_API_failed_to_initiate_a_clean_q_000483a8[2];
          cmdbuf_1[3] = s_API_failed_to_initiate_a_clean_q_000483a8[3];
          cmdbuf_1[4] = s_API_failed_to_initiate_a_clean_q_000483a8[4];
          cmdbuf_1[5] = s_API_failed_to_initiate_a_clean_q_000483a8[5];
          cmdbuf_1[6] = s_API_failed_to_initiate_a_clean_q_000483a8[6];
          cmdbuf_1[7] = s_API_failed_to_initiate_a_clean_q_000483a8[7];
          cmdbuf_1[8] = s_API_failed_to_initiate_a_clean_q_000483a8[8];
          cmdbuf_1[9] = s_API_failed_to_initiate_a_clean_q_000483a8[9];
          cmdbuf_1[10] = s_API_failed_to_initiate_a_clean_q_000483a8[10];
          cmdbuf_1[11] = s_API_failed_to_initiate_a_clean_q_000483a8[11];
          cmdbuf_1[12] = s_API_failed_to_initiate_a_clean_q_000483a8[12];
          cmdbuf_1[13] = s_API_failed_to_initiate_a_clean_q_000483a8[13];
          cmdbuf_1[14] = s_API_failed_to_initiate_a_clean_q_000483a8[14];
          cmdbuf_1[15] = s_API_failed_to_initiate_a_clean_q_000483a8[15];
          cmdbuf_1[16] = s_API_failed_to_initiate_a_clean_q_000483a8[16];
          cmdbuf_1[17] = s_API_failed_to_initiate_a_clean_q_000483a8[17];
          cmdbuf_1[18] = s_API_failed_to_initiate_a_clean_q_000483a8[18];
          cmdbuf_1[19] = s_API_failed_to_initiate_a_clean_q_000483a8[19];
          cmdbuf_1[20] = s_API_failed_to_initiate_a_clean_q_000483a8[20];
          cmdbuf_1[21] = s_API_failed_to_initiate_a_clean_q_000483a8[21];
          cmdbuf_1[22] = s_API_failed_to_initiate_a_clean_q_000483a8[22];
          cmdbuf_1[23] = s_API_failed_to_initiate_a_clean_q_000483a8[23];
          cmdbuf_1[24] = s_API_failed_to_initiate_a_clean_q_000483a8[24];
          cmdbuf_1[25] = s_API_failed_to_initiate_a_clean_q_000483a8[25];
          cmdbuf_1[26] = s_API_failed_to_initiate_a_clean_q_000483a8[26];
          cmdbuf_1[27] = s_API_failed_to_initiate_a_clean_q_000483a8[27];
          cmdbuf_1[28] = s_API_failed_to_initiate_a_clean_q_000483a8[28];
          cmdbuf_1[29] = s_API_failed_to_initiate_a_clean_q_000483a8[29];
          cmdbuf_1[30] = s_API_failed_to_initiate_a_clean_q_000483a8[30];
          cmdbuf_1[31] = s_API_failed_to_initiate_a_clean_q_000483a8[31];
          cmdbuf_1[32] = s_API_failed_to_initiate_a_clean_q_000483a8[32];
          cmdbuf_1[33] = s_API_failed_to_initiate_a_clean_q_000483a8[33];
          cmdbuf_1[34] = s_API_failed_to_initiate_a_clean_q_000483a8[34];
          cmdbuf_1[35] = s_API_failed_to_initiate_a_clean_q_000483a8[35];
          cmdbuf_1[36] = s_API_failed_to_initiate_a_clean_q_000483a8[36];
          cmdbuf_1[37] = s_API_failed_to_initiate_a_clean_q_000483a8[37];
          cmdbuf_1[38] = s_API_failed_to_initiate_a_clean_q_000483a8[38];
          cmdbuf_1[39] = s_API_failed_to_initiate_a_clean_q_000483a8[39];
          cmdbuf_1[40] = s_API_failed_to_initiate_a_clean_q_000483a8[40];
          cmdbuf_1[41] = s_API_failed_to_initiate_a_clean_q_000483a8[41];
          cmdbuf_1[42] = s_API_failed_to_initiate_a_clean_q_000483a8[42];
          cmdbuf_1[43] = s_API_failed_to_initiate_a_clean_q_000483a8[43];
          pjVar25 = (json_t *)0x1;
          cmdbuf_1._44_2_ = SUB42(ram0x000483d4,0);
          cmdbuf_1[46] = (char)((uint)ram0x000483d4 >> 0x10);
          thr = ram0x000483d4;
          _applog(3,cmdbuf_1,true);
          _quit(1);
        }
      }
      else {
        thr = &bye_thr;
        pjVar25 = (json_t *)(restart_thread + 1);
        iVar13 = thr_info_create(thr,(pthread_attr_t *)0x0,restart_thread + 1,thr);
        if (iVar13 != 0) {
          _mutex_unlock(&quit_restart_lock,DAT_0001d8b0->__size,(char *)0x160d,(int)thr);
          cmdbuf_1[0] = s_API_failed_to_initiate_a_restart_0004837c[0];
          cmdbuf_1[1] = s_API_failed_to_initiate_a_restart_0004837c[1];
          cmdbuf_1[2] = s_API_failed_to_initiate_a_restart_0004837c[2];
          cmdbuf_1[3] = s_API_failed_to_initiate_a_restart_0004837c[3];
          cmdbuf_1[4] = s_API_failed_to_initiate_a_restart_0004837c[4];
          cmdbuf_1[5] = s_API_failed_to_initiate_a_restart_0004837c[5];
          cmdbuf_1[6] = s_API_failed_to_initiate_a_restart_0004837c[6];
          cmdbuf_1[7] = s_API_failed_to_initiate_a_restart_0004837c[7];
          cmdbuf_1[8] = s_API_failed_to_initiate_a_restart_0004837c[8];
          cmdbuf_1[9] = s_API_failed_to_initiate_a_restart_0004837c[9];
          cmdbuf_1[10] = s_API_failed_to_initiate_a_restart_0004837c[10];
          cmdbuf_1[11] = s_API_failed_to_initiate_a_restart_0004837c[11];
          cmdbuf_1[12] = s_API_failed_to_initiate_a_restart_0004837c[12];
          cmdbuf_1[13] = s_API_failed_to_initiate_a_restart_0004837c[13];
          cmdbuf_1[14] = s_API_failed_to_initiate_a_restart_0004837c[14];
          cmdbuf_1[15] = s_API_failed_to_initiate_a_restart_0004837c[15];
          cmdbuf_1[16] = s_API_failed_to_initiate_a_restart_0004837c[16];
          cmdbuf_1[17] = s_API_failed_to_initiate_a_restart_0004837c[17];
          cmdbuf_1[18] = s_API_failed_to_initiate_a_restart_0004837c[18];
          cmdbuf_1[19] = s_API_failed_to_initiate_a_restart_0004837c[19];
          cmdbuf_1[20] = s_API_failed_to_initiate_a_restart_0004837c[20];
          cmdbuf_1[21] = s_API_failed_to_initiate_a_restart_0004837c[21];
          cmdbuf_1[22] = s_API_failed_to_initiate_a_restart_0004837c[22];
          cmdbuf_1[23] = s_API_failed_to_initiate_a_restart_0004837c[23];
          cmdbuf_1[24] = s_API_failed_to_initiate_a_restart_0004837c[24];
          cmdbuf_1[25] = s_API_failed_to_initiate_a_restart_0004837c[25];
          cmdbuf_1[26] = s_API_failed_to_initiate_a_restart_0004837c[26];
          cmdbuf_1[27] = s_API_failed_to_initiate_a_restart_0004837c[27];
          cmdbuf_1[28] = s_API_failed_to_initiate_a_restart_0004837c[28];
          cmdbuf_1[29] = s_API_failed_to_initiate_a_restart_0004837c[29];
          cmdbuf_1[30] = s_API_failed_to_initiate_a_restart_0004837c[30];
          cmdbuf_1[31] = s_API_failed_to_initiate_a_restart_0004837c[31];
          cmdbuf_1[32] = s_API_failed_to_initiate_a_restart_0004837c[32];
          cmdbuf_1[33] = s_API_failed_to_initiate_a_restart_0004837c[33];
          cmdbuf_1[34] = s_API_failed_to_initiate_a_restart_0004837c[34];
          cmdbuf_1[35] = s_API_failed_to_initiate_a_restart_0004837c[35];
          cmdbuf_1[36] = s_API_failed_to_initiate_a_restart_0004837c[36];
          cmdbuf_1[37] = s_API_failed_to_initiate_a_restart_0004837c[37];
          cmdbuf_1[38] = s_API_failed_to_initiate_a_restart_0004837c[38];
          cmdbuf_1[39] = s_API_failed_to_initiate_a_restart_0004837c[39];
          cmdbuf_1[40] = s_API_failed_to_initiate_a_restart_0004837c[40];
          cmdbuf_1[41] = s_API_failed_to_initiate_a_restart_0004837c[41];
          cmdbuf_1[42] = s_API_failed_to_initiate_a_restart_0004837c[42];
          cmdbuf_1[43] = s_API_failed_to_initiate_a_restart_0004837c[43];
          pjVar25 = (json_t *)0x1;
          thr = (thr_info *)s_API_failed_to_initiate_a_restart_0004837c._28_4_;
          _applog(3,cmdbuf_1,true);
          _quit(1);
        }
      }
      pthread_detach(bye_thr.pth);
LAB_0001ceaa:
      iVar13 = pthread_mutex_unlock(DAT_0001cfbc);
      if (iVar13 != 0) {
        _mutex_unlock_noyield(DAT_0001d8b0,(char *)0x161c,(char *)pjVar25,(int)thr);
      }
      (*selective_yield)();
      return;
    }
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_0001c364;
    snprintf(param_buf,0x800,"API failed to resolve %s",opt_api_host);
  }
  else {
    tidyup(arg);
    __pthread_unwind_next((__pthread_unwind_buf_t *)&__cancel_buf);
LAB_0001d50c:
    freeaddrinfo((addrinfo *)res);
    if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 3))
    goto LAB_0001c364;
    snprintf(param_buf,0x800,"API bind to port %d failed (%s)%s",unaff_r6,binderror,
             " - API will not be available");
  }
  _applog(3,param_buf,false);
LAB_0001c364:
  free(arg);
  return;
}

