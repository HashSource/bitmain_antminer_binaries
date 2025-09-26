
int PEM_read_bio(BIO *bp,char **name,char **header,uchar **data,long *len)

{
  BUF_MEM *pBVar1;
  BUF_MEM *a;
  BUF_MEM *a_00;
  int iVar2;
  size_t sVar3;
  char *__s;
  int iVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  BUF_MEM *local_1a4;
  int local_190;
  int local_18c;
  EVP_ENCODE_CTX EStack_188;
  byte local_128 [9];
  byte abStack_11f [245];
  undefined1 local_2a;
  
  local_18c = 0;
  a = BUF_MEM_new();
  a_00 = BUF_MEM_new();
  local_1a4 = BUF_MEM_new();
  if ((a == (BUF_MEM *)0x0 || a_00 == (BUF_MEM *)0x0) || (local_1a4 == (BUF_MEM *)0x0)) {
    BUF_MEM_free(a);
    BUF_MEM_free(a_00);
    BUF_MEM_free(local_1a4);
    ERR_put_error(9,0x6d,0x41,"pem_lib.c",0x2b4);
    return 0;
  }
  local_2a = 0;
  do {
    do {
      iVar2 = BIO_gets(bp,(char *)local_128,0xfe);
      if (iVar2 < 1) {
        ERR_put_error(9,0x6d,0x6c,"pem_lib.c",0x2bd);
        goto LAB_0015f9e8;
      }
      do {
        if (0x20 < local_128[iVar2]) break;
        bVar6 = iVar2 != 0;
        iVar2 = iVar2 + -1;
      } while (bVar6);
      local_128[iVar2 + 1] = 10;
      local_128[iVar2 + 2] = 0;
      iVar2 = strncmp((char *)local_128,"-----BEGIN ",0xb);
    } while (iVar2 != 0);
    sVar3 = strlen((char *)(abStack_11f + 2));
    iVar2 = strncmp((char *)(local_128 + sVar3 + 5),"-----\n",6);
  } while (iVar2 != 0);
  iVar2 = BUF_MEM_grow(a,sVar3 + 9);
  if (iVar2 == 0) {
    iVar2 = 0x2cc;
  }
  else {
    memcpy(a->data,abStack_11f + 2,sVar3 - 6);
    a->data[sVar3 - 6] = '\0';
    iVar2 = BUF_MEM_grow(a_00,0x100);
    if (iVar2 == 0) {
      iVar2 = 0x2d6;
    }
    else {
      *a_00->data = '\0';
      iVar5 = 0;
      while (iVar2 = BIO_gets(bp,(char *)local_128,0xfe), 0 < iVar2) {
        do {
          if (0x20 < local_128[iVar2]) break;
          bVar6 = iVar2 != 0;
          iVar2 = iVar2 + -1;
        } while (bVar6);
        sVar3 = iVar2 + 2;
        local_128[iVar2 + 1] = 10;
        local_128[sVar3] = 0;
        if (local_128[0] == 10) break;
        iVar4 = iVar5 + sVar3;
        iVar2 = BUF_MEM_grow(a_00,iVar4 + 9);
        if (iVar2 == 0) {
          iVar2 = 0x2e7;
          goto LAB_0015f9da;
        }
        iVar2 = strncmp((char *)local_128,"-----END ",9);
        if (iVar2 == 0) {
          bVar6 = true;
          goto LAB_0015fae4;
        }
        memcpy(a_00->data + iVar5,local_128,sVar3);
        a_00->data[iVar4] = '\0';
        iVar5 = iVar4;
      }
      bVar6 = false;
LAB_0015fae4:
      local_18c = 0;
      iVar4 = BUF_MEM_grow(local_1a4,0x400);
      iVar2 = 0x2f5;
      if (iVar4 != 0) {
        *local_1a4->data = '\0';
        if (bVar6) {
          local_18c = iVar5;
          iVar2 = strncmp((char *)local_128,"-----END ",9);
          pBVar1 = local_1a4;
          local_1a4 = a_00;
        }
        else {
          do {
            iVar2 = BIO_gets(bp,(char *)local_128,0xfe);
            pBVar1 = a_00;
            if (iVar2 < 1) goto LAB_0015fce8;
            do {
              if (0x20 < local_128[iVar2]) {
                sVar3 = iVar2 + 2;
                local_128[iVar2 + 1] = 10;
                local_128[sVar3] = bVar6;
                if (sVar3 == 0x41) {
                  iVar2 = strncmp((char *)local_128,"-----END ",9);
                  if (iVar2 == 0) goto LAB_0015fcfe;
                  bVar7 = false;
                }
                else {
                  iVar2 = strncmp((char *)local_128,"-----END ",9);
                  if (iVar2 == 0) goto LAB_0015fcfe;
                  if (0x41 < (int)sVar3) goto LAB_0015fcc8;
                  bVar7 = true;
                }
                goto LAB_0015fb4a;
              }
              bVar7 = iVar2 != 0;
              iVar2 = iVar2 + -1;
            } while (bVar7);
            local_128[0] = 10;
            local_128[1] = bVar6;
            iVar2 = strncmp((char *)local_128,"-----END ",9);
            if (iVar2 == 0) {
LAB_0015fcfe:
              __s = a->data;
              sVar3 = strlen(__s);
              goto LAB_0015fc30;
            }
            sVar3 = 1;
            bVar7 = true;
LAB_0015fb4a:
            iVar2 = BUF_MEM_grow_clean(local_1a4,sVar3 + local_18c + 9);
            if (iVar2 == 0) {
              iVar2 = 0x30b;
              goto LAB_0015f9da;
            }
            memcpy(local_1a4->data + local_18c,local_128,sVar3);
            local_1a4->data[sVar3 + local_18c] = bVar6;
            local_18c = local_18c + sVar3;
          } while (!bVar7);
          local_128[0] = 0;
          iVar2 = BIO_gets(bp,(char *)local_128,0xfe);
          if (iVar2 < 1) {
LAB_0015fce8:
            iVar2 = strncmp((char *)local_128,"-----END ",9);
          }
          else {
            do {
              if (0x20 < local_128[iVar2]) break;
              bVar6 = iVar2 != 0;
              iVar2 = iVar2 + -1;
            } while (bVar6);
            local_128[iVar2 + 1] = 10;
            local_128[iVar2 + 2] = 0;
            iVar2 = strncmp((char *)local_128,"-----END ",9);
          }
        }
        a_00 = pBVar1;
        __s = a->data;
        sVar3 = strlen(__s);
        if (iVar2 == 0) {
LAB_0015fc30:
          iVar2 = strncmp(__s,(char *)abStack_11f,sVar3);
          if ((iVar2 == 0) &&
             (iVar2 = strncmp((char *)(local_128 + sVar3 + 9),"-----\n",6), iVar2 == 0)) {
            EVP_DecodeInit(&EStack_188);
            iVar2 = EVP_DecodeUpdate(&EStack_188,(uchar *)local_1a4->data,&local_18c,
                                     (uchar *)local_1a4->data,local_18c);
            if (iVar2 < 0) {
              iVar2 = 0x332;
            }
            else {
              iVar2 = EVP_DecodeFinal(&EStack_188,(uchar *)(local_1a4->data + local_18c),&local_190)
              ;
              if (-1 < iVar2) {
                local_18c = local_18c + local_190;
                if (local_18c != 0) {
                  *name = a->data;
                  *header = a_00->data;
                  *data = (uchar *)local_1a4->data;
                  *len = local_18c;
                  CRYPTO_free(a);
                  CRYPTO_free(a_00);
                  CRYPTO_free(local_1a4);
                  return 1;
                }
                goto LAB_0015f9e8;
              }
              iVar2 = 0x337;
            }
            ERR_put_error(9,0x6d,100,"pem_lib.c",iVar2);
            goto LAB_0015f9e8;
          }
        }
LAB_0015fcc8:
        ERR_put_error(9,0x6d,0x66,"pem_lib.c",0x329);
        goto LAB_0015f9e8;
      }
    }
  }
LAB_0015f9da:
  ERR_put_error(9,0x6d,0x41,"pem_lib.c",iVar2);
LAB_0015f9e8:
  BUF_MEM_free(a);
  BUF_MEM_free(a_00);
  BUF_MEM_free(local_1a4);
  return 0;
}

