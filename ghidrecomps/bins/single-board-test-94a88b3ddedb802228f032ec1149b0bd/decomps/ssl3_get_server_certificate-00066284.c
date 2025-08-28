
int ssl3_get_server_certificate(int param_1)

{
  int iVar1;
  X509 *pXVar2;
  undefined4 *puVar3;
  X509 *x;
  X509 *pkey;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint len;
  X509 *a;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  int local_28;
  byte *local_24;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_28);
  if (local_28 == 0) {
    return iVar1;
  }
  iVar4 = *(int *)(param_1 + 0x58);
  iVar5 = *(int *)(iVar4 + 0x340);
  if ((iVar5 == 0xc) || ((*(int *)(*(int *)(iVar4 + 0x344) + 0x10) << 0x1a < 0 && (iVar5 == 0xe))))
  {
    *(undefined4 *)(iVar4 + 0x354) = 1;
    return 1;
  }
  if (iVar5 != 0xb) {
    uVar6 = 10;
    a = (X509 *)0x0;
    ERR_put_error(0x14,0x90,0x72,"s3_clnt.c",0x4ad);
    pkey = (X509 *)0x0;
    pXVar2 = (X509 *)0x0;
    goto LAB_000662e4;
  }
  pbVar7 = *(byte **)(param_1 + 0x40);
  pXVar2 = (X509 *)sk_new_null();
  if (pXVar2 == (X509 *)0x0) {
    ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x4b3);
    a = (X509 *)0x0;
    pkey = (X509 *)0x0;
  }
  else {
    uVar9 = (uint)pbVar7[1] << 8 | (uint)*pbVar7 << 0x10 | (uint)pbVar7[2];
    if (uVar9 + 3 == iVar1) {
      if (uVar9 != 0) {
        pbVar10 = pbVar7 + 6;
        len = (uint)pbVar7[3] << 0x10 | (uint)pbVar7[4] << 8 | (uint)pbVar7[5];
        for (uVar8 = len + 3; uVar8 <= uVar9; uVar8 = uVar8 + len + 3) {
          local_24 = pbVar10;
          a = d2i_X509((X509 **)0x0,&local_24,len);
          if (a == (X509 *)0x0) {
            ERR_put_error(0x14,0x90,0xd,"s3_clnt.c",0x4ca);
            uVar6 = 0x2a;
            pkey = (X509 *)0x0;
            goto LAB_000662e4;
          }
          if (local_24 != pbVar10 + len) {
            ERR_put_error(0x14,0x90,0x87,"s3_clnt.c",0x4d0);
            pkey = (X509 *)0x0;
            uVar6 = 0x32;
            goto LAB_000662e4;
          }
          iVar1 = sk_push((_STACK *)pXVar2,a);
          if (iVar1 == 0) {
            ERR_put_error(0x14,0x90,0x41,"s3_clnt.c",0x4d4);
            pkey = (X509 *)0x0;
            goto LAB_000662ee;
          }
          if (uVar9 <= uVar8) goto LAB_000663e4;
          pbVar10 = local_24 + 3;
          len = (uint)local_24[1] << 8 | (uint)*local_24 << 0x10 | (uint)local_24[2];
        }
        iVar4 = 0x4c2;
        iVar1 = 0x87;
        goto LAB_000663d6;
      }
LAB_000663e4:
      iVar1 = ssl_verify_cert_chain(param_1,pXVar2);
      if ((*(int *)(param_1 + 200) == 0) || (0 < iVar1)) {
        ERR_clear_error();
        puVar3 = (undefined4 *)ssl_sess_cert_new();
        if (puVar3 == (undefined4 *)0x0) {
          a = (X509 *)0x0;
          pkey = (X509 *)0x0;
          goto LAB_000662ee;
        }
        iVar1 = *(int *)(param_1 + 0xc0);
        if (*(int *)(iVar1 + 0x98) != 0) {
          ssl_sess_cert_free();
          iVar1 = *(int *)(param_1 + 0xc0);
        }
        *(undefined4 **)(iVar1 + 0x98) = puVar3;
        *puVar3 = pXVar2;
        x = (X509 *)sk_value((_STACK *)pXVar2,0);
        pkey = (X509 *)X509_get_pubkey(x);
        iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
        if ((*(int *)(iVar1 + 0xc) << 0x1b < 0) && (*(int *)(iVar1 + 0x10) << 0x1a < 0)) {
          uVar6 = ssl_cert_type(x,pkey);
          iVar1 = *(int *)(param_1 + 0xc0);
          puVar3[1] = uVar6;
          puVar3[2] = 0;
          if (*(X509 **)(iVar1 + 0x9c) != (X509 *)0x0) {
            X509_free(*(X509 **)(iVar1 + 0x9c));
            iVar1 = *(int *)(param_1 + 0xc0);
          }
          *(undefined4 *)(iVar1 + 0x9c) = 0;
LAB_0006646a:
          pXVar2 = (X509 *)0x0;
          a = (X509 *)0x0;
          iVar4 = 1;
          *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(param_1 + 0xec);
          goto LAB_000662f6;
        }
        if ((pkey == (X509 *)0x0) ||
           (iVar1 = EVP_PKEY_missing_parameters((EVP_PKEY *)pkey), iVar1 != 0)) {
          pXVar2 = (X509 *)0x0;
          uVar6 = 2;
          ERR_put_error(0x14,0x90,0xef,"s3_clnt.c",0x511);
          a = (X509 *)0x0;
        }
        else {
          iVar1 = ssl_cert_type(x,pkey);
          a = (X509 *)0x0;
          pXVar2 = a;
          if (iVar1 < 0) {
            uVar6 = 2;
            ERR_put_error(0x14,0x90,0xf7,"s3_clnt.c",0x51a);
          }
          else {
            iVar4 = ssl_cipher_get_cert_index(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x344));
            iVar5 = iVar1 - iVar4;
            if (iVar5 != 0) {
              iVar5 = 1;
            }
            if (iVar4 < 0) {
              iVar5 = 0;
            }
            if (iVar5 == 0) {
              puVar3[1] = iVar1;
              CRYPTO_add_lock(&x->references,1,3,"s3_clnt.c",0x528);
              if ((X509 *)puVar3[iVar1 * 7 + 3] != (X509 *)0x0) {
                X509_free((X509 *)puVar3[iVar1 * 7 + 3]);
              }
              pXVar2 = *(X509 **)(*(int *)(param_1 + 0xc0) + 0x9c);
              puVar3[iVar1 * 7 + 3] = x;
              puVar3[2] = puVar3 + iVar1 * 7 + 3;
              if (pXVar2 != (X509 *)0x0) {
                X509_free(pXVar2);
              }
              CRYPTO_add_lock(&x->references,1,3,"s3_clnt.c",0x534);
              iVar1 = *(int *)(param_1 + 0xc0);
              *(X509 **)(iVar1 + 0x9c) = x;
              goto LAB_0006646a;
            }
            uVar6 = 0x2f;
            ERR_put_error(0x14,0x90,0x17f,"s3_clnt.c",0x524);
          }
        }
      }
      else {
        pkey = (X509 *)0x0;
        uVar6 = ssl_verify_alarm_type(*(undefined4 *)(param_1 + 0xec));
        a = (X509 *)0x0;
        ERR_put_error(0x14,0x90,0x86,"s3_clnt.c",0x4e5);
      }
    }
    else {
      iVar1 = 0x9f;
      iVar4 = 0x4ba;
LAB_000663d6:
      a = (X509 *)0x0;
      uVar6 = 0x32;
      ERR_put_error(0x14,0x90,iVar1,"s3_clnt.c",iVar4);
      pkey = a;
    }
LAB_000662e4:
    ssl3_send_alert(param_1,2,uVar6);
  }
LAB_000662ee:
  iVar4 = -1;
  *(undefined4 *)(param_1 + 0x34) = 5;
LAB_000662f6:
  EVP_PKEY_free((EVP_PKEY *)pkey);
  X509_free(a);
  sk_pop_free((_STACK *)pXVar2,X509_free);
  return iVar4;
}

