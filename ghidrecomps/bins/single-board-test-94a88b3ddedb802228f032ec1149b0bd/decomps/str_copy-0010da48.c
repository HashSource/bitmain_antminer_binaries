
undefined4 str_copy(CONF *param_1,byte *param_2,char **param_3,byte *param_4)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  byte *pbVar4;
  BUF_MEM *str;
  size_t sVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  char *__s;
  byte *pbVar9;
  byte *pbVar10;
  void *pvVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  byte *name;
  
  str = BUF_MEM_new();
  if (str != (BUF_MEM *)0x0) {
    sVar5 = strlen((char *)param_4);
    iVar6 = BUF_MEM_grow(str,sVar5 + 1);
    if (iVar6 != 0) {
      uVar13 = (uint)*param_4;
      iVar6 = 0;
      pvVar11 = param_1->meth_data;
      bVar3 = 0;
      iVar7 = (int)(short)(ushort)*param_4;
LAB_0010da7c:
      do {
        uVar2 = *(ushort *)((int)pvVar11 + iVar7 * 2);
        uVar14 = uVar13;
        pbVar15 = param_4;
        while (uVar13 = (uint)uVar2, (int)(uVar13 << 0x19) < 0) {
          bVar12 = pbVar15[1];
          iVar7 = (int)(short)(ushort)bVar12;
          uVar2 = *(ushort *)((int)pvVar11 + iVar7 * 2);
          param_4 = pbVar15;
          while( true ) {
            param_4 = param_4 + 1;
            uVar13 = (uint)bVar12;
            if ((uVar2 & 8) != 0) break;
            if (uVar13 == uVar14) goto LAB_0010dad4;
            pbVar15 = param_4 + 1;
            if ((uVar2 & 0x20) == 0) {
              bVar12 = *param_4;
            }
            else {
              bVar12 = param_4[1];
              uVar13 = (uint)bVar12;
              iVar7 = (int)(short)(ushort)bVar12;
              param_4 = pbVar15;
              if ((int)((uint)*(ushort *)((int)pvVar11 + iVar7 * 2) << 0x1c) < 0) break;
            }
            str->data[iVar6] = bVar12;
            iVar6 = iVar6 + 1;
            bVar12 = param_4[1];
            pvVar11 = param_1->meth_data;
            iVar7 = (int)(short)(ushort)bVar12;
            uVar2 = *(ushort *)((int)pvVar11 + iVar7 * 2);
          }
          if (uVar13 != uVar14) goto LAB_0010da7c;
LAB_0010dad4:
          uVar14 = (uint)param_4[1];
          pbVar15 = param_4 + 1;
          uVar2 = *(ushort *)((int)pvVar11 + (short)(ushort)param_4[1] * 2);
        }
        if (-1 < (int)(uVar13 << 0x15)) {
          if ((int)(uVar13 << 0x1a) < 0) {
            bVar12 = pbVar15[1];
            uVar13 = (uint)bVar12;
            param_4 = pbVar15 + 2;
            if ((int)((uint)*(ushort *)((int)pvVar11 + uVar13 * 2) << 0x1c) < 0) {
LAB_0010dcea:
              str->data[iVar6] = '\0';
              if (*param_3 != (char *)0x0) {
                CRYPTO_free(*param_3);
              }
              *param_3 = str->data;
              CRYPTO_free(str);
              return 1;
            }
            if (uVar13 == 0x72) {
              bVar12 = 0xd;
            }
            else if (uVar13 == 0x6e) {
              bVar12 = 10;
            }
            else if (uVar13 == 0x62) {
              bVar12 = 8;
            }
            else if (uVar13 == 0x74) {
              bVar12 = 9;
            }
            str->data[iVar6] = bVar12;
            iVar6 = iVar6 + 1;
            uVar13 = (uint)pbVar15[2];
            pvVar11 = param_1->meth_data;
            iVar7 = (int)(short)(ushort)pbVar15[2];
          }
          else {
            if ((uVar2 & 8) != 0) goto LAB_0010dcea;
            if (uVar14 == 0x24) {
              uVar13 = (uint)pbVar15[1];
              if (uVar13 == 0x7b) {
                uVar14 = 0x7d;
LAB_0010dcdc:
                pbVar8 = pbVar15 + 2;
                uVar13 = (uint)pbVar15[2];
              }
              else {
                if (uVar13 == 0x28) {
                  uVar14 = 0x29;
                  goto LAB_0010dcdc;
                }
                pbVar8 = pbVar15 + 1;
                uVar14 = 0;
              }
              uVar2 = *(ushort *)((int)pvVar11 + uVar13 * 2);
              pbVar9 = pbVar8;
              while ((uVar2 & 0x107) != 0) {
                pbVar9 = pbVar9 + 1;
                uVar13 = (uint)*pbVar9;
                uVar2 = *(ushort *)((int)pvVar11 + uVar13 * 2);
              }
              if ((uVar13 == 0x3a) && (pbVar9[1] == 0x3a)) {
                name = pbVar9 + 2;
                *pbVar9 = 0;
                uVar13 = (uint)pbVar9[2];
                pbVar10 = pbVar8;
                if ((*(ushort *)((int)param_1->meth_data + uVar13 * 2) & 0x107) == 0) {
                  bVar3 = 0x3a;
                  pbVar8 = name;
                }
                else {
                  pbVar4 = pbVar9 + 3;
                  do {
                    pbVar8 = pbVar4;
                    uVar13 = (uint)*pbVar8;
                    pbVar4 = pbVar8 + 1;
                  } while ((*(ushort *)((int)param_1->meth_data + uVar13 * 2) & 0x107) != 0);
                  bVar3 = 0x3a;
                }
              }
              else {
                pbVar10 = param_2;
                name = pbVar8;
                pbVar8 = pbVar9;
                pbVar9 = (byte *)0x0;
              }
              *pbVar8 = 0;
              param_4 = pbVar8;
              if (uVar14 != 0) {
                if (uVar13 != uVar14) {
                  ERR_put_error(0xe,0x65,0x66,DAT_0010dd44,0x235);
                  break;
                }
                param_4 = pbVar8 + 1;
              }
              __s = _CONF_get_string(param_1,(char *)pbVar10,(char *)name);
              if (pbVar9 != (byte *)0x0) {
                *pbVar9 = bVar3;
              }
              *pbVar8 = (byte)uVar13;
              if (__s == (char *)0x0) {
                ERR_put_error(0xe,0x65,0x68,DAT_0010dd44,0x249);
                break;
              }
              sVar5 = strlen(__s);
              iVar7 = BUF_MEM_grow_clean(str,(size_t)(pbVar15 + sVar5 + (str->length - (int)param_4)
                                                     ));
              if (iVar7 == 0) {
                ERR_put_error(0xe,0x65,0x41,DAT_0010dd44,0x24e);
                break;
              }
              cVar1 = *__s;
              while (cVar1 != '\0') {
                str->data[iVar6] = cVar1;
                iVar6 = iVar6 + 1;
                __s = __s + 1;
                cVar1 = *__s;
              }
              *pbVar8 = (byte)uVar13;
              uVar13 = (uint)*param_4;
              pvVar11 = param_1->meth_data;
              iVar7 = (int)(short)(ushort)*param_4;
            }
            else {
              str->data[iVar6] = (char)uVar14;
              iVar6 = iVar6 + 1;
              uVar13 = (uint)pbVar15[1];
              param_4 = pbVar15 + 1;
              pvVar11 = param_1->meth_data;
              iVar7 = (int)(short)(ushort)pbVar15[1];
            }
          }
          goto LAB_0010da7c;
        }
        uVar13 = (uint)pbVar15[1];
        uVar2 = *(ushort *)((int)pvVar11 + uVar13 * 2);
        while (param_4 = pbVar15 + 1, -1 < (int)((uint)uVar2 << 0x1c)) {
          if (uVar13 == uVar14) {
            bVar12 = param_4[1];
            uVar13 = (uint)bVar12;
            pbVar15 = param_4 + 1;
            if (uVar13 != uVar14) {
              param_4 = param_4 + 1;
              iVar7 = (int)(short)(ushort)bVar12;
              goto LAB_0010da7c;
            }
          }
          else {
            bVar12 = *param_4;
            pbVar15 = param_4;
          }
          str->data[iVar6] = bVar12;
          iVar6 = iVar6 + 1;
          pvVar11 = param_1->meth_data;
          uVar13 = (uint)pbVar15[1];
          uVar2 = *(ushort *)((int)pvVar11 + uVar13 * 2);
        }
        if (uVar13 == uVar14) {
          pbVar15 = param_4 + 1;
          uVar13 = (uint)*pbVar15;
          param_4 = param_4 + 1;
          iVar7 = (int)(short)(ushort)*pbVar15;
        }
        else {
          uVar13 = (uint)*param_4;
          iVar7 = (int)(short)(ushort)*param_4;
        }
      } while( true );
    }
    BUF_MEM_free(str);
  }
  return 0;
}

