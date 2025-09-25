
int pkey_tls1_prf_derive(int param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  EVP_MD *pEVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint num;
  
  puVar6 = *(undefined4 **)(param_1 + 0x14);
  pEVar7 = (EVP_MD *)*puVar6;
  if (pEVar7 == (EVP_MD *)0x0) {
    ERR_put_error(0x34,0x65,0x69,"crypto/kdf/tls1_prf.c",0x81);
    iVar2 = 0;
  }
  else {
    iVar11 = puVar6[1];
    if (iVar11 == 0) {
      ERR_put_error(0x34,0x65,0x6b,"crypto/kdf/tls1_prf.c",0x85);
      iVar2 = 0;
    }
    else {
      iVar9 = puVar6[0x103];
      if (iVar9 == 0) {
        ERR_put_error(0x34,0x65,0x6a,"crypto/kdf/tls1_prf.c",0x89);
        return 0;
      }
      uVar15 = puVar6[2];
      num = *param_3;
      iVar2 = EVP_MD_type(pEVar7);
      puVar6 = puVar6 + 3;
      if (iVar2 == 0x72) {
        iVar16 = (uVar15 & 1) + (uVar15 >> 1);
        pEVar7 = EVP_md5();
        iVar2 = tls1_prf_P_hash(pEVar7,iVar11,iVar16,puVar6,iVar9,param_2,num);
        if (iVar2 != 0) {
          puVar3 = (uint *)CRYPTO_malloc(num,"crypto/kdf/tls1_prf.c",0x104);
          if (puVar3 == (uint *)0x0) {
            ERR_put_error(0x34,0x6f,0x41,"crypto/kdf/tls1_prf.c",0x105);
            iVar2 = 0;
          }
          else {
            pEVar7 = EVP_sha1();
            iVar2 = tls1_prf_P_hash(pEVar7,(uVar15 >> 1) + iVar11,iVar16,puVar6,iVar9,puVar3,num);
            if (iVar2 == 0) {
              CRYPTO_clear_free(puVar3,num,"crypto/kdf/tls1_prf.c",0x10a);
              iVar2 = 0;
            }
            else {
              if (num != 0) {
                if ((((uint)puVar3 | (uint)param_2) & 3) == 0 &&
                    (6 < num && (param_2 + 1 <= puVar3 || puVar3 + 1 <= param_2))) {
                  uVar15 = num - 4 >> 2;
                  uVar8 = uVar15 + 1;
                  uVar15 = uVar15 - 8;
                  uVar12 = uVar8 * 4;
                  if (uVar15 < 0xfffffff7) {
                    uVar15 = (uVar15 & 0xfffffff8) + 8;
                    uVar10 = 0;
                    puVar1 = param_2 + 8;
                    puVar4 = puVar3;
                    do {
                      puVar14 = puVar1;
                      uVar10 = uVar10 + 8;
                      HintPreloadData(puVar14 + 0xc);
                      puVar14[-8] = puVar14[-8] ^ *puVar4;
                      puVar14[-7] = puVar4[1] ^ puVar14[-7];
                      puVar14[-6] = puVar4[2] ^ puVar14[-6];
                      puVar14[-5] = puVar4[3] ^ puVar14[-5];
                      puVar14[-4] = puVar4[4] ^ puVar14[-4];
                      puVar14[-3] = puVar4[5] ^ puVar14[-3];
                      puVar14[-2] = puVar14[-2] ^ puVar4[6];
                      puVar14[-1] = puVar14[-1] ^ puVar4[7];
                      puVar1 = puVar14 + 8;
                      puVar13 = puVar4 + 8;
                      puVar4 = puVar4 + 8;
                    } while (uVar10 != uVar15);
                  }
                  else {
                    uVar15 = 0;
                    puVar14 = param_2;
                    puVar13 = puVar3;
                  }
                  puVar13 = puVar13 + -1;
                  puVar4 = puVar14 + -1;
                  do {
                    puVar4 = puVar4 + 1;
                    uVar15 = uVar15 + 1;
                    puVar13 = puVar13 + 1;
                    *puVar14 = *puVar13 ^ *puVar4;
                    puVar14 = puVar14 + 1;
                  } while (uVar15 < uVar8);
                  if (num != uVar12) {
                    uVar15 = uVar12 + 1;
                    *(byte *)(param_2 + uVar8) = (byte)param_2[uVar8] ^ (byte)puVar3[uVar8];
                    if (uVar15 < num) {
                      uVar12 = uVar12 + 2;
                      *(byte *)((int)param_2 + uVar15) =
                           *(byte *)((int)param_2 + uVar15) ^ *(byte *)((int)puVar3 + uVar15);
                      if (uVar12 < num) {
                        *(byte *)((int)param_2 + uVar12) =
                             *(byte *)((int)param_2 + uVar12) ^ *(byte *)((int)puVar3 + uVar12);
                      }
                    }
                  }
                }
                else {
                  pbVar5 = (byte *)((int)puVar3 + -1);
                  puVar13 = param_2;
                  do {
                    pbVar5 = pbVar5 + 1;
                    puVar14 = (uint *)((int)puVar13 + 1);
                    *(byte *)puVar13 = *pbVar5 ^ (byte)*puVar13;
                    puVar13 = puVar14;
                  } while ((uint *)((int)param_2 + num) != puVar14);
                }
              }
              iVar2 = 1;
              CRYPTO_clear_free(puVar3,num,"crypto/kdf/tls1_prf.c",0x10f);
            }
          }
        }
      }
      else {
        iVar2 = tls1_prf_P_hash(pEVar7,iVar11,uVar15,puVar6,iVar9,param_2,num);
        if (iVar2 != 0) {
          iVar2 = 1;
        }
      }
    }
  }
  return iVar2;
}

