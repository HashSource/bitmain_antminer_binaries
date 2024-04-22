
/* WARNING: Heritage AFTER dead removal. Example location: r0x00080b1c : 0x0001a7a6 */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void api(void)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char cVar4;
  int *__ptr;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  int iVar8;
  size_t sVar9;
  __int32_t **pp_Var10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  ushort **ppuVar14;
  byte *pbVar15;
  long lVar16;
  time_t tVar17;
  ssize_t sVar18;
  char *pcVar19;
  int iVar20;
  undefined2 *puVar21;
  time_t tVar22;
  int *piVar23;
  byte bVar24;
  __int32_t *p_Var25;
  bool bVar26;
  undefined4 uVar27;
  char *pcVar28;
  byte *pbVar29;
  undefined1 *puVar30;
  addrinfo *paVar31;
  int iVar32;
  int iVar33;
  char *pcVar34;
  byte *pbVar35;
  uint uVar36;
  char *pcVar37;
  __int32_t **unaff_r11;
  undefined8 uVar38;
  byte *pbStack_16488;
  char *pcStack_16480;
  int *piStack_16478;
  short sStack_16464;
  undefined2 *puStack_16460;
  byte *pbStack_1644c;
  byte bStack_16422;
  undefined uStack_16421;
  void *pvStack_16420;
  socklen_t sStack_1641c;
  addrinfo *paStack_16418;
  undefined4 uStack_16414;
  char acStack_16410 [12];
  char acStack_16404 [32];
  addrinfo aStack_163e4;
  undefined auStack_163c4 [12];
  pthread_t pStack_163b8;
  char acStack_16384 [100];
  char acStack_16320 [100];
  sockaddr asStack_162bc [8];
  undefined auStack_1623c [252];
  __pthread_unwind_buf_t a_Stack_16140 [6];
  char acStack_16028 [2048];
  char acStack_15828 [2048];
  char acStack_15028 [2048];
  char acStack_14828 [2048];
  char acStack_14028 [2048];
  char acStack_13828 [2048];
  char acStack_13028 [2048];
  char acStack_12828 [2048];
  char acStack_12028 [2048];
  char acStack_11828 [2048];
  char acStack_11028 [2048];
  char acStack_10828 [2048];
  char acStack_10028 [2048];
  char acStack_f828 [2048];
  char acStack_f028 [2048];
  char acStack_e828 [2048];
  char acStack_e028 [2048];
  char acStack_d828 [2048];
  undefined4 local_d028;
  undefined4 uStack_d024;
  undefined4 uStack_d020;
  undefined4 uStack_d01c;
  undefined4 local_d018;
  undefined4 uStack_d014;
  undefined4 uStack_d010;
  undefined4 uStack_d00c;
  undefined4 local_d008;
  undefined4 uStack_d004;
  undefined4 uStack_d000;
  undefined4 local_c828;
  undefined4 uStack_c824;
  undefined4 uStack_c820;
  undefined4 uStack_c81c;
  undefined4 local_c818;
  undefined4 uStack_c814;
  undefined4 uStack_c810;
  undefined4 uStack_c80c;
  undefined4 local_c808;
  undefined4 uStack_c804;
  undefined4 uStack_c800;
  undefined2 uStack_c7fc;
  undefined local_c7fa;
  char acStack_c028 [2048];
  undefined4 local_b828;
  undefined4 uStack_b824;
  undefined4 uStack_b820;
  undefined4 uStack_b81c;
  undefined4 local_b818;
  undefined4 uStack_b814;
  undefined4 uStack_b810;
  undefined2 local_b80c;
  char acStack_b028 [2048];
  char acStack_a828 [2048];
  char acStack_a028 [2048];
  char acStack_9828 [2048];
  char acStack_9028 [2048];
  char acStack_8828 [2048];
  undefined4 local_8028;
  undefined4 uStack_8024;
  undefined4 uStack_8020;
  undefined4 uStack_801c;
  undefined4 local_8018;
  undefined4 uStack_8014;
  undefined4 uStack_8010;
  undefined4 uStack_800c;
  undefined4 local_8008;
  undefined4 local_7828;
  undefined4 uStack_7824;
  undefined4 uStack_7820;
  undefined4 uStack_781c;
  undefined4 local_7818;
  undefined4 uStack_7814;
  undefined4 uStack_7810;
  undefined4 uStack_780c;
  undefined4 local_7808;
  undefined4 uStack_7804;
  undefined2 local_7800;
  undefined4 local_7028;
  undefined4 uStack_7024;
  undefined4 uStack_7020;
  undefined4 uStack_701c;
  undefined4 local_7018;
  undefined4 uStack_7014;
  undefined4 uStack_7010;
  undefined2 local_700c;
  undefined4 local_6828;
  undefined4 uStack_6824;
  undefined4 uStack_6820;
  undefined4 uStack_681c;
  undefined4 local_6818;
  undefined4 uStack_6814;
  undefined2 local_6810;
  char local_6028 [8192];
  char acStack_4028 [8192];
  char local_2028;
  char local_2027 [8195];
  
  uVar2 = opt_api_port;
  pvStack_16420 = (void *)0x0;
  piStack_16478 = (int *)0x0;
  bVar1 = false;
  __ptr = (int *)malloc(4);
  cVar4 = opt_api_listen;
  *__ptr = -1;
  if (cVar4 == '\0') {
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      snprintf(acStack_16028,0x800,"API not running%s"," - API will not be available");
      _applog(7,acStack_16028,0);
    }
    goto LAB_00019dcc;
  }
  puVar5 = (undefined4 *)malloc(0x10);
  puVar6 = (undefined *)malloc(0x10000);
  pcVar34 = (char *)0x0;
  puVar5[1] = puVar6;
  puVar5[2] = puVar6;
  *puVar6 = 0;
  *(undefined *)(puVar5 + 3) = 1;
  *(undefined *)((int)puVar5 + 0xd) = 0;
  *puVar5 = 0x10000;
  puVar7 = (undefined4 *)malloc(0xc);
  *puVar7 = puVar5;
  puVar3 = io_head;
  if (io_head == (undefined4 *)0x0) {
    puVar7[1] = puVar7;
    puVar7[2] = puVar7;
    io_head = puVar7;
  }
  else {
    uVar27 = io_head[1];
    puVar7[2] = io_head;
    puVar7[1] = uVar27;
    puVar3[1] = puVar7;
    *(undefined4 **)(puVar7[1] + 8) = puVar7;
  }
  iVar8 = pthread_mutex_init(DAT_0001a0a4,(pthread_mutexattr_t *)0x0);
  uVar27 = DAT_0001af20;
  if (iVar8 != 0) {
    piVar23 = __errno_location();
    snprintf(acStack_c028,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",*piVar23,
             "api.c",uVar27,0x1511);
    _applog(3,acStack_c028,1);
    _quit(1);
  }
  iVar8 = __sigsetjmp(a_Stack_16140,0);
  if (iVar8 == 0) {
    __pthread_register_cancel(a_Stack_16140);
    pcVar34 = opt_api_groups;
    if (opt_api_groups == (char *)0x0) {
      sVar9 = 1;
      pcVar34 = "";
    }
    else {
      sVar9 = strlen(opt_api_groups);
      sVar9 = sVar9 + 1;
    }
    pbStack_1644c = (byte *)malloc(sVar9);
    if (pbStack_1644c == (byte *)0x0) {
      local_b828._0_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[0];
      local_b828._1_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[1];
      local_b828._2_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[2];
      local_b828._3_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[3];
      uStack_b824._0_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[4];
      uStack_b824._1_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[5];
      uStack_b824._2_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[6];
      uStack_b824._3_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[7];
      uStack_b820._0_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[8];
      uStack_b820._1_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[9];
      uStack_b820._2_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[10];
      uStack_b820._3_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[11];
      uStack_b81c._0_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[12];
      uStack_b81c._1_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[13];
      uStack_b81c._2_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[14];
      uStack_b81c._3_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[15];
      local_b818._0_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[16];
      local_b818._1_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[17];
      local_b818._2_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[18];
      local_b818._3_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[19];
      uStack_b814._0_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[20];
      uStack_b814._1_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[21];
      uStack_b814._2_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[22];
      uStack_b814._3_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[23];
      uStack_b810._0_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[24];
      uStack_b810._1_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[25];
      uStack_b810._2_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[26];
      uStack_b810._3_1_ = s_Failed_to_malloc_ipgroups_buf_000587e4[27];
      local_b80c = (undefined2)ram0x00058800;
      _applog(3,&local_b828,1);
      _quit(1);
    }
    strcpy((char *)pbStack_1644c,pcVar34);
    bVar24 = *pbStack_1644c;
    pbVar12 = pbStack_1644c;
    while (bVar24 != 0) {
      pcVar34 = strchr((char *)pbVar12,0x2c);
      if (pcVar34 == (char *)0x0) {
        pbStack_16488 = (byte *)0x0;
      }
      else {
        pbStack_16488 = (byte *)(pcVar34 + 1);
        *pcVar34 = '\0';
      }
      if (pbVar12[1] != 0x3a) {
        pcVar34 = strchr((char *)pbVar12,0x3a);
        if (pcVar34 != (char *)0x0) {
          *pcVar34 = '\0';
        }
        snprintf(acStack_b028,0x800,"API invalid group name \'%s\'",pbVar12);
        _applog(3,acStack_b028,1);
        _quit(1);
      }
      pp_Var10 = __ctype_toupper_loc();
      p_Var25 = *pp_Var10;
      uVar36 = (uint)*(byte *)(p_Var25 + *pbVar12);
      if ((p_Var25[uVar36] < p_Var25[0x41]) || (p_Var25[0x5a] < p_Var25[uVar36])) {
        snprintf(acStack_a828,0x800,"API invalid group name \'%c\'");
        _applog(3,acStack_a828,1);
        _quit(1);
        p_Var25 = *pp_Var10;
      }
      if (uVar36 == p_Var25[0x57]) {
        snprintf(acStack_a028,0x800,"API group name can\'t be \'%c\'",uVar36);
        _applog(3,acStack_a028,1);
        _quit(1);
        p_Var25 = *pp_Var10;
      }
      if (uVar36 == p_Var25[0x52]) {
        snprintf(acStack_9828,0x800,"API group name can\'t be \'%c\'",uVar36);
        _applog(3,acStack_9828,1);
        _quit(1);
        p_Var25 = *pp_Var10;
      }
      if (*(int *)(apigroups + (p_Var25[uVar36] - p_Var25[0x41]) * 4) != 0) {
        snprintf(acStack_9028,0x800,"API duplicate group name \'%c\'",(uint)*pbVar12);
        _applog(3,acStack_9028,1);
        _quit(1);
      }
      local_2028 = '|';
      local_2027[0] = '\0';
      if ((pbVar12 + 2 != (byte *)0x0) && (pbVar12[2] != 0)) {
        pcStack_16480 = local_2027;
        bVar26 = false;
        pbVar12 = pbVar12 + 2;
        do {
          pbVar11 = (byte *)strchr((char *)pbVar12,0x3a);
          pbVar35 = pbVar11;
          if (pbVar11 != (byte *)0x0) {
            pbVar35 = pbVar11 + 1;
            *pbVar11 = 0;
          }
          if ((*pbVar12 == 0x2a) && (pbVar12[1] == 0)) {
            bVar26 = true;
          }
          else {
            if (cmds._0_4_ != 0) {
              puVar30 = cmds;
              iVar8 = 0;
              pcVar34 = (char *)cmds._0_4_;
              do {
                iVar33 = strcasecmp((char *)pbVar12,pcVar34);
                if (iVar33 == 0) {
                  sprintf(acStack_16320,"|%s|",pcVar34);
                  pcVar34 = strstr(&local_2028,acStack_16320);
                  if (pcVar34 == (char *)0x0) {
                    pcVar34 = *(char **)(cmds + iVar8 * 0xc);
                    strcpy(pcStack_16480,pcVar34);
                    sVar9 = strlen(pcVar34);
                    pcVar34 = pcStack_16480 + sVar9;
                    pcStack_16480 = pcStack_16480 + sVar9 + 1;
                    pcVar34[1] = '\0';
                    *pcVar34 = '|';
                  }
                  goto joined_r0x0001a08e;
                }
                puVar30 = (undefined1 *)((int)puVar30 + 0xc);
                pcVar34 = *(char **)puVar30;
                iVar8 = iVar8 + 1;
              } while (pcVar34 != (char *)0x0);
            }
            snprintf(acStack_8828,0x800,"API unknown command \'%s\' in group \'%c\'",pbVar12,uVar36)
            ;
            _applog(3,acStack_8828,1);
            _quit(1);
          }
joined_r0x0001a08e:
        } while ((pbVar35 != (byte *)0x0) && (pbVar12 = pbVar35, *pbVar35 != 0));
        if ((bVar26) && (cmds._0_4_ != 0)) {
          puVar30 = cmds;
LAB_0001a0ae:
          do {
            if (*(char *)((int)puVar30 + 8) == '\0') {
              sprintf(acStack_16320,"|%s|");
              pcVar34 = strstr(&local_2028,acStack_16320);
              if (pcVar34 == (char *)0x0) {
                pcVar34 = *(char **)puVar30;
                strcpy(pcStack_16480,pcVar34);
                sVar9 = strlen(pcVar34);
                pcVar28 = pcStack_16480 + sVar9;
                pcStack_16480 = pcStack_16480 + sVar9 + 1;
                *pcVar28 = '|';
                puVar30 = (undefined1 *)((int)puVar30 + 0xc);
                pcVar34 = *(char **)puVar30;
                pcVar28[1] = '\0';
                if (pcVar34 == (char *)0x0) break;
                goto LAB_0001a0ae;
              }
            }
            puVar30 = (undefined1 *)((int)puVar30 + 0xc);
          } while (*(char **)puVar30 != (char *)0x0);
        }
      }
      iVar33 = (*pp_Var10)[uVar36];
      iVar8 = (*pp_Var10)[0x41];
      sVar9 = strlen(&local_2028);
      pcVar34 = (char *)malloc(sVar9 + 1);
      *(char **)(apigroups + (iVar33 - iVar8) * 4) = pcVar34;
      if (pcVar34 == (char *)0x0) {
        local_8028._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[0];
        local_8028._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[1];
        local_8028._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[2];
        local_8028._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[3];
        uStack_8024._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[4];
        uStack_8024._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[5];
        uStack_8024._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[6];
        uStack_8024._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[7];
        uStack_8020._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[8];
        uStack_8020._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[9];
        uStack_8020._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[10];
        uStack_8020._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[11];
        uStack_801c._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[12];
        uStack_801c._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[13];
        uStack_801c._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[14];
        uStack_801c._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[15];
        local_8018._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[16];
        local_8018._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[17];
        local_8018._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[18];
        local_8018._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[19];
        uStack_8014._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[20];
        uStack_8014._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[21];
        uStack_8014._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[22];
        uStack_8014._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[23];
        uStack_8010._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[24];
        uStack_8010._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[25];
        uStack_8010._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[26];
        uStack_8010._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[27];
        uStack_800c._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[28];
        uStack_800c._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[29];
        uStack_800c._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[30];
        uStack_800c._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[31];
        local_8008._0_1_ = s_Failed_to_malloc_group_commands_b_0005887c[32];
        local_8008._1_1_ = s_Failed_to_malloc_group_commands_b_0005887c[33];
        local_8008._2_1_ = s_Failed_to_malloc_group_commands_b_0005887c[34];
        local_8008._3_1_ = s_Failed_to_malloc_group_commands_b_0005887c[35];
        _applog(3,&local_8028,1);
        _quit(1);
      }
      strcpy(pcVar34,&local_2028);
      if (pbStack_16488 == (byte *)0x0) break;
      pbVar12 = pbStack_16488;
      bVar24 = *pbStack_16488;
    }
    unaff_r11 = __ctype_toupper_loc();
    local_2027[0] = '\0';
    local_2028 = '|';
    puVar30 = cmds;
    pcVar34 = local_2027;
    pcVar28 = (char *)cmds._0_4_;
    while (pcVar28 != (char *)0x0) {
      while (*(char *)((int)puVar30 + 8) == '\0') {
        strcpy(pcVar34,pcVar28);
        sVar9 = strlen(pcVar28);
        puVar30 = (undefined1 *)((int)puVar30 + 0xc);
        pcVar28 = *(char **)puVar30;
        pcVar37 = pcVar34 + sVar9;
        pcVar34 = pcVar34 + sVar9 + 1;
        *pcVar37 = '|';
        pcVar37[1] = '\0';
        if (pcVar28 == (char *)0x0) goto LAB_0001a19c;
      }
      puVar30 = (undefined1 *)((int)puVar30 + 0xc);
      pcVar28 = *(char **)puVar30;
    }
LAB_0001a19c:
    p_Var25 = *unaff_r11;
    iVar8 = p_Var25[0x52];
    if (iVar8 + 0x80U < 0x180) {
      iVar8 = p_Var25[iVar8];
    }
    iVar33 = p_Var25[0x41];
    sVar9 = strlen(&local_2028);
    pcVar34 = (char *)malloc(sVar9 + 1);
    *(char **)(apigroups + (iVar8 - iVar33) * 4) = pcVar34;
    if (pcVar34 == (char *)0x0) goto LAB_0001aca2;
  }
  else {
    tidyup(__ptr);
    __pthread_unwind_next(a_Stack_16140);
LAB_0001aca2:
    local_7828._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[0];
    local_7828._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[1];
    local_7828._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[2];
    local_7828._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[3];
    uStack_7824._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[4];
    uStack_7824._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[5];
    uStack_7824._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[6];
    uStack_7824._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[7];
    uStack_7820._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[8];
    uStack_7820._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[9];
    uStack_7820._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[10];
    uStack_7820._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[11];
    uStack_781c._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[12];
    uStack_781c._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[13];
    uStack_781c._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[14];
    uStack_781c._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[15];
    local_7818._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[16];
    local_7818._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[17];
    local_7818._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[18];
    local_7818._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[19];
    uStack_7814._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[20];
    uStack_7814._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[21];
    uStack_7814._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[22];
    uStack_7814._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[23];
    uStack_7810._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[24];
    uStack_7810._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[25];
    uStack_7810._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[26];
    uStack_7810._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[27];
    uStack_780c._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[28];
    uStack_780c._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[29];
    uStack_780c._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[30];
    uStack_780c._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[31];
    local_7808._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[32];
    local_7808._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[33];
    local_7808._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[34];
    local_7808._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[35];
    uStack_7804._0_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[36];
    uStack_7804._1_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[37];
    uStack_7804._2_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[38];
    uStack_7804._3_1_ = s_Failed_to_malloc_noprivgroup_com_000588a0[39];
    local_7800 = (undefined2)ram0x000588c8;
    _applog(3,&local_7828,1);
    _quit(1);
  }
  strcpy(pcVar34,&local_2028);
  free(pbStack_1644c);
  pcVar34 = opt_api_allow;
  if (opt_api_allow != (char *)0x0) {
    sVar9 = strlen(opt_api_allow);
    pbVar12 = (byte *)malloc(sVar9 + 1);
    if (pbVar12 == (byte *)0x0) {
      local_7028._0_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[0];
      local_7028._1_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[1];
      local_7028._2_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[2];
      local_7028._3_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[3];
      uStack_7024._0_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[4];
      uStack_7024._1_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[5];
      uStack_7024._2_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[6];
      uStack_7024._3_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[7];
      uStack_7020._0_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[8];
      uStack_7020._1_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[9];
      uStack_7020._2_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[10];
      uStack_7020._3_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[11];
      uStack_701c._0_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[12];
      uStack_701c._1_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[13];
      uStack_701c._2_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[14];
      uStack_701c._3_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[15];
      local_7018._0_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[16];
      local_7018._1_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[17];
      local_7018._2_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[18];
      local_7018._3_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[19];
      uStack_7014._0_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[20];
      uStack_7014._1_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[21];
      uStack_7014._2_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[22];
      uStack_7014._3_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[23];
      uStack_7010._0_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[24];
      uStack_7010._1_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[25];
      uStack_7010._2_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[26];
      uStack_7010._3_1_ = s_Failed_to_malloc_ipaccess_buf_000588cc[27];
      local_700c = (undefined2)ram0x000588e8;
      _applog(3,&local_7028,1);
      _quit(1);
      pcVar34 = opt_api_allow;
    }
    strcpy((char *)pbVar12,pcVar34);
    pbVar35 = pbVar12 + -1;
    sVar9 = 1;
    while( true ) {
      pbVar35 = pbVar35 + 1;
      if (*pbVar35 == 0) break;
      if (*pbVar35 == 0x2c) {
        sVar9 = sVar9 + 1;
      }
    }
    ipaccess = calloc(sVar9,0x24);
    if (ipaccess == (void *)0x0) {
      local_6828._0_1_ = s_Failed_to_calloc_ipaccess_000588ec[0];
      local_6828._1_1_ = s_Failed_to_calloc_ipaccess_000588ec[1];
      local_6828._2_1_ = s_Failed_to_calloc_ipaccess_000588ec[2];
      local_6828._3_1_ = s_Failed_to_calloc_ipaccess_000588ec[3];
      uStack_6824._0_1_ = s_Failed_to_calloc_ipaccess_000588ec[4];
      uStack_6824._1_1_ = s_Failed_to_calloc_ipaccess_000588ec[5];
      uStack_6824._2_1_ = s_Failed_to_calloc_ipaccess_000588ec[6];
      uStack_6824._3_1_ = s_Failed_to_calloc_ipaccess_000588ec[7];
      uStack_6820._0_1_ = s_Failed_to_calloc_ipaccess_000588ec[8];
      uStack_6820._1_1_ = s_Failed_to_calloc_ipaccess_000588ec[9];
      uStack_6820._2_1_ = s_Failed_to_calloc_ipaccess_000588ec[10];
      uStack_6820._3_1_ = s_Failed_to_calloc_ipaccess_000588ec[11];
      uStack_681c._0_1_ = s_Failed_to_calloc_ipaccess_000588ec[12];
      uStack_681c._1_1_ = s_Failed_to_calloc_ipaccess_000588ec[13];
      uStack_681c._2_1_ = s_Failed_to_calloc_ipaccess_000588ec[14];
      uStack_681c._3_1_ = s_Failed_to_calloc_ipaccess_000588ec[15];
      local_6818._0_1_ = s_Failed_to_calloc_ipaccess_000588ec[16];
      local_6818._1_1_ = s_Failed_to_calloc_ipaccess_000588ec[17];
      local_6818._2_1_ = s_Failed_to_calloc_ipaccess_000588ec[18];
      local_6818._3_1_ = s_Failed_to_calloc_ipaccess_000588ec[19];
      uStack_6814._0_1_ = s_Failed_to_calloc_ipaccess_000588ec[20];
      uStack_6814._1_1_ = s_Failed_to_calloc_ipaccess_000588ec[21];
      uStack_6814._2_1_ = s_Failed_to_calloc_ipaccess_000588ec[22];
      uStack_6814._3_1_ = s_Failed_to_calloc_ipaccess_000588ec[23];
      local_6810 = (undefined2)ram0x00058904;
      _applog(3,&local_6828,1);
      _quit(1);
    }
    iVar8 = 0;
    ips = 0;
    pbVar35 = pbVar12;
    do {
      while( true ) {
        bVar24 = *pbVar35;
        if (bVar24 == 0) goto LAB_0001a322;
        if (bVar24 == 9 || bVar24 == 0x20) {
          do {
            pbVar35 = pbVar35 + 1;
            bVar24 = *pbVar35;
          } while (bVar24 == 9 || bVar24 == 0x20);
        }
        if (bVar24 == 0x2c) {
          pbVar11 = pbVar35 + 1;
          goto LAB_0001a31e;
        }
        pbVar13 = (byte *)strchr((char *)pbVar35,0x2c);
        pbVar11 = pbVar13;
        if (pbVar13 != (byte *)0x0) {
          pbVar11 = pbVar13 + 1;
          *pbVar13 = 0;
        }
        ppuVar14 = __ctype_b_loc();
        p_Var25 = *unaff_r11;
        bVar24 = *(byte *)(p_Var25 + 0x52);
        if (((int)((uint)(*ppuVar14)[*pbVar35] << 0x15) < 0) && (pbVar35[1] == 0x3a)) {
          iVar33 = p_Var25[*pbVar35];
          if ((iVar33 == p_Var25[0x57]) || (*(int *)(apigroups + (iVar33 - p_Var25[0x41]) * 4) != 0)
             ) {
            bVar24 = (byte)iVar33;
          }
          pbVar35 = pbVar35 + 2;
        }
        pbVar13 = (byte *)((int)ipaccess + iVar8 * 0x24);
        pbVar13[0x20] = bVar24;
        bVar24 = *pbVar35;
        if (bVar24 == 0x30) break;
        pbVar15 = (byte *)strchr((char *)pbVar35,0x2f);
        if (pbVar15 == (byte *)0x0) {
LAB_0001a4d4:
          pbVar15 = pbVar13 + 0xf;
          do {
            pbVar15 = pbVar15 + 1;
            *pbVar15 = 0xff;
          } while (pbVar15 != pbVar13 + 0x1f);
          sVar9 = strlen((char *)pbVar35);
          bVar24 = *pbVar35;
          pbVar15 = pbVar35 + sVar9;
        }
        if ((bVar24 == 0x5b) && (pbVar15[-1] == 0x5d)) {
          *pbVar35 = 0;
          pbVar35 = pbVar35 + 1;
          pbVar15[-1] = 0;
          bVar26 = true;
        }
        else {
LAB_0001a2ea:
          bVar26 = false;
        }
        if (*pbVar15 == 0) {
LAB_0001a2f6:
          pbVar15 = pbVar13 + -1;
          do {
            pbVar15 = pbVar15 + 1;
            *pbVar15 = 0;
          } while (pbVar15 != pbVar13 + 0xf);
          if (bVar26) {
            iVar33 = inet_pton(10,(char *)pbVar35,pbVar13);
          }
          else {
            sprintf(acStack_16404,"::ffff:%s",pbVar35);
            iVar8 = ips;
            pbVar13 = (byte *)((int)ipaccess + ips * 0x24);
            iVar33 = inet_pton(10,acStack_16404,pbVar13);
          }
          if (iVar33 == 1) {
            pbVar35 = pbVar13 + 0xf;
            pbVar15 = pbVar13;
            do {
              pbVar35 = pbVar35 + 1;
              pbVar29 = pbVar15 + 1;
              *pbVar15 = *pbVar35 & *pbVar15;
              pbVar15 = pbVar29;
            } while (pbVar29 != pbVar13 + 0x10);
            goto LAB_0001a492;
          }
        }
        else {
          *pbVar15 = 0;
          lVar16 = strtol((char *)(pbVar15 + 1),(char **)0x0,10);
          if (0 < lVar16) {
            iVar32 = 0;
            iVar33 = iVar32;
            if (!bVar26) {
              iVar33 = 0x60;
            }
            iVar33 = lVar16 + iVar33;
            if (iVar33 < 0x81) {
              pbVar15 = pbVar13 + 0xf;
              do {
                pbVar15 = pbVar15 + 1;
                *pbVar15 = 0;
              } while (pbVar13 + 0x1f != pbVar15);
              while (uVar36 = 7, iVar33 != 0) {
                while( true ) {
                  iVar33 = iVar33 + -1;
                  pbVar13[iVar32 + 0x10] = pbVar13[iVar32 + 0x10] | (byte)(1 << (uVar36 & 0xff));
                  if (uVar36 == 0) break;
                  uVar36 = uVar36 - 1;
                  if (iVar33 == 0) goto LAB_0001a2f6;
                }
                iVar32 = iVar32 + 1;
              }
              goto LAB_0001a2f6;
            }
          }
        }
LAB_0001a31e:
        pbVar35 = pbVar11;
        if (pbVar11 == (byte *)0x0) goto LAB_0001a322;
      }
      if (((pbVar35[1] != 0x2f) || (pbVar35[2] != 0x30)) || (pbVar35[3] != 0)) {
        pbVar15 = (byte *)strchr((char *)pbVar35,0x2f);
        if (pbVar15 == (byte *)0x0) goto LAB_0001a4d4;
        goto LAB_0001a2ea;
      }
      pbVar35 = pbVar13 + -1;
      pbVar15 = pbVar13 + 0xf;
      do {
        pbVar35 = pbVar35 + 1;
        *pbVar35 = 0;
        pbVar15 = pbVar15 + 1;
        *pbVar15 = 0;
      } while (pbVar13 + 0xf != pbVar35);
LAB_0001a492:
      iVar8 = iVar8 + 1;
      pbVar35 = pbVar11;
      ips = iVar8;
    } while (pbVar11 != (byte *)0x0);
LAB_0001a322:
    free(pbVar12);
    if (iVar8 == 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(acStack_15828,0x800,"API not running (no valid IPs specified)%s",
                 " - API will not be available");
        _applog(4,acStack_15828,0);
      }
      goto LAB_00019dcc;
    }
  }
  sStack_16464 = (short)uVar2;
  iVar33 = (int)sStack_16464;
  cgsleep_ms(opt_log_interval * 1000);
  sprintf(acStack_16410,"%d",iVar33);
  memset(&aStack_163e4,0,0x20);
  aStack_163e4.ai_flags = 1;
  iVar8 = getaddrinfo(opt_api_host,acStack_16410,&aStack_163e4,&paStack_16418);
  if (iVar8 != 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      snprintf(acStack_15028,0x800,"API failed to resolve %s",opt_api_host);
      _applog(3,acStack_15028,0);
    }
