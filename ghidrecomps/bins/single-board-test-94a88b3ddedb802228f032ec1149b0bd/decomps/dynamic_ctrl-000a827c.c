
void dynamic_ctrl(ENGINE *param_1,undefined4 param_2,uint param_3,char *param_4)

{
  int *__s;
  int iVar1;
  _STACK *p_Var2;
  int *piVar3;
  DSO *pDVar4;
  char *pcVar5;
  DSO_FUNC_TYPE pDVar6;
  uint uVar7;
  int mode;
  int *num;
  CRYPTO_dynlock_value *l;
  int type;
  int mount;
  int line;
  CRYPTO_dynlock_value *l_00;
  char *file;
  char *file_00;
  int type_00;
  char *file_01;
  int line_00;
  int line_01;
  char *file_02;
  int line_02;
  int iVar8;
  int in_stack_ffffff38;
  void *local_bc;
  ERR_FNS *local_b8;
  CRYPTO_EX_DATA_IMPL *local_b4;
  m *pmStack_b0;
  r *prStack_ac;
  f *apfStack_a8 [2];
  char *local_a0;
  CRYPTO_dynlock_value *local_9c;
  undefined1 auStack_90 [112];
  
  if (dynamic_ex_data_idx < 0) {
    in_stack_ffffff38 = 0xa8245;
    iVar1 = ENGINE_get_ex_new_index
                      (0,(void *)0x0,(undefined1 *)0x0,(undefined1 *)0x0,(undefined1 *)0xa8245);
    if (iVar1 == -1) {
      ERR_put_error(0x26,0xb5,0x90,"eng_dyn.c",0x10b);
      goto LAB_000a860c;
    }
    CRYPTO_lock(9,0x1e,"eng_dyn.c",0x10e);
    if (dynamic_ex_data_idx < 0) {
      dynamic_ex_data_idx = iVar1;
    }
    CRYPTO_lock(10,0x1e,"eng_dyn.c",0x115);
  }
  __s = (int *)ENGINE_get_ex_data(param_1,dynamic_ex_data_idx);
  if (__s == (int *)0x0) {
    __s = (int *)CRYPTO_malloc(0x2c,"eng_dyn.c",0xd2);
    if (__s == (int *)0x0) {
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xd4);
LAB_000a860c:
      ERR_put_error(0x26,0xb4,0x70,"eng_dyn.c",0x160);
      return;
    }
    memset(__s,0,0x2c);
    *__s = 0;
    __s[1] = 0;
    __s[2] = 0;
    __s[3] = 0;
    __s[4] = 0;
    __s[5] = 0;
    __s[6] = 0;
    __s[7] = (int)"v_check";
    __s[8] = (int)"bind_engine";
    __s[9] = 1;
    p_Var2 = sk_new_null();
    __s[10] = (int)p_Var2;
    if (p_Var2 == (_STACK *)0x0) {
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xe4);
      CRYPTO_free(__s);
      goto LAB_000a860c;
    }
    CRYPTO_lock(9,0x1e,"eng_dyn.c",0xe8);
    piVar3 = (int *)ENGINE_get_ex_data(param_1,dynamic_ex_data_idx);
    if (piVar3 == (int *)0x0) {
      ENGINE_set_ex_data(param_1,dynamic_ex_data_idx,__s);
      CRYPTO_lock(10,0x1e,"eng_dyn.c",0xf1);
    }
    else {
      CRYPTO_lock(10,0x1e,"eng_dyn.c",0xf1);
      CRYPTO_free(__s);
      __s = piVar3;
    }
  }
  if (*__s != 0) {
    ERR_put_error(0x26,0xb4,100,"eng_dyn.c",0x166);
    return;
  }
  switch(param_2) {
  case 200:
    if ((param_4 != (char *)0x0) && (*param_4 == '\0')) {
      param_4 = (char *)0x0;
    }
    if ((void *)__s[3] != (void *)0x0) {
      CRYPTO_free((void *)__s[3]);
    }
    if (param_4 == (char *)0x0) {
      __s[3] = 0;
    }
    else {
      pcVar5 = BUF_strdup(param_4);
      __s[3] = (int)pcVar5;
    }
    break;
  case 0xc9:
    if (param_3 != 0) {
      param_3 = 1;
    }
    __s[4] = param_3;
    break;
  case 0xca:
    if ((param_4 != (char *)0x0) && (*param_4 == '\0')) {
      param_4 = (char *)0x0;
    }
    if ((void *)__s[5] != (void *)0x0) {
      CRYPTO_free((void *)__s[5]);
    }
    if (param_4 == (char *)0x0) {
      __s[5] = 0;
    }
    else {
      pcVar5 = BUF_strdup(param_4);
      __s[5] = (int)pcVar5;
    }
    break;
  case 0xcb:
    if (param_3 < 3) {
      __s[6] = param_3;
      return;
    }
    iVar1 = 0x185;
    goto LAB_000a83ae;
  case 0xcc:
    if (param_3 < 3) {
      __s[9] = param_3;
      return;
    }
    iVar1 = 0x18e;
    goto LAB_000a83ae;
  case 0xcd:
    if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
      pcVar5 = BUF_strdup(param_4);
      if (pcVar5 != (char *)0x0) {
        sk_insert((_STACK *)__s[10],pcVar5,-1);
        return;
      }
      ERR_put_error(0x26,0xb4,0x41,"eng_dyn.c",0x19c);
      return;
    }
    iVar1 = 0x196;
