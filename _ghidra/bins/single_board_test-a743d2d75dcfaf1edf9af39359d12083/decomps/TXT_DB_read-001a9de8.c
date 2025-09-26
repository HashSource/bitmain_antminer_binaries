
TXT_DB * TXT_DB_read(BIO *in,int num)

{
  char cVar1;
  BUF_MEM *str;
  int iVar2;
  _STACK *p_Var3;
  lhash_st_OPENSSL_STRING **pplVar4;
  _func_4786 **pp_Var5;
  size_t sVar6;
  int iVar7;
  undefined4 *data;
  char *pcVar8;
  TXT_DB *ptr;
  TXT_DB *pTVar9;
  char *pcVar10;
  int iVar11;
  size_t len;
  char *pcVar12;
  char *pcVar13;
  bool bVar14;
  
  str = BUF_MEM_new();
  if (((str == (BUF_MEM *)0x0) || (iVar2 = BUF_MEM_grow(str,0x200), iVar2 == 0)) ||
     (ptr = (TXT_DB *)CRYPTO_malloc(0x20,"txt_db.c",0x59), ptr == (TXT_DB *)0x0)) {
    ptr = (TXT_DB *)0x0;
  }
  else {
    ptr->num_fields = num;
    ptr->index = (lhash_st_OPENSSL_STRING **)0x0;
    ptr->qual = (_func_4786 **)0x0;
    p_Var3 = sk_new_null();
    ptr->data = (stack_st_OPENSSL_PSTRING *)p_Var3;
    if (p_Var3 != (_STACK *)0x0) {
      pplVar4 = (lhash_st_OPENSSL_STRING **)CRYPTO_malloc(num * 4,"txt_db.c",0x60);
      ptr->index = pplVar4;
      if (pplVar4 != (lhash_st_OPENSSL_STRING **)0x0) {
        pp_Var5 = (_func_4786 **)CRYPTO_malloc(num * 4,"txt_db.c",0x62);
        ptr->qual = pp_Var5;
        if (pp_Var5 != (_func_4786 **)0x0) {
          if (0 < num) {
            iVar2 = 0;
            do {
              ptr->index[iVar2] = (lhash_st_OPENSSL_STRING *)0x0;
              ptr->qual[iVar2] = (_func_4786 *)0x0;
              iVar2 = iVar2 + 1;
            } while (iVar2 != num);
          }
          iVar2 = 0;
          str->data[0x1ff] = '\0';
          iVar11 = 1;
          len = 0x200;
LAB_001a9eca:
          *str->data = (char)iVar2;
          BIO_gets(in,str->data,len);
          pcVar12 = str->data;
          if (*pcVar12 == '\0') {
LAB_001a9f34:
            BUF_MEM_free(str);
            return ptr;
          }
          pcVar13 = pcVar12;
          if (*pcVar12 == '#') goto LAB_001a9ef8;
          do {
            sVar6 = strlen(pcVar12);
            iVar2 = iVar2 + sVar6;
            if (pcVar13[iVar2 + -1] == '\n') {
              pcVar13[iVar2 + -1] = '\0';
              data = (undefined4 *)CRYPTO_malloc((num + 1) * 4 + iVar2,"txt_db.c",0x7f);
              if (data == (undefined4 *)0x0) break;
              iVar2 = 1;
              *data = data + num + 1;
              bVar14 = false;
              pcVar12 = str->data;
              pcVar13 = (char *)(data + num + 1);
              while( true ) {
                pcVar8 = pcVar12 + 1;
                cVar1 = *pcVar12;
                pcVar10 = pcVar13;
                if (cVar1 == '\0') break;
                pcVar12 = pcVar8;
                if (cVar1 == '\t') {
                  if (bVar14) {
                    pcVar13 = pcVar13 + -1;
                    goto LAB_001a9f62;
                  }
                  pcVar10 = pcVar13 + 1;
                  *pcVar13 = '\0';
                  if (num <= iVar2) break;
                  data[iVar2] = pcVar10;
                  iVar2 = iVar2 + 1;
                  pcVar13 = pcVar10;
                }
                else {
LAB_001a9f62:
                  *pcVar13 = cVar1;
                  bVar14 = cVar1 == '\\';
                  pcVar13 = pcVar13 + 1;
                }
              }
              *pcVar10 = '\0';
              if ((iVar2 == num) && (*pcVar12 == '\0')) {
                data[num] = pcVar10 + 1;
                iVar7 = sk_push(&ptr->data->stack,data);
                iVar2 = 0;
                if (iVar7 != 0) goto LAB_001a9ef8;
                fwrite("failure in sk_push\n",1,0x13,stderr);
              }
              else {
                fprintf(stderr,
                        "wrong number of fields on line %ld (looking for field %d, got %d, \'%s\' left)\n"
                        ,iVar11,num,iVar2,pcVar12);
              }
              BUF_MEM_free(str);
              goto LAB_001a9e1c;
            }
LAB_001a9ef8:
            iVar11 = iVar11 + 1;
            if (iVar2 == 0) goto LAB_001a9eca;
            len = len + 0x200;
            iVar7 = BUF_MEM_grow_clean(str,len);
            if (iVar7 == 0) break;
            str->data[iVar2] = '\0';
            BIO_gets(in,str->data + iVar2,len - iVar2);
            pcVar13 = str->data;
            pcVar12 = pcVar13 + iVar2;
            if (pcVar13[iVar2] == '\0') goto LAB_001a9f34;
          } while( true );
        }
      }
    }
  }
  BUF_MEM_free(str);
  fwrite("OPENSSL_malloc failure\n",1,0x17,stderr);
  pTVar9 = ptr;
  if (ptr != (TXT_DB *)0x0) {
LAB_001a9e1c:
    if (&ptr->data->stack != (_STACK *)0x0) {
      sk_free(&ptr->data->stack);
    }
    if (ptr->index != (lhash_st_OPENSSL_STRING **)0x0) {
      CRYPTO_free(ptr->index);
    }
    if (ptr->qual != (_func_4786 **)0x0) {
      CRYPTO_free(ptr->qual);
    }
    pTVar9 = (TXT_DB *)0x0;
    CRYPTO_free(ptr);
  }
  return pTVar9;
}

