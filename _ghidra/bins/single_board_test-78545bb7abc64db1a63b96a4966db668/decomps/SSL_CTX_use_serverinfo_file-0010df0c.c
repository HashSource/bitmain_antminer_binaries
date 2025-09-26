
char * SSL_CTX_use_serverinfo_file(int param_1,void *param_2)

{
  BIO_METHOD *type;
  long lVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  char *num;
  char *pcVar6;
  char *pcVar7;
  BIO *bp;
  bool bVar8;
  bool bVar9;
  uchar *local_5c;
  size_t local_58;
  char *local_54;
  char *local_50;
  char local_4c [32];
  undefined2 local_2c;
  
  bp = (BIO *)0x0;
  bVar8 = param_2 == (void *)0x0;
  bVar9 = param_1 == 0;
  local_5c = (uchar *)0x0;
  local_58 = 0;
  builtin_strncpy(local_4c,"SERVERINFO FOR ",0x10);
  pcVar7 = local_4c;
  if (bVar8 || bVar9) {
    pcVar7 = (char *)0x1;
  }
  local_54 = (char *)0x0;
  if (!bVar8 && !bVar9) {
    pcVar7 = (char *)0x0;
  }
  local_50 = (char *)0x0;
  builtin_strncpy(local_4c + 0x10,"SERVERINFOV2 FOR",0x10);
  local_2c = 0x20;
  if (bVar8 || bVar9) {
    pcVar7 = (char *)0x0;
    pcVar5 = (char *)0x0;
    ERR_put_error(0x14,0x151,0x43,"ssl/ssl_rsa.c",0x3bd);
  }
  else {
    type = BIO_s_file();
    bp = BIO_new(type);
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x14,0x151,7,"ssl/ssl_rsa.c",0x3c3);
      pcVar7 = (char *)0x0;
      pcVar5 = (char *)0x0;
    }
    else {
      lVar1 = BIO_ctrl(bp,0x6c,3,param_2);
      pcVar5 = pcVar7;
      if (lVar1 < 1) {
        ERR_put_error(0x14,0x151,2,"ssl/ssl_rsa.c",0x3c7);
      }
      else {
        pcVar6 = pcVar7;
        while (iVar2 = PEM_read_bio(bp,&local_54,&local_50,&local_5c,(long *)&local_58),
              pcVar4 = local_54, iVar2 != 0) {
          sVar3 = strlen(local_54);
          if (sVar3 < 0xf) {
            iVar2 = 0x3dd;
LAB_0010e146:
            ERR_put_error(0x14,0x151,0x188,"ssl/ssl_rsa.c",iVar2);
            pcVar7 = (char *)0x0;
            goto LAB_0010e0cc;
          }
          iVar2 = strncmp(pcVar4,local_4c,0xf);
          if (iVar2 == 0) {
            if (((int)local_58 < 4) ||
               ((uint)local_5c[3] + (uint)local_5c[2] * 0x100 != local_58 - 4)) {
              iVar2 = 0x3f7;
LAB_0010e116:
              ERR_put_error(0x14,0x151,0x186,"ssl/ssl_rsa.c",iVar2);
              pcVar7 = (char *)0x0;
              goto LAB_0010e0cc;
            }
            num = pcVar6 + local_58 + 4;
            pcVar4 = (char *)CRYPTO_realloc(pcVar5,(int)num,"ssl/ssl_rsa.c",0x405);
            if (pcVar4 == (char *)0x0) {
LAB_0010e15a:
              pcVar7 = (char *)0x0;
              ERR_put_error(0x14,0x151,0x41,"ssl/ssl_rsa.c",0x407);
              goto LAB_0010e0cc;
            }
            pcVar5 = pcVar4 + (int)pcVar6;
            pcVar4[(int)pcVar6] = '\0';
            pcVar5[1] = '\0';
            pcVar5[3] = -0x30;
            pcVar5[2] = '\x01';
            iVar2 = 4;
          }
          else {
            if (sVar3 < 0x11) {
              iVar2 = 0x3e5;
              goto LAB_0010e146;
            }
            iVar2 = strncmp(pcVar4,local_4c + 0x10,0x11);
            if (iVar2 != 0) {
              pcVar7 = (char *)0x0;
              ERR_put_error(0x14,0x151,0x187,"ssl/ssl_rsa.c",0x3ea);
              goto LAB_0010e0cc;
            }
            if (((int)local_58 < 8) ||
               ((uint)local_5c[7] + (uint)local_5c[6] * 0x100 != local_58 - 8)) {
              iVar2 = 0x3ff;
              goto LAB_0010e116;
            }
            num = pcVar6 + local_58;
            pcVar4 = (char *)CRYPTO_realloc(pcVar5,(int)num,"ssl/ssl_rsa.c",0x405);
            if (pcVar4 == (char *)0x0) goto LAB_0010e15a;
            pcVar5 = pcVar4 + (int)pcVar6;
            iVar2 = 0;
          }
          memcpy(pcVar5 + iVar2,local_5c,local_58);
          pcVar7 = pcVar7 + 1;
          CRYPTO_free(local_54);
          local_54 = (char *)0x0;
          CRYPTO_free(local_50);
          local_50 = (char *)0x0;
          CRYPTO_free(local_5c);
          local_5c = (uchar *)0x0;
          pcVar6 = num;
          pcVar5 = pcVar4;
        }
        if (pcVar7 == (char *)0x0) {
          ERR_put_error(0x14,0x151,0x185,"ssl/ssl_rsa.c",0x3d6);
          pcVar7 = (char *)0x0;
        }
        else {
          pcVar7 = (char *)SSL_CTX_use_serverinfo_ex(param_1,2,pcVar5,pcVar6);
        }
      }
    }
  }
LAB_0010e0cc:
  CRYPTO_free(local_54);
  CRYPTO_free(local_50);
  CRYPTO_free(local_5c);
  CRYPTO_free(pcVar5);
  BIO_free(bp);
  return pcVar7;
}

