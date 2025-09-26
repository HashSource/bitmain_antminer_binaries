
undefined4
get_cert_by_subject(X509_LOOKUP *param_1,int param_2,X509_NAME *param_3,undefined4 *param_4)

{
  BUF_MEM *str;
  ulong uVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  ulong *data;
  _STACK *st;
  char *pcVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined4 uVar8;
  char *pcVar9;
  int iVar10;
  undefined4 *local_13c;
  void *local_138;
  int local_130;
  undefined1 **local_12c;
  ulong local_128 [2];
  stat sStack_120;
  undefined1 *local_c4 [19];
  undefined1 auStack_78 [8];
  X509_NAME *local_70;
  undefined1 auStack_5c [20];
  X509_NAME *local_48;
  
  if (param_3 == (X509_NAME *)0x0) {
    return 0;
  }
  local_130 = param_2;
  if (param_2 == 1) {
    local_12c = local_c4;
    local_c4[0] = auStack_5c;
    pcVar9 = "";
    local_48 = param_3;
    str = BUF_MEM_new();
  }
  else {
    if (param_2 != 2) {
      ERR_put_error(0xb,0x67,0x70,"by_dir.c",0x122);
      return 0;
    }
    local_12c = local_c4;
    local_c4[0] = auStack_78;
    pcVar9 = "r";
    local_70 = param_3;
    str = BUF_MEM_new();
  }
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xb,0x67,7,"by_dir.c",0x127);
    return 0;
  }
  pcVar5 = param_1->method_data;
  iVar10 = 0;
  uVar1 = X509_NAME_hash(param_3);
  iVar2 = sk_num(*(_STACK **)(pcVar5 + 4));
  if (0 < iVar2) {
    do {
      puVar3 = (undefined4 *)sk_value(*(_STACK **)(pcVar5 + 4),iVar10);
      sVar4 = strlen((char *)*puVar3);
      iVar2 = BUF_MEM_grow(str,sVar4 + 0x11);
      if (iVar2 == 0) {
        ERR_put_error(0xb,0x67,0x41,"by_dir.c",0x135);
        uVar8 = 0;
        goto LAB_001639c4;
      }
      if (param_2 == 2) {
        if (puVar3[2] == 0) {
          uVar7 = 0;
          local_138 = (void *)0x0;
        }
        else {
          local_128[0] = uVar1;
          CRYPTO_lock(5,0xb,"by_dir.c",0x13a);
          iVar2 = sk_find((_STACK *)puVar3[2],local_128);
          if (iVar2 < 0) {
            uVar7 = 0;
            local_138 = (void *)0x0;
          }
          else {
            local_138 = sk_value((_STACK *)puVar3[2],iVar2);
            uVar7 = *(ulong *)((int)local_138 + 4);
          }
          CRYPTO_lock(6,0xb,"by_dir.c",0x143);
        }
        while( true ) {
          BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*puVar3,0x2f,uVar1,pcVar9,uVar7);
          iVar2 = __xstat(3,str->data,&sStack_120);
          if ((iVar2 < 0) || (iVar2 = X509_load_crl_file(param_1,str->data,puVar3[1]), iVar2 == 0))
          break;
          uVar7 = uVar7 + 1;
        }
      }
      else {
        uVar7 = 0;
        if (param_2 == 1) {
          while( true ) {
            BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*puVar3,0x2f,uVar1,pcVar9,uVar7);
            iVar2 = __xstat(3,str->data,&sStack_120);
            if (iVar2 < 0) break;
            iVar2 = X509_load_cert_file(param_1,str->data,puVar3[1]);
            if (iVar2 == 0) {
              local_138 = (void *)0x0;
              goto LAB_00163964;
            }
            uVar7 = uVar7 + 1;
          }
          local_138 = (void *)0x0;
        }
        else {
          while( true ) {
            BIO_snprintf(str->data,str->max,"%s%c%08lx.%s%d",*puVar3,0x2f,uVar1,pcVar9,uVar7);
            iVar2 = __xstat(3,str->data,&sStack_120);
            if (iVar2 < 0) break;
            uVar7 = uVar7 + 1;
          }
          local_138 = (void *)0x0;
        }
      }
LAB_00163964:
      CRYPTO_lock(9,0xb,"by_dir.c",0x17c);
      iVar2 = sk_find(&param_1->store_ctx->objs->stack,&local_130);
      if (iVar2 == -1) {
        local_13c = (undefined4 *)0x0;
      }
      else {
        local_13c = (undefined4 *)sk_value(&param_1->store_ctx->objs->stack,iVar2);
      }
      CRYPTO_lock(10,0xb,"by_dir.c",0x182);
      if (param_2 == 2) {
        CRYPTO_lock(9,0xb,"by_dir.c",0x187);
        if ((local_138 == (void *)0x0) &&
           ((local_128[0] = uVar1, iVar2 = sk_find((_STACK *)puVar3[2],local_128), iVar2 < 0 ||
            (local_138 = sk_value((_STACK *)puVar3[2],iVar2), local_138 == (void *)0x0)))) {
          data = (ulong *)CRYPTO_malloc(8,"by_dir.c",0x193);
          st = (_STACK *)puVar3[2];
          *data = uVar1;
          data[1] = uVar7;
          iVar2 = sk_push(st,data);
          if (iVar2 == 0) {
            CRYPTO_lock(10,0xb,"by_dir.c",0x197);
            CRYPTO_free(data);
            uVar8 = 0;
            goto LAB_001639c4;
          }
        }
        else if (*(int *)((int)local_138 + 4) < (int)uVar7) {
          *(ulong *)((int)local_138 + 4) = uVar7;
        }
        CRYPTO_lock(10,0xb,"by_dir.c",0x19f);
      }
      if (local_13c != (undefined4 *)0x0) {
        uVar8 = 1;
        uVar6 = local_13c[1];
        *param_4 = *local_13c;
        param_4[1] = uVar6;
        goto LAB_001639c4;
      }
      iVar10 = iVar10 + 1;
      iVar2 = sk_num(*(_STACK **)(pcVar5 + 4));
    } while (iVar10 < iVar2);
  }
  uVar8 = 0;
LAB_001639c4:
  BUF_MEM_free(str);
  return uVar8;
}

