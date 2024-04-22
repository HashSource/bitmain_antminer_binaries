
int ssl3_get_server_certificate(int param_1)

{
  int iVar1;
  X509 *pXVar2;
  X509 **ppXVar3;
  X509 *x;
  X509 *pkey;
  X509 *pXVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint len;
  X509 *a;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  int local_28;
  byte *local_24;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_28);
  if (local_28 == 0) {
    return iVar1;
  }
  iVar5 = *(int *)(param_1 + 0x58);
  iVar6 = *(int *)(iVar5 + 0x340);
  if ((iVar6 == 0xc) || ((*(int *)(*(int *)(iVar5 + 0x344) + 0x10) << 0x1a < 0 && (iVar6 == 0xe))))
  {
    *(undefined4 *)(iVar5 + 0x354) = 1;
    return 1;
  }
  if (iVar6 != 0xb) {
    uVar7 = 10;
    a = (X509 *)0x0;
    ERR_put_error(0x14,0x90,0x72,DAT_0006657c,0x4ad);
    pkey = (X509 *)0x0;
    pXVar2 = (X509 *)0x0;
    goto LAB_000662e4;
  }
  pbVar8 = *(byte **)(param_1 + 0x40);
  pXVar2 = (X509 *)sk_new_null();
  if (pXVar2 == (X509 *)0x0) {
    ERR_put_error(0x14,0x90,0x41,DAT_0006657c,0x4b3);
    a = (X509 *)0x0;
    pkey = (X509 *)0x0;
  }
  else {
    uVar10 = (uint)pbVar8[1] << 8 | (uint)*pbVar8 << 0x10 | (uint)pbVar8[2];
    if (uVar10 + 3 == iVar1) {
      if (uVar10 != 0) {
        pbVar11 = pbVar8 + 6;
        len = (uint)pbVar8[3] << 0x10 | (uint)pbVar8[4] << 8 | (uint)pbVar8[5];
        for (uVar9 = len + 3; uVar9 <= uVar10; uVar9 = uVar9 + len + 3) {
          local_24 = pbVar11;
          a = d2i_X509((X509 **)0x0,&local_24,len);
          if (a == (X509 *)0x0) {
            ERR_put_error(0x14,0x90,0xd,DAT_0006657c,0x4ca);
            uVar7 = 0x2a;
            pkey = (X509 *)0x0;
            goto LAB_000662e4;
          }
          if (local_24 != pbVar11 + len) {
            ERR_put_error(0x14,0x90,0x87,DAT_0006657c,0x4d0);
            pkey = (X509 *)0x0;
            uVar7 = 0x32;
            goto LAB_000662e4;
          }
          iVar1 = sk_push((_STACK *)pXVar2,a);
          if (iVar1 == 0) {
            ERR_put_error(0x14,0x90,0x41,DAT_0006657c,0x4d4);
            pkey = (X509 *)0x0;
            goto LAB_000662ee;
          }
          if (uVar10 <= uVar9) goto LAB_000663e4;
          pbVar11 = local_24 + 3;
          len = (uint)local_24[1] << 8 | (uint)*local_24 << 0x10 | (uint)local_24[2];
        }
        iVar5 = 0x4c2;
        iVar1 = 0x87;
        goto LAB_000663d6;
      }
LAB_000663e4:
      iVar1 = ssl_verify_cert_chain(param_1,pXVar2);
      if ((*(int *)(param_1 + 200) == 0) || (0 < iVar1)) {
        ERR_clear_error();
        ppXVar3 = (X509 **)ssl_sess_cert_new();
        if (ppXVar3 == (X509 **)0x0) {
          a = (X509 *)0x0;
          pkey = (X509 *)0x0;
          goto LAB_000662ee;
        }
        iVar1 = *(int *)(param_1 + 0xc0);
        if (*(int *)(iVar1 + 0x98) != 0) {
          ssl_sess_cert_free();
          iVar1 = *(int *)(param_1 + 0xc0);
        }
        *(X509 ***)(iVar1 + 0x98) = ppXVar3;
        *ppXVar3 = pXVar2;
        x = (X509 *)sk_value((_STACK *)pXVar2,0);
        pkey = (X509 *)X509_get_pubkey(x);
        iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
        if ((*(int *)(iVar1 + 0xc) << 0x1b < 0) && (*(int *)(iVar1 + 0x10) << 0x1a < 0)) {
          pXVar2 = (X509 *)ssl_cert_type(x,pkey);
          iVar1 = *(int *)(param_1 + 0xc0);
          ppXVar3[1] = pXVar2;
          ppXVar3[2] = (X509 *)0x0;
          if (*(X509 **)(iVar1 + 0x9c) != (X509 *)0x0) {
            X509_free(*(X509 **)(iVar1 + 0x9c));
            iVar1 = *(int *)(param_1 + 0xc0);
          }
          *(undefined4 *)(iVar1 + 0x9c) = 0;
LAB_0006646a:
          pXVar2 = (X509 *)0x0;
          a = (X509 *)0x0;
          iVar5 = 1;
          *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(param_1 + 0xec);
          goto LAB_000662f6;
        }
        if ((pkey == (X509 *)0x0) ||
           (iVar1 = EVP_PKEY_missing_parameters((EVP_PKEY *)pkey), iVar1 != 0)) {
          pXVar2 = (X509 *)0x0;
          uVar7 = 2;
          ERR_put_error(0x14,0x90,0xef,DAT_0006657c,0x511);
          a = (X509 *)0x0;
        }
        else {
          pXVar4 = (X509 *)ssl_cert_type(x,pkey);
          a = (X509 *)0x0;
          pXVar2 = a;
          if ((int)pXVar4 < 0) {
            uVar7 = 2;
            ERR_put_error(0x14,0x90,0xf7,DAT_0006657c,0x51a);
          }
          else {
            iVar1 = ssl_cipher_get_cert_index(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x344));
            iVar5 = (int)pXVar4 - iVar1;
            if (iVar5 != 0) {
              iVar5 = 1;
            }
            if (iVar1 < 0) {
              iVar5 = 0;
            }
            if (iVar5 == 0) {
              ppXVar3[1] = pXVar4;
              CRYPTO_add_lock(&x->references,1,3,DAT_000665ec,0x528);
              if (ppXVar3[(int)pXVar4 * 7 + 3] != (X509 *)0x0) {
                X509_free(ppXVar3[(int)pXVar4 * 7 + 3]);
              }
              pXVar2 = *(X509 **)(*(int *)(param_1 + 0xc0) + 0x9c);
              ppXVar3[(int)pXVar4 * 7 + 3] = x;
              ppXVar3[2] = (X509 *)(ppXVar3 + (int)pXVar4 * 7 + 3);
              if (pXVar2 != (X509 *)0x0) {
                X509_free(pXVar2);
              }
              CRYPTO_add_lock(&x->references,1,3,DAT_000665ec,0x534);
              iVar1 = *(int *)(param_1 + 0xc0);
              *(X509 **)(iVar1 + 0x9c) = x;
              goto LAB_0006646a;
            }
            uVar7 = 0x2f;
            ERR_put_error(0x14,0x90,0x17f,DAT_0006657c,0x524);
          }
        }
      }
      else {
        pkey = (X509 *)0x0;
        uVar7 = ssl_verify_alarm_type(*(undefined4 *)(param_1 + 0xec));
        a = (X509 *)0x0;
        ERR_put_error(0x14,0x90,0x86,DAT_0006657c,0x4e5);
      }
    }
    else {
      iVar1 = 0x9f;
      iVar5 = 0x4ba;
LAB_000663d6:
      a = (X509 *)0x0;
      uVar7 = 0x32;
      ERR_put_error(0x14,0x90,iVar1,DAT_0006657c,iVar5);
      pkey = a;
    }
LAB_000662e4:
    ssl3_send_alert(param_1,2,uVar7);
  }
LAB_000662ee:
  iVar5 = -1;
  *(undefined4 *)(param_1 + 0x34) = 5;
LAB_000662f6:
  EVP_PKEY_free((EVP_PKEY *)pkey);
  X509_free(a);
  sk_pop_free((_STACK *)pXVar2,DAT_00066580);
  return iVar5;
}

