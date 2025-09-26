
undefined4 SSL_get0_peer_scts(int param_1)

{
  void *pvVar1;
  X509 *x;
  int iVar2;
  OCSP_SINGLERESP *x_00;
  int iVar3;
  int iVar4;
  OCSP_BASICRESP *bs;
  OCSP_RESPONSE *resp;
  uchar *local_24 [2];
  
  if (*(int *)(param_1 + 0x5dc) != 0) {
LAB_000ed2d6:
    return *(undefined4 *)(param_1 + 0x5d8);
  }
  if (*(uchar **)(param_1 + 0x540) == (uchar *)0x0) {
LAB_000ed328:
    if (((*(uchar **)(param_1 + 0x554) == (uchar *)0x0) || (*(long *)(param_1 + 0x558) == 0)) ||
       (local_24[0] = *(uchar **)(param_1 + 0x554),
       resp = d2i_OCSP_RESPONSE((OCSP_RESPONSE **)0x0,local_24,*(long *)(param_1 + 0x558)),
       resp == (OCSP_RESPONSE *)0x0)) {
      pvVar1 = (void *)0x0;
      resp = (OCSP_RESPONSE *)0x0;
      bs = (OCSP_BASICRESP *)0x0;
    }
    else {
      bs = OCSP_response_get1_basic(resp);
      if (bs == (OCSP_BASICRESP *)0x0) {
        pvVar1 = (void *)0x0;
      }
      else {
        pvVar1 = (void *)0x0;
        for (iVar4 = 0; iVar2 = OCSP_resp_count(bs), iVar4 < iVar2; iVar4 = iVar4 + 1) {
          x_00 = OCSP_resp_get0(bs,iVar4);
          if (x_00 != (OCSP_SINGLERESP *)0x0) {
            pvVar1 = OCSP_SINGLERESP_get1_ext_d2i(x_00,0x3ba,(int *)0x0,(int *)0x0);
            if (*(int *)(param_1 + 0x5d8) == 0) {
              iVar2 = OPENSSL_sk_new_null();
              *(int *)(param_1 + 0x5d8) = iVar2;
              if (iVar2 == 0) {
                ERR_put_error(0x14,0x159,0x41,"ssl/ssl_lib.c",0x1293);
LAB_000ed432:
                SCT_LIST_free(pvVar1);
                OCSP_BASICRESP_free(bs);
                OCSP_RESPONSE_free(resp);
                return 0;
              }
            }
            while (iVar2 = OPENSSL_sk_pop(pvVar1), iVar2 != 0) {
              iVar3 = SCT_set_source(iVar2,3);
              if ((iVar3 != 1) ||
                 (iVar3 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x5d8),iVar2), iVar3 < 1)) {
                OPENSSL_sk_push(pvVar1,iVar2);
                goto LAB_000ed432;
              }
            }
          }
        }
      }
    }
    SCT_LIST_free(pvVar1);
    OCSP_BASICRESP_free(bs);
    OCSP_RESPONSE_free(resp);
    if ((*(int *)(param_1 + 0x474) == 0) ||
       (x = *(X509 **)(*(int *)(param_1 + 0x474) + 0x19c), x == (X509 *)0x0)) {
LAB_000ed39a:
      *(undefined4 *)(param_1 + 0x5dc) = 1;
      goto LAB_000ed2d6;
    }
    pvVar1 = X509_get_ext_d2i(x,0x3b7,(int *)0x0,(int *)0x0);
    if (*(int *)(param_1 + 0x5d8) == 0) {
      iVar4 = OPENSSL_sk_new_null();
      *(int *)(param_1 + 0x5d8) = iVar4;
      if (iVar4 == 0) goto LAB_000ed482;
    }
    do {
      iVar4 = OPENSSL_sk_pop(pvVar1);
      if (iVar4 == 0) {
        SCT_LIST_free(pvVar1);
        goto LAB_000ed39a;
      }
      iVar2 = SCT_set_source(iVar4,2);
    } while ((iVar2 == 1) &&
            (iVar2 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x5d8),iVar4), 0 < iVar2));
  }
  else {
    local_24[0] = *(uchar **)(param_1 + 0x540);
    pvVar1 = (void *)o2i_SCT_LIST(0,local_24,*(undefined2 *)(param_1 + 0x544));
    if (*(int *)(param_1 + 0x5d8) == 0) {
      iVar4 = OPENSSL_sk_new_null();
      *(int *)(param_1 + 0x5d8) = iVar4;
      if (iVar4 == 0) {
LAB_000ed482:
        ERR_put_error(0x14,0x159,0x41,"ssl/ssl_lib.c",0x1293);
        goto LAB_000ed3aa;
      }
    }
    do {
      iVar4 = OPENSSL_sk_pop(pvVar1);
      if (iVar4 == 0) {
        SCT_LIST_free(pvVar1);
        goto LAB_000ed328;
      }
      iVar2 = SCT_set_source(iVar4,1);
    } while ((iVar2 == 1) &&
            (iVar2 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x5d8),iVar4), 0 < iVar2));
  }
  OPENSSL_sk_push(pvVar1,iVar4);
LAB_000ed3aa:
  SCT_LIST_free(pvVar1);
  return 0;
}

