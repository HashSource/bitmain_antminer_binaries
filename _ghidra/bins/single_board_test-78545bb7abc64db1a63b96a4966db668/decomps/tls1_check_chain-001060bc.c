
uint tls1_check_chain(SSL *param_1,X509 *param_2,EVP_PKEY *param_3,int param_4,uint param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  X509_NAME *pXVar5;
  int iVar6;
  X509 *a;
  X509_NAME *pXVar7;
  int iVar8;
  char *pcVar9;
  int *piVar10;
  uint uVar11;
  char *pcVar12;
  undefined1 *puVar13;
  short *psVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint local_40;
  int local_3c;
  uint *local_38;
  uint local_2c [2];
  
  piVar18 = (int *)param_1[2].error;
  uVar11 = piVar18[4] & 0x30000;
  if (param_5 == 0xffffffff) {
    if (param_3 == (EVP_PKEY *)0x0 || param_2 == (X509 *)0x0) {
      return 0;
    }
    uVar15 = 0;
    iVar2 = ssl_cert_lookup_by_pkey(param_3,local_2c);
    if (iVar2 == 0) {
      return 0;
    }
    local_3c = local_2c[0] * 4;
    local_38 = (uint *)(param_1->mac_flags + 0x27c + local_3c);
    if ((piVar18[4] & 0x30001U) == 0) {
      local_40 = 0x850;
      uVar16 = 0x50;
    }
    else {
      local_40 = 0xef0;
      uVar16 = 0x6f0;
    }
    param_5 = local_2c[0];
    if (uVar11 == 0) {
      uVar17 = 1;
      local_40 = uVar16;
LAB_00106168:
      iVar2 = SSL_version(param_1);
      uVar15 = uVar11;
      if (iVar2 >> 8 != 3) {
LAB_00106176:
        if (local_40 != 0) {
          uVar11 = uVar15 | 0x30;
          goto LAB_001062e8;
        }
        iVar2 = tls1_check_cert_param(param_1,param_2,1);
        if (iVar2 == 0) goto LAB_00106126;
        goto LAB_0010618c;
      }
      uVar11 = uVar17;
      if (uVar17 != 0) {
        uVar11 = 1;
      }
LAB_0010631e:
      iVar2 = SSL_version(param_1);
      if (iVar2 < 0x303) {
        uVar11 = 0;
      }
      else {
        uVar11 = uVar11 & 1;
      }
      if (uVar11 == 0) goto LAB_00106176;
      if (*(int *)(param_1->mac_flags + 0x26c) == 0) {
        iVar2 = 0;
        if (*(int *)(param_1->mac_flags + 0x268) != 0) goto LAB_0010634c;
        if (6 < param_5) {
          iVar2 = -1;
          goto LAB_0010634c;
        }
        iVar2 = *(int *)(CSWTCH_165 + local_3c);
        if (iVar2 < 1) goto LAB_0010634c;
        if (piVar18[0x34] == 0) {
LAB_001065a6:
          piVar18 = (int *)param_1->type;
          local_3c = iVar2;
          if (-1 < *(int *)(piVar18[0x19] + 0x30) << 0x1c) goto LAB_00106356;
          goto LAB_00106458;
        }
        iVar4 = piVar18[0x35];
        uVar11 = uVar15;
        uVar16 = uVar15;
        if (iVar4 != 0) {
          psVar14 = (short *)(piVar18[0x34] + -2);
          iVar6 = 0;
          do {
            psVar14 = psVar14 + 1;
            puVar13 = &sigalg_lookup_tbl;
            do {
              if (*(short *)(puVar13 + 4) == *psVar14) {
                if ((*(int *)(puVar13 + 8) == 0x40) &&
                   (*(int *)(CSWTCH_166 + local_3c) == *(int *)(puVar13 + 0x10))) {
                  if (iVar6 != iVar4) goto LAB_001065a6;
                  goto joined_r0x00106596;
                }
                break;
              }
              puVar13 = puVar13 + 0x20;
            } while (puVar13 != legacy_rsa_sigalg);
            iVar6 = iVar6 + 1;
          } while (iVar4 != iVar6);
        }
joined_r0x00106596:
        uVar15 = uVar16;
        if (local_40 == 0) goto LAB_00106126;
        goto LAB_001062e8;
      }
      local_3c = 0;
      iVar2 = local_3c;
LAB_0010634c:
      local_3c = iVar2;
      piVar18 = (int *)param_1->type;
      if (*(int *)(piVar18[0x19] + 0x30) << 0x1c < 0) {
LAB_00106452:
        if (local_3c == -1) {
LAB_0010637e:
          uVar15 = uVar15 | 0x10;
          goto LAB_00106382;
        }
LAB_00106458:
        iVar2 = tls1_check_sig_alg_part_10(param_1,param_2,local_3c);
        if (iVar2 != 0) goto LAB_0010637e;
        if (local_40 == 0) goto LAB_00106126;
        uVar16 = uVar15 | 0x20;
LAB_00106474:
        iVar2 = 0;
        do {
          iVar4 = OPENSSL_sk_num(param_4);
          if (iVar4 <= iVar2) goto LAB_001063a8;
          uVar3 = OPENSSL_sk_value(param_4,iVar2);
          iVar4 = tls1_check_sig_alg_part_10(param_1,uVar3,local_3c);
          iVar2 = iVar2 + 1;
          uVar11 = uVar15;
        } while (iVar4 != 0);
        goto joined_r0x00106596;
      }
LAB_00106356:
      if (*piVar18 == 0x10000 || *piVar18 < 0x304) goto LAB_00106452;
      iVar2 = find_sig_alg(param_1,param_2,param_3);
      if (iVar2 != 0) goto LAB_0010637e;
LAB_00106382:
      uVar16 = uVar15 | 0x20;
      if (local_3c != -1) goto LAB_00106474;
      iVar2 = 0;
      while( true ) {
        iVar4 = OPENSSL_sk_num(param_4);
        if (iVar4 <= iVar2) break;
        OPENSSL_sk_value(param_4,iVar2);
        iVar2 = iVar2 + 1;
      }
LAB_001063a8:
      uVar15 = uVar16;
      iVar2 = tls1_check_cert_param(param_1,param_2,1);
      if (iVar2 != 0) goto LAB_0010618c;
      uVar11 = uVar15;
      if (local_40 == 0) goto LAB_00106126;
    }
    else {
      iVar2 = X509_chain_check_suiteb(0,param_2,param_4);
      if (iVar2 == 0) {
        uVar17 = 1;
        uVar11 = 0x800;
        goto LAB_00106168;
      }
      iVar2 = SSL_version(param_1);
      if (iVar2 >> 8 == 3) {
        uVar11 = 1;
        uVar17 = uVar11;
        goto LAB_0010631e;
      }
      uVar11 = 0x30;
      uVar17 = 1;
LAB_001062e8:
      iVar2 = tls1_check_cert_param(param_1,param_2,1);
      uVar15 = uVar11;
      if (iVar2 != 0) {
LAB_0010618c:
        uVar11 = uVar15 | 0x40;
      }
    }
    if (param_1->in_handshake == 0) {
      iVar2 = 0;
LAB_0010619a:
      uVar11 = uVar11 | 0x80;
      if (uVar17 != 0) {
        uVar17 = 1;
      }
      if (iVar2 != 0) {
        uVar17 = 0;
      }
      uVar15 = uVar11;
      if (uVar17 == 0) {
LAB_001061ae:
        uVar15 = uVar11 | 0x600;
        if (local_40 != 0) goto LAB_001062dc;
      }
      else {
LAB_001063c2:
        iVar2 = EVP_PKEY_id(param_3);
        if (iVar2 == 0x74) {
          cVar1 = '\x02';
LAB_0010640c:
          iVar2 = param_1->mac_flags;
          pcVar12 = *(char **)(iVar2 + 0x21c);
          if (*(int *)(iVar2 + 0x220) != 0) {
            if (*pcVar12 != cVar1) {
              pcVar9 = pcVar12 + *(int *)(iVar2 + 0x220);
              do {
                pcVar12 = pcVar12 + 1;
                if (pcVar9 == pcVar12) goto LAB_00106432;
              } while (*pcVar12 != cVar1);
            }
            uVar15 = uVar15 | 0x400;
          }
LAB_00106432:
          if ((uVar15 & 0x400) == 0 && local_40 == 0) {
            local_40 = 0;
            goto LAB_00106126;
          }
        }
        else {
          if (iVar2 == 0x198) {
            cVar1 = '@';
            goto LAB_0010640c;
          }
          if (iVar2 == 6) {
            cVar1 = '\x01';
            goto LAB_0010640c;
          }
          iVar2 = param_1->mac_flags;
          uVar15 = uVar15 | 0x400;
        }
        iVar2 = *(int *)(iVar2 + 0x224);
        if ((iVar2 != 0) && (iVar4 = OPENSSL_sk_num(iVar2), iVar4 != 0)) {
          pXVar5 = X509_get_issuer_name(param_2);
          iVar4 = 0;
LAB_001064d0:
          iVar6 = OPENSSL_sk_num(iVar2);
          if (iVar4 < iVar6) goto LAB_001064c0;
          for (iVar6 = 0; iVar4 = OPENSSL_sk_num(param_4,iVar4), iVar6 < iVar4; iVar6 = iVar6 + 1) {
            a = (X509 *)OPENSSL_sk_value(param_4,iVar6);
            pXVar5 = X509_get_issuer_name(a);
            iVar4 = 0;
            while( true ) {
              iVar8 = OPENSSL_sk_num(iVar2);
              if (iVar8 <= iVar4) break;
              pXVar7 = (X509_NAME *)OPENSSL_sk_value(iVar2);
              iVar8 = X509_NAME_cmp(pXVar5,pXVar7);
              iVar4 = iVar4 + 1;
              if (iVar8 == 0) goto LAB_001063ec;
            }
          }
          goto LAB_001063f0;
        }
LAB_001063ec:
        uVar15 = uVar15 | 0x200;
LAB_001063f0:
        if (local_40 != 0) goto LAB_001062dc;
        if (-1 < (int)(uVar15 << 0x16)) goto LAB_00106126;
      }
    }
    else {
      uVar15 = uVar11 | 0x80;
      iVar2 = 0;
      if (uVar17 == 0) goto LAB_001061ae;
      do {
        iVar4 = OPENSSL_sk_num(param_4);
        if (iVar4 <= iVar2) {
          iVar2 = param_1->in_handshake;
          goto LAB_0010619a;
        }
        uVar3 = OPENSSL_sk_value(param_4,iVar2);
        iVar4 = tls1_check_cert_param(param_1,uVar3,0);
        iVar2 = iVar2 + 1;
      } while (iVar4 != 0);
      if (local_40 == 0) goto LAB_00106126;
      uVar15 = uVar11;
      if (param_1->in_handshake == 0) goto LAB_001063c2;
      uVar15 = uVar11 | 0x600;
LAB_001062dc:
      if ((local_40 & ~uVar15) != 0) goto LAB_00106126;
    }
    uVar15 = uVar15 | 1;
    iVar2 = SSL_version(param_1);
  }
  else {
    if (param_5 == 0xfffffffe) {
      piVar10 = (int *)*piVar18;
      local_3c = (int)piVar10 - (int)(piVar18 + 5) >> 2;
      param_5 = local_3c * -0x33333333;
      local_3c = local_3c * 0x33333334;
    }
    else {
      local_3c = param_5 * 4;
      piVar10 = piVar18 + param_5 * 5 + 5;
    }
    param_2 = (X509 *)*piVar10;
    param_3 = (EVP_PKEY *)piVar10[1];
    uVar17 = piVar18[4] & 0x30001;
    local_38 = (uint *)(param_1->mac_flags + 0x27c + local_3c);
    if (param_3 != (EVP_PKEY *)0x0 && param_2 != (X509 *)0x0) {
      uVar15 = 0;
      param_4 = piVar10[2];
      if (uVar11 == 0) {
        local_40 = 0;
      }
      else {
        iVar2 = X509_chain_check_suiteb(0,param_2,param_4);
        if (iVar2 != 0) {
          local_40 = 0;
          goto LAB_00106126;
        }
        uVar11 = 0x800;
        local_40 = 0;
      }
      goto LAB_00106168;
    }
    uVar15 = 0;
    local_40 = 0;
LAB_00106126:
    iVar2 = SSL_version(param_1);
  }
  if ((iVar2 >> 8 == 3) && (iVar2 = SSL_version(param_1), 0x302 < iVar2)) {
    uVar15 = uVar15 | *local_38 & 0x102;
  }
  else {
    uVar15 = uVar15 | 0x102;
  }
  if (local_40 == 0) {
    if ((uVar15 & 1) == 0) {
      *local_38 = *local_38 & 0x102;
      uVar15 = 0;
    }
    else {
      *local_38 = uVar15;
    }
  }
  return uVar15;
LAB_001064c0:
  pXVar7 = (X509_NAME *)OPENSSL_sk_value(iVar2,iVar4);
  iVar6 = X509_NAME_cmp(pXVar5,pXVar7);
  iVar4 = iVar4 + 1;
  if (iVar6 == 0) goto LAB_001063ec;
  goto LAB_001064d0;
}

