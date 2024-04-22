
int RAND_set_rand_method(RAND_METHOD *meth)

{
  ENGINE **ppEVar1;
  
  ppEVar1 = DAT_000ac158;
  if (*DAT_000ac158 != (ENGINE *)0x0) {
    ENGINE_finish(*DAT_000ac158);
    *ppEVar1 = (ENGINE *)0x0;
  }
  ppEVar1[1] = (ENGINE *)meth;
  return 1;
}