LAB_000a83ae:
    ERR_put_error(0x26,0xb4,0x8f,"eng_dyn.c",iVar1);
    break;
  case 0xce:
    pDVar4 = DSO_new();
    *__s = (int)pDVar4;
    if (__s[3] == 0) {
      if ((char *)__s[5] == (char *)0x0) {
        return;
      }
      pcVar5 = DSO_convert_filename(pDVar4,(char *)__s[5]);
      __s[3] = (int)pcVar5;
    }
    if (__s[9] == 2) {
LAB_000a8474:
      iVar1 = sk_num((_STACK *)__s[10]);
      if (0 < iVar1) {
        iVar8 = 0;
        do {
          pcVar5 = (char *)sk_value((_STACK *)__s[10],iVar8);
          iVar8 = iVar8 + 1;
          pcVar5 = DSO_merge((DSO *)*__s,(char *)__s[3],pcVar5);
          if (pcVar5 == (char *)0x0) break;
          pDVar4 = DSO_load((DSO *)*__s,pcVar5,(DSO_METHOD *)0x0,0);
          if (pDVar4 != (DSO *)0x0) {
            CRYPTO_free(pcVar5);
            goto LAB_000a84fe;
          }
          CRYPTO_free(pcVar5);
        } while (iVar8 != iVar1);
      }
    }
    else {
      pDVar4 = DSO_load((DSO *)*__s,(char *)__s[3],(DSO_METHOD *)0x0,0);
      if (pDVar4 != (DSO *)0x0) {
LAB_000a84fe:
        pDVar6 = DSO_bind_func((DSO *)*__s,(char *)__s[8]);
        __s[2] = (int)pDVar6;
        if (pDVar6 == (DSO_FUNC_TYPE)0x0) {
          DSO_free((DSO *)*__s);
          *__s = 0;
          ERR_put_error(0x26,0xb6,0x68,"eng_dyn.c",0x1de);
          return;
        }
        if (__s[4] == 0) {
          pDVar6 = DSO_bind_func((DSO *)*__s,(char *)__s[7]);
          __s[1] = (int)pDVar6;
          if ((pDVar6 == (DSO_FUNC_TYPE)0x0) || (uVar7 = (*pDVar6)(0x20000), uVar7 < 0x20000)) {
            __s[2] = 0;
            __s[1] = 0;
            DSO_free((DSO *)*__s);
            *__s = 0;
            ERR_put_error(0x26,0xb6,0x91,"eng_dyn.c",0x1f9);
            return;
          }
        }
        memcpy(auStack_90,param_1,0x70);
        local_bc = ENGINE_get_static_state();
        local_b8 = ERR_get_implementation();
        local_b4 = CRYPTO_get_ex_data_implementation();
        CRYPTO_get_mem_functions(&pmStack_b0,&prStack_ac,apfStack_a8);
        CRYPTO_get_locking_callback(mode,type,file_00,line_01);
        local_a0 = (char *)CRYPTO_get_add_lock_callback(num,mount,type_00,file_02,in_stack_ffffff38)
        ;
        local_9c = CRYPTO_get_dynlock_create_callback(local_a0,line);
        CRYPTO_get_dynlock_lock_callback((int)local_9c,l_00,file_01,line_02);
        CRYPTO_get_dynlock_destroy_callback(l,file,line_00);
        engine_set_all_null(param_1);
        iVar1 = (*(code *)__s[2])(param_1,__s[5],&local_bc);
        if (iVar1 == 0) {
          __s[2] = 0;
          __s[1] = 0;
          DSO_free((DSO *)*__s);
          *__s = 0;
          ERR_put_error(0x26,0xb6,0x6d,"eng_dyn.c",0x21f);
          memcpy(param_1,auStack_90,0x70);
          return;
        }
        if (__s[6] < 1) {
          return;
        }
        iVar1 = ENGINE_add(param_1);
        if (iVar1 != 0) {
          return;
        }
        if (__s[6] < 2) {
          ERR_clear_error();
          return;
        }
        ERR_put_error(0x26,0xb6,0x67,"eng_dyn.c",0x230);
        return;
      }
      if (__s[9] != 0) goto LAB_000a8474;
    }
    ERR_put_error(0x26,0xb6,0x84,"eng_dyn.c",0x1d1);
    DSO_free((DSO *)*__s);
    *__s = 0;
    break;
  default:
    ERR_put_error(0x26,0xb4,0x77,"eng_dyn.c",0x1a5);
  }
  return;
}

