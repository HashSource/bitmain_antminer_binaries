
void CRYPTO_THREADID_current(CRYPTO_THREADID *id)

{
  ulong uVar1;
  int *piVar2;
  
  if (threadid_callback != (code *)0x0) {
    (*threadid_callback)();
    return;
  }
  if (id_callback != (code *)0x0) {
    uVar1 = (*id_callback)();
    *(undefined1 *)&id->ptr = 0;
    *(undefined1 *)((int)&id->ptr + 1) = 0;
    *(undefined1 *)((int)&id->ptr + 2) = 0;
    *(undefined1 *)((int)&id->ptr + 3) = 0;
    *(undefined1 *)&id->val = 0;
    *(undefined1 *)((int)&id->val + 1) = 0;
    *(undefined1 *)((int)&id->val + 2) = 0;
    *(undefined1 *)((int)&id->val + 3) = 0;
    id->val = uVar1;
    return;
  }
  piVar2 = __errno_location();
  *(undefined1 *)((int)&id->ptr + 3) = 0;
  *(undefined1 *)&id->val = 0;
  *(undefined1 *)((int)&id->val + 1) = 0;
  *(undefined1 *)((int)&id->val + 2) = 0;
  *(undefined1 *)((int)&id->val + 3) = 0;
  id->ptr = piVar2;
  id->val = (ulong)piVar2;
  return;
}

