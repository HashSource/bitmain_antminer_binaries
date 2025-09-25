
int c448_ed448_verify_part_0
              (void *param_1,void *param_2,void *param_3,undefined **param_4,char param_5,
              void *param_6,byte param_7)

{
  char *pcVar1;
  int iVar2;
  EVP_MD *type;
  size_t cnt;
  undefined1 auStack_2f0 [256];
  undefined1 auStack_1f0 [264];
  char *local_e8;
  undefined **local_e4;
  EVP_MD_CTX *local_e0;
  undefined **local_dc;
  char local_d4;
  byte local_d3;
  char local_9c [120];
  
  local_dc = param_4;
  iVar2 = curve448_point_decode_like_eddsa_and_mul_by_ratio(auStack_1f0);
  if (iVar2 == -1) {
    local_e0 = (EVP_MD_CTX *)&_GLOBAL_OFFSET_TABLE_;
    iVar2 = curve448_point_decode_like_eddsa_and_mul_by_ratio(auStack_2f0,param_1);
    if (iVar2 == -1) {
      local_e4 = (undefined **)local_e0;
      local_e0 = (EVP_MD_CTX *)EVP_MD_CTX_new();
      if (local_e0 != (EVP_MD_CTX *)0x0) {
        local_e8 = local_9c;
        local_d3 = param_7;
        if (param_5 != '\0') {
          param_5 = '\x01';
        }
        builtin_strncpy(local_9c,"SigEd448",8);
        local_9c[8] = 0;
        local_d4 = param_5;
        type = (EVP_MD *)EVP_shake256();
        iVar2 = EVP_DigestInit_ex(local_e0,type,(ENGINE *)0x0);
        pcVar1 = local_e8;
        if (iVar2 != 0) {
          cnt = strlen(local_e8);
          iVar2 = EVP_DigestUpdate(local_e0,pcVar1,cnt);
          if (iVar2 != 0) {
            iVar2 = EVP_DigestUpdate(local_e0,&local_d4,2);
            if ((((iVar2 != 0) &&
                 (iVar2 = EVP_DigestUpdate(local_e0,param_6,(uint)param_7), iVar2 != 0)) &&
                (iVar2 = EVP_DigestUpdate(local_e0,param_1,0x39), iVar2 != 0)) &&
               ((iVar2 = EVP_DigestUpdate(local_e0,param_2,0x39), iVar2 != 0 &&
                (iVar2 = EVP_DigestUpdate(local_e0,param_3,(size_t)local_dc), iVar2 != 0)))) {
              local_dc = local_e4;
              iVar2 = EVP_DigestFinalXOF(local_e0,local_e8,0x72);
              if (iVar2 != 0) {
                EVP_MD_CTX_free(local_e0);
                pcVar1 = local_e8;
                curve448_scalar_decode_long(&local_d4,local_e8,0x72);
                OPENSSL_cleanse(pcVar1,0x72);
                curve448_scalar_sub(&local_d4,local_dc[0x1d1],&local_d4);
                curve448_scalar_decode_long(pcVar1,(int)param_1 + 0x39,0x39);
                curve448_base_double_scalarmul_non_secret(auStack_1f0,pcVar1,auStack_1f0,&local_d4);
                iVar2 = curve448_point_eq(auStack_1f0,auStack_2f0);
                return iVar2;
              }
            }
          }
        }
      }
      EVP_MD_CTX_free(local_e0);
      iVar2 = 0;
    }
  }
  return iVar2;
}

