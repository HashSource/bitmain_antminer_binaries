
void cgsem_reset(cgsem_t *cgsem)

{
  _Bool _Var1;
  cgsem_t *cgsem_local;
  int ret;
  
  do {
    ret = sem_trywait((sem_t *)cgsem);
    if ((ret < 0) && (_Var1 = interrupted(), _Var1)) {
      ret = 0;
    }
  } while (ret == 0);
  return;
}

