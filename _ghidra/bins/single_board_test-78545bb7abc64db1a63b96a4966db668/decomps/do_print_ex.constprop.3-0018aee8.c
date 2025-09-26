
int do_print_ex_constprop_3(FILE *param_1,uint param_2,_union_263 param_3)

{
  byte bVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte **ppbVar12;
  char *pcVar14;
  int iVar15;
  uint uVar16;
  byte *pbVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte **ppbVar20;
  byte *pbVar21;
  int local_68;
  uint local_64;
  char local_42;
  byte local_41;
  undefined4 local_40;
  byte *local_3c;
  byte local_38;
  byte local_37;
  ASN1_TYPE local_34 [2];
  byte **ppbVar13;
  
  uVar5 = param_2 & 0x40f;
  iVar15 = (param_3.asn1_string)->type;
  local_42 = '\0';
  if ((param_2 & 0x40) == 0) {
    local_68 = 0;
  }
  else {
    pcVar14 = ASN1_tag2str(iVar15);
    sVar2 = strlen(pcVar14);
    if (param_1 != (FILE *)0x0) {
      sVar3 = fwrite(pcVar14,1,sVar2,param_1);
      if (sVar2 != sVar3) {
        return -1;
      }
      sVar3 = fwrite(":",1,1,param_1);
      if (sVar3 != 1) {
        return -1;
      }
    }
    local_68 = sVar2 + 1;
  }
  if ((int)(param_2 << 0x18) < 0) {
LAB_0018af1c:
    if (param_1 == (FILE *)0x0) {
      if ((int)(param_2 << 0x16) < 0) goto LAB_0018b792;
      pcVar14 = (char *)(param_3.asn1_string)->length;
    }
    else {
      sVar2 = fwrite(&DAT_00230168,1,1,param_1);
      if (sVar2 != 1) {
        return -1;
      }
      if ((int)(param_2 << 0x16) < 0) {
LAB_0018b792:
        local_34[0].type = (param_3.asn1_string)->type;
        local_34[0].value = param_3;
        iVar15 = i2d_ASN1_TYPE(local_34,(uchar **)0x0);
        if (iVar15 < 1) {
          return -1;
        }
        pbVar17 = (byte *)CRYPTO_malloc(iVar15,"crypto/asn1/a_strex.c",0x11d);
        if (pbVar17 == (byte *)0x0) {
          ERR_put_error(0xd,0x7d,0x41,"crypto/asn1/a_strex.c",0x11e);
          return -1;
        }
        local_3c = pbVar17;
        i2d_ASN1_TYPE(local_34,&local_3c);
        if ((param_1 != (FILE *)0x0) && (pbVar17 != pbVar17 + iVar15)) {
          pbVar21 = pbVar17;
          do {
            pbVar18 = pbVar21 + 1;
            local_40 = CONCAT31(CONCAT21(local_40._2_2_,"0123456789ABCDEF"[*pbVar21 & 0xf]),
                                "0123456789ABCDEF"[*pbVar21 >> 4]);
            sVar2 = fwrite(&local_40,1,2,param_1);
            if (sVar2 != 2) {
              CRYPTO_free(pbVar17);
              return -1;
            }
            pbVar21 = pbVar18;
          } while (pbVar17 + iVar15 != pbVar18);
        }
        iVar15 = iVar15 * 2;
        CRYPTO_free(pbVar17);
        if (iVar15 < 0) {
          return -1;
        }
        goto LAB_0018b672;
      }
      pbVar17 = (param_3.asn1_string)->data;
      pcVar14 = (param_3.object)->sn;
      if (pbVar17 + (int)pcVar14 != pbVar17) {
        pbVar21 = pbVar17;
        do {
          pbVar18 = pbVar21 + 1;
          local_34[0].type =
               CONCAT31(CONCAT21(local_34[0].type._2_2_,"0123456789ABCDEF"[*pbVar21 & 0xf]),
                        "0123456789ABCDEF"[*pbVar21 >> 4]);
          sVar2 = fwrite(local_34,1,2,param_1);
          if (sVar2 != 2) {
            return -1;
          }
          pbVar21 = pbVar18;
        } while (pbVar17 + (int)pcVar14 != pbVar18);
      }
    }
    iVar15 = (int)pcVar14 << 1;
    if (iVar15 < 0) {
      return -1;
    }
LAB_0018b672:
    return local_68 + iVar15 + 1;
  }
  if ((int)(param_2 << 0x1a) < 0) {
LAB_0018afe0:
    if ((int)(param_2 << 0x1b) < 0) {
      pbVar17 = (param_3.asn1_string)->data;
      bVar1 = 1;
      local_64 = (param_3.asn1_string)->length;
      bVar8 = 9;
      pbVar21 = pbVar17 + local_64;
    }
    else {
LAB_0018afe6:
      local_64 = (param_3.asn1_string)->length;
      pbVar17 = (param_3.asn1_string)->data;
      bVar1 = 1;
      pbVar21 = pbVar17 + local_64;
      bVar8 = 0;
    }
LAB_0018aff8:
    if (pbVar17 == pbVar21) {
      iVar15 = 0;
    }
    else {
      iVar15 = 0;
      bVar7 = bVar8 & 8;
      pbVar18 = pbVar17;
      do {
        while( true ) {
          if (pbVar17 == pbVar18) {
            uVar11 = (param_2 & 1) << 5;
          }
          else {
            uVar11 = 0;
          }
          switch(bVar1) {
          case 0:
            iVar4 = UTF8_getc(pbVar18,local_64,&local_40);
            if (iVar4 < 0) {
              return -1;
            }
            local_64 = local_64 - iVar4;
            pbVar19 = pbVar18 + iVar4;
            break;
          case 1:
            local_40 = (ulong)*pbVar18;
            pbVar19 = pbVar18 + 1;
            break;
          case 2:
            pbVar19 = pbVar18 + 2;
            local_40 = (ulong)CONCAT11(*pbVar18,pbVar18[1]);
            if (pbVar19 == pbVar21) goto LAB_0018b2b2;
            goto LAB_0018b092;
          default:
            goto LAB_0018af3e;
          case 4:
            pbVar19 = pbVar18 + 4;
            local_40 = (uint)*pbVar18 << 0x18 | (uint)pbVar18[1] << 0x10 | (uint)pbVar18[2] << 8 |
                       (uint)pbVar18[3];
          }
          if (pbVar19 != pbVar21) break;
LAB_0018b2b2:
          if ((param_2 & 1) != 0) {
            uVar11 = 0x40;
          }
          if (bVar7 == 0) goto LAB_0018b2c0;
LAB_0018b098:
          iVar4 = UTF8_putc((uchar *)&local_3c,6,local_40);
          if (0 < iVar4) {
            uVar11 = uVar11 | uVar5;
            uVar16 = (uint)local_3c & 0xff;
            if (uVar5 == 0) {
              if ((int)(uVar16 << 0x18) < 0) {
                uVar16 = param_2 & 4;
LAB_0018b0d6:
                if ((uVar16 & 0x406) == 0) {
                  iVar9 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar16 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar16 & 0x61) == 0) goto LAB_0018b0d6;
                if ((int)(uVar16 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 1) goto LAB_0018b1e0;
              uVar16 = (uint)local_3c >> 8 & 0xff;
              if ((int)(uVar16 << 0x18) < 0) {
                uVar16 = param_2 & 4;
LAB_0018b6a4:
                if ((uVar16 & 0x406) == 0) {
                  iVar9 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar16 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar16 & 0x61) == 0) goto LAB_0018b6a4;
                if ((int)(uVar16 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 2) goto LAB_0018b1e0;
              uVar16 = (uint)local_3c >> 0x10 & 0xff;
              if ((int)(uVar16 << 0x18) < 0) {
                uVar16 = param_2 & 4;
LAB_0018b682:
                if ((uVar16 & 0x406) == 0) {
                  iVar9 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar16 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar16 & 0x61) == 0) goto LAB_0018b682;
                if ((int)(uVar16 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 3) goto LAB_0018b1e0;
              if ((int)(((uint)local_3c >> 0x18) << 0x18) < 0) {
                uVar16 = param_2 & 4;
LAB_0018b70c:
                if ((uVar16 & 0x406) == 0) {
                  iVar9 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar16 = *(ushort *)(&char_type + ((uint)local_3c >> 0x18) * 2) & uVar11;
                if ((uVar16 & 0x61) == 0) goto LAB_0018b70c;
                if ((int)(uVar16 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 4) goto LAB_0018b1e0;
              if ((int)((uint)local_38 << 0x18) < 0) {
                uVar16 = param_2 & 4;
LAB_0018b6ea:
                if ((uVar16 & 0x406) == 0) {
                  iVar9 = 1;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar16 = *(ushort *)(&char_type + (uint)local_38 * 2) & uVar11;
                if ((uVar16 & 0x61) == 0) goto LAB_0018b6ea;
                if ((int)(uVar16 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 != 5) {
                if ((int)((uint)local_37 << 0x18) < 0) {
                  uVar11 = param_2 & 4;
                }
                else {
                  uVar11 = uVar11 & *(ushort *)(&char_type + (uint)local_37 * 2);
                  if ((uVar11 & 0x61) != 0) goto LAB_0018b1d2;
                }
                if ((uVar11 & 0x406) == 0) goto LAB_0018b1de;
                BIO_snprintf((char *)local_34,0xb,"\\%02X");
                iVar15 = iVar15 + 3;
              }
            }
            else {
              if ((int)(uVar16 << 0x18) < 0) {
                uVar6 = param_2 & 4;
LAB_0018b612:
                if ((uVar6 & 0x406) == 0) {
                  if (uVar16 == 0x5c) {
                    iVar9 = 2;
                  }
                  else {
                    iVar9 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar6 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar6 & 0x61) == 0) goto LAB_0018b612;
                if ((int)(uVar6 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 1) goto LAB_0018b1e0;
              uVar16 = (uint)local_3c >> 8 & 0xff;
              if ((int)(uVar16 << 0x18) < 0) {
                uVar6 = param_2 & 4;
LAB_0018b86e:
                if ((uVar6 & 0x406) == 0) {
                  if (uVar16 == 0x5c) {
                    iVar9 = 2;
                  }
                  else {
                    iVar9 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar6 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar6 & 0x61) == 0) goto LAB_0018b86e;
                if ((int)(uVar6 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 2) goto LAB_0018b1e0;
              uVar16 = (uint)local_3c >> 0x10 & 0xff;
              if ((int)(uVar16 << 0x18) < 0) {
                uVar6 = param_2 & 4;
LAB_0018b858:
                if ((uVar6 & 0x406) == 0) {
                  if (uVar16 == 0x5c) {
                    iVar9 = 2;
                  }
                  else {
                    iVar9 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar6 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar6 & 0x61) == 0) goto LAB_0018b858;
                if ((int)(uVar6 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 3) goto LAB_0018b1e0;
              uVar16 = (uint)local_3c >> 0x18;
              if ((int)(uVar16 << 0x18) < 0) {
                uVar6 = param_2 & 4;
LAB_0018b842:
                if ((uVar6 & 0x406) == 0) {
                  if (uVar16 == 0x5c) {
                    iVar9 = 2;
                  }
                  else {
                    iVar9 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar6 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar6 & 0x61) == 0) goto LAB_0018b842;
                if ((int)(uVar6 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 4) goto LAB_0018b1e0;
              uVar16 = (uint)local_38;
              if ((int)(uVar16 << 0x18) < 0) {
                uVar6 = param_2 & 4;
LAB_0018b82c:
                if ((uVar6 & 0x406) == 0) {
                  if (uVar16 == 0x5c) {
                    iVar9 = 2;
                  }
                  else {
                    iVar9 = 1;
                  }
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar9 = 3;
                }
              }
              else {
                uVar6 = *(ushort *)(&char_type + uVar16 * 2) & uVar11;
                if ((uVar6 & 0x61) == 0) goto LAB_0018b82c;
                if ((int)(uVar6 << 0x1c) < 0) {
                  iVar9 = 1;
                  local_42 = '\x01';
                }
                else {
                  iVar9 = 2;
                }
              }
              iVar15 = iVar15 + iVar9;
              if (iVar4 == 5) goto LAB_0018b1e0;
              uVar16 = (uint)local_37;
              if ((int)(uVar16 << 0x18) < 0) {
                uVar11 = param_2 & 4;
LAB_0018b5d4:
                if ((uVar11 & 0x406) == 0) {
                  if (uVar16 == 0x5c) {
                    iVar4 = 2;
                  }
                  else {
                    iVar4 = 1;
                  }
                  iVar15 = iVar15 + iVar4;
                }
                else {
                  BIO_snprintf((char *)local_34,0xb,"\\%02X");
                  iVar15 = iVar15 + 3;
                }
                goto LAB_0018b1e0;
              }
              uVar11 = uVar11 & *(ushort *)(&char_type + uVar16 * 2);
              if ((uVar11 & 0x61) == 0) goto LAB_0018b5d4;
LAB_0018b1d2:
              if ((int)(uVar11 << 0x1c) < 0) {
                local_42 = '\x01';
LAB_0018b1de:
                iVar15 = iVar15 + 1;
              }
              else {
                iVar15 = iVar15 + 2;
              }
            }
          }
LAB_0018b1e0:
          pbVar18 = pbVar19;
          if (pbVar19 == pbVar21) goto LAB_0018b1ec;
        }
LAB_0018b092:
        if (bVar7 != 0) goto LAB_0018b098;
LAB_0018b2c0:
        iVar4 = do_esc_char_constprop_7(local_40,uVar5 | uVar11,&local_42,bVar7);
        if (iVar4 < 0) {
          return -1;
        }
        iVar15 = iVar15 + iVar4;
        pbVar18 = pbVar19;
      } while (pbVar19 != pbVar21);
    }
LAB_0018b1ec:
    local_68 = local_68 + iVar15;
    if (local_42 == '\0') {
      if (param_1 == (FILE *)0x0) {
        return local_68;
      }
    }
    else {
      local_68 = local_68 + 2;
      if (param_1 == (FILE *)0x0) {
        return local_68;
      }
      sVar2 = fwrite(&DAT_00249714,1,1,param_1);
      if (sVar2 != 1) {
        return -1;
      }
    }
    pbVar17 = (param_3.asn1_string)->data;
    uVar11 = (param_3.asn1_string)->length;
    pbVar21 = pbVar17 + uVar11;
    if (bVar1 == 2) {
      if ((uVar11 & 1) != 0) {
LAB_0018b646:
        ERR_put_error(0xd,0x8e,0x81,"crypto/asn1/a_strex.c",0xa1);
        return -1;
      }
    }
    else if ((bVar1 == 4) && ((uVar11 & 3) != 0)) goto LAB_0018af90;
    if (pbVar17 != pbVar21) {
      bVar8 = bVar8 & 8;
      pbVar18 = pbVar17;
      do {
        if (pbVar17 == pbVar18) {
          uVar16 = (param_2 & 1) << 5;
        }
        else {
          uVar16 = 0;
        }
        switch(bVar1) {
        case 0:
          iVar15 = UTF8_getc(pbVar18,uVar11,&local_40);
          if (iVar15 < 0) {
            return -1;
          }
          uVar11 = uVar11 - iVar15;
          pbVar18 = pbVar18 + iVar15;
          break;
        case 1:
          local_40 = (ulong)*pbVar18;
          pbVar18 = pbVar18 + 1;
          break;
        case 2:
          local_40 = (ulong)CONCAT11(*pbVar18,pbVar18[1]);
          pbVar18 = pbVar18 + 2;
          break;
        default:
          goto LAB_0018af3e;
        case 4:
          local_40 = (uint)*pbVar18 << 0x18 | (uint)pbVar18[1] << 0x10 | (uint)pbVar18[2] << 8 |
                     (uint)pbVar18[3];
          pbVar18 = pbVar18 + 4;
        }
        if (pbVar21 == pbVar18) {
          if ((param_2 & 1) != 0) {
            uVar16 = 0x40;
          }
          if (bVar8 == 0) goto LAB_0018b3e0;
LAB_0018b33a:
          iVar15 = UTF8_putc((uchar *)&local_3c,6,local_40);
          if (0 < iVar15) {
            ppbVar20 = (byte **)((int)&local_3c + iVar15);
            ppbVar13 = &local_3c;
            do {
              while( true ) {
                ppbVar12 = (byte **)((int)ppbVar13 + 1);
                local_41 = *(byte *)ppbVar13;
                uVar10 = (uint)local_41;
                uVar6 = param_2 & 4;
                ppbVar13 = ppbVar12;
                if (((int)(uVar10 << 0x18) < 0) ||
                   (uVar6 = (uint)*(ushort *)(&char_type + uVar10 * 2) & (uVar16 | uVar5),
                   (uVar6 & 0x61) == 0)) break;
                if ((-1 < (int)(uVar6 << 0x1c)) &&
                   (sVar2 = fwrite(&DAT_0023015c,1,1,param_1), sVar2 != 1)) {
                  return -1;
                }
LAB_0018b38c:
                sVar2 = fwrite(&local_41,1,1,param_1);
                if (sVar2 != 1) {
                  return -1;
                }
LAB_0018b39c:
                if (ppbVar12 == ppbVar20) goto LAB_0018b3a4;
              }
              if ((uVar6 & 0x406) == 0) {
                if ((uVar10 != 0x5c) || (uVar5 == 0)) goto LAB_0018b38c;
                sVar2 = fwrite(&DAT_0020be44,1,2,param_1);
                if (sVar2 != 2) {
                  return -1;
                }
                goto LAB_0018b39c;
              }
              BIO_snprintf((char *)local_34,0xb,"\\%02X");
              sVar2 = fwrite(local_34,1,3,param_1);
              if (sVar2 != 3) {
                return -1;
              }
            } while (ppbVar12 != ppbVar20);
          }
        }
        else {
          if (bVar8 != 0) goto LAB_0018b33a;
LAB_0018b3e0:
          iVar15 = do_esc_char_constprop_7(local_40,uVar5 | uVar16,bVar8,param_1);
          if (iVar15 < 0) {
            return -1;
          }
        }
LAB_0018b3a4:
      } while (pbVar21 != pbVar18);
    }
    if ((local_42 == '\0') || (sVar2 = fwrite(&DAT_00249714,1,1,param_1), sVar2 == 1)) {
      return local_68;
    }
  }
  else {
    if ((0x1d < iVar15 - 1U) || (bVar1 = tag2nbyte[iVar15], bVar1 == 0xff)) {
      if ((int)(param_2 << 0x17) < 0) goto LAB_0018af1c;
      goto LAB_0018afe0;
    }
    bVar8 = bVar1;
    if ((int)(param_2 << 0x1b) < 0) {
      if (bVar1 != 0) {
        bVar8 = bVar1 | 8;
        goto LAB_0018af6c;
      }
      goto LAB_0018afe6;
    }
LAB_0018af6c:
    bVar1 = bVar1 & 7;
    local_64 = (param_3.asn1_string)->length;
    pbVar17 = (param_3.asn1_string)->data;
    pbVar21 = pbVar17 + local_64;
    if (bVar1 == 2) {
      if ((int)(local_64 << 0x1f) < 0) goto LAB_0018b646;
      goto LAB_0018aff8;
    }
    if ((bVar1 != 4) || ((local_64 & 3) == 0)) goto LAB_0018aff8;
LAB_0018af90:
    ERR_put_error(0xd,0x8e,0x85,"crypto/asn1/a_strex.c",0x9b);
  }
LAB_0018af3e:
  return -1;
}

