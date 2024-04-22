
/* WARNING: Type propagation algorithm not settling */

undefined4 def_load_bio(CONF *param_1,BIO *param_2,CONF_VALUE **param_3)

{
  ushort uVar1;
  ushort uVar2;
  byte *pbVar3;
  byte bVar4;
  BUF_MEM *str;
  int iVar5;
  lhash_st_CONF_VALUE *conf;
  int iVar6;
  size_t sVar7;
  uint uVar8;
  CONF_VALUE *value;
  CONF_VALUE *section;
  byte *pbVar9;
  lhash_st_CONF_VALUE *plVar10;
  void *pvVar11;
  byte *pbVar12;
  size_t sVar13;
  uint uVar15;
  char *pcVar16;
  byte *pbVar17;
  byte *pbVar18;
  byte *pbVar19;
  uint uVar20;
  bool bVar21;
  CONF_VALUE *local_54;
  CONF_VALUE *local_44;
  byte *local_3c;
  char acStack_38 [20];
  size_t sVar14;
  
  uVar15 = 0;
  plVar10 = param_1->data;
  local_3c = (byte *)0x0;
  str = BUF_MEM_new();
  if (str == (BUF_MEM *)0x0) {
    ERR_put_error(0xe,0x79,7,DAT_0010e45c,0xe0);
    value = (CONF_VALUE *)0x0;
    local_54 = (CONF_VALUE *)0x0;
    goto LAB_0010ddd0;
  }
  local_3c = (byte *)CRYPTO_malloc(10,DAT_0010e05c,0xe4);
  if (local_3c == (byte *)0x0) {
    iVar5 = 0xe6;
LAB_0010ddba:
    value = (CONF_VALUE *)0x0;
    ERR_put_error(0xe,0x79,0x41,DAT_0010e05c,iVar5);
    local_54 = value;
  }
  else {
    BUF_strlcpy((char *)local_3c,DAT_0010e060,10);
    iVar5 = _CONF_new_data(param_1);
    if (iVar5 == 0) {
      iVar5 = 0xec;
      goto LAB_0010ddba;
    }
    local_44 = _CONF_new_section(param_1,(char *)local_3c);
    if (local_44 == (CONF_VALUE *)0x0) {
      ERR_put_error(0xe,0x79,0x67,DAT_0010e45c,0xf2);
      value = (CONF_VALUE *)0x0;
      local_54 = (CONF_VALUE *)0x0;
    }
    else {
      iVar5 = 0;
      local_54 = (CONF_VALUE *)0x0;
      while (iVar6 = BUF_MEM_grow(str,iVar5 + 0x200), iVar6 != 0) {
        pcVar16 = str->data + iVar5;
        str->data[iVar5] = '\0';
        BIO_gets(param_2,pcVar16,0x1ff);
        pcVar16[0x1ff] = '\0';
        sVar7 = strlen(pcVar16);
        if ((uVar15 | sVar7) == 0) {
          BUF_MEM_free(str);
          if (local_3c != (byte *)0x0) {
            CRYPTO_free(local_3c);
            return 1;
          }
          return 1;
        }
        if ((int)sVar7 < 1) {
          bVar21 = true;
          sVar13 = sVar7;
LAB_0010e0da:
          if (sVar7 == 0) {
            bVar21 = false;
          }
          sVar7 = sVar13;
          if (bVar21) goto LAB_0010e0ea;
LAB_0010deac:
          bVar21 = false;
          pcVar16[sVar13] = '\0';
          local_54 = (CONF_VALUE *)((int)&local_54->section + 1);
        }
        else {
          sVar14 = sVar7;
          if (pcVar16[sVar7 - 1] == '\n' || pcVar16[sVar7 - 1] == '\r') {
            do {
              sVar13 = sVar14 - 1;
              if (sVar13 == 0) goto LAB_0010deac;
              iVar6 = sVar14 - 2;
              sVar14 = sVar13;
            } while (pcVar16[iVar6] == '\n' || pcVar16[iVar6] == '\r');
            bVar21 = sVar7 == sVar13;
            goto LAB_0010e0da;
          }
LAB_0010e0ea:
          bVar21 = true;
          sVar13 = sVar7;
        }
        iVar6 = iVar5 + sVar13;
        if (iVar6 < 1) {
LAB_0010deec:
          iVar5 = iVar6;
          if (bVar21) goto LAB_0010dee8;
          pbVar18 = (byte *)str->data;
          pvVar11 = param_1->meth_data;
          uVar15 = (uint)*pbVar18;
          iVar5 = (int)(short)(ushort)*pbVar18;
          uVar1 = *(ushort *)((int)pvVar11 + iVar5 * 2);
          pbVar19 = pbVar18;
          uVar20 = uVar15;
          iVar6 = iVar5;
          uVar2 = uVar1;
          while ((uVar2 & 0x800) == 0) {
            if ((uVar2 & 0x10) == 0) goto LAB_0010dfe8;
            pbVar19 = pbVar19 + 1;
            uVar20 = (uint)*pbVar19;
            iVar6 = (int)(short)(ushort)*pbVar19;
            uVar2 = *(ushort *)((int)pvVar11 + iVar6 * 2);
          }
LAB_0010df30:
          *pbVar19 = 0;
          uVar15 = (uint)*pbVar18;
          pvVar11 = param_1->meth_data;
          iVar5 = (int)(short)(ushort)*pbVar18;
          uVar1 = *(ushort *)((int)pvVar11 + iVar5 * 2);
joined_r0x0010df48:
          while ((uVar1 & 0x18) == 0x10) {
            pbVar18 = pbVar18 + 1;
            uVar15 = (uint)*pbVar18;
            iVar5 = (int)(short)(ushort)*pbVar18;
            uVar1 = *(ushort *)((int)pvVar11 + iVar5 * 2);
          }
          if ((uVar1 & 8) == 0) {
            pbVar19 = pbVar18;
            if (uVar15 != 0x5b) {
              while( true ) {
                while( true ) {
                  uVar2 = *(ushort *)((int)pvVar11 + iVar5 * 2);
                  uVar20 = (uint)uVar2;
                  pbVar9 = (byte *)(uVar20 & 0x307);
                  if ((uVar2 & 0x20) == 0) break;
                  bVar4 = pbVar19[1];
                  iVar5 = (int)(short)(ushort)bVar4;
                  bVar21 = -1 < (int)((uint)*(ushort *)((int)pvVar11 + iVar5 * 2) << 0x1c);
                  if (bVar21) {
                    bVar4 = pbVar19[2];
                  }
                  uVar15 = (uint)bVar4;
                  if (bVar21) {
                    pbVar19 = pbVar19 + 2;
                    iVar5 = (int)(short)(ushort)bVar4;
                  }
                  else {
                    pbVar19 = pbVar19 + 1;
                  }
                }
                if ((uVar2 & 0x307) == 0) break;
                uVar15 = (uint)pbVar19[1];
                iVar5 = (int)(short)(ushort)pbVar19[1];
                pbVar19 = pbVar19 + 1;
              }
              pbVar17 = pbVar18;
              if ((uVar15 == 0x3a) && (pbVar19[1] == 0x3a)) {
                pbVar17 = pbVar19 + 2;
                *pbVar19 = (byte)pbVar9;
                pvVar11 = param_1->meth_data;
                uVar15 = (uint)pbVar19[2];
                uVar2 = *(ushort *)((int)pvVar11 + uVar15 * 2);
                pbVar19 = pbVar17;
                while( true ) {
                  uVar20 = (uint)uVar2;
                  if ((uVar2 & 0x20) != 0) {
                    do {
                      uVar15 = (uint)pbVar19[1];
                      uVar20 = (uint)*(ushort *)((int)pvVar11 + uVar15 * 2);
                      if ((int)(uVar20 << 0x1c) < 0) {
                        pbVar19 = pbVar19 + 1;
                      }
                      else {
                        uVar15 = (uint)pbVar19[2];
                        pbVar19 = pbVar19 + 2;
                        uVar20 = (uint)*(ushort *)((int)pvVar11 + uVar15 * 2);
                      }
                    } while ((uVar20 & 0x20) != 0);
                  }
                  pbVar9 = pbVar18;
                  if ((uVar20 & 0x307) == 0) break;
                  uVar15 = (uint)pbVar19[1];
                  pbVar19 = pbVar19 + 1;
                  uVar2 = *(ushort *)((int)pvVar11 + uVar15 * 2);
                }
              }
              pbVar18 = pbVar19;
              if ((uVar20 & 0x18) == 0x10) {
                do {
                  pbVar18 = pbVar18 + 1;
                  uVar15 = (uint)*pbVar18;
                } while ((*(ushort *)((int)pvVar11 + uVar15 * 2) & 0x18) == 0x10);
              }
              if (uVar15 == 0x3d) {
                *pbVar19 = 0;
                pbVar12 = pbVar18 + 1;
                pvVar11 = param_1->meth_data;
                uVar2 = *(ushort *)((int)pvVar11 + (uint)pbVar18[1] * 2);
                pbVar19 = pbVar12;
                if ((uVar2 & 0x18) == 0x10) {
                  pbVar3 = pbVar18 + 2;
                  do {
                    pbVar19 = pbVar3;
                    pbVar3 = pbVar19 + 1;
                  } while ((*(ushort *)((int)pvVar11 + (uint)*pbVar19 * 2) & 0x18) == 0x10);
                }
                if ((uVar2 & 8) == 0) {
                  pbVar18 = pbVar18 + 2;
                  do {
                    pbVar12 = pbVar18;
                    pbVar18 = pbVar12 + 1;
                  } while (-1 < (int)((uint)*(ushort *)((int)pvVar11 + (uint)*pbVar12 * 2) << 0x1c))
                  ;
                }
                pbVar18 = pbVar12 + -1;
                if ((pbVar18 != pbVar19) &&
                   ((int)((uint)*(ushort *)((int)pvVar11 + (uint)pbVar12[-1] * 2) << 0x1b) < 0)) {
                  pbVar12 = pbVar12 + -2;
                  do {
                    pbVar18 = pbVar12;
                    if (pbVar18 == pbVar19) break;
                    pbVar12 = pbVar18 + -1;
                  } while ((int)((uint)*(ushort *)((int)pvVar11 + (uint)*pbVar18 * 2) << 0x1b) < 0);
                }
                pbVar18[1] = 0;
                value = (CONF_VALUE *)CRYPTO_malloc(0xc,DAT_0010e45c,0x168);
                if (value == (CONF_VALUE *)0x0) {
                  iVar5 = 0x169;
                }
                else {
                  if (pbVar9 == (byte *)0x0) {
                    pbVar9 = local_3c;
                  }
                  sVar7 = strlen((char *)pbVar17);
                  pcVar16 = (char *)CRYPTO_malloc(sVar7 + 1,DAT_0010e45c,0x16e);
                  value->value = (char *)0x0;
                  value->name = pcVar16;
                  if (pcVar16 == (char *)0x0) {
                    iVar5 = 0x171;
                  }
                  else {
                    sVar7 = strlen((char *)pbVar17);
                    BUF_strlcpy(pcVar16,(char *)pbVar17,sVar7 + 1);
                    iVar5 = str_copy(param_1,pbVar9,&value->value,pbVar19);
                    if (iVar5 == 0) goto LAB_0010ddca;
                    iVar5 = strcmp((char *)pbVar9,(char *)local_3c);
                    section = local_44;
                    if (((iVar5 != 0) &&
                        (section = _CONF_get_section(param_1,(char *)pbVar9),
                        section == (CONF_VALUE *)0x0)) &&
                       (section = _CONF_new_section(param_1,(char *)pbVar9),
                       section == (CONF_VALUE *)0x0)) {
                      ERR_put_error(0xe,0x79,0x67,DAT_0010e45c,0x17e);
                      goto LAB_0010ddca;
                    }
                    iVar5 = _CONF_add_string(param_1,section,value);
                    if (iVar5 != 0) goto LAB_0010e23c;
                    iVar5 = 0x185;
                  }
                }
                ERR_put_error(0xe,0x79,0x41,DAT_0010e45c,iVar5);
              }
              else {
                ERR_put_error(0xe,0x79,0x65,DAT_0010e45c,0x15a);
                value = (CONF_VALUE *)0x0;
              }
              goto LAB_0010ddca;
            }
            bVar4 = pbVar18[1];
            pbVar17 = pbVar18 + 1;
            iVar5 = (int)(short)(ushort)bVar4;
            pbVar19 = pbVar17;
            pbVar9 = pbVar17;
            if ((*(ushort *)((int)pvVar11 + iVar5 * 2) & 0x18) == 0x10) {
              pbVar18 = pbVar18 + 2;
              do {
                pbVar17 = pbVar18;
                bVar4 = *pbVar17;
                iVar5 = (int)(short)(ushort)bVar4;
                pbVar18 = pbVar17 + 1;
                pbVar19 = pbVar17;
                pbVar9 = pbVar17;
              } while ((*(ushort *)((int)pvVar11 + iVar5 * 2) & 0x18) == 0x10);
            }
            while( true ) {
              while( true ) {
                while( true ) {
                  uVar2 = *(ushort *)((int)pvVar11 + iVar5 * 2);
                  if ((uVar2 & 0x20) == 0) break;
                  bVar4 = pbVar19[1];
                  iVar5 = (int)(short)(ushort)bVar4;
                  if ((int)((uint)*(ushort *)((int)pvVar11 + iVar5 * 2) << 0x1c) < 0) {
                    pbVar19 = pbVar19 + 1;
                  }
                  else {
                    bVar4 = pbVar19[2];
                    pbVar19 = pbVar19 + 2;
                    iVar5 = (int)(short)(ushort)bVar4;
                  }
                }
                pbVar18 = pbVar19;
                if ((uVar2 & 0x307) == 0) break;
                bVar4 = pbVar19[1];
                iVar5 = (int)(short)(ushort)bVar4;
                pbVar19 = pbVar19 + 1;
              }
              while ((uVar2 & 0x18) == 0x10) {
                bVar4 = pbVar18[1];
                iVar5 = (int)(short)(ushort)bVar4;
                pbVar18 = pbVar18 + 1;
                uVar2 = *(ushort *)((int)pvVar11 + iVar5 * 2);
              }
              if (bVar4 == 0x5d) break;
              if ((bVar4 == 0) ||
                 (bVar21 = pbVar9 == pbVar18, pbVar19 = pbVar18, pbVar9 = pbVar18, bVar21)) {
                ERR_put_error(0xe,0x79,100,DAT_0010e45c,0x13f);
                value = (CONF_VALUE *)0x0;
                goto LAB_0010ddca;
              }
            }
            *pbVar19 = 0;
            iVar5 = str_copy(param_1,0,&local_3c,pbVar17);
            if (iVar5 == 0) {
              value = (CONF_VALUE *)0x0;
              goto LAB_0010ddca;
            }
            local_44 = _CONF_get_section(param_1,(char *)local_3c);
            if ((local_44 == (CONF_VALUE *)0x0) &&
               (local_44 = _CONF_new_section(param_1,(char *)local_3c),
               local_44 == (CONF_VALUE *)0x0)) {
              ERR_put_error(0xe,0x79,0x67,DAT_0010e45c,0x149);
              value = (CONF_VALUE *)0x0;
              goto LAB_0010ddca;
            }
          }
LAB_0010e23c:
          iVar5 = 0;
          uVar15 = 0;
        }
        else {
          iVar5 = iVar6 + -1;
          if ((-1 < (int)((uint)*(ushort *)
                                 ((int)param_1->meth_data + (uint)(byte)str->data[iVar5] * 2) <<
                         0x1a)) ||
             ((iVar6 != 1 &&
              ((int)((uint)*(ushort *)
                            ((int)param_1->meth_data + (uint)(byte)str->data[iVar6 + -2] * 2) <<
                    0x1a) < 0)))) goto LAB_0010deec;
LAB_0010dee8:
          uVar15 = 1;
        }
      }
      ERR_put_error(0xe,0x79,7,DAT_0010e45c,0xfa);
      value = (CONF_VALUE *)0x0;
    }
  }
LAB_0010ddca:
  BUF_MEM_free(str);
LAB_0010ddd0:
  if (local_3c != (byte *)0x0) {
    CRYPTO_free(local_3c);
  }
  if (param_3 != (CONF_VALUE **)0x0) {
    *param_3 = local_54;
  }
  BIO_snprintf(acStack_38,0xd,DAT_0010e064,local_54);
  ERR_add_error_data(2,DAT_0010e068,acStack_38);
  conf = param_1->data;
  if ((conf != plVar10) && (conf != (lhash_st_CONF_VALUE *)0x0)) {
    CONF_free(conf);
    param_1->data = (lhash_st_CONF_VALUE *)0x0;
  }
  if (value != (CONF_VALUE *)0x0) {
    if (value->name != (char *)0x0) {
      CRYPTO_free(value->name);
    }
    if (value->value != (char *)0x0) {
      CRYPTO_free(value->value);
    }
    CRYPTO_free(value);
  }
  return 0;
LAB_0010dfe8:
  uVar2 = *(ushort *)((int)pvVar11 + iVar6 * 2);
  uVar8 = uVar20;
  if ((uVar2 & 0x80) == 0) {
    while ((uVar2 & 0x400) == 0) {
      if ((uVar2 & 0x40) != 0) {
        uVar20 = (uint)pbVar19[1];
        uVar2 = *(ushort *)((int)pvVar11 + uVar20 * 2);
        pbVar9 = pbVar19;
        goto joined_r0x0010e0fc;
      }
      if (-1 < (int)((uint)uVar2 << 0x1a)) {
        if ((int)((uint)uVar2 << 0x1c) < 0) goto joined_r0x0010df48;
        goto LAB_0010e0c2;
      }
      bVar4 = pbVar19[1];
      iVar6 = (int)(short)(ushort)bVar4;
      bVar21 = (*(ushort *)((int)pvVar11 + iVar6 * 2) & 8) == 0;
      if (bVar21) {
        bVar4 = pbVar19[2];
      }
      uVar8 = (uint)bVar4;
      if (bVar21) {
        pbVar19 = pbVar19 + 2;
        iVar6 = (int)(short)(ushort)bVar4;
      }
      else {
        pbVar19 = pbVar19 + 1;
      }
      uVar2 = *(ushort *)((int)pvVar11 + iVar6 * 2);
      if ((uVar2 & 0x80) != 0) goto LAB_0010df30;
    }
    uVar20 = (uint)pbVar19[1];
    uVar2 = *(ushort *)((int)pvVar11 + uVar20 * 2);
    pbVar9 = pbVar19;
    while (pbVar19 = pbVar9 + 1, -1 < (int)((uint)uVar2 << 0x1c)) {
      pbVar9 = pbVar19;
      if (uVar8 == uVar20) {
        uVar20 = (uint)pbVar19[1];
        pbVar9 = pbVar19 + 1;
        if (uVar8 != uVar20) {
          iVar6 = (int)(short)(ushort)pbVar19[1];
          pbVar19 = pbVar19 + 1;
          goto LAB_0010dfe8;
        }
      }
      uVar20 = (uint)pbVar9[1];
      uVar2 = *(ushort *)((int)pvVar11 + uVar20 * 2);
    }
    if (uVar8 == uVar20) {
LAB_0010e0c2:
      uVar20 = (uint)pbVar19[1];
      iVar6 = (int)(short)(ushort)pbVar19[1];
      pbVar19 = pbVar19 + 1;
    }
    else {
      uVar20 = (uint)*pbVar19;
      iVar6 = (int)(short)(ushort)*pbVar19;
    }
    goto LAB_0010dfe8;
  }
  goto LAB_0010df30;
joined_r0x0010e0fc:
  pbVar9 = pbVar9 + 1;
  if ((int)((uint)uVar2 << 0x1c) < 0) goto LAB_0010dfda;
  if (uVar8 == uVar20) goto LAB_0010e242;
  pbVar19 = pbVar9 + 1;
  if ((uVar2 & 0x20) != 0) {
    uVar20 = (uint)pbVar9[1];
    iVar6 = (int)(short)(ushort)pbVar9[1];
    pbVar9 = pbVar19;
    if ((*(ushort *)((int)pvVar11 + iVar6 * 2) & 8) != 0) goto LAB_0010dfe8;
  }
  uVar20 = (uint)pbVar9[1];
  uVar2 = *(ushort *)((int)pvVar11 + uVar20 * 2);
  goto joined_r0x0010e0fc;
LAB_0010dfda:
  if (uVar8 == uVar20) {
LAB_0010e242:
    uVar20 = (uint)pbVar9[1];
    pbVar19 = pbVar9 + 1;
    iVar6 = (int)(short)(ushort)pbVar9[1];
  }
  else {
    uVar20 = (uint)*pbVar9;
    iVar6 = (int)(short)(ushort)*pbVar9;
    pbVar19 = pbVar9;
  }
  goto LAB_0010dfe8;
}

