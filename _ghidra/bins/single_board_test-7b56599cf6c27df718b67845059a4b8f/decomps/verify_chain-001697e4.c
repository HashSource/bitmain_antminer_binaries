
int verify_chain(int param_1)

{
  int iVar1;
  X509 *pXVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  EVP_PKEY *pkey;
  X509 *pXVar8;
  GENERAL_NAMES *a;
  int *piVar9;
  X509_NAME *pXVar10;
  X509_NAME *name;
  uint *puVar11;
  X509_NAME_ENTRY *ne;
  ASN1_OBJECT *o;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  NAME_CONSTRAINTS *nc;
  int iVar17;
  bool bVar18;
  bool bVar19;
  uint local_4c;
  uint local_48;
  int local_40;
  X509 *local_2c [2];
  
  iVar17 = *(int *)(param_1 + 0x80);
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
  pXVar2 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar1 + -1);
  iVar3 = X509_check_purpose(pXVar2,-1,0);
  if (iVar3 == 1) {
    local_48 = (uint)(pXVar2[1].references << 0x12) >> 0x1f;
  }
  else {
    local_48 = 0;
  }
  if ((iVar1 != 1) || (*(int *)(param_1 + 0x4c) != 1)) {
    ERR_put_error(0xb,0x6a,0x44,"crypto/x509/x509_vfy.c",0xb96);
    *(undefined4 *)(param_1 + 0x60) = 1;
    goto LAB_0016983a;
  }
  uVar4 = *(uint *)(param_1 + 8);
  uVar14 = uVar4;
  if (uVar4 != 0) {
    uVar14 = 1;
  }
  if (((iVar17 == 0) || ((*(uint *)(iVar17 + 0x14) & 3) != 0)) ||
     ((*(uint *)(iVar17 + 0x14) & 0xc) == 0)) {
    if ((uVar4 == 0) ||
       (uVar15 = *(uint *)(*(int *)(param_1 + 0x10) + 0xc), (int)(uVar15 << 0x10) < 0)) {
      uVar14 = uVar14 | 2;
      uVar15 = 0;
    }
    else {
      uVar15 = ((uVar15 ^ 0x100000) << 0xb) >> 0x1f;
    }
    bVar19 = true;
    if (iVar17 != 0) goto LAB_00169896;
LAB_00169a4a:
    if (uVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = OPENSSL_sk_dup();
      if (iVar1 == 0) {
LAB_00169aba:
        iVar1 = 0xbc4;
        goto LAB_00169ac4;
      }
    }
  }
  else {
    uVar15 = 0;
    bVar19 = false;
LAB_00169896:
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(iVar17 + 4));
    if ((iVar1 < 1) || (*(int *)(iVar17 + 8) == 0)) {
      uVar4 = *(uint *)(param_1 + 8);
      goto LAB_00169a4a;
    }
    iVar1 = OPENSSL_sk_dup();
    if (iVar1 == 0) {
      iVar1 = 0xbb9;
LAB_00169ac4:
      ERR_put_error(0xb,0x6a,0x41,"crypto/x509/x509_vfy.c",iVar1);
      *(undefined4 *)(param_1 + 0x60) = 0x11;
      goto LAB_0016983a;
    }
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 != 0) {
      iVar12 = 0;
      do {
        iVar5 = OPENSSL_sk_num(iVar3);
        if (iVar5 <= iVar12) goto LAB_001698e8;
        uVar6 = OPENSSL_sk_value(iVar3,iVar12);
        iVar5 = OPENSSL_sk_push(iVar1,uVar6);
        iVar12 = iVar12 + 1;
      } while (iVar5 != 0);
      OPENSSL_sk_free(iVar1);
      goto LAB_00169aba;
    }
  }
