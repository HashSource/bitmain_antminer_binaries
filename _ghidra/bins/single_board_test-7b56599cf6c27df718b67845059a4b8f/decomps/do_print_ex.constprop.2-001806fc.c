
int do_print_ex_constprop_2(BIO *param_1,uint param_2,_union_263 param_3)

{
  byte bVar1;
  size_t len;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte **ppbVar11;
  char *pcVar13;
  int iVar14;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  byte *pbVar18;
  byte **ppbVar19;
  byte *pbVar20;
  int local_68;
  uint local_64;
  char local_42;
  byte local_41;
  undefined4 local_40;
  byte *local_3c;
  byte local_38;
  byte local_37;
  ASN1_TYPE local_34 [2];
  byte **ppbVar12;
  
  uVar4 = param_2 & 0x40f;
  iVar14 = (param_3.asn1_string)->type;
  local_42 = '\0';
  if ((param_2 & 0x40) == 0) {
    local_68 = 0;
  }
  else {
    pcVar13 = ASN1_tag2str(iVar14);
    len = strlen(pcVar13);
    if (param_1 != (BIO *)0x0) {
      sVar2 = BIO_write(param_1,pcVar13,len);
      if (len != sVar2) {
        return -1;
      }
      iVar3 = BIO_write(param_1,":",1);
      if (iVar3 != 1) {
        return -1;
      }
    }
    local_68 = len + 1;
  }
  if ((int)(param_2 << 0x18) < 0) {
LAB_00180730:
    if (param_1 == (BIO *)0x0) {
      if ((int)(param_2 << 0x16) < 0) goto LAB_00180f92;
      pcVar13 = (char *)(param_3.asn1_string)->length;
    }
    else {
      iVar14 = BIO_write(param_1,&DAT_00224688,1);
      if (iVar14 != 1) {
        return -1;
      }
      if ((int)(param_2 << 0x16) < 0) {
LAB_00180f92:
        local_34[0].type = (param_3.asn1_string)->type;
        local_34[0].value = param_3;
        iVar14 = i2d_ASN1_TYPE(local_34,(uchar **)0x0);
        if (iVar14 < 1) {
          return -1;
        }
        pbVar16 = (byte *)CRYPTO_malloc(iVar14,"crypto/asn1/a_strex.c",0x11d);
        if (pbVar16 == (byte *)0x0) {
          ERR_put_error(0xd,0x7d,0x41,"crypto/asn1/a_strex.c",0x11e);
          return -1;
        }
        local_3c = pbVar16;
        i2d_ASN1_TYPE(local_34,&local_3c);
        if ((param_1 != (BIO *)0x0) && (pbVar16 != pbVar16 + iVar14)) {
          pbVar20 = pbVar16;
          do {
            pbVar17 = pbVar20 + 1;
            local_40 = CONCAT31(CONCAT21(local_40._2_2_,"0123456789ABCDEF"[*pbVar20 & 0xf]),
                                "0123456789ABCDEF"[*pbVar20 >> 4]);
            iVar3 = BIO_write(param_1,&local_40,2);
            if (iVar3 != 2) {
              CRYPTO_free(pbVar16);
              return -1;
            }
            pbVar20 = pbVar17;
          } while (pbVar16 + iVar14 != pbVar17);
        }
        iVar14 = iVar14 * 2;
        CRYPTO_free(pbVar16);
        if (iVar14 < 0) {
          return -1;
        }
        goto LAB_00180e74;
      }
      pbVar16 = (param_3.asn1_string)->data;
      pcVar13 = (param_3.object)->sn;
      if (pbVar16 + (int)pcVar13 != pbVar16) {
        pbVar20 = pbVar16;
        do {
          pbVar17 = pbVar20 + 1;
          local_34[0].type =
               CONCAT31(CONCAT21(local_34[0].type._2_2_,"0123456789ABCDEF"[*pbVar20 & 0xf]),
                        "0123456789ABCDEF"[*pbVar20 >> 4]);
          iVar14 = BIO_write(param_1,local_34,2);
          if (iVar14 != 2) {
            return -1;
          }
          pbVar20 = pbVar17;
        } while (pbVar16 + (int)pcVar13 != pbVar17);
      }
    }
    iVar14 = (int)pcVar13 << 1;
    if (iVar14 < 0) {
      return -1;
    }
LAB_00180e74:
    return local_68 + iVar14 + 1;
  }
  if ((int)(param_2 << 0x1a) < 0) {
LAB_001807ee:
    if ((int)(param_2 << 0x1b) < 0) {
      pbVar16 = (param_3.asn1_string)->data;
      bVar1 = 1;
      local_64 = (param_3.asn1_string)->length;
      bVar7 = 9;
      pbVar20 = pbVar16 + local_64;
    }
    else {
LAB_001807f4:
      local_64 = (param_3.asn1_string)->length;
      pbVar16 = (param_3.asn1_string)->data;
      bVar1 = 1;
      pbVar20 = pbVar16 + local_64;
      bVar7 = 0;
    }
LAB_00180806:
    if (pbVar16 == pbVar20) {
      iVar14 = 0;
    }
    else {
      iVar14 = 0;
      bVar6 = bVar7 & 8;
      pbVar17 = pbVar16;
      do {
        while( true ) {
          if (pbVar16 == pbVar17) {
            uVar10 = (param_2 & 1) << 5;
          }
          else {
            uVar10 = 0;
          }
          switch(bVar1) {
          case 0:
            iVar3 = UTF8_getc(pbVar17,local_64,&local_40);
            if (iVar3 < 0) {
              return -1;
            }
            local_64 = local_64 - iVar3;
            pbVar18 = pbVar17 + iVar3;
            break;
          case 1:
            local_40 = (ulong)*pbVar17;
            pbVar18 = pbVar17 + 1;
            break;
          case 2:
            pbVar18 = pbVar17 + 2;
            local_40 = (ulong)CONCAT11(*pbVar17,pbVar17[1]);
            if (pbVar18 == pbVar20) goto LAB_00180ac2;
            goto LAB_001808a2;
          default:
            goto LAB_00180750;
          case 4:
            pbVar18 = pbVar17 + 4;
            local_40 = (uint)*pbVar17 << 0x18 | (uint)pbVar17[1] << 0x10 | (uint)pbVar17[2] << 8 |
                       (uint)pbVar17[3];
          }
          if (pbVar18 != pbVar20) break;
LAB_00180ac2:
          if ((param_2 & 1) != 0) {
            uVar10 = 0x40;
          }
          if (bVar6 == 0) goto LAB_00180ad0;
LAB_001808a8:
          iVar3 = UTF8_putc((uchar *)&local_3c,6,local_40);
          if (0 < iVar3) {
            uVar10 = uVar10 | uVar4;
            uVar15 = (uint)local_3c & 0xff;
            if (uVar4 == 0) {
              if ((int)(uVar15 << 0x18) < 0) {
                uVar15 = param_2 & 4;
LAB_001808e6:
                if ((uVar15 & 0x406) == 0) {
                  iVar8 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar15 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar15 & 0x61) == 0) goto LAB_001808e6;
                if ((int)(uVar15 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 1) goto LAB_001809f0;
              uVar15 = (uint)local_3c >> 8 & 0xff;
              if ((int)(uVar15 << 0x18) < 0) {
                uVar15 = param_2 & 4;
LAB_00180ea6:
                if ((uVar15 & 0x406) == 0) {
                  iVar8 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar15 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar15 & 0x61) == 0) goto LAB_00180ea6;
                if ((int)(uVar15 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 2) goto LAB_001809f0;
              uVar15 = (uint)local_3c >> 0x10 & 0xff;
              if ((int)(uVar15 << 0x18) < 0) {
                uVar15 = param_2 & 4;
LAB_00180e84:
                if ((uVar15 & 0x406) == 0) {
                  iVar8 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar15 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar15 & 0x61) == 0) goto LAB_00180e84;
                if ((int)(uVar15 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 3) goto LAB_001809f0;
              if ((int)(((uint)local_3c >> 0x18) << 0x18) < 0) {
                uVar15 = param_2 & 4;
LAB_00180f0e:
                if ((uVar15 & 0x406) == 0) {
                  iVar8 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar15 = *(ushort *)(&char_type + ((uint)local_3c >> 0x18) * 2) & uVar10;
                if ((uVar15 & 0x61) == 0) goto LAB_00180f0e;
                if ((int)(uVar15 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 4) goto LAB_001809f0;
              if ((int)((uint)local_38 << 0x18) < 0) {
                uVar15 = param_2 & 4;
LAB_00180eec:
                if ((uVar15 & 0x406) == 0) {
                  iVar8 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar15 = *(ushort *)(&char_type + (uint)local_38 * 2) & uVar10;
                if ((uVar15 & 0x61) == 0) goto LAB_00180eec;
                if ((int)(uVar15 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 != 5) {
                if ((int)((uint)local_37 << 0x18) < 0) {
                  uVar10 = param_2 & 4;
                }
                else {
                  uVar10 = uVar10 & *(ushort *)(&char_type + (uint)local_37 * 2);
                  if ((uVar10 & 0x61) != 0) goto LAB_001809e2;
                }
                if ((uVar10 & 0x406) == 0) goto LAB_001809ee;
                BIO_snprintf((char *)local_34,0xb,"\\%02X");
                iVar14 = iVar14 + 3;
              }
            }
            else {
              if ((int)(uVar15 << 0x18) < 0) {
                uVar5 = param_2 & 4;
LAB_00180e14:
                if ((uVar5 & 0x406) == 0) {
                  if (uVar15 == 0x5c) {
                    iVar8 = 2;
                  }
                  else {
                    iVar8 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar5 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar5 & 0x61) == 0) goto LAB_00180e14;
                if ((int)(uVar5 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 1) goto LAB_001809f0;
              uVar15 = (uint)local_3c >> 8 & 0xff;
              if ((int)(uVar15 << 0x18) < 0) {
                uVar5 = param_2 & 4;
LAB_0018106c:
                if ((uVar5 & 0x406) == 0) {
                  if (uVar15 == 0x5c) {
                    iVar8 = 2;
                  }
                  else {
                    iVar8 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar5 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar5 & 0x61) == 0) goto LAB_0018106c;
                if ((int)(uVar5 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 2) goto LAB_001809f0;
              uVar15 = (uint)local_3c >> 0x10 & 0xff;
              if ((int)(uVar15 << 0x18) < 0) {
                uVar5 = param_2 & 4;
LAB_00181056:
                if ((uVar5 & 0x406) == 0) {
                  if (uVar15 == 0x5c) {
                    iVar8 = 2;
                  }
                  else {
                    iVar8 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar5 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar5 & 0x61) == 0) goto LAB_00181056;
                if ((int)(uVar5 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 3) goto LAB_001809f0;
              uVar15 = (uint)local_3c >> 0x18;
              if ((int)(uVar15 << 0x18) < 0) {
                uVar5 = param_2 & 4;
LAB_00181040:
                if ((uVar5 & 0x406) == 0) {
                  if (uVar15 == 0x5c) {
                    iVar8 = 2;
                  }
                  else {
                    iVar8 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar5 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar5 & 0x61) == 0) goto LAB_00181040;
                if ((int)(uVar5 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 4) goto LAB_001809f0;
              uVar15 = (uint)local_38;
              if ((int)(uVar15 << 0x18) < 0) {
                uVar5 = param_2 & 4;
LAB_0018102a:
                if ((uVar5 & 0x406) == 0) {
                  if (uVar15 == 0x5c) {
                    iVar8 = 2;
                  }
                  else {
                    iVar8 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar8 = 3;
                }
              }
              else {
                uVar5 = *(ushort *)(&char_type + uVar15 * 2) & uVar10;
                if ((uVar5 & 0x61) == 0) goto LAB_0018102a;
                if ((int)(uVar5 << 0x1c) < 0) {
                  iVar8 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar8 = 2;
                }
              }
              iVar14 = iVar14 + iVar8;
              if (iVar3 == 5) goto LAB_001809f0;
              uVar15 = (uint)local_37;
              if ((int)(uVar15 << 0x18) < 0) {
                uVar10 = param_2 & 4;
LAB_00180dd6:
                if ((uVar10 & 0x406) == 0) {
                  if (uVar15 == 0x5c) {
                    iVar3 = 2;
                  }
                  else {
                    iVar3 = 1;
                  }
                  iVar14 = iVar14 + iVar3;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar14 = iVar14 + 3;
                }
                goto LAB_001809f0;
              }
              uVar10 = uVar10 & *(ushort *)(&char_type + uVar15 * 2);
              if ((uVar10 & 0x61) == 0) goto LAB_00180dd6;
LAB_001809e2:
              if ((int)(uVar10 << 0x1c) < 0) {
                local_42 = '\x01';
LAB_001809ee:
                iVar14 = iVar14 + 1;
              }
              else {
                iVar14 = iVar14 + 2;
              }
            }
          }
LAB_001809f0:
          pbVar17 = pbVar18;
          if (pbVar18 == pbVar20) goto LAB_001809fc;
        }
LAB_001808a2:
        if (bVar6 != 0) goto LAB_001808a8;
LAB_00180ad0:
        iVar3 = do_esc_char_constprop_6(local_40,uVar4 | uVar10,&local_42,bVar6);
        if (iVar3 < 0) {
          return -1;
        }
        iVar14 = iVar14 + iVar3;
        pbVar17 = pbVar18;
      } while (pbVar18 != pbVar20);
    }
LAB_001809fc:
    local_68 = local_68 + iVar14;
    if (local_42 == '\0') {
      if (param_1 == (BIO *)0x0) {
        return local_68;
      }
    }
    else {
      local_68 = local_68 + 2;
      if (param_1 == (BIO *)0x0) {
        return local_68;
      }
      iVar14 = BIO_write(param_1,&DAT_0023dc34,1);
      if (iVar14 != 1) {
        return -1;
      }
    }
    pbVar16 = (param_3.asn1_string)->data;
    uVar10 = (param_3.asn1_string)->length;
    pbVar20 = pbVar16 + uVar10;
    if (bVar1 == 2) {
      if ((uVar10 & 1) != 0) {
LAB_00180e48:
        ERR_put_error(0xd,0x8e,0x81,"crypto/asn1/a_strex.c",0xa1);
        return -1;
      }
    }
    else if ((bVar1 == 4) && ((uVar10 & 3) != 0)) goto LAB_001807a2;
    if (pbVar16 != pbVar20) {
      bVar7 = bVar7 & 8;
      pbVar17 = pbVar16;
      do {
        if (pbVar16 == pbVar17) {
          uVar15 = (param_2 & 1) << 5;
        }
        else {
          uVar15 = 0;
        }
        switch(bVar1) {
        case 0:
          iVar14 = UTF8_getc(pbVar17,uVar10,&local_40);
          if (iVar14 < 0) {
            return -1;
          }
          uVar10 = uVar10 - iVar14;
          pbVar17 = pbVar17 + iVar14;
          break;
        case 1:
          local_40 = (ulong)*pbVar17;
          pbVar17 = pbVar17 + 1;
          break;
        case 2:
          local_40 = (ulong)CONCAT11(*pbVar17,pbVar17[1]);
          pbVar17 = pbVar17 + 2;
          break;
        default:
          goto LAB_00180750;
        case 4:
          local_40 = (uint)*pbVar17 << 0x18 | (uint)pbVar17[1] << 0x10 | (uint)pbVar17[2] << 8 |
                     (uint)pbVar17[3];
          pbVar17 = pbVar17 + 4;
        }
        if (pbVar20 == pbVar17) {
          if ((param_2 & 1) != 0) {
            uVar15 = 0x40;
          }
          if (bVar7 == 0) goto LAB_00180bee;
LAB_00180b4a:
          iVar14 = UTF8_putc((uchar *)&local_3c,6,local_40);
          if (0 < iVar14) {
            ppbVar19 = (byte **)((int)&local_3c + iVar14);
            ppbVar12 = &local_3c;
            do {
              while( true ) {
                ppbVar11 = (byte **)((int)ppbVar12 + 1);
                local_41 = *(byte *)ppbVar12;
                uVar9 = (uint)local_41;
                uVar5 = param_2 & 4;
                ppbVar12 = ppbVar11;
                if (((int)(uVar9 << 0x18) < 0) ||
                   (uVar5 = (uint)*(ushort *)(&char_type + uVar9 * 2) & (uVar15 | uVar4),
                   (uVar5 & 0x61) == 0)) break;
                if ((-1 < (int)(uVar5 << 0x1c)) &&
                   (iVar14 = BIO_write(param_1,&DAT_0022467c,1), iVar14 != 1)) {
                  return -1;
                }
LAB_00180b9a:
                iVar14 = BIO_write(param_1,&local_41,1);
                if (iVar14 != 1) {
                  return -1;
                }
LAB_00180baa:
                if (ppbVar11 == ppbVar19) goto LAB_00180bb2;
              }
              if ((uVar5 & 0x406) == 0) {
                if ((uVar9 != 0x5c) || (uVar4 == 0)) goto LAB_00180b9a;
                iVar14 = BIO_write(param_1,&DAT_00200360,2);
                if (iVar14 != 2) {
                  return -1;
                }
                goto LAB_00180baa;
              }
              BIO_snprintf((char *)local_34,0xb,"\\%02X");
              iVar14 = BIO_write(param_1,local_34,3);
              if (iVar14 != 3) {
                return -1;
              }
            } while (ppbVar11 != ppbVar19);
          }
        }
        else {
          if (bVar7 != 0) goto LAB_00180b4a;
LAB_00180bee:
          iVar14 = do_esc_char_constprop_6(local_40,uVar4 | uVar15,bVar7,param_1);
          if (iVar14 < 0) {
            return -1;
          }
        }
LAB_00180bb2:
      } while (pbVar20 != pbVar17);
    }
    if ((local_42 == '\0') || (iVar14 = BIO_write(param_1,&DAT_0023dc34,1), iVar14 == 1)) {
      return local_68;
    }
  }
  else {
    if ((0x1d < iVar14 - 1U) || (bVar1 = tag2nbyte[iVar14], bVar1 == 0xff)) {
      if ((int)(param_2 << 0x17) < 0) goto LAB_00180730;
      goto LAB_001807ee;
    }
    bVar7 = bVar1;
    if ((int)(param_2 << 0x1b) < 0) {
      if (bVar1 != 0) {
        bVar7 = bVar1 | 8;
        goto LAB_0018077e;
      }
      goto LAB_001807f4;
    }
LAB_0018077e:
    bVar1 = bVar1 & 7;
    local_64 = (param_3.asn1_string)->length;
    pbVar16 = (param_3.asn1_string)->data;
    pbVar20 = pbVar16 + local_64;
    if (bVar1 == 2) {
      if ((int)(local_64 << 0x1f) < 0) goto LAB_00180e48;
      goto LAB_00180806;
    }
    if ((bVar1 != 4) || ((local_64 & 3) == 0)) goto LAB_00180806;
LAB_001807a2:
    ERR_put_error(0xd,0x8e,0x85,"crypto/asn1/a_strex.c",0x9b);
  }
LAB_00180750:
  return -1;
}

