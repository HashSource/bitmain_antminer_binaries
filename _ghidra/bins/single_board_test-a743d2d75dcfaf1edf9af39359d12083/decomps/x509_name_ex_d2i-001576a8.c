
int x509_name_ex_d2i(undefined4 *param_1,undefined4 *param_2,long param_3,undefined4 param_4,
                    int param_5,int param_6,char param_7,ASN1_TLC *param_8)

{
  int iVar1;
  ASN1_VALUE *val;
  _STACK *p_Var2;
  BUF_MEM *str;
  int iVar3;
  void *data;
  _STACK *st;
  int iVar4;
  undefined4 *ptr;
  uchar *__src;
  uchar *local_28;
  _STACK *local_24 [2];
  
  __src = (uchar *)*param_2;
  local_24[0] = (_STACK *)0x0;
  local_28 = __src;
  iVar1 = ASN1_item_ex_d2i((ASN1_VALUE **)local_24,&local_28,param_3,
                           (ASN1_ITEM *)X509_NAME_INTERNAL_it,param_5,param_6,param_7,param_8);
  if (iVar1 < 1) {
    return iVar1;
  }
  ptr = (undefined4 *)*param_1;
  if (ptr != (undefined4 *)0x0) {
    BUF_MEM_free((BUF_MEM *)ptr[2]);
    sk_pop_free((_STACK *)*ptr,(func *)0x1572f1);
    if ((void *)ptr[3] != (void *)0x0) {
      CRYPTO_free((void *)ptr[3]);
    }
    CRYPTO_free(ptr);
    *param_1 = 0;
  }
  val = (ASN1_VALUE *)CRYPTO_malloc(0x14,"x_name.c",0x88);
  if (val == (ASN1_VALUE *)0x0) {
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x96);
  }
  else {
    p_Var2 = sk_new_null();
    *(_STACK **)val = p_Var2;
    if (p_Var2 != (_STACK *)0x0) {
      str = BUF_MEM_new();
      *(BUF_MEM **)(val + 8) = str;
      if (str != (BUF_MEM *)0x0) {
        *(undefined4 *)(val + 0xc) = 0;
        *(undefined4 *)(val + 0x10) = 0;
        *(undefined4 *)(val + 4) = 1;
        iVar1 = BUF_MEM_grow(str,(int)local_28 - (int)__src);
        if (iVar1 != 0) {
          memcpy(*(void **)(*(int *)(val + 8) + 4),__src,(int)local_28 - (int)__src);
          for (iVar1 = 0; iVar3 = sk_num(local_24[0]), iVar1 < iVar3; iVar1 = iVar1 + 1) {
            p_Var2 = (_STACK *)sk_value(local_24[0],iVar1);
            iVar3 = 0;
            while( true ) {
              iVar4 = sk_num(p_Var2);
              if (iVar4 <= iVar3) break;
              data = sk_value(p_Var2,iVar3);
              st = *(_STACK **)val;
              *(int *)((int)data + 8) = iVar1;
              iVar4 = sk_push(st,data);
              iVar3 = iVar3 + 1;
              if (iVar4 == 0) goto LAB_00157740;
            }
            sk_free(p_Var2);
          }
          sk_free(local_24[0]);
          if (*(void **)(val + 0xc) != (void *)0x0) {
            CRYPTO_free(*(void **)(val + 0xc));
            *(undefined4 *)(val + 0xc) = 0;
          }
          iVar1 = sk_num(*(_STACK **)val);
          if (iVar1 == 0) {
            *(undefined4 *)(val + 0x10) = 0;
            iVar1 = 1;
LAB_00157808:
            *(undefined4 *)(val + 4) = 0;
            *param_1 = val;
            *param_2 = local_28;
            return iVar1;
          }
          iVar1 = x509_name_canon_part_0(val);
          if (iVar1 != 0) goto LAB_00157808;
        }
LAB_00157740:
        ASN1_item_free(val,(ASN1_ITEM *)X509_NAME_it);
        goto LAB_00157748;
      }
    }
    ERR_put_error(0xd,0xab,0x41,"x_name.c",0x96);
    if (*(_STACK **)val != (_STACK *)0x0) {
      sk_free(*(_STACK **)val);
    }
    CRYPTO_free(val);
  }
LAB_00157748:
  ERR_put_error(0xd,0x9e,0x3a,"x_name.c",0xec);
  return 0;
}