LAB_001698e8:
  iVar3 = *(int *)(param_1 + 0x10);
  iVar12 = *(int *)(iVar3 + 0x18);
  if (iVar12 < 0x40000000) {
    iVar3 = iVar12 + 1;
    iVar5 = iVar12;
    local_40 = iVar3;
  }
  else {
    local_40 = 0x40000000;
    iVar5 = 0x3fffffff;
  }
  if (0x3fffffff < iVar12) {
    *(int *)(iVar3 + 0x18) = iVar5;
  }
  if (uVar14 == 0) {
    OPENSSL_sk_free(iVar1);
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
    if (iVar1 <= local_40) {
      if (iVar17 != 0) goto LAB_00169af0;
LAB_00169afa:
      if (*(int *)(param_1 + 0x4c) == iVar1) {
        iVar3 = check_trust(param_1,iVar1);
        goto LAB_00169988;
      }
    }
LAB_00169b02:
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
    if (local_40 < iVar1) {
      *(int *)(param_1 + 0x5c) = iVar1 + -1;
      uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
      uVar13 = 0x16;
LAB_00169ef2:
      *(undefined4 *)(param_1 + 100) = uVar6;
      *(undefined4 *)(param_1 + 0x60) = uVar13;
      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
    }
    else {
      if (((iVar17 != 0) && (iVar3 = OPENSSL_sk_num(*(undefined4 *)(iVar17 + 4)), 0 < iVar3)) &&
         (((*(uint *)(iVar17 + 0x14) & 3) == 0 || (-1 < *(int *)(iVar17 + 0x1c))))) {
        *(int *)(param_1 + 0x5c) = iVar1 + -1;
        uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
        uVar13 = 0x41;
        goto LAB_00169ef2;
      }
      if (local_48 != 0) {
        iVar3 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
        *(int *)(param_1 + 0x5c) = iVar1 + -1;
        if (iVar3 == 1) {
          uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
          uVar13 = 0x12;
        }
        else {
          uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
          uVar13 = 0x13;
        }
        goto LAB_00169ef2;
      }
      if (*(int *)(param_1 + 0x4c) < iVar1) {
        *(int *)(param_1 + 0x5c) = iVar1 + -1;
        uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
        uVar13 = 2;
      }
      else {
        *(int *)(param_1 + 0x5c) = iVar1 + -1;
        uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50));
        uVar13 = 0x14;
      }
      *(undefined4 *)(param_1 + 100) = uVar6;
      *(undefined4 *)(param_1 + 0x60) = uVar13;
      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
    }
    if (iVar1 == 0) goto LAB_0016983a;
  }
  else {
    iVar3 = 3;
    iVar12 = 0;
LAB_00169918:
    do {
      local_2c[0] = (X509 *)0x0;
      if (-1 < (int)(uVar14 << 0x1e)) {
LAB_00169922:
        if (-1 < (int)(uVar14 << 0x1f)) goto LAB_00169918;
LAB_00169926:
        iVar5 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
        if (iVar5 == *(int *)(param_1 + 0x4c)) {
          uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar5 + -1);
          uVar4 = local_48 ^ 1;
          if (local_40 < iVar5) {
            uVar4 = 0;
          }
          if ((uVar4 == 0) ||
             (local_2c[0] = (X509 *)find_issuer(param_1,iVar1,uVar6), local_2c[0] == (X509 *)0x0)) {
            uVar14 = uVar14 & 0xfffffffe;
            if (!bVar19) goto LAB_001699d4;
            uVar14 = uVar14 | 2;
            if (uVar14 == 0) break;
            goto LAB_00169918;
          }
          OPENSSL_sk_delete_ptr(iVar1,local_2c[0]);
          iVar3 = X509_up_ref(local_2c[0]);
          if (iVar3 != 0) {
            iVar3 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x50),local_2c[0]);
            pXVar2 = local_2c[0];
            if (iVar3 == 0) {
              iVar3 = 2;
              X509_free(local_2c[0]);
              ERR_put_error(0xb,0x6a,0x41,"crypto/x509/x509_vfy.c",0xcad);
              *(undefined4 *)(param_1 + 0x60) = 0x11;
              break;
            }
            *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
            iVar3 = X509_check_purpose(local_2c[0],-1,0);
            if (iVar3 == 1) {
              local_48 = (uint)(pXVar2[1].references << 0x12) >> 0x1f;
            }
            else {
              local_48 = 0;
            }
            if (*(int *)(param_1 + 0x80) != 0) {
              iVar5 = *(int *)(param_1 + 0x4c);
              if ((iVar5 != 1 && (*(uint *)(*(int *)(param_1 + 0x80) + 0x14) & 5) != 0) &&
                 (iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar5 + -1), iVar3 != 0))
              {
                iVar3 = dane_match_isra_1(*(undefined4 *)(param_1 + 0x4c),
                                          *(undefined4 *)(param_1 + 0x80),iVar3,iVar5 + -1);
                if (iVar3 < 0) {
                  iVar3 = 2;
                  break;
                }
                if (iVar3 != 0) {
                  iVar3 = 1;
                  *(int *)(param_1 + 0x4c) = iVar5 + -2;
                  break;
                }
              }
            }
            iVar3 = 3;
            goto LAB_00169918;
          }
          iVar12 = 0xca4;
        }
        else {
          iVar12 = 0xc8c;
        }
