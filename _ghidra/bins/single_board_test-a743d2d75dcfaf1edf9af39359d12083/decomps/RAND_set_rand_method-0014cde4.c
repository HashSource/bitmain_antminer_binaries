
int RAND_set_rand_method(RAND_METHOD *meth)

{
  if (funct_ref != (ENGINE *)0x0) {
    ENGINE_finish(funct_ref);
    funct_ref = (ENGINE *)0x0;
  }
  default_RAND_meth = meth;
  return 1;
}

