
int c448_ed448_sign(undefined4 *param_1,void *param_2,void *param_3,void *param_4,size_t param_5,
                   char param_6,void *param_7,uint param_8)

{
  undefined1 uVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  EVP_MD_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  EVP_MD *pEVar5;
  int iVar6;
  size_t sVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined1 auStack_2b0 [276];
  uint local_19c;
  char *local_198;
  undefined1 *local_194;
  char *local_190;
  void *local_18c;
  undefined **local_188;
  undefined4 *local_184;
  undefined1 auStack_180 [56];
  char local_148;
  undefined1 local_147;
  char local_110;
  undefined1 uStack_10f;
  undefined4 local_d8 [12];
  undefined4 auStack_a8 [3];
  uint local_9c [2];
  undefined1 local_94;
  byte local_65;
  undefined1 local_64;
  undefined1 auStack_63 [63];
  
  local_18c = param_3;
  local_184 = param_1;
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  local_188 = &_GLOBAL_OFFSET_TABLE_;
  memset(local_d8,0,0x39);
  if (ctx == (EVP_MD_CTX *)0x0) {
    return 0;
  }
  ctx_00 = (EVP_MD_CTX *)EVP_MD_CTX_new(ctx);
  if (ctx_00 != (EVP_MD_CTX *)0x0) {
    pEVar5 = (EVP_MD *)EVP_shake256();
    iVar6 = EVP_DigestInit_ex(ctx_00,pEVar5,(ENGINE *)0x0);
    if ((iVar6 != 0) && (iVar6 = EVP_DigestUpdate(ctx_00,param_2,0x39), iVar6 != 0)) {
      iVar6 = EVP_DigestFinalXOF(ctx_00,local_9c,0x72);
      if (iVar6 != 0) {
        local_194 = auStack_180;
        EVP_MD_CTX_free(ctx_00);
        local_65 = local_65 | 0x80;
        local_64 = 0;
        local_190 = &local_110;
        local_9c[0] = local_9c[0] & 0xfffffffc;
        curve448_scalar_decode_long(auStack_180,local_9c,0x39);
        builtin_strncpy(local_190,"SigEd448",9);
        if (param_8 < 0x100) {
          local_19c = param_8 & 0xff;
          local_198 = &local_148;
          local_147 = (undefined1)param_8;
          local_148 = param_6;
          if (param_6 != '\0') {
            local_148 = '\x01';
          }
          pEVar5 = (EVP_MD *)EVP_shake256();
          iVar6 = EVP_DigestInit_ex(ctx,pEVar5,(ENGINE *)0x0);
          pcVar2 = local_190;
          if (iVar6 != 0) {
            sVar7 = strlen(local_190);
            iVar6 = EVP_DigestUpdate(ctx,pcVar2,sVar7);
            if ((((iVar6 != 0) && (iVar6 = EVP_DigestUpdate(ctx,local_198,2), iVar6 != 0)) &&
                (iVar6 = EVP_DigestUpdate(ctx,param_7,param_8), iVar6 != 0)) &&
               ((iVar6 = EVP_DigestUpdate(ctx,auStack_63,0x39), iVar6 != 0 &&
                (iVar6 = EVP_DigestUpdate(ctx,param_4,param_5), iVar6 != 0)))) {
              OPENSSL_cleanse(local_9c,0x72);
              iVar6 = EVP_DigestFinalXOF(ctx,local_9c,0x72);
              pcVar2 = local_198;
              if (iVar6 == 0) goto LAB_001acf68;
              curve448_scalar_decode_long(local_198,local_9c,0x72);
              OPENSSL_cleanse(local_9c,0x72);
              curve448_scalar_halve(local_9c,pcVar2);
              curve448_scalar_halve(local_9c,local_9c);
              curve448_precomputed_scalarmul(auStack_2b0,*(undefined4 *)local_188[0x123],local_9c);
              curve448_point_mul_by_ratio_and_encode_like_eddsa(local_d8,auStack_2b0);
              curve448_point_destroy(auStack_2b0);
              curve448_scalar_destroy(local_9c);
              if (param_6 != '\0') {
                param_6 = '\x01';
              }
              uStack_10f = (undefined1)local_19c;
              local_9c[0] = 0x45676953;
              local_9c[1] = 0x38343464;
              local_94 = 0;
              local_110 = param_6;
              pEVar5 = (EVP_MD *)EVP_shake256();
              iVar6 = EVP_DigestInit_ex(ctx,pEVar5,(ENGINE *)0x0);
              if (iVar6 != 0) {
                sVar7 = strlen((char *)local_9c);
                iVar6 = EVP_DigestUpdate(ctx,local_9c,sVar7);
                if ((((iVar6 != 0) && (iVar6 = EVP_DigestUpdate(ctx,local_190,2), iVar6 != 0)) &&
                    ((iVar6 = EVP_DigestUpdate(ctx,param_7,param_8), iVar6 != 0 &&
                     (((iVar6 = EVP_DigestUpdate(ctx,local_d8,0x39), iVar6 != 0 &&
                       (iVar6 = EVP_DigestUpdate(ctx,local_18c,0x39), iVar6 != 0)) &&
                      (iVar6 = EVP_DigestUpdate(ctx,param_4,param_5), iVar6 != 0)))))) &&
                   (iVar6 = EVP_DigestFinalXOF(ctx,local_9c,0x72), pcVar2 = local_190, iVar6 != 0))
                {
                  curve448_scalar_decode_long(local_190,local_9c,0x72);
                  OPENSSL_cleanse(local_9c,0x72);
                  curve448_scalar_mul(pcVar2,pcVar2,local_194);
                  curve448_scalar_add(pcVar2,pcVar2,local_198);
                  puVar4 = local_184;
                  OPENSSL_cleanse(local_184,0x72);
                  pcVar2 = local_190;
                  puVar3 = local_d8;
                  do {
                    puVar12 = puVar4;
                    puVar11 = puVar3;
                    uVar8 = puVar11[1];
                    uVar9 = puVar11[2];
                    uVar10 = puVar11[3];
                    *puVar12 = *puVar11;
                    puVar12[1] = uVar8;
                    puVar12[2] = uVar9;
                    puVar12[3] = uVar10;
                    puVar3 = puVar11 + 4;
                    puVar4 = puVar12 + 4;
                  } while (puVar11 + 4 != auStack_a8);
                  iVar6 = -1;
                  uVar8 = puVar11[5];
                  uVar1 = *(undefined1 *)(puVar11 + 6);
                  puVar12[4] = puVar11[4];
                  puVar12[5] = uVar8;
                  *(undefined1 *)(puVar12 + 6) = uVar1;
                  curve448_scalar_encode((int)local_184 + 0x39,local_190);
                  curve448_scalar_destroy(local_194);
                  curve448_scalar_destroy(local_198);
                  curve448_scalar_destroy(pcVar2);
                  goto LAB_001acf68;
                }
              }
              goto LAB_001acf66;
            }
          }
        }
        OPENSSL_cleanse(local_9c,0x72);
        goto LAB_001acf66;
      }
    }
    EVP_MD_CTX_free(ctx_00);
  }
LAB_001acf66:
  iVar6 = 0;
LAB_001acf68:
  EVP_MD_CTX_free(ctx);
  return iVar6;
}