LAB_0016993e:
        iVar3 = 2;
        ERR_put_error(0xb,0x6a,0x44,"crypto/x509/x509_vfy.c",iVar12);
        *(undefined4 *)(param_1 + 0x60) = 1;
        break;
      }
      iVar5 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
      iVar16 = iVar12;
      if ((uVar14 & 4) == 0) {
        iVar16 = iVar5;
      }
      pXVar2 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar16 + -1);
      if (local_40 < iVar5) {
LAB_001699c2:
        if ((int)(uVar14 << 0x1f) < 0) goto LAB_00169926;
        if (-1 < (int)(uVar14 << 0x1d)) {
          if ((uVar15 == 1) && (1 < *(int *)(param_1 + 0x4c))) {
            uVar14 = uVar14 | 4;
            iVar12 = *(int *)(param_1 + 0x4c) + -1;
            local_48 = 0;
            goto LAB_00169922;
          }
          break;
        }
        iVar12 = iVar12 + -1;
        if (iVar12 < 1) break;
      }
      else {
        uVar6 = *(undefined4 *)(param_1 + 0x50);
        *(undefined4 *)(param_1 + 0x50) = 0;
        iVar7 = (**(code **)(param_1 + 0x20))(local_2c,param_1,pXVar2);
        *(undefined4 *)(param_1 + 0x50) = uVar6;
        if (iVar7 < 0) {
          iVar3 = 2;
          *(undefined4 *)(param_1 + 0x60) = 0x46;
          break;
        }
        if (iVar7 == 0) goto LAB_001699c2;
        if ((uVar14 & 4) == 0) {
          if (local_48 == 0) goto LAB_00169f88;
          iVar16 = *(int *)(param_1 + 0x4c);
          if (iVar5 == iVar16) {
            iVar16 = X509_cmp(pXVar2,local_2c[0]);
            if (iVar16 != 0) {
              local_48 = 1;
              X509_free(local_2c[0]);
              goto LAB_001699c2;
            }
            iVar5 = iVar5 + -1;
            X509_free(pXVar2);
            *(int *)(param_1 + 0x4c) = iVar5;
            local_48 = 1;
            OPENSSL_sk_set(*(undefined4 *)(param_1 + 0x50),iVar5,local_2c[0]);
            iVar16 = *(int *)(param_1 + 0x4c);
          }
          else {
            local_48 = 1;
          }
        }
        else {
          bVar18 = iVar5 == iVar16;
          iVar3 = iVar5 - iVar16;
          if (iVar5 > iVar16) {
            bVar18 = iVar16 == 0;
            iVar3 = iVar16;
          }
          if (((local_48 ^ 1) &
              (uint)(!bVar18 && iVar3 < 0 == (iVar5 <= iVar16 && SBORROW4(iVar5,iVar16)))) == 0) {
            iVar3 = 2;
            ERR_put_error(0xb,0x6a,0x44,"crypto/x509/x509_vfy.c",0xc19);
            X509_free(local_2c[0]);
            *(undefined4 *)(param_1 + 0x60) = 1;
            break;
          }
          uVar14 = uVar14 & 0xfffffffb;
          if (iVar16 < iVar5) {
            while( true ) {
              pXVar2 = (X509 *)OPENSSL_sk_pop(uVar6);
              iVar3 = iVar5 + -1;
              X509_free(pXVar2);
              iVar5 = iVar16;
              if (iVar16 == iVar3) break;
              uVar6 = *(undefined4 *)(param_1 + 0x50);
              iVar5 = iVar3;
            }
          }
          *(int *)(param_1 + 0x4c) = iVar5;
          if (iVar17 != 0) {
            iVar3 = OPENSSL_sk_num(*(undefined4 *)(iVar17 + 4));
            if ((0 < iVar3) && (*(int *)(param_1 + 0x4c) <= *(int *)(iVar17 + 0x18))) {
              *(undefined4 *)(iVar17 + 0x18) = 0xffffffff;
              X509_free(*(X509 **)(iVar17 + 0x10));
              *(undefined4 *)(iVar17 + 0x10) = 0;
            }
            iVar3 = OPENSSL_sk_num(*(undefined4 *)(iVar17 + 4));
            if (0 < iVar3) {
              iVar16 = *(int *)(param_1 + 0x4c);
              iVar3 = iVar16;
              if (iVar16 <= *(int *)(iVar17 + 0x1c)) {
                iVar3 = -1;
              }
              if (iVar16 <= *(int *)(iVar17 + 0x1c)) {
                *(int *)(iVar17 + 0x1c) = iVar3;
              }
            }
          }
LAB_00169f88:
          pXVar2 = local_2c[0];
          iVar3 = OPENSSL_sk_push(*(undefined4 *)(param_1 + 0x50),local_2c[0]);
          if (iVar3 == 0) {
            iVar3 = 2;
            X509_free(local_2c[0]);
            ERR_put_error(0xb,0x6a,0x41,"crypto/x509/x509_vfy.c",0xc37);
            *(undefined4 *)(param_1 + 0x60) = 0x11;
            local_48 = 0;
            break;
          }
          iVar3 = X509_check_purpose(pXVar2,-1,0);
          if (iVar3 == 1) {
            iVar16 = *(int *)(param_1 + 0x4c);
            local_48 = (uint)(pXVar2[1].references << 0x12) >> 0x1f;
          }
          else {
            iVar16 = *(int *)(param_1 + 0x4c);
            local_48 = 0;
          }
        }
        if (iVar5 < iVar16) {
          iVar12 = 0xc5f;
          goto LAB_0016993e;
        }
        iVar3 = check_trust(param_1,iVar5);
        if (iVar3 - 1U < 2) break;
        uVar14 = uVar14 & 0xfffffffe;
        if (local_48 != 0) {
          local_48 = 1;
          goto LAB_001699c2;
        }
      }
