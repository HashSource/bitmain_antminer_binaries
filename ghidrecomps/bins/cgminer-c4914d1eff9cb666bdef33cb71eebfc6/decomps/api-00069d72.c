
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void api(int api_thr_id)

{
  short sVar1;
  bool bVar2;
  _Bool _Var3;
  int *arg;
  io_data *io_data_00;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  time_t tVar7;
  time_t tVar8;
  size_t buflen;
  json_t *pjVar9;
  size_t sVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  double dVar14;
  json_int_t jVar15;
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
  
  sVar1 = (short)opt_api_port;
  cmd = (char *)0x0;
  arg = (int *)_cgmalloc(4,"api-btm.c","api",0x14a1);
  *arg = -1;
  json_config = (json_t *)0x0;
  isjoin = false;
  if (opt_api_listen == true) {
    io_data_00 = _io_new(0x10000,true);
    _mutex_init(&quit_restart_lock,"api-btm.c","api",0x14af);
    iVar4 = __sigsetjmp(&__cancel_buf,0);
    if (iVar4 != 0) {
      tidyup(arg);
      __pthread_unwind_next((__pthread_unwind_buf_t *)&__cancel_buf);
    }
    __pthread_register_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
    my_thr_id = api_thr_id;
    setup_groups();
    if ((opt_api_allow == (char *)0x0) || (setup_ipaccess(), ips != 0)) {
      cgsleep_ms(opt_log_interval * 1000);
      sprintf(port_s,"%d",(int)sVar1);
      memset(&hints,0,0x20);
      hints.ai_flags = 1;
      hints.ai_family = 0;
      iVar4 = getaddrinfo(opt_api_host,port_s,(addrinfo *)&hints,(addrinfo **)&res);
      if (iVar4 == 0) {
        for (host = res; host != (addrinfo *)0x0; host = host->ai_next) {
          iVar4 = socket(res->ai_family,1,0);
          *arg = iVar4;
          if (0 < *arg) break;
        }
        if (*arg == -1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
            piVar5 = __errno_location();
            pcVar6 = strerror(*piVar5);
            snprintf(tmp42_3,0x800,"API initialisation failed (%s)%s",pcVar6,UNAVAILABLE);
            _applog(3,tmp42_3,false);
          }
          freeaddrinfo((addrinfo *)res);
          free(arg);
        }
        else {
          optval = 1;
          iVar4 = setsockopt(*arg,1,2,&optval,4);
          if (((iVar4 < 0) && (opt_debug != false)) &&
             ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
            piVar5 = __errno_location();
            pcVar6 = strerror(*piVar5);
            snprintf(tmp42_4,0x800,"API setsockopt SO_REUSEADDR failed (ignored): %s",pcVar6);
            _applog(7,tmp42_4,false);
          }
          bVar2 = false;
          tVar7 = time((time_t *)0x0);
          while (!bVar2) {
            iVar4 = bind(*arg,(sockaddr *)host->ai_addr,host->ai_addrlen);
            if (iVar4 < 0) {
              piVar5 = __errno_location();
              binderror = strerror(*piVar5);
              tVar8 = time((time_t *)0x0);
              if (0x3d < tVar8 - tVar7) break;
              if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                snprintf(tmp42_5,0x800,"API bind to port %d failed - trying again in 30sec",
                         (int)sVar1);
                _applog(4,tmp42_5,false);
              }
              cgsleep_ms(30000);
            }
            else {
              bVar2 = true;
            }
          }
          freeaddrinfo((addrinfo *)res);
          if (bVar2) {
            iVar4 = listen(*arg,100);
            if (iVar4 < 0) {
              if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                piVar5 = __errno_location();
                pcVar6 = strerror(*piVar5);
                snprintf(tmp42_7,0x800,"API3 initialisation failed (%s)%s",pcVar6,UNAVAILABLE);
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
                             (int)sVar1,*arg);
                    _applog(4,tmp42_10,false);
                  }
                }
                else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)
                        ) {
                  snprintf(tmp42_9,0x800,
                           "API running in UNRESTRICTED read access mode on port %d (%d)",(int)sVar1
                           ,*arg);
                  _applog(4,tmp42_9,false);
                }
              }
              else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level))
              {
                snprintf(tmp42_8,0x800,"API running in IP access mode on port %d (%d)",(int)sVar1,
                         *arg);
                _applog(4,tmp42_8,false);
              }
              if (opt_api_mcast != false) {
                mcast_init();
              }
              strbufs = _k_new_list("StrBufs",0xc,2,0,false,"api-btm.c","api",0x151f);
              while (bye != true) {
                clisiz = 0x80;
                iVar4 = accept(*arg,(sockaddr *)&cli,&clisiz);
                if (iVar4 < 0) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    piVar5 = __errno_location();
                    pcVar6 = strerror(*piVar5);
                    snprintf(tmp42_11,0x800,"API failed (%s)%s (%d)",pcVar6,UNAVAILABLE,*arg);
                    _applog(3,tmp42_11,false);
                  }
                  break;
                }
                _Var3 = check_connect(&cli,&connectaddr,&group);
                if ((opt_debug != false) &&
                   (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                  if (_Var3) {
                    pcVar6 = "Accepted";
                  }
                  else {
                    pcVar6 = "Ignored";
                  }
                  snprintf(tmp42_12,0x800,"API: connection from %s - %s",connectaddr,pcVar6);
                  _applog(7,tmp42_12,false);
                }
                if (_Var3) {
                  buflen = recv(iVar4,buf,0x1fff,0);
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
                        piVar5 = __errno_location();
                        pcVar6 = strerror(*piVar5);
                        snprintf(tmp42_13,0x800,"API: recv failed: %s",pcVar6);
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
                    bVar2 = false;
                    if (buf[0] == '{') {
                      isjson = true;
                      param = (char *)0x0;
                      json_config = json_loadb(buf,buflen,0,&json_err);
                      if ((json_config == (json_t *)0x0) || (json_config->type != JSON_OBJECT)) {
                        message(io_data_00,0x17,0,(char *)0x0,true);
                        send_result(io_data_00,iVar4,true);
                        bVar2 = true;
                      }
                      else {
                        pjVar9 = json_object_get(json_config,JSON_COMMAND);
                        if (pjVar9 == (json_t *)0x0) {
                          message(io_data_00,0x18,0,(char *)0x0,true);
                          send_result(io_data_00,iVar4,true);
                          bVar2 = true;
                        }
                        else if ((pjVar9 == (json_t *)0x0) || (pjVar9->type != JSON_STRING)) {
                          message(io_data_00,0xe,0,(char *)0x0,true);
                          send_result(io_data_00,iVar4,true);
                          bVar2 = true;
                        }
                        else {
                          cmd = json_string_value(pjVar9);
                          pjVar9 = json_object_get(json_config,JSON_PARAMETER);
                          if ((pjVar9 == (json_t *)0x0) || (pjVar9->type != JSON_STRING)) {
                            if ((pjVar9 == (json_t *)0x0) || (pjVar9->type != JSON_INTEGER)) {
                              if ((pjVar9 != (json_t *)0x0) && (pjVar9->type == JSON_REAL)) {
                                dVar14 = json_real_value(pjVar9);
                                sprintf(param_buf,"%f",SUB84(dVar14,0),
                                        (int)((ulonglong)dVar14 >> 0x20));
                                param = param_buf;
                              }
                            }
                            else {
                              jVar15 = json_integer_value(pjVar9);
                              sprintf(param_buf,"%d",(int)jVar15);
                              param = param_buf;
                            }
                          }
                          else {
                            param = json_string_value(pjVar9);
                          }
                        }
                      }
                    }
                    else {
                      isjson = false;
                      pcVar6 = strchr(buf,0x7c);
                      param = pcVar6;
                      if (pcVar6 != (char *)0x0) {
                        param = pcVar6 + 1;
                        *pcVar6 = '\0';
                      }
                      cmd = buf;
                    }
                    if (!bVar2) {
                      cmdsbuf = (char *)0x0;
                      pcVar6 = strchr(cmd,0x2b);
                      if (pcVar6 == (char *)0x0) {
                        firstjoin = false;
                      }
                      else {
                        firstjoin = true;
                        sVar10 = strlen(cmd);
                        cmdsbuf = (char *)_cgmalloc(sVar10 + 3,"api-btm.c","api",0x158c);
                        *(undefined2 *)cmdsbuf = DAT_00092f08;
                        param = (char *)0x0;
                      }
                      isjoin = pcVar6 != (char *)0x0;
                      do {
                        pcVar6 = cmd;
                        bVar2 = false;
                        if (isjoin) {
                          pcVar11 = strchr(cmd,0x2b);
                          cmd = pcVar11;
                          if (pcVar11 != (char *)0x0) {
                            cmd = pcVar11 + 1;
                            *pcVar11 = '\0';
                          }
                          if (*pcVar6 != '\0') goto LAB_0006af0e;
                        }
                        else {
LAB_0006af0e:
                          for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
                            iVar12 = strcmp(pcVar6,cmds[i].name);
                            if (iVar12 == 0) {
                              sprintf(cmdbuf,"|%s|",pcVar6);
                              if (isjoin) {
                                pcVar11 = strstr(cmdsbuf,cmdbuf);
                                if (pcVar11 != (char *)0x0) {
                                  bVar2 = true;
                                  break;
                                }
                                strcat(cmdsbuf,pcVar6);
                                sVar10 = strlen(cmdsbuf);
                                *(undefined2 *)(cmdsbuf + sVar10) = DAT_00092f08;
                                head_join(io_data_00,pcVar6,isjson,&firstjoin);
                                if (cmds[i].joinable != true) {
                                  message(io_data_00,0x2d,0,cmds[i].name,isjson);
                                  bVar2 = true;
                                  tail_join(io_data_00,isjson);
                                  break;
                                }
                              }
                              iVar12 = toupper((uint)(byte)group);
                              iVar13 = toupper(0x57);
                              if (iVar12 == iVar13) {
LAB_0006b112:
                                (*cmds[i].func)(io_data_00,iVar4,param,isjson,group);
                              }
                              else {
                                iVar12 = toupper((uint)(byte)group);
                                iVar13 = toupper(0x41);
                                pcVar11 = strstr(apigroups[iVar12 - iVar13].commands,cmdbuf);
                                if (pcVar11 != (char *)0x0) goto LAB_0006b112;
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
                              bVar2 = true;
                              if (isjoin) {
                                tail_join(io_data_00,isjson);
                              }
                              else {
                                send_result(io_data_00,iVar4,isjson);
                              }
                              break;
                            }
                          }
                          if (!bVar2) {
                            if (isjoin) {
                              head_join(io_data_00,pcVar6,isjson,&firstjoin);
                            }
                            message(io_data_00,0xe,0,(char *)0x0,isjson);
                            if (isjoin) {
                              tail_join(io_data_00,isjson);
                            }
                            else {
                              send_result(io_data_00,iVar4,isjson);
                            }
                          }
                        }
                      } while ((isjoin) && (cmd != (char *)0x0));
                    }
                    if (isjoin) {
                      send_result(io_data_00,iVar4,isjson);
                    }
                    if (((isjson != false) && (json_config != (json_t *)0x0)) &&
                       (json_config->type == JSON_OBJECT)) {
                      json_decref(json_config);
                    }
                  }
                }
                close(iVar4);
              }
              __pthread_unregister_cancel((__pthread_unwind_buf_t *)&__cancel_buf);
              tidyup(arg);
              free(arg);
              if (((opt_debug != false) && (opt_debug != false)) &&
                 ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
                if (do_a_quit == false) {
                  if (do_a_restart == false) {
                    if (bye == false) {
                      pcVar6 = "UNKNOWN!";
                    }
                    else {
                      pcVar6 = "BYE";
                    }
                  }
                  else {
                    pcVar6 = "RESTART";
                  }
                }
                else {
                  pcVar6 = "QUIT";
                }
                snprintf(tmp42_16,0x800,"API: terminating due to: %s",pcVar6);
                _applog(7,tmp42_16,false);
              }
              _mutex_lock(&quit_restart_lock,"api-btm.c","api",0x15ef);
              if (do_a_restart == false) {
                if (do_a_quit != false) {
                  iVar4 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,quit_thread + 1,&bye_thr);
                  if (iVar4 != 0) {
                    _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x15fe);
                    tmp42_18[0] = s_API_failed_to_initiate_a_clean_q_000941a0[0];
                    tmp42_18[1] = s_API_failed_to_initiate_a_clean_q_000941a0[1];
                    tmp42_18[2] = s_API_failed_to_initiate_a_clean_q_000941a0[2];
                    tmp42_18[3] = s_API_failed_to_initiate_a_clean_q_000941a0[3];
                    tmp42_18[4] = s_API_failed_to_initiate_a_clean_q_000941a0[4];
                    tmp42_18[5] = s_API_failed_to_initiate_a_clean_q_000941a0[5];
                    tmp42_18[6] = s_API_failed_to_initiate_a_clean_q_000941a0[6];
                    tmp42_18[7] = s_API_failed_to_initiate_a_clean_q_000941a0[7];
                    tmp42_18[8] = s_API_failed_to_initiate_a_clean_q_000941a0[8];
                    tmp42_18[9] = s_API_failed_to_initiate_a_clean_q_000941a0[9];
                    tmp42_18[10] = s_API_failed_to_initiate_a_clean_q_000941a0[10];
                    tmp42_18[11] = s_API_failed_to_initiate_a_clean_q_000941a0[11];
                    tmp42_18[12] = s_API_failed_to_initiate_a_clean_q_000941a0[12];
                    tmp42_18[13] = s_API_failed_to_initiate_a_clean_q_000941a0[13];
                    tmp42_18[14] = s_API_failed_to_initiate_a_clean_q_000941a0[14];
                    tmp42_18[15] = s_API_failed_to_initiate_a_clean_q_000941a0[15];
                    tmp42_18[16] = s_API_failed_to_initiate_a_clean_q_000941a0[16];
                    tmp42_18[17] = s_API_failed_to_initiate_a_clean_q_000941a0[17];
                    tmp42_18[18] = s_API_failed_to_initiate_a_clean_q_000941a0[18];
                    tmp42_18[19] = s_API_failed_to_initiate_a_clean_q_000941a0[19];
                    tmp42_18[20] = s_API_failed_to_initiate_a_clean_q_000941a0[20];
                    tmp42_18[21] = s_API_failed_to_initiate_a_clean_q_000941a0[21];
                    tmp42_18[22] = s_API_failed_to_initiate_a_clean_q_000941a0[22];
                    tmp42_18[23] = s_API_failed_to_initiate_a_clean_q_000941a0[23];
                    tmp42_18[24] = s_API_failed_to_initiate_a_clean_q_000941a0[24];
                    tmp42_18[25] = s_API_failed_to_initiate_a_clean_q_000941a0[25];
                    tmp42_18[26] = s_API_failed_to_initiate_a_clean_q_000941a0[26];
                    tmp42_18[27] = s_API_failed_to_initiate_a_clean_q_000941a0[27];
                    tmp42_18[28] = s_API_failed_to_initiate_a_clean_q_000941a0[28];
                    tmp42_18[29] = s_API_failed_to_initiate_a_clean_q_000941a0[29];
                    tmp42_18[30] = s_API_failed_to_initiate_a_clean_q_000941a0[30];
                    tmp42_18[31] = s_API_failed_to_initiate_a_clean_q_000941a0[31];
                    tmp42_18[32] = s_API_failed_to_initiate_a_clean_q_000941a0[32];
                    tmp42_18[33] = s_API_failed_to_initiate_a_clean_q_000941a0[33];
                    tmp42_18[34] = s_API_failed_to_initiate_a_clean_q_000941a0[34];
                    tmp42_18[35] = s_API_failed_to_initiate_a_clean_q_000941a0[35];
                    tmp42_18[36] = s_API_failed_to_initiate_a_clean_q_000941a0[36];
                    tmp42_18[37] = s_API_failed_to_initiate_a_clean_q_000941a0[37];
                    tmp42_18[38] = s_API_failed_to_initiate_a_clean_q_000941a0[38];
                    tmp42_18[39] = s_API_failed_to_initiate_a_clean_q_000941a0[39];
                    tmp42_18[40] = s_API_failed_to_initiate_a_clean_q_000941a0[40];
                    tmp42_18[41] = s_API_failed_to_initiate_a_clean_q_000941a0[41];
                    tmp42_18[42] = s_API_failed_to_initiate_a_clean_q_000941a0[42];
                    tmp42_18[43] = s_API_failed_to_initiate_a_clean_q_000941a0[43];
                    tmp42_18._44_2_ = (undefined2)ram0x000941cc;
                    tmp42_18[46] = (char)((uint)ram0x000941cc >> 0x10);
                    _applog(3,tmp42_18,true);
                    _quit(1);
                  }
                  pthread_detach(bye_thr.pth);
                }
              }
              else {
                iVar4 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,restart_thread + 1,&bye_thr);
                if (iVar4 != 0) {
                  _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x15f5);
                  tmp42_17[0] = s_API_failed_to_initiate_a_restart_00094174[0];
                  tmp42_17[1] = s_API_failed_to_initiate_a_restart_00094174[1];
                  tmp42_17[2] = s_API_failed_to_initiate_a_restart_00094174[2];
                  tmp42_17[3] = s_API_failed_to_initiate_a_restart_00094174[3];
                  tmp42_17[4] = s_API_failed_to_initiate_a_restart_00094174[4];
                  tmp42_17[5] = s_API_failed_to_initiate_a_restart_00094174[5];
                  tmp42_17[6] = s_API_failed_to_initiate_a_restart_00094174[6];
                  tmp42_17[7] = s_API_failed_to_initiate_a_restart_00094174[7];
                  tmp42_17[8] = s_API_failed_to_initiate_a_restart_00094174[8];
                  tmp42_17[9] = s_API_failed_to_initiate_a_restart_00094174[9];
                  tmp42_17[10] = s_API_failed_to_initiate_a_restart_00094174[10];
                  tmp42_17[11] = s_API_failed_to_initiate_a_restart_00094174[11];
                  tmp42_17[12] = s_API_failed_to_initiate_a_restart_00094174[12];
                  tmp42_17[13] = s_API_failed_to_initiate_a_restart_00094174[13];
                  tmp42_17[14] = s_API_failed_to_initiate_a_restart_00094174[14];
                  tmp42_17[15] = s_API_failed_to_initiate_a_restart_00094174[15];
                  tmp42_17[16] = s_API_failed_to_initiate_a_restart_00094174[16];
                  tmp42_17[17] = s_API_failed_to_initiate_a_restart_00094174[17];
                  tmp42_17[18] = s_API_failed_to_initiate_a_restart_00094174[18];
                  tmp42_17[19] = s_API_failed_to_initiate_a_restart_00094174[19];
                  tmp42_17[20] = s_API_failed_to_initiate_a_restart_00094174[20];
                  tmp42_17[21] = s_API_failed_to_initiate_a_restart_00094174[21];
                  tmp42_17[22] = s_API_failed_to_initiate_a_restart_00094174[22];
                  tmp42_17[23] = s_API_failed_to_initiate_a_restart_00094174[23];
                  tmp42_17[24] = s_API_failed_to_initiate_a_restart_00094174[24];
                  tmp42_17[25] = s_API_failed_to_initiate_a_restart_00094174[25];
                  tmp42_17[26] = s_API_failed_to_initiate_a_restart_00094174[26];
                  tmp42_17[27] = s_API_failed_to_initiate_a_restart_00094174[27];
                  tmp42_17[28] = s_API_failed_to_initiate_a_restart_00094174[28];
                  tmp42_17[29] = s_API_failed_to_initiate_a_restart_00094174[29];
                  tmp42_17[30] = s_API_failed_to_initiate_a_restart_00094174[30];
                  tmp42_17[31] = s_API_failed_to_initiate_a_restart_00094174[31];
                  tmp42_17[32] = s_API_failed_to_initiate_a_restart_00094174[32];
                  tmp42_17[33] = s_API_failed_to_initiate_a_restart_00094174[33];
                  tmp42_17[34] = s_API_failed_to_initiate_a_restart_00094174[34];
                  tmp42_17[35] = s_API_failed_to_initiate_a_restart_00094174[35];
                  tmp42_17[36] = s_API_failed_to_initiate_a_restart_00094174[36];
                  tmp42_17[37] = s_API_failed_to_initiate_a_restart_00094174[37];
                  tmp42_17[38] = s_API_failed_to_initiate_a_restart_00094174[38];
                  tmp42_17[39] = s_API_failed_to_initiate_a_restart_00094174[39];
                  tmp42_17[40] = s_API_failed_to_initiate_a_restart_00094174[40];
                  tmp42_17[41] = s_API_failed_to_initiate_a_restart_00094174[41];
                  tmp42_17[42] = s_API_failed_to_initiate_a_restart_00094174[42];
                  tmp42_17[43] = s_API_failed_to_initiate_a_restart_00094174[43];
                  _applog(3,tmp42_17,true);
                  _quit(1);
                }
                pthread_detach(bye_thr.pth);
              }
              _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x1604);
            }
          }
          else {
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              snprintf(tmp42_6,0x800,"API bind to port %d failed (%s)%s",(int)sVar1,binderror,
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

