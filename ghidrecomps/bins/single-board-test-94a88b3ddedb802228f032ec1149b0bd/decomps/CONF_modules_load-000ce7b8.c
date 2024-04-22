
int CONF_modules_load(CONF *cnf,char *appname,ulong flags)

{
  bool bVar1;
  _STACK **pp_Var2;
  char *pcVar3;
  _STACK *p_Var4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  DSO *pDVar8;
  DSO *pDVar9;
  DSO *pDVar10;
  DSO **data;
  DSO *pDVar11;
  _STACK *p_Var12;
  void **data_00;
  char *__s;
  int iVar13;
  size_t __n;
  char *group;
  char acStack_38 [20];
  
  if (cnf == (CONF *)0x0) {
    return 1;
  }
  if (appname != (char *)0x0) {
    pcVar3 = NCONF_get_string(cnf,(char *)0x0,appname);
    if (pcVar3 != (char *)0x0) goto LAB_000ce7da;
    if (-1 < (int)(flags << 0x1a)) goto LAB_000cea4a;
  }
  pcVar3 = NCONF_get_string(cnf,(char *)0x0,DAT_000ceaac);
  if (pcVar3 == (char *)0x0) {
LAB_000cea4a:
    ERR_clear_error();
    return 1;
  }
LAB_000ce7da:
  p_Var4 = &NCONF_get_section(cnf,pcVar3)->stack;
  if (p_Var4 == (_STACK *)0x0) {
    return 0;
  }
  iVar13 = 0;
  iVar5 = sk_num(p_Var4);
  pp_Var2 = DAT_000cea88;
  if (0 < iVar5) {
    do {
      pvVar6 = sk_value(p_Var4,iVar13);
      __s = *(char **)((int)pvVar6 + 4);
      group = *(char **)((int)pvVar6 + 8);
      pcVar3 = strrchr(__s,0x2e);
      if (pcVar3 == (char *)0x0) {
        __n = strlen(__s);
      }
      else {
        __n = (int)pcVar3 - (int)__s;
      }
      iVar5 = 0;
      do {
        iVar7 = sk_num(*pp_Var2);
        if (iVar7 <= iVar5) {
          if ((flags & 8) == 0) {
            pcVar3 = NCONF_get_string(cnf,group,DAT_000cea8c);
            if (pcVar3 == (char *)0x0) {
              ERR_clear_error();
              pcVar3 = __s;
            }
            pDVar8 = DSO_load((DSO *)0x0,pcVar3,(DSO_METHOD *)0x0,0);
            if (pDVar8 == (DSO *)0x0) {
              iVar5 = 0x6e;
            }
            else {
              pDVar9 = (DSO *)DSO_bind_func(pDVar8,DAT_000cea90);
              if (pDVar9 == (DSO *)0x0) {
                iVar5 = 0x70;
              }
              else {
                pDVar10 = (DSO *)DSO_bind_func(pDVar8,DAT_000cea94);
                if (*pp_Var2 == (_STACK *)0x0) {
                  p_Var12 = sk_new_null();
                  *pp_Var2 = p_Var12;
                  if (p_Var12 != (_STACK *)0x0) goto LAB_000ce8c4;
                }
                else {
LAB_000ce8c4:
                  data = (DSO **)CRYPTO_malloc(0x18,DAT_000cea98,0x11d);
                  if (data != (DSO **)0x0) {
                    *data = pDVar8;
                    pDVar11 = (DSO *)BUF_strdup(__s);
                    data[1] = pDVar11;
                    data[4] = (DSO *)0x0;
                    data[2] = pDVar9;
                    p_Var12 = *pp_Var2;
                    data[3] = pDVar10;
                    iVar5 = sk_push(p_Var12,data);
                    if (iVar5 != 0) break;
                    CRYPTO_free(data);
                  }
                }
                iVar5 = 0;
              }
              DSO_free(pDVar8);
            }
            ERR_put_error(0xe,0x75,iVar5,DAT_000cea98,0x10f);
            ERR_add_error_data(4,DAT_000ceaa4,__s,DAT_000ceab0,pcVar3);
          }
          if ((flags & 4) == 0) {
            ERR_put_error(0xe,0x76,0x71,DAT_000cea98,0xd4);
            ERR_add_error_data(2,DAT_000ceaa4,__s);
          }
          goto joined_r0x000ce864;
        }
        data = (DSO **)sk_value(*pp_Var2,iVar5);
        iVar7 = strncmp((char *)data[1],__s,__n);
        iVar5 = iVar5 + 1;
      } while (iVar7 != 0);
      data_00 = (void **)CRYPTO_malloc(0x14,DAT_000cea98,0x154);
      if (data_00 == (void **)0x0) {
LAB_000ce9a0:
        if ((flags & 4) == 0) {
          ERR_put_error(0xe,0x76,0x6d,DAT_000cea98,0xdf);
          BIO_snprintf(acStack_38,0xd,DAT_000cea9c,0xffffffff);
          ERR_add_error_data(6,DAT_000ceaa4,__s,DAT_000ceaa8,group,DAT_000ceaa0,acStack_38);
        }
joined_r0x000ce864:
        if ((flags & 1) == 0) {
          return -1;
        }
      }
      else {
        *data_00 = data;
        pcVar3 = BUF_strdup(__s);
        data_00[1] = pcVar3;
        pcVar3 = BUF_strdup(group);
        pvVar6 = data_00[1];
        data_00[2] = pcVar3;
        data_00[4] = (void *)0x0;
        if (pvVar6 == (void *)0x0) {
LAB_000ce994:
          if (pcVar3 != (char *)0x0) {
            CRYPTO_free(pcVar3);
          }
          CRYPTO_free(data_00);
          goto LAB_000ce9a0;
        }
        if (pcVar3 == (char *)0x0) {
LAB_000ce98a:
          CRYPTO_free(pvVar6);
LAB_000ce990:
          pcVar3 = (char *)data_00[2];
          goto LAB_000ce994;
        }
        if (data[2] != (DSO *)0x0) {
          iVar5 = (*(code *)data[2])(data_00,cnf);
          if (0 < iVar5) {
            bVar1 = true;
            p_Var12 = pp_Var2[1];
            goto joined_r0x000ce950;
          }
          pDVar8 = data[3];
          if (pDVar8 == (DSO *)0x0) goto LAB_000ce97e;
LAB_000ce9fc:
          (*(code *)pDVar8)(data_00);
LAB_000ce984:
          pvVar6 = data_00[1];
          if (pvVar6 != (void *)0x0) goto LAB_000ce98a;
          goto LAB_000ce990;
        }
        p_Var12 = pp_Var2[1];
        bVar1 = false;
joined_r0x000ce950:
        if (p_Var12 == (_STACK *)0x0) {
          p_Var12 = sk_new_null();
          iVar5 = 0x16c;
          pp_Var2[1] = p_Var12;
          if (p_Var12 != (_STACK *)0x0) goto LAB_000ce952;
LAB_000ce966:
          ERR_put_error(0xe,0x73,0x41,DAT_000cea98,iVar5);
          pDVar8 = data[3];
          if ((pDVar8 != (DSO *)0x0) && (bVar1)) goto LAB_000ce9fc;
LAB_000ce97e:
          if (data_00 == (void **)0x0) goto LAB_000ce9a0;
          goto LAB_000ce984;
        }
LAB_000ce952:
        iVar5 = sk_push(p_Var12,data_00);
        if (iVar5 == 0) {
          iVar5 = 0x172;
          goto LAB_000ce966;
        }
        data[4] = (DSO *)((int)&data[4]->meth + 1);
      }
      iVar13 = iVar13 + 1;
      iVar5 = sk_num(p_Var4);
    } while (iVar13 < iVar5);
  }
  return 1;
}

