
undefined4 ssl_check_srvr_ecc_cert_and_alg(X509 *param_1,int *param_2)

{
  EVP_PKEY *pkey;
  ASN1_OBJECT *o;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_28;
  int local_24 [2];
  
  local_28 = 0;
  local_24[0] = 0;
  iVar2 = *(int *)(param_2[0x16] + 0x344);
  uVar3 = *(uint *)(iVar2 + 0xc);
  iVar4 = *(int *)(iVar2 + 0x10);
  if (*(int *)(iVar2 + 0x20) << 0x1e < 0) {
    pkey = X509_get_pubkey(param_1);
    if (pkey != (EVP_PKEY *)0x0) {
      iVar2 = EVP_PKEY_bits(pkey);
      EVP_PKEY_free(pkey);
      if (iVar2 < 0xa4) goto LAB_0007bb00;
    }
LAB_0007bbb0:
    uVar1 = 0;
  }
  else {
LAB_0007bb00:
    X509_check_purpose(param_1,-1,0);
    if ((param_1->sig_alg != (X509_ALGOR *)0x0) &&
       (o = param_1->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0)) {
      iVar2 = OBJ_obj2nid(o);
      OBJ_find_sigid_algs(iVar2,&local_28,local_24);
    }
    if ((uVar3 & 0x60) != 0) {
      if (((int)(param_1->ex_flags << 0x1e) < 0) && ((param_1->ex_kusage & 8) == 0)) {
        ERR_put_error(0x14,0x117,0x13d,DAT_0007bbf4,0x9a7);
        return 0;
      }
      if (((int)(uVar3 << 0x19) < 0) &&
         (((*param_2 >> 8 != 3 || (*param_2 < 0x303)) && (local_24[0] != 0x198)))) {
        ERR_put_error(0x14,0x117,0x143,DAT_0007bbf4,0x9ae);
        return 0;
      }
      if ((((int)(uVar3 << 0x1a) < 0) && ((*param_2 >> 8 != 3 || (*param_2 < 0x303)))) &&
         (local_24[0] != 0x13 && local_24[0] != 6)) {
        ERR_put_error(0x14,0x117,0x142,DAT_0007bbf4,0x9b7);
        goto LAB_0007bbb0;
      }
    }
    if (((iVar4 << 0x19 < 0) && ((int)(param_1->ex_flags << 0x1e) < 0)) &&
       ((param_1->ex_kusage & 0x80) == 0)) {
      ERR_put_error(0x14,0x117,0x13e,DAT_0007bbf4,0x9c0);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

