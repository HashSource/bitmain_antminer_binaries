
int BIO_vfree(BIO *a)

{
  bool bVar1;
  int iVar2;
  ulong *puVar3;
  ulong uVar4;
  code *pcVar5;
  
  if (a == (BIO *)0x0) {
    return 0;
  }
  puVar3 = &a->num_read;
  do {
    ExclusiveAccess(puVar3);
    uVar4 = *puVar3;
    bVar1 = (bool)hasExclusiveAccess(puVar3);
  } while (!bVar1);
  *puVar3 = uVar4 - 1;
  if (uVar4 == 1) {
    DataMemoryBarrier(0x1b);
  }
  else {
    if (uVar4 != 1 && -1 < (int)(uVar4 - 1)) {
      a = (BIO *)0x1;
    }
    if (0 < (int)(uVar4 - 1)) {
      return (int)a;
    }
  }
  pcVar5 = (code *)a->cb_arg;
  if (a->callback == (_func_745 *)0x0) {
    if (pcVar5 == (code *)0x0) goto LAB_0010a248;
LAB_0010a27e:
    iVar2 = (*pcVar5)(a,1,0,0,0,0,1,0);
  }
  else {
    if (pcVar5 != (code *)0x0) goto LAB_0010a27e;
    iVar2 = (*a->callback)(a,1,(char *)0x0,0,0,1);
  }
  if (iVar2 < 1) {
    return iVar2;
  }
LAB_0010a248:
  if ((a->method != (BIO_METHOD *)0x0) &&
     (pcVar5 = (code *)a->method[1].type, pcVar5 != (code *)0x0)) {
    (*pcVar5)(a);
  }
  CRYPTO_free_ex_data(0xc,a,(CRYPTO_EX_DATA *)&a[1].cb_arg);
  CRYPTO_THREAD_lock_free(a[1].init);
  CRYPTO_free(a);
  return 1;
}

