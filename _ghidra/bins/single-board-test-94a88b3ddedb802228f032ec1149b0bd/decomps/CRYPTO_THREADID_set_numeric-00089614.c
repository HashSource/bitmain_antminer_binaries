
void CRYPTO_THREADID_set_numeric(CRYPTO_THREADID *id,ulong val)

{
  *(undefined1 *)&id->ptr = 0;
  *(undefined1 *)((int)&id->ptr + 1) = 0;
  *(undefined1 *)((int)&id->ptr + 2) = 0;
  *(undefined1 *)((int)&id->ptr + 3) = 0;
  *(undefined1 *)&id->val = 0;
  *(undefined1 *)((int)&id->val + 1) = 0;
  *(undefined1 *)((int)&id->val + 2) = 0;
  *(undefined1 *)((int)&id->val + 3) = 0;
  id->val = val;
  return;
}

