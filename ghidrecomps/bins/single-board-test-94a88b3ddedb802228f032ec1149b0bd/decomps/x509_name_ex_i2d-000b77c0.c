
size_t x509_name_ex_i2d(undefined4 *param_1,void **param_2)

{
  void *data;
  int iVar1;
  int iVar2;
  size_t sVar3;
  _STACK *st;
  _STACK **pp_Var4;
  int iVar5;
  _STACK *local_28;
  char **local_24 [2];
  
  pp_Var4 = (_STACK **)*param_1;
  if (pp_Var4[1] == (_STACK *)0x0) {
LAB_000b77ce:
    sVar3 = pp_Var4[2]->num;
    if (param_2 != (void **)0x0) {
      memcpy(*param_2,pp_Var4[2]->data,sVar3);
      *param_2 = (void *)((int)*param_2 + sVar3);
    }
  }
  else {
    local_28 = (_STACK *)0x0;
    local_28 = sk_new_null();
    if (local_28 != (_STACK *)0x0) {
      iVar5 = -1;
      st = (_STACK *)0x0;
      iVar2 = 0;
      while( true ) {
        iVar1 = sk_num(*pp_Var4);
        if (iVar1 <= iVar2) break;
        data = sk_value(*pp_Var4,iVar2);
        if (*(int *)((int)data + 8) != iVar5) {
          st = sk_new_null();
          if ((st == (_STACK *)0x0) || (iVar5 = sk_push(local_28,st), iVar5 == 0))
          goto LAB_000b78b2;
          iVar5 = *(int *)((int)data + 8);
        }
        iVar1 = sk_push(st,data);
        iVar2 = iVar2 + 1;
        if (iVar1 == 0) goto LAB_000b78b2;
      }
      sVar3 = ASN1_item_ex_i2d((ASN1_VALUE **)&local_28,(uchar **)0x0,DAT_000b78e0,-1,-1);
      iVar2 = BUF_MEM_grow((BUF_MEM *)pp_Var4[2],sVar3);
      if (iVar2 != 0) {
        local_24[0] = pp_Var4[2]->data;
        ASN1_item_ex_i2d((ASN1_VALUE **)&local_28,(uchar **)local_24,DAT_000b78e0,-1,-1);
        sk_pop_free(local_28,DAT_000b78e4);
        pp_Var4[1] = (_STACK *)0x0;
        if ((int)sVar3 < 0) {
          return sVar3;
        }
        if (pp_Var4[3] != (_STACK *)0x0) {
          CRYPTO_free(pp_Var4[3]);
          pp_Var4[3] = (_STACK *)0x0;
        }
        iVar2 = sk_num(*pp_Var4);
        if (iVar2 == 0) {
          pp_Var4[4] = (_STACK *)0x0;
        }
        else {
          sVar3 = x509_name_canon_part_0(pp_Var4);
          if ((int)sVar3 < 0) {
            return sVar3;
          }
        }
        goto LAB_000b77ce;
      }
    }
LAB_000b78b2:
    sVar3 = 0xffffffff;
    sk_pop_free(local_28,DAT_000b78e4);
    ERR_put_error(0xd,0xcb,0x41,DAT_000b78e8,0x13a);
  }
  return sVar3;
}

