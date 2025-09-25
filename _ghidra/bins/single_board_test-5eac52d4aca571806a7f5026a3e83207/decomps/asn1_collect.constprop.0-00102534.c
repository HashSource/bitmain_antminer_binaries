
undefined4
asn1_collect_constprop_0(BUF_MEM *param_1,undefined4 *param_2,int param_3,uint param_4,int param_5)

{
  uchar *puVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  size_t __n;
  bool bVar5;
  uchar *local_3c;
  int iStack_38;
  int iStack_34;
  size_t local_30;
  uchar *local_2c [2];
  
  param_4 = param_4 & 1;
  local_3c = (uchar *)*param_2;
  uVar3 = param_4 ^ 1;
  if (param_1 != (BUF_MEM *)0x0) {
    uVar3 = 0;
  }
  if (uVar3 != 0) {
    *param_2 = local_3c + param_3;
    return 1;
  }
  if (0 < param_3) {
    do {
      puVar1 = local_3c;
      if (((param_3 != 1) && (*local_3c == '\0')) && (local_3c[1] == '\0')) {
        local_3c = local_3c + 2;
        if (param_4 == 0) {
          ERR_put_error(0xd,0x6a,0x9f,"crypto/asn1/tasn_dec.c",0x403);
          return 0;
        }
        goto LAB_00102692;
      }
      local_2c[0] = local_3c;
      uVar3 = ASN1_get_object(local_2c,(long *)&local_30,&iStack_38,&iStack_34,param_3);
      if ((uVar3 & 0x80) != 0) {
        ERR_put_error(0xd,0x68,0x66,"crypto/asn1/tasn_dec.c",0x471);
        ERR_put_error(0xd,0x6a,0x3a,"crypto/asn1/tasn_dec.c",0x40c);
        return 0;
      }
      local_3c = local_2c[0];
      bVar5 = (int)(uVar3 << 0x1f) < 0;
      __n = local_30;
      if (bVar5) {
        __n = (int)local_2c[0] - (int)puVar1;
      }
      if (bVar5) {
        __n = param_3 - __n;
      }
      if ((int)(uVar3 << 0x1a) < 0) {
        if (4 < param_5) {
          ERR_put_error(0xd,0x6a,0xc5,"crypto/asn1/tasn_dec.c",0x413);
          return 0;
        }
        iVar2 = asn1_collect_constprop_0(param_1,&local_3c,__n,uVar3 & 1,param_5 + 1);
        if (iVar2 == 0) {
          return 0;
        }
LAB_00102596:
        iVar2 = (int)local_3c - (int)puVar1;
      }
      else {
        if (__n == 0) goto LAB_00102596;
        if (param_1 != (BUF_MEM *)0x0) {
          sVar4 = param_1->length;
          iVar2 = BUF_MEM_grow_clean(param_1,sVar4 + __n);
          if (iVar2 == 0) {
            ERR_put_error(0xd,0x8c,0x41,"crypto/asn1/tasn_dec.c",0x42a);
            return 0;
          }
          memcpy(param_1->data + sVar4,local_3c,__n);
        }
        local_3c = local_3c + __n;
        iVar2 = (int)local_3c - (int)puVar1;
      }
      param_3 = param_3 - iVar2;
    } while (0 < param_3);
  }
  if (param_4 != 0) {
    ERR_put_error(0xd,0x6a,0x89,"crypto/asn1/tasn_dec.c",0x41d);
    return 0;
  }
LAB_00102692:
  *param_2 = local_3c;
  return 1;
}

