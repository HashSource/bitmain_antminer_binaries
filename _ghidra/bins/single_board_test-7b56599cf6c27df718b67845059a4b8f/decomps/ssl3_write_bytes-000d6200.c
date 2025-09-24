
int ssl3_write_bytes(int param_1,int param_2,int param_3,uint param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  EVP_CIPHER *cipher;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  uint extraout_r1;
  uint *puVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  uint local_b8;
  uint local_ac;
  uint local_a8 [33];
  
  uVar12 = *(uint *)(param_1 + 0xf00);
  *(undefined4 *)(param_1 + 0x14) = 1;
  if (param_4 < uVar12) {
LAB_000d6456:
    uVar9 = 0x178;
    uVar10 = 0x10f;
    goto LAB_000d6466;
  }
  if (*(int *)(param_1 + 0x688) == 0) {
    if (*(int *)(param_1 + 0x68) == 4) {
LAB_000d6296:
      iVar1 = early_data_count_ok(param_1,param_4,0,1);
      if (iVar1 == 0) {
        return -1;
      }
      *(undefined4 *)(param_1 + 0xf00) = 0;
      if (*(int *)(param_1 + 0x688) != 0) goto LAB_000d623e;
    }
    else {
      *(undefined4 *)(param_1 + 0xf00) = 0;
    }
    if (*(int *)(param_1 + 0x5f0) != -1) {
      ossl_statem_set_in_init(param_1,1);
    }
  }
  else {
    if (param_4 < *(int *)(param_1 + 0xf10) + uVar12) goto LAB_000d6456;
    iVar1 = *(int *)(param_1 + 0x68);
    bVar13 = iVar1 != 4;
    if (bVar13) {
      iVar1 = 0;
    }
    if (!bVar13) goto LAB_000d6296;
    *(int *)(param_1 + 0xf00) = iVar1;
  }
LAB_000d623e:
  iVar1 = SSL_in_init(param_1);
  if (((iVar1 != 0) && (iVar1 = ossl_statem_get_in_handshake(param_1), iVar1 == 0)) &&
     (*(int *)(param_1 + 0x68) != 6)) {
    iVar1 = (**(code **)(param_1 + 0x18))(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (iVar1 == 0) {
      return -1;
    }
  }
  if (*(int *)(param_1 + 0x688) != 0) {
    iVar1 = ssl3_write_pending(param_1,param_2,param_3 + uVar12,*(undefined4 *)(param_1 + 0xf10),
                               &local_ac);
    if (iVar1 < 1) {
LAB_000d641c:
      *(uint *)(param_1 + 0xf00) = uVar12;
      return iVar1;
    }
    uVar12 = uVar12 + local_ac;
  }
  if (uVar12 == param_4) {
    if ((*(int *)(param_1 + 0x4f0) << 0x1b < 0) &&
       (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c)) {
      ssl3_release_write_buffer(param_1);
    }
    *param_5 = uVar12;
    return 1;
  }
  param_4 = param_4 - uVar12;
  uVar2 = ssl_get_max_send_fragment(param_1);
  uVar3 = ssl_get_split_send_fragment(param_1);
  local_b8 = *(uint *)(param_1 + 0x510);
  if (local_b8 < 0x21) {
    if ((local_b8 == 0) || (*(EVP_CIPHER_CTX **)(param_1 + 0x3ec) == (EVP_CIPHER_CTX *)0x0)) {
LAB_000d62f8:
      local_b8 = 1;
    }
    else {
      cipher = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)(param_1 + 0x3ec));
      uVar4 = EVP_CIPHER_flags(cipher);
      if ((-1 < (int)(uVar4 << 8)) ||
         (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1f)) goto LAB_000d62f8;
    }
    if (uVar3 <= uVar2 && (uVar3 != 0 && uVar2 != 0)) {
      while( true ) {
        uVar11 = 1;
        if (param_4 != 0) {
          iVar1 = __aeabi_uidiv(param_4 - 1,uVar3);
          uVar11 = iVar1 + 1U;
          if (local_b8 <= iVar1 + 1U) {
            uVar11 = local_b8;
          }
        }
        uVar5 = __aeabi_uidiv(param_4,uVar11);
        if (uVar5 < uVar2) {
          __aeabi_uidivmod(param_4,uVar11);
          uVar8 = 0;
          do {
            uVar6 = uVar5 + 1;
            if (extraout_r1 <= uVar8) {
              uVar6 = uVar5;
            }
            local_a8[uVar8] = uVar6;
            uVar8 = uVar8 + 1;
          } while (uVar11 != uVar8);
        }
        else {
          puVar7 = &local_ac;
          do {
            puVar7 = puVar7 + 1;
            *puVar7 = uVar2;
          } while (puVar7 != local_a8 + uVar11 + 0x3fffffff);
        }
        iVar1 = do_ssl3_write(param_1,param_2,param_3 + uVar12,local_a8,uVar11,0,&local_ac);
        if (iVar1 < 1) goto LAB_000d641c;
        if (param_4 == local_ac) break;
        if ((param_2 == 0x17) && (*(int *)(param_1 + 0x4f0) << 0x1f < 0)) {
          *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xd0) = 0;
LAB_000d63be:
          *param_5 = local_ac + uVar12;
          return 1;
        }
        param_4 = param_4 - local_ac;
        uVar12 = uVar12 + local_ac;
      }
      iVar1 = *(int *)(param_1 + 0x4f0);
      *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xd0) = 0;
      if ((iVar1 << 0x1b < 0) &&
         (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c)) {
        ssl3_release_write_buffer(param_1);
      }
      goto LAB_000d63be;
    }
    uVar9 = 0x256;
  }
  else {
    uVar9 = 0x246;
  }
  uVar10 = 0x44;
LAB_000d6466:
  ossl_statem_fatal(param_1,0x50,0x9e,uVar10,"ssl/record/rec_layer_s3.c",uVar9);
  return -1;
}

