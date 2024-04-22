
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
  int iVar11;
  char *pcVar12;
  int iVar13;
  double dVar14;
  json_int_t jVar15;
  int api_thr_id_local;
  __pthread_unwind_buf_t __cancel_buf;
  char tmp42 [2048];
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
  void *__cancel_arg;
  _func_void_void_ptr *__cancel_routine;
  io_data *io_data;
  long *apisock;
  short port;
  char *cmdsbuf;
  char *cmdptr;
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
  
  sVar1 = (short)opt_api_port;
  cmd = (char *)0x0;
  arg = (int *)_cgmalloc(4,"api-btm.c","api",0x1491);
  *arg = -1;
  json_config = (json_t *)0x0;
  isjoin = false;
  if (opt_api_listen == true) {
    io_data_00 = _io_new(0x10000,true);
    _mutex_init(&quit_restart_lock,"api-btm.c","api",0x149f);
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
            snprintf(tmp42,0x800,"API initialisation failed (%s)%s",pcVar6,UNAVAILABLE);
            _applog(3,tmp42,false);
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
            snprintf(tmp42,0x800,"API setsockopt SO_REUSEADDR failed (ignored): %s",pcVar6);
            _applog(7,tmp42,false);
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
                snprintf(tmp42,0x800,"API bind to port %d failed - trying again in 30sec",(int)sVar1
                        );
                _applog(4,tmp42,false);
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
                snprintf(tmp42,0x800,"API3 initialisation failed (%s)%s",pcVar6,UNAVAILABLE);
                _applog(3,tmp42,false);
              }
              close(*arg);
              free(arg);
            }
            else {
              if (opt_api_allow == (char *)0x0) {
                if (opt_api_network == false) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
                    snprintf(tmp42,0x800,"API running in local read access mode on port %d (%d)",
                             (int)sVar1,*arg);
                    _applog(4,tmp42,false);
                  }
                }
                else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)
                        ) {
                  snprintf(tmp42,0x800,
                           "API running in UNRESTRICTED read access mode on port %d (%d)",(int)sVar1
                           ,*arg);
                  _applog(4,tmp42,false);
                }
              }
              else if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level))
              {
                snprintf(tmp42,0x800,"API running in IP access mode on port %d (%d)",(int)sVar1,*arg
                        );
                _applog(4,tmp42,false);
              }
              if (opt_api_mcast != false) {
                mcast_init();
              }
              strbufs = _k_new_list("StrBufs",0xc,2,0,false,"api-btm.c","api",0x150f);
              while (bye != true) {
                clisiz = 0x80;
                iVar4 = accept(*arg,(sockaddr *)&cli,&clisiz);
                if (iVar4 < 0) {
                  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
                    piVar5 = __errno_location();
                    pcVar6 = strerror(*piVar5);
                    snprintf(tmp42,0x800,"API failed (%s)%s (%d)",pcVar6,UNAVAILABLE,*arg);
                    _applog(3,tmp42,false);
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
                  snprintf(tmp42,0x800,"API: connection from %s - %s",connectaddr,pcVar6);
                  _applog(7,tmp42,false);
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
                        snprintf(tmp42,0x800,"API: recv failed: %s",pcVar6);
                        _applog(7,tmp42,false);
                      }
                    }
                    else if ((opt_debug != false) &&
                            (((use_syslog != false || (opt_log_output != false)) ||
                             (6 < opt_log_level)))) {
                      snprintf(tmp42,0x800,"API: recv command: (%d) \'%s\'",buflen,buf);
                      _applog(7,tmp42,false);
                    }
                  }
                  if (-1 < (int)buflen) {
                    when = time((time_t *)0x0);
                    io_reinit(io_data_00);
                    bVar2 = false;
                    if (buf[0] == ISJSON) {
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
                      param = strchr(buf,(uint)(byte)SEPARATOR);
                      if (param != (char *)0x0) {
                        *param = '\0';
                        param = param + 1;
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
                        cmdsbuf = (char *)_cgmalloc(sVar10 + 3,"api-btm.c","api",0x157c);
                        *(undefined2 *)cmdsbuf = DAT_0006d29c;
                        param = (char *)0x0;
                      }
                      isjoin = pcVar6 != (char *)0x0;
                      do {
                        pcVar6 = cmd;
                        bVar2 = false;
                        if (isjoin) {
                          cmd = strchr(cmd,0x2b);
                          if (cmd != (char *)0x0) {
                            *cmd = '\0';
                            cmd = cmd + 1;
                          }
                          if (*pcVar6 != '\0') goto LAB_00014ea6;
                        }
                        else {
LAB_00014ea6:
                          for (i = 0; cmds[i].name != (char *)0x0; i = i + 1) {
                            iVar11 = strcmp(pcVar6,cmds[i].name);
                            if (iVar11 == 0) {
                              sprintf(cmdbuf,"|%s|",pcVar6);
                              if (isjoin) {
                                pcVar12 = strstr(cmdsbuf,cmdbuf);
                                if (pcVar12 != (char *)0x0) {
                                  bVar2 = true;
                                  break;
                                }
                                strcat(cmdsbuf,pcVar6);
                                sVar10 = strlen(cmdsbuf);
                                *(undefined2 *)(cmdsbuf + sVar10) = DAT_0006d29c;
                                head_join(io_data_00,pcVar6,isjson,&firstjoin);
                                if (cmds[i].joinable != true) {
                                  message(io_data_00,0x2d,0,cmds[i].name,isjson);
                                  bVar2 = true;
                                  tail_join(io_data_00,isjson);
                                  break;
                                }
                              }
                              iVar11 = toupper((uint)(byte)group);
                              iVar13 = toupper(0x57);
                              if (iVar11 == iVar13) {
LAB_0001509c:
                                (*cmds[i].func)(io_data_00,iVar4,param,isjson,group);
                              }
                              else {
                                iVar11 = toupper((uint)(byte)group);
                                iVar13 = toupper(0x41);
                                pcVar12 = strstr(apigroups[iVar11 - iVar13].commands,cmdbuf);
                                if (pcVar12 != (char *)0x0) goto LAB_0001509c;
                                message(io_data_00,0x2d,0,cmds[i].name,isjson);
                                if ((opt_debug != false) &&
                                   (((use_syslog != false || (opt_log_output != false)) ||
                                    (6 < opt_log_level)))) {
                                  snprintf(tmp42,0x800,
                                           "API: access denied to \'%s\' for \'%s\' command",
                                           connectaddr,cmds[i].name);
                                  _applog(7,tmp42,false);
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
                snprintf(tmp42,0x800,"API: terminating due to: %s",pcVar6);
                _applog(7,tmp42,false);
              }
              _mutex_lock(&quit_restart_lock,"api-btm.c","api",0x15df);
              if (do_a_restart == false) {
                if (do_a_quit != false) {
                  iVar4 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,quit_thread + 1,&bye_thr);
                  if (iVar4 != 0) {
                    _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x15ee);
                    tmp42[0] = s_API_failed_to_initiate_a_clean_q_0006e524[0];
                    tmp42[1] = s_API_failed_to_initiate_a_clean_q_0006e524[1];
                    tmp42[2] = s_API_failed_to_initiate_a_clean_q_0006e524[2];
                    tmp42[3] = s_API_failed_to_initiate_a_clean_q_0006e524[3];
                    tmp42[4] = s_API_failed_to_initiate_a_clean_q_0006e524[4];
                    tmp42[5] = s_API_failed_to_initiate_a_clean_q_0006e524[5];
                    tmp42[6] = s_API_failed_to_initiate_a_clean_q_0006e524[6];
                    tmp42[7] = s_API_failed_to_initiate_a_clean_q_0006e524[7];
                    tmp42[8] = s_API_failed_to_initiate_a_clean_q_0006e524[8];
                    tmp42[9] = s_API_failed_to_initiate_a_clean_q_0006e524[9];
                    tmp42[10] = s_API_failed_to_initiate_a_clean_q_0006e524[10];
                    tmp42[11] = s_API_failed_to_initiate_a_clean_q_0006e524[11];
                    tmp42[12] = s_API_failed_to_initiate_a_clean_q_0006e524[12];
                    tmp42[13] = s_API_failed_to_initiate_a_clean_q_0006e524[13];
                    tmp42[14] = s_API_failed_to_initiate_a_clean_q_0006e524[14];
                    tmp42[15] = s_API_failed_to_initiate_a_clean_q_0006e524[15];
                    tmp42[16] = s_API_failed_to_initiate_a_clean_q_0006e524[16];
                    tmp42[17] = s_API_failed_to_initiate_a_clean_q_0006e524[17];
                    tmp42[18] = s_API_failed_to_initiate_a_clean_q_0006e524[18];
                    tmp42[19] = s_API_failed_to_initiate_a_clean_q_0006e524[19];
                    tmp42[20] = s_API_failed_to_initiate_a_clean_q_0006e524[20];
                    tmp42[21] = s_API_failed_to_initiate_a_clean_q_0006e524[21];
                    tmp42[22] = s_API_failed_to_initiate_a_clean_q_0006e524[22];
                    tmp42[23] = s_API_failed_to_initiate_a_clean_q_0006e524[23];
                    tmp42[24] = s_API_failed_to_initiate_a_clean_q_0006e524[24];
                    tmp42[25] = s_API_failed_to_initiate_a_clean_q_0006e524[25];
                    tmp42[26] = s_API_failed_to_initiate_a_clean_q_0006e524[26];
                    tmp42[27] = s_API_failed_to_initiate_a_clean_q_0006e524[27];
                    tmp42[28] = s_API_failed_to_initiate_a_clean_q_0006e524[28];
                    tmp42[29] = s_API_failed_to_initiate_a_clean_q_0006e524[29];
                    tmp42[30] = s_API_failed_to_initiate_a_clean_q_0006e524[30];
                    tmp42[31] = s_API_failed_to_initiate_a_clean_q_0006e524[31];
                    tmp42[32] = s_API_failed_to_initiate_a_clean_q_0006e524[32];
                    tmp42[33] = s_API_failed_to_initiate_a_clean_q_0006e524[33];
                    tmp42[34] = s_API_failed_to_initiate_a_clean_q_0006e524[34];
                    tmp42[35] = s_API_failed_to_initiate_a_clean_q_0006e524[35];
                    tmp42[36] = s_API_failed_to_initiate_a_clean_q_0006e524[36];
                    tmp42[37] = s_API_failed_to_initiate_a_clean_q_0006e524[37];
                    tmp42[38] = s_API_failed_to_initiate_a_clean_q_0006e524[38];
                    tmp42[39] = s_API_failed_to_initiate_a_clean_q_0006e524[39];
                    tmp42[40] = s_API_failed_to_initiate_a_clean_q_0006e524[40];
                    tmp42[41] = s_API_failed_to_initiate_a_clean_q_0006e524[41];
                    tmp42[42] = s_API_failed_to_initiate_a_clean_q_0006e524[42];
                    tmp42[43] = s_API_failed_to_initiate_a_clean_q_0006e524[43];
                    tmp42._44_2_ = (undefined2)ram0x0006e550;
                    tmp42[46] = (char)((uint)ram0x0006e550 >> 0x10);
                    _applog(3,tmp42,true);
                    _quit(1);
                  }
                  pthread_detach(bye_thr.pth);
                }
              }
              else {
                iVar4 = thr_info_create(&bye_thr,(pthread_attr_t *)0x0,restart_thread + 1,&bye_thr);
                if (iVar4 != 0) {
                  _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x15e5);
                  tmp42[0] = s_API_failed_to_initiate_a_restart_0006e4f8[0];
                  tmp42[1] = s_API_failed_to_initiate_a_restart_0006e4f8[1];
                  tmp42[2] = s_API_failed_to_initiate_a_restart_0006e4f8[2];
                  tmp42[3] = s_API_failed_to_initiate_a_restart_0006e4f8[3];
                  tmp42[4] = s_API_failed_to_initiate_a_restart_0006e4f8[4];
                  tmp42[5] = s_API_failed_to_initiate_a_restart_0006e4f8[5];
                  tmp42[6] = s_API_failed_to_initiate_a_restart_0006e4f8[6];
                  tmp42[7] = s_API_failed_to_initiate_a_restart_0006e4f8[7];
                  tmp42[8] = s_API_failed_to_initiate_a_restart_0006e4f8[8];
                  tmp42[9] = s_API_failed_to_initiate_a_restart_0006e4f8[9];
                  tmp42[10] = s_API_failed_to_initiate_a_restart_0006e4f8[10];
                  tmp42[11] = s_API_failed_to_initiate_a_restart_0006e4f8[11];
                  tmp42[12] = s_API_failed_to_initiate_a_restart_0006e4f8[12];
                  tmp42[13] = s_API_failed_to_initiate_a_restart_0006e4f8[13];
                  tmp42[14] = s_API_failed_to_initiate_a_restart_0006e4f8[14];
                  tmp42[15] = s_API_failed_to_initiate_a_restart_0006e4f8[15];
                  tmp42[16] = s_API_failed_to_initiate_a_restart_0006e4f8[16];
                  tmp42[17] = s_API_failed_to_initiate_a_restart_0006e4f8[17];
                  tmp42[18] = s_API_failed_to_initiate_a_restart_0006e4f8[18];
                  tmp42[19] = s_API_failed_to_initiate_a_restart_0006e4f8[19];
                  tmp42[20] = s_API_failed_to_initiate_a_restart_0006e4f8[20];
                  tmp42[21] = s_API_failed_to_initiate_a_restart_0006e4f8[21];
                  tmp42[22] = s_API_failed_to_initiate_a_restart_0006e4f8[22];
                  tmp42[23] = s_API_failed_to_initiate_a_restart_0006e4f8[23];
                  tmp42[24] = s_API_failed_to_initiate_a_restart_0006e4f8[24];
                  tmp42[25] = s_API_failed_to_initiate_a_restart_0006e4f8[25];
                  tmp42[26] = s_API_failed_to_initiate_a_restart_0006e4f8[26];
                  tmp42[27] = s_API_failed_to_initiate_a_restart_0006e4f8[27];
                  tmp42[28] = s_API_failed_to_initiate_a_restart_0006e4f8[28];
                  tmp42[29] = s_API_failed_to_initiate_a_restart_0006e4f8[29];
                  tmp42[30] = s_API_failed_to_initiate_a_restart_0006e4f8[30];
                  tmp42[31] = s_API_failed_to_initiate_a_restart_0006e4f8[31];
                  tmp42[32] = s_API_failed_to_initiate_a_restart_0006e4f8[32];
                  tmp42[33] = s_API_failed_to_initiate_a_restart_0006e4f8[33];
                  tmp42[34] = s_API_failed_to_initiate_a_restart_0006e4f8[34];
                  tmp42[35] = s_API_failed_to_initiate_a_restart_0006e4f8[35];
                  tmp42[36] = s_API_failed_to_initiate_a_restart_0006e4f8[36];
                  tmp42[37] = s_API_failed_to_initiate_a_restart_0006e4f8[37];
                  tmp42[38] = s_API_failed_to_initiate_a_restart_0006e4f8[38];
                  tmp42[39] = s_API_failed_to_initiate_a_restart_0006e4f8[39];
                  tmp42[40] = s_API_failed_to_initiate_a_restart_0006e4f8[40];
                  tmp42[41] = s_API_failed_to_initiate_a_restart_0006e4f8[41];
                  tmp42[42] = s_API_failed_to_initiate_a_restart_0006e4f8[42];
                  tmp42[43] = s_API_failed_to_initiate_a_restart_0006e4f8[43];
                  _applog(3,tmp42,true);
                  _quit(1);
                }
                pthread_detach(bye_thr.pth);
              }
              _mutex_unlock(&quit_restart_lock,"api-btm.c","api",0x15f4);
            }
          }
          else {
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              snprintf(tmp42,0x800,"API bind to port %d failed (%s)%s",(int)sVar1,binderror,
                       UNAVAILABLE);
              _applog(3,tmp42,false);
            }
            free(arg);
          }
        }
      }
      else {
        if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
          snprintf(tmp42,0x800,"API failed to resolve %s",opt_api_host);
          _applog(3,tmp42,false);
        }
        free(arg);
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (3 < opt_log_level)) {
        snprintf(tmp42,0x800,"API not running (no valid IPs specified)%s",UNAVAILABLE);
        _applog(4,tmp42,false);
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

