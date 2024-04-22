
void dynamic_ctrl(ENGINE *param_1,undefined4 param_2,DSO *param_3,char *param_4)

{
  int *piVar1;
  DSO *pDVar2;
  DSO **__s;
  DSO *pDVar3;
  DSO **ppDVar4;
  char *pcVar5;
  uint uVar6;
  m **m;
  CRYPTO_dynlock_value *l;
  int iVar7;
  int type;
  int mount;
  int line;
  CRYPTO_dynlock_value *l_00;
  char *file;
  f **f;
  int iVar8;
  undefined1 *in_stack_ffffff38;
  void *local_bc;
  ERR_FNS *local_b8;
  CRYPTO_EX_DATA_IMPL *local_b4;
  m *pmStack_b0;
  r *prStack_ac;
  f *pfStack_a8;
  m **local_a4;
  char *local_a0;
  CRYPTO_dynlock_value *local_9c;
  CRYPTO_dynlock_value *local_98;
  CRYPTO_dynlock_value *local_94;
  undefined auStack_90 [112];
  
  piVar1 = DAT_000a84d8;
  iVar7 = *DAT_000a84d8;
  if (iVar7 < 0) {
    in_stack_ffffff38 = DAT_000a84e0;
    iVar7 = ENGINE_get_ex_new_index(0,(void *)0x0,(undefined1 *)0x0,(undefined1 *)0x0,DAT_000a84e0);
    if (iVar7 == -1) {
      ERR_put_error(0x26,0xb5,0x90,DAT_000a8700,0x10b);
      goto LAB_000a860c;
    }
    CRYPTO_lock(9,0x1e,DAT_000a84dc,0x10e);
    pcVar5 = DAT_000a84dc;
    if (*piVar1 < 0) {
      *piVar1 = iVar7;
    }
    CRYPTO_lock(10,0x1e,pcVar5,0x115);
    iVar7 = *piVar1;
  }
  __s = (DSO **)ENGINE_get_ex_data(param_1,iVar7);
  if (__s == (DSO **)0x0) {
    __s = (DSO **)CRYPTO_malloc(0x2c,DAT_000a84dc,0xd2);
    if (__s == (DSO **)0x0) {
      ERR_put_error(0x26,0xb7,0x41,DAT_000a8700,0xd4);
LAB_000a860c:
      ERR_put_error(0x26,0xb4,0x70,DAT_000a8700,0x160);
      return;
    }
    memset(__s,0,0x2c);
    pDVar2 = DAT_000a84e8;
    pDVar3 = DAT_000a84e4;
    *__s = (DSO *)0x0;
    __s[1] = (DSO *)0x0;
    __s[2] = (DSO *)0x0;
    __s[3] = (DSO *)0x0;
    __s[4] = (DSO *)0x0;
    __s[5] = (DSO *)0x0;
    __s[6] = (DSO *)0x0;
    __s[7] = pDVar3;
    __s[8] = pDVar2;
    __s[9] = (DSO *)0x1;
    pDVar3 = (DSO *)sk_new_null();
    __s[10] = pDVar3;
    if (pDVar3 == (DSO *)0x0) {
      ERR_put_error(0x26,0xb7,0x41,DAT_000a8700,0xe4);
      CRYPTO_free(__s);
      goto LAB_000a860c;
    }
    CRYPTO_lock(9,0x1e,DAT_000a84dc,0xe8);
    ppDVar4 = (DSO **)ENGINE_get_ex_data(param_1,*piVar1);
    if (ppDVar4 == (DSO **)0x0) {
      ENGINE_set_ex_data(param_1,*DAT_000a84d8,__s);
      CRYPTO_lock(10,0x1e,DAT_000a8700,0xf1);
    }
    else {
      CRYPTO_lock(10,0x1e,DAT_000a84dc,0xf1);
      CRYPTO_free(__s);
      __s = ppDVar4;
    }
  }
  if (*__s != (DSO *)0x0) {
    ERR_put_error(0x26,0xb4,100,DAT_000a84dc,0x166);
    return;
  }
  switch(param_2) {
  case 200:
    if ((param_4 != (char *)0x0) && (*param_4 == '\0')) {
      param_4 = (char *)0x0;
    }
    if (__s[3] != (DSO *)0x0) {
      CRYPTO_free(__s[3]);
    }
    if (param_4 == (char *)0x0) {
      __s[3] = (DSO *)0x0;
    }
    else {
      pDVar3 = (DSO *)BUF_strdup(param_4);
      __s[3] = pDVar3;
    }
    break;
  case 0xc9:
    if (param_3 != (DSO *)0x0) {
      param_3 = (DSO *)0x1;
    }
    __s[4] = param_3;
    break;
  case 0xca:
    if ((param_4 != (char *)0x0) && (*param_4 == '\0')) {
      param_4 = (char *)0x0;
    }
    if (__s[5] != (DSO *)0x0) {
      CRYPTO_free(__s[5]);
    }
    if (param_4 == (char *)0x0) {
      __s[5] = (DSO *)0x0;
    }
    else {
      pDVar3 = (DSO *)BUF_strdup(param_4);
      __s[5] = pDVar3;
    }
    break;
  case 0xcb:
    if (param_3 < (DSO *)0x3) {
      __s[6] = param_3;
      return;
    }
    iVar7 = 0x185;
    goto LAB_000a83ae;
  case 0xcc:
    if (param_3 < (DSO *)0x3) {
      __s[9] = param_3;
      return;
    }
    iVar7 = 0x18e;
    goto LAB_000a83ae;
  case 0xcd:
    if ((param_4 != (char *)0x0) && (*param_4 != '\0')) {
      pcVar5 = BUF_strdup(param_4);
      if (pcVar5 != (char *)0x0) {
        sk_insert((_STACK *)__s[10],pcVar5,-1);
        return;
      }
      ERR_put_error(0x26,0xb4,0x41,DAT_000a8700,0x19c);
      return;
    }
    iVar7 = 0x196;
LAB_000a83ae:
    ERR_put_error(0x26,0xb4,0x8f,DAT_000a84dc,iVar7);
    break;
  case 0xce:
    pDVar3 = DSO_new();
    *__s = pDVar3;
    if (__s[3] == (DSO *)0x0) {
      if (__s[5] == (DSO *)0x0) {
        return;
      }
      pDVar3 = (DSO *)DSO_convert_filename(pDVar3,(char *)__s[5]);
      __s[3] = pDVar3;
    }
    if (__s[9] == (DSO *)0x2) {
LAB_000a8474:
      iVar7 = sk_num((_STACK *)__s[10]);
      if (0 < iVar7) {
        iVar8 = 0;
        do {
          pcVar5 = (char *)sk_value((_STACK *)__s[10],iVar8);
          iVar8 = iVar8 + 1;
          pcVar5 = DSO_merge(*__s,(char *)__s[3],pcVar5);
          if (pcVar5 == (char *)0x0) break;
          pDVar3 = DSO_load(*__s,pcVar5,(DSO_METHOD *)0x0,0);
          if (pDVar3 != (DSO *)0x0) {
            CRYPTO_free(pcVar5);
            goto LAB_000a84fe;
          }
          CRYPTO_free(pcVar5);
        } while (iVar8 != iVar7);
      }
    }
    else {
      pDVar3 = DSO_load(*__s,(char *)__s[3],(DSO_METHOD *)0x0,0);
      if (pDVar3 != (DSO *)0x0) {
LAB_000a84fe:
        pDVar3 = (DSO *)DSO_bind_func(*__s,(char *)__s[8]);
        __s[2] = pDVar3;
        if (pDVar3 == (DSO *)0x0) {
          DSO_free(*__s);
          *__s = (DSO *)0x0;
          ERR_put_error(0x26,0xb6,0x68,DAT_000a8700,0x1de);
          return;
        }
        pDVar3 = __s[4];
        if (pDVar3 == (DSO *)0x0) {
          pDVar3 = (DSO *)DSO_bind_func(*__s,(char *)__s[7]);
          __s[1] = pDVar3;
          if ((pDVar3 == (DSO *)0x0) || (uVar6 = (*(code *)pDVar3)(0x20000), uVar6 < 0x20000)) {
            __s[2] = (DSO *)0x0;
            __s[1] = (DSO *)0x0;
            DSO_free(*__s);
            *__s = (DSO *)0x0;
            ERR_put_error(0x26,0xb6,0x91,DAT_000a8700,0x1f9);
            return;
          }
        }
        memcpy(auStack_90,param_1,0x70);
        local_bc = ENGINE_get_static_state();
        local_b8 = ERR_get_implementation();
        local_b4 = CRYPTO_get_ex_data_implementation();
        f = &pfStack_a8;
        m = &pmStack_b0;
        CRYPTO_get_mem_functions(m,&prStack_ac,f);
        CRYPTO_get_locking_callback((int)m,type,(char *)f,(int)pDVar3);
        local_a4 = m;
        local_a0 = (char *)CRYPTO_get_add_lock_callback
                                     ((int *)m,mount,(int)f,(char *)pDVar3,(int)in_stack_ffffff38);
        l = CRYPTO_get_dynlock_create_callback(local_a0,line);
        local_9c = l;
        CRYPTO_get_dynlock_lock_callback((int)l,l_00,(char *)f,(int)pDVar3);
        local_98 = l;
        CRYPTO_get_dynlock_destroy_callback(l,file,(int)f);
        local_94 = l;
        engine_set_all_null(param_1);
        iVar7 = (*(code *)__s[2])(param_1,__s[5],&local_bc);
        if (iVar7 == 0) {
          __s[2] = (DSO *)0x0;
          __s[1] = (DSO *)0x0;
          DSO_free(*__s);
          *__s = (DSO *)0x0;
          ERR_put_error(0x26,0xb6,0x6d,DAT_000a8700,0x21f);
          memcpy(param_1,auStack_90,0x70);
          return;
        }
        if ((int)__s[6] < 1) {
          return;
        }
        iVar7 = ENGINE_add(param_1);
        if (iVar7 != 0) {
          return;
        }
        if ((int)__s[6] < 2) {
          ERR_clear_error();
          return;
        }
        ERR_put_error(0x26,0xb6,0x67,DAT_000a8700,0x230);
        return;
      }
      if (__s[9] != (DSO *)0x0) goto LAB_000a8474;
    }
    ERR_put_error(0x26,0xb6,0x84,DAT_000a84dc,0x1d1);
    DSO_free(*__s);
    *__s = (DSO *)0x0;
    break;
  default:
    ERR_put_error(0x26,0xb4,0x77,DAT_000a84dc,0x1a5);
  }
  return;
}

