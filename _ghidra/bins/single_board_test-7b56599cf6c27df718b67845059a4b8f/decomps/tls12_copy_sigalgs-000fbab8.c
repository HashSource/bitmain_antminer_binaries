
/* WARNING: Type propagation algorithm not settling */

bool tls12_copy_sigalgs(SSL *param_1,undefined4 param_2,short *param_3,int param_4)

{
  int iVar1;
  stack_st_SSL_CIPHER *psVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  bool bVar9;
  short sVar10;
  bool bVar11;
  undefined4 local_2c;
  
  if (param_4 != 0) {
    bVar9 = false;
    iVar8 = 0;
    do {
      puVar7 = &sigalg_lookup_tbl;
      do {
        if (*(short *)(puVar7 + 4) == *param_3) goto LAB_000fbaee;
        puVar7 = puVar7 + 0x20;
      } while (puVar7 != legacy_rsa_sigalg);
      puVar7 = (undefined1 *)0x0;
LAB_000fbaee:
      iVar1 = tls1_lookup_md(puVar7,0);
      if (iVar1 != 0) {
        if (*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) {
LAB_000fbb46:
          iVar1 = ssl_cert_is_disabled(*(undefined4 *)(puVar7 + 0x14));
          if (iVar1 == 0) {
            uVar5 = *(uint *)(puVar7 + 0x10);
            bVar11 = 0x32a < uVar5;
            if (uVar5 != 0x32b) {
              bVar11 = uVar5 != 0x3d3;
            }
            if (!bVar11 || (uVar5 == 0x32b || uVar5 == 0x3d4)) {
              if (param_1->in_handshake == 0) {
                if ((*(int *)param_1->type == 0x10000) &&
                   (0x303 < *(int *)(param_1->mac_flags + 0x2ac))) {
                  if ((*(int *)(param_1->mac_flags + 0x2a8) < 0x304) &&
                     (psVar2 = SSL_get_ciphers(param_1), psVar2 != (stack_st_SSL_CIPHER *)0x0)) {
                    iVar1 = OPENSSL_sk_num();
                    if (iVar1 < 1) {
                      if (iVar1 != 0) goto LAB_000fbba6;
                    }
                    else {
                      iVar6 = 0;
                      do {
                        iVar3 = OPENSSL_sk_value(psVar2,iVar6);
                        iVar6 = iVar6 + 1;
                        iVar4 = ssl_cipher_disabled(param_1,iVar3,0x10001,0);
                        if ((iVar4 == 0) && (*(int *)(iVar3 + 0x10) << 0x1b < 0)) goto LAB_000fbba6;
                      } while (iVar1 != iVar6);
                    }
                  }
                  goto LAB_000fbb88;
                }
              }
              else if (-1 < *(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c) {
                iVar6 = *(int *)param_1->type;
                iVar1 = iVar6 + -0x10000;
                if (iVar1 != 0) {
                  iVar1 = 1;
                }
                if (iVar6 < 0x304) {
                  iVar1 = 0;
                }
                if (iVar1 != 0) goto LAB_000fbb88;
              }
            }
LAB_000fbba6:
            local_2c = (EVP_MD *)0x0;
            iVar1 = tls1_lookup_md(puVar7,&local_2c);
            if (iVar1 == 0) {
              sVar10 = *(short *)(puVar7 + 4);
              iVar1 = 0;
            }
            else if (local_2c == (EVP_MD *)0x0) {
              sVar10 = *(short *)(puVar7 + 4);
              if (sVar10 == 0x807) {
                iVar1 = 0x80;
              }
              else if (sVar10 == 0x808) {
                iVar1 = 0xe0;
              }
              else {
                iVar1 = 0;
              }
            }
            else {
              iVar1 = EVP_MD_size(local_2c);
              sVar10 = *(short *)(puVar7 + 4);
              iVar1 = iVar1 << 2;
            }
            local_2c = (EVP_MD *)
                       CONCAT31(CONCAT21(local_2c._2_2_,(char)sVar10),(char)((ushort)sVar10 >> 8));
            iVar1 = ssl_security(param_1,0x5000b,iVar1,*(undefined4 *)(puVar7 + 8),&local_2c);
            if (iVar1 != 0) {
              iVar1 = WPACKET_put_bytes__(param_2,2,*param_3,0,2);
              if (iVar1 == 0) {
                return false;
              }
              if (bVar9 == false) {
                if ((*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) ||
                   (iVar1 = *(int *)param_1->type, iVar1 == 0x10000 || iVar1 < 0x304)) {
                  bVar9 = true;
                }
                else if (*(int *)(puVar7 + 0x10) != 6) {
                  bVar9 = *(int *)(puVar7 + 8) != 0x2a3 && *(int *)(puVar7 + 8) != 0x40;
                }
              }
            }
          }
        }
        else {
          iVar1 = *(int *)param_1->type;
          if ((iVar1 == 0x10000 || iVar1 < 0x304) || (*(int *)(puVar7 + 0x10) != 0x74)) {
            if ((param_1->in_handshake != 0) || (*(int *)(param_1->mac_flags + 0x2a8) < 0x304))
            goto LAB_000fbb46;
            if (*(int *)(puVar7 + 0x10) != 0x74) {
              uVar5 = *(uint *)(puVar7 + 0xc);
              bVar11 = 9 < uVar5;
              if (uVar5 != 10) {
                bVar11 = uVar5 != 0;
              }
              if (bVar11 && (uVar5 != 10 && uVar5 != 1)) goto LAB_000fbb46;
            }
          }
        }
      }
LAB_000fbb88:
      iVar8 = iVar8 + 1;
      param_3 = param_3 + 1;
    } while (param_4 != iVar8);
    if (bVar9 != false) {
      return bVar9;
    }
  }
  ERR_put_error(0x14,0x215,0x76,"ssl/t1_lib.c",0x6b8);
  return false;
}

