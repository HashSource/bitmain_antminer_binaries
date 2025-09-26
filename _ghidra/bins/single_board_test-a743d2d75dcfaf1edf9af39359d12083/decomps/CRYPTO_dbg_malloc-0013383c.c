
void CRYPTO_dbg_malloc(void *addr,int num,char *file,int line,int before_p)

{
  _LHASH *lh;
  undefined4 *ptr;
  void *pvVar1;
  time_t tVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  CRYPTO_THREADID CStack_44;
  CRYPTO_THREADID aCStack_3c [4];
  
  if ((before_p & 0x7fU) != 1) {
    return;
  }
  if (addr == (void *)0x0) {
    return;
  }
  if (-1 < (int)(mh_mode << 0x1f)) {
    return;
  }
  CRYPTO_THREADID_current(&CStack_44);
  CRYPTO_lock(5,0x14,"mem_dbg.c",0x11d);
  if ((int)(mh_mode << 0x1e) < 0) {
    CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
  }
  else {
    iVar3 = CRYPTO_THREADID_cmp((CRYPTO_THREADID *)&disabling_threadid,&CStack_44);
    CRYPTO_lock(6,0x14,"mem_dbg.c",0x122);
    if (iVar3 == 0) {
      return;
    }
  }
  CRYPTO_mem_ctrl_constprop_2();
  ptr = (undefined4 *)CRYPTO_malloc(0x24,"mem_dbg.c",0x1e1);
  if (ptr != (undefined4 *)0x0) {
    if ((mh == (_LHASH *)0x0) &&
       (mh = lh_new((LHASH_HASH_FN_TYPE)0x133105,(LHASH_COMP_FN_TYPE)0x1330fd), mh == (_LHASH *)0x0)
       ) {
      CRYPTO_free(addr);
      CRYPTO_free(ptr);
      goto LAB_00133910;
    }
    uVar4 = options;
    *ptr = addr;
    ptr[1] = num;
    ptr[2] = file;
    ptr[3] = line;
    if ((uVar4 & 2) == 0) {
      *(undefined1 *)(ptr + 4) = 0;
      *(undefined1 *)((int)ptr + 0x11) = 0;
      *(undefined1 *)((int)ptr + 0x12) = 0;
      *(undefined1 *)((int)ptr + 0x13) = 0;
      *(undefined1 *)(ptr + 5) = 0;
      *(undefined1 *)((int)ptr + 0x15) = 0;
      *(undefined1 *)((int)ptr + 0x16) = 0;
      *(undefined1 *)((int)ptr + 0x17) = 0;
    }
    else {
      CRYPTO_THREADID_current((CRYPTO_THREADID *)(ptr + 4));
      uVar4 = options;
    }
    bVar5 = (uVar4 & 1) != 0;
    if (!bVar5) {
      ptr[7] = 0;
    }
    iVar3 = order + 1;
    ptr[6] = order;
    order = iVar3;
    if (bVar5) {
      tVar2 = time((time_t *)0x0);
      ptr[7] = tVar2;
    }
    CRYPTO_THREADID_current(aCStack_3c);
    lh = amih;
    ptr[8] = 0;
    if ((lh != (_LHASH *)0x0) && (pvVar1 = lh_retrieve(lh,aCStack_3c), pvVar1 != (void *)0x0)) {
      iVar3 = *(int *)((int)pvVar1 + 0x18);
      ptr[8] = pvVar1;
      *(int *)((int)pvVar1 + 0x18) = iVar3 + 1;
    }
    addr = lh_insert(mh,ptr);
    if (addr == (void *)0x0) goto LAB_00133910;
    iVar3 = *(int *)((int)addr + 0x20);
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -1;
    }
  }
  CRYPTO_free(addr);
LAB_00133910:
  CRYPTO_lock(9,0x14,"mem_dbg.c",0xd4);
  if ((((int)(mh_mode << 0x1f) < 0) && (num_disable != 0)) &&
     (num_disable = num_disable + -1, num_disable == 0)) {
    mh_mode = mh_mode | 2;
    CRYPTO_lock(10,0x1b,"mem_dbg.c",0x109);
  }
  CRYPTO_lock(10,0x14,"mem_dbg.c",0x112);
  return;
}

