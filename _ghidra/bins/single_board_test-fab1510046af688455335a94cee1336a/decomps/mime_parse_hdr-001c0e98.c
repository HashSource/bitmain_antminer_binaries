
_STACK * mime_parse_hdr(BIO *param_1)

{
  _STACK *st;
  int iVar1;
  ushort **ppuVar2;
  size_t sVar3;
  ushort *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *__s;
  void *data;
  byte local_428 [1028];
  
  st = sk_new((cmp *)0x1c0bc1);
  if (st != (_STACK *)0x0) {
    data = (void *)0x0;
    do {
      iVar1 = BIO_gets(param_1,(char *)local_428,0x400);
      if (iVar1 < 1) {
        return st;
      }
      if (data == (void *)0x0) {
        uVar7 = (uint)local_428[0];
LAB_001c0ee2:
        iVar1 = 1;
      }
      else {
        ppuVar2 = __ctype_b_loc();
        uVar7 = (uint)local_428[0];
        if (-1 < (int)((uint)(*ppuVar2)[uVar7] << 0x12)) goto LAB_001c0ee2;
        iVar1 = 3;
      }
      pbVar9 = local_428;
      pbVar5 = local_428;
      if (uVar7 == 0) {
        __s = (byte *)0x0;
      }
      else if (uVar7 == 0xd || uVar7 == 10) {
        __s = (byte *)0x0;
      }
      else {
        __s = (byte *)0x0;
        do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(iVar1) {
          case 1:
            if (uVar7 == 0x3a) {
              *pbVar9 = 0;
              pbVar6 = (byte *)(uint)*pbVar5;
              __s = pbVar6;
              if (pbVar6 != (byte *)0x0) {
                if (pbVar6 != (byte *)0x22) {
                  ppuVar2 = __ctype_b_loc();
                  __s = pbVar5;
                  do {
                    pbVar5 = __s + 1;
                    if (-1 < (int)((uint)(*ppuVar2)[(int)pbVar6] << 0x12)) goto LAB_001c0fb8;
                    pbVar6 = (byte *)(uint)__s[1];
                    __s = pbVar6;
                    if (pbVar6 == (byte *)0x0) goto LAB_001c1008;
                    __s = pbVar5;
                  } while (pbVar6 != (byte *)0x22);
                }
                __s = (byte *)(uint)pbVar5[1];
                if ((__s != (byte *)0x0) && (__s = pbVar5 + 1, __s != (byte *)0x0)) {
LAB_001c0fb8:
                  sVar3 = strlen((char *)__s);
                  uVar7 = sVar3 - 1;
                  pbVar6 = __s + uVar7;
                  if (!CARRY4((uint)__s,uVar7)) {
                    uVar7 = (uint)__s[uVar7];
                    if (uVar7 != 0x22) {
                      ppuVar2 = __ctype_b_loc();
                      puVar4 = *ppuVar2;
                      pbVar5 = pbVar6;
                      do {
                        pbVar6 = pbVar5 + -1;
                        if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001c1008;
                        *pbVar5 = 0;
                        if (pbVar6 == __s + -1) goto LAB_001c131a;
                        uVar7 = (uint)*pbVar6;
                        pbVar5 = pbVar6;
                      } while (uVar7 != 0x22);
                    }
                    if (__s != pbVar6 + -1) {
                      pbVar5 = pbVar9 + 1;
                      *pbVar6 = 0;
                      iVar1 = 2;
                      break;
                    }
                  }
LAB_001c131a:
                  pbVar5 = pbVar9 + 1;
                  __s = (byte *)0x0;
                  iVar1 = 2;
                  break;
                }
              }
LAB_001c1008:
              pbVar5 = pbVar9 + 1;
              iVar1 = 2;
            }
            break;
          case 2:
            if (uVar7 == 0x3b) {
              *pbVar9 = 0;
              pbVar6 = (byte *)(uint)*pbVar5;
              if (pbVar6 != (byte *)0x0) {
                if (pbVar6 != (byte *)0x22) {
                  ppuVar2 = __ctype_b_loc();
                  pbVar8 = pbVar5;
                  do {
                    puVar4 = *ppuVar2 + (int)pbVar6;
                    pbVar5 = pbVar8 + 1;
                    pbVar6 = pbVar8;
                    if (-1 < (int)((uint)*puVar4 << 0x12)) goto LAB_001c10dc;
                    pbVar6 = (byte *)(uint)pbVar8[1];
                    if (pbVar6 == (byte *)0x0) goto LAB_001c1126;
                    pbVar8 = pbVar5;
                  } while (pbVar6 != (byte *)0x22);
                }
                pbVar6 = (byte *)(uint)pbVar5[1];
                if ((pbVar6 != (byte *)0x0) && (pbVar6 = pbVar5 + 1, pbVar6 != (byte *)0x0)) {
LAB_001c10dc:
                  sVar3 = strlen((char *)pbVar6);
                  uVar7 = sVar3 - 1;
                  pbVar5 = pbVar6 + uVar7;
                  if (!CARRY4((uint)pbVar6,uVar7)) {
                    uVar7 = (uint)pbVar6[uVar7];
                    if (uVar7 != 0x22) {
                      ppuVar2 = __ctype_b_loc();
                      puVar4 = *ppuVar2;
                      pbVar8 = pbVar5;
                      do {
                        pbVar5 = pbVar8 + -1;
                        if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001c1126;
                        *pbVar8 = 0;
                        if (pbVar5 == pbVar6 + -1) goto LAB_001c1336;
                        uVar7 = (uint)*pbVar5;
                        pbVar8 = pbVar5;
                      } while (uVar7 != 0x22);
                    }
                    if (pbVar6 != pbVar5 + -1) {
                      *pbVar5 = 0;
                      goto LAB_001c1126;
                    }
                  }
LAB_001c1336:
                  pbVar6 = (byte *)0x0;
                }
              }
LAB_001c1126:
              data = (void *)mime_hdr_new(__s,pbVar6);
              pbVar5 = pbVar9 + 1;
              sk_push(st,data);
              __s = (byte *)0x0;
              iVar1 = 3;
            }
            else if (uVar7 == 0x28) {
              iVar1 = 6;
            }
            break;
          case 3:
            if (uVar7 == 0x3d) {
              *pbVar9 = 0;
              pbVar6 = (byte *)(uint)*pbVar5;
              __s = pbVar6;
              if (pbVar6 != (byte *)0x0) {
                if (pbVar6 != (byte *)0x22) {
                  ppuVar2 = __ctype_b_loc();
                  __s = pbVar5;
                  do {
                    pbVar5 = __s + 1;
                    if (-1 < (int)((uint)(*ppuVar2)[(int)pbVar6] << 0x12)) goto LAB_001c1050;
                    pbVar6 = (byte *)(uint)__s[1];
                    __s = pbVar6;
                    if (pbVar6 == (byte *)0x0) goto LAB_001c10a0;
                    __s = pbVar5;
                  } while (pbVar6 != (byte *)0x22);
                }
                __s = (byte *)(uint)pbVar5[1];
                if ((__s != (byte *)0x0) && (__s = pbVar5 + 1, __s != (byte *)0x0)) {
LAB_001c1050:
                  sVar3 = strlen((char *)__s);
                  uVar7 = sVar3 - 1;
                  pbVar6 = __s + uVar7;
                  if (!CARRY4((uint)__s,uVar7)) {
                    uVar7 = (uint)__s[uVar7];
                    if (uVar7 != 0x22) {
                      ppuVar2 = __ctype_b_loc();
                      puVar4 = *ppuVar2;
                      pbVar5 = pbVar6;
                      do {
                        pbVar6 = pbVar5 + -1;
                        if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001c10a0;
                        *pbVar5 = 0;
                        if (pbVar6 == __s + -1) goto LAB_001c1324;
                        uVar7 = (uint)*pbVar6;
                        pbVar5 = pbVar6;
                      } while (uVar7 != 0x22);
                    }
                    if (__s != pbVar6 + -1) {
                      pbVar5 = pbVar9 + 1;
                      *pbVar6 = 0;
                      iVar1 = 4;
                      break;
                    }
                  }
LAB_001c1324:
                  pbVar5 = pbVar9 + 1;
                  __s = (byte *)0x0;
                  iVar1 = 4;
                  break;
                }
              }
LAB_001c10a0:
              pbVar5 = pbVar9 + 1;
              iVar1 = 4;
            }
          }
          pbVar9 = pbVar9 + 1;
          uVar7 = (uint)*pbVar9;
        } while ((uVar7 != 0) && (uVar7 != 10 && uVar7 != 0xd));
      }
      if (iVar1 == 2) {
        pbVar6 = (byte *)(uint)*pbVar5;
        if (pbVar6 != (byte *)0x0) {
          if (pbVar6 != (byte *)0x22) {
            ppuVar2 = __ctype_b_loc();
            pbVar8 = pbVar5;
            do {
              puVar4 = *ppuVar2 + (int)pbVar6;
              pbVar5 = pbVar8 + 1;
              pbVar6 = pbVar8;
              if (-1 < (int)((uint)*puVar4 << 0x12)) goto LAB_001c121e;
              pbVar6 = (byte *)(uint)pbVar8[1];
              if (pbVar6 == (byte *)0x0) goto LAB_001c1268;
              pbVar8 = pbVar5;
            } while (pbVar6 != (byte *)0x22);
          }
          pbVar6 = (byte *)(uint)pbVar5[1];
          if ((pbVar6 != (byte *)0x0) && (pbVar6 = pbVar5 + 1, pbVar6 != (byte *)0x0)) {
LAB_001c121e:
            sVar3 = strlen((char *)pbVar6);
            uVar7 = sVar3 - 1;
            pbVar5 = pbVar6 + uVar7;
            if (!CARRY4((uint)pbVar6,uVar7)) {
              uVar7 = (uint)pbVar6[uVar7];
              if (uVar7 != 0x22) {
                ppuVar2 = __ctype_b_loc();
                puVar4 = *ppuVar2;
                pbVar8 = pbVar5;
                do {
                  pbVar5 = pbVar8 + -1;
                  if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001c1268;
                  *pbVar8 = 0;
                  if (pbVar5 == pbVar6 + -1) goto LAB_001c13d2;
                  uVar7 = (uint)*pbVar5;
                  pbVar8 = pbVar5;
                } while (uVar7 != 0x22);
              }
              if (pbVar6 != pbVar5 + -1) {
                *pbVar5 = 0;
                goto LAB_001c1268;
              }
            }
LAB_001c13d2:
            pbVar6 = (byte *)0x0;
          }
        }
LAB_001c1268:
        data = (void *)mime_hdr_new(__s,pbVar6);
        sk_push(st,data);
      }
      else if (iVar1 == 4) {
        uVar7 = (uint)*pbVar5;
        if (uVar7 == 0) {
LAB_001c1406:
          mime_hdr_addparam(data,__s,uVar7);
        }
        else {
          if (uVar7 != 0x22) {
            ppuVar2 = __ctype_b_loc();
            pbVar6 = pbVar5;
            do {
              pbVar5 = pbVar6 + 1;
              if (-1 < (int)((uint)(*ppuVar2)[uVar7] << 0x12)) goto LAB_001c12b6;
              uVar7 = (uint)pbVar6[1];
              if (uVar7 == 0) goto LAB_001c1406;
              pbVar6 = pbVar5;
            } while (uVar7 != 0x22);
          }
          if ((pbVar5[1] == 0) || (pbVar6 = pbVar5 + 1, pbVar6 == (byte *)0x0)) {
LAB_001c1310:
            mime_hdr_addparam(data,__s);
          }
          else {
LAB_001c12b6:
            sVar3 = strlen((char *)pbVar6);
            uVar7 = sVar3 - 1;
            pbVar5 = pbVar6 + uVar7;
            if (!CARRY4((uint)pbVar6,uVar7)) {
              uVar7 = (uint)pbVar6[uVar7];
              if (uVar7 != 0x22) {
                ppuVar2 = __ctype_b_loc();
                puVar4 = *ppuVar2;
                pbVar8 = pbVar5;
                do {
                  pbVar5 = pbVar8 + -1;
                  if (-1 < (int)((uint)puVar4[uVar7] << 0x12)) goto LAB_001c1310;
                  *pbVar8 = 0;
                  if (pbVar5 == pbVar6 + -1) goto LAB_001c1412;
                  uVar7 = (uint)*pbVar5;
                  pbVar8 = pbVar5;
                } while (uVar7 != 0x22);
              }
              if (pbVar6 != pbVar5 + -1) {
                *pbVar5 = 0;
                mime_hdr_addparam(data,__s);
                goto LAB_001c0f30;
              }
            }
LAB_001c1412:
            mime_hdr_addparam(data,__s,0);
          }
        }
      }
LAB_001c0f30:
    } while (pbVar9 != local_428);
  }
  return st;
}

