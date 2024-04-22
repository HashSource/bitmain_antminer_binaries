
void * SSL_CTX_use_serverinfo_file(int param_1,void *param_2)

{
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  size_t sVar2;
  size_t __n;
  char *pcVar3;
  int iVar4;
  void *pvVar5;
  void *addr;
  void *pvVar6;
  uchar *local_48;
  size_t local_44;
  char *local_40;
  char *local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  local_38 = *DAT_00082534;
  uStack_34 = DAT_00082534[1];
  uStack_30 = DAT_00082534[2];
  uStack_2c = DAT_00082534[3];
  local_48 = (uchar *)0x0;
  local_44 = 0;
  local_40 = (char *)0x0;
  local_3c = (char *)0x0;
  if (param_1 == 0 || param_2 == (void *)0x0) {
    ERR_put_error(0x14,0x151,0x43,DAT_00082538,0x3a4);
  }
  else {
    addr = (void *)0x0;
    type = BIO_s_file();
    bp = BIO_new(type);
    if (bp != (BIO *)0x0) {
      lVar1 = BIO_ctrl(bp,0x6c,3,param_2);
      if (lVar1 < 1) {
        ERR_put_error(0x14,0x151,2,DAT_00082538,0x3ae);
        pvVar5 = addr;
      }
      else {
        pvVar5 = addr;
        pvVar6 = addr;
        while (iVar4 = PEM_read_bio(bp,&local_40,&local_3c,&local_48,(long *)&local_44),
              pcVar3 = local_40, iVar4 != 0) {
          pvVar5 = (void *)((int)pvVar5 + 1);
          sVar2 = strlen(local_40);
          __n = strlen((char *)&local_38);
          if (sVar2 < __n) {
            ERR_put_error(0x14,0x151,0x188,DAT_00082538,0x3c2);
            pvVar5 = (void *)0x0;
            goto LAB_0008249e;
          }
          pcVar3 = (char *)strncmp(pcVar3,(char *)&local_38,__n);
          if (pcVar3 != (char *)0x0) {
            ERR_put_error(0x14,0x151,0x187,DAT_00082538,0x3c7);
            pvVar5 = (void *)0x0;
            goto LAB_0008249e;
          }
          if (((int)local_44 < 4) || ((uint)local_48[3] + (uint)local_48[2] * 0x100 != local_44 - 4)
             ) {
            ERR_put_error(0x14,0x151,0x186,DAT_00082538,0x3cf);
            pvVar5 = (void *)0x0;
            goto LAB_0008249e;
          }
          addr = CRYPTO_realloc(addr,local_44 + (int)pvVar6,DAT_00082538,0x3d4);
          if (addr == (void *)0x0) {
            ERR_put_error(0x14,0x151,0x41,DAT_00082538,0x3d6);
            pvVar5 = (void *)0x0;
            goto LAB_0008249e;
          }
          memcpy((void *)((int)addr + (int)pvVar6),local_48,local_44);
          pvVar6 = (void *)((int)pvVar6 + local_44);
          CRYPTO_free(local_40);
          local_40 = pcVar3;
          CRYPTO_free(local_3c);
          local_3c = pcVar3;
          CRYPTO_free(local_48);
          local_48 = (uchar *)0x0;
        }
        if (pvVar5 == (void *)0x0) {
          ERR_put_error(0x14,0x151,0x185,DAT_00082538,0x3ba);
          pvVar5 = (void *)0x0;
        }
        else {
          pvVar5 = (void *)SSL_CTX_use_serverinfo(param_1,addr,pvVar6);
        }
      }
LAB_0008249e:
      CRYPTO_free(local_40);
      CRYPTO_free(local_3c);
      CRYPTO_free(local_48);
      CRYPTO_free(addr);
      BIO_free(bp);
      return pvVar5;
    }
    ERR_put_error(0x14,0x151,7,DAT_00082538,0x3aa);
  }
  CRYPTO_free(local_40);
  CRYPTO_free(local_3c);
  CRYPTO_free(local_48);
  CRYPTO_free((void *)0x0);
  return (void *)0x0;
}

