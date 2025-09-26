
undefined4 tls_construct_cke_gost(int param_1,undefined4 param_2)

{
  EVP_PKEY *pkey;
  EVP_PKEY_CTX *ctx;
  uchar *buf;
  EVP_MD_CTX *ctx_00;
  char *name;
  EVP_MD *type;
  undefined4 uVar1;
  int iVar2;
  int n;
  undefined8 uVar3;
  undefined4 uVar4;
  size_t local_148;
  uint uStack_144;
  uchar auStack_140 [32];
  uchar auStack_120 [256];
  
  n = 0x329;
  iVar2 = *(int *)(*(int *)(param_1 + 0x474) + 0x19c);
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x14) & 0x80) != 0) {
    n = 0x3d6;
  }
  if (iVar2 == 0) {
    ossl_statem_fatal(param_1,0x28,0x196,0x14a,"ssl/statem/statem_clnt.c",0xc7f);
    return 0;
  }
  pkey = (EVP_PKEY *)X509_get0_pubkey(iVar2);
  ctx = EVP_PKEY_CTX_new(pkey,(ENGINE *)0x0);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x196,0x41,"ssl/statem/statem_clnt.c",0xc86);
    return 0;
  }
  buf = (uchar *)CRYPTO_malloc(0x20,"ssl/statem/statem_clnt.c",0xc91);
  if (buf == (uchar *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x196,0x41,"ssl/statem/statem_clnt.c",0xc94);
    ctx_00 = (EVP_MD_CTX *)0x0;
    goto LAB_000f839c;
  }
  iVar2 = EVP_PKEY_encrypt_init(ctx);
  if ((iVar2 < 1) || (iVar2 = RAND_bytes(buf,0x20), iVar2 < 1)) {
    uVar4 = 0xc9e;
LAB_000f8386:
    uVar1 = 0x44;
LAB_000f838c:
    ctx_00 = (EVP_MD_CTX *)0x0;
    ossl_statem_fatal(param_1,0x50,0x196,uVar1,"ssl/statem/statem_clnt.c",uVar4);
  }
  else {
    ctx_00 = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if (ctx_00 != (EVP_MD_CTX *)0x0) {
      name = OBJ_nid2sn(n);
      type = EVP_get_digestbyname(name);
      iVar2 = EVP_DigestInit(ctx_00,type);
      if (((0 < iVar2) &&
          (iVar2 = EVP_DigestUpdate(ctx_00,(void *)(*(int *)(param_1 + 0x7c) + 0xac),0x20),
          0 < iVar2)) &&
         (iVar2 = EVP_DigestUpdate(ctx_00,(void *)(*(int *)(param_1 + 0x7c) + 0x8c),0x20), 0 < iVar2
         )) {
        iVar2 = EVP_DigestFinal_ex(ctx_00,auStack_140,&uStack_144);
        if (0 < iVar2) {
          EVP_MD_CTX_free(ctx_00);
          iVar2 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,8,8,auStack_140);
          if (iVar2 < 0) {
            uVar4 = 0xcb6;
            uVar1 = 0x112;
          }
          else {
            local_148 = 0xff;
            iVar2 = EVP_PKEY_encrypt(ctx,auStack_120,&local_148,buf,0x20);
            if (0 < iVar2) {
              uVar4 = 1;
              uVar3 = WPACKET_put_bytes__(param_2);
              if ((int)uVar3 != 0) {
                if (0x7f < local_148) {
                  uVar4 = 1;
                  iVar2 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),0x81,0,1);
                  if (iVar2 == 0) goto LAB_000f8374;
                }
                iVar2 = WPACKET_sub_memcpy__(param_2,auStack_120,local_148,1,uVar4);
                if (iVar2 != 0) {
                  EVP_PKEY_CTX_free(ctx);
                  iVar2 = *(int *)(param_1 + 0x7c);
                  *(uchar **)(iVar2 + 0x250) = buf;
                  *(undefined4 *)(iVar2 + 0x254) = 0x20;
                  return 1;
                }
              }
LAB_000f8374:
              uVar4 = 0xcc8;
              goto LAB_000f8386;
            }
            uVar4 = 0xcc0;
            uVar1 = 0x112;
          }
          goto LAB_000f838c;
        }
      }
    }
    ossl_statem_fatal(param_1,0x50,0x196,0x44,"ssl/statem/statem_clnt.c",0xcae);
  }
LAB_000f839c:
  EVP_PKEY_CTX_free(ctx);
  CRYPTO_clear_free(buf,0x20,"ssl/statem/statem_clnt.c",0xcd3);
  EVP_MD_CTX_free(ctx_00);
  return 0;
}

