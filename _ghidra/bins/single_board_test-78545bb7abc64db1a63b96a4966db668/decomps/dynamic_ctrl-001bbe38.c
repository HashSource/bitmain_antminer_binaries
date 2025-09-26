
char * dynamic_ctrl(ENGINE *param_1,undefined4 param_2,uint param_3,char *param_4)

{
  int *ptr;
  int iVar1;
  int *piVar2;
  DSO *pDVar3;
  DSO_FUNC_TYPE pDVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  void *local_a8;
  m *pmStack_a4;
  r *prStack_a0;
  f *pfStack_9c;
  undefined1 auStack_98 [116];
  
  if (dynamic_ex_data_idx < 0) {
    iVar1 = CRYPTO_get_ex_new_index
                      (10,0,(void *)0x0,(undefined1 *)0x0,(undefined1 *)0x0,(undefined1 *)0x1bbdf1);
    if (iVar1 == -1) {
      ERR_put_error(0x26,0xb5,0x90,"crypto/engine/eng_dyn.c",0xd2);
      goto LAB_001bc22c;
    }
    CRYPTO_THREAD_write_lock(global_engine_lock);
    if (dynamic_ex_data_idx < 0) {
      dynamic_ex_data_idx = iVar1;
    }
    CRYPTO_THREAD_unlock(global_engine_lock);
  }
  ptr = (int *)ENGINE_get_ex_data(param_1,dynamic_ex_data_idx);
  if (ptr == (int *)0x0) {
    ptr = (int *)CRYPTO_zalloc(0x2c,"crypto/engine/eng_dyn.c",0x9c);
    if (ptr == (int *)0x0) {
      ERR_put_error(0x26,0xb7,0x41,"crypto/engine/eng_dyn.c",0xa0);
LAB_001bc22c:
      ERR_put_error(0x26,0xb4,0x70,"crypto/engine/eng_dyn.c",0x127);
      return (char *)0x0;
    }
    iVar1 = OPENSSL_sk_new_null();
    ptr[10] = iVar1;
    if (iVar1 == 0) {
      ERR_put_error(0x26,0xb7,0x41,"crypto/engine/eng_dyn.c",0xa5);
      CRYPTO_free(ptr);
      goto LAB_001bc22c;
    }
    ptr[9] = 1;
    ptr[7] = (int)"v_check";
    ptr[8] = (int)"bind_engine";
    CRYPTO_THREAD_write_lock(global_engine_lock);
    piVar2 = (int *)ENGINE_get_ex_data(param_1,dynamic_ex_data_idx);
    if (piVar2 == (int *)0x0) {
      iVar1 = ENGINE_set_ex_data(param_1,dynamic_ex_data_idx,ptr);
      if (iVar1 == 0) {
        CRYPTO_THREAD_unlock(global_engine_lock);
        OPENSSL_sk_free(ptr[10]);
        CRYPTO_free(ptr);
        goto LAB_001bc22c;
      }
      CRYPTO_THREAD_unlock(global_engine_lock);
      CRYPTO_free((void *)0x0);
    }
    else {
      CRYPTO_THREAD_unlock(global_engine_lock);
      OPENSSL_sk_free(ptr[10]);
      CRYPTO_free(ptr);
      ptr = piVar2;
    }
  }
  if (*ptr != 0) {
    ERR_put_error(0x26,0xb4,100,"crypto/engine/eng_dyn.c",0x12d);
    return (char *)0x0;
  }
  switch(param_2) {
  case 200:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      pcVar7 = (char *)0x0;
      CRYPTO_free((void *)ptr[3]);
      ptr[3] = 0;
    }
    else {
      CRYPTO_free((void *)ptr[3]);
      pcVar7 = CRYPTO_strdup(param_4,"crypto/engine/eng_dyn.c",0x137);
      ptr[3] = (int)pcVar7;
      if (pcVar7 != (char *)0x0) {
        pcVar7 = (char *)0x1;
      }
    }
    break;
  case 0xc9:
    pcVar7 = (char *)0x1;
    if (param_3 != 0) {
      param_3 = 1;
    }
    ptr[4] = param_3;
    break;
  case 0xca:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      pcVar7 = (char *)0x0;
      CRYPTO_free((void *)ptr[5]);
      ptr[5] = 0;
    }
    else {
      CRYPTO_free((void *)ptr[5]);
      pcVar7 = CRYPTO_strdup(param_4,"crypto/engine/eng_dyn.c",0x144);
      ptr[5] = (int)pcVar7;
      if (pcVar7 != (char *)0x0) {
        pcVar7 = (char *)0x1;
      }
    }
    break;
  case 0xcb:
    if (param_3 < 3) {
      ptr[6] = param_3;
      return (char *)0x1;
    }
    iVar1 = 0x14a;
    goto LAB_001bc05a;
  case 0xcc:
    if (param_3 < 3) {
      ptr[9] = param_3;
      return (char *)0x1;
    }
    iVar1 = 0x153;
    goto LAB_001bc05a;
  case 0xcd:
    if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
      pcVar7 = CRYPTO_strdup(param_4,"crypto/engine/eng_dyn.c",0x15f);
      if (pcVar7 == (char *)0x0) {
        ERR_put_error(0x26,0xb4,0x41,"crypto/engine/eng_dyn.c",0x161);
        return (char *)0x0;
      }
      iVar1 = OPENSSL_sk_push(ptr[10],pcVar7);
      if (iVar1 != 0) {
        return (char *)0x1;
      }
      CRYPTO_free(pcVar7);
      ERR_put_error(0x26,0xb4,0x41,"crypto/engine/eng_dyn.c",0x166);
      return (char *)0x0;
    }
    iVar1 = 0x15b;
