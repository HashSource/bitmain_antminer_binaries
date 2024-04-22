
int ssl3_get_cert_verify(int param_1)

{
  uint uVar1;
  int iVar2;
  EVP_PKEY *pubkey;
  int iVar3;
  uint uVar4;
  BIO *a;
  size_t cnt;
  EVP_PKEY_CTX *ctx;
  uchar *sig;
  undefined4 uVar5;
  uint *puVar6;
  uint uVar7;
  X509 *x;
  uchar *puVar8;
  uint siglen;
  int local_84;
  EVP_MD *local_80;
  void *local_7c;
  EVP_MD_CTX EStack_78;
  uchar auStack_60 [64];
  uchar auStack_20 [4];
  
  local_80 = (EVP_MD *)0x0;
  EVP_MD_CTX_init(&EStack_78);
  if (*(int *)(*(int *)(param_1 + 0xc0) + 0x9c) == 0) {
    iVar2 = 1;
    pubkey = (EVP_PKEY *)0x0;
    goto LAB_00087608;
  }
  iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x30))(param_1,0x21a0,0x21a1,0xf,0x4000,&local_84);
  if (local_84 == 0) {
    return iVar2;
  }
  x = *(X509 **)(*(int *)(param_1 + 0xc0) + 0x9c);
  pubkey = X509_get_pubkey(x);
  iVar3 = X509_certificate_type(x,pubkey);
  if (-1 < iVar3 << 0x1b) {
    ERR_put_error(0x14,0x88,0xdc,DAT_0008784c,0xba6);
    uVar5 = 0x2f;
    goto LAB_00087646;
  }
  puVar8 = *(uchar **)(param_1 + 0x40);
  if ((iVar2 == 0x40) && (pubkey->type - 0x32bU < 2)) {
    iVar2 = EVP_PKEY_size(pubkey);
    if (iVar2 < 0x40) {
LAB_00087656:
      ERR_put_error(0x14,0x88,0x109,DAT_0008784c,0xbcf);
      uVar5 = 0x32;
    }
    else {
      siglen = 0x40;
LAB_000875c2:
      if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) & 2) == 0) {
        iVar2 = pubkey->type;
        if (iVar2 == 6) {
          iVar2 = RSA_verify(0x72,(uchar *)(*(int *)(param_1 + 0x58) + 0x1b4),0x24,puVar8,siglen,
                             (pubkey->pkey).rsa);
          if (iVar2 < 0) {
            ERR_put_error(0x14,0x88,0x76,DAT_0008784c,0xbf5);
            uVar5 = 0x33;
          }
          else {
            if (iVar2 != 0) goto LAB_00087754;
            ERR_put_error(0x14,0x88,0x7a,DAT_0008784c,0xbfa);
            uVar5 = 0x33;
          }
        }
        else if (iVar2 == 0x74) {
          iVar2 = DSA_verify(pubkey->save_type,(uchar *)(*(int *)(param_1 + 0x58) + 0x1c4),0x14,
                             puVar8,siglen,(DSA *)(pubkey->pkey).rsa);
          if (0 < iVar2) goto LAB_00087754;
          ERR_put_error(0x14,0x88,0x70,DAT_0008784c,0xc07);
          uVar5 = 0x33;
        }
        else if (iVar2 == 0x198) {
          iVar2 = ECDSA_verify(pubkey->save_type,(uchar *)(*(int *)(param_1 + 0x58) + 0x1c4),0x14,
                               puVar8,siglen,(EC_KEY *)(pubkey->pkey).rsa);
          if (0 < iVar2) goto LAB_00087754;
          iVar2 = 0xc14;
LAB_000877f6:
          ERR_put_error(0x14,0x88,0x131,DAT_0008784c,iVar2);
          uVar5 = 0x33;
        }
        else {
          if (iVar2 - 0x32bU < 2) {
            ctx = EVP_PKEY_CTX_new(pubkey,(ENGINE *)0x0);
            EVP_PKEY_verify_init(ctx);
            if (siglen != 0x40) {
              fprintf(*DAT_00087850,DAT_00087854,siglen);
            }
            puVar8 = puVar8 + -1;
            sig = auStack_20;
            do {
              puVar8 = puVar8 + 1;
              sig = sig + -1;
              *sig = *puVar8;
            } while (sig != auStack_60);
            iVar2 = EVP_PKEY_verify(ctx,sig,0x40,(uchar *)(*(int *)(param_1 + 0x58) + 0x1b4),0x20);
            EVP_PKEY_CTX_free(ctx);
            if (iVar2 < 1) {
              iVar2 = 0xc2a;
              goto LAB_000877f6;
            }
LAB_00087754:
            iVar2 = 1;
            goto LAB_00087608;
          }
          ERR_put_error(0x14,0x88,0x44,DAT_0008784c,0xc2e);
          uVar5 = 0x2b;
        }
      }
      else {
        cnt = BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x58) + 0x178),3,0,&local_7c);
        if ((int)cnt < 1) {
          ERR_put_error(0x14,0x88,0x44,DAT_0008784c,0xbd9);
          uVar5 = 0x50;
        }
        else {
          iVar2 = EVP_DigestInit_ex(&EStack_78,local_80,(ENGINE *)0x0);
          if ((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&EStack_78,local_7c,cnt), iVar2 == 0)) {
            ERR_put_error(0x14,0x88,6,DAT_0008784c,0xbe3);
            uVar5 = 0x50;
          }
          else {
            iVar2 = EVP_VerifyFinal(&EStack_78,puVar8,siglen,pubkey);
            if (0 < iVar2) goto LAB_00087754;
            ERR_put_error(0x14,0x88,0x7b,DAT_0008784c,0xbea);
            uVar5 = 0x33;
          }
        }
      }
    }
  }
  else if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e < 0) {
    iVar3 = tls12_check_peer_sigalg(&local_80,param_1,puVar8,pubkey);
    if (iVar3 == -1) {
      uVar5 = 0x50;
    }
    else {
      if (iVar3 != 0) {
        puVar8 = puVar8 + 2;
        iVar2 = iVar2 + -2;
        goto LAB_0008759c;
      }
      uVar5 = 0x32;
    }
  }
  else {
LAB_0008759c:
    uVar7 = iVar2 - 2;
    siglen = (uint)CONCAT11(*puVar8,puVar8[1]);
    if ((int)siglen <= (int)uVar7) {
      uVar4 = EVP_PKEY_size(pubkey);
      iVar2 = siglen - uVar4;
      uVar1 = siglen;
      if ((int)siglen <= (int)uVar4) {
        iVar2 = uVar7 - uVar4;
        uVar1 = uVar7;
      }
      if ((uVar1 != uVar4 && iVar2 < 0 == SBORROW4(uVar1,uVar4)) || ((int)uVar7 < 1))
      goto LAB_00087656;
      puVar8 = puVar8 + 2;
      goto LAB_000875c2;
    }
    ERR_put_error(0x14,0x88,0x9f,DAT_0008784c,0xbc8);
    uVar5 = 0x32;
  }
LAB_00087646:
  ssl3_send_alert(param_1,2,uVar5);
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0x34) = 5;
LAB_00087608:
  a = *(BIO **)(*(int *)(param_1 + 0x58) + 0x178);
  if (a != (BIO *)0x0) {
    BIO_free(a);
    puVar6 = *(uint **)(param_1 + 0x58);
    puVar6[0x5e] = 0;
    *puVar6 = *puVar6 & 0xffffffdf;
  }
  EVP_MD_CTX_cleanup(&EStack_78);
  EVP_PKEY_free(pubkey);
  return iVar2;
}

