
int X509_chain_check_suiteb(uint *param_1,int *param_2,_STACK *param_3,uint param_4)

{
  long lVar1;
  EVP_PKEY *pkey;
  EC_GROUP *pEVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  uint local_2c;
  
  if ((param_4 & 0x30000) == 0) {
LAB_0015ed8a:
    iVar4 = 0;
  }
  else {
    bVar6 = param_2 == (int *)0x0;
    if (bVar6) {
      param_2 = (int *)sk_value(param_3,0);
    }
    uVar5 = (uint)bVar6;
    lVar1 = ASN1_INTEGER_get(*(ASN1_INTEGER **)*param_2);
    if (lVar1 == 2) {
      local_2c = param_4;
      if (*param_2 == 0) {
        pkey = (EVP_PKEY *)0x0;
LAB_0015edae:
        iVar4 = 0x39;
LAB_0015edb0:
        uVar5 = 0;
LAB_0015edb4:
        if (pkey != (EVP_PKEY *)0x0) goto LAB_0015edba;
      }
      else {
        pkey = X509_PUBKEY_get(*(X509_PUBKEY **)(*param_2 + 0x18));
        if (((pkey == (EVP_PKEY *)0x0) || (pkey->type != 0x198)) ||
           (pEVar2 = EC_KEY_get0_group((EC_KEY *)(pkey->pkey).rsa), pEVar2 == (EC_GROUP *)0x0))
        goto LAB_0015edae;
        iVar4 = EC_GROUP_get_curve_name(pEVar2);
        if (iVar4 == 0x2cb) {
          if ((int)(param_4 << 0xe) < 0) {
            local_2c = param_4 & 0xfffeffff;
LAB_0015ee26:
            for (; iVar4 = sk_num(param_3), (int)uVar5 < iVar4; uVar5 = uVar5 + 1) {
              iVar4 = X509_get_signature_nid(param_2);
              param_2 = (int *)sk_value(param_3,uVar5);
              lVar1 = ASN1_INTEGER_get(*(ASN1_INTEGER **)*param_2);
              if (lVar1 != 2) {
                iVar4 = 0x38;
                goto LAB_0015edba;
              }
              EVP_PKEY_free(pkey);
              if (*param_2 == 0) {
                pkey = (EVP_PKEY *)0x0;
LAB_0015ee6a:
                iVar4 = 0x39;
                goto LAB_0015edb4;
              }
              pkey = X509_PUBKEY_get(*(X509_PUBKEY **)(*param_2 + 0x18));
              if (((pkey == (EVP_PKEY *)0x0) || (pkey->type != 0x198)) ||
                 (pEVar2 = EC_KEY_get0_group((EC_KEY *)(pkey->pkey).rsa), pEVar2 == (EC_GROUP *)0x0)
                 ) goto LAB_0015ee6a;
              iVar3 = EC_GROUP_get_curve_name(pEVar2);
              if (iVar3 == 0x2cb) {
                if (iVar4 != 0x31b && iVar4 != -1) {
LAB_0015ee9a:
                  iVar4 = 0x3b;
                  goto LAB_0015edb4;
                }
                if (-1 < (int)(local_2c << 0xe)) {
                  iVar4 = 0x3c;
                  goto LAB_0015edb4;
                }
                local_2c = local_2c & 0xfffeffff;
              }
              else {
                if (iVar3 != 0x19f) {
                  iVar4 = 0x3a;
                  goto LAB_0015edb4;
                }
                if (iVar4 != 0x31a && iVar4 != -1) goto LAB_0015ee9a;
                if (-1 < (int)(local_2c << 0xf)) goto LAB_0015ee1e;
              }
            }
            iVar4 = X509_get_signature_nid(param_2);
            if ((pkey->type == 0x198) &&
               (pEVar2 = EC_KEY_get0_group((EC_KEY *)(pkey->pkey).rsa), pEVar2 != (EC_GROUP *)0x0))
            {
              iVar3 = EC_GROUP_get_curve_name(pEVar2);
              if (iVar3 == 0x2cb) {
                if (iVar4 == 0x31b || iVar4 == -1) {
                  iVar4 = 0;
                  if (-1 < (int)(local_2c << 0xe)) goto LAB_0015ee1e;
                  local_2c = local_2c & 0xfffeffff;
                }
                else {
LAB_0015ef2a:
                  iVar4 = 0x3b;
                }
              }
              else if (iVar3 == 0x19f) {
                if ((iVar4 != 0x31a) && (iVar4 != -1)) goto LAB_0015ef2a;
                if ((local_2c & 0x10000) == 0) {
                  iVar4 = 0x3c;
                }
                else {
                  iVar4 = 0;
                }
              }
              else {
                iVar4 = 0x3a;
              }
            }
            else {
              iVar4 = 0x39;
            }
            goto LAB_0015edba;
          }
          iVar4 = 0x3c;
          goto LAB_0015edb0;
        }
        if (iVar4 != 0x19f) {
          iVar4 = 0x3a;
          goto LAB_0015edb0;
        }
        if ((param_4 & 0x10000) != 0) goto LAB_0015ee26;
        uVar5 = 0;
LAB_0015ee1e:
        iVar4 = 0x3c;
LAB_0015edba:
        EVP_PKEY_free(pkey);
      }
      if (iVar4 == 0) goto LAB_0015ed8a;
      if (iVar4 - 0x3bU < 2) {
        if (uVar5 != 0) {
          uVar5 = uVar5 - 1;
        }
        if (iVar4 == 0x3c) {
          if (param_4 != local_2c) {
            iVar4 = 0x3d;
          }
        }
        else {
          iVar4 = 0x3b;
        }
      }
    }
    else {
      uVar5 = 0;
      iVar4 = 0x38;
    }
    if (param_1 != (uint *)0x0) {
      *param_1 = uVar5;
    }
  }
  return iVar4;
}