LAB_001699d4:
    } while (uVar14 != 0);
    OPENSSL_sk_free(iVar1);
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
    if (iVar1 <= local_40) {
      if (iVar17 != 0 && iVar3 == 3) {
LAB_00169af0:
        if (*(int *)(iVar17 + 0x14) << 0x1d < 0) {
          iVar12 = *(int *)(param_1 + 0x80);
          iVar5 = *(int *)(param_1 + 0x4c) + -1;
          pXVar2 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar5);
          iVar3 = OPENSSL_sk_num(*(undefined4 *)(iVar12 + 4));
          if (0 < iVar3) {
            iVar16 = 0;
            do {
              puVar11 = (uint *)OPENSSL_sk_value(*(undefined4 *)(iVar12 + 4),iVar16);
              iVar16 = iVar16 + 1;
              if (((*puVar11 & 0xffffff) == 0x102) &&
                 (iVar7 = X509_verify(pXVar2,(EVP_PKEY *)puVar11[3]), 0 < iVar7)) {
                X509_free(*(X509 **)(iVar12 + 0x10));
                uVar6 = *(undefined4 *)(param_1 + 0x50);
                *(undefined4 *)(iVar12 + 0x10) = 0;
                *(undefined4 *)(param_1 + 0x84) = 1;
                *(int *)(iVar12 + 0x18) = iVar5;
                *(uint **)(iVar12 + 0xc) = puVar11;
                iVar1 = OPENSSL_sk_num(uVar6);
                if (*(int *)(param_1 + 0x4c) < iVar1) {
                  do {
                    iVar1 = iVar1 + -1;
                    pXVar2 = (X509 *)OPENSSL_sk_pop(*(undefined4 *)(param_1 + 0x50));
                    X509_free(pXVar2);
                  } while (*(int *)(param_1 + 0x4c) < iVar1);
                }
                goto LAB_00169b66;
              }
            } while (iVar3 != iVar16);
          }
        }
        goto LAB_00169afa;
      }
      if (iVar3 == 3) goto LAB_00169afa;
    }
