
SSL_SESSION * d2i_SSL_SESSION(SSL_SESSION **a,uchar **pp,long length)

{
  ASN1_VALUE *val;
  SSL_CIPHER *pSVar1;
  long lVar2;
  ssl_session_st *psVar3;
  void *ptr;
  char *pcVar4;
  int iVar5;
  size_t sVar6;
  uint uVar7;
  long lVar8;
  int *piVar9;
  byte *pbVar10;
  size_t *psVar11;
  uint *puVar12;
  uchar *puVar13;
  SSL_SESSION *ses;
  undefined4 *puVar14;
  uchar *local_24 [2];
  
  local_24[0] = *pp;
  val = ASN1_item_d2i((ASN1_VALUE **)0x0,local_24,length,(ASN1_ITEM *)&SSL_SESSION_ASN1_it);
  if (val == (ASN1_VALUE *)0x0) {
    ses = (SSL_SESSION *)0x0;
LAB_000fd3f2:
    ASN1_item_free(val,(ASN1_ITEM *)&SSL_SESSION_ASN1_it);
    if (a == (SSL_SESSION **)0x0) goto LAB_000fd408;
  }
  else {
    if (a == (SSL_SESSION **)0x0) {
      ses = SSL_SESSION_new();
      if (ses == (SSL_SESSION *)0x0) {
        ASN1_item_free(val,(ASN1_ITEM *)&SSL_SESSION_ASN1_it);
        goto LAB_000fd408;
      }
LAB_000fd3d8:
      if (*(int *)val == 1) {
        iVar5 = *(int *)(val + 4);
        if (iVar5 == 0x100 || (iVar5 >> 8 == 3 || iVar5 >> 8 == 0xfe)) {
          piVar9 = *(int **)(val + 8);
          ses->ssl_version = iVar5;
          if (*piVar9 == 2) {
            pbVar10 = (byte *)piVar9[2];
            ses->cipher_id = pbVar10[1] | 0x3000000 | (uint)*pbVar10 << 8;
            pSVar1 = (SSL_CIPHER *)ssl3_get_cipher_by_id();
            ses->cipher = pSVar1;
            if (pSVar1 != (SSL_CIPHER *)0x0) {
              psVar11 = *(size_t **)(val + 0x14);
              if ((psVar11 == (size_t *)0x0) || (sVar6 = *psVar11, sVar6 == 0)) {
                ses->krb5_client_princ[0xb8] = '\0';
                ses->krb5_client_princ[0xb9] = '\0';
                ses->krb5_client_princ[0xba] = '\0';
                ses->krb5_client_princ[0xbb] = '\0';
              }
              else {
                if (0x20 < sVar6) goto LAB_000fd3f2;
                memcpy(ses->krb5_client_princ + 0xbc,(void *)psVar11[2],sVar6);
                *(size_t *)(ses->krb5_client_princ + 0xb8) = *psVar11;
              }
              puVar12 = *(uint **)(val + 0x10);
              if (puVar12 == (uint *)0x0) {
                uVar7 = 0;
              }
              else {
                uVar7 = *puVar12;
                if (uVar7 != 0) {
                  if (0x100 < uVar7) goto LAB_000fd3f2;
                  memcpy(ses->session_id,(void *)puVar12[2],uVar7);
                  uVar7 = *puVar12;
                }
              }
              lVar2 = *(long *)(val + 0x20);
              iVar5 = *(int *)(val + 0x24);
              ses->key_arg_length = uVar7;
              if (lVar2 == 0 && iVar5 == 0) {
                lVar2 = time((time_t *)0x0);
              }
              lVar8 = *(long *)(val + 0x28);
              iVar5 = *(int *)(val + 0x2c);
              ses->time = lVar2;
              if (lVar8 == 0 && iVar5 == 0) {
                lVar8 = 3;
              }
              ses->timeout = lVar8;
              X509_free((X509 *)ses->sess_cert);
              psVar11 = *(size_t **)(val + 0x34);
              ses->sess_cert = *(sess_cert_st **)(val + 0x30);
              *(undefined4 *)(val + 0x30) = 0;
              if ((psVar11 == (size_t *)0x0) || (sVar6 = *psVar11, sVar6 == 0)) {
                ses->krb5_client_princ[0xdc] = '\0';
                ses->krb5_client_princ[0xdd] = '\0';
                ses->krb5_client_princ[0xde] = '\0';
                ses->krb5_client_princ[0xdf] = '\0';
              }
              else {
                if (0x20 < sVar6) goto LAB_000fd3f2;
                memcpy(ses->krb5_client_princ + 0xe0,(void *)psVar11[2],sVar6);
                *(size_t *)(ses->krb5_client_princ + 0xdc) = *psVar11;
              }
              puVar14 = *(undefined4 **)(val + 0x3c);
              ses->verify_result = *(long *)(val + 0x38);
              CRYPTO_free(ses->prev);
              ses->prev = (ssl_session_st *)0x0;
              if (puVar14 != (undefined4 *)0x0) {
                psVar3 = (ssl_session_st *)CRYPTO_strndup(puVar14[2],*puVar14,"ssl/ssl_asn1.c",0xd9)
                ;
                ses->prev = psVar3;
                if (psVar3 == (ssl_session_st *)0x0) goto LAB_000fd3f2;
              }
              iVar5 = ssl_session_strndup(&ses->psk_identity_hint,*(undefined4 *)(val + 0x50));
              if ((iVar5 != 0) &&
                 (iVar5 = ssl_session_strndup(&ses->psk_identity,*(undefined4 *)(val + 0x54)),
                 iVar5 != 0)) {
                puVar13 = *(uchar **)(val + 0x48);
                ses->tlsext_ecpointformatlist_length = *(size_t *)(val + 0x40);
                ses->tlsext_ecpointformatlist = puVar13;
                CRYPTO_free(ses->next);
                puVar14 = *(undefined4 **)(val + 0x4c);
                if (puVar14 == (undefined4 *)0x0) {
                  ses->next = (ssl_session_st **)0x0;
                }
                else {
                  pcVar4 = (char *)*puVar14;
                  ses->next = (ssl_session_st **)puVar14[2];
                  ses->tlsext_hostname = pcVar4;
                  puVar14[2] = 0;
                }
                piVar9 = *(int **)(val + 0xc);
                if (piVar9 == (int *)0x0) {
                  ses->compress_meth = 0;
                }
                else {
                  if (*piVar9 != 1) {
                    ERR_put_error(0x14,0x67,0x10f,"ssl/ssl_asn1.c",0x156);
                    goto LAB_000fd3f2;
                  }
                  ses->compress_meth = (uint)*(byte *)piVar9[2];
                }
                iVar5 = ssl_session_strndup(&ses->tlsext_tick_lifetime_hint,
                                            *(undefined4 *)(val + 0x58));
                if (iVar5 != 0) {
                  sVar6 = *(size_t *)(val + 0x68);
                  *(undefined4 *)ses[1].key_arg = *(undefined4 *)(val + 0x60);
                  ses->tlsext_ellipticcurvelist_length = sVar6;
                  CRYPTO_free(ses->tlsext_ellipticcurvelist);
                  puVar14 = *(undefined4 **)(val + 0x6c);
                  if (puVar14 == (undefined4 *)0x0) {
                    ses->tlsext_ellipticcurvelist = (uchar *)0x0;
                    ses->tlsext_tick = (uchar *)0x0;
                  }
                  else {
                    puVar13 = (uchar *)*puVar14;
                    ses->tlsext_ellipticcurvelist = (uchar *)puVar14[2];
                    ses->tlsext_tick = puVar13;
                    puVar14[2] = 0;
                  }
                  ptr = (void *)ses[1].ssl_version;
                  *(char *)&ses->tlsext_ticklen = (char)*(undefined4 *)(val + 0x70);
                  CRYPTO_free(ptr);
                  puVar12 = *(uint **)(val + 0x74);
                  if (puVar12 == (uint *)0x0) {
                    ses[1].ssl_version = 0;
                    ses[1].key_arg_length = 0;
                  }
                  else {
                    uVar7 = *puVar12;
                    ses[1].ssl_version = puVar12[2];
                    ses[1].key_arg_length = uVar7;
                    puVar12[2] = 0;
                  }
                  ASN1_item_free(val,(ASN1_ITEM *)&SSL_SESSION_ASN1_it);
                  if ((a != (SSL_SESSION **)0x0) && (*a == (SSL_SESSION *)0x0)) {
                    *a = ses;
                  }
                  *pp = local_24[0];
                  return ses;
                }
              }
            }
          }
          else {
            ERR_put_error(0x14,0x67,0x89,"ssl/ssl_asn1.c",0x114);
          }
        }
        else {
          ERR_put_error(0x14,0x67,0x103,"ssl/ssl_asn1.c",0x10d);
        }
      }
      else {
        ERR_put_error(0x14,0x67,0xfe,"ssl/ssl_asn1.c",0x106);
      }
      goto LAB_000fd3f2;
    }
    ses = *a;
    if ((ses != (SSL_SESSION *)0x0) || (ses = SSL_SESSION_new(), ses != (SSL_SESSION *)0x0))
    goto LAB_000fd3d8;
    ASN1_item_free(val,(ASN1_ITEM *)&SSL_SESSION_ASN1_it);
  }
  if (*a == ses) {
    return (SSL_SESSION *)0x0;
  }
LAB_000fd408:
  SSL_SESSION_free(ses);
  return (SSL_SESSION *)0x0;
}

