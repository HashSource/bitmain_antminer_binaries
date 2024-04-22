
undefined4 multi_runsingle(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  code **ppcVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  char *pcVar14;
  bool bVar15;
  uint *local_4c;
  undefined4 local_40;
  undefined4 uStack_3c;
  char local_35;
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  int local_30;
  uint local_2c [2];
  
  local_33 = '\0';
  local_32 = '\0';
  local_31 = '\0';
  if ((param_4 == 0) || (*(int *)(param_4 + 0x879c) != -0x3f212453)) {
    uVar10 = 2;
  }
  else {
    pcVar14 = (char *)(param_4 + 0x867d);
    iVar4 = 0;
    local_40 = param_2;
    uStack_3c = param_3;
LAB_0003aa9a:
    do {
      iVar5 = iVar4;
      if (*pcVar14 != '\0') {
        Curl_infof(param_4,DAT_0003adc8,param_4,*(undefined4 *)(param_4 + 0x868c));
        if (*(uint *)(param_4 + 0xc) < 0x11) {
          mstate(param_4,2);
          iVar5 = 0;
          uVar12 = 0xffffffff;
        }
        else {
          uVar12 = 0;
        }
        *pcVar14 = '\0';
        *(undefined4 *)(param_4 + 8) = 0;
        goto LAB_0003ab38;
      }
      piVar7 = *(int **)(param_4 + 8);
      if (((piVar7 == (int *)0x0) && (2 < *(uint *)(param_4 + 0xc))) &&
         (*(uint *)(param_4 + 0xc) < 0x10)) {
        Curl_failf(param_4,DAT_0003adcc);
        return 4;
      }
      cVar1 = *(char *)(param_1 + 100);
      *(undefined *)(param_1 + 100) = 0;
      if (cVar1 != '\0') {
        Curl_multi_process_pending_handles(param_1);
        piVar7 = *(int **)(param_4 + 8);
      }
      uVar6 = *(uint *)(param_4 + 0xc);
      if (piVar7 != (int *)0x0) {
        if (uVar6 < 3) {
          if ((1 < uVar6) && (uVar6 < 0x11)) goto LAB_0003aac6;
          goto LAB_0003aade;
        }
        if (0x10 < uVar6) goto LAB_0003aade;
        *piVar7 = param_4;
LAB_0003aac6:
        iVar3 = Curl_timeleft(param_4,&local_40,uVar6 < 9);
        if (-1 < iVar3) {
          uVar6 = *(uint *)(param_4 + 0xc);
          goto LAB_0003aade;
        }
        if (*(int *)(param_4 + 0xc) == 3) {
          curlx_tvdiff(local_40,uStack_3c,*(undefined4 *)(param_4 + 0x500),
                       *(undefined4 *)(param_4 + 0x504));
          Curl_failf(param_4,DAT_0003b500);
        }
        else if (*(int *)(param_4 + 0xc) == 4) {
          curlx_tvdiff(local_40,uStack_3c,*(undefined4 *)(param_4 + 0x500),
                       *(undefined4 *)(param_4 + 0x504));
          Curl_failf(param_4,DAT_0003b504);
        }
        else if (*(int *)(param_4 + 0x54) == -1 && *(int *)(param_4 + 0x50) == -1) {
          curlx_tvdiff(local_40,uStack_3c,*(undefined4 *)(param_4 + 0x500),
                       *(undefined4 *)(param_4 + 0x504));
          Curl_failf(param_4,DAT_0003b4f8);
        }
        else {
          curlx_tvdiff(*(undefined4 *)(param_4 + 0x90),*(undefined4 *)(param_4 + 0x94),
                       *(undefined4 *)(param_4 + 0x500),*(undefined4 *)(param_4 + 0x504));
          Curl_failf(param_4,DAT_0003b130);
        }
        iVar5 = 0x1c;
        bVar15 = 9 < *(uint *)(param_4 + 0xc);
        if (bVar15) {
          *(undefined *)(*(int *)(param_4 + 8) + 0x1ed) = 1;
        }
        uVar11 = (uint)bVar15;
        Curl_done(param_4 + 8,0x1c,1);
        goto LAB_0003aeac;
      }
LAB_0003aade:
      switch(uVar6) {
      case 0:
        iVar5 = Curl_pretransfer(param_4);
        if (iVar5 != 0) {
LAB_0003aeaa:
          uVar11 = 0;
          goto LAB_0003aeac;
        }
        mstate(param_4,2);
        uVar12 = 0xffffffff;
        Curl_pgrsTime(param_4,1);
        break;
      case 1:
        uVar11 = 0;
        uVar12 = uVar11;
        goto LAB_0003ac22;
      case 2:
        Curl_pgrsTime(param_4,2);
        iVar5 = Curl_connect(param_4,param_4 + 8,&local_34,&local_33);
        if (iVar5 == 0x59) {
          mstate(param_4,1);
          iVar4 = Curl_llist_insert_next
                            (*(int *)(param_1 + 0x18),*(undefined4 *)(*(int *)(param_1 + 0x18) + 4),
                             param_4);
          if (iVar4 == 0) {
            iVar5 = 0x1b;
            uVar11 = 0;
            goto LAB_0003aeac;
          }
LAB_0003afac:
          uVar12 = 0;
        }
        else {
          if (iVar5 != 0) goto LAB_0003aeaa;
          iVar5 = Curl_add_handle_to_pipeline(param_4,*(undefined4 *)(param_4 + 8));
          if (iVar5 != 0) goto LAB_0003b124;
          if (local_34 == '\0') {
            if (local_33 != '\0') goto LAB_0003af6a;
            uVar12 = 0xffffffff;
            if (*(int *)(*(int *)(param_4 + 8) + 0x468) == 1) {
              uVar10 = 5;
            }
            else {
              uVar10 = 4;
            }
            mstate(param_4,uVar10);
          }
          else {
            mstate(param_4,3);
            uVar12 = 0;
          }
        }
        break;
      case 3:
        iVar4 = *(int *)(param_4 + 8);
        iVar4 = Curl_fetch_addr(iVar4,*(undefined4 *)(iVar4 + 0x98),*(undefined4 *)(iVar4 + 0xb0));
        if (iVar4 == 0) {
          singlesocket(param_1,param_4);
          uVar11 = 1;
          iVar5 = 6;
          goto LAB_0003aeac;
        }
        Curl_infof(param_4,DAT_0003b128);
        singlesocket(param_1,param_4);
        if (local_33 == '\0') {
          if (*(int *)(*(int *)(param_4 + 8) + 0x468) == 1) {
            uVar10 = 5;
          }
          else {
            uVar10 = 4;
          }
          mstate(param_4,uVar10);
        }
        else {
          if ((*(uint *)(param_1 + 0x60) & 1) == 0) {
            uVar10 = 9;
          }
          else {
            uVar10 = 8;
          }
          mstate(param_4,uVar10);
        }
        uVar12 = 0xffffffff;
        break;
      case 4:
        iVar5 = Curl_is_connected(*(undefined4 *)(param_4 + 8),0,&local_35);
        if (local_35 == '\0') {
          if (iVar5 == 0) goto LAB_0003afac;
        }
        else if (iVar5 == 0) {
          uVar12 = 0xffffffff;
          if (*(char *)(*(int *)(param_4 + 8) + 0x1fa) == '\0') {
            uVar10 = 6;
          }
          else {
            uVar10 = 5;
          }
          mstate(param_4,uVar10);
          break;
        }
LAB_0003b124:
        uVar11 = 1;
        goto LAB_0003aeac;
      case 5:
        iVar5 = Curl_http_connect(*(undefined4 *)(param_4 + 8),&local_33);
        if (*(char *)(*(int *)(param_4 + 8) + 0x202) == '\0') {
          uVar11 = 0;
          if (iVar5 != 0) goto LAB_0003aeac;
          if (*(int *)(*(int *)(param_4 + 8) + 0x468) != 2) goto LAB_0003afac;
          mstate(param_4,6);
          uVar12 = 0xffffffff;
        }
        else {
          uVar12 = 0xffffffff;
          Curl_done(param_4 + 8,0,0);
          mstate(param_4,2);
        }
        break;
      case 6:
        iVar5 = Curl_protocol_connect(*(undefined4 *)(param_4 + 8),&local_33);
        if (local_33 == '\0') {
          mstate(param_4,7);
          uVar6 = *(uint *)(param_4 + 0xc);
          uVar11 = 0;
          uVar12 = 0;
          goto joined_r0x0003ac20;
        }
        if (iVar5 != 0) goto LAB_0003af3a;
LAB_0003af6a:
        uVar12 = 0xffffffff;
        if ((*(uint *)(param_1 + 0x60) & 1) == 0) {
          uVar10 = 9;
        }
        else {
          uVar10 = 8;
        }
        mstate(param_4,uVar10);
        break;
      case 7:
        iVar5 = Curl_protocol_connecting(*(undefined4 *)(param_4 + 8),&local_33);
        if (iVar5 == 0) {
          if (local_33 == '\0') goto LAB_0003afac;
          goto LAB_0003af6a;
        }
LAB_0003af3a:
        uVar11 = 1;
        Curl_posttransfer(param_4);
        Curl_done(param_4 + 8,iVar5,1);
LAB_0003aeac:
        uVar6 = *(uint *)(param_4 + 0xc);
        uVar12 = 0;
        if (uVar6 < 0x11) goto LAB_0003aeb6;
        goto LAB_0003ab9c;
      case 8:
        iVar5 = Curl_pipeline_checkget_write(param_4,*(undefined4 *)(param_4 + 8));
        if (iVar5 == 0) goto LAB_0003ac98;
        uVar10 = 9;
        goto LAB_0003ac10;
      case 9:
        bVar2 = *(byte *)(param_4 + 0x329);
        if (bVar2 == 0) {
          iVar4 = param_4 + 8;
          iVar5 = Curl_do(iVar4,&local_32);
          if (iVar5 != 0) {
            if ((iVar5 != 0x37) || (*(char *)(*(int *)(param_4 + 8) + 0x1ee) == '\0')) {
              Curl_posttransfer(param_4);
              if (*(int *)(param_4 + 8) == 0) goto LAB_0003b124;
              uVar11 = 1;
              Curl_done(iVar4,iVar5,0);
              goto LAB_0003aeac;
            }
            local_2c[0] = (uint)bVar2;
            iVar3 = Curl_retry_request(*(int *)(param_4 + 8),local_2c);
            uVar12 = local_2c[0];
            if (iVar3 == 0) {
              Curl_posttransfer(param_4);
              iVar4 = Curl_done(iVar4,0x37,0);
              iVar3 = iVar5;
              if (uVar12 == 0) goto LAB_0003b460;
              if (iVar4 == 0 || iVar4 == 0x37) {
                iVar4 = Curl_follow(param_4,local_2c[0],2);
                if (iVar4 == 0) {
                  mstate(param_4,2);
                  uVar11 = 0;
                  uVar12 = 0xffffffff;
                }
                else {
                  (*Curl_cfree)(local_2c[0]);
                  uVar11 = 0;
                  uVar12 = 0;
                }
              }
              else {
                uVar11 = 0;
                (*Curl_cfree)(local_2c[0]);
                uVar12 = uVar11;
              }
            }
            else {
              Curl_posttransfer(param_4);
              Curl_done(iVar4,iVar3,0);
LAB_0003b460:
              iVar4 = iVar3;
              uVar11 = 1;
              uVar12 = 0;
              (*Curl_cfree)(local_2c[0]);
            }
            goto LAB_0003ad88;
          }
          if (local_32 == '\0') {
            if ((*(char *)(param_4 + 0x414) == '\0') ||
               ((*(uint *)(param_4 + 0x86d8) & 0xfffffffd) != 4)) {
              mstate(param_4,10);
              uVar12 = 0;
            }
            else {
              Curl_done(iVar4,0,0);
              uVar12 = 0xffffffff;
              mstate(param_4,0x10);
            }
          }
          else if (*(char *)(*(int *)(param_4 + 8) + 0x1f5) == '\0') {
            uVar12 = 0xffffffff;
            mstate(param_4,0xc);
          }
          else {
            mstate(param_4,0xb);
            uVar12 = 0;
          }
        }
        else {
          uVar12 = 0xffffffff;
          *(undefined *)(*(int *)(param_4 + 8) + 0x1ed) = 0;
          mstate(param_4,0x10);
        }
        break;
      case 10:
        iVar5 = Curl_protocol_doing(*(undefined4 *)(param_4 + 8),&local_32);
        if (iVar5 != 0) {
LAB_0003b108:
          uVar11 = 1;
          Curl_posttransfer(param_4);
          Curl_done(param_4 + 8,iVar5,0);
          goto LAB_0003aeac;
        }
        if (local_32 == '\0') goto LAB_0003afac;
        uVar12 = 0xffffffff;
        if (*(char *)(*(int *)(param_4 + 8) + 0x1f5) == '\0') {
          uVar10 = 0xc;
        }
        else {
          uVar10 = 0xb;
        }
        mstate(param_4,uVar10);
        break;
      case 0xb:
        iVar5 = Curl_do_more(*(undefined4 *)(param_4 + 8),&local_30);
        if (iVar5 != 0) goto LAB_0003b108;
        if (local_30 == 0) goto LAB_0003afac;
        uVar12 = 0xffffffff;
        if (local_30 == 1) {
          uVar10 = 0xc;
        }
        else {
          uVar10 = 10;
        }
        mstate(param_4,uVar10);
        break;
      case 0xc:
        Curl_move_handle_from_send_to_recv_pipe(param_4,*(undefined4 *)(param_4 + 8));
        Curl_multi_process_pending_handles(param_1);
        if ((*(int *)(*(int *)(param_4 + 8) + 0x224) != -1) ||
           (*(int *)(*(int *)(param_4 + 8) + 0x228) != -1)) {
          uVar10 = 0xd;
          goto LAB_0003ac10;
        }
        mstate(param_4,0x10);
        uVar6 = *(uint *)(param_4 + 0xc);
        uVar11 = 0;
        uVar12 = 0xffffffff;
        goto joined_r0x0003ac20;
      case 0xd:
        iVar5 = Curl_pipeline_checkget_read(param_4,*(undefined4 *)(param_4 + 8));
        if (iVar5 == 0) goto LAB_0003ac98;
        uVar10 = 0xe;
        goto LAB_0003ac10;
      case 0xe:
        puVar13 = (uint *)(param_4 + 0x228);
        uVar12 = *puVar13;
        iVar5 = *(int *)(param_4 + 0x22c);
        local_2c[0] = 0;
        if ((int)(iVar5 - (uint)(uVar12 == 0)) < 0 == (SBORROW4(iVar5,(uint)(uVar12 == 0)) != false)
           ) {
          local_4c = (uint *)(param_4 + 0x4c0);
          iVar3 = *(int *)(param_4 + 0x4c4);
          if ((int)((iVar5 - iVar3) - (uint)(uVar12 < *local_4c)) < 0 ==
              (SBORROW4(iVar5,iVar3) != SBORROW4(iVar5 - iVar3,(uint)(uVar12 < *local_4c))))
          goto LAB_0003ad00;
          mstate(param_4,0xf);
          iVar5 = *(int *)(param_4 + 0x2cc);
LAB_0003b278:
          uVar11 = 0;
          if (iVar5 == 0) {
            iVar5 = 0x4000;
          }
          uVar10 = Curl_sleep_time(*puVar13,puVar13[1],*local_4c,local_4c[1],iVar5);
          Curl_expire_latest(param_4,uVar10);
          uVar12 = uVar11;
        }
        else {
LAB_0003ad00:
          puVar13 = (uint *)(param_4 + 0x230);
          uVar12 = *puVar13;
          iVar5 = *(int *)(param_4 + 0x234);
          if ((int)(iVar5 - (uint)(uVar12 == 0)) < 0 ==
              (SBORROW4(iVar5,(uint)(uVar12 == 0)) != false)) {
            local_4c = (uint *)(param_4 + 0x4b8);
            iVar3 = *(int *)(param_4 + 0x4bc);
            if ((int)((iVar5 - iVar3) - (uint)(uVar12 < *local_4c)) < 0 !=
                (SBORROW4(iVar5,iVar3) != SBORROW4(iVar5 - iVar3,(uint)(uVar12 < *local_4c)))) {
              mstate(param_4,0xf);
              iVar5 = *(int *)(param_4 + 0x2cc);
              goto LAB_0003b278;
            }
          }
          iVar4 = Curl_readwrite(*(undefined4 *)(param_4 + 8),param_4,&local_31);
          iVar5 = *(int *)(param_4 + 0x130);
          if (-1 < iVar5 << 0x1f) {
            Curl_pipeline_leave_read(*(undefined4 *)(param_4 + 8));
            iVar5 = *(int *)(param_4 + 0x130);
          }
          if (-1 < iVar5 << 0x1e) {
            Curl_pipeline_leave_write(*(undefined4 *)(param_4 + 8));
          }
          if ((((local_31 == '\0') && (iVar4 != 0x38)) ||
              (iVar5 = Curl_retry_request(*(undefined4 *)(param_4 + 8),local_2c), iVar5 != 0)) ||
             (local_2c[0] == 0)) {
            if (iVar4 == 0) {
              bVar15 = false;
              if (local_31 != '\0') goto LAB_0003b004;
              uVar11 = 0;
              uVar12 = 0;
              ppcVar9 = DAT_0003b4fc;
            }
            else {
              uVar11 = 0;
              uVar12 = 0;
              if (-1 < *(int *)(*(int *)(*(int *)(param_4 + 8) + 0x218) + 0x40) << 0x1e) {
                *(undefined *)(*(int *)(param_4 + 8) + 0x1ed) = 1;
              }
              Curl_posttransfer(param_4);
              Curl_done(param_4 + 8,iVar4,0);
              ppcVar9 = DAT_0003add0;
            }
          }
          else {
            bVar15 = true;
            local_31 = '\x01';
LAB_0003b004:
            Curl_posttransfer(param_4);
            Curl_removeHandleFromPipeline(param_4,*(undefined4 *)(*(int *)(param_4 + 8) + 0x25c));
            puVar8 = (undefined4 *)**(undefined4 **)(*(int *)(param_4 + 8) + 0x25c);
            if (puVar8 != (undefined4 *)0x0) {
              Curl_expire_latest(*puVar8,1);
            }
            Curl_multi_process_pending_handles(param_1);
            if (*(int *)(param_4 + 0x13c) == 0) {
              ppcVar9 = DAT_0003b4fc;
              if (!bVar15) {
                uVar11 = 0;
                if (*(int *)(param_4 + 0x138) == 0) {
                  iVar4 = 0;
                }
                else {
                  (*Curl_cfree)(local_2c[0]);
                  ppcVar9 = DAT_0003b4fc;
                  local_2c[0] = *(uint *)(param_4 + 0x138);
                  *(undefined4 *)(param_4 + 0x138) = 0;
                  iVar4 = Curl_follow(param_4,local_2c[0],1);
                  if (iVar4 == 0) {
                    local_2c[0] = 0;
                  }
                  else {
                    uVar11 = 1;
                  }
                }
                uVar12 = 0xffffffff;
                mstate(param_4,0x10);
                goto LAB_0003ad82;
              }
              uVar10 = 2;
            }
            else if (bVar15) {
              uVar10 = 2;
              ppcVar9 = DAT_0003b12c;
            }
            else {
              uVar10 = 3;
              (*Curl_cfree)(local_2c[0]);
              ppcVar9 = DAT_0003b4fc;
              local_2c[0] = *(uint *)(param_4 + 0x13c);
              *(undefined4 *)(param_4 + 0x13c) = 0;
            }
            iVar4 = Curl_done(param_4 + 8,0,0);
            if ((iVar4 == 0) && (iVar4 = Curl_follow(param_4,local_2c[0],uVar10), iVar4 == 0)) {
              mstate(param_4,2);
              uVar12 = 0xffffffff;
              uVar11 = 0;
              local_2c[0] = 0;
            }
            else {
              uVar11 = 0;
              uVar12 = 0;
            }
          }
LAB_0003ad82:
          (**ppcVar9)(local_2c[0]);
        }
LAB_0003ad88:
        uVar6 = *(uint *)(param_4 + 0xc);
        iVar5 = iVar4;
        goto joined_r0x0003ac20;
      case 0xf:
        iVar4 = 0x2a;
        iVar5 = Curl_pgrsUpdate(*(undefined4 *)(param_4 + 8));
        if (iVar5 == 0) {
          iVar4 = Curl_speedcheck(param_4,local_40,uStack_3c);
        }
        uVar12 = *(uint *)(param_4 + 0x228);
        uVar6 = *(uint *)(param_4 + 0x22c);
        if (((uVar12 | uVar6) == 0) ||
           (iVar5 = *(int *)(param_4 + 0x4c4), bVar15 = *(uint *)(param_4 + 0x4c0) < uVar12,
           (int)((iVar5 - uVar6) - (uint)bVar15) < 0 !=
           (SBORROW4(iVar5,uVar6) != SBORROW4(iVar5 - uVar6,(uint)bVar15)))) {
          uVar12 = *(uint *)(param_4 + 0x230);
          uVar6 = *(uint *)(param_4 + 0x234);
          if (((uVar12 | uVar6) == 0) ||
             (iVar5 = *(int *)(param_4 + 0x4bc), bVar15 = *(uint *)(param_4 + 0x4b8) < uVar12,
             (int)((iVar5 - uVar6) - (uint)bVar15) < 0 !=
             (SBORROW4(iVar5,uVar6) != SBORROW4(iVar5 - uVar6,(uint)bVar15)))) {
            mstate(param_4,0xe);
          }
        }
LAB_0003ac98:
        uVar6 = *(uint *)(param_4 + 0xc);
        uVar11 = 0;
        uVar12 = uVar11;
        iVar5 = iVar4;
        goto joined_r0x0003ac20;
      case 0x10:
        if (*(int *)(param_4 + 8) != 0) {
          Curl_removeHandleFromPipeline(param_4,*(undefined4 *)(*(int *)(param_4 + 8) + 0x25c));
          Curl_multi_process_pending_handles(param_1);
          iVar5 = Curl_done(param_4 + 8,iVar4,0);
          if (iVar4 == 0) {
            iVar4 = iVar5;
          }
          if (*(int *)(param_4 + 8) != 0) {
            *(undefined4 *)(param_4 + 8) = 0;
          }
        }
        if ((*(char *)(param_4 + 0x414) == '\0') || (*(int *)(param_4 + 0x86d8) == 6)) {
          uVar10 = 0x11;
        }
        else {
          uVar10 = 0;
        }
LAB_0003ac10:
        mstate(param_4,uVar10);
        uVar6 = *(uint *)(param_4 + 0xc);
        uVar11 = 0;
        uVar12 = 0xffffffff;
        iVar5 = iVar4;
        goto joined_r0x0003ac20;
      case 0x11:
        uVar11 = 0;
        *(undefined4 *)(param_4 + 8) = 0;
        Curl_expire(param_4,0);
        uVar6 = *(uint *)(param_4 + 0xc);
        uVar12 = 0;
joined_r0x0003ac20:
        iVar4 = iVar5;
        if (uVar6 < 0x11) {
LAB_0003ac22:
          iVar5 = iVar4;
          if (iVar4 != 0) {
LAB_0003aeb6:
            *pcVar14 = '\0';
            Curl_multi_process_pending_handles(param_1);
            if (*(int *)(param_4 + 8) == 0) {
              if (*(int *)(param_4 + 0xc) == 2) {
                Curl_posttransfer(param_4);
              }
            }
            else {
              Curl_pipeline_leave_write();
              Curl_pipeline_leave_read(*(undefined4 *)(param_4 + 8));
              Curl_removeHandleFromPipeline(param_4,*(undefined4 *)(*(int *)(param_4 + 8) + 600));
              Curl_removeHandleFromPipeline(param_4,*(undefined4 *)(*(int *)(param_4 + 8) + 0x25c));
              if (uVar11 != 0) {
                Curl_disconnect(*(undefined4 *)(param_4 + 8),iVar5 == 0x1c);
                *(undefined4 *)(param_4 + 8) = 0;
              }
            }
            mstate(param_4,0x11);
            uVar6 = *(uint *)(param_4 + 0xc);
            goto LAB_0003ab9c;
          }
          goto LAB_0003ac2a;
        }
        goto LAB_0003ab9c;
      case 0x12:
        *(int *)(param_4 + 0x10) = iVar4;
        return 0;
      default:
        return 4;
      }
      uVar6 = *(uint *)(param_4 + 0xc);
      if (uVar6 < 0x11) {
LAB_0003ac2a:
        iVar5 = *(int *)(param_4 + 8);
        if (iVar5 != 0) {
          iVar4 = Curl_pgrsUpdate();
          if (iVar4 == 0) {
            uVar6 = *(uint *)(param_4 + 0xc);
            iVar5 = 0;
          }
          else {
            uVar6 = *(uint *)(param_4 + 0xc);
            iVar5 = 0x2a;
            uVar12 = 0xffffffff;
            *(undefined *)(*(int *)(param_4 + 8) + 0x1ed) = 1;
            if (uVar6 < 0x10) {
              uVar10 = 0x10;
            }
            else {
              uVar10 = 0x11;
            }
            mstate(param_4,uVar10);
            uVar6 = *(uint *)(param_4 + 0xc);
          }
        }
      }
      else {
        iVar5 = 0;
      }
LAB_0003ab9c:
      if (uVar6 == 0x11) {
        *(int *)(param_4 + 0x1c) = iVar5;
        iVar4 = *(int *)(param_1 + 0x14);
        *(int *)(param_4 + 0x18) = param_4;
        *(undefined4 *)(param_4 + 0x14) = 1;
        iVar4 = Curl_llist_insert_next(iVar4,*(undefined4 *)(iVar4 + 4),param_4 + 0x14);
        if (iVar4 == 0) {
          uVar10 = 3;
        }
        else {
          uVar10 = 0;
        }
        mstate(param_4,0x12);
      }
      else {
LAB_0003ab38:
        iVar4 = iVar5;
        if (uVar12 == 0xffffffff) goto LAB_0003aa9a;
        uVar10 = 0;
      }
      iVar4 = iVar5;
    } while (*(char *)(param_1 + 100) != '\0');
    *(int *)(param_4 + 0x10) = iVar5;
  }
  return uVar10;
}

