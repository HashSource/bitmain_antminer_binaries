
size_t x509_name_ex_i2d(undefined4 *param_1,int *param_2)

{
  void *data;
  int iVar1;
  int iVar2;
  size_t sVar3;
  _STACK *st;
  int iVar4;
  _STACK *local_28;
  uchar *local_24 [2];
  
  param_1 = (undefined4 *)*param_1;
  if (param_1[1] == 0) {
LAB_000b77ce:
    sVar3 = *(size_t *)param_1[2];
    if (param_2 != (int *)0x0) {
      memcpy((void *)*param_2,(void *)((size_t *)param_1[2])[1],sVar3);
      *param_2 = *param_2 + sVar3;
    }
  }
  else {
    local_28 = (_STACK *)0x0;
    local_28 = sk_new_null();
    if (local_28 != (_STACK *)0x0) {
      iVar4 = -1;
      st = (_STACK *)0x0;
      iVar2 = 0;
      while( true ) {
        iVar1 = sk_num((_STACK *)*param_1);
        if (iVar1 <= iVar2) break;
        data = sk_value((_STACK *)*param_1,iVar2);
        if (*(int *)((int)data + 8) != iVar4) {
          st = sk_new_null();
          if ((st == (_STACK *)0x0) || (iVar4 = sk_push(local_28,st), iVar4 == 0))
          goto LAB_000b78b2;
          iVar4 = *(int *)((int)data + 8);
        }
        iVar1 = sk_push(st,data);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_000b78b2;
      }
      sVar3 = ASN1_item_ex_i2d((ASN1_VALUE **)&local_28,(uchar **)0x0,
                               (ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1);
      iVar2 = BUF_MEM_grow((BUF_MEM *)param_1[2],sVar3);
      if (iVar2 != 0) {
        local_24[0] = *(uchar **)(param_1[2] + 4);
        ASN1_item_ex_i2d((ASN1_VALUE **)&local_28,local_24,(ASN1_ITEM *)X509_NAME_INTERNAL_it,-1,-1)
        ;
        sk_pop_free(local_28,(func *)0xb748d);
        param_1[1] = 0;
        if ((int)sVar3 < 0) {
          return sVar3;
        }
        if ((void *)param_1[3] != (void *)0x0) {
          CRYPTO_free((void *)param_1[3]);
          param_1[3] = 0;
        }
        iVar2 = sk_num((_STACK *)*param_1);
        if (iVar2 == 0) {
          param_1[4] = 0;
        }
        else {
          sVar3 = x509_name_canon_part_0(param_1);
          if ((int)sVar3 < 0) {
            return sVar3;
          }
        }
        goto LAB_000b77ce;
      }
    }
LAB_000b78b2:
    sVar3 = 0xffffffff;
    sk_pop_free(local_28,(func *)0xb748d);
    ERR_put_error(0xd,0xcb,0x41,"x_name.c",0x13a);
  }
  return sVar3;
}

