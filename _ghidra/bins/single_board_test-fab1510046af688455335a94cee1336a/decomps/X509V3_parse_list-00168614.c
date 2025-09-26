
stack_st_CONF_VALUE * X509V3_parse_list(char *line)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *ptr;
  ushort **ppuVar3;
  size_t sVar4;
  uint uVar5;
  byte *__s;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  ushort *puVar9;
  _STACK *local_24;
  
  local_24 = (_STACK *)0x0;
  ptr = (byte *)BUF_strdup(line);
  if (ptr == (byte *)0x0) {
    ERR_put_error(0x22,0x6d,0x41,"v3_utl.c",0x121);
    goto LAB_0016884a;
  }
  uVar5 = (uint)*ptr;
  if (uVar5 != 0) {
    __s = ptr;
    if (uVar5 != 0xd && uVar5 != 10) {
      pbVar8 = (byte *)0x0;
      iVar7 = 1;
      pbVar1 = ptr;
      do {
        pbVar6 = pbVar1 + 1;
        if (iVar7 == 1) {
          if (uVar5 == 0x3a) {
            *pbVar1 = 0;
            uVar5 = (uint)*__s;
            if (uVar5 != 0) {
              ppuVar3 = __ctype_b_loc();
              puVar9 = *ppuVar3;
              while ((int)((uint)puVar9[uVar5] << 0x12) < 0) {
                __s = __s + 1;
                uVar5 = (uint)*__s;
                if (uVar5 == 0) goto LAB_0016885c;
              }
              sVar4 = strlen((char *)__s);
              pbVar1 = __s + (sVar4 - 1);
              do {
                pbVar8 = pbVar1;
                if (pbVar8 == __s) goto LAB_0016880c;
                pbVar1 = pbVar8 + -1;
              } while ((puVar9[*pbVar8] & 0x2000) != 0);
              if (pbVar8 != __s) {
                pbVar8[1] = 0;
              }
LAB_0016880c:
              if (*__s != 0) {
                iVar7 = 2;
                pbVar8 = __s;
                __s = pbVar6;
                goto LAB_00168650;
              }
            }
LAB_0016885c:
            iVar7 = 0x132;
            goto LAB_00168860;
          }
          if (uVar5 != 0x2c) goto LAB_00168650;
          *pbVar1 = 0;
          uVar5 = (uint)*__s;
          if (uVar5 != 0) {
            ppuVar3 = __ctype_b_loc();
            puVar9 = *ppuVar3;
            while ((int)((uint)puVar9[uVar5] << 0x12) < 0) {
              __s = __s + 1;
              uVar5 = (uint)*__s;
              if (uVar5 == 0) goto LAB_00168870;
            }
            sVar4 = strlen((char *)__s);
            pbVar1 = __s + (sVar4 - 1);
            do {
              pbVar8 = pbVar1;
              if (pbVar8 == __s) goto LAB_001686ca;
              pbVar1 = pbVar8 + -1;
            } while ((puVar9[*pbVar8] & 0x2000) != 0);
            pbVar8[1] = 0;
LAB_001686ca:
            if (*__s != 0) {
              X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)&local_24);
              uVar5 = (uint)*pbVar6;
              pbVar8 = __s;
              __s = pbVar6;
              if (uVar5 != 0) goto LAB_00168656;
              break;
            }
          }
LAB_00168870:
          iVar7 = 0x13f;
          goto LAB_00168860;
        }
        if ((iVar7 == 2) && (uVar5 == 0x2c)) {
          *pbVar1 = 0;
          uVar5 = (uint)*__s;
          if (uVar5 != 0) {
            ppuVar3 = __ctype_b_loc();
            puVar9 = *ppuVar3;
            while ((int)((uint)puVar9[uVar5] << 0x12) < 0) {
              __s = __s + 1;
              uVar5 = (uint)*__s;
              if (uVar5 == 0) goto LAB_00168838;
            }
            sVar4 = strlen((char *)__s);
            pbVar1 = __s + (sVar4 - 1);
            do {
              pbVar2 = pbVar1;
              if (pbVar2 == __s) goto LAB_0016879c;
              pbVar1 = pbVar2 + -1;
            } while ((puVar9[*pbVar2] & 0x2000) != 0);
            if (__s != pbVar2) {
              pbVar2[1] = 0;
            }
LAB_0016879c:
            if (*__s != 0) {
              X509V3_add_value((char *)pbVar8,(char *)__s,(stack_st_CONF_VALUE **)&local_24);
              iVar7 = 1;
              pbVar8 = (byte *)0x0;
              __s = pbVar6;
              goto LAB_00168650;
            }
          }
LAB_00168838:
          iVar7 = 0x150;
          goto LAB_0016883c;
        }
LAB_00168650:
        uVar5 = (uint)*pbVar6;
        if (uVar5 == 0) break;
LAB_00168656:
        pbVar1 = pbVar6;
      } while (uVar5 != 10 && uVar5 != 0xd);
      uVar5 = (uint)*__s;
      if (iVar7 == 2) {
        if (uVar5 != 0) {
          ppuVar3 = __ctype_b_loc();
          puVar9 = *ppuVar3;
          do {
            if (-1 < (int)((uint)puVar9[uVar5] << 0x12)) {
              sVar4 = strlen((char *)__s);
              pbVar1 = __s + (sVar4 - 1);
              goto joined_r0x001688a2;
            }
            __s = __s + 1;
            uVar5 = (uint)*__s;
          } while (uVar5 != 0);
        }
        goto LAB_001688d6;
      }
      if (uVar5 == 0) goto LAB_00168876;
    }
    ppuVar3 = __ctype_b_loc();
    puVar9 = *ppuVar3;
    do {
      if (-1 < (int)((uint)puVar9[uVar5] << 0x12)) {
        sVar4 = strlen((char *)__s);
        pbVar1 = __s + (sVar4 - 1);
        goto joined_r0x0016871e;
      }
      __s = __s + 1;
      uVar5 = (uint)*__s;
    } while (uVar5 != 0);
  }
  goto LAB_00168876;
  while (pbVar1 = pbVar6 + -1, (puVar9[*pbVar6] & 0x2000) != 0) {
joined_r0x001688a2:
    pbVar6 = pbVar1;
    if (pbVar6 == __s) goto LAB_001688c4;
  }
  if (pbVar6 != __s) {
    pbVar6[1] = 0;
  }
