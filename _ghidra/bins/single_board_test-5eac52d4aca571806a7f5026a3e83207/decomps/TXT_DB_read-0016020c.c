
TXT_DB * TXT_DB_read(BIO *in,int num)

{
  char cVar1;
  bool bVar2;
  BUF_MEM *str;
  int iVar3;
  TXT_DB *ptr;
  stack_st_OPENSSL_PSTRING *psVar4;
  lhash_st_OPENSSL_STRING **pplVar5;
  _func_4786 **pp_Var6;
  int iVar7;
  char *pcVar8;
  size_t sVar9;
  undefined4 *ptr_00;
  char *pcVar10;
  int iVar11;
  size_t len;
  char *pcVar12;
  
  str = BUF_MEM_new();
  if (((str == (BUF_MEM *)0x0) || (iVar3 = BUF_MEM_grow(str,0x200), iVar3 == 0)) ||
     (ptr = (TXT_DB *)CRYPTO_malloc(0x20,"crypto/txt_db/txt_db.c",0x25), ptr == (TXT_DB *)0x0)) {
    BUF_MEM_free(str);
    return (TXT_DB *)0x0;
  }
  ptr->num_fields = num;
  ptr->index = (lhash_st_OPENSSL_STRING **)0x0;
  ptr->qual = (_func_4786 **)0x0;
  psVar4 = (stack_st_OPENSSL_PSTRING *)OPENSSL_sk_new_null();
  ptr->data = psVar4;
  if (psVar4 != (stack_st_OPENSSL_PSTRING *)0x0) {
    iVar3 = num * 4;
    pplVar5 = (lhash_st_OPENSSL_STRING **)CRYPTO_malloc(iVar3,"crypto/txt_db/txt_db.c",0x2c);
    ptr->index = pplVar5;
    if (pplVar5 != (lhash_st_OPENSSL_STRING **)0x0) {
      pp_Var6 = (_func_4786 **)CRYPTO_malloc(iVar3,"crypto/txt_db/txt_db.c",0x2e);
      ptr->qual = pp_Var6;
      if (pp_Var6 != (_func_4786 **)0x0) {
        if (0 < num) {
          iVar11 = 0;
          do {
            ptr->index[iVar11] = (lhash_st_OPENSSL_STRING *)0x0;
            ptr->qual[iVar11] = (_func_4786 *)0x0;
            iVar11 = iVar11 + 1;
          } while (num != iVar11);
        }
        str->data[0x1ff] = '\0';
        len = 0x200;
        iVar11 = 0;
        while( true ) {
          if (iVar11 == 0) goto LAB_00160386;
          len = len + 0x200;
          iVar7 = BUF_MEM_grow_clean(str,len);
          if (iVar7 == 0) break;
          str->data[iVar11] = '\0';
          BIO_gets(in,str->data + iVar11,len - iVar11);
          pcVar12 = str->data;
          pcVar8 = pcVar12 + iVar11;
          if (pcVar12[iVar11] == '\0') {
LAB_00160412:
            BUF_MEM_free(str);
            return ptr;
          }
          while( true ) {
            sVar9 = strlen(pcVar8);
            iVar11 = iVar11 + sVar9;
            if (pcVar12[iVar11 + -1] != '\n') break;
            pcVar12[iVar11 + -1] = '\0';
            ptr_00 = (undefined4 *)CRYPTO_malloc(iVar3 + 4 + iVar11,"crypto/txt_db/txt_db.c",0x4b);
            if (ptr_00 == (undefined4 *)0x0) goto LAB_001603b8;
            iVar11 = 1;
            bVar2 = false;
            *ptr_00 = ptr_00 + num + 1;
            pcVar12 = str->data;
            pcVar8 = (char *)(ptr_00 + num + 1);
            while( true ) {
              pcVar10 = pcVar12 + 1;
              cVar1 = *pcVar12;
              if (cVar1 == '\0') break;
              pcVar12 = pcVar10;
              if (cVar1 == '\t') {
                pcVar10 = pcVar8 + 1;
                if (bVar2) {
                  pcVar8 = pcVar8 + -1;
                  goto LAB_00160338;
                }
                *pcVar8 = '\0';
                pcVar8 = pcVar10;
                if (num <= iVar11) break;
                ptr_00[iVar11] = pcVar10;
                iVar11 = iVar11 + 1;
              }
              else {
LAB_00160338:
                *pcVar8 = cVar1;
                bVar2 = cVar1 == '\\';
                pcVar8 = pcVar8 + 1;
              }
            }
            *pcVar8 = '\0';
            if ((iVar11 != num) || (*pcVar12 != '\0')) {
              CRYPTO_free(ptr_00);
              ptr->error = 6;
              goto LAB_001603b8;
            }
            ptr_00[iVar11] = pcVar8 + 1;
            iVar7 = OPENSSL_sk_push(ptr->data,ptr_00);
            iVar11 = 0;
            if (iVar7 == 0) {
              CRYPTO_free(ptr_00);
              goto LAB_001603b8;
            }
LAB_00160386:
            do {
              *str->data = (char)iVar11;
              BIO_gets(in,str->data,len);
              pcVar8 = str->data;
              if (*pcVar8 == '\0') goto LAB_00160412;
              pcVar12 = pcVar8;
            } while (*pcVar8 == '#');
          }
        }
      }
    }
  }
LAB_001603b8:
  BUF_MEM_free(str);
  OPENSSL_sk_free(ptr->data);
  CRYPTO_free(ptr->index);
  CRYPTO_free(ptr->qual);
  CRYPTO_free(ptr);
  return (TXT_DB *)0x0;
}