LAB_00169988:
    if (iVar3 != 1) {
      if (iVar3 == 2) goto LAB_0016983a;
      goto LAB_00169b02;
    }
  }
LAB_00169b66:
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
  if (*(int *)(param_1 + 0x78) == 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0x10);
    local_4c = (uint)(*(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x19) >> 0x1f;
  }
  else {
    iVar3 = 6;
    local_4c = 0;
  }
  if (0 < iVar1) {
    iVar16 = 0;
    iVar12 = -1;
    iVar5 = 0;
    iVar17 = 0;
LAB_00169bb2:
    do {
      pXVar2 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar17);
      if (((*(uint *)(*(int *)(param_1 + 0x10) + 0xc) & 0x10) == 0) &&
         (pXVar2[1].references << 0x16 < 0)) {
        *(int *)(param_1 + 0x5c) = iVar17;
        *(X509 **)(param_1 + 100) = pXVar2;
        *(undefined4 *)(param_1 + 0x60) = 0x22;
        iVar7 = (**(code **)(param_1 + 0x1c))(0,param_1);
        if (iVar7 == 0) goto LAB_0016983a;
      }
      if ((local_4c == 0) && (pXVar2[1].references << 0x15 < 0)) {
        *(int *)(param_1 + 0x5c) = iVar17;
        *(X509 **)(param_1 + 100) = pXVar2;
        *(undefined4 *)(param_1 + 0x60) = 0x28;
        iVar7 = (**(code **)(param_1 + 0x1c))(0,param_1);
        if (iVar7 == 0) goto LAB_0016983a;
      }
      uVar14 = X509_check_ca(pXVar2);
      pXVar8 = pXVar2;
      if (iVar12 == -1) {
        uVar4 = *(uint *)(*(int *)(param_1 + 0x10) + 0xc) & 0x20;
        if (uVar4 == 0) goto LAB_00169db4;
        if (uVar14 < 2) goto LAB_00169d96;
LAB_00169d66:
        *(int *)(param_1 + 0x5c) = iVar17;
        *(undefined4 *)(param_1 + 0x60) = 0x18;
joined_r0x00169d70:
        if (pXVar2 == (X509 *)0x0) {
          pXVar8 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar17);
        }
LAB_00169c06:
        *(X509 **)(param_1 + 100) = pXVar8;
        iVar7 = (**(code **)(param_1 + 0x1c))(0,param_1);
        if (iVar7 == 0) goto LAB_0016983a;
      }
      else {
        if (iVar12 != 0) {
          if (uVar14 != 0) {
            if ((iVar1 <= iVar17 + 1) && (-1 < *(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x1a))
            goto LAB_00169db4;
            if (uVar14 == 1) goto LAB_00169d8e;
          }
          goto LAB_00169d66;
        }
        if (uVar14 != 0) {
          *(undefined4 *)(param_1 + 0x60) = 0x25;
LAB_00169bfa:
          *(int *)(param_1 + 0x5c) = iVar17;
          goto joined_r0x00169d70;
        }
LAB_00169d8e:
        uVar4 = *(uint *)(*(int *)(param_1 + 0x10) + 0xc) & 0x20;
LAB_00169d96:
        if (iVar1 != 1 && uVar4 != 0) {
          pkey = (EVP_PKEY *)X509_get0_pubkey(pXVar2);
          if (pkey == (EVP_PKEY *)0x0) {
LAB_00169df2:
            *(undefined4 *)(param_1 + 0x60) = 1;
            goto LAB_00169bfa;
          }
          iVar7 = EVP_PKEY_id(pkey);
          if (iVar7 == 0x198) {
            EVP_PKEY_get0_EC_KEY(pkey);
            iVar7 = EC_KEY_decoded_from_explicit_params();
            if (iVar7 < 0) goto LAB_00169df2;
            if (iVar7 != 0) {
              *(undefined4 *)(param_1 + 0x60) = 0x4f;
              goto LAB_00169bfa;
            }
          }
        }
LAB_00169db4:
        if (((-1 < pXVar2[1].references << 0x1b) &&
            (pXVar2[1].signature != (ASN1_BIT_STRING *)0xffffffff)) &&
           (*(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x1a < 0)) {
          *(int *)(param_1 + 0x5c) = iVar17;
          *(undefined4 *)(param_1 + 0x60) = 0x29;
          goto LAB_00169c06;
        }
      }
      if (0 < iVar3) {
        if ((iVar17 < *(int *)(param_1 + 0x4c)) ||
           (iVar3 != *(int *)(*(int *)(param_1 + 0x10) + 0x10))) {
LAB_00169c24:
          iVar12 = X509_check_purpose(pXVar2,iVar3,(uint)(0 < iVar12));
          if ((iVar12 == 0) ||
             ((iVar12 != 1 && (*(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x1a < 0)))) {
            *(int *)(param_1 + 0x5c) = iVar17;
joined_r0x00169c4a:
            pXVar8 = pXVar2;
            if (pXVar2 == (X509 *)0x0) {
              pXVar8 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar17);
            }
            *(X509 **)(param_1 + 100) = pXVar8;
            *(undefined4 *)(param_1 + 0x60) = 0x1a;
            iVar12 = (**(code **)(param_1 + 0x1c))(0,param_1);
            if (iVar12 == 0) goto LAB_0016983a;
          }
        }
        else {
          iVar7 = X509_check_trust(pXVar2,*(int *)(*(int *)(param_1 + 0x10) + 0x14),4);
          if (iVar7 != 1) {
            if (iVar7 != 2) goto LAB_00169c24;
            *(int *)(param_1 + 0x5c) = iVar17;
            goto joined_r0x00169c4a;
          }
        }
      }
      if (iVar17 < 2) {
        if (iVar17 != 0) goto LAB_00169c78;
        iVar12 = pXVar2[1].references;
      }
      else {
        if ((pXVar2[1].signature != (ASN1_BIT_STRING *)0xffffffff) &&
           ((int)&(pXVar2[1].signature)->length + iVar5 < iVar16)) {
          *(int *)(param_1 + 0x5c) = iVar17;
          *(undefined4 *)(param_1 + 0x60) = 0x19;
          *(X509 **)(param_1 + 100) = pXVar2;
          iVar12 = (**(code **)(param_1 + 0x1c))(0,param_1);
          if (iVar12 == 0) goto LAB_0016983a;
        }
LAB_00169c78:
        iVar12 = pXVar2[1].references;
        if (-1 < iVar12 << 0x1a) {
          iVar16 = iVar16 + 1;
        }
      }
      if (-1 < iVar12 << 0x15) {
        iVar17 = iVar17 + 1;
        iVar12 = 1;
        if (iVar1 == iVar17) break;
        goto LAB_00169bb2;
      }
      iVar7 = pXVar2[1].valid;
      iVar12 = iVar5;
      if ((iVar7 != -1) && (iVar12 = iVar7, iVar7 < iVar5)) {
        *(int *)(param_1 + 0x5c) = iVar17;
        *(undefined4 *)(param_1 + 0x60) = 0x26;
        *(X509 **)(param_1 + 100) = pXVar2;
        iVar12 = (**(code **)(param_1 + 0x1c))(0,param_1);
        if (iVar12 == 0) goto LAB_0016983a;
        iVar12 = pXVar2[1].valid;
      }
      iVar17 = iVar17 + 1;
      iVar5 = iVar12 + 1;
      iVar12 = 0;
    } while (iVar1 != iVar17);
  }
  iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
  if ((*(int *)(*(int *)(param_1 + 0x10) + 0x1c) < 1) || (iVar1 < 1)) {
LAB_0016a0d0:
    iVar1 = check_id(param_1);
    X509_get_pubkey_parameters((EVP_PKEY *)0x0,*(stack_st_X509 **)(param_1 + 0x50));
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (**(code **)(param_1 + 0x28))(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = X509_chain_check_suiteb
                      (param_1 + 0x5c,0,*(undefined4 *)(param_1 + 0x50),
                       *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc));
    if (iVar1 != 0) {
      uVar6 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x5c));
      *(int *)(param_1 + 0x60) = iVar1;
      *(undefined4 *)(param_1 + 100) = uVar6;
      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (*(code **)(param_1 + 0x18) == (code *)0x0) {
      iVar1 = internal_verify(param_1);
    }
    else {
      iVar1 = (**(code **)(param_1 + 0x18))(param_1);
    }
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
    iVar1 = iVar1 + -1;
    if (-1 < iVar1) {
      do {
        pXVar2 = (X509 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar1);
        if ((iVar1 == 0) || (-1 < pXVar2[1].references << 0x1a)) {
          if (pXVar2[1].references << 0x15 < 0) {
            pXVar10 = X509_get_subject_name(pXVar2);
            name = X509_get_issuer_name(pXVar2);
            iVar3 = X509_NAME_entry_count(pXVar10);
            iVar17 = iVar3 + -1;
            if (0 < iVar17) {
              iVar12 = X509_NAME_entry_count(pXVar10);
              iVar5 = X509_NAME_entry_count(name);
              if (iVar12 == iVar5 + 1) {
                X509_NAME_get_entry(pXVar10,iVar17);
                iVar12 = X509_NAME_ENTRY_set();
                X509_NAME_get_entry(pXVar10,iVar3 + -2);
                iVar3 = X509_NAME_ENTRY_set();
                if (iVar12 != iVar3) {
                  pXVar10 = X509_NAME_dup(pXVar10);
                  if (pXVar10 == (X509_NAME *)0x0) {
                    ERR_put_error(0xb,0x95,0x41,"crypto/x509/x509_vfy.c",0x2a2);
                    *(undefined4 *)(param_1 + 0x60) = 0x11;
                    return 0;
                  }
                  ne = X509_NAME_delete_entry(pXVar10,iVar17);
                  o = X509_NAME_ENTRY_get_object(ne);
                  iVar3 = OBJ_obj2nid(o);
                  if ((iVar3 == 0xd) && (iVar3 = X509_NAME_cmp(pXVar10,name), iVar3 == 0)) {
                    X509_NAME_ENTRY_free(ne);
                    X509_NAME_free(pXVar10);
                    goto LAB_0016a146;
                  }
                  X509_NAME_ENTRY_free(ne);
                  X509_NAME_free(pXVar10);
                }
              }
            }
            *(int *)(param_1 + 0x5c) = iVar1;
            *(X509 **)(param_1 + 100) = pXVar2;
            *(undefined4 *)(param_1 + 0x60) = 0x48;
            iVar3 = (**(code **)(param_1 + 0x1c))(0,param_1);
            if (iVar3 == 0) {
              return 0;
            }
          }
LAB_0016a146:
          iVar3 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x50));
          iVar3 = iVar3 + -1;
          if (iVar1 < iVar3) {
            do {
              iVar17 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar3);
              nc = *(NAME_CONSTRAINTS **)(iVar17 + 0xa4);
              if (nc != (NAME_CONSTRAINTS *)0x0) {
                iVar17 = NAME_CONSTRAINTS_check(pXVar2,nc);
                if (iVar17 == 0 && iVar1 == 0) {
                  uVar14 = *(uint *)(*(int *)(param_1 + 0x10) + 0x28);
                  if ((int)(uVar14 << 0x1a) < 0) goto LAB_0016a1de;
                  if ((uVar14 & 1) == 0) {
                    a = (GENERAL_NAMES *)X509_get_ext_d2i(pXVar2,0x55,(int *)0x0,(int *)0x0);
                    iVar17 = 0;
                    if (a != (GENERAL_NAMES *)0x0) {
                      do {
                        iVar12 = OPENSSL_sk_num(a);
                        if (iVar12 <= iVar17) {
                          GENERAL_NAMES_free(a);
                          goto LAB_0016a1b6;
                        }
                        piVar9 = (int *)OPENSSL_sk_value(a,iVar17);
                        iVar17 = iVar17 + 1;
                      } while (*piVar9 != 2);
                      GENERAL_NAMES_free(a);
                      goto LAB_0016a1de;
                    }
                  }
LAB_0016a1b6:
                  iVar17 = NAME_CONSTRAINTS_check_CN(pXVar2,nc);
                }
                if (iVar17 != 0) {
                  if (iVar17 == 0x11) {
                    return 0;
                  }
                  *(int *)(param_1 + 0x5c) = iVar1;
                  *(X509 **)(param_1 + 100) = pXVar2;
                  if (iVar17 != 0) {
                    *(int *)(param_1 + 0x60) = iVar17;
                  }
                  iVar17 = (**(code **)(param_1 + 0x1c))(0,param_1);
                  if (iVar17 == 0) {
                    return 0;
                  }
                }
              }
LAB_0016a1de:
              iVar3 = iVar3 + -1;
            } while (iVar3 != iVar1);
          }
        }
        bVar19 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar19);
    }
    iVar1 = X509v3_asid_validate_path(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = X509v3_addr_validate_path(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xc) << 0x18 < 0) {
      iVar1 = (**(code **)(param_1 + 0x38))(param_1);
      return iVar1;
    }
    return iVar1;
  }
  iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),0);
  iVar17 = 0;
