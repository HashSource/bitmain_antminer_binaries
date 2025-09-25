
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_ERR_strings(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined1 *puVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  char *pcVar12;
  
  iVar2 = CRYPTO_THREAD_run_once(&err_string_init,0x122fc1);
  if ((iVar2 != 0) && (do_err_strings_init_ossl_ret_ != 0)) {
    CRYPTO_THREAD_write_lock(err_string_lock);
    piVar7 = &ERR_str_libraries;
    iVar2 = ERR_str_libraries;
    while (iVar2 != 0) {
      OPENSSL_LH_insert(int_error_hash,piVar7);
      piVar7 = piVar7 + 2;
      iVar2 = *piVar7;
    }
    CRYPTO_THREAD_unlock(err_string_lock);
    puVar8 = ERR_str_reasons;
    CRYPTO_THREAD_write_lock(err_string_lock);
    iVar2 = ERR_str_reasons._0_4_;
    while (iVar2 != 0) {
      OPENSSL_LH_insert(int_error_hash,puVar8);
      puVar8 = (undefined1 *)((int)puVar8 + 8);
      iVar2 = *(int *)puVar8;
    }
    CRYPTO_THREAD_unlock(err_string_lock);
    puVar8 = ERR_str_functs;
    uVar6 = ERR_str_functs._0_4_;
    while (uVar6 != 0) {
      *(uint *)puVar8 = uVar6 | 0x2000000;
      puVar8 = (undefined1 *)((int)puVar8 + 8);
      uVar6 = *(uint *)puVar8;
    }
    CRYPTO_THREAD_write_lock(err_string_lock);
    puVar8 = ERR_str_functs;
    iVar2 = ERR_str_functs._0_4_;
    while (iVar2 != 0) {
      OPENSSL_LH_insert(int_error_hash,puVar8);
      puVar8 = (undefined1 *)((int)puVar8 + 8);
      iVar2 = *(int *)puVar8;
    }
    CRYPTO_THREAD_unlock(err_string_lock);
    piVar7 = __errno_location();
    iVar2 = *piVar7;
    CRYPTO_THREAD_write_lock(err_string_lock);
    if (init_9307 != 0) {
      puVar8 = strerror_pool_9304;
      uVar6 = 0;
      uVar10 = 1;
      iVar9 = 0xb25044;
      do {
        *(uint *)(iVar9 + -0x1c) = uVar10 | 0x2000000;
        HintPreloadData(iVar9);
        pcVar11 = puVar8;
        pcVar12 = *(char **)(iVar9 + -0x18);
        if (uVar6 < 0x2000 && *(char **)(iVar9 + -0x18) == (char *)0x0) {
          iVar3 = openssl_strerror_r(uVar10,puVar8,0x2000 - uVar6);
          if (iVar3 == 0) {
            pcVar12 = *(char **)(iVar9 + -0x18);
          }
          else {
            sVar4 = strlen(puVar8);
            pcVar11 = puVar8 + sVar4;
            iVar3 = uVar6 + sVar4;
            *(undefined1 **)(iVar9 + -0x18) = puVar8;
            if (strerror_pool_9304 + 1 <= pcVar11) {
              do {
                pcVar12 = pcVar11 + -1;
                iVar5 = ossl_ctype_check(pcVar11[-1],8);
                if (iVar5 == 0) {
                  puVar8 = *(undefined1 **)(iVar9 + -0x18);
                  goto LAB_00123248;
                }
                iVar3 = iVar3 + -1;
                pcVar11 = pcVar12;
              } while (pcVar12 != strerror_pool_9304);
              puVar8 = *(undefined1 **)(iVar9 + -0x18);
              pcVar11 = strerror_pool_9304;
            }
LAB_00123248:
            uVar6 = iVar3 + 1;
            *pcVar11 = '\0';
            pcVar11 = pcVar11 + 1;
            pcVar12 = puVar8;
          }
        }
        puVar8 = pcVar11;
        if (pcVar12 == (char *)0x0) {
          *(char **)(iVar9 + -0x18) = "unknown";
        }
        uVar10 = uVar10 + 1;
        iVar9 = iVar9 + 8;
        if (uVar10 == 0x80) {
          init_9307 = 0;
          CRYPTO_THREAD_unlock(err_string_lock);
          uVar1 = err_string_lock;
          puVar8 = SYS_str_reasons;
          *piVar7 = iVar2;
          CRYPTO_THREAD_write_lock(uVar1);
          iVar2 = SYS_str_reasons._0_4_;
          while (iVar2 != 0) {
            OPENSSL_LH_insert(int_error_hash,puVar8);
            puVar8 = (undefined1 *)((int)puVar8 + 8);
            iVar2 = *(int *)puVar8;
          }
          CRYPTO_THREAD_unlock(err_string_lock);
          return;
        }
      } while( true );
    }
    CRYPTO_THREAD_unlock(err_string_lock);
  }
  return;
}

