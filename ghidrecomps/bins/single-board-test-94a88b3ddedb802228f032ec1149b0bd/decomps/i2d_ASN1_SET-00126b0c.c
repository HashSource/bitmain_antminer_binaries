
int i2d_ASN1_SET(stack_st_OPENSSL_BLOCK *a,uchar **pp,undefined1 *i2d,int ex_tag,int ex_class,
                int is_set)

{
  uchar *__dest;
  int iVar1;
  void *pvVar2;
  int iVar3;
  uchar **__base;
  size_t __nmemb;
  uchar *__src;
  int iVar4;
  uchar **ppuVar5;
  size_t __n;
  uchar *local_2c [2];
  
  if (a == (stack_st_OPENSSL_BLOCK *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = sk_num(&a->stack);
    iVar1 = iVar1 + -1;
    iVar4 = 0;
    if (-1 < iVar1) {
      do {
        pvVar2 = sk_value(&a->stack,iVar1);
        iVar1 = iVar1 + -1;
        iVar3 = (*(code *)i2d)(pvVar2,0);
        iVar4 = iVar4 + iVar3;
      } while (iVar1 != -1);
    }
    iVar1 = ASN1_object_size(1,iVar4,ex_tag);
    if (pp != (uchar **)0x0) {
      local_2c[0] = *pp;
      ASN1_put_object(local_2c,1,iVar4,ex_tag,ex_class);
      if ((is_set == 0) || (iVar4 = sk_num(&a->stack), __dest = local_2c[0], iVar4 < 2)) {
        iVar4 = 0;
        while( true ) {
          iVar3 = sk_num(&a->stack);
          if (iVar3 <= iVar4) break;
          pvVar2 = sk_value(&a->stack,iVar4);
          (*(code *)i2d)(pvVar2,local_2c);
          iVar4 = iVar4 + 1;
        }
        *pp = local_2c[0];
      }
      else {
        iVar4 = sk_num(&a->stack);
        __base = (uchar **)CRYPTO_malloc(iVar4 << 3,DAT_00126ca8,0x7c);
        if (__base == (uchar **)0x0) {
          ERR_put_error(0xd,0xbc,0x41,DAT_00126ca8,0x7e);
          iVar1 = 0;
        }
        else {
          ppuVar5 = __base;
          iVar4 = 0;
          while( true ) {
            iVar3 = sk_num(&a->stack);
            HintPreloadData(ppuVar5 + 8);
            if (iVar3 <= iVar4) break;
            *ppuVar5 = local_2c[0];
            pvVar2 = sk_value(&a->stack,iVar4);
            (*(code *)i2d)(pvVar2,local_2c);
            ppuVar5[1] = local_2c[0] + -(int)*ppuVar5;
            ppuVar5 = ppuVar5 + 2;
            iVar4 = iVar4 + 1;
          }
          *pp = local_2c[0];
          __n = (int)local_2c[0] - (int)__dest;
          __nmemb = sk_num(&a->stack);
          qsort(__base,__nmemb,8,DAT_00126cac);
          __src = (uchar *)CRYPTO_malloc(__n,DAT_00126ca8,0x90);
          if (__src == (uchar *)0x0) {
            ERR_put_error(0xd,0xbc,0x41,DAT_00126ca8,0x91);
            iVar1 = 0;
          }
          else {
            iVar4 = 0;
            ppuVar5 = __base;
            local_2c[0] = __src;
            while( true ) {
              iVar3 = sk_num(&a->stack);
              HintPreloadData(ppuVar5 + 0xd);
              if (iVar3 <= iVar4) break;
              memcpy(local_2c[0],*ppuVar5,(size_t)ppuVar5[1]);
              local_2c[0] = local_2c[0] + (int)ppuVar5[1];
              iVar4 = iVar4 + 1;
              ppuVar5 = ppuVar5 + 2;
            }
            memcpy(__dest,__src,__n);
            CRYPTO_free(__src);
            CRYPTO_free(__base);
          }
        }
      }
    }
  }
  return iVar1;
}