LAB_00169cca:
  do {
    do {
      if (iVar17 < iVar1 + -1) {
        local_2c[0] = (X509 *)0xffffffff;
        iVar12 = *(int *)(*(int *)(param_1 + 0x10) + 0x1c);
        if (0 < iVar12) {
          iVar5 = X509_get_signature_info(iVar3,0,0,local_2c,0);
          if (iVar5 != 0) {
            if (4 < iVar12) {
              iVar12 = 5;
            }
            if (*(int *)(&minbits_table + (iVar12 + -1) * 4) <= (int)local_2c[0]) goto LAB_00169d04;
          }
          *(int *)(param_1 + 0x5c) = iVar17;
          if (iVar3 == 0) {
            iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar17);
          }
          *(int *)(param_1 + 100) = iVar3;
          *(undefined4 *)(param_1 + 0x60) = 0x44;
          iVar3 = (**(code **)(param_1 + 0x1c))(0,param_1);
          if (iVar3 == 0) goto LAB_0016983a;
        }
      }
LAB_00169d04:
      iVar17 = iVar17 + 1;
      if (iVar1 == iVar17) goto LAB_0016a0d0;
      iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar17);
      iVar12 = X509_get0_pubkey();
      iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0x1c);
    } while (iVar5 < 1);
    if (iVar12 != 0) {
      iVar12 = EVP_PKEY_security_bits();
      if (4 < iVar5) {
        iVar5 = 5;
      }
      if (*(int *)(&minbits_table + (iVar5 + -1) * 4) <= iVar12) goto LAB_00169cca;
    }
    *(int *)(param_1 + 0x5c) = iVar17;
    iVar12 = iVar3;
    if (iVar3 == 0) {
      iVar12 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x50),iVar17);
    }
    *(int *)(param_1 + 100) = iVar12;
    *(undefined4 *)(param_1 + 0x60) = 0x43;
    iVar12 = (**(code **)(param_1 + 0x1c))(0,param_1);
  } while (iVar12 != 0);
LAB_0016983a:
  X509_get_pubkey_parameters((EVP_PKEY *)0x0,*(stack_st_X509 **)(param_1 + 0x50));
  return 0;
}

