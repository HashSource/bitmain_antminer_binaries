
undefined4
asn1_collect_constprop_0(BUF_MEM *param_1,uchar **param_2,uchar *param_3,uint param_4,int param_5)

{
  uchar *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  uchar *__n;
  uchar *local_3c;
  int iStack_38;
  int iStack_34;
  uchar *puStack_30;
  uchar *local_2c [2];
  
  param_4 = param_4 & 1;
  local_3c = *param_2;
  uVar4 = param_4 ^ 1;
  if (param_1 != (BUF_MEM *)0x0) {
    uVar4 = 0;
  }
  if (uVar4 == 0) {
    if (0 < (int)param_3) {
      do {
        puVar1 = local_3c;
        if (((param_3 != (uchar *)0x1) && (*local_3c == '\0')) && (local_3c[1] == '\0')) {
          local_3c = local_3c + 2;
          if (param_4 == 0) {
            ERR_put_error(0xd,0x6a,0x9f,DAT_000ba9dc,0x434);
            return 0;
          }
          goto LAB_000ba8a2;
        }
        local_2c[0] = local_3c;
        uVar4 = ASN1_get_object(local_2c,(long *)&puStack_30,&iStack_38,&iStack_34,(long)param_3);
        if ((int)(uVar4 << 0x18) < 0) {
          ERR_put_error(0xd,0x68,0x66,DAT_000ba9dc,0x4a2);
          ERR_put_error(0xd,0x6a,0x3a,DAT_000ba9dc,0x43d);
          return 0;
        }
        __n = puStack_30;
        if ((uVar4 & 1) != 0) {
          __n = puVar1 + ((int)param_3 - (int)local_2c[0]);
        }
        local_3c = local_2c[0];
        if ((int)(uVar4 << 0x1a) < 0) {
          if (4 < param_5) {
            ERR_put_error(0xd,0x6a,0xc5,DAT_000ba9dc,0x444);
            return 0;
          }
          iVar3 = asn1_collect_constprop_0(param_1,&local_3c,__n,uVar4 & 1,param_5 + 1);
          if (iVar3 == 0) {
            return 0;
          }
        }
        else if (__n != (uchar *)0x0) {
          if (param_1 != (BUF_MEM *)0x0) {
            sVar5 = param_1->length;
            iVar3 = BUF_MEM_grow_clean(param_1,(size_t)(__n + sVar5));
            if (iVar3 == 0) {
              ERR_put_error(0xd,0x8c,0x41,DAT_000ba9dc,0x45b);
              return 0;
            }
            memcpy(param_1->data + sVar5,local_3c,(size_t)__n);
          }
          local_3c = local_3c + (int)__n;
        }
        param_3 = puVar1 + ((int)param_3 - (int)local_3c);
      } while (0 < (int)param_3);
    }
    if (param_4 == 0) {
LAB_000ba8a2:
      uVar2 = 1;
      *param_2 = local_3c;
    }
    else {
      ERR_put_error(0xd,0x6a,0x89,DAT_000ba9dc,0x44e);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
    *param_2 = local_3c + (int)param_3;
  }
  return uVar2;
}

