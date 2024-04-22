
void * ssl_session_dup(void *param_1,int param_2)

{
  void *__dest;
  int iVar1;
  char *pcVar2;
  _STACK *p_Var3;
  void *pvVar4;
  
  __dest = CRYPTO_malloc(0xf4,DAT_0007ec7c,0xee);
  if (__dest == (void *)0x0) {
    ERR_put_error(0x14,0x15c,0x41,DAT_0007ec7c,0x15d);
    return (void *)0x0;
  }
  memcpy(__dest,param_1,0xf4);
  *(undefined *)((int)__dest + 0xc0) = 0;
  *(undefined *)((int)__dest + 0xc1) = 0;
  *(undefined *)((int)__dest + 0xc2) = 0;
  *(undefined *)((int)__dest + 0xc3) = 0;
  *(undefined *)((int)__dest + 0xc4) = 0;
  *(undefined *)((int)__dest + 0xc5) = 0;
  *(undefined *)((int)__dest + 0xc6) = 0;
  *(undefined *)((int)__dest + 199) = 0;
  iVar1 = *(int *)((int)param_1 + 0x98);
  *(undefined4 *)((int)__dest + 0x8c) = 0;
  *(undefined4 *)((int)__dest + 0x90) = 0;
  *(undefined4 *)((int)__dest + 0xbc) = 0;
  *(undefined4 *)((int)__dest + 0xd0) = 0;
  *(undefined4 *)((int)__dest + 0xd8) = 0;
  *(undefined4 *)((int)__dest + 0xe0) = 0;
  *(undefined4 *)((int)__dest + 0xe4) = 0;
  *(undefined4 *)((int)__dest + 0xf0) = 0;
  *(undefined4 *)((int)__dest + 200) = 0;
  *(undefined4 *)((int)__dest + 0xcc) = 0;
  *(undefined4 *)((int)__dest + 0xa4) = 1;
  if (iVar1 != 0) {
    CRYPTO_add_lock((int *)(iVar1 + 0xf8),1,0xf,DAT_0007ec7c,0x111);
  }
  if (*(int *)((int)param_1 + 0x9c) != 0) {
    CRYPTO_add_lock((int *)(*(int *)((int)param_1 + 0x9c) + 0x10),1,3,DAT_0007ec7c,0x114);
  }
  if (*(char **)((int)param_1 + 0x8c) != (char *)0x0) {
    pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0x8c));
    *(char **)((int)__dest + 0x8c) = pcVar2;
    if (pcVar2 == (char *)0x0) goto LAB_0007ec28;
  }
  if (*(char **)((int)param_1 + 0x90) != (char *)0x0) {
    pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0x90));
    *(char **)((int)__dest + 0x90) = pcVar2;
    if (pcVar2 == (char *)0x0) goto LAB_0007ec28;
  }
  if (*(_STACK **)((int)param_1 + 0xbc) != (_STACK *)0x0) {
    p_Var3 = sk_dup(*(_STACK **)((int)param_1 + 0xbc));
    *(_STACK **)((int)__dest + 0xbc) = p_Var3;
    if (p_Var3 == (_STACK *)0x0) goto LAB_0007ec28;
  }
  iVar1 = CRYPTO_dup_ex_data(3,(CRYPTO_EX_DATA *)((int)__dest + 0xc0),
                             (CRYPTO_EX_DATA *)((int)param_1 + 0xc0));
  if (iVar1 != 0) {
    if (*(char **)((int)param_1 + 0xd0) != (char *)0x0) {
      pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0xd0));
      *(char **)((int)__dest + 0xd0) = pcVar2;
      if (pcVar2 == (char *)0x0) goto LAB_0007ec28;
    }
    if (*(void **)((int)param_1 + 0xd8) != (void *)0x0) {
      pvVar4 = BUF_memdup(*(void **)((int)param_1 + 0xd8),*(size_t *)((int)param_1 + 0xd4));
      *(void **)((int)__dest + 0xd8) = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_0007ec28;
    }
    if (*(void **)((int)param_1 + 0xe0) != (void *)0x0) {
      pvVar4 = BUF_memdup(*(void **)((int)param_1 + 0xe0),*(size_t *)((int)param_1 + 0xdc));
      *(void **)((int)__dest + 0xe0) = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_0007ec28;
    }
    if (param_2 == 0) {
      *(undefined4 *)((int)__dest + 0xec) = 0;
      *(undefined4 *)((int)__dest + 0xe8) = 0;
    }
    else {
      pvVar4 = BUF_memdup(*(void **)((int)param_1 + 0xe4),*(size_t *)((int)param_1 + 0xe8));
      *(void **)((int)__dest + 0xe4) = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_0007ec28;
    }
    if (*(char **)((int)param_1 + 0xf0) == (char *)0x0) {
      return __dest;
    }
    pcVar2 = BUF_strdup(*(char **)((int)param_1 + 0xf0));
    *(char **)((int)__dest + 0xf0) = pcVar2;
    if (pcVar2 != (char *)0x0) {
      return __dest;
    }
  }
LAB_0007ec28:
  ERR_put_error(0x14,0x15c,0x41,DAT_0007ec7c,0x15d);
  iVar1 = CRYPTO_add_lock((int *)((int)__dest + 0xa4),-1,0xe,DAT_0007ec7c,0x352);
  if (iVar1 < 1) {
    SSL_SESSION_free_part_0(__dest);
  }
  return (void *)0x0;
}

