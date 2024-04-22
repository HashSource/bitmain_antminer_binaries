
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  EVP_PKEY *pEVar1;
  int iVar2;
  uint uVar3;
  dh_st *dh;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  uVar6 = *(uint *)(iVar5 + 0x10);
  uVar7 = *(uint *)(iVar5 + 0xc);
  if ((uVar6 & 0x24) != 0) {
    return 1;
  }
  if ((int)(uVar7 << 0x17) < 0) {
    return 1;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
  if (iVar5 == 0) {
    ERR_put_error(0x14,0x82,0x44,DAT_00067ce0,0xd81);
    return 0;
  }
  iVar9 = *(int *)(iVar5 + 0xec);
  iVar8 = *(int *)(iVar5 + 0xf0);
  if (*(int *)(iVar5 + 4) == 5) {
    iVar5 = ssl_check_srvr_ecc_cert_and_alg(*(undefined4 *)(iVar5 + 0x98),param_1);
    if (iVar5 != 0) {
      return 1;
    }
    ERR_put_error(0x14,0x82,0x130,DAT_00067ce0,0xd92);
    uVar4 = 0x28;
    goto LAB_00067a24;
  }
  if ((int)(uVar6 << 0x19) < 0) {
    ERR_put_error(0x14,0x82,0x17d,DAT_00067ce0,0xd99);
    uVar4 = 0x28;
    goto LAB_00067a24;
  }
  if ((uVar7 & 0x60) != 0) {
    ERR_put_error(0x14,0x82,0x17e,DAT_00067ce0,0xd9c);
    uVar4 = 0x28;
    goto LAB_00067a24;
  }
  iVar10 = iVar5 + *(int *)(iVar5 + 4) * 0x1c;
  pEVar1 = X509_get_pubkey(*(X509 **)(iVar10 + 0xc));
  iVar2 = EVP_PKEY_bits(pEVar1);
  uVar3 = X509_certificate_type(*(X509 **)(iVar10 + 0xc),pEVar1);
  EVP_PKEY_free(pEVar1);
  if (((int)(uVar6 << 0x1f) < 0) && ((uVar3 & 0x11) != 0x11)) {
    ERR_put_error(0x14,0x82,0xaa,DAT_00067ce0,0xda8);
    uVar4 = 0x28;
    goto LAB_00067a24;
  }
  if (((int)(uVar6 << 0x1e) < 0) && ((uVar3 & 0x12) != 0x12)) {
    ERR_put_error(0x14,0x82,0xa5,DAT_00067ce0,0xdae);
    uVar4 = 0x28;
    goto LAB_00067a24;
  }
  if ((uVar7 & 1) == 0) {
LAB_00067ad6:
    uVar6 = uVar7 & 8;
    if ((uVar6 == 0) || (iVar8 != 0)) {
      if (((int)(uVar7 << 0x1e) < 0) &&
         ((-1 < *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e &&
          ((uVar3 & 0x104) != 0x104)))) {
        ERR_put_error(0x14,0x82,0xa4,DAT_00067ce0,0xdd3);
        uVar4 = 0x28;
        goto LAB_00067a24;
      }
      if ((((int)(uVar7 << 0x1d) < 0) &&
          (-1 < *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e)) &&
         ((uVar3 & 0x204) != 0x204)) {
        ERR_put_error(0x14,0x82,0xa2,DAT_00067ce0,0xdda);
        uVar4 = 0x28;
        goto LAB_00067a24;
      }
      if ((uVar7 & 0xe) == 0) {
        uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
        if (-1 < (int)(uVar3 << 0x1e)) {
          return 1;
        }
LAB_00067c10:
        if ((uVar3 & 8) == 0) {
          iVar5 = 0x400;
        }
        else {
          iVar5 = 0x200;
        }
        if (iVar2 <= iVar5) {
          return 1;
        }
        if ((uVar7 & 1) == 0) {
          if (uVar6 == 0) {
            if ((uVar7 & 6) == 0) {
              ERR_put_error(0x14,0x82,0xfa,DAT_00067d70,0xe19);
              uVar4 = 0x28;
              goto LAB_00067a24;
            }
            iVar5 = 0xe13;
          }
          else {
            iVar5 = BN_num_bits(*(BIGNUM **)(iVar8 + 8));
            if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
              iVar8 = 0x400;
            }
            else {
              iVar8 = 0x200;
            }
            if (iVar5 <= iVar8) {
              return 1;
            }
            iVar5 = 0xe0c;
          }
          ERR_put_error(0x14,0x82,0xa6,DAT_00067ce0,iVar5);
          uVar4 = 0x3c;
        }
        else if (iVar9 == 0) {
          ERR_put_error(0x14,0x82,0xa7,DAT_00067d70,0xdf9);
          uVar4 = 0x28;
        }
        else {
          iVar5 = BN_num_bits(*(BIGNUM **)(iVar9 + 0x10));
          if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
            iVar8 = 0x400;
          }
          else {
            iVar8 = 0x200;
          }
          if (iVar5 <= iVar8) {
            return 1;
          }
          ERR_put_error(0x14,0x82,0xa7,DAT_00067ce0,0xe00);
          uVar4 = 0x3c;
        }
      }
      else {
        if (uVar6 == 0) {
          if ((-1 < *(int *)(iVar5 + 4)) &&
             (pEVar1 = X509_get_pubkey(*(X509 **)(iVar5 + *(int *)(iVar5 + 4) * 0x1c + 0xc)),
             pEVar1 != (EVP_PKEY *)0x0)) {
            dh = EVP_PKEY_get1_DH(pEVar1);
            EVP_PKEY_free(pEVar1);
            if (dh != (dh_st *)0x0) {
              iVar5 = BN_num_bits(dh->p);
              DH_free(dh);
              goto LAB_00067bd8;
            }
          }
          ERR_put_error(0x14,0x154,0x44,DAT_00067ce0,0x971);
          uVar4 = 0x28;
          goto LAB_00067a24;
        }
        iVar5 = BN_num_bits(*(BIGNUM **)(iVar8 + 8));
LAB_00067bd8:
        uVar3 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
        if ((int)(uVar3 << 0x1e) < 0) {
          if (0x1ff < iVar5) goto LAB_00067c10;
        }
        else if (0x2ff < iVar5) {
          return 1;
        }
        ERR_put_error(0x14,0x82,0x174,DAT_00067ce0,0xded);
        uVar4 = 0x28;
      }
      goto LAB_00067a24;
    }
    iVar10 = 0xdcd;
  }
  else {
    uVar6 = *(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20);
    if (-1 < (int)(uVar6 << 0x1e)) {
      if ((uVar3 & 0x21) != 0x21) {
        iVar5 = 0xdb7;
LAB_00067b5a:
        ERR_put_error(0x14,0x82,0xa9,DAT_00067ce0,iVar5);
        uVar4 = 0x28;
        goto LAB_00067a24;
      }
      goto LAB_00067ad6;
    }
    if ((uVar6 & 8) == 0) {
      iVar10 = 0x400;
    }
    else {
      iVar10 = 0x200;
    }
    if (iVar10 < iVar2) goto LAB_00067ad6;
    if ((uVar3 & 0x21) != 0x21) {
      iVar5 = 0xdbd;
      goto LAB_00067b5a;
    }
    iVar10 = 0xdc3;
    if (iVar9 == 0) goto LAB_00067ad6;
  }
  ERR_put_error(0x14,0x82,0x44,DAT_00067d70,iVar10);
  uVar4 = 0x50;
LAB_00067a24:
  ssl3_send_alert(param_1,2,uVar4);
  return 0;
}

