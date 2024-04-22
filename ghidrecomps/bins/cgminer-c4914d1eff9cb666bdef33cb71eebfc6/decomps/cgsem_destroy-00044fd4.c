
void cgsem_destroy(cgsem_t *cgsem)

{
  cgsem_t *cgsem_local;
  
  sem_destroy((sem_t *)cgsem);
  return;
}

