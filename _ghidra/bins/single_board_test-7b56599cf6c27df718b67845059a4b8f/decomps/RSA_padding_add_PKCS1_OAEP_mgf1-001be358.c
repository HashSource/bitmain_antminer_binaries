
uint RSA_padding_add_PKCS1_OAEP_mgf1
               (undefined1 *param_1,int param_2,void *param_3,size_t param_4,void *param_5,
               size_t param_6,EVP_MD *param_7,EVP_MD *param_8)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint num;
  int iVar4;
  uint *puVar5;
  byte *pbVar6;
  uint *puVar7;
  uint *md;
  uint uVar8;
  uint uVar9;
  uint *buf;
  uint *puVar10;
  int iVar11;
  uint num_00;
  uint *mask;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 local_6c;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  param_2 = param_2 + -1;
  if (param_7 == (EVP_MD *)0x0) {
    param_7 = EVP_sha1();
  }
  if (param_8 == (EVP_MD *)0x0) {
    param_8 = param_7;
  }
  num = EVP_MD_size(param_7);
  iVar11 = param_2 + num * -2;
  if (iVar11 <= (int)param_4) {
    ERR_put_error(4,0x9a,0x6e,"crypto/rsa/rsa_oaep.c",0x3e);
    return 0;
  }
  if (param_2 == num * 2 || (int)(param_2 + num * -2) < 0 != SBORROW4(param_2,num * 2)) {
    ERR_put_error(4,0x9a,0x78,"crypto/rsa/rsa_oaep.c",0x44);
    return 0;
  }
  uVar9 = 0;
  md = (uint *)(param_1 + num + 1);
  *param_1 = 0;
  iVar4 = EVP_Digest(param_5,param_6,(uchar *)md,(uint *)0x0,param_7,(ENGINE *)0x0);
  if (iVar4 != 0) {
    iVar4 = (param_2 - param_4) + num * -2;
    memset((byte *)((int)md + num),0,iVar4 - 1);
    buf = (uint *)(param_1 + 1);
    ((byte *)((int)md + num))[iVar4 + -1] = 1;
    memcpy((byte *)(((param_2 - param_4) - num) + (int)md),param_3,param_4);
    iVar4 = RAND_bytes((uchar *)buf,num);
    if (0 < iVar4) {
      num_00 = iVar11 + num;
      mask = (uint *)CRYPTO_malloc(num_00,"crypto/rsa/rsa_oaep.c",0x55);
      if (mask == (uint *)0x0) {
        ERR_put_error(4,0x9a,0x41,"crypto/rsa/rsa_oaep.c",0x57);
        uVar9 = 0;
      }
      else {
        iVar11 = PKCS1_MGF1((uchar *)mask,num_00,(uchar *)buf,num,param_8);
        if (-1 < iVar11) {
          if (0 < (int)num_00) {
            if ((((uint)md | (uint)mask) & 3) == 0 &&
                (6 < num_00 && (mask + 1 <= md || param_1 + num + 5 <= mask))) {
              uVar8 = num_00 - 4 >> 2;
              uVar14 = uVar8 + 1;
              uVar8 = uVar8 - 8;
              uVar13 = uVar14 * 4;
              puVar5 = md;
              puVar10 = md;
              puVar7 = mask;
              if (uVar8 < 0xfffffff7) {
                uVar12 = 0;
                uVar9 = (uVar8 & 0xfffffff8) + 8;
                puVar2 = md + 8;
                puVar3 = md + 8;
                puVar1 = mask;
                do {
                  puVar5 = puVar3;
                  puVar10 = puVar2;
                  puVar7 = puVar1 + 8;
                  uVar12 = uVar12 + 8;
                  HintPreloadData(puVar10 + 0xc);
                  puVar5[-8] = puVar10[-8] ^ *puVar1;
                  puVar5[-7] = puVar10[-7] ^ puVar1[1];
                  puVar5[-6] = puVar10[-6] ^ puVar1[2];
                  puVar5[-5] = puVar10[-5] ^ puVar1[3];
                  puVar5[-4] = puVar10[-4] ^ puVar1[4];
                  puVar5[-3] = puVar10[-3] ^ puVar1[5];
                  puVar5[-2] = puVar10[-2] ^ puVar1[6];
                  puVar5[-1] = puVar10[-1] ^ puVar1[7];
                  puVar2 = puVar10 + 8;
                  puVar3 = puVar5 + 8;
                  puVar1 = puVar7;
                  local_6c = puVar5;
                } while (uVar12 != uVar9);
              }
              puVar10 = puVar10 + -1;
              puVar7 = puVar7 + -1;
              do {
                puVar10 = puVar10 + 1;
                uVar9 = uVar9 + 1;
                puVar7 = puVar7 + 1;
                *puVar5 = *puVar7 ^ *puVar10;
                puVar5 = puVar5 + 1;
              } while (uVar9 < uVar14);
              if (num_00 != uVar13) {
                iVar11 = uVar13 + 1;
                *(byte *)(md + uVar14) = (byte)md[uVar14] ^ (byte)mask[uVar14];
                if (iVar11 < (int)num_00) {
                  iVar4 = uVar13 + 2;
                  *(byte *)((int)md + iVar11) =
                       *(byte *)((int)md + iVar11) ^ *(byte *)((int)mask + iVar11);
                  if (iVar4 < (int)num_00) {
                    *(byte *)((int)md + iVar4) =
                         *(byte *)((int)md + iVar4) ^ *(byte *)((int)mask + iVar4);
                  }
                }
              }
            }
            else {
              pbVar6 = (byte *)((int)mask + -1);
              puVar10 = md;
              do {
                pbVar6 = pbVar6 + 1;
                puVar7 = (uint *)((int)puVar10 + 1);
                *(byte *)puVar10 = *pbVar6 ^ (byte)*puVar10;
                puVar10 = puVar7;
              } while (puVar7 != (uint *)((int)md + num_00));
            }
          }
          iVar11 = PKCS1_MGF1((uchar *)&local_68,num,(uchar *)md,num_00,param_8);
          if (iVar11 < 0) {
            uVar9 = 0;
          }
          else {
            if (0 < (int)num) {
              if (((uint)buf & 3) == 0 && 5 < num) {
                iVar11 = (num - 4 >> 2) + 1;
                *(uint *)(param_1 + 1) = *(uint *)(param_1 + 1) ^ local_68;
                uVar9 = iVar11 * 4;
                if (((((iVar11 != 1) &&
                      (*(uint *)(param_1 + 5) = local_64 ^ *(uint *)(param_1 + 5), iVar11 != 2)) &&
                     (*(uint *)(param_1 + 9) = local_60 ^ *(uint *)(param_1 + 9), iVar11 != 3)) &&
                    (((*(uint *)(param_1 + 0xd) = local_5c ^ *(uint *)(param_1 + 0xd), iVar11 != 4
                      && (*(uint *)(param_1 + 0x11) = local_58 ^ *(uint *)(param_1 + 0x11),
                         iVar11 != 5)) &&
                     ((*(uint *)(param_1 + 0x15) = local_54 ^ *(uint *)(param_1 + 0x15), iVar11 != 6
                      && ((*(uint *)(param_1 + 0x19) = local_50 ^ *(uint *)(param_1 + 0x19),
                          iVar11 != 7 &&
                          (*(uint *)(param_1 + 0x1d) = local_4c ^ *(uint *)(param_1 + 0x1d),
                          iVar11 != 8)))))))) &&
                   ((*(uint *)(param_1 + 0x21) = local_48 ^ *(uint *)(param_1 + 0x21), iVar11 != 9
                    && (((((*(uint *)(param_1 + 0x25) = local_44 ^ *(uint *)(param_1 + 0x25),
                           iVar11 != 10 &&
                           (*(uint *)(param_1 + 0x29) = local_40 ^ *(uint *)(param_1 + 0x29),
                           iVar11 != 0xb)) &&
                          (*(uint *)(param_1 + 0x2d) = local_3c ^ *(uint *)(param_1 + 0x2d),
                          iVar11 != 0xc)) &&
                         ((*(uint *)(param_1 + 0x31) = local_38 ^ *(uint *)(param_1 + 0x31),
                          iVar11 != 0xd &&
                          (*(uint *)(param_1 + 0x35) = local_34 ^ *(uint *)(param_1 + 0x35),
                          iVar11 != 0xe)))) &&
                        (*(uint *)(param_1 + 0x39) = local_30 ^ *(uint *)(param_1 + 0x39),
                        iVar11 != 0xf)))))) {
                  *(uint *)(param_1 + 0x3d) = local_2c ^ *(uint *)(param_1 + 0x3d);
                }
                if (num != uVar9) {
                  iVar4 = uVar9 + 1;
                  *(byte *)(buf + iVar11) = *(byte *)(&local_68 + iVar11) ^ (byte)buf[iVar11];
                  if (iVar4 < (int)num) {
                    iVar11 = uVar9 + 2;
                    *(byte *)((int)buf + iVar4) =
                         *(byte *)((int)&local_68 + uVar9 + 1) ^ *(byte *)((int)buf + iVar4);
                    if (iVar11 < (int)num) {
                      *(byte *)((int)buf + iVar11) =
                           *(byte *)((int)&local_68 + uVar9 + 2) ^ *(byte *)((int)buf + iVar11);
                    }
                  }
                }
              }
              else {
                pbVar6 = (byte *)((int)&local_6c + 3);
                do {
                  pbVar6 = pbVar6 + 1;
                  puVar10 = (uint *)((int)buf + 1);
                  *(byte *)buf = (byte)*buf ^ *pbVar6;
                  buf = puVar10;
                } while (md != puVar10);
              }
            }
            uVar9 = 1;
          }
        }
      }
      goto LAB_001be3b8;
    }
  }
  num_00 = 0;
  mask = (uint *)0x0;
  uVar9 = 0;
LAB_001be3b8:
  OPENSSL_cleanse(&local_68,0x40);
  CRYPTO_clear_free(mask,num_00,"crypto/rsa/rsa_oaep.c",0x68);
  return uVar9;
}

