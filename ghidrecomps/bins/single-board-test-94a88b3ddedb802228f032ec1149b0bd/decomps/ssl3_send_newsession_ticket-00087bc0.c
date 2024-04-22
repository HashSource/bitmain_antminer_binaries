
undefined4 ssl3_send_newsession_ticket(int param_1)

{
  undefined4 uVar1;
  uint num;
  uchar *in;
  int iVar2;
  SSL_SESSION *in_00;
  size_t __n;
  EVP_CIPHER *cipher;
  EVP_MD *md;
  uchar uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uchar *data;
  int iVar7;
  uchar *puVar8;
  uchar *local_1ac;
  uchar *local_1a8;
  uchar *local_1a4;
  uint local_1a0;
  uchar auStack_19c [16];
  undefined4 local_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  EVP_CIPHER_CTX EStack_17c;
  HMAC_CTX HStack_f0;
  
  if (*(int *)(param_1 + 0x34) == 0x21f0) {
    iVar7 = *(int *)(param_1 + 0x170);
    num = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
    uVar6 = 1 - num;
    if (1 < num) {
      uVar6 = 0;
    }
    if (0xff00 < (int)num) {
      uVar6 = uVar6 | 1;
    }
    if ((uVar6 != 0) || (in = (uchar *)CRYPTO_malloc(num,DAT_00087ea4,0xd1a), in == (uchar *)0x0)) {
      *(undefined4 *)(param_1 + 0x34) = 5;
      return 0xffffffff;
    }
    EVP_CIPHER_CTX_init(&EStack_17c);
    HMAC_CTX_init(&HStack_f0);
    local_1ac = in;
    iVar2 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1ac);
    if ((iVar2 != 0) &&
       (local_1a8 = in, in_00 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1a8,num),
       in_00 != (SSL_SESSION *)0x0)) {
      in_00->session_id_length = 0;
      uVar6 = i2d_SSL_SESSION(in_00,(uchar **)0x0);
      uVar4 = 1 - uVar6;
      if (1 < uVar6) {
        uVar4 = 0;
      }
      if ((int)num < (int)uVar6) {
        uVar4 = uVar4 | 1;
      }
      if ((uVar4 == 0) && (local_1ac = in, iVar2 = i2d_SSL_SESSION(in_00,&local_1ac), iVar2 != 0)) {
        SSL_SESSION_free(in_00);
        iVar2 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),
                             *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c) + 0x86 + uVar6);
        if (iVar2 != 0) {
          local_1ac = (uchar *)(*(int *)(*(int *)(param_1 + 0x3c) + 4) +
                               *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c));
          if (*(code **)(iVar7 + 0x138) == (code *)0x0) {
            iVar2 = RAND_bytes(auStack_19c,0x10);
            if (0 < iVar2) {
              cipher = EVP_aes_128_cbc();
              iVar2 = EVP_EncryptInit_ex(&EStack_17c,cipher,(ENGINE *)0x0,(uchar *)(iVar7 + 0x128),
                                         auStack_19c);
              if (iVar2 != 0) {
                md = EVP_sha256();
                iVar2 = HMAC_Init_ex(&HStack_f0,(void *)(iVar7 + 0x118),0x10,md,(ENGINE *)0x0);
                if (iVar2 != 0) {
                  local_18c = *(undefined4 *)(iVar7 + 0x108);
                  uStack_188 = *(undefined4 *)(iVar7 + 0x10c);
                  uStack_184 = *(undefined4 *)(iVar7 + 0x110);
                  uStack_180 = *(undefined4 *)(iVar7 + 0x114);
                  goto LAB_00087cd2;
                }
              }
            }
          }
          else {
            iVar7 = (**(code **)(iVar7 + 0x138))
                              (param_1,&local_18c,auStack_19c,&EStack_17c,&HStack_f0,1);
            if (-1 < iVar7) {
LAB_00087cd2:
              uVar3 = '\0';
              if (*(int *)(param_1 + 0x6c) == 0) {
                uVar3 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xab);
              }
              *local_1ac = uVar3;
              uVar3 = '\0';
              if (*(int *)(param_1 + 0x6c) == 0) {
                uVar3 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xaa);
              }
              local_1ac[1] = uVar3;
              if (*(int *)(param_1 + 0x6c) == 0) {
                local_1ac[2] = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xa9);
                if (*(int *)(param_1 + 0x6c) == 0) goto LAB_00087d14;
LAB_00087e16:
                uVar3 = '\0';
              }
              else {
                local_1ac[2] = '\0';
                if (*(int *)(param_1 + 0x6c) != 0) goto LAB_00087e16;
LAB_00087d14:
                uVar3 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xa8);
              }
              local_1ac[3] = uVar3;
              puVar8 = local_1ac + 0x16;
              data = local_1ac + 6;
              *(undefined4 *)(local_1ac + 0x12) = uStack_180;
              *(undefined4 *)(local_1ac + 6) = local_18c;
              *(undefined4 *)(local_1ac + 10) = uStack_188;
              *(undefined4 *)(local_1ac + 0xe) = uStack_184;
              local_1ac = puVar8;
              __n = EVP_CIPHER_CTX_iv_length(&EStack_17c);
              memcpy(puVar8,auStack_19c,__n);
              puVar8 = local_1ac;
              iVar7 = EVP_CIPHER_CTX_iv_length(&EStack_17c);
              local_1ac = puVar8 + iVar7;
              iVar7 = EVP_EncryptUpdate(&EStack_17c,local_1ac,(int *)&local_1a4,in,uVar6);
              if (iVar7 != 0) {
                local_1ac = local_1ac + (int)local_1a4;
                iVar7 = EVP_EncryptFinal(&EStack_17c,local_1ac,(int *)&local_1a4);
                if (iVar7 != 0) {
                  local_1ac = local_1ac + (int)local_1a4;
                  iVar7 = HMAC_Update(&HStack_f0,data,(int)local_1ac - (int)data);
                  if ((iVar7 != 0) &&
                     (iVar7 = HMAC_Final(&HStack_f0,local_1ac,&local_1a0), iVar7 != 0)) {
                    EVP_CIPHER_CTX_cleanup(&EStack_17c);
                    HMAC_CTX_cleanup(&HStack_f0);
                    iVar5 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
                    iVar7 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c);
                    iVar2 = iVar7 + 4;
                    local_1a4 = local_1ac + (local_1a0 - (iVar5 + iVar7));
                    iVar7 = iVar5 + iVar2;
                    *(char *)(iVar5 + iVar2) = (char)((uint)(local_1a4 + -6) >> 8);
                    *(char *)(iVar7 + 1) = (char)local_1a4 + -6;
                    local_1ac = (uchar *)(iVar7 + 2);
                    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x40))(param_1,4,local_1a4)
                    ;
                    *(undefined4 *)(param_1 + 0x34) = 0x21f1;
                    CRYPTO_free(in);
                    goto LAB_00087bd2;
                  }
                }
              }
            }
          }
        }
      }
      else {
        SSL_SESSION_free(in_00);
      }
    }
    CRYPTO_free(in);
    EVP_CIPHER_CTX_cleanup(&EStack_17c);
    HMAC_CTX_cleanup(&HStack_f0);
    uVar1 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
  else {
LAB_00087bd2:
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
  }
  return uVar1;
}

