
undefined4 state_machine(SSL *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  BUF_MEM *pBVar7;
  SRTP_PROTECTION_PROFILE *pSVar8;
  code *pcVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  bool bVar13;
  SRTP_PROTECTION_PROFILE *local_58;
  code *local_48;
  int local_44;
  X509_VERIFY_PARAM *local_40;
  int local_3c;
  
  if (param_1->quiet_shutdown == 1) {
    return 0xffffffff;
  }
  ERR_clear_error();
  piVar1 = __errno_location();
  local_58 = param_1[2].srtp_profile;
  *piVar1 = 0;
  if (local_58 == (SRTP_PROTECTION_PROFILE *)0x0) {
    local_58 = (SRTP_PROTECTION_PROFILE *)param_1[3].method[1].ssl_renegotiate_check;
  }
  param_1->packet_length = param_1->packet_length + 1;
  iVar2 = SSL_in_init(param_1);
  if (iVar2 == 0) {
    iVar2 = *(int *)param_1->mac_flags;
joined_r0x000e96e0:
    if ((-1 < iVar2 << 0x14) && (iVar2 = SSL_clear(param_1), iVar2 == 0)) {
      return 0xffffffff;
    }
  }
  else {
    iVar2 = SSL_in_before(param_1);
    if (iVar2 != 0) {
      iVar2 = *(int *)param_1->mac_flags;
      goto joined_r0x000e96e0;
    }
  }
  uVar3 = param_1->quiet_shutdown;
  if ((uVar3 & 0xfffffffb) == 0) {
    if (uVar3 == 0) {
      param_1->init_msg = (void *)0x0;
      param_1->init_num = 0;
    }
    param_1->in_handshake = param_2;
    if (local_58 == (SRTP_PROTECTION_PROFILE *)0x0) {
LAB_000e9138:
      if (-1 < *(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c) goto LAB_000e964e;
      uVar3 = param_1->version;
      if (((uVar3 & 0xff00) == 0xfe00) || ((uVar3 & 0xff00) == 0x100 && param_2 == 0))
      goto LAB_000e9656;
      uVar4 = 0x168;
    }
    else {
      if ((((*(int *)(param_1->mac_flags + 0x180) == 0) ||
           (*(int *)(param_1->mac_flags + 0x204) == 0)) ||
          (*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0)) ||
         (iVar2 = *(int *)param_1->type, iVar2 < 0x304 || iVar2 == 0x10000)) {
        (*(code *)local_58)(param_1,0x10,1);
        goto LAB_000e9138;
      }
LAB_000e964e:
      uVar3 = param_1->version;
      if ((int)uVar3 >> 8 == 3) {
LAB_000e9656:
        iVar2 = ssl_security(param_1,9,0,uVar3,0);
        if (iVar2 == 0) {
          uVar4 = 0x175;
          goto LAB_000e9686;
        }
        if (param_1->hit == 0) {
          pBVar7 = BUF_MEM_new();
          if (pBVar7 == (BUF_MEM *)0x0) {
            uVar4 = 0x17c;
          }
          else {
            iVar2 = BUF_MEM_grow(pBVar7,0x4000);
            if (iVar2 != 0) {
              param_1->hit = (int)pBVar7;
              goto LAB_000e9670;
            }
            uVar4 = 0x181;
          }
          ossl_statem_fatal(param_1,0xffffffff,0x161,0x44,"ssl/statem/statem.c",uVar4);
          uVar6 = 0xffffffff;
          goto LAB_000e9184;
        }
LAB_000e9670:
        iVar2 = ssl3_setup_buffers(param_1);
        if (iVar2 == 0) {
          uVar4 = 0x18a;
        }
        else {
          param_1->cipher_list = (stack_st_SSL_CIPHER *)0x0;
          *(undefined4 *)(param_1->mac_flags + 0xdc) = 0;
          iVar2 = ssl_init_wbio_buffer(param_1);
          if (iVar2 != 0) {
            iVar2 = SSL_in_before(param_1);
            if ((iVar2 == 0) && (param_1[3].tlsext_hostname == (char *)0x0)) {
LAB_000e91f6:
              uVar3 = 3;
              param_1->quiet_shutdown = 3;
              param_1->shutdown = 0;
              goto LAB_000e9200;
            }
            iVar2 = tls_setup_handshake(param_1);
            if (iVar2 != 0) {
              if ((*(int *)(param_1->mac_flags + 0x180) == 0) ||
                 (*(int *)(param_1->mac_flags + 0x204) == 0)) {
                param_1->packet = (uchar *)0x1;
              }
              goto LAB_000e91f6;
            }
            goto switchD_000e951e_caseD_3;
          }
          uVar4 = 0x19d;
        }
LAB_000e9686:
        pBVar7 = (BUF_MEM *)0x0;
        uVar6 = 0xffffffff;
        ossl_statem_fatal(param_1,0xffffffff,0x161,0x44,"ssl/statem/statem.c",uVar4);
        goto LAB_000e9184;
      }
      uVar4 = 0x16e;
    }
    ossl_statem_fatal(param_1,0xffffffff,0x161,0x44,"ssl/statem/statem.c",uVar4);
  }
  else {
LAB_000e9200:
    if (uVar3 == 4) {
LAB_000e938a:
      uVar6 = 1;
      pBVar7 = (BUF_MEM *)0x0;
      goto LAB_000e9184;
    }
LAB_000e9206:
    if (uVar3 == 2) {
LAB_000e9400:
      pSVar8 = param_1[2].srtp_profile;
      local_44 = 0;
      if (pSVar8 == (SRTP_PROTECTION_PROFILE *)0x0) {
        pSVar8 = (SRTP_PROTECTION_PROFILE *)param_1[3].method[1].ssl_renegotiate_check;
      }
      if (param_1->in_handshake == 0) {
        pcVar12 = (code *)0xeb501;
        pcVar10 = (code *)0xedc65;
        pcVar9 = (code *)0xed905;
        pcVar11 = (code *)0xeacd9;
      }
      else {
        pcVar12 = (code *)0xf3b85;
        pcVar10 = (code *)0xf57a1;
        pcVar9 = (code *)0xf5ea9;
        pcVar11 = (code *)0xf2ff1;
      }
      if (param_1->packet != (uchar *)0x0) {
        param_1->packet = (uchar *)0x0;
        param_1[3].rstate = 1;
      }
      iVar2 = param_1->rstate;
LAB_000e9446:
      bVar13 = iVar2 != 0;
      if (iVar2 == 1) {
        uVar3 = *(uint *)(*(int *)(param_1->type + 100) + 0x30) & 8;
        goto joined_r0x000e9544;
      }
      do {
        if (!bVar13) {
          if (*(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c < 0) {
            iVar2 = dtls_get_message(param_1,&local_48,&local_44);
          }
          else {
            iVar2 = tls_get_message_header(param_1,&local_48);
          }
          if (iVar2 == 0) goto switchD_000e951e_caseD_3;
          if (pSVar8 != (SRTP_PROTECTION_PROFILE *)0x0) {
            if (param_1->in_handshake == 0) {
              (*(code *)pSVar8)(param_1,0x1001,1);
            }
            else {
              (*(code *)pSVar8)(param_1,0x2001);
            }
          }
          iVar2 = (*pcVar11)(param_1,local_48);
          if (iVar2 == 0) goto switchD_000e951e_caseD_3;
          uVar5 = *(uint *)(param_1->mac_flags + 0x208);
          uVar3 = (*pcVar12)(param_1);
          if (uVar3 < uVar5) {
            ossl_statem_fatal(param_1,0x2f,0x160,0x98,"ssl/statem/statem.c",0x25b);
            goto switchD_000e951e_caseD_3;
          }
          uVar3 = *(uint *)(*(int *)(param_1->type + 100) + 0x30) & 8;
          if ((uVar3 == 0) && (uVar3 = *(uint *)(param_1->mac_flags + 0x208), uVar3 != 0)) {
            uVar5 = (int)param_1->param - (int)((BUF_MEM *)param_1->hit)->data;
            iVar2 = BUF_MEM_grow_clean((BUF_MEM *)param_1->hit,uVar3 + 4);
            if (iVar2 != 0 && uVar5 <= uVar3 + 4) {
              param_1->param = (X509_VERIFY_PARAM *)(uVar5 + *(int *)(param_1->hit + 4));
              uVar3 = *(uint *)(*(int *)(param_1->type + 100) + 0x30) & 8;
              goto LAB_000e95ea;
            }
            uVar4 = 0x265;
            uVar6 = 7;
          }
          else {
LAB_000e95ea:
            param_1->rstate = 1;
joined_r0x000e9544:
            if ((uVar3 == 0) && (iVar2 = tls_get_message_body(param_1,&local_44), iVar2 == 0))
            goto switchD_000e951e_caseD_3;
            param_1[3].rstate = 0;
            if (-1 < local_44) {
              local_3c = local_44;
              local_40 = param_1->param;
              iVar2 = (*pcVar9)(param_1,&local_40);
              param_1->cipher_list = (stack_st_SSL_CIPHER *)0x0;
              if (iVar2 == 1) goto switchD_000e951e_caseD_1;
              if (iVar2 != 0) {
                if (iVar2 == 2) {
                  param_1->rstate = 2;
                  param_1->init_buf = (BUF_MEM *)0x3;
                  iVar2 = 2;
                  goto LAB_000e944e;
                }
                goto switchD_000e951e_caseD_2;
              }
              if ((param_1->init_off == 0) || (param_1->quiet_shutdown != 1)) {
                uVar4 = 0x283;
                goto LAB_000e970c;
              }
              goto switchD_000e951e_caseD_3;
            }
            uVar4 = 0x279;
            uVar6 = 0x44;
          }
LAB_000e9462:
          ossl_statem_fatal(param_1,0x50,0x160,uVar6,"ssl/statem/statem.c",uVar4);
          goto switchD_000e951e_caseD_3;
        }
LAB_000e944e:
        if (iVar2 != 2) {
          uVar4 = 0x2b1;
          uVar6 = 0x44;
          goto LAB_000e9462;
        }
        pBVar7 = (BUF_MEM *)(*pcVar10)(param_1,param_1->init_buf);
        param_1->init_buf = pBVar7;
        switch(pBVar7) {
        case (BUF_MEM *)0x0:
          if ((param_1->init_off == 0) || (param_1->quiet_shutdown != 1)) {
            uVar4 = 0x29b;
LAB_000e970c:
            uVar6 = 0x100;
            goto LAB_000e9462;
          }
          goto switchD_000e951e_caseD_3;
        case (BUF_MEM *)0x1:
switchD_000e951e_caseD_1:
          if (*(int *)(*(int *)(param_1->type + 100) + 0x30) << 0x1c < 0) {
            dtls1_stop_timer(param_1);
          }
          uVar3 = 3;
          param_1->shutdown = 0;
          param_1->quiet_shutdown = 3;
          goto LAB_000e9206;
        case (BUF_MEM *)0x2:
switchD_000e951e_caseD_2:
          iVar2 = 0;
          param_1->rstate = 0;
          bVar13 = false;
          break;
        case (BUF_MEM *)0x3:
        case (BUF_MEM *)0x4:
        case (BUF_MEM *)0x5:
          goto switchD_000e951e_caseD_3;
        default:
          goto switchD_000e951e_default;
        }
      } while( true );
    }
    if (uVar3 == 3) {
      pSVar8 = param_1[2].srtp_profile;
      if (pSVar8 == (SRTP_PROTECTION_PROFILE *)0x0) {
        pSVar8 = (SRTP_PROTECTION_PROFILE *)param_1[3].method[1].ssl_renegotiate_check;
      }
      if (param_1->in_handshake == 0) {
        pcVar9 = (code *)0xeb3d9;
        pcVar10 = (code *)0xecba9;
        pcVar12 = (code *)0xeb341;
        pcVar11 = (code *)0xeb0b5;
      }
      else {
        pcVar9 = (code *)0xf3a15;
        pcVar10 = (code *)0xf37a9;
        pcVar12 = (code *)0xf365d;
        pcVar11 = (code *)0xf3311;
      }
      iVar2 = param_1->shutdown;
LAB_000e9248:
      switch(iVar2) {
      case 0:
        if (pSVar8 == (SRTP_PROTECTION_PROFILE *)0x0) {
LAB_000e936c:
          iVar2 = (*pcVar11)(param_1);
        }
        else {
          if (param_1->in_handshake != 0) {
            (*(code *)pSVar8)(param_1,0x2001);
            goto LAB_000e936c;
          }
          (*(code *)pSVar8)(param_1,0x1001,1);
          iVar2 = (*pcVar11)(param_1);
        }
        if (iVar2 == 1) {
          param_1->shutdown = 1;
          param_1->state = 3;
          iVar2 = 1;
          goto LAB_000e9248;
        }
        if (iVar2 == 0) {
          if ((param_1->init_off == 0) || (param_1->quiet_shutdown != 1)) {
            uVar4 = 0x324;
            goto LAB_000e93a2;
          }
          goto switchD_000e951e_caseD_3;
        }
        if (iVar2 != 2) goto switchD_000e930c_default;
        param_1->quiet_shutdown = 2;
        param_1->rstate = 0;
        goto LAB_000e9400;
      case 1:
        iVar2 = (*pcVar12)(param_1,param_1->state);
        param_1->state = iVar2;
        switch(iVar2) {
        case 0:
          if ((param_1->init_off == 0) || (param_1->quiet_shutdown != 1)) {
            uVar4 = 0x32c;
            goto LAB_000e93a2;
          }
          break;
        case 1:
          goto switchD_000e930c_caseD_1;
        case 2:
          param_1->shutdown = 2;
        default:
          iVar2 = (*pcVar9)(param_1,&local_40,&local_48,&local_44);
          if (iVar2 != 0) {
            if (local_44 == -1) goto LAB_000e9600;
            iVar2 = WPACKET_init(&local_40,param_1->hit);
            if ((iVar2 == 0) ||
               (iVar2 = (**(code **)(*(int *)(param_1->type + 100) + 0x34))
                                  (param_1,&local_40,local_44), iVar2 == 0)) {
              WPACKET_cleanup(&local_40);
              uVar4 = 0x348;
              uVar6 = 0x44;
              goto LAB_000e93a8;
            }
            if ((local_48 == (code *)0x0) || (iVar2 = (*local_48)(param_1,&local_40), iVar2 != 0)) {
              iVar2 = (**(code **)(*(int *)(param_1->type + 100) + 0x38))
                                (param_1,&local_40,local_44);
              if ((iVar2 != 0) && (iVar2 = WPACKET_finish(&local_40), iVar2 != 0))
              goto switchD_000e924e_caseD_2;
              WPACKET_cleanup(&local_40);
              uVar4 = 0x354;
              uVar6 = 0x44;
              goto LAB_000e93a8;
            }
            WPACKET_cleanup(&local_40);
            if ((param_1->init_off == 0) || (param_1->quiet_shutdown != 1)) {
              uVar4 = 0x34d;
              goto LAB_000e93a2;
            }
          }
          break;
        case 3:
        case 4:
        case 5:
          break;
        }
        goto switchD_000e951e_caseD_3;
      case 2:
switchD_000e924e_caseD_2:
        iVar2 = *(int *)(param_1->type + 100);
        if (*(int *)(iVar2 + 0x30) << 0x1c < 0) {
          if (param_1->d1 == (dtls1_state_st *)0x0) {
            if (param_1->init_msg != (void *)0x23 && param_1->init_msg != (void *)0x10) {
LAB_000e94a8:
              iVar2 = (**(code **)(iVar2 + 0x3c))(param_1);
              goto LAB_000e92ee;
            }
          }
          else {
            dtls1_start_timer(param_1);
            iVar2 = *(int *)(param_1->type + 100);
            if (param_1->init_msg != (void *)0x23 && param_1->init_msg != (void *)0x10)
            goto LAB_000e94a8;
            if (-1 < *(int *)(iVar2 + 0x30) << 0x1c) goto LAB_000e947c;
          }
          iVar2 = dtls1_do_write(param_1,0x14);
        }
        else {
          if (param_1->init_msg != (void *)0x23 && param_1->init_msg != (void *)0x10)
          goto LAB_000e94a8;
LAB_000e947c:
          iVar2 = ssl3_do_write(param_1,0x14);
        }
LAB_000e92ee:
        if (iVar2 < 1) goto switchD_000e951e_caseD_3;
        iVar2 = 3;
        param_1->shutdown = 3;
        param_1->state = 3;
        break;
      case 3:
        iVar2 = param_1->state;
        break;
      default:
        uVar4 = 0x37b;
        uVar6 = 0x44;
        goto LAB_000e93a8;
      }
      iVar2 = (*pcVar10)(param_1,iVar2);
      param_1->state = iVar2;
      switch(iVar2) {
      case 0:
        if ((param_1->init_off == 0) || (param_1->quiet_shutdown != 1)) {
          uVar4 = 0x369;
LAB_000e93a2:
          uVar6 = 0x100;
LAB_000e93a8:
          ossl_statem_fatal(param_1,0x50,0x24a,uVar6,"ssl/statem/statem.c",uVar4);
        }
        goto switchD_000e951e_caseD_3;
      case 1:
switchD_000e930c_caseD_1:
        param_1->quiet_shutdown = 4;
        goto LAB_000e938a;
      case 2:
        iVar2 = 0;
        param_1->shutdown = 0;
        break;
      case 3:
      case 4:
      case 5:
        goto switchD_000e951e_caseD_3;
      default:
switchD_000e930c_default:
        iVar2 = param_1->shutdown;
      }
      goto LAB_000e9248;
    }
    iVar2 = param_1->init_off;
    if (iVar2 != 0) {
      iVar2 = 1;
    }
    if (uVar3 != 1) {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      ossl_statem_fatal(param_1,0x50,0x161,0x100,"ssl/statem/statem.c",0x1c7);
    }
    ERR_put_error(0x14,0x161,0x42,"ssl/statem/statem.c",0x1c8);
  }
switchD_000e951e_caseD_3:
  uVar6 = 0xffffffff;
  pBVar7 = (BUF_MEM *)0x0;
LAB_000e9184:
  param_1->packet_length = param_1->packet_length - 1;
  BUF_MEM_free(pBVar7);
  if (local_58 != (SRTP_PROTECTION_PROFILE *)0x0) {
    if (param_2 != 0) {
      (*(code *)local_58)(param_1,0x2002,uVar6);
      return uVar6;
    }
    (*(code *)local_58)(param_1,0x1002);
  }
  return uVar6;
LAB_000e9600:
  param_1->shutdown = 3;
  iVar2 = 3;
  param_1->state = 3;
  goto LAB_000e9248;
switchD_000e951e_default:
  iVar2 = param_1->rstate;
  goto LAB_000e9446;
}

