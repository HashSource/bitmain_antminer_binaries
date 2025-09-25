
undefined4 str_copy(CONF *param_1,byte *param_2,undefined4 *param_3,byte *param_4)

{
  char cVar1;
  ushort uVar2;
  BUF_MEM *str;
  size_t sVar3;
  int iVar4;
  char *__s;
  int iVar5;
  void *pvVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  byte *section;
  byte *pbVar13;
  byte *name;
  byte local_3c;
  
  str = BUF_MEM_new();
  if (str != (BUF_MEM *)0x0) {
    sVar3 = strlen((char *)param_4);
    iVar4 = BUF_MEM_grow(str,sVar3 + 1);
    if (iVar4 != 0) {
      bVar7 = *param_4;
      uVar8 = (uint)bVar7;
      pvVar6 = param_1->meth_data;
      iVar4 = 0;
      local_3c = 0;
LAB_001cd708:
      do {
        uVar11 = uVar8;
        pbVar10 = param_4;
        if (-1 < (char)bVar7) {
LAB_001cd70c:
          uVar2 = *(ushort *)((int)pvVar6 + uVar11 * 2);
          uVar8 = (uint)uVar2;
          if ((int)(uVar8 << 0x19) < 0) {
            do {
              param_4 = pbVar10 + 1;
              bVar7 = *param_4;
              uVar8 = (uint)bVar7;
              pbVar13 = pbVar10 + 2;
              if (-1 < (char)bVar7) {
                uVar2 = *(ushort *)((int)pvVar6 + uVar8 * 2);
                if ((uVar2 & 8) != 0) goto LAB_001cd798;
                if (uVar11 == uVar8) goto LAB_001cd79c;
                if ((uVar2 & 0x20) != 0) {
                  bVar7 = pbVar10[2];
                  uVar8 = (uint)bVar7;
                  param_4 = pbVar13;
                  if ((-1 < (char)bVar7) && ((*(ushort *)((int)pvVar6 + uVar8 * 2) & 8) != 0))
                  goto LAB_001cd798;
                }
              }
              str->data[iVar4] = bVar7;
              iVar4 = iVar4 + 1;
              pvVar6 = param_1->meth_data;
              pbVar10 = param_4;
            } while( true );
          }
          if ((int)(uVar8 << 0x15) < 0) {
            while( true ) {
              param_4 = pbVar10 + 1;
              bVar7 = *param_4;
              uVar8 = (uint)bVar7;
              if ((-1 < (char)bVar7) && ((*(ushort *)((int)pvVar6 + uVar8 * 2) & 8) != 0)) break;
              if (uVar11 == uVar8) {
                bVar7 = pbVar10[2];
                uVar8 = (uint)bVar7;
                if (uVar11 != uVar8) goto LAB_001cd79e;
                param_4 = pbVar10 + 2;
              }
              str->data[iVar4] = bVar7;
              iVar4 = iVar4 + 1;
              pvVar6 = param_1->meth_data;
              pbVar10 = param_4;
            }
            if (uVar11 == uVar8) {
              uVar8 = (uint)pbVar10[2];
              goto LAB_001cd79e;
            }
            goto LAB_001cd708;
          }
          if ((int)(uVar8 << 0x1a) < 0) {
            bVar7 = pbVar10[1];
            uVar8 = (uint)bVar7;
            param_4 = pbVar10 + 2;
            if ((int)(uVar8 << 0x18) < 0) {
LAB_001cd7dc:
              if (uVar8 == 0x6e) {
                bVar7 = 10;
              }
              else if (uVar8 == 0x62) {
                bVar7 = 8;
              }
              else if (uVar8 == 0x74) {
                bVar7 = 9;
              }
            }
            else {
              if ((int)((uint)*(ushort *)((int)pvVar6 + uVar8 * 2) << 0x1c) < 0) goto LAB_001cd92e;
              if (uVar8 != 0x72) goto LAB_001cd7dc;
              bVar7 = 0xd;
            }
            str->data[iVar4] = bVar7;
            iVar4 = iVar4 + 1;
            bVar7 = pbVar10[2];
            uVar8 = (uint)bVar7;
            pvVar6 = param_1->meth_data;
            goto LAB_001cd708;
          }
          uVar8 = uVar8 & 8;
          if ((uVar2 & 8) != 0) {
LAB_001cd92e:
            str->data[iVar4] = '\0';
            CRYPTO_free((void *)*param_3);
            *param_3 = str->data;
            CRYPTO_free(str);
            return 1;
          }
          if (uVar11 == 0x24) {
            bVar7 = pbVar10[1];
            uVar11 = (uint)bVar7;
            if (uVar11 == 0x7b) {
              uVar8 = 0x7d;
LAB_001cd8dc:
              bVar7 = pbVar10[2];
              uVar11 = (uint)bVar7;
              pbVar13 = pbVar10 + 2;
            }
            else {
              if (uVar11 == 0x28) {
                uVar8 = 0x29;
                goto LAB_001cd8dc;
              }
              pbVar13 = pbVar10 + 1;
            }
            if ((bVar7 & 0x80) == 0) {
              uVar2 = *(ushort *)((int)pvVar6 + uVar11 * 2);
              pbVar9 = pbVar13;
              goto joined_r0x001cd834;
            }
            bVar7 = (byte)uVar11;
            *pbVar13 = 0;
            pbVar12 = pbVar13;
            goto joined_r0x001cd8f6;
          }
        }
LAB_001cd7a6:
        param_4 = pbVar10 + 1;
        str->data[iVar4] = (char)uVar11;
        iVar4 = iVar4 + 1;
        bVar7 = *param_4;
        uVar8 = (uint)bVar7;
        pvVar6 = param_1->meth_data;
      } while( true );
    }
LAB_001cd91c:
    BUF_MEM_free(str);
  }
  return 0;
LAB_001cd798:
  if (uVar11 != uVar8) goto LAB_001cd708;
LAB_001cd79c:
  uVar8 = (uint)param_4[1];
LAB_001cd79e:
  pbVar10 = param_4 + 1;
  uVar11 = uVar8;
  if ((char)uVar8 < '\0') goto LAB_001cd7a6;
  goto LAB_001cd70c;
joined_r0x001cd834:
  if ((uVar2 & 0x107) == 0) goto LAB_001cd9a0;
  pbVar9 = pbVar9 + 1;
  uVar11 = (uint)*pbVar9;
  if ((*pbVar9 & 0x80) != 0) goto LAB_001cd84e;
  uVar2 = *(ushort *)((int)pvVar6 + uVar11 * 2);
  goto joined_r0x001cd834;
LAB_001cd9a0:
  if ((uVar11 == 0x3a) && (pbVar9[1] == 0x3a)) {
    name = pbVar9 + 2;
    *pbVar9 = 0;
    bVar7 = pbVar9[2];
    uVar11 = (uint)bVar7;
    pbVar12 = name;
    if ((bVar7 & 0x80) == 0) {
      uVar2 = *(ushort *)((int)param_1->meth_data + uVar11 * 2);
      while ((uVar2 & 0x107) != 0) {
        pbVar12 = pbVar12 + 1;
        bVar7 = *pbVar12;
        uVar11 = (uint)bVar7;
        if ((bVar7 & 0x80) != 0) goto LAB_001cd9ea;
        uVar2 = *(ushort *)((int)param_1->meth_data + uVar11 * 2);
      }
      bVar7 = (byte)uVar11;
      *pbVar12 = 0;
      if (uVar8 != 0) {
        local_3c = 0x3a;
        section = pbVar13;
        goto LAB_001cd85c;
      }
      __s = _CONF_get_string(param_1,(char *)pbVar13,(char *)name);
      local_3c = 0x3a;
      param_4 = pbVar12;
    }
    else {
LAB_001cd9ea:
      *pbVar12 = 0;
      if (uVar8 != 0) goto LAB_001cd974;
      local_3c = 0x3a;
      __s = _CONF_get_string(param_1,(char *)pbVar13,(char *)name);
      param_4 = pbVar12;
    }
  }
  else {
LAB_001cd84e:
    bVar7 = (byte)uVar11;
    *pbVar9 = 0;
    pbVar12 = pbVar9;
joined_r0x001cd8f6:
    pbVar9 = (byte *)0x0;
    name = pbVar13;
    section = param_2;
    if (uVar8 == 0) {
      __s = _CONF_get_string(param_1,(char *)param_2,(char *)pbVar13);
      param_4 = pbVar12;
      goto LAB_001cd884;
    }
LAB_001cd85c:
    bVar7 = (byte)uVar11;
    if (uVar11 != uVar8) {
LAB_001cd974:
      ERR_put_error(0xe,0x65,0x66,"crypto/conf/conf_def.c",0x26a);
      goto LAB_001cd91c;
    }
    __s = _CONF_get_string(param_1,(char *)section,(char *)name);
    param_4 = pbVar12 + 1;
    if (pbVar9 == (byte *)0x0) goto LAB_001cd884;
  }
  *pbVar9 = local_3c;
LAB_001cd884:
  *pbVar12 = bVar7;
  if (__s == (char *)0x0) {
    ERR_put_error(0xe,0x65,0x68,"crypto/conf/conf_def.c",0x27e);
    goto LAB_001cd91c;
  }
  sVar3 = strlen(__s);
  sVar3 = (str->length - ((int)param_4 - (int)pbVar10)) + sVar3;
  if (0x10000 < sVar3) {
    ERR_put_error(0xe,0x65,0x74,"crypto/conf/conf_def.c",0x283);
    goto LAB_001cd91c;
  }
  iVar5 = BUF_MEM_grow_clean(str,sVar3);
  if (iVar5 == 0) {
    ERR_put_error(0xe,0x65,0x41,"crypto/conf/conf_def.c",0x287);
    goto LAB_001cd91c;
  }
  cVar1 = *__s;
  while (cVar1 != '\0') {
    str->data[iVar4] = cVar1;
    __s = __s + 1;
    iVar4 = iVar4 + 1;
    cVar1 = *__s;
  }
  *pbVar12 = bVar7;
  bVar7 = *param_4;
  uVar8 = (uint)bVar7;
  pvVar6 = param_1->meth_data;
  goto LAB_001cd708;
}

