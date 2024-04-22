
void do_dump(int param_1,code *param_2,int param_3,_union_263 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  undefined local_30;
  undefined local_2f;
  byte *local_2c;
  undefined8 local_28;
  
  iVar2 = (*param_2)(param_3,DAT_000b6198,1);
  iVar3 = DAT_000b61a0;
  if (iVar2 != 0) {
    if (param_1 << 0x16 < 0) {
      local_28._0_4_ = (param_4.asn1_string)->type;
      local_28._4_4_ = param_4;
      iVar3 = i2d_ASN1_TYPE((ASN1_TYPE *)&local_28,(uchar **)0x0);
      pbVar4 = (byte *)CRYPTO_malloc(iVar3,DAT_000b619c,0x13d);
      if (pbVar4 != (byte *)0x0) {
        local_2c = pbVar4;
        i2d_ASN1_TYPE((ASN1_TYPE *)&local_28,&local_2c);
        iVar2 = DAT_000b61a0;
        if (param_3 == 0) {
LAB_000b6180:
          CRYPTO_free(pbVar4);
        }
        else {
          pbVar1 = pbVar4;
          do {
            if (pbVar1 == pbVar4 + iVar3) goto LAB_000b6180;
            local_2f = *(undefined *)((*pbVar1 & 0xf) + iVar2 + 0x80);
            local_30 = *(undefined *)(iVar2 + (uint)(*pbVar1 >> 4) + 0x80);
            iVar5 = (*param_2)(param_3,&local_30,2);
            pbVar1 = pbVar1 + 1;
          } while (iVar5 != 0);
          CRYPTO_free(pbVar4);
        }
      }
    }
    else {
      pbVar4 = (param_4.asn1_string)->data;
      pcVar6 = (param_4.object)->sn;
      if (param_3 != 0) {
        pbVar1 = pbVar4;
        do {
          if (pbVar1 == pbVar4 + (int)pcVar6) {
            return;
          }
          local_28._2_2_ = (undefined2)((uint)(int)local_28 >> 0x10);
          local_28._0_4_ =
               CONCAT31(CONCAT21(local_28._2_2_,*(undefined *)((*pbVar1 & 0xf) + iVar3 + 0x80)),
                        *(undefined *)(iVar3 + (uint)(*pbVar1 >> 4) + 0x80));
          iVar2 = (*param_2)(param_3,&local_28,2);
          pbVar1 = pbVar1 + 1;
        } while (iVar2 != 0);
      }
    }
  }
  return;
}

