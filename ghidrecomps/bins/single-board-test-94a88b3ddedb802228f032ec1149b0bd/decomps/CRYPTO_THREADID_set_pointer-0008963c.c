
void CRYPTO_THREADID_set_pointer(CRYPTO_THREADID *id,void *ptr)

{
  *(undefined1 *)((int)&id->ptr + 3) = 0;
  *(undefined1 *)&id->val = 0;
  *(undefined1 *)((int)&id->val + 1) = 0;
  *(undefined1 *)((int)&id->val + 2) = 0;
  *(undefined1 *)((int)&id->val + 3) = 0;
  id->ptr = ptr;
  id->val = (ulong)ptr;
  return;
}

