
int ssl3_choose_cipher(int *param_1,int param_2,int param_3)

{
  EVP_MD *pEVar1;
  int iVar2;
  EVP_MD *pEVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int local_3c;
  uint local_30;
  int local_2c;
  
  pEVar1 = EVP_sha256();
  if ((*(uint *)(param_1[0x101] + 0x10) & 0x30000) == 0) {
    if ((param_1[0x13b] & 0x400000U) != 0) {
      if (((param_1[0x13b] << 10 < 0) && (iVar6 = OPENSSL_sk_num(param_2), 0 < iVar6)) &&
         (iVar6 = OPENSSL_sk_value(param_2,0), *(int *)(iVar6 + 0x18) == 0x80000)) {
        iVar8 = OPENSSL_sk_num(param_3);
        iVar6 = 0;
        if (0 < iVar8) {
LAB_000d64e6:
          iVar2 = OPENSSL_sk_value(param_3,iVar6);
          if (*(int *)(iVar2 + 0x18) != 0x80000) goto LAB_000d64de;
          iVar5 = OPENSSL_sk_new_reserve(0,iVar8);
          if (iVar5 != 0) {
            iVar6 = iVar6 + 1;
            OPENSSL_sk_push(iVar5,iVar2);
            if (iVar6 < iVar8) {
              do {
                iVar2 = OPENSSL_sk_value(param_3,iVar6);
                iVar6 = iVar6 + 1;
                if (*(int *)(iVar2 + 0x18) == 0x80000) {
                  OPENSSL_sk_push(iVar5,iVar2);
                }
              } while (iVar8 != iVar6);
            }
            iVar6 = 0;
            do {
              iVar2 = OPENSSL_sk_value(param_3,iVar6);
              iVar6 = iVar6 + 1;
              if (*(int *)(iVar2 + 0x18) != 0x80000) {
                OPENSSL_sk_push(iVar5);
              }
              local_2c = iVar5;
            } while (iVar8 != iVar6);
            goto LAB_000d6244;
          }
        }
      }
      goto LAB_000d6240;
    }
    iVar5 = param_2;
    param_2 = param_3;
    local_2c = 0;
  }
  else {
LAB_000d6240:
    local_2c = 0;
    iVar5 = param_3;
  }
LAB_000d6244:
  if ((*(uint *)(((int *)param_1[1])[0x19] + 0x30) & 8) == 0) {
    iVar8 = *(int *)param_1[1];
    iVar6 = iVar8 + -0x10000;
    if (iVar6 != 0) {
      iVar6 = 1;
    }
    if (iVar8 < 0x304) {
      iVar6 = 0;
    }
    if (iVar6 != 0) {
      local_30 = param_1[0x131];
      if (local_30 != 0) {
        iVar6 = param_1[0x101];
        if ((*(int *)(iVar6 + 0x14) == 0) || (*(int *)(iVar6 + 0x18) == 0)) {
          if ((((((*(int *)(iVar6 + 0x28) == 0) || (*(int *)(iVar6 + 0x2c) == 0)) &&
                ((*(int *)(iVar6 + 0x3c) == 0 || (*(int *)(iVar6 + 0x40) == 0)))) &&
               ((*(int *)(iVar6 + 0x50) == 0 || (*(int *)(iVar6 + 0x54) == 0)))) &&
              (((*(int *)(iVar6 + 100) == 0 || (*(int *)(iVar6 + 0x68) == 0)) &&
               ((*(int *)(iVar6 + 0x78) == 0 || (*(int *)(iVar6 + 0x7c) == 0)))))) &&
             (((*(int *)(iVar6 + 0x8c) == 0 || (*(int *)(iVar6 + 0x90) == 0)) &&
              ((*(int *)(iVar6 + 0xa0) == 0 || (*(int *)(iVar6 + 0xa4) == 0)))))) {
            if (*(int *)(iVar6 + 0xb4) == 0) {
              local_30 = 1;
            }
            else {
              local_30 = (uint)(*(int *)(iVar6 + 0xb8) == 0);
            }
          }
          else {
            local_30 = 0;
          }
        }
        else {
          local_30 = 0;
        }
      }
      goto LAB_000d62f6;
    }
  }
  local_30 = 0;
  tls1_set_cert_validity(param_1);
  ssl_set_masks(param_1);
LAB_000d62f6:
  uVar12 = 0;
  uVar11 = 0;
  iVar6 = 0;
  local_3c = 0;
  do {
    iVar2 = OPENSSL_sk_num(iVar5);
    iVar8 = local_3c;
    if (iVar2 <= iVar6) {
LAB_000d6480:
      local_3c = iVar8;
      OPENSSL_sk_free(local_2c);
      return local_3c;
    }
    iVar8 = OPENSSL_sk_value(iVar5,iVar6);
    if (*(int *)(((int *)param_1[1])[0x19] + 0x30) << 0x1c < 0) {
      iVar9 = *param_1;
      iVar2 = *(int *)(iVar8 + 0x28);
      if (iVar9 == 0x100) {
        if (iVar2 != 0x100) {
          iVar4 = 0xff00;
          goto LAB_000d6328;
        }
LAB_000d6468:
        iVar2 = *(int *)(iVar8 + 0x2c);
        if (iVar2 == 0x100) goto LAB_000d6404;
        iVar9 = 0xff00;
      }
      else {
        iVar4 = iVar9;
        if (iVar2 == 0x100) {
          iVar2 = 0xff00;
        }
LAB_000d6328:
        if (iVar2 < iVar4) goto LAB_000d632c;
        if (iVar9 == 0x100) goto LAB_000d6468;
        iVar2 = *(int *)(iVar8 + 0x2c);
        if (iVar2 == 0x100) {
          iVar2 = 0xff00;
        }
      }
      if (iVar2 <= iVar9) {
LAB_000d6404:
        uVar11 = *(uint *)(iVar8 + 0x10);
        uVar7 = *(uint *)(param_1[0x1f] + 0x2a0);
        uVar10 = *(uint *)(param_1[0x1f] + 0x2a4);
        uVar12 = *(uint *)(iVar8 + 0x14);
        if (param_1[0x192] << 0x1a < 0) {
          uVar7 = uVar7 | 0x20;
          uVar10 = uVar10 | 0x40;
        }
        if ((((((uVar11 & 0x1c8) == 0) || (param_1[0x131] != 0)) && ((uVar7 & uVar11) != 0)) &&
            ((uVar10 & uVar12) != 0)) &&
           ((-1 < (int)(uVar11 << 0x1d) ||
            (iVar2 = tls1_check_ec_tmp_key(param_1,*(undefined4 *)(iVar8 + 0xc)), iVar2 != 0))))
        goto LAB_000d6378;
      }
    }
    else if ((*(int *)(iVar8 + 0x20) <= *param_1) && (*param_1 <= *(int *)(iVar8 + 0x24))) {
      iVar2 = *(int *)param_1[1];
      if (iVar2 < 0x304 || iVar2 == 0x10000) goto LAB_000d6404;
LAB_000d6378:
      iVar2 = OPENSSL_sk_find(param_2,iVar8);
      if ((-1 < iVar2) &&
         (iVar8 = ssl_security(param_1,0x10002,*(undefined4 *)(iVar8 + 0x38),0,iVar8), iVar8 != 0))
      {
        if ((((int)(uVar11 << 0x1d) < 0) && ((uVar12 & 8) != 0)) &&
           (*(char *)(param_1[0x1f] + 0x354) != '\0')) {
          if (local_3c == 0) {
            local_3c = OPENSSL_sk_value(param_2,iVar2);
          }
        }
        else {
          if (local_30 == 0) {
            iVar8 = OPENSSL_sk_value(param_2,iVar2);
            goto LAB_000d6480;
          }
          iVar8 = OPENSSL_sk_value(param_2,iVar2);
          pEVar3 = (EVP_MD *)ssl_md(*(undefined4 *)(iVar8 + 0x34));
          if (pEVar1 == pEVar3) goto LAB_000d6480;
          if (local_3c == 0) {
            local_3c = iVar8;
          }
        }
      }
    }
LAB_000d632c:
    iVar6 = iVar6 + 1;
  } while( true );
LAB_000d64de:
  iVar6 = iVar6 + 1;
  if (iVar8 == iVar6) goto LAB_000d6240;
  goto LAB_000d64e6;
}

