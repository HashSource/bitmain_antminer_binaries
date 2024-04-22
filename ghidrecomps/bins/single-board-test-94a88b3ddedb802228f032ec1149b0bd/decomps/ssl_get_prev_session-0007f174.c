
undefined4 ssl_get_prev_session(undefined4 *param_1,void *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  time_t tVar4;
  SSL_CTX *pSVar5;
  int iVar6;
  size_t __n;
  SSL_SESSION *pSVar7;
  uint uVar8;
  SSL_SESSION **ppSVar9;
  SSL_SESSION *local_114;
  int local_110;
  undefined4 local_10c;
  uint local_c8;
  undefined auStack_c4 [172];
  
  local_114 = (SSL_SESSION *)0x0;
  if (param_3 < 0x21) {
    if ((int)param_2 + param_3 <= param_4) {
      ppSVar9 = &local_114;
      uVar8 = param_3;
      if (param_3 != 0) {
        uVar8 = 1;
      }
      uVar2 = tls1_process_ticket();
      switch(uVar2) {
      case 0:
      case 1:
        if (uVar8 == 0) goto switchD_0007f2a2_caseD_2;
        if (local_114 == (SSL_SESSION *)0x0) {
          iVar3 = param_1[0x5c];
          if (-1 < *(int *)(iVar3 + 0x20) << 0x17) {
            local_10c = *param_1;
            if (param_3 == 0) goto LAB_0007f282;
            local_c8 = param_3;
            memcpy(auStack_c4,param_2,param_3);
            CRYPTO_lock(5,0xc,DAT_0007f404,0x268);
            local_114 = (SSL_SESSION *)lh_retrieve(*(_LHASH **)(param_1[0x5c] + 0x10),&local_10c);
            if (local_114 != (SSL_SESSION *)0x0) {
              ppSVar9 = (SSL_SESSION **)0x26c;
              CRYPTO_add_lock((int *)(local_114->krb5_client_princ + 0x14),1,0xe,DAT_0007f404,0x26c)
              ;
            }
            CRYPTO_lock(6,0xc,DAT_0007f404,0x26e);
            if (local_114 != (SSL_SESSION *)0x0) goto LAB_0007f2c2;
            iVar3 = param_1[0x5c];
            *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x4c) + 1;
          }
          if (*(code **)(iVar3 + 0x30) == (code *)0x0) goto LAB_0007f282;
          local_110 = 1;
          local_114 = (SSL_SESSION *)
                      (**(code **)(iVar3 + 0x30))(param_1,param_2,param_3,&local_110,ppSVar9);
          if (local_114 != (SSL_SESSION *)0x0) {
            pSVar5 = (SSL_CTX *)param_1[0x5c];
            (pSVar5->stats).sess_cb_hit = (pSVar5->stats).sess_cb_hit + 1;
            if (local_110 != 0) {
              CRYPTO_add_lock((int *)(local_114->krb5_client_princ + 0x14),1,0xe,DAT_0007f404,0x282)
              ;
              pSVar5 = (SSL_CTX *)param_1[0x5c];
            }
            if (-1 < pSVar5->session_cache_mode << 0x16) {
              SSL_CTX_add_session(pSVar5,local_114);
            }
          }
          uVar8 = 1;
          goto LAB_0007f244;
        }
LAB_0007f2c2:
        uVar8 = 1;
        break;
      case 2:
      case 3:
switchD_0007f2a2_caseD_2:
        uVar8 = 0;
LAB_0007f244:
        if (local_114 == (SSL_SESSION *)0x0) goto LAB_0007f282;
        break;
      default:
                    /* WARNING: Subroutine does not return */
        abort();
      case 0xffffffff:
        bVar1 = true;
        pSVar7 = local_114;
        goto joined_r0x0007f3d0;
      }
      pSVar7 = local_114;
      __n = local_114->sid_ctx_length;
      if ((__n == param_1[0x27]) &&
         (iVar3 = memcmp(local_114->sid_ctx,param_1 + 0x28,__n), iVar3 == 0)) {
        if (((int)(param_1[0x32] << 0x1f) < 0) && (__n == 0)) {
          ERR_put_error(0x14,0xd9,0x115,DAT_0007f404,0x2ad);
          bVar1 = true;
          pSVar7 = local_114;
        }
        else {
          if (*(int *)(pSVar7->krb5_client_princ + 0x24) == 0) {
            uVar2 = *(undefined4 *)(pSVar7->krb5_client_princ + 0x28);
            if (pSVar7->ssl_version < 0x300) {
              iVar3 = (int)&local_10c + 1;
            }
            else {
              iVar3 = (int)&local_10c + 2;
            }
            uVar2 = ssl_get_cipher_by_char(param_1,iVar3);
            *(undefined4 *)(pSVar7->krb5_client_princ + 0x24) = uVar2;
            pSVar7 = local_114;
            if (*(int *)(local_114->krb5_client_princ + 0x24) == 0) goto LAB_0007f250;
          }
          iVar3 = *(int *)(pSVar7->krb5_client_princ + 0x18);
          tVar4 = time((time_t *)0x0);
          if (tVar4 - *(int *)(local_114->krb5_client_princ + 0x1c) <= iVar3) {
            iVar3 = param_1[0x30];
            *(int *)(param_1[0x5c] + 0x58) = *(int *)(param_1[0x5c] + 0x58) + 1;
            if ((iVar3 != 0) &&
               (iVar6 = CRYPTO_add_lock((int *)(iVar3 + 0xa4),-1,0xe,DAT_0007f404,0x352), iVar6 < 1)
               ) {
              SSL_SESSION_free_part_0(iVar3);
            }
            uVar2 = *(undefined4 *)(local_114->krb5_client_princ + 0x10);
            param_1[0x30] = local_114;
            param_1[0x3b] = uVar2;
            return 1;
          }
          pSVar5 = (SSL_CTX *)param_1[0x5c];
          (pSVar5->stats).sess_timeout = (pSVar5->stats).sess_timeout + 1;
          pSVar7 = local_114;
          if (uVar8 == 0) goto LAB_0007f250;
          uVar8 = 1;
          SSL_CTX_remove_session(pSVar5,local_114);
          bVar1 = false;
          pSVar7 = local_114;
        }
joined_r0x0007f3d0:
        local_114 = pSVar7;
        if (pSVar7 != (SSL_SESSION *)0x0) goto LAB_0007f252;
      }
      else {
LAB_0007f250:
        bVar1 = false;
LAB_0007f252:
        iVar3 = CRYPTO_add_lock((int *)(pSVar7->krb5_client_princ + 0x14),-1,0xe,DAT_0007f404,0x352)
        ;
        if (iVar3 < 1) {
          SSL_SESSION_free_part_0(pSVar7);
        }
        if (uVar8 == 0) {
          param_1[0x50] = 1;
        }
      }
      if (!bVar1) goto LAB_0007f282;
    }
    uVar2 = 0xffffffff;
  }
  else {
LAB_0007f282:
    uVar2 = 0;
  }
  return uVar2;
}

