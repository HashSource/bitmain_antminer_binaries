
void do_dump(int param_1,code *param_2,int param_3,_union_263 param_4)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  char *pcVar5;
  char local_30;
  char local_2f;
  byte *local_2c;
  ASN1_TYPE local_28;
  
  iVar2 = (*param_2)(param_3,&DAT_002288e4,1);
  if (iVar2 != 0) {
    if (param_1 << 0x16 < 0) {
      local_28.type = (param_4.asn1_string)->type;
      local_28.value = param_4;
      iVar2 = i2d_ASN1_TYPE(&local_28,(uchar **)0x0);
      pbVar3 = (byte *)CRYPTO_malloc(iVar2,"a_strex.c",0x13d);
      if (pbVar3 != (byte *)0x0) {
        local_2c = pbVar3;
        i2d_ASN1_TYPE(&local_28,&local_2c);
        if (param_3 == 0) {
LAB_001a3810:
          CRYPTO_free(pbVar3);
        }
        else {
          pbVar1 = pbVar3;
          do {
            if (pbVar1 == pbVar3 + iVar2) goto LAB_001a3810;
            local_2f = "0123456789ABCDEF"[*pbVar1 & 0xf];
            local_30 = "0123456789ABCDEF"[*pbVar1 >> 4];
            iVar4 = (*param_2)(param_3,&local_30,2);
            pbVar1 = pbVar1 + 1;
          } while (iVar4 != 0);
          CRYPTO_free(pbVar3);
        }
      }
    }
    else {
      pbVar3 = (param_4.asn1_string)->data;
      pcVar5 = (param_4.object)->sn;
      if (param_3 != 0) {
        pbVar1 = pbVar3;
        do {
          if (pbVar1 == pbVar3 + (int)pcVar5) {
            return;
          }
          local_28.type._2_2_ = (undefined2)((uint)local_28.type >> 0x10);
          local_28.type =
               CONCAT31(CONCAT21(local_28.type._2_2_,"0123456789ABCDEF"[*pbVar1 & 0xf]),
                        "0123456789ABCDEF"[*pbVar1 >> 4]);
          iVar2 = (*param_2)(param_3,&local_28,2);
          pbVar1 = pbVar1 + 1;
        } while (iVar2 != 0);
      }
    }
  }
  return;
}

