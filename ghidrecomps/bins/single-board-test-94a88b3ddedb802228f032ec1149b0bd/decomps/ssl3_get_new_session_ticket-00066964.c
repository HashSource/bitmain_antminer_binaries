
int ssl3_get_new_session_ticket(int param_1)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  EVP_MD *type;
  SSL_CTX *ctx;
  undefined4 uVar4;
  uint uVar5;
  SSL_SESSION *c;
  byte *pbVar6;
  int local_1c;
  
  iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x11e0,0x11e1,4,0x4000,&local_1c);
  if (local_1c == 0) {
    return iVar2;
  }
  if (iVar2 < 6) {
    iVar2 = 0x8ba;
LAB_00066a82:
    ERR_put_error(0x14,0x11b,0x9f,DAT_00066ad4,iVar2);
    uVar4 = 0x32;
  }
  else {
    c = *(SSL_SESSION **)(param_1 + 0xc0);
    pbVar6 = *(byte **)(param_1 + 0x40);
    if (c->session_id_length == 0) {
LAB_000669a4:
      bVar1 = *pbVar6;
      *(uint *)(c->krb5_client_princ + 0x5c) = (uint)bVar1 << 0x18;
      uVar5 = (uint)bVar1 << 0x18 | (uint)pbVar6[1] << 0x10;
      *(uint *)(c->krb5_client_princ + 0x5c) = uVar5;
      uVar5 = uVar5 | (uint)pbVar6[2] << 8;
      *(uint *)(c->krb5_client_princ + 0x5c) = uVar5;
      *(uint *)(c->krb5_client_princ + 0x5c) = uVar5 | pbVar6[3];
      uVar5 = (uint)CONCAT11(pbVar6[4],pbVar6[5]);
      if (uVar5 + 6 == iVar2) {
        if (*(void **)(c->krb5_client_princ + 0x54) != (void *)0x0) {
          CRYPTO_free(*(void **)(c->krb5_client_princ + 0x54));
          c = *(SSL_SESSION **)(param_1 + 0xc0);
          *(undefined4 *)(c->krb5_client_princ + 0x58) = 0;
        }
        pvVar3 = CRYPTO_malloc(uVar5,DAT_00066ad4,0x8eb);
        iVar2 = *(int *)(param_1 + 0xc0);
        *(void **)(c->krb5_client_princ + 0x54) = pvVar3;
        pvVar3 = *(void **)(iVar2 + 0xe4);
        if (pvVar3 != (void *)0x0) {
          memcpy(pvVar3,pbVar6 + 6,uVar5);
          iVar2 = *(int *)(param_1 + 0xc0);
          *(uint *)(iVar2 + 0xe8) = uVar5;
          type = EVP_sha256();
          EVP_Digest(pbVar6 + 6,uVar5,(uchar *)(iVar2 + 0x48),(uint *)(iVar2 + 0x44),type,
                     (ENGINE *)0x0);
          return 1;
        }
        ERR_put_error(0x14,0x11b,0x41,DAT_00066ad4,0x8ed);
        goto LAB_00066a9c;
      }
      iVar2 = 0x8e4;
      goto LAB_00066a82;
    }
    ctx = *(SSL_CTX **)(param_1 + 0x170);
    if (ctx->session_cache_mode << 0x1f < 0) {
      if (ctx->session_cache_mode << 0x16 < 0) {
        if (ctx->remove_session_cb != (_func_3230 *)0x0) {
          (*ctx->remove_session_cb)(ctx,c);
          c = *(SSL_SESSION **)(param_1 + 0xc0);
        }
      }
      else {
        SSL_CTX_remove_session(ctx,c);
        c = *(SSL_SESSION **)(param_1 + 0xc0);
      }
    }
    c = (SSL_SESSION *)ssl_session_dup(c,0);
    if (c != (SSL_SESSION *)0x0) {
      SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0xc0));
      *(SSL_SESSION **)(param_1 + 0xc0) = c;
      goto LAB_000669a4;
    }
    ERR_put_error(0x14,0x11b,0x41,DAT_00066ad4,0x8d7);
    uVar4 = 0x50;
  }
  ssl3_send_alert(param_1,2,uVar4);
LAB_00066a9c:
  *(undefined4 *)(param_1 + 0x34) = 5;
  return -1;
}

