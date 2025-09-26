
undefined4 SCT_CTX_set1_cert(int param_1,X509 *param_2,X509 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  X509_EXTENSION *pXVar4;
  uint uVar5;
  X509_NAME *name;
  X509_EXTENSION *ex;
  ASN1_OCTET_STRING *data;
  int iVar6;
  X509 *x;
  uint uVar7;
  bool bVar8;
  uchar *local_28;
  void *local_24;
  
  iVar6 = 0;
  local_28 = (uchar *)0x0;
  local_24 = (void *)0x0;
  iVar1 = X509_get_ext_by_NID(param_2,0x3b8,-1);
  if (iVar1 < 0) {
    if ((iVar1 != -1) ||
       ((param_3 == (X509 *)0x0 && (iVar6 = i2d_X509(param_2,&local_28), -1 < iVar6))))
    goto LAB_0011efd8;
  }
  else {
    iVar2 = X509_get_ext_by_NID(param_2,0x3b8,iVar1);
    if (iVar2 < 0) {
LAB_0011efd8:
      iVar2 = X509_get_ext_by_NID(param_2,0x3b7,-1);
      if (iVar2 < 0) {
        if ((iVar2 != -1) || (iVar2 = iVar1, iVar1 < 0)) {
          iVar1 = 0;
          x = (X509 *)0x0;
          goto LAB_0011f10e;
        }
      }
      else {
        iVar3 = X509_get_ext_by_NID(param_2,0x3b7,iVar2);
        if ((-1 < iVar3) || (-1 < iVar1)) goto LAB_0011ef9c;
      }
      x = X509_dup(param_2);
      if (x != (X509 *)0x0) {
        pXVar4 = X509_delete_ext(x,iVar2);
        X509_EXTENSION_free(pXVar4);
        if (param_3 != (X509 *)0x0) {
          iVar1 = X509_get_ext_by_NID(param_3,0x5a,-1);
          if (iVar1 < 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = X509_get_ext_by_NID(param_3,0x5a,iVar1);
            uVar7 = ~uVar7 >> 0x1f;
          }
          iVar2 = X509_get_ext_by_NID(x,0x5a,-1);
          if (iVar2 < 0) {
            uVar5 = 0;
          }
          else {
            uVar5 = X509_get_ext_by_NID(x,0x5a,iVar2);
            uVar5 = ~uVar5 >> 0x1f;
          }
          iVar3 = iVar2;
          if (-2 < iVar2) {
            iVar3 = iVar1;
          }
          if ((uVar7 != 0 || iVar3 < -1) || uVar5 != 0) goto LAB_0011ef9e;
          bVar8 = iVar1 == 0;
          if (-1 < iVar1) {
            bVar8 = iVar2 == -1;
          }
          if (bVar8) goto LAB_0011ef9e;
          bVar8 = iVar2 == 0;
          if (-1 < iVar2) {
            bVar8 = iVar1 == -1;
          }
          if (bVar8) goto LAB_0011ef9e;
          name = X509_get_issuer_name(param_3);
          iVar3 = X509_set_issuer_name(x,name);
          if (iVar3 == 0) goto LAB_0011ef9e;
          if (iVar1 != -1) {
            pXVar4 = X509_get_ext(param_3,iVar1);
            ex = X509_get_ext(x,iVar2);
            if ((((pXVar4 == (X509_EXTENSION *)0x0) || (ex == (X509_EXTENSION *)0x0)) ||
                (data = X509_EXTENSION_get_data(pXVar4), data == (ASN1_OCTET_STRING *)0x0)) ||
               (iVar1 = X509_EXTENSION_set_data(ex,data), iVar1 == 0)) goto LAB_0011ef9e;
          }
        }
        iVar1 = i2d_re_X509_tbs(x,&local_24);
        if (0 < iVar1) {
LAB_0011f10e:
          X509_free(x);
          CRYPTO_free(*(void **)(param_1 + 0x14));
          *(int *)(param_1 + 0x18) = iVar6;
          *(uchar **)(param_1 + 0x14) = local_28;
          CRYPTO_free(*(void **)(param_1 + 0x1c));
          *(int *)(param_1 + 0x20) = iVar1;
          *(void **)(param_1 + 0x1c) = local_24;
          return 1;
        }
        goto LAB_0011ef9e;
      }
    }
  }
LAB_0011ef9c:
  x = (X509 *)0x0;
LAB_0011ef9e:
  CRYPTO_free(local_28);
  CRYPTO_free(local_24);
  X509_free(x);
  return 0;
}

