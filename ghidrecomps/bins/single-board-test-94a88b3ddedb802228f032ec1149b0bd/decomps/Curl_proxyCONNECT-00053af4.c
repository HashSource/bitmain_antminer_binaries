
int Curl_proxyCONNECT(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  char cVar1;
  bool bVar2;
  code **ppcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int in_r12;
  undefined8 local_68;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  int local_2c [2];
  char *pcVar15;
  
  iVar11 = param_2 + 0x11a;
  iVar9 = param_1[iVar11];
  iVar19 = *param_1;
  iVar4 = param_1[param_2 + 0x55];
  if (iVar9 == 2) {
    in_r12 = 0;
  }
  local_34 = 0;
  if (iVar9 != 2) {
    local_44 = 0;
    local_68 = 0;
    *(undefined *)((int)param_1 + 0x202) = 0;
LAB_00053b42:
    if (iVar9 == 0) {
      Curl_infof(iVar19,DAT_00053d9c,param_3,param_4);
      (*Curl_cfree)(*(undefined4 *)(iVar19 + 0x13c));
      *(undefined4 *)(iVar19 + 0x13c) = 0;
      iVar9 = Curl_add_buffer_init();
      ppcVar3 = DAT_00053da0;
      if (iVar9 == 0) {
        return 0x1b;
      }
      iVar5 = curl_maprintf(DAT_00053da4,param_3,param_4);
      if (iVar5 == 0) {
LAB_000541fc:
        Curl_add_buffer_free(iVar9);
        return 0x1b;
      }
      iVar6 = Curl_http_output_auth(param_1,DAT_00053da8,iVar5,1);
      (**ppcVar3)(iVar5);
      if (iVar6 != 0) {
        Curl_add_buffer_free(iVar9);
        return iVar6;
      }
      uVar7 = DAT_00053dac;
      if (param_1[0x4e] == 1) {
        uVar7 = DAT_00053db0;
      }
      pcVar10 = DAT_000540dc;
      pcVar14 = DAT_000540e0;
      if (*(char *)((int)param_1 + 499) == '\0') {
        pcVar10 = DAT_00053db4;
        pcVar14 = DAT_00053db4;
      }
      iVar5 = curl_maprintf(DAT_00053db8,pcVar10,param_3,pcVar14,param_4);
      if (iVar5 == 0) goto LAB_000541fc;
      iVar6 = Curl_checkProxyheaders(param_1,DAT_00053dbc);
      pcVar10 = DAT_00053db4;
      if ((iVar6 == 0) &&
         (pcVar10 = (char *)curl_maprintf(DAT_000542fc,iVar5), pcVar10 == (char *)0x0)) {
        (**ppcVar3)(iVar5);
        Curl_add_buffer_free(iVar9);
        return 0x1b;
      }
      iVar6 = Curl_checkProxyheaders(param_1,DAT_00053dc0);
      pcVar14 = DAT_00053db4;
      if ((iVar6 == 0) && (*(int *)(iVar19 + 0x3a8) != 0)) {
        pcVar14 = (char *)param_1[0x8c];
      }
      pcVar12 = (char *)param_1[0x8b];
      if ((char *)param_1[0x8b] == (char *)0x0) {
        pcVar12 = DAT_00053db4;
      }
      iVar6 = Curl_add_bufferf(iVar9,DAT_00053dc4,iVar5,uVar7,pcVar10,pcVar12,pcVar14);
      if (*pcVar10 != '\0') {
        (*Curl_cfree)(pcVar10);
      }
      (*Curl_cfree)(iVar5);
      if ((((iVar6 != 0) || (iVar6 = Curl_add_custom_headers(param_1,1,iVar9), iVar6 != 0)) ||
          (iVar6 = Curl_add_bufferf(iVar9,DAT_00053dcc), iVar6 != 0)) ||
         (iVar6 = Curl_add_buffer_send(iVar9,param_1,iVar19 + 0x870c,0,param_2), iVar6 != 0)) {
        Curl_failf(iVar19,DAT_00053dc8);
        Curl_add_buffer_free(0);
        return iVar6;
      }
      Curl_add_buffer_free();
      param_1[iVar11] = 1;
    }
    iVar9 = Curl_timeleft(iVar19,0,1);
    if (iVar9 < 1) {
LAB_00054002:
      Curl_failf(iVar19,DAT_000540f8);
      return 0x38;
    }
    if ((param_5 == '\0') && (iVar9 = Curl_socket_check(iVar4,0xffffffff,0xffffffff,0), iVar9 == 0))
    {
      return 0;
    }
    pcVar12 = (char *)(iVar19 + 0x59c);
    iVar9 = 0;
    uVar17 = 0;
    uVar13 = 0;
    bVar2 = false;
    uVar16 = 1;
    pcVar10 = pcVar12;
    pcVar14 = pcVar12;
    do {
      while( true ) {
        uVar8 = uVar17 ^ 1;
        if (uVar16 == 0) {
          uVar8 = 0;
        }
        uVar18 = uVar17;
        if (uVar8 == 0) goto LAB_00053dde;
        iVar5 = Curl_timeleft(iVar19,0,1);
        if (iVar5 < 1) goto LAB_00054002;
        iVar5 = Curl_socket_check(iVar4,0xffffffff,0xffffffff);
        if (iVar5 != -1) break;
        Curl_failf(iVar19,DAT_00053dd0);
        uVar17 = 1;
LAB_00053cd0:
        iVar5 = Curl_pgrsUpdate(param_1);
joined_r0x00053d7e:
        if (iVar5 != 0) {
          return 0x2a;
        }
        uVar18 = uVar17;
        if (0x3fff < uVar13) goto LAB_00053dde;
      }
      if (iVar5 == 0) {
LAB_00053ccc:
        uVar17 = 0;
        goto LAB_00053cd0;
      }
      iVar5 = Curl_read(param_1,iVar4,pcVar14,0x4000 - uVar13,&local_30);
      if (iVar5 != 0x51) {
        if (iVar5 != 0) {
          uVar16 = 0;
          uVar17 = 0;
          goto LAB_00053cd0;
        }
        if ((int)local_30 < 1) {
          if ((*(int *)(iVar19 + 0x178) == 0) || (*(int *)(iVar19 + 0x8638) == 0)) {
            Curl_failf(iVar19,DAT_000540d8);
            uVar16 = 0;
            uVar17 = 1;
          }
          else {
            *(undefined *)((int)param_1 + 0x202) = 1;
            Curl_infof(iVar19,DAT_00054110);
            uVar16 = 0;
            uVar17 = 0;
          }
          goto LAB_00053cd0;
        }
        uVar13 = uVar13 + local_30;
        if (uVar16 < 2) {
          uVar17 = 0;
          uVar8 = local_30;
          pcVar15 = pcVar14;
          do {
            while( true ) {
              pcVar14 = pcVar15 + 1;
              iVar9 = iVar9 + 1;
              if (*pcVar15 != '\n') break;
              if (*(char *)(iVar19 + 0x310) != '\0') {
                Curl_debug(iVar19,1,pcVar10,iVar9,param_1);
              }
              if (*(char *)(iVar19 + 0x304) == '\0') {
                uVar7 = 2;
              }
              else {
                uVar7 = 3;
              }
              iVar5 = Curl_client_write(param_1,uVar7,pcVar10,iVar9);
              *(int *)(iVar19 + 0x80) = *(int *)(iVar19 + 0x80) + iVar9;
              *(int *)(iVar19 + 0x8708) = *(int *)(iVar19 + 0x8708) + iVar9;
              if (iVar5 != 0) {
                return iVar5;
              }
              if (*pcVar10 == '\r' || *pcVar10 == '\n') {
                if ((*(int *)(iVar19 + 200) == 0x197) && (*(char *)(iVar19 + 0x8640) == '\0')) {
                  if ((local_68._4_4_ | (uint)local_68) == 0) {
                    uVar16 = local_44;
                    if (local_44 != 0) {
                      *(undefined *)(iVar19 + 0x135) = 1;
                      Curl_infof(iVar19,DAT_00054314,local_30 - uVar17);
                      if (pcVar10[1] == '\n') {
                        pcVar10 = pcVar10 + 1;
                        uVar17 = uVar17 + 1;
                      }
                      iVar5 = Curl_httpchunk_read(param_1,pcVar10 + 1,local_30 - uVar17,&local_30);
                      if (iVar5 == -1) {
                        uVar16 = 0;
                        Curl_infof(iVar19,DAT_00054324);
                        local_68 = 0;
                      }
                      else {
                        Curl_infof(iVar19,DAT_00054318,local_30);
                        uVar16 = 2;
                        local_68 = 0;
                      }
                    }
                  }
                  else {
                    Curl_infof(iVar19,DAT_00054320,(uint)local_68,local_68._4_4_);
                    uVar17 = local_30 - uVar17;
                    iVar5 = (uint)local_68 - uVar17;
                    iVar6 = (local_68._4_4_ - ((int)uVar17 >> 0x1f)) -
                            (uint)((uint)local_68 < uVar17);
                    local_68 = CONCAT44(iVar6,iVar5);
                    if ((int)(iVar6 - (uint)(iVar5 == 0)) < 0 ==
                        (SBORROW4(iVar6,(uint)(iVar5 == 0)) != false)) {
                      uVar16 = 2;
                    }
                    else {
                      uVar16 = 0;
                    }
                  }
                }
                else if (*(int *)(iVar19 + 0x86f8) == 200) {
                  if (~uVar17 + local_30 == 0) {
                    uVar16 = 0;
                  }
                  else {
                    Curl_failf(iVar19,DAT_0005430c);
                    uVar16 = 0;
                  }
                }
                else {
                  uVar16 = 0;
                }
                uVar13 = 0;
                uVar17 = 0;
                param_1[iVar11] = 2;
                pcVar14 = pcVar12;
                goto LAB_00053cd0;
              }
              cVar1 = pcVar10[iVar9];
              pcVar10[iVar9] = '\0';
              iVar5 = Curl_raw_nequal(DAT_000540e4,pcVar10,0x11);
              if (((iVar5 == 0) || (iVar5 = *(int *)(iVar19 + 200), iVar5 != 0x191)) &&
                 ((iVar5 = Curl_raw_nequal(DAT_000540e8,pcVar10,0x13), iVar5 == 0 ||
                  (iVar5 = *(int *)(iVar19 + 200), iVar5 != 0x197)))) {
                iVar5 = Curl_raw_nequal(DAT_000540ec,pcVar10,0xf);
                if (iVar5 == 0) {
                  iVar5 = Curl_compareheader(pcVar10,DAT_000540f0,DAT_000540f4);
                  if (iVar5 == 0) {
                    iVar5 = Curl_compareheader(pcVar10,DAT_00054100,DAT_00054104);
                    if (iVar5 == 0) {
                      iVar5 = Curl_compareheader(pcVar10,DAT_00054108,DAT_000540f4);
                      if (iVar5 == 0) {
                        iVar5 = __isoc99_sscanf(pcVar10,DAT_00054310,&local_34,iVar19 + 200);
                        if (iVar5 == 2) {
                          *(undefined4 *)(iVar19 + 0x86f8) = *(undefined4 *)(iVar19 + 200);
                        }
                      }
                      else {
                        bVar2 = true;
                      }
                    }
                    else {
                      Curl_infof(iVar19,DAT_0005410c);
                      Curl_httpchunk_init(param_1);
                      local_44 = 1;
                    }
                  }
                  else {
                    bVar2 = true;
                  }
                }
                else {
                  local_68 = strtoll(pcVar10 + 0xf,(char **)0x0,10);
                }
              }
              else {
                iVar6 = Curl_copy_header_value(pcVar10);
                if (iVar6 == 0) {
                  return 0x1b;
                }
                iVar5 = Curl_http_input_auth(param_1,iVar5 == 0x197,iVar6);
                (*Curl_cfree)(iVar6);
                if (iVar5 != 0) {
                  return iVar5;
                }
              }
              pcVar10[iVar9] = cVar1;
              uVar17 = uVar17 + 1;
              iVar9 = 0;
              uVar8 = local_30;
              pcVar10 = pcVar14;
              pcVar15 = pcVar14;
              if ((int)local_30 <= (int)uVar17) goto LAB_00053ccc;
            }
            uVar17 = uVar17 + 1;
            pcVar15 = pcVar14;
          } while ((int)uVar17 < (int)uVar8);
          goto LAB_00053ccc;
        }
        if ((local_68._4_4_ | (uint)local_68) == 0) {
          local_2c[0] = iVar5;
          iVar5 = Curl_httpchunk_read(param_1,pcVar12,local_30,local_2c);
          if (iVar5 == -1) {
            uVar16 = 0;
            Curl_infof(iVar19,DAT_00054114);
            param_1[iVar11] = 2;
          }
          else {
            Curl_infof(iVar19,DAT_000540fc,local_2c[0]);
          }
        }
        else {
          iVar5 = (uint)local_68 - local_30;
          iVar6 = (local_68._4_4_ - ((int)local_30 >> 0x1f)) - (uint)((uint)local_68 < local_30);
          local_68 = CONCAT44(iVar6,iVar5);
          if ((int)(iVar6 - (uint)(iVar5 == 0)) < 0 != (SBORROW4(iVar6,(uint)(iVar5 == 0)) != false)
             ) {
            uVar16 = 0;
            uVar13 = 0;
            pcVar14 = pcVar12;
            uVar17 = uVar13;
            goto LAB_00053cd0;
          }
        }
        uVar13 = 0;
        iVar5 = Curl_pgrsUpdate(param_1);
        pcVar14 = pcVar12;
        uVar17 = uVar13;
        goto joined_r0x00053d7e;
      }
      uVar17 = 0;
      uVar18 = 0;
    } while (uVar13 < 0x4000);
LAB_00053dde:
    if (uVar18 != 0) {
      return 0x38;
    }
    if (*(int *)(iVar19 + 0x86f8) == 200) {
LAB_00053e04:
      uVar7 = DAT_000540d0;
      if (bVar2) goto LAB_00053e36;
      if (*(int *)(iVar19 + 0x13c) == 0) goto LAB_00053e40;
      iVar9 = param_1[iVar11];
      if (iVar9 == 2) {
        param_1[iVar11] = 0;
        Curl_infof(iVar19,uVar7,0);
        if (*(int *)(iVar19 + 0x13c) == 0) goto LAB_00053e40;
        iVar9 = param_1[iVar11];
      }
      goto LAB_00053b42;
    }
    iVar9 = Curl_http_auth_act(param_1);
    if (iVar9 != 0) {
      return iVar9;
    }
    if (*(char *)((int)param_1 + 0x1ed) == '\0') goto LAB_00053e04;
LAB_00053e36:
    if (*(int *)(iVar19 + 0x13c) != 0) {
      Curl_closesocket(param_1,param_1[param_2 + 0x55]);
      param_1[param_2 + 0x55] = -1;
      if (*(int *)(iVar19 + 200) == 200) goto LAB_00054182;
      if (*(int *)(iVar19 + 0x13c) == 0) goto LAB_00053e4a;
      *(undefined *)((int)param_1 + 0x202) = 1;
      Curl_infof(iVar19,DAT_0005431c);
      goto LAB_00053e72;
    }
LAB_00053e40:
    if (*(int *)(iVar19 + 200) == 200) {
LAB_00054182:
      ppcVar3 = DAT_00054304;
      iVar4 = param_1[0x8b];
      param_1[iVar11] = 2;
      (**ppcVar3)(iVar4);
      param_1[0x8b] = 0;
      *(undefined *)(iVar19 + 0x863c) = 1;
      Curl_infof(iVar19,DAT_00054308);
      *(undefined *)(iVar19 + 0x135) = 0;
      in_r12 = 0;
      *(undefined *)(param_1 + 0x7f) = 0;
    }
    else {
LAB_00053e4a:
      (**DAT_000540d4)(0);
      *(undefined4 *)(iVar19 + 0x13c) = 0;
      *(undefined *)((int)param_1 + 0x1ed) = 1;
      Curl_closesocket(param_1,param_1[param_2 + 0x55]);
      param_1[param_2 + 0x55] = -1;
LAB_00053e72:
      in_r12 = 0;
      cVar1 = *(char *)((int)param_1 + 0x202);
      param_1[iVar11] = 0;
      if (cVar1 == '\0') {
        Curl_failf(iVar19,DAT_00054300,*(undefined4 *)(iVar19 + 200));
        in_r12 = 0x38;
      }
    }
  }
  return in_r12;
}

