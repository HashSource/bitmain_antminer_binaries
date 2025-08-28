
int Curl_proxyCONNECT(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined *puVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  char *pcVar14;
  uint uVar15;
  undefined1 *puVar16;
  char *pcVar17;
  undefined *puVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  int in_r12;
  undefined8 local_68;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  int local_2c [2];
  char *pcVar18;
  
  iVar12 = param_2 + 0x11a;
  iVar11 = param_1[iVar12];
  iVar23 = *param_1;
  iVar3 = param_1[param_2 + 0x55];
  if (iVar11 == 2) {
    in_r12 = 0;
  }
  local_34 = 0;
  if (iVar11 != 2) {
    local_44 = 0;
    local_68 = 0;
    *(undefined1 *)((int)param_1 + 0x202) = 0;
LAB_00053b42:
    if (iVar11 == 0) {
      Curl_infof(iVar23,"Establish HTTP proxy tunnel to %s:%hu\n",param_3,param_4);
      (*Curl_cfree)(*(undefined4 *)(iVar23 + 0x13c));
      *(undefined4 *)(iVar23 + 0x13c) = 0;
      iVar11 = Curl_add_buffer_init();
      if (iVar11 == 0) {
        return 0x1b;
      }
      iVar4 = curl_maprintf("%s:%hu",param_3,param_4);
      if (iVar4 == 0) {
LAB_000541fc:
        Curl_add_buffer_free(iVar11);
        return 0x1b;
      }
      iVar5 = Curl_http_output_auth(param_1,"CONNECT",iVar4,1);
      (*Curl_cfree)(iVar4);
      if (iVar5 != 0) {
        Curl_add_buffer_free(iVar11);
        return iVar5;
      }
      if (param_1[0x4e] == 1) {
        puVar19 = &DAT_0013ac2c;
      }
      else {
        puVar19 = &DAT_0013ac24;
      }
      if (*(char *)((int)param_1 + 499) == '\0') {
        puVar6 = &DAT_0013a6fc;
        puVar9 = &DAT_0013a6fc;
      }
      else {
        puVar6 = &DAT_00135eb4;
        puVar9 = &DAT_00135988;
      }
      iVar4 = curl_maprintf(&DAT_00139ffc,puVar6,param_3,puVar9,param_4);
      if (iVar4 == 0) goto LAB_000541fc;
      iVar5 = Curl_checkProxyheaders(param_1,"Host:");
      pcVar13 = "";
      if ((iVar5 == 0) &&
         (pcVar13 = (char *)curl_maprintf("Host: %s\r\n",iVar4), pcVar13 == (char *)0x0)) {
        (*Curl_cfree)(iVar4);
        Curl_add_buffer_free(iVar11);
        return 0x1b;
      }
      iVar5 = Curl_checkProxyheaders(param_1,"User-Agent:");
      if ((iVar5 == 0) && (*(int *)(iVar23 + 0x3a8) != 0)) {
        puVar8 = (undefined1 *)param_1[0x8c];
      }
      else {
        puVar8 = &DAT_0013a6fc;
      }
      puVar16 = (undefined1 *)param_1[0x8b];
      if (puVar16 == (undefined1 *)0x0) {
        puVar16 = &DAT_0013a6fc;
      }
      iVar5 = Curl_add_bufferf(iVar11,"CONNECT %s HTTP/%s\r\n%s%s%s",iVar4,puVar19,pcVar13,puVar16,
                               puVar8);
      if (*pcVar13 != '\0') {
        (*Curl_cfree)(pcVar13);
      }
      (*Curl_cfree)(iVar4);
      if ((((iVar5 != 0) || (iVar5 = Curl_add_custom_headers(param_1,1,iVar11), iVar5 != 0)) ||
          (iVar5 = Curl_add_bufferf(iVar11,&DAT_0013c1d4), iVar5 != 0)) ||
         (iVar5 = Curl_add_buffer_send(iVar11,param_1,iVar23 + 0x870c,0,param_2), iVar5 != 0)) {
        Curl_failf(iVar23,"Failed sending CONNECT to proxy");
        Curl_add_buffer_free(0);
        return iVar5;
      }
      Curl_add_buffer_free();
      param_1[iVar12] = 1;
    }
    iVar11 = Curl_timeleft(iVar23,0,1);
    if (iVar11 < 1) {
LAB_00054002:
      Curl_failf(iVar23,"Proxy CONNECT aborted due to timeout");
      return 0x38;
    }
    if ((param_5 == '\0') &&
       (iVar11 = Curl_socket_check(iVar3,0xffffffff,0xffffffff,0), iVar11 == 0)) {
      return 0;
    }
    pcVar14 = (char *)(iVar23 + 0x59c);
    iVar11 = 0;
    uVar21 = 0;
    uVar15 = 0;
    bVar2 = false;
    uVar20 = 1;
    pcVar13 = pcVar14;
    pcVar17 = pcVar14;
    do {
      while( true ) {
        uVar10 = uVar21 ^ 1;
        if (uVar20 == 0) {
          uVar10 = 0;
        }
        uVar22 = uVar21;
        if (uVar10 == 0) goto LAB_00053dde;
        iVar4 = Curl_timeleft(iVar23,0,1);
        if (iVar4 < 1) goto LAB_00054002;
        if (999 < iVar4) {
          iVar4 = 1000;
        }
        iVar4 = Curl_socket_check(iVar3,0xffffffff,0xffffffff,iVar4);
        if (iVar4 != -1) break;
        Curl_failf(iVar23,"Proxy CONNECT aborted due to select/poll error");
        uVar21 = 1;
LAB_00053cd0:
        iVar4 = Curl_pgrsUpdate(param_1);
joined_r0x00053d7e:
        if (iVar4 != 0) {
          return 0x2a;
        }
        uVar22 = uVar21;
        if (0x3fff < uVar15) goto LAB_00053dde;
      }
      if (iVar4 == 0) {
LAB_00053ccc:
        uVar21 = 0;
        goto LAB_00053cd0;
      }
      iVar4 = Curl_read(param_1,iVar3,pcVar17,0x4000 - uVar15,&local_30);
      if (iVar4 != 0x51) {
        if (iVar4 != 0) {
          uVar20 = 0;
          uVar21 = 0;
          goto LAB_00053cd0;
        }
        if ((int)local_30 < 1) {
          if ((*(int *)(iVar23 + 0x178) == 0) || (*(int *)(iVar23 + 0x8638) == 0)) {
            Curl_failf(iVar23,"Proxy CONNECT aborted");
            uVar20 = 0;
            uVar21 = 1;
          }
          else {
            *(undefined1 *)((int)param_1 + 0x202) = 1;
            Curl_infof(iVar23,"Proxy CONNECT connection closed\n");
            uVar20 = 0;
            uVar21 = 0;
          }
          goto LAB_00053cd0;
        }
        uVar15 = uVar15 + local_30;
        if (uVar20 < 2) {
          uVar21 = 0;
          uVar10 = local_30;
          pcVar18 = pcVar17;
          do {
            while( true ) {
              pcVar17 = pcVar18 + 1;
              iVar11 = iVar11 + 1;
              if (*pcVar18 != '\n') break;
              if (*(char *)(iVar23 + 0x310) != '\0') {
                Curl_debug(iVar23,1,pcVar13,iVar11,param_1);
              }
              if (*(char *)(iVar23 + 0x304) == '\0') {
                uVar7 = 2;
              }
              else {
                uVar7 = 3;
              }
              iVar4 = Curl_client_write(param_1,uVar7,pcVar13,iVar11);
              *(int *)(iVar23 + 0x80) = *(int *)(iVar23 + 0x80) + iVar11;
              *(int *)(iVar23 + 0x8708) = *(int *)(iVar23 + 0x8708) + iVar11;
              if (iVar4 != 0) {
                return iVar4;
              }
              if (*pcVar13 == '\r' || *pcVar13 == '\n') {
                if ((*(int *)(iVar23 + 200) == 0x197) && (*(char *)(iVar23 + 0x8640) == '\0')) {
                  if (local_68._4_4_ == 0 && (uint)local_68 == 0) {
                    uVar20 = local_44;
                    if (local_44 != 0) {
                      *(undefined1 *)(iVar23 + 0x135) = 1;
                      Curl_infof(iVar23,"%zd bytes of chunk left\n",local_30 - uVar21);
                      if (pcVar13[1] == '\n') {
                        pcVar13 = pcVar13 + 1;
                        uVar21 = uVar21 + 1;
                      }
                      iVar4 = Curl_httpchunk_read(param_1,pcVar13 + 1,local_30 - uVar21,&local_30);
                      if (iVar4 == -1) {
                        uVar20 = 0;
                        Curl_infof(iVar23,"chunk reading DONE\n");
                        local_68 = 0;
                      }
                      else {
                        Curl_infof(iVar23,"Read %zd bytes of chunk, continue\n",local_30);
                        uVar20 = 2;
                        local_68 = 0;
                      }
                    }
                  }
                  else {
                    Curl_infof(iVar23,"Ignore %lld bytes of response-body\n",(uint)local_68,
                               local_68._4_4_);
                    uVar21 = local_30 - uVar21;
                    iVar4 = (uint)local_68 - uVar21;
                    iVar5 = (local_68._4_4_ - ((int)uVar21 >> 0x1f)) -
                            (uint)((uint)local_68 < uVar21);
                    local_68 = CONCAT44(iVar5,iVar4);
                    if (iVar5 < (int)(uint)(iVar4 == 0)) {
                      uVar20 = 0;
                    }
                    else {
                      uVar20 = 2;
                    }
                  }
                }
                else if (*(int *)(iVar23 + 0x86f8) == 200) {
                  if (~uVar21 + local_30 == 0) {
                    uVar20 = 0;
                  }
                  else {
                    Curl_failf(iVar23,
                               "Proxy CONNECT followed by %zd bytes of opaque data. Data ignored (known bug #39)"
                              );
                    uVar20 = 0;
                  }
                }
                else {
                  uVar20 = 0;
                }
                uVar15 = 0;
                uVar21 = 0;
                param_1[iVar12] = 2;
                pcVar17 = pcVar14;
                goto LAB_00053cd0;
              }
              cVar1 = pcVar13[iVar11];
              pcVar13[iVar11] = '\0';
              iVar4 = Curl_raw_nequal("WWW-Authenticate:",pcVar13,0x11);
              if (((iVar4 == 0) || (iVar4 = *(int *)(iVar23 + 200), iVar4 != 0x191)) &&
                 ((iVar4 = Curl_raw_nequal("Proxy-authenticate:",pcVar13,0x13), iVar4 == 0 ||
                  (iVar4 = *(int *)(iVar23 + 200), iVar4 != 0x197)))) {
                iVar4 = Curl_raw_nequal("Content-Length:",pcVar13,0xf);
                if (iVar4 == 0) {
                  iVar4 = Curl_compareheader(pcVar13,"Connection:","close");
                  if (iVar4 == 0) {
                    iVar4 = Curl_compareheader(pcVar13,"Transfer-Encoding:","chunked");
                    if (iVar4 == 0) {
                      iVar4 = Curl_compareheader(pcVar13,"Proxy-Connection:","close");
                      if (iVar4 == 0) {
                        iVar4 = __isoc99_sscanf(pcVar13,"HTTP/1.%d %d",&local_34,iVar23 + 200);
                        if (iVar4 == 2) {
                          *(undefined4 *)(iVar23 + 0x86f8) = *(undefined4 *)(iVar23 + 200);
                        }
                      }
                      else {
                        bVar2 = true;
                      }
                    }
                    else {
                      Curl_infof(iVar23,"CONNECT responded chunked\n");
                      Curl_httpchunk_init(param_1);
                      local_44 = 1;
                    }
                  }
                  else {
                    bVar2 = true;
                  }
                }
                else {
                  local_68 = strtoll(pcVar13 + 0xf,(char **)0x0,10);
                }
              }
              else {
                iVar5 = Curl_copy_header_value(pcVar13);
                if (iVar5 == 0) {
                  return 0x1b;
                }
                iVar4 = Curl_http_input_auth(param_1,iVar4 == 0x197,iVar5);
                (*Curl_cfree)(iVar5);
                if (iVar4 != 0) {
                  return iVar4;
                }
              }
              pcVar13[iVar11] = cVar1;
              uVar21 = uVar21 + 1;
              iVar11 = 0;
              uVar10 = local_30;
              pcVar13 = pcVar17;
              pcVar18 = pcVar17;
              if ((int)local_30 <= (int)uVar21) goto LAB_00053ccc;
            }
            uVar21 = uVar21 + 1;
            pcVar18 = pcVar17;
          } while ((int)uVar21 < (int)uVar10);
          goto LAB_00053ccc;
        }
        if (local_68._4_4_ == 0 && (uint)local_68 == 0) {
          local_2c[0] = iVar4;
          iVar4 = Curl_httpchunk_read(param_1,pcVar14,local_30,local_2c);
          if (iVar4 == -1) {
            uVar20 = 0;
            Curl_infof(iVar23,"chunk reading DONE\n");
            param_1[iVar12] = 2;
          }
          else {
            Curl_infof(iVar23,"Read %zd bytes of chunk, continue\n",local_2c[0]);
          }
        }
        else {
          iVar4 = (uint)local_68 - local_30;
          iVar5 = (local_68._4_4_ - ((int)local_30 >> 0x1f)) - (uint)((uint)local_68 < local_30);
          local_68 = CONCAT44(iVar5,iVar4);
          if (iVar5 < (int)(uint)(iVar4 == 0)) {
            uVar20 = 0;
            uVar15 = 0;
            pcVar17 = pcVar14;
            uVar21 = uVar15;
            goto LAB_00053cd0;
          }
        }
        uVar15 = 0;
        iVar4 = Curl_pgrsUpdate(param_1);
        pcVar17 = pcVar14;
        uVar21 = uVar15;
        goto joined_r0x00053d7e;
      }
      uVar21 = 0;
      uVar22 = 0;
    } while (uVar15 < 0x4000);
LAB_00053dde:
    if (uVar22 != 0) {
      return 0x38;
    }
    if (*(int *)(iVar23 + 0x86f8) == 200) {
LAB_00053e04:
      if (bVar2) goto LAB_00053e36;
      if (*(int *)(iVar23 + 0x13c) == 0) goto LAB_00053e40;
      iVar11 = param_1[iVar12];
      if (iVar11 == 2) {
        param_1[iVar12] = 0;
        Curl_infof(iVar23,"TUNNEL_STATE switched to: %d\n",0);
        if (*(int *)(iVar23 + 0x13c) == 0) goto LAB_00053e40;
        iVar11 = param_1[iVar12];
      }
      goto LAB_00053b42;
    }
    iVar11 = Curl_http_auth_act(param_1);
    if (iVar11 != 0) {
      return iVar11;
    }
    if (*(char *)((int)param_1 + 0x1ed) == '\0') goto LAB_00053e04;
LAB_00053e36:
    if (*(int *)(iVar23 + 0x13c) != 0) {
      Curl_closesocket(param_1,param_1[param_2 + 0x55]);
      param_1[param_2 + 0x55] = -1;
      if (*(int *)(iVar23 + 200) == 200) goto LAB_00054182;
      if (*(int *)(iVar23 + 0x13c) == 0) goto LAB_00053e4a;
      *(undefined1 *)((int)param_1 + 0x202) = 1;
      Curl_infof(iVar23,"Connect me again please\n");
      goto LAB_00053e72;
    }
LAB_00053e40:
    if (*(int *)(iVar23 + 200) == 200) {
LAB_00054182:
      iVar3 = param_1[0x8b];
      param_1[iVar12] = 2;
      (*Curl_cfree)(iVar3);
      param_1[0x8b] = 0;
      *(undefined1 *)(iVar23 + 0x863c) = 1;
      Curl_infof(iVar23,"Proxy replied OK to CONNECT request\n");
      *(undefined1 *)(iVar23 + 0x135) = 0;
      in_r12 = 0;
      *(undefined1 *)(param_1 + 0x7f) = 0;
    }
    else {
LAB_00053e4a:
      (*Curl_cfree)(0);
      *(undefined4 *)(iVar23 + 0x13c) = 0;
      *(undefined1 *)((int)param_1 + 0x1ed) = 1;
      Curl_closesocket(param_1,param_1[param_2 + 0x55]);
      param_1[param_2 + 0x55] = -1;
LAB_00053e72:
      in_r12 = 0;
      cVar1 = *(char *)((int)param_1 + 0x202);
      param_1[iVar12] = 0;
      if (cVar1 == '\0') {
        Curl_failf(iVar23,"Received HTTP code %d from proxy after CONNECT",
                   *(undefined4 *)(iVar23 + 200));
        in_r12 = 0x38;
      }
    }
  }
  return in_r12;
}

