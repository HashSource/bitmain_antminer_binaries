
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void api(int api_thr_id)

{
  uint uVar1;
  short sVar2;
  bool bVar3;
  _Bool _Var4;
  int *arg;
  io_data *io_data_00;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  time_t tVar8;
  time_t tVar9;
  size_t buflen;
  json_t *pjVar10;
  size_t sVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  double dVar15;
  json_int_t jVar16;
  int api_thr_id_local;
  __pthread_unwind_buf_t __cancel_buf;
  char tmp42 [2048];
  char tmp42_1 [2048];
  char tmp42_2 [2048];
  char tmp42_3 [2048];
  char tmp42_4 [2048];
  char tmp42_5 [2048];
  char tmp42_6 [2048];
  char tmp42_7 [2048];
  char tmp42_8 [2048];
  char tmp42_9 [2048];
  char tmp42_10 [2048];
  char tmp42_11 [2048];
  char tmp42_12 [2048];
  char tmp42_13 [2048];
  char tmp42_14 [2048];
  char tmp42_15 [2048];
  char tmp42_16 [2048];
  char tmp42_17 [2048];
  char tmp42_18 [2048];
  int optval;
  addrinfo *res;
  addrinfo hints;
  _Bool firstjoin;
  json_error_t json_err;
  char group;
  char cmdbuf [100];
  socklen_t clisiz;
  sockaddr_storage cli;
  char port_s [10];
  char *connectaddr;
  char param_buf [8192];
  char buf [8192];
  thr_info bye_thr;
  json_t *json_val;
  int n;
  _Bool addrok;
  long c;
  time_t bindstart;
  int __not_first_call;
  short port;
  char *cmdsbuf;
  char *cmdptr;
  void *__cancel_arg;
  _func_void_void_ptr *__cancel_routine;
  long *apisock;
  addrinfo *host;
  int i;
  _Bool isjoin;
  _Bool did;
  _Bool isjson;
  json_t *json_config;
  char *param;
  char *cmd;
  char *binderror;
  int bound;
  io_data *io_data;
  
  sVar2 = (short)opt_api_port;
  cmd = (char *)0x0;
  arg = (int *)_cgmalloc(4,"api-btm.c","api",0x149f);
  *arg = -1;
  json_config = (json_t *)0x0;
  isjoin = false;
  if (opt_api_listen == true) {
    io_data_00 = _io_new(0x10000,true);
    _mutex_init(&quit_restart_lock,"api-btm.c","api",0x14ad);
    iVar5 = __sigsetjmp(&__cancel_buf,0);
    if (iVar5 != 0) {
      tidyup(arg);
      __pthread_unwind_next((__pthread_unwind_buf_t *)&__cancel_buf);
    }
    __pthread_register_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
    my_thr_id = api_thr_id;
    setup_groups();
    if ((opt_api_allow == (char *)0x0) || (setup_ipaccess(), ips != 0)) {
      cgsleep_ms(opt_log_interval * 1000);
      sprintf(port_s,"%d",(int)sVar2);
      memset(&hints,0,0x20);
      hints.ai_flags = 1;
      hints.ai_family = 0;
      iVar5 = getaddrinfo(opt_api_host,port_s,(addrinfo *)&hints,(addrinfo **)&res);
      if (iVar5 == 0) {
        for (host = res; host != (addrinfo *)0x0; host = host->ai_next) {
          iVar5 = socket(res->ai_family,1,0);
          *arg = iVar5;
          if (0 < *arg) break;
        }
        if (*arg == -1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            piVar6 = __errno_location();
            pcVar7 = strerror(*piVar6);
            snprintf(tmp42_3,0x800,"API initialisation failed (%s)%s",pcVar7,UNAVAILABLE);
            _applog(3,tmp42_3,false);
          }
          freeaddrinfo((addrinfo *)res);
          free(arg);
        }
        else {
          optval = 1;
          iVar5 = setsockopt(*arg,1,2,&optval,4);
          if (((iVar5 < 0) && (opt_debug != false)) &&
             ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
            piVar6 = __errno_location();
            pcVar7 = strerror(*piVar6);
            snprintf(tmp42_4,0x800,"API setsockopt SO_REUSEADDR failed (ignored): %s",pcVar7);
            _applog(7,tmp42_4,false);
          }
          bVar3 = false;
          tVar8 = time((time_t *)0x0);
          while (!bVar3) {
            iVar5 = bind(*arg,(sockaddr *)host->ai_addr,host->ai_addrlen);
            if (iVar5 < 0) {
              piVar6 = __errno_location();
              binderror = strerror(*piVar6);
              tVar9 = time((time_t *)0x0);
              if (0x3d < tVar9 - tVar8) break;
              if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                snprintf(tmp42_5,0x800,"API bind to port %d failed - trying again in 30sec",
                         (int)sVar2);
                _applog(4,tmp42_5,false);
              }
              cgsleep_ms(30000);
            }
            else {
              bVar3 = true;
            }
          }
          freeaddrinfo((addrinfo *)res);
          if (bVar3) {
            iVar5 = listen(*arg,100);
            if (iVar5 < 0) {
              if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                piVar6 = __errno_location();
                pcVar7 = strerror(*piVar6);
                snprintf(tmp42_7,0x800,"API3 initialisation failed (%s)%s",pcVar7,UNAVAILABLE);
                _applog(3,tmp42_7,false);
              }
              close(*arg);
              free(arg);
            }
            else {
              if (opt_api_allow == (char *)0x0) {
                if (opt_api_network == false) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                    snprintf(tmp42_10,0x800,"API running in local read access mode on port %d (%d)",
                             (int)sVar2,*arg);
                    _applog(4,tmp42_10,false);
                  }
                }
                else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)
                        ) {
                  snprintf(tmp42_9,0x800,
                           "API running in UNRESTRICTED read access mode on port %d (%d)",(int)sVar2
                           ,*arg);
                  _applog(4,tmp42_9,false);
                }
              }
              else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level))
              {
                snprintf(tmp42_8,0x800,"API running in IP access mode on port %d (%d)",(int)sVar2,
                         *arg);
                _applog(4,tmp42_8,false);
              }
              if (opt_api_mcast != false) {
                mcast_init();
              }
              strbufs = _k_new_list("StrBufs",0xc,2,0,false,"api-btm.c","api",0x151d);
              while (bye != true) {
                clisiz = 0x80;
                iVar5 = accept(*arg,(sockaddr *)&cli,&clisiz);
                if (iVar5 < 0) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    piVar6 = __errno_location();
                    pcVar7 = strerror(*piVar6);
                    snprintf(tmp42_11,0x800,"API failed (%s)%s (%d)",pcVar7,UNAVAILABLE,*arg);
                    _applog(3,tmp42_11,false);
                  }
                  break;
                }
                _Var4 = check_connect(&cli,&connectaddr,&group);
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  if (_Var4) {
                    uVar1 = 0xdc70;
                  }
                  else {
                    uVar1 = 0xe920;
                  }
                  snprintf(tmp42_12,0x800,"API: connection from %s - %s",connectaddr,uVar1 | 0xa0000
                          );
                  _applog(7,tmp42_12,false);
                }
                if (_Var4) {
                  buflen = recv(iVar5,buf,0x1fff,0);
                  if ((int)buflen < 0) {
                    buf[0] = '\0';
                  }
                  else {
                    buf[buflen] = '\0';
                  }
                  if (opt_debug != false) {
                    if ((int)buflen < 0) {
                      if ((opt_debug != false) &&
                         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)
                          ))) {
                        piVar6 = __errno_location();
                        pcVar7 = strerror(*piVar6);
                        snprintf(tmp42_13,0x800,"API: recv failed: %s",pcVar7);
                        _applog(7,tmp42_13,false);
                      }
                    }
                    else if ((opt_debug != false) &&
                            (((use_syslog != false || (opt_log_output != false)) ||
                             (6 < opt_log_level)))) {
                      snprintf(tmp42_14,0x800,"API: recv command: (%d) \'%s\'",buflen,buf);
                      _applog(7,tmp42_14,false);
                    }
                  }
                  if (-1 < (int)buflen) {
                    when = time((time_t *)0x0);
                    io_reinit(io_data_00);
                    bVar3 = false;
                    if (buf[0] == '{') {
                      isjson = true;
                      param = (char *)0x0;
                      json_config = json_loadb(buf,buflen,0,&json_err);
                      if ((json_config == (json_t *)0x0) || (json_config->type != JSON_OBJECT)) {
                        message(io_data_00,0x17,0,(char *)0x0,true);
                        send_result(io_data_00,iVar5,true);
                        bVar3 = true;
                      }
                      else {
                        pjVar10 = json_object_get(json_config,JSON_COMMAND);
                        if (pjVar10 == (json_t *)0x0) {
                          message(io_data_00,0x18,0,(char *)0x0,true);
                          send_result(io_data_00,iVar5,true);
                          bVar3 = true;
                        }
                        else if ((pjVar10 == (json_t *)0x0) || (pjVar10->type != JSON_STRING)) {
                          message(io_data_00,0xe,0,(char *)0x0,true);
                          send_result(io_data_00,iVar5,true);
                          bVar3 = true;
                        }
                        else {
                          cmd = json_string_value(pjVar10);
                          pjVar10 = json_object_get(json_config,JSON_PARAMETER);
                          if ((pjVar10 == (json_t *)0x0) || (pjVar10->type != JSON_STRING)) {
                            if ((pjVar10 == (json_t *)0x0) || (pjVar10->type != JSON_INTEGER)) {
                              if ((pjVar10 != (json_t *)0x0) && (pjVar10->type == JSON_REAL)) {
                                dVar15 = json_real_value(pjVar10);
                                sprintf(param_buf,"%f",SUB84(dVar15,0),
                                        (int)((ulonglong)dVar15 >> 0x20));
                                param = param_buf;
                              }
                            }
                            else {
                              jVar16 = json_integer_value(pjVar10);
                              sprintf(param_buf,"%d",(int)jVar16);
                              param = param_buf;
                            }
                          }
                          else {
                            param = json_string_value(pjVar10);
                          }
                        }
                      }
                    }
                    else {
                      isjson = false;
                      pcVar7 = strchr(buf,0x7c);
                      param = pcVar7;
                      if (pcVar7 != (char *)0x0) {
                        param = pcVar7 + 1;
                        *pcVar7 = '\0';
                      }
                      cmd = buf;
                    }
                    if (!bVar3) {
                      cmdsbuf = (char *)0x0;
                      pcVar7 = strchr(cmd,0x2b);
                      if (pcVar7 == (char *)0x0) {
                        firstjoin = false;
                      }
                      else {
                        firstjoin = true;
                        sVar11 = strlen(cmd);
                        cmdsbuf = (char *)_cgmalloc(sVar11 + 3,"api-btm.c","api",0x158a);
                        *(undefined2 *)cmdsbuf = DAT_000adb3c;
                        param = (char *)0x0;
                      }
                      isjoin = pcVar7 != (char *)0x0;
                      do {
                        pcVar7 = cmd;
                        bVar3 = false;
                        if (isjoin) {
                          pcVar12 = strchr(cmd,0x2b);
                          cmd = pcVar12;
                          if (pcVar12 != (char *)0x0) {
                            cmd = pcVar12 + 1;
                            *pcVar12 = '\0';
                          }
                          if (*pcVar7 != '\0') goto LAB_000881cc;
                        }
                        else {
LAB_000881cc:
                          for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
                            iVar13 = strcmp(pcVar7,cmds[i].name);
                            if (iVar13 == 0) {
                              sprintf(cmdbuf,"|%s|",pcVar7);
                              if (isjoin) {
                                pcVar12 = strstr(cmdsbuf,cmdbuf);
                                if (pcVar12 != (char *)0x0) {
                                  bVar3 = true;
                                  break;
                                }
                                strcat(cmdsbuf,pcVar7);
                                sVar11 = strlen(cmdsbuf);
                                *(undefined2 *)(cmdsbuf + sVar11) = DAT_000adb3c;
                                head_join(io_data_00,pcVar7,isjson,&firstjoin);
                                if (cmds[i].joinable != true) {
                                  message(io_data_00,0x2d,0,cmds[i].name,isjson);
                                  bVar3 = true;
                                  tail_join(io_data_00,isjson);
                                  break;
                                }
                              }
                              iVar13 = toupper((uint)(byte)group);
                              iVar14 = toupper(0x57);
                              if (iVar13 == iVar14) {
LAB_000883d8:
                                (*cmds[i].func)(io_data_00,iVar5,param,isjson,group);
                              }
                              else {
                                iVar13 = toupper((uint)(byte)group);
                                iVar14 = toupper(0x41);
                                pcVar12 = strstr(apigroups[iVar13 - iVar14].commands,cmdbuf);
                                if (pcVar12 != (char *)0x0) goto LAB_000883d8;
                                message(io_data_00,0x2d,0,cmds[i].name,isjson);
                                if ((opt_debug != false) &&
                                   (((use_syslog != false || (opt_log_output != false)) ||
                                    (6 < opt_log_level)))) {
                                  snprintf(tmp42_15,0x800,
                                           "API: access denied to \'%s\' for \'%s\' command",
                                           connectaddr,cmds[i].name);
                                  _applog(7,tmp42_15,false);
                                }
                              }
                              bVar3 = true;
                              if (isjoin) {
                                tail_join(io_data_00,isjson);
                              }
                              else {
                                send_result(io_data_00,iVar5,isjson);
                              }
                              break;
                            }
                          }
                          if (!bVar3) {
                            if (isjoin) {
                              head_join(io_data_00,pcVar7,isjson,&firstjoin);
                            }
                            message(io_data_00,0xe,0,(char *)0x0,isjson);
                            if (isjoin) {
                              tail_join(io_data_00,isjson);
                            }
                            else {
                              send_result(io_data_00,iVar5,isjson);
                            }
                          }
                        }
                      } while ((isjoin) && (cmd != (char *)0x0));
                    }
                    if (isjoin) {
                      send_result(io_data_00,iVar5,isjson);
                    }
                    if (((isjson != false) && (json_config != (json_t *)0x0)) &&
                       (json_config->type == JSON_OBJECT)) {
                      json_decref(json_config);
                    }
                  }
                }
                close(iVar5);
              }
              __pthread_unregister_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
              tidyup(arg);
              free(arg);
              if (((opt_debug != false) && (opt_debug != false)) &&
                 ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
                if (do_a_quit == false) {
                  if (do_a_restart == false) {
                    if (bye == false) {
                      pcVar7 = "UNKNOWN!";
                    }
                    else {
                      pcVar7 = "BYE";
                    }
                  }
                  else {
                    pcVar7 = "RESTART";
                  }
                }
                else {
                  pcVar7 = "QUIT";
                }
                snprintf(tmp42_16,0x800,"API: terminating due to: %s",pcVar7);
                _applog(7,tmp42_16,false);
              }
              _mutex_lock(&quit_restart_lock,"api-btm.c","api",0x15ed);
              if (do_a_restart == false) {
                if (do_a_quit != false) {
                  iVar5 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,quit_thread,&bye_thr);
                  if (iVar5 != 0) {
                    _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x15fc);
                    tmp42_18[0] = s_API_failed_to_initiate_a_clean_q_000aeda0[0];
                    tmp42_18[1] = s_API_failed_to_initiate_a_clean_q_000aeda0[1];
                    tmp42_18[2] = s_API_failed_to_initiate_a_clean_q_000aeda0[2];
                    tmp42_18[3] = s_API_failed_to_initiate_a_clean_q_000aeda0[3];
                    tmp42_18[4] = s_API_failed_to_initiate_a_clean_q_000aeda0[4];
                    tmp42_18[5] = s_API_failed_to_initiate_a_clean_q_000aeda0[5];
                    tmp42_18[6] = s_API_failed_to_initiate_a_clean_q_000aeda0[6];
                    tmp42_18[7] = s_API_failed_to_initiate_a_clean_q_000aeda0[7];
                    tmp42_18[8] = s_API_failed_to_initiate_a_clean_q_000aeda0[8];
                    tmp42_18[9] = s_API_failed_to_initiate_a_clean_q_000aeda0[9];
                    tmp42_18[10] = s_API_failed_to_initiate_a_clean_q_000aeda0[10];
                    tmp42_18[11] = s_API_failed_to_initiate_a_clean_q_000aeda0[11];
                    tmp42_18[12] = s_API_failed_to_initiate_a_clean_q_000aeda0[12];
                    tmp42_18[13] = s_API_failed_to_initiate_a_clean_q_000aeda0[13];
                    tmp42_18[14] = s_API_failed_to_initiate_a_clean_q_000aeda0[14];
                    tmp42_18[15] = s_API_failed_to_initiate_a_clean_q_000aeda0[15];
                    tmp42_18[16] = s_API_failed_to_initiate_a_clean_q_000aeda0[16];
                    tmp42_18[17] = s_API_failed_to_initiate_a_clean_q_000aeda0[17];
                    tmp42_18[18] = s_API_failed_to_initiate_a_clean_q_000aeda0[18];
                    tmp42_18[19] = s_API_failed_to_initiate_a_clean_q_000aeda0[19];
                    tmp42_18[20] = s_API_failed_to_initiate_a_clean_q_000aeda0[20];
                    tmp42_18[21] = s_API_failed_to_initiate_a_clean_q_000aeda0[21];
                    tmp42_18[22] = s_API_failed_to_initiate_a_clean_q_000aeda0[22];
                    tmp42_18[23] = s_API_failed_to_initiate_a_clean_q_000aeda0[23];
                    tmp42_18[24] = s_API_failed_to_initiate_a_clean_q_000aeda0[24];
                    tmp42_18[25] = s_API_failed_to_initiate_a_clean_q_000aeda0[25];
                    tmp42_18[26] = s_API_failed_to_initiate_a_clean_q_000aeda0[26];
                    tmp42_18[27] = s_API_failed_to_initiate_a_clean_q_000aeda0[27];
                    tmp42_18[28] = s_API_failed_to_initiate_a_clean_q_000aeda0[28];
                    tmp42_18[29] = s_API_failed_to_initiate_a_clean_q_000aeda0[29];
                    tmp42_18[30] = s_API_failed_to_initiate_a_clean_q_000aeda0[30];
                    tmp42_18[31] = s_API_failed_to_initiate_a_clean_q_000aeda0[31];
                    tmp42_18[32] = s_API_failed_to_initiate_a_clean_q_000aeda0[32];
                    tmp42_18[33] = s_API_failed_to_initiate_a_clean_q_000aeda0[33];
                    tmp42_18[34] = s_API_failed_to_initiate_a_clean_q_000aeda0[34];
                    tmp42_18[35] = s_API_failed_to_initiate_a_clean_q_000aeda0[35];
                    tmp42_18[36] = s_API_failed_to_initiate_a_clean_q_000aeda0[36];
                    tmp42_18[37] = s_API_failed_to_initiate_a_clean_q_000aeda0[37];
                    tmp42_18[38] = s_API_failed_to_initiate_a_clean_q_000aeda0[38];
                    tmp42_18[39] = s_API_failed_to_initiate_a_clean_q_000aeda0[39];
                    tmp42_18[40] = s_API_failed_to_initiate_a_clean_q_000aeda0[40];
                    tmp42_18[41] = s_API_failed_to_initiate_a_clean_q_000aeda0[41];
                    tmp42_18[42] = s_API_failed_to_initiate_a_clean_q_000aeda0[42];
                    tmp42_18[43] = s_API_failed_to_initiate_a_clean_q_000aeda0[43];
                    tmp42_18._44_2_ = (undefined2)ram0x000aedcc;
                    tmp42_18[46] = (char)((uint)ram0x000aedcc >> 0x10);
                    _applog(3,tmp42_18,true);
                    _quit(1);
                  }
                  pthread_detach(bye_thr.pth);
                }
              }
              else {
                iVar5 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,restart_thread,&bye_thr);
                if (iVar5 != 0) {
                  _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x15f3);
                  tmp42_17[0] = s_API_failed_to_initiate_a_restart_000aed74[0];
                  tmp42_17[1] = s_API_failed_to_initiate_a_restart_000aed74[1];
                  tmp42_17[2] = s_API_failed_to_initiate_a_restart_000aed74[2];
                  tmp42_17[3] = s_API_failed_to_initiate_a_restart_000aed74[3];
                  tmp42_17[4] = s_API_failed_to_initiate_a_restart_000aed74[4];
                  tmp42_17[5] = s_API_failed_to_initiate_a_restart_000aed74[5];
                  tmp42_17[6] = s_API_failed_to_initiate_a_restart_000aed74[6];
                  tmp42_17[7] = s_API_failed_to_initiate_a_restart_000aed74[7];
                  tmp42_17[8] = s_API_failed_to_initiate_a_restart_000aed74[8];
                  tmp42_17[9] = s_API_failed_to_initiate_a_restart_000aed74[9];
                  tmp42_17[10] = s_API_failed_to_initiate_a_restart_000aed74[10];
                  tmp42_17[11] = s_API_failed_to_initiate_a_restart_000aed74[11];
                  tmp42_17[12] = s_API_failed_to_initiate_a_restart_000aed74[12];
                  tmp42_17[13] = s_API_failed_to_initiate_a_restart_000aed74[13];
                  tmp42_17[14] = s_API_failed_to_initiate_a_restart_000aed74[14];
                  tmp42_17[15] = s_API_failed_to_initiate_a_restart_000aed74[15];
                  tmp42_17[16] = s_API_failed_to_initiate_a_restart_000aed74[16];
                  tmp42_17[17] = s_API_failed_to_initiate_a_restart_000aed74[17];
                  tmp42_17[18] = s_API_failed_to_initiate_a_restart_000aed74[18];
                  tmp42_17[19] = s_API_failed_to_initiate_a_restart_000aed74[19];
                  tmp42_17[20] = s_API_failed_to_initiate_a_restart_000aed74[20];
                  tmp42_17[21] = s_API_failed_to_initiate_a_restart_000aed74[21];
                  tmp42_17[22] = s_API_failed_to_initiate_a_restart_000aed74[22];
                  tmp42_17[23] = s_API_failed_to_initiate_a_restart_000aed74[23];
                  tmp42_17[24] = s_API_failed_to_initiate_a_restart_000aed74[24];
                  tmp42_17[25] = s_API_failed_to_initiate_a_restart_000aed74[25];
                  tmp42_17[26] = s_API_failed_to_initiate_a_restart_000aed74[26];
                  tmp42_17[27] = s_API_failed_to_initiate_a_restart_000aed74[27];
                  tmp42_17[28] = s_API_failed_to_initiate_a_restart_000aed74[28];
                  tmp42_17[29] = s_API_failed_to_initiate_a_restart_000aed74[29];
                  tmp42_17[30] = s_API_failed_to_initiate_a_restart_000aed74[30];
                  tmp42_17[31] = s_API_failed_to_initiate_a_restart_000aed74[31];
                  tmp42_17[32] = s_API_failed_to_initiate_a_restart_000aed74[32];
                  tmp42_17[33] = s_API_failed_to_initiate_a_restart_000aed74[33];
                  tmp42_17[34] = s_API_failed_to_initiate_a_restart_000aed74[34];
                  tmp42_17[35] = s_API_failed_to_initiate_a_restart_000aed74[35];
                  tmp42_17[36] = s_API_failed_to_initiate_a_restart_000aed74[36];
                  tmp42_17[37] = s_API_failed_to_initiate_a_restart_000aed74[37];
                  tmp42_17[38] = s_API_failed_to_initiate_a_restart_000aed74[38];
                  tmp42_17[39] = s_API_failed_to_initiate_a_restart_000aed74[39];
                  tmp42_17[40] = s_API_failed_to_initiate_a_restart_000aed74[40];
                  tmp42_17[41] = s_API_failed_to_initiate_a_restart_000aed74[41];
                  tmp42_17[42] = s_API_failed_to_initiate_a_restart_000aed74[42];
                  tmp42_17[43] = s_API_failed_to_initiate_a_restart_000aed74[43];
                  _applog(3,tmp42_17,true);
                  _quit(1);
                }
                pthread_detach(bye_thr.pth);
              }
              _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x1602);
            }
          }
          else {
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              snprintf(tmp42_6,0x800,"API bind to port %d failed (%s)%s",(int)sVar2,binderror,
                       UNAVAILABLE);
              _applog(3,tmp42_6,false);
            }
            free(arg);
          }
        }
      }
      else {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42_2,0x800,"API failed to resolve %s",opt_api_host);
          _applog(3,tmp42_2,false);
        }
        free(arg);
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42_1,0x800,"API not running (no valid IPs specified)%s",UNAVAILABLE);
        _applog(4,tmp42_1,false);
      }
      free(arg);
    }
  }
  else {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"API not running%s",UNAVAILABLE);
      _applog(7,tmp42,false);
    }
    free(arg);
  }
  return;
}