LAB_00019dcc:
    free(__ptr);
    return;
  }
  paVar31 = paStack_16418;
  if (paStack_16418 == (addrinfo *)0x0) {
    iVar8 = *__ptr;
  }
  else {
    do {
      iVar8 = socket(paStack_16418->ai_family,1,0);
      *__ptr = iVar8;
      if (0 < iVar8) goto LAB_0001a67e;
      paVar31 = paVar31->ai_next;
    } while (paVar31 != (addrinfo *)0x0);
  }
  if (iVar8 == -1) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      piVar23 = __errno_location();
      pcVar34 = strerror(*piVar23);
      snprintf(acStack_14828,0x800,"API initialisation failed (%s)%s",pcVar34,
               " - API will not be available");
      _applog(3,acStack_14828,0);
    }
    freeaddrinfo(paStack_16418);
    free(__ptr);
    return;
  }
  paVar31 = (addrinfo *)0x0;
LAB_0001a67e:
  uStack_16414 = 1;
  iVar8 = setsockopt(iVar8,1,2,&uStack_16414,4);
  if (((iVar8 < 0) && (opt_debug != '\0')) &&
     ((use_syslog != '\0' || ((opt_log_output != '\0' || (6 < opt_log_level)))))) {
    piVar23 = __errno_location();
    pcVar34 = strerror(*piVar23);
    snprintf(acStack_14028,0x800,"API setsockopt SO_REUSEADDR failed (ignored): %s",pcVar34);
    _applog(7,acStack_14028,0);
  }
  tVar17 = time((time_t *)0x0);
  while (iVar8 = bind(*__ptr,paVar31->ai_addr,paVar31->ai_addrlen), iVar8 < 0) {
    piVar23 = __errno_location();
    pcVar34 = strerror(*piVar23);
    tVar22 = time((time_t *)0x0);
    if (0x3d < tVar22 - tVar17) {
      freeaddrinfo(paStack_16418);
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_13028,0x800,"API bind to port %d failed (%s)%s",iVar33,pcVar34,
                 " - API will not be available");
        _applog(3,acStack_13028,0);
      }
      goto LAB_00019dcc;
    }
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(acStack_13828,0x800,"API bind to port %d failed - trying again in 30sec",iVar33);
      _applog(4,acStack_13828,0);
    }
    cgsleep_ms(30000);
  }
  freeaddrinfo(paStack_16418);
  iVar8 = listen(*__ptr,100);
  if (iVar8 < 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
      piVar23 = __errno_location();
      pcVar34 = strerror(*piVar23);
      snprintf(acStack_12828,0x800,"API3 initialisation failed (%s)%s",pcVar34,
               " - API will not be available");
      _applog(3,acStack_12828,0);
    }
    close(*__ptr);
    free(__ptr);
    return;
  }
  if (opt_api_allow == (char *)0x0) {
    if (opt_api_network == '\0') {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
        snprintf(acStack_11028,0x800,"API running in local read access mode on port %d (%d)",iVar33,
                 *__ptr);
        _applog(4,acStack_11028,0);
      }
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
      snprintf(acStack_11828,0x800,"API running in UNRESTRICTED read access mode on port %d (%d)",
               iVar33,*__ptr);
      _applog(4,acStack_11828,0);
    }
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (3 < opt_log_level)) {
    snprintf(acStack_12028,0x800,"API running in IP access mode on port %d (%d)",iVar33,*__ptr);
    _applog(4,acStack_12028,0);
  }
  if (opt_api_mcast != '\0') {
    mcast_init();
  }
  uVar2 = DAT_0001aa08;
  strbufs = _k_new_list("StrBufs",0xc,2,0,0,"api.c",DAT_0001aa08,0x1581);
  while (bye == '\0') {
    sStack_1641c = 0x80;
    iVar8 = accept(*__ptr,asStack_162bc,&sStack_1641c);
    if (iVar8 < 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        piVar23 = __errno_location();
        pcVar34 = strerror(*piVar23);
        snprintf(acStack_10828,0x800,"API failed (%s)%s (%d)",pcVar34," - API will not be available"
                 ,*__ptr);
        _applog(3,acStack_10828,0);
      }
      break;
    }
    if (pvStack_16420 != (void *)0x0) {
      free(pvStack_16420);
      pvStack_16420 = (void *)0x0;
    }
    iVar33 = check_connect(asStack_162bc,&pvStack_16420,&bStack_16422);
    if ((opt_debug != '\0') &&
       (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
      pcVar34 = "Accepted";
      if (iVar33 == 0) {
        pcVar34 = "Ignored";
      }
      snprintf(acStack_10028,0x800,"API: connection from %s - %s",pvStack_16420,pcVar34);
      _applog(7,acStack_10028,0);
    }
    if (iVar33 != 0) {
      sVar18 = recv(iVar8,local_6028,0x1fff,0);
      if (sVar18 < 0) {
        local_6028[0] = '\0';
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          piVar23 = __errno_location();
          pcVar34 = strerror(*piVar23);
          snprintf(acStack_f828,0x800,"API: recv failed: %s",pcVar34);
          _applog(7,acStack_f828,0);
        }
      }
      else {
        local_6028[sVar18] = '\0';
        if ((opt_debug != '\0') &&
           (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
          snprintf(acStack_f028,0x800,"API: recv command: (%d) \'%s\'",sVar18,local_6028);
          _applog(7,acStack_f028,0);
        }
        iVar33 = 0;
        pcVar34 = local_6028;
        when = time((time_t *)0x0);
        puVar5[2] = (undefined *)puVar5[1];
        *(undefined *)puVar5[1] = 0;
        *(undefined *)((int)puVar5 + 0xd) = 0;
        if (local_6028[0] != '{') {
          pcVar28 = strchr(pcVar34,0x7c);
          if (pcVar28 == (char *)0x0) {
            iVar33 = 0;
            pcVar37 = (char *)0x0;
          }
          else {
            pcVar37 = pcVar28 + 1;
            *pcVar28 = '\0';
          }
LAB_0001a90c:
          pcVar28 = strchr(pcVar34,0x2b);
          if (pcVar28 == (char *)0x0) {
            uStack_16421 = 0;
            bVar1 = false;
            puStack_16460 = (undefined2 *)0x0;
          }
          else {
            bVar1 = true;
            uStack_16421 = 1;
            sVar9 = strlen(pcVar34);
            puStack_16460 = (undefined2 *)malloc(sVar9 + 3);
            if (puStack_16460 == (undefined2 *)0x0) {
              snprintf(acStack_e828,0x800,"OOM cmdsbuf in %s %s():%d","api.c",uVar2,0x15f4);
              _applog(3,acStack_e828,1);
              _quit(1);
            }
            pcVar37 = (char *)0x0;
            *puStack_16460 = 0x7c;
          }
          pcVar28 = pcVar34;
          if (!bVar1) goto LAB_0001a98c;
LAB_0001a954:
          pcVar19 = strchr(pcVar28,0x2b);
          if (pcVar19 == (char *)0x0) {
            if (*pcVar28 == '\0') goto LAB_0001af08;
            pcVar34 = (char *)0x0;
          }
          else {
            pcVar34 = pcVar19 + 1;
            *pcVar19 = '\0';
            if (*pcVar28 == '\0') goto LAB_0001a974;
          }
          if (cmds._0_4_ != 0) goto LAB_0001a996;
LAB_0001ab36:
          head_join(puVar5,pcVar28,iVar33,&uStack_16421);
LAB_0001ab42:
          message(puVar5,0xe,0,0,iVar33);
          do {
            if (bVar1) {
              tail_join(puVar5,iVar33);
            }
            else {
              send_result_isra_6(puVar5[1],(int)puVar5 + 0xd,iVar8);
            }
            while( true ) {
              do {
                if (!bVar1) goto LAB_0001a9dc;
LAB_0001a974:
                bVar26 = bVar1;
                if (pcVar34 == (char *)0x0) {
                  bVar26 = false;
                }
                if (!bVar26) goto LAB_0001af08;
                pcVar28 = pcVar34;
                if (bVar1) goto LAB_0001a954;
LAB_0001a98c:
                pcVar28 = pcVar34;
                if (cmds._0_4_ == 0) goto LAB_0001ab42;
LAB_0001a996:
                puVar30 = cmds;
                iVar32 = 0;
                pcVar19 = (char *)cmds._0_4_;
                while (iVar20 = strcmp(pcVar28,pcVar19), iVar20 != 0) {
                  puVar30 = (undefined1 *)((int)puVar30 + 0xc);
                  pcVar19 = *(char **)puVar30;
                  iVar32 = iVar32 + 1;
                  if (pcVar19 == (char *)0x0) {
                    if (bVar1) goto LAB_0001ab36;
                    goto LAB_0001ab42;
                  }
                }
                sprintf(acStack_16384,"|%s|",pcVar28);
                if (!bVar1) goto LAB_0001aada;
                pcVar19 = strstr((char *)puStack_16460,acStack_16384);
              } while (pcVar19 != (char *)0x0);
              sVar9 = strlen((char *)puStack_16460);
              puVar21 = (undefined2 *)stpcpy((char *)(sVar9 + (int)puStack_16460),pcVar28);
              *puVar21 = DAT_00057a28;
              head_join(puVar5,pcVar28,iVar33,&uStack_16421);
              if (cmds[iVar32 * 0xc + 9] != '\0') break;
              message(puVar5,0x2d,0,*(undefined4 *)(cmds + iVar32 * 0xc),iVar33);
              tail_join(puVar5,iVar33);
            }
LAB_0001aada:
            uVar36 = (uint)bStack_16422;
            p_Var25 = *unaff_r11;
            if ((p_Var25[uVar36] == p_Var25[0x57]) ||
               (pcVar28 = strstr(*(char **)(apigroups + (p_Var25[uVar36] - p_Var25[0x41]) * 4),
                                 acStack_16384), pcVar28 != (char *)0x0)) {
              (**(code **)(cmds + iVar32 * 0xc + 4))(puVar5,iVar8,pcVar37,iVar33,uVar36);
            }
            else {
              message(puVar5,0x2d,0,*(undefined4 *)(cmds + iVar32 * 0xc),iVar33);
              if ((opt_debug != '\0') &&
                 (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
                snprintf(acStack_e028,0x800,"API: access denied to \'%s\' for \'%s\' command",
                         pvStack_16420,*(undefined4 *)(cmds + iVar32 * 0xc));
                _applog(7,acStack_e028,0);
              }
            }
          } while( true );
        }
        piStack_16478 = (int *)json_loadb(pcVar34,sVar18,0,auStack_1623c);
        if ((piStack_16478 == (int *)0x0) || (*piStack_16478 != 0)) {
          uVar27 = 0x17;
        }
        else {
          piVar23 = (int *)json_object_get(piStack_16478,"command");
          if (piVar23 == (int *)0x0) {
            uVar27 = 0x18;
          }
          else {
            if (*piVar23 == 2) {
              pcVar34 = (char *)json_string_value();
              piVar23 = (int *)json_object_get(piStack_16478,"parameter");
              if (piVar23 == (int *)0x0) {
                iVar33 = 1;
                pcVar37 = (char *)0x0;
              }
              else {
                iVar33 = *piVar23;
                if (iVar33 == 2) {
                  pcVar37 = (char *)json_string_value();
                  iVar33 = 1;
                }
                else if (iVar33 == 3) {
                  uVar27 = json_integer_value();
                  pcVar37 = acStack_4028;
                  iVar33 = 1;
                  sprintf(pcVar37,"%d",uVar27);
                }
                else if (iVar33 == 4) {
                  uVar38 = json_real_value();
                  pcVar37 = acStack_4028;
                  iVar33 = 1;
                  sprintf(pcVar37,"%f",(int)uVar38,(int)((ulonglong)uVar38 >> 0x20));
                }
                else {
                  iVar33 = 1;
                  pcVar37 = (char *)0x0;
                }
              }
              goto LAB_0001a90c;
            }
            uVar27 = 0xe;
          }
        }
        iVar33 = 1;
        message(puVar5,uVar27,0,0,1);
        send_result_isra_6(puVar5[1],(int)puVar5 + 0xd,iVar8,1);
LAB_0001af08:
        if (bVar1) {
          send_result_isra_6(puVar5[1],(int)puVar5 + 0xd,iVar8,iVar33);
        }
LAB_0001a9dc:
        if (piStack_16478 == (int *)0x0) {
          iVar33 = 0;
        }
        if (((iVar33 != 0) && (*piStack_16478 == 0)) &&
           ((piStack_16478[1] != -1 &&
            (iVar33 = piStack_16478[1] + -1, piStack_16478[1] = iVar33, iVar33 == 0)))) {
          json_delete(piStack_16478);
        }
      }
    }
    close(iVar8);
  }
  if (pvStack_16420 != (void *)0x0) {
    free(pvStack_16420);
    pvStack_16420 = (void *)0x0;
  }
  __pthread_unregister_cancel(a_Stack_16140);
  tidyup(__ptr);
  free(__ptr);
  if ((opt_debug != '\0') &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (6 < opt_log_level)))) {
    if (do_a_quit == '\0') {
      if (do_a_restart == '\0') {
        pcVar34 = "UNKNOWN!";
        if (bye != '\0') {
          pcVar34 = "BYE";
        }
      }
      else {
        pcVar34 = "RESTART";
      }
    }
    else {
      pcVar34 = "QUIT";
    }
    snprintf(acStack_d828,0x800,"API: terminating due to: %s",pcVar34);
    _applog(7,acStack_d828,0);
  }
  iVar8 = pthread_mutex_lock(DAT_0001b3c4);
  if (iVar8 != 0) {
    _mutex_lock_part_3_constprop_27(DAT_0001b3c8,0x165b);
  }
  if (do_a_restart == '\0') {
    if (do_a_quit == '\0') goto LAB_0001b2ac;
    iVar8 = thr_info_create(auStack_163c4,0,0x16281);
    if (iVar8 != 0) {
      iVar8 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
      if (iVar8 != 0) {
        _mutex_unlock_noyield_part_5_constprop_32(DAT_0001b3c8,0x166a);
      }
      (*selective_yield)();
      local_c828._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[0];
      local_c828._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[1];
      local_c828._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[2];
      local_c828._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[3];
      uStack_c824._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[4];
      uStack_c824._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[5];
      uStack_c824._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[6];
      uStack_c824._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[7];
      uStack_c820._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[8];
      uStack_c820._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[9];
      uStack_c820._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[10];
      uStack_c820._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[11];
      uStack_c81c._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[12];
      uStack_c81c._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[13];
      uStack_c81c._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[14];
      uStack_c81c._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[15];
      local_c818._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[16];
      local_c818._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[17];
      local_c818._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[18];
      local_c818._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[19];
      uStack_c814._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[20];
      uStack_c814._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[21];
      uStack_c814._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[22];
      uStack_c814._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[23];
      uStack_c810._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[24];
      uStack_c810._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[25];
      uStack_c810._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[26];
      uStack_c810._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[27];
      uStack_c80c._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[28];
      uStack_c80c._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[29];
      uStack_c80c._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[30];
      uStack_c80c._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[31];
      local_c808._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[32];
      local_c808._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[33];
      local_c808._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[34];
      local_c808._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[35];
      uStack_c804._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[36];
      uStack_c804._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[37];
      uStack_c804._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[38];
      uStack_c804._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[39];
      uStack_c800._0_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[40];
      uStack_c800._1_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[41];
      uStack_c800._2_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[42];
      uStack_c800._3_1_ = s_API_failed_to_initiate_a_clean_q_00058bd4[43];
      uStack_c7fc = (undefined2)ram0x00058c00;
      local_c7fa = (undefined)((uint)ram0x00058c00 >> 0x10);
      _applog(3,&local_c828,1);
      _quit(1);
    }
  }
  else {
    iVar8 = thr_info_create(auStack_163c4,0,0x16161);
    if (iVar8 != 0) {
      iVar8 = pthread_mutex_unlock((pthread_mutex_t *)quit_restart_lock);
      if (iVar8 != 0) {
        _mutex_unlock_noyield_part_5_constprop_32(DAT_0001b3c8,0x1661);
      }
      (*selective_yield)();
      local_d028._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[0];
      local_d028._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[1];
      local_d028._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[2];
      local_d028._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[3];
      uStack_d024._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[4];
      uStack_d024._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[5];
      uStack_d024._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[6];
      uStack_d024._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[7];
      uStack_d020._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[8];
      uStack_d020._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[9];
      uStack_d020._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[10];
      uStack_d020._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[11];
      uStack_d01c._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[12];
      uStack_d01c._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[13];
      uStack_d01c._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[14];
      uStack_d01c._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[15];
      local_d018._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[16];
      local_d018._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[17];
      local_d018._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[18];
      local_d018._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[19];
      uStack_d014._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[20];
      uStack_d014._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[21];
      uStack_d014._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[22];
      uStack_d014._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[23];
      uStack_d010._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[24];
      uStack_d010._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[25];
      uStack_d010._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[26];
      uStack_d010._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[27];
      uStack_d00c._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[28];
      uStack_d00c._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[29];
      uStack_d00c._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[30];
      uStack_d00c._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[31];
      local_d008._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[32];
      local_d008._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[33];
      local_d008._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[34];
      local_d008._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[35];
      uStack_d004._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[36];
      uStack_d004._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[37];
      uStack_d004._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[38];
      uStack_d004._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[39];
      uStack_d000._0_1_ = s_API_failed_to_initiate_a_restart_00058ba8[40];
      uStack_d000._1_1_ = s_API_failed_to_initiate_a_restart_00058ba8[41];
      uStack_d000._2_1_ = s_API_failed_to_initiate_a_restart_00058ba8[42];
      uStack_d000._3_1_ = s_API_failed_to_initiate_a_restart_00058ba8[43];
      _applog(3,&local_d028,1);
      _quit(1);
    }
  }
  pthread_detach(pStack_163b8);
LAB_0001b2ac:
  iVar8 = pthread_mutex_unlock(DAT_0001b3c4);
  if (iVar8 != 0) {
    _mutex_unlock_noyield_part_5_constprop_32(DAT_0001b3c8,0x1670);
  }
  (*selective_yield)();
  return;
}

