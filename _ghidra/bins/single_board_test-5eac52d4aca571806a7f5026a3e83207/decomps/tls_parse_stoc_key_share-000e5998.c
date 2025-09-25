
undefined4 tls_parse_stoc_key_share(int param_1,undefined4 *param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  short sVar3;
  EVP_PKEY *to;
  int iVar4;
  short *psVar5;
  EVP_PKEY *from;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  short *local_28;
  int local_24;
  
  iVar4 = *(int *)(param_1 + 0x7c);
  from = *(EVP_PKEY **)(iVar4 + 0x214);
  if ((from == (EVP_PKEY *)0x0) || (local_28 = *(short **)(iVar4 + 0x358), local_28 != (short *)0x0)
     ) {
    ossl_statem_fatal(param_1,0x50,0x1bd,0x44,"ssl/statem/extensions_clnt.c",0x71c);
  }
  else {
    uVar7 = param_2[1];
    if (uVar7 < 2) {
      ossl_statem_fatal(param_1,0x32,0x1bd,0x9f,"ssl/statem/extensions_clnt.c",0x722);
    }
    else {
      puVar8 = (undefined1 *)*param_2;
      uVar6 = uVar7 - 2;
      uVar1 = *puVar8;
      uVar2 = puVar8[1];
      *param_2 = puVar8 + 2;
      param_2[1] = uVar6;
      sVar3 = CONCAT11(uVar1,uVar2);
      if ((param_3 & 0x800) == 0) {
        if (*(short *)(iVar4 + 0x356) == sVar3) {
          if (1 < uVar6) {
            uVar6 = (uint)CONCAT11(puVar8[2],puVar8[3]);
            if (uVar6 <= uVar7 - 4) {
              if (uVar6 == uVar7 - 4) {
                *param_2 = puVar8 + 4 + uVar6;
                param_2[1] = 0;
                if (uVar6 != 0) {
                  to = EVP_PKEY_new();
                  if ((to == (EVP_PKEY *)0x0) ||
                     (iVar4 = EVP_PKEY_copy_parameters(to,from), iVar4 < 1)) {
                    ossl_statem_fatal(param_1,0x50,0x1bd,0x41,"ssl/statem/extensions_clnt.c",0x761);
                    EVP_PKEY_free(to);
                    return 0;
                  }
                  iVar4 = EVP_PKEY_set1_tls_encodedpoint(to,puVar8 + 4,uVar6);
                  if (iVar4 == 0) {
                    ossl_statem_fatal(param_1,0x2f,0x1bd,0x132,"ssl/statem/extensions_clnt.c",0x768)
                    ;
                    EVP_PKEY_free(to);
                    return 0;
                  }
                  iVar4 = ssl_derive(param_1,from,to,1);
                  if (iVar4 != 0) {
                    *(EVP_PKEY **)(*(int *)(param_1 + 0x7c) + 0x358) = to;
                    return 1;
                  }
                  EVP_PKEY_free(to);
                  return 0;
                }
              }
            }
          }
          ossl_statem_fatal(param_1,0x32,0x1bd,0x9f,"ssl/statem/extensions_clnt.c",0x75a);
        }
        else {
          ossl_statem_fatal(param_1,0x2f,0x1bd,0x6c,"ssl/statem/extensions_clnt.c",0x753);
        }
      }
      else if (uVar6 == 0) {
        if (*(short *)(iVar4 + 0x356) == sVar3) {
          ossl_statem_fatal(param_1,0x2f,0x1bd,0x6c,"ssl/statem/extensions_clnt.c",0x736);
        }
        else {
          tls1_get_supported_groups(param_1,&local_28,&local_24);
          if (local_24 != 0) {
            if (*local_28 != sVar3) {
              iVar4 = 0;
              psVar5 = local_28;
              do {
                iVar4 = iVar4 + 1;
                if (iVar4 == local_24) goto LAB_000e5a3c;
                psVar5 = psVar5 + 1;
              } while (*psVar5 != sVar3);
            }
            iVar4 = tls_curve_allowed(param_1,sVar3,0x20004);
            if (iVar4 != 0) {
              iVar4 = *(int *)(param_1 + 0x7c);
              *(short *)(iVar4 + 0x356) = sVar3;
              EVP_PKEY_free(*(EVP_PKEY **)(iVar4 + 0x214));
              *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x214) = 0;
              return 1;
            }
          }
LAB_000e5a3c:
          ossl_statem_fatal(param_1,0x2f,0x1bd,0x6c,"ssl/statem/extensions_clnt.c",0x743);
        }
      }
      else {
        ossl_statem_fatal(param_1,0x32,0x1bd,0x9f,"ssl/statem/extensions_clnt.c",0x72c);
      }
    }
  }
  return 0;
}

