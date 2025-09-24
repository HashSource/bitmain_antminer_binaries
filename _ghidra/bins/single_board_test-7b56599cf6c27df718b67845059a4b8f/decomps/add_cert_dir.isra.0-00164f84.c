
undefined4 add_cert_dir_isra_0(int *param_1,char *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  size_t sVar3;
  undefined4 uVar4;
  void *ptr;
  char cVar5;
  int iVar6;
  char *__s;
  size_t __n;
  char *__s2;
  char *pcVar7;
  
  if ((param_2 == (char *)0x0) || (cVar5 = *param_2, cVar5 == '\0')) {
    ERR_put_error(0xb,100,0x71,"crypto/x509/by_dir.c",0xa0);
    return 0;
  }
  pcVar7 = param_2 + 1;
  __s2 = param_2;
  do {
    if (cVar5 == '\0' || cVar5 == ':') {
      __n = (int)param_2 - (int)__s2;
      if (__n != 0) {
        for (iVar6 = 0; iVar1 = OPENSSL_sk_num(*param_1), iVar6 < iVar1; iVar6 = iVar6 + 1) {
          puVar2 = (undefined4 *)OPENSSL_sk_value(*param_1,iVar6);
          __s = (char *)*puVar2;
          sVar3 = strlen(__s);
          if ((__n == sVar3) && (iVar1 = strncmp(__s,__s2,__n), iVar1 == 0)) break;
        }
        iVar1 = OPENSSL_sk_num(*param_1);
        if (iVar1 <= iVar6) {
          if (*param_1 == 0) {
            iVar6 = OPENSSL_sk_new_null();
            *param_1 = iVar6;
            if (iVar6 == 0) {
              iVar6 = 0xb9;
              goto LAB_001650d0;
            }
          }
          puVar2 = (undefined4 *)CRYPTO_malloc(0xc,"crypto/x509/by_dir.c",0xbd);
          if (puVar2 == (undefined4 *)0x0) {
            iVar6 = 0xbf;
LAB_001650d0:
            ERR_put_error(0xb,100,0x41,"crypto/x509/by_dir.c",iVar6);
            return 0;
          }
          puVar2[1] = param_3;
          uVar4 = OPENSSL_sk_new(0x164a85);
          puVar2[2] = uVar4;
          ptr = (void *)CRYPTO_strndup(__s2,__n,"crypto/x509/by_dir.c",0xc4);
          *puVar2 = ptr;
          if ((ptr == (void *)0x0) || (puVar2[2] == 0)) {
            CRYPTO_free(ptr);
            OPENSSL_sk_pop_free(puVar2[2],0x164aa1);
            CRYPTO_free(puVar2);
            return 0;
          }
          iVar6 = OPENSSL_sk_push(*param_1,puVar2);
          if (iVar6 == 0) {
            CRYPTO_free((void *)*puVar2);
            OPENSSL_sk_pop_free(puVar2[2],0x164aa1);
            CRYPTO_free(puVar2);
            ERR_put_error(0xb,100,0x41,"crypto/x509/by_dir.c",0xcb);
            return 0;
          }
        }
        cVar5 = *param_2;
      }
      __s2 = pcVar7;
      if (cVar5 == '\0') {
        return 1;
      }
    }
    pcVar7 = pcVar7 + 1;
    param_2 = param_2 + 1;
    cVar5 = *param_2;
  } while( true );
}

