
int ENGINE_set_RAND(ENGINE *e,RAND_METHOD *rand_meth)

{
  *(RAND_METHOD **)(e + 0x18) = rand_meth;
  return 1;
}

