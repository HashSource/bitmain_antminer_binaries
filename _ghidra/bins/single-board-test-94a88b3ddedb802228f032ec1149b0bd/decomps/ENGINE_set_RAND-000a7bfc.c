
int ENGINE_set_RAND(ENGINE *e,RAND_METHOD *rand_meth)

{
  *(RAND_METHOD **)(e + 0x1c) = rand_meth;
  return 1;
}

