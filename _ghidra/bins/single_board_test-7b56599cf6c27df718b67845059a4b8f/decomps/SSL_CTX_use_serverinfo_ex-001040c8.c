
undefined4 SSL_CTX_use_serverinfo_ex(int param_1,int param_2,byte *param_3,uint param_4)

{
  undefined1 *ptr;
  undefined4 uVar1;
  void *__dest;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == 0 || (param_4 == 0 || param_3 == (byte *)0x0)) {
    ERR_put_error(0x14,0x21f,0x43,"ssl/ssl_rsa.c",0x36c);
  }
  else {
    if (param_2 != 1) {
      if ((((param_2 == 2) && (-1 < (int)param_4)) && (3 < param_4)) &&
         (uVar4 = param_4 - 4, 1 < uVar4)) {
        pbVar2 = param_3 + 4;
        while ((1 < uVar4 - 2 && (uVar5 = (uint)CONCAT11(pbVar2[2],pbVar2[3]), uVar5 <= uVar4 - 4)))
        {
          uVar6 = (uVar4 - 4) - uVar5;
          uVar4 = uVar6 - 4;
          pbVar2 = pbVar2 + uVar5 + 8;
          if (uVar6 == 0) {
            if (**(int **)(param_1 + 0xc0) == 0) {
              ERR_put_error(0x14,0x21f,0x44,"ssl/ssl_rsa.c",0x38d);
              return 0;
            }
            __dest = CRYPTO_realloc(*(void **)(**(int **)(param_1 + 0xc0) + 0xc),param_4,
                                    "ssl/ssl_rsa.c",0x391);
            if (__dest == (void *)0x0) {
              ERR_put_error(0x14,0x21f,0x41,"ssl/ssl_rsa.c",0x393);
              return 0;
            }
            *(void **)(**(int **)(param_1 + 0xc0) + 0xc) = __dest;
            memcpy(__dest,param_3,param_4);
            *(uint *)(**(int **)(param_1 + 0xc0) + 0x10) = param_4;
            if (3 < param_4) goto LAB_00104218;
            goto LAB_0010428c;
          }
          if ((uVar6 < 4) || (uVar4 < 2)) break;
        }
      }
      iVar3 = 0x389;
      goto LAB_001040fc;
    }
    ptr = (undefined1 *)CRYPTO_malloc(param_4 + 4,"ssl/ssl_rsa.c",0x379);
    if (ptr != (undefined1 *)0x0) {
      *ptr = 0;
      ptr[1] = 0;
      ptr[2] = 1;
      ptr[3] = 0xd0;
      memcpy(ptr + 4,param_3,param_4);
      uVar1 = SSL_CTX_use_serverinfo_ex(param_1,2,ptr,param_4 + 4);
      CRYPTO_free(ptr);
      return uVar1;
    }
    ERR_put_error(0x14,0x21f,0x41,"ssl/ssl_rsa.c",0x37b);
  }
  return 0;
  while( true ) {
    param_4 = (param_4 - 8) - uVar4;
    uVar5 = (uint)param_3[3] | (uint)param_3[1] << 0x10 | (uint)*param_3 << 0x18 |
            (uint)param_3[2] << 8;
    if (uVar5 == 0x1d0) {
      iVar3 = SSL_CTX_add_server_custom_ext
                        (param_1,CONCAT11(param_3[4],param_3[5]),0x1032fd,0,0,0x102e11,0);
    }
    else {
      iVar3 = SSL_CTX_add_custom_ext
                        (param_1,CONCAT11(param_3[4],param_3[5]),uVar5,0x103269,0,0,0x102dfd,0);
    }
    if (iVar3 == 0) break;
    if (param_4 == 0) {
      return 1;
    }
    param_3 = param_3 + uVar4 + 8;
    if (param_4 < 4) break;
LAB_00104218:
    if ((param_4 - 4 < 4) || (uVar4 = (uint)CONCAT11(param_3[6],param_3[7]), param_4 - 8 < uVar4))
    break;
  }
LAB_0010428c:
  iVar3 = 0x3a0;
LAB_001040fc:
  ERR_put_error(0x14,0x21f,0x184,"ssl/ssl_rsa.c",iVar3);
  return 0;
}