LAB_001688c4:
  if (*__s != 0) {
    X509V3_add_value((char *)pbVar8,(char *)__s,(stack_st_CONF_VALUE **)&local_24);
    goto LAB_00168752;
  }
LAB_001688d6:
  iVar7 = 0x162;
LAB_0016883c:
  ERR_put_error(0x22,0x6d,0x6d,"v3_utl.c",iVar7);
  goto LAB_0016884a;
  while (pbVar1 = pbVar8 + -1, (puVar9[*pbVar8] & 0x2000) != 0) {
joined_r0x0016871e:
    pbVar8 = pbVar1;
    if (pbVar8 == __s) goto LAB_00168740;
  }
  if (pbVar8 != __s) {
    pbVar8[1] = 0;
  }
LAB_00168740:
  if (*__s != 0) {
    X509V3_add_value((char *)__s,(char *)0x0,(stack_st_CONF_VALUE **)&local_24);
LAB_00168752:
    CRYPTO_free(ptr);
    return (stack_st_CONF_VALUE *)local_24;
  }
LAB_00168876:
  iVar7 = 0x16c;
LAB_00168860:
  ERR_put_error(0x22,0x6d,0x6c,"v3_utl.c",iVar7);
LAB_0016884a:
  CRYPTO_free(ptr);
  sk_pop_free(local_24,(func *)0x167909);
  return (stack_st_CONF_VALUE *)0x0;
}