LAB_001bc05a:
    ERR_put_error(0x26,0xb4,0x8f,"crypto/engine/eng_dyn.c",iVar1);
    pcVar7 = (char *)0x0;
    break;
  case 0xce:
    pDVar3 = DSO_new();
    *ptr = (int)pDVar3;
    if (pDVar3 == (DSO *)0x0) {
      return (char *)0x0;
    }
    pcVar7 = (char *)ptr[3];
    if (pcVar7 == (char *)0x0) {
      if (ptr[5] == 0) {
        return (char *)0x0;
      }
      DSO_ctrl(pDVar3,2,2,(void *)0x0);
      pcVar7 = DSO_convert_filename((DSO *)*ptr,(char *)ptr[5]);
      ptr[3] = (int)pcVar7;
    }
    if (ptr[9] == 2) {
LAB_001bbf8c:
      iVar1 = OPENSSL_sk_num(ptr[10]);
      if (0 < iVar1) {
        iVar6 = 0;
        do {
          pcVar7 = (char *)OPENSSL_sk_value(ptr[10],iVar6);
          iVar6 = iVar6 + 1;
          pcVar7 = DSO_merge((DSO *)*ptr,(char *)ptr[3],pcVar7);
          if (pcVar7 == (char *)0x0) break;
          pDVar3 = DSO_load((DSO *)*ptr,pcVar7,(DSO_METHOD *)0x0,0);
          if (pDVar3 != (DSO *)0x0) {
            CRYPTO_free(pcVar7);
            goto LAB_001bc10c;
          }
          CRYPTO_free(pcVar7);
        } while (iVar1 != iVar6);
      }
    }
    else {
      pDVar3 = DSO_load((DSO *)*ptr,pcVar7,(DSO_METHOD *)0x0,0);
      if (pDVar3 != (DSO *)0x0) {
LAB_001bc10c:
        pDVar4 = DSO_bind_func((DSO *)*ptr,(char *)ptr[8]);
        ptr[2] = (int)pDVar4;
        if (pDVar4 == (DSO_FUNC_TYPE)0x0) {
          DSO_free((DSO *)*ptr);
          *ptr = 0;
          ERR_put_error(0x26,0xb6,0x68,"crypto/engine/eng_dyn.c",0x1bf);
          return (char *)0x0;
        }
        if (ptr[4] != 0) {
LAB_001bc15c:
          memcpy(auStack_98,param_1,0x70);
          local_a8 = ENGINE_get_static_state();
          CRYPTO_get_mem_functions(&pmStack_a4,&prStack_a0,&pfStack_9c);
          engine_set_all_null(param_1);
          iVar1 = engine_add_dynamic_id(param_1,ptr[2],1);
          if ((iVar1 == 0) || (iVar1 = (*(code *)ptr[2])(param_1,ptr[5],&local_a8), iVar1 == 0)) {
            engine_remove_dynamic_id(param_1,1);
            ptr[2] = 0;
            ptr[1] = 0;
            DSO_free((DSO *)*ptr);
            *ptr = 0;
            ERR_put_error(0x26,0xb6,0x6d,"crypto/engine/eng_dyn.c",0x1fb);
            memcpy(param_1,auStack_98,0x70);
            return (char *)0x0;
          }
          if (ptr[6] < 1) {
            return (char *)0x1;
          }
          iVar1 = ENGINE_add(param_1);
          if (iVar1 != 0) {
            return (char *)0x1;
          }
          if (ptr[6] < 2) {
            ERR_clear_error();
            return (char *)0x1;
          }
          ERR_put_error(0x26,0xb6,0x67,"crypto/engine/eng_dyn.c",0x20c);
          return (char *)0x0;
        }
        pDVar4 = DSO_bind_func((DSO *)*ptr,(char *)ptr[7]);
        ptr[1] = (int)pDVar4;
        if ((pDVar4 != (DSO_FUNC_TYPE)0x0) && (uVar5 = (*pDVar4)(0x30000), 0x2ffff < uVar5)) {
          ERR_set_mark();
          pDVar4 = DSO_bind_func((DSO *)*ptr,"EVP_PKEY_get_base_id");
          ERR_pop_to_mark();
          if (pDVar4 == (DSO_FUNC_TYPE)0x0) goto LAB_001bc15c;
        }
        ptr[2] = 0;
        ptr[1] = 0;
        DSO_free((DSO *)*ptr);
        *ptr = 0;
        ERR_put_error(0x26,0xb6,0x91,"crypto/engine/eng_dyn.c",0x1da);
        return (char *)0x0;
      }
      if (ptr[9] != 0) goto LAB_001bbf8c;
    }
    pcVar7 = (char *)0x0;
    ERR_put_error(0x26,0xb6,0x84,"crypto/engine/eng_dyn.c",0x1b2);
    DSO_free((DSO *)*ptr);
    *ptr = 0;
    break;
  default:
    pcVar7 = (char *)0x0;
    ERR_put_error(0x26,0xb4,0x77,"crypto/engine/eng_dyn.c",0x16e);
  }
  return pcVar7;
}

